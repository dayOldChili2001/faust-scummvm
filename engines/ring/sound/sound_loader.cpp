/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "ring/sound/sound_loader.h"

#include "audio/decoders/wave.h"

#include "common/archive.h"
#include "common/endian.h"

namespace Ring {

// 8-byte Arxel header + 44-byte RIFF header
static const uint32 kHeaderSize = 52;

// Number of samples in a WAC chunk
static const uint32 kMonoChunkSamples = 256;

// Bit readers read 4 bytes at a time, so chunks are padded
static const uint32 kChunkPadding = 4;

#pragma region CompressedSoundStream

CompressedSoundStream::CompressedSoundStream(Common::SeekableReadStream *stream, SoundFormat format) {
	_stream       = stream;
	_format       = format;
	_isValid      = false;
	_isStereo     = false;
	_rate         = 0;
	_totalSamples = 0;
	_samplesRead  = 0;
	_samplesPos   = 0;
	_value        = 0;
	_delta        = 0;
	_lastSample   = 0;

	byte header[kHeaderSize];
	if (_stream->read(header, kHeaderSize) != kHeaderSize) {
		warning("[CompressedSoundStream] Cannot read header");
		return;
	}

	uint32 wavSize = READ_LE_UINT32(&header[4]);
	if (READ_BE_UINT32(&header[8]) != MKTAG('R', 'I', 'F', 'F')
	 || READ_BE_UINT32(&header[16]) != MKTAG('W', 'A', 'V', 'E')
	 || READ_BE_UINT32(&header[44]) != MKTAG('d', 'a', 't', 'a')) {
		warning("[CompressedSoundStream] Invalid WAVE header");
		return;
	}

	uint16 type          = READ_LE_UINT16(&header[28]);
	uint16 channels      = READ_LE_UINT16(&header[30]);
	uint16 bitsPerSample = READ_LE_UINT16(&header[42]);
	if (type != 1 || bitsPerSample != 16 || (channels != 1 && channels != 2)) {
		warning("[CompressedSoundStream] Unsupported WAVE format (type: %d, channels: %d, bits: %d)", type, channels, bitsPerSample);
		return;
	}

	_isStereo = (channels == 2);
	_rate     = (int)READ_LE_UINT32(&header[32]);

	// The last chunk is padded: the data chunk size is the real length
	uint32 dataSize = READ_LE_UINT32(&header[48]);
	if (wavSize >= 44 && wavSize - 44 < dataSize)
		dataSize = wavSize - 44;

	_totalSamples = dataSize / 2;
	if (_isStereo)
		_totalSamples &= ~1u;

	_isValid = true;
}

CompressedSoundStream::~CompressedSoundStream() {
	delete _stream;
}

bool CompressedSoundStream::endOfData() const {
	return !_isValid || _samplesRead >= _totalSamples;
}

bool CompressedSoundStream::rewind() {
	if (!_isValid)
		return false;

	_samplesRead = 0;
	_samplesPos  = 0;
	_samples.clear();
	_value       = 0;
	_delta       = 0;
	_lastSample  = 0;

	return _stream->seek(kHeaderSize);
}

int CompressedSoundStream::readBuffer(int16 *buffer, const int numSamples) {
	int count = 0;

	while (count < numSamples && !endOfData()) {
		if (_samplesPos >= _samples.size()) {
			if (!decodeChunk()) {
				// Truncated file: stop here
				_totalSamples = _samplesRead;
				break;
			}
		}

		uint32 available = MIN<uint32>(_samples.size() - _samplesPos, _totalSamples - _samplesRead);
		uint32 toCopy    = MIN<uint32>(available, (uint32)(numSamples - count));

		memcpy(&buffer[count], &_samples[_samplesPos], toCopy * sizeof(int16));
		count        += toCopy;
		_samplesPos  += toCopy;
		_samplesRead += toCopy;
	}

	return count;
}

bool CompressedSoundStream::readChunk(uint32 size) {
	if (size == 0 || _stream->pos() + (int64)size > _stream->size())
		return false;

	_chunk.resize(size + kChunkPadding);
	if (_stream->read(_chunk.data(), size) != size)
		return false;

	memset(&_chunk[size], 0, kChunkPadding);

	return true;
}

bool CompressedSoundStream::decodeChunk() {
	_samples.clear();
	_samplesPos = 0;

	bool result = (_format == kSoundFormatWAS) ? decodeChunkStereo() : decodeChunkMono();

	if (!_samples.empty())
		_lastSample = _samples.back();

	return result && !_samples.empty();
}

bool CompressedSoundStream::decodeChunkMono() {
	if (_stream->pos() + 2 > _stream->size())
		return false;

	if (!readChunk(_stream->readUint16LE()))
		return false;

	_samples.resize(kMonoChunkSamples);

	// The first 3 bits of each chunk are skipped
	uint32 position = 3;
	uint32 end = (_chunk.size() - kChunkPadding) * 8;

	for (uint32 i = 0; i < kMonoChunkSamples; i++) {
		if (position >= end) {
			warning("[CompressedSoundStream::decodeChunkMono] Chunk too short");
			return false;
		}

		uint32 bits = READ_BE_UINT32(&_chunk[position >> 3]);
		uint32 bit  = 31 - (position & 7);

		if (bits & (1u << bit)) {
			position += 1;
		} else {
			uint16 delta = (uint16)((bits << (32 - bit)) >> 22);
			if (delta >= 512)
				delta = (uint16)(512 - delta);

			_delta = (uint16)(delta << 6);
			position += 11;
		}

		_value += _delta;
		_samples[i] = (int16)_value;
	}

	return true;
}

bool CompressedSoundStream::decodeChunkStereo() {
	if (_stream->pos() + 8 > _stream->size())
		return false;

	uint32 compressedSize = _stream->readUint32LE();
	uint32 decodedSize    = _stream->readUint32LE();

	if (!readChunk(compressedSize))
		return false;

	_samples.reserve(decodedSize / 2);

	uint16 dictionary[64];
	uint32 lastUsed[64];
	memset(dictionary, 0, sizeof(dictionary));
	memset(lastUsed, 0, sizeof(lastUsed));
	byte leastUsed = 0;
	byte current = 0;
	int16 previous = _lastSample;

	uint32 position = 0;
	uint32 end = compressedSize * 8;

	while (position < end) {
		uint32 bits = READ_BE_UINT32(&_chunk[position >> 3]);
		uint32 bit  = 31 - (position & 7);

		if (!(bits & (1u << bit))) {
			// Literal (the original does not update the slot usage here)
			uint16 sample = (uint16)(((bits << (32 - bit)) >> 20) << 4);

			dictionary[leastUsed] = sample;
			current = leastUsed;
			previous = (int16)sample;
			position += 13;
		} else {
			if (!(bits & (1u << (bit - 1)))) {
				// Dictionary reference
				current = (byte)((bits << (33 - bit)) >> 26);
				previous = (int16)dictionary[current];
				position += 8;
			} else {
				// Repeat previous sample
				position += 2;
			}

			lastUsed[current] = position;

			if (current == leastUsed) {
				leastUsed = 0;
				for (byte i = 1; i < 64; i++)
					if (lastUsed[i] < lastUsed[leastUsed])
						leastUsed = i;
			}
		}

		_samples.push_back(previous);
	}

	if (_samples.size() > decodedSize / 2)
		_samples.resize(decodedSize / 2);

	return true;
}

#pragma endregion

Audio::RewindableAudioStream *makeSoundStream(const Common::String &path, SoundFormat format) {
	Common::SeekableReadStream *stream = SearchMan.createReadStreamForMember(Common::Path(path, '/'));
	if (!stream) {
		warning("[makeSoundStream] Cannot open stream to file (%s)", path.c_str());
		return nullptr;
	}

	switch (format) {
	default:
		error("[makeSoundStream] Invalid sound format (%d)", format);

	case kSoundFormatWAV:
		return Audio::makeWAVStream(stream, DisposeAfterUse::YES);

	case kSoundFormatWAC:
	case kSoundFormatWAS: {
		CompressedSoundStream *audioStream = new CompressedSoundStream(stream, format);
		if (!audioStream->isValid()) {
			warning("[makeSoundStream] Invalid compressed sound (%s)", path.c_str());
			delete audioStream;
			return nullptr;
		}

		return audioStream;
	}
	}
}

} // End of namespace Ring
