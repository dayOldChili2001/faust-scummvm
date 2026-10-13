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

#ifndef RING_SOUND_LOADER_H
#define RING_SOUND_LOADER_H

#include "ring/shared.h"

#include "audio/audiostream.h"

#include "common/array.h"
#include "common/stream.h"

namespace Ring {

// Arxel compressed sound (.wac / .was)
//
// File layout:
//   uint32 chunkCount
//   uint32 wavSize (size of the equivalent .wav file)
//   44-byte RIFF/WAVE header (PCM, 16 bits)
//   chunks
//
// WAC (original: aSecComSouMono) chunk: uint16 size + bitstream decoding to 256 samples.
// Each sample is either a 1-bit "repeat last delta" flag, or a 0 bit followed by a
// 10-bit sign/magnitude delta (shifted left by 6) added to the previous sample.
//
// WAS (original: aSecComSouStereo) chunk: uint32 compressedSize + uint32 decodedSize
// + bitstream. Each sample is one of:
//   0 + 12-bit literal (shifted left by 4), stored in the least recently used dictionary slot
//   10 + 6-bit index into a 64-entry dictionary of recent sample values
//   11 repeat the previous sample
// The dictionary is reset at the start of each chunk.
class CompressedSoundStream : public Audio::RewindableAudioStream {
public:
	CompressedSoundStream(Common::SeekableReadStream *stream, SoundFormat format);
	~CompressedSoundStream() override;

	bool isValid() const { return _isValid; }

	// AudioStream
	int readBuffer(int16 *buffer, const int numSamples) override;
	bool isStereo() const override { return _isStereo; }
	int getRate() const override { return _rate; }
	bool endOfData() const override;
	bool rewind() override;

private:
	Common::SeekableReadStream *_stream;
	SoundFormat _format;
	bool        _isValid;
	bool        _isStereo;
	int         _rate;
	uint32      _totalSamples;
	uint32      _samplesRead;

	Common::Array<byte>  _chunk;
	Common::Array<int16> _samples;
	uint32               _samplesPos;

	// Decoder state
	uint16 _value;
	uint16 _delta;
	int16  _lastSample;

	bool decodeChunk();
	bool decodeChunkMono();
	bool decodeChunkStereo();
	bool readChunk(uint32 size);
};

// Creates a stream for a .wav, .wac or .was file (nullptr on error)
Audio::RewindableAudioStream *makeSoundStream(const Common::String &path, SoundFormat format);

} // End of namespace Ring

#endif // RING_SOUND_LOADER_H
