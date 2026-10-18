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

#ifndef RING_SOUND_ENTRY_H
#define RING_SOUND_ENTRY_H

#include "ring/shared.h"

#include "audio/audiostream.h"
#include "audio/mixer.h"

namespace Ring {

class SoundEntry : public BaseObject {
public:
	SoundEntry(Id soundId, SoundType type, Common::String name, LoadFrom loadFrom, SoundFormat format);
	virtual ~SoundEntry();

	virtual void play(bool loop) = 0;
	virtual void stop() = 0;
	virtual void stopAndClear() = 0;
	virtual void preload() {}
	virtual void unload() {}
	virtual bool isPreloaded() { return false; }
	bool isPlaying() const ;

	void setVolume(int32 volume);
	void setMultiplier(int32 multiplier);
	void setPan(int32 pan);

	bool checkPlaying();

	// Accessors
	SoundType getType() { return _type; }
	Common::String getName() { return _name; }
	void setField125(uint32 val) { _field_125 = val; }
	void setPlaying(bool state) { _isPlaying = state; }

	int32 getVolume() { return _volume; }
	int32 getMultiplier() { return _multiplier; }
	int32 getPan() { return _pan; }
	bool isLooping() { return _loop; }
	void setSoundInfo(int32 volume, int32 multiplier, int32 pan) { _volume = volume; _multiplier = multiplier; _pan = pan; }

	static SoundFormat getFormat(Common::String filename);

protected:
	SoundType      _type;
	Common::String _name;
	Common::String _path;
	bool           _isPlaying;
	LoadFrom       _loadFrom;
	int32          _volume;
	int32          _multiplier;
	int32          _pan;
	bool           _loop;
	SoundFormat    _format;
	uint32         _field_125;

	Audio::SoundHandle _handle;

	void setVolumeAndPan() const ;
};

class SoundEntryStream : public SoundEntry {
public:
	SoundEntryStream(Id soundId, SoundType type, Common::String name, LoadFrom loadFrom, SoundFormat format, int32 soundChunk);
	~SoundEntryStream();

	void play(bool loop) override;
	void stop() override;
	void stopAndClear() override;

private:
	Audio::RewindableAudioStream *_audioStream;
	int32         _soundChunk;

	void initSoundBuffer(const Common::String &path, bool loop, SoundFormat format);
	void stopAndReleaseSoundBuffer();
};

class SoundEntryData : public SoundEntry {
public:
	SoundEntryData(Id soundId, SoundType type, Common::String name, LoadFrom loadFrom, SoundFormat format);
	~SoundEntryData();

	void play(bool loop) override;
	void stop() override;
	void stopAndClear() override;
	void preload() override;
	void unload() override;
	bool isPreloaded() override { return _isPreloaded; }

private:
	Audio::RewindableAudioStream *_audioStream;
	uint32         _isPreloaded;

	void initSoundBuffer(const Common::String &path);
	void stopAndReleaseSoundBuffer();
};

} // End of namespace Ring

#endif // RING_SOUND_ENTRY_H
