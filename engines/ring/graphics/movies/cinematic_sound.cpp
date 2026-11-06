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

#include "ring/graphics/movies/cinematic_sound.h"

#include "ring/base/application.h"

#include "ring/sound/sound_entry.h"
#include "ring/sound/sound_manager.h"

#include "ring/ring.h"
#include "ring/helpers.h"

#include "audio/audiostream.h"
#include "audio/decoders/raw.h"

namespace Ring {

#pragma region CinematicSound

CinematicSound::CinematicSound() {
	_channels       = 0;
	_samplesPerSec  = 0;
	_avgBytesPerSec = 0;
	_blockAlign     = 0;
	_bitsPerSample  = 0;
	_audioStream    = nullptr;
	_isPlaying      = false;
	_volume         = 1.0f;
}

CinematicSound::~CinematicSound() {
	deinit();
}

void CinematicSound::init(uint32 channels, uint32 bitsPerSample, uint32 samplesPerSec) {
	deinit();

	_channels       = channels;
	_bitsPerSample  = bitsPerSample;
	_blockAlign     = bitsPerSample * channels / 8;
	_samplesPerSec  = samplesPerSec;
	_avgBytesPerSec = samplesPerSec * _blockAlign;

	_isPlaying      = false;
	_volume         = 1.0f;

	debugC(kRingDebugMovie, "Setting up movie sound (channels: %d, bitsPerSample: %d, blockAlign: %d, samplesPerSec: %d, avgBytesPerSec: %d)",
	       _channels, _bitsPerSample, _blockAlign, _samplesPerSec, _avgBytesPerSec);

	// Create an audio stream where the decoded chunks will be appended
	_audioStream = Audio::makeQueuingAudioStream(_samplesPerSec, channels == 1 ? false : true);
}

void CinematicSound::deinit() {
	if (!_audioStream)
		return;

	if (_isPlaying) {
		_isPlaying = false;

		// Stop sound
		getSound()->getMixer()->stopHandle(_handle);
	}

	// Close the audio stream
	_audioStream = nullptr;
}

void CinematicSound::play() {
	if (_isPlaying)
		return;

	if (!_audioStream)
		error("[CinematicSound::play] Audiostream not initialized properly");

	// Play sound
	getSound()->getMixer()->setChannelVolume(_handle, _volume);
	getSound()->getMixer()->playStream(Audio::Mixer::kPlainSoundType, &_handle, _audioStream);

	_isPlaying = true;
}

void CinematicSound::setVolume(int32 volume) {
	_volume = volume;

	getSound()->getMixer()->setChannelVolume(_handle, _volume);
}

void CinematicSound::queueBuffer(byte *data, uint32 size) {
	if (!_audioStream)
		error("[CinematicSound::queueBuffer] Audiostream not initialized properly");

	// The movie sound chunks are plain PCM (every Faust movie: 16-bit little-endian stereo, 22050 Hz),
	// not MS ADPCM: decoding them as ADPCM turned the audio into full-scale noise.
	byte flags = 0;
	if (_bitsPerSample == 16)
		flags |= Audio::FLAG_16BITS | Audio::FLAG_LITTLE_ENDIAN;
	else
		flags |= Audio::FLAG_UNSIGNED;
	if (_channels == 2)
		flags |= Audio::FLAG_STEREO;

	// Keep whole sample frames only
	size -= size % MAX<uint32>(_blockAlign, 1);

	// Queue the samples (the stream frees the buffer)
	_audioStream->queueBuffer(data, size, DisposeAfterUse::YES, flags);
}

#pragma endregion

} // End of namespace Ring
