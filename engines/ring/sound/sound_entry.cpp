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

#include "ring/sound/sound_entry.h"

#include "ring/base/application.h"

#include "ring/sound/sound_loader.h"
#include "ring/sound/sound_manager.h"

#include "ring/helpers.h"
#include "ring/ring.h"


namespace Ring {

#pragma region SoundEntry

SoundEntry::SoundEntry(Id soundId, SoundType type, Common::String name, LoadFrom loadFrom, SoundFormat format) : BaseObject(soundId) {
	_type       = type;
	_name       = name;
	// FAUST.EXE 0x479640 builds the path from the current zone when the sound is added,
	// so sounds from an earlier zone still play (and load) after a zone change
	_path       = getApp()->getSoundPath(name, type);
	_isPlaying  = false;
	_loadFrom   = loadFrom;
	_volume     = 100;
	_multiplier = 100;
	_pan        = 0;
	_loop       = false;
	_format     = format;
	_field_125  = 1;
}

SoundEntry::~SoundEntry() {
}

bool SoundEntry::isPlaying() const {
	return getSound()->getMixer()->isSoundHandleActive(_handle);
}

void SoundEntry::setVolume(int32 volume) {
	if (volume >= 0)
		_volume = (volume > 100) ? 100 : volume;
	else
		_volume = 0;

	setVolumeAndPan();
}

void SoundEntry::setMultiplier(int32 multiplier) {
	if (multiplier >= 0)
		_multiplier = (multiplier > 100) ? 100 : multiplier;
	else
		_multiplier = 0;

	setVolumeAndPan();
}

void SoundEntry::setPan(int32 pan) {
	if (pan >= -100)
		_pan = (pan > 100) ? 100 : pan;
	else
		_pan = -100;

	setVolumeAndPan();
}

bool SoundEntry::checkPlaying() {
	if (!_isPlaying)
		return false;

	bool playing = isPlaying();
	if (!playing) {
		_isPlaying = false;
		stop();
	}

	return (playing == false);
}

// FAUST.EXE 0x46b8b0 passes DirectSound attenuations in hundredths of a dB:
// volume = -10000 * (1 - volume% * multiplier% * global), pan = pan * 100 (on the other channel)
void SoundEntry::setVolumeAndPan() const {
	int32 volume = -10000 + (int32)(_multiplier * 0.01f * (_volume * 0.01f) * getSound()->getGlobalVolume() * 10000.0f);
	int32 pan    = _pan * 100;

	getSound()->getMixer()->setChannelVolume(_handle, (byte)(pow(10.0, volume / 2000.0) * Audio::Mixer::kMaxChannelVolume + 0.5));
	getSound()->getMixer()->setChannelBalance(_handle, (int8)((pan < 0 ? -127 : 127) * (1.0 - pow(10.0, -ABS(pan) / 2000.0))));
}

SoundFormat SoundEntry::getFormat(Common::String filename) {
	filename.toLowercase();

	if (filename.hasSuffix("wav"))
		return kSoundFormatWAV;

	if (filename.hasSuffix("wac"))
		return kSoundFormatWAC;

	if (filename.hasSuffix("was"))
		return kSoundFormatWAS;

	return kSoundFormatInvalid;
}

#pragma endregion

#pragma region SoundEntryStream

SoundEntryStream::SoundEntryStream(Id soundId, SoundType type, Common::String name, LoadFrom loadFrom, SoundFormat format, int32 soundChunk) : SoundEntry(soundId, type, name, loadFrom, format) {
	_audioStream = nullptr;
	_soundChunk = soundChunk;
}

SoundEntryStream::~SoundEntryStream() {
	stopAndReleaseSoundBuffer();
}

void SoundEntryStream::play(bool loop) {
	// Compute sound path
	Common::String path = _path;

	debugC(kRingDebugSound, "Playing sound: %s", path.c_str());

	initSoundBuffer(path, loop, _format);

	// Rewind and play sound
	stop();

	if (_audioStream) {
		_audioStream->rewind();
		getSound()->getMixer()->playStream(Audio::Mixer::kPlainSoundType, &_handle, new Audio::LoopingAudioStream(_audioStream, loop ? 0 : 1, DisposeAfterUse::NO));

		setVolumeAndPan();
		_isPlaying = true;
	}
}

void SoundEntryStream::stop() {
	getSound()->getMixer()->stopHandle(_handle);

	_isPlaying = false;
}

void SoundEntryStream::stopAndClear() {
	stop();
	stopAndReleaseSoundBuffer();
}

void SoundEntryStream::initSoundBuffer(const Common::String &path, bool loop, SoundFormat format) {
	stopAndReleaseSoundBuffer();

	_loop = loop;

	// The original streams the sound into a DirectSound buffer, _soundChunk seconds at a time.
	// Audio streams are decoded on the fly by the mixer, so we don't need to.
	_audioStream = makeSoundStream(path, format);
}

void SoundEntryStream::stopAndReleaseSoundBuffer() {
	if (!_audioStream)
		return;

	stop();
	SAFE_DELETE(_audioStream);
}

#pragma endregion

#pragma region SoundEntryData

SoundEntryData::SoundEntryData(Id soundId, SoundType type, Common::String name, LoadFrom loadFrom, SoundFormat format) : SoundEntry(soundId, type, name, loadFrom, format) {
	_audioStream = nullptr;
	_isPreloaded = 0;
}

SoundEntryData::~SoundEntryData() {
	stopAndReleaseSoundBuffer();
}

void SoundEntryData::play(bool loop) {
	if (!_audioStream)
		preload();

	if (!_audioStream)
		return;

	// Rewind and play sound
	_audioStream->rewind();
	getSound()->getMixer()->playStream(Audio::Mixer::kPlainSoundType, &_handle, new Audio::LoopingAudioStream(_audioStream, loop ? 0 : 1, DisposeAfterUse::NO));

	setVolumeAndPan();
	_isPlaying = !loop;
}

void SoundEntryData::stop() {
	getSound()->getMixer()->stopHandle(_handle);

	if (!_isPreloaded)
		stopAndReleaseSoundBuffer();

	_isPlaying = false;
}

void SoundEntryData::stopAndClear() {
	stop();
	stopAndReleaseSoundBuffer();
}

void SoundEntryData::preload() {
	_isPreloaded = true;

	// Compute sound path
	Common::String path = _path;
	initSoundBuffer(path);
}

void SoundEntryData::unload() {
	if (_isPreloaded)
		stopAndReleaseSoundBuffer();

	_isPreloaded = false;
}

void SoundEntryData::initSoundBuffer(const Common::String &path) {
	SAFE_DELETE(_audioStream);

	_audioStream = makeSoundStream(path, _format);
}

void SoundEntryData::stopAndReleaseSoundBuffer() {
	if (!_audioStream)
		return;

	stop();
	SAFE_DELETE(_audioStream);
}

#pragma endregion

} // End of namespace Ring
