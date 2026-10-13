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

#ifndef RING_FAUST_ZONE_SYSTEM_H
#define RING_FAUST_ZONE_SYSTEM_H

#include "ring/base/event.h"

#include "ring/shared.h"

namespace Ring {

class ApplicationFaust;

class ZoneSystemFaust : public EventHandlerZone {
public:
	ZoneSystemFaust(ApplicationFaust *application);
	~ZoneSystemFaust();

	int8 getChapterIndex() const { return _chapterIndex; }

	void onInit() override;
	void onTimer(TimerId id) override;
	void onKeyDown(const Common::KeyState &keyState) override;
	void onButtonUp(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, const Common::Point &point) override;
	void onButtonDown(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, const Common::Point &point) override;
	void onAnimationNextFrame(Id animationId, const Common::String &name, uint32 frame, uint32 frameCount) override;
	void onSound(Id id, SoundType type, uint32 a3, bool process) override;
	void onBag(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, DragControl *dragControl, byte type) override;
	void onUpdateBag(const Common::Point &point) override;
	void onUpdateBefore(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, const Common::Point &point) override;
	void onVisualList(Id id, uint32 type, const Common::Point &point) override;

private:
	ApplicationFaust *_app;

	// Name being typed in the user / savegame lists (global buffer at 0x4dc250 in FAUST.EXE)
	Common::String _name;

	// Preferences in slider space, 0..100 (globals 0x4dbf04, 0x4dc24c, 0x4dc350, 0x4dc018)
	int32 _prefsVolume;
	int32 _prefsVolumeDialog;
	bool  _prefsReverseStereo;
	bool  _prefsSubtitles;

	// Values when the preferences screen was opened, restored on cancel (0x4dbf08, 0x4dc354, 0x4dc044, 0x4dbdf4)
	int32 _prefsVolumeBackup;
	int32 _prefsVolumeDialogBackup;
	bool  _prefsReverseStereoBackup;
	bool  _prefsSubtitlesBackup;

	int32 _object22Volume;    // 0x4dc358
	int32 _dialPosition;      // 0x4dbf00
	int32 _dialLastPosition;  // 0x4dbf10

	bool _object1Visible;     // 0x4c65fc
	int8 _jukeboxIndex;       // 0x4dc042 (1..13)
	int8 _chapterIndex;       // 0x4dbf0c

	void savePreferences();
	void hideMainMenuButtons();
	void showMainMenu(bool enableArrows);
	void hideMenuButtons(ObjectId from, ObjectId to);
	void playHint(uint32 counterVar, int8 maxCount, Id baseSound);
	void onQuestion(Id target);
	void onJukebox(Id target);
	void onLogin();
};

} // End of namespace Ring

#endif // RING_FAUST_ZONE_SYSTEM_H
