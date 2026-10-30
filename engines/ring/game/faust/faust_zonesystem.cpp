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

#include "ring/game/faust/faust_zonesystem.h"

#include "ring/base/object.h"
#include "ring/base/preferences.h"
#include "ring/base/saveload.h"

#include "ring/game/faust/faust_application.h"
#include "ring/game/faust/faust_shared.h"

#include "ring/debug.h"
#include "ring/ring.h"
#include "ring/helpers.h"

#include "ring/graphics/drag_control.h"
#include "ring/graphics/image.h"

#include "audio/mixer.h"

#include "common/util.h"

#include <math.h>

using namespace FaustGame;

namespace Ring {

ZoneSystemFaust::ZoneSystemFaust(ApplicationFaust *application) : _app(application),
	_prefsVolume(100), _prefsVolumeDialog(100), _prefsReverseStereo(false), _prefsSubtitles(true),
	_prefsVolumeBackup(100), _prefsVolumeDialogBackup(100), _prefsReverseStereoBackup(false), _prefsSubtitlesBackup(true),
	_object22Volume(0), _dialPosition(0), _dialLastPosition(-1),
	_object1Visible(true), _jukeboxIndex(0), _chapterIndex(0) {
}

ZoneSystemFaust::~ZoneSystemFaust() {
	// Zero-out passed pointers
	_app = nullptr;
}

void ZoneSystemFaust::onInit() {
	_app->setCurrentZone(kZoneSY);
	_app->objectAdd(kObjectHomunculus, "Homunculus", "a08_Humunculus", 1);
	_app->objectSetActiveCursor(kObjectHomunculus, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectHomunculus, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->puzzleAdd(kPuzzleMenu);
	_app->objectAdd(kObject1, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject1, kPuzzleMenu, Common::Rect(0, 0, 640, 480), false, kCursorDefault, 0);
	_app->objectAddPresentation(kObject1);
	_app->objectPresentationAddTextToPuzzle(kObject1, 0, kPuzzleMenu, "", Common::Point(1, 16),  kFontDefault, Color(0, 0, 0), Color(255, 255, 255));
	_app->objectPresentationAddTextToPuzzle(kObject1, 0, kPuzzleMenu, "", Common::Point(1, 32),  kFontDefault, Color(0, 0, 0), Color(255, 255, 255));
	_app->objectPresentationAddTextToPuzzle(kObject1, 0, kPuzzleMenu, "", Common::Point(1, 48),  kFontDefault, Color(0, 0, 0), Color(255, 255, 255));
	_app->objectPresentationAddTextToPuzzle(kObject1, 0, kPuzzleMenu, "", Common::Point(1, 64),  kFontDefault, Color(0, 0, 0), Color(255, 255, 255));
	_app->objectPresentationAddTextToPuzzle(kObject1, 0, kPuzzleMenu, "", Common::Point(1, 80),  kFontDefault, Color(0, 0, 0), Color(255, 255, 255));
	_app->objectPresentationAddTextToPuzzle(kObject1, 0, kPuzzleMenu, "", Common::Point(1, 96),  kFontDefault, Color(0, 0, 0), Color(255, 255, 255));
	_app->objectPresentationAddTextToPuzzle(kObject1, 0, kPuzzleMenu, "", Common::Point(1, 112), kFontDefault, Color(0, 0, 0), Color(255, 255, 255));
	_app->objectPresentationAddTextToPuzzle(kObject1, 0, kPuzzleMenu, "", Common::Point(1, 128), kFontDefault, Color(0, 0, 0), Color(255, 255, 255));
	_app->objectPresentationAddTextToPuzzle(kObject1, 0, kPuzzleMenu, "", Common::Point(1, 144), kFontDefault, Color(0, 0, 0), Color(255, 255, 255));
	_app->objectPresentationShow(kObject1, 0);
	_app->puzzleAdd(kPuzzleGeneralMenu);
	_app->puzzleAddBackgroundImage(kPuzzleGeneralMenu, "Menu.bmp", Common::Point(0, 0), true);
	_app->puzzleAdd(kPuzzlePreferences);
	_app->puzzleAddBackgroundImage(kPuzzlePreferences, "Login.bmp", Common::Point(0, 0), true);
	_app->objectAdd(kObject6, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject6, kPuzzleMenu, Common::Rect(498, 16, 528, 71), false, kCursorHotspot, 0);
	_app->objectAddPuzzleAccessibility(kObject6, kPuzzleMenu, Common::Rect(0, 0, 640, 72), false, kCursorTake, 1);
	_app->objectAddPresentation(kObject6);
	_app->objectPresentationAddImageToPuzzle(kObject6, 0, kPuzzleMenu, "a12_trak.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 1000);
	_app->objectAddPresentation(kObject6);
	_app->objectPresentationAddImageToPuzzle(kObject6, 1, kPuzzleMenu, "a12_timer.tga", Common::Point(130, 16), true, kDrawTypeAlpha, 1010);
	_app->objectAddPresentation(kObject6);
	_app->objectPresentationAddImageToPuzzle(kObject6, 2, kPuzzleMenu, "a12_timer.tga", Common::Point(130, 46), true, kDrawTypeAlpha, 1010);
	_app->objectAddPresentation(kObject6);
	_app->objectPresentationAddImageToPuzzle(kObject6, 3, kPuzzleMenu, "a12_stairs.0001.tga", Common::Point(477, 16), true, kDrawTypeAlpha, 1005);
	_app->objectAddPresentation(kObject6);
	_app->objectPresentationAddImageToPuzzle(kObject6, 4, kPuzzleMenu, "a12_stairs.0002.tga", Common::Point(477, 16), true, kDrawTypeAlpha, 1005);
	_app->objectAddPresentation(kObject6);
	_app->objectPresentationAddImageToPuzzle(kObject6, 5, kPuzzleMenu, "a12_humunculus.tga", Common::Point(502, 20), true, kDrawTypeAlpha, 1020);
	_app->objectAdd(kObject11, "", "", 1);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 0, kPuzzleMenu, "a11s02n06p07.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 1, kPuzzleMenu, "a11s02n05p03.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 2, kPuzzleMenu, "a11s01n03p02l03.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 3, kPuzzleMenu, "a11s01n08p01l04.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 4, kPuzzleMenu, "a11s01n07p01l03.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 5, kPuzzleMenu, "a11s01n06p01l05.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 6, kPuzzleMenu, "a11s04n02p04l04.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 7, kPuzzleMenu, "a11s04n02p03l04.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 8, kPuzzleMenu, "a11s02n05p01.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 9, kPuzzleMenu, "a11s02n06p10.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 10, kPuzzleMenu, "a11s02n06p10l01.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 11, kPuzzleMenu, "a11s02n06p11.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 12, kPuzzleMenu, "a11s02n06p11l01.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 13, kPuzzleMenu, "a11s02n06p12.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 14, kPuzzleMenu, "a11s02n06p13.tga", Common::Point(163, 32), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 15, kPuzzleMenu, "a11s02n06p13l01.tga", Common::Point(163, 32), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 16, kPuzzleMenu, "a11s02n06p08.tga", Common::Point(0, 74), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 17, kPuzzleMenu, "a11s02n06p08l01.tga", Common::Point(0, 161), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject11);
	_app->objectPresentationAddImageToPuzzle(kObject11, 18, kPuzzleMenu, "a11s04n01p08l05.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 2000);
	_app->objectAdd(kObject12, "", "", 1);
	_app->objectAddPresentation(kObject12);
	_app->objectPresentationAddImageToPuzzle(kObject12, 0, kPuzzleMenu, "a11s04n01p11.tga", Common::Point(118, 130), true, kDrawTypeAlpha, 1100);
	_app->objectPresentationAddImageToPuzzle(kObject12, 0, kPuzzleMenu, "a11s04n01p11l01.tga", Common::Point(244, 210), true, kDrawTypeAlpha, 1200);
	_app->objectAddPresentation(kObject12);
	_app->objectPresentationAddImageToPuzzle(kObject12, 1, kPuzzleMenu, "a11s04n01p11l02.tga", Common::Point(0, 20), true, kDrawTypeAlpha, 1500);
	_app->objectAddPresentation(kObject12);
	_app->objectPresentationAddImageToPuzzle(kObject12, 2, kPuzzleMenu, "a11s04n01p11l01.tga", Common::Point(244, 210), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject12);
	_app->objectPresentationAddImageToPuzzle(kObject12, 3, kPuzzleMenu, "a11s04n01p11l03.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 2000);
	_app->objectAdd(kObject23, "", "Cur_Drag", 5);
	_app->objectSetActiveDrawCursor(kObject23, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveDrawCursor(kObject23, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObject23, kPuzzleMenu, Common::Rect(220, 150, 420, 340), false, kCursorDragDrop, 0);
	_app->objectAddPuzzleAccessibility(kObject23, kPuzzleMenu, Common::Rect(0, 0, 640, 480), false, kCursorBack, 99);
	_app->objectAdd(kObjectCodingWheel, "Coding Wheel", "a11_CodeWheel", 1);
	_app->objectSetActiveCursor(kObjectCodingWheel, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectCodingWheel, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);

	for (uint32 i = 0; i < 36; i++) {
		_app->objectAddPresentation(kObjectCodingWheel);
		_app->objectPresentationAddImageToPuzzle(kObjectCodingWheel, i, kPuzzleMenu, Common::String::format("a11s04n01p16s01.%04d.tga", i + 1), Common::Point(220, 150), true, kDrawTypeAlpha, 1000);
	}

	_app->objectAdd(kObject13, "", "", 1);
	_app->objectAddPresentation(kObject13);
	_app->objectPresentationAddImageToPuzzle(kObject13, 0, kPuzzleMenu, "a11s02n05p02.tga", Common::Point(0, 360), true, kDrawTypeAlpha, 900);
	_app->objectAddPresentation(kObject13);
	_app->objectPresentationAddImageToPuzzle(kObject13, 1, kPuzzleMenu, "a11s02n05p02l01.bmp", Common::Point(33, 395), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject13);
	_app->objectPresentationAddImageToPuzzle(kObject13, 2, kPuzzleMenu, "a11s02n05p02l02.bmp", Common::Point(56, 395), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject13);
	_app->objectPresentationAddImageToPuzzle(kObject13, 3, kPuzzleMenu, "a11s02n05p02l03.bmp", Common::Point(73, 392), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject13);
	_app->objectPresentationAddImageToPuzzle(kObject13, 4, kPuzzleMenu, "a11s02n05p02l04.bmp", Common::Point(93, 392), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject13);
	_app->objectPresentationAddImageToPuzzle(kObject13, 5, kPuzzleMenu, "a11s02n05p02l05.bmp", Common::Point(112, 390), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject13);
	_app->objectPresentationAddImageToPuzzle(kObject13, 6, kPuzzleMenu, "a11s02n05p02l06.bmp", Common::Point(24, 418), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject13);
	_app->objectPresentationAddImageToPuzzle(kObject13, 7, kPuzzleMenu, "a11s02n05p02l07.bmp", Common::Point(39, 414), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject13);
	_app->objectPresentationAddImageToPuzzle(kObject13, 8, kPuzzleMenu, "a11s02n05p02l08.bmp", Common::Point(55, 415), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject13);
	_app->objectPresentationAddImageToPuzzle(kObject13, 9, kPuzzleMenu, "a11s02n05p02l09.bmp", Common::Point(72, 414), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject13);
	_app->objectPresentationAddImageToPuzzle(kObject13, 10, kPuzzleMenu, "a11s02n05p02l10.bmp", Common::Point(104, 420), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject13);
	_app->objectPresentationAddImageToPuzzle(kObject13, 11, kPuzzleMenu, "a11s02n05p02l11.bmp", Common::Point(121, 419), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObject7, "", "", 1);
	_app->objectAddPresentation(kObject7);
	_app->objectPresentationAddImageToPuzzle(kObject7, 0, kPuzzleMenu, "a12s07n01p01.tga", Common::Point(6, 350), true, kDrawTypeAlpha, 1000);
	_app->objectAddPresentation(kObject7);
	_app->objectPresentationAddImageToPuzzle(kObject7, 1, kPuzzleMenu, "a12s07n01p01l01.tga", Common::Point(21, 387), true, kDrawTypeAlpha, 1010);
	_app->objectAddPresentation(kObject7);
	_app->objectPresentationAddImageToPuzzle(kObject7, 2, kPuzzleMenu, "a12s07n01p01l02.tga", Common::Point(80, 387), true, kDrawTypeAlpha, 1010);
	_app->objectAddPresentation(kObject7);
	_app->objectPresentationAddImageToPuzzle(kObject7, 3, kPuzzleMenu, "a12s07n01p01l03.tga", Common::Point(30, 360), true, kDrawTypeAlpha, 1010);
	_app->objectAddPresentation(kObject7);
	_app->objectPresentationAddImageToPuzzle(kObject7, 4, kPuzzleMenu, "a12s07n01p01l04.tga", Common::Point(93, 360), true, kDrawTypeAlpha, 1010);
	_app->objectAdd(kObject8, "", "", 1);
	_app->objectAddPresentation(kObject8);
	_app->objectPresentationAddImageToPuzzle(kObject8, 0, kPuzzleMenu, "a07s01n14r01p01.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 1000);
	_app->objectAddPresentation(kObject8);
	_app->objectPresentationAddImageToPuzzle(kObject8, 1, kPuzzleMenu, "a07s01n14r01p01l01.tga", Common::Point(10, 24), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject8);
	_app->objectPresentationAddImageToPuzzle(kObject8, 2, kPuzzleMenu, "a07s01n14r01p01l01.tga", Common::Point(30, 24), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject8);
	_app->objectPresentationAddImageToPuzzle(kObject8, 3, kPuzzleMenu, "a07s01n14r01p01l01.tga", Common::Point(50, 24), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject8);
	_app->objectPresentationAddImageToPuzzle(kObject8, 4, kPuzzleMenu, "a07s01n14r01p01l01.tga", Common::Point(70, 24), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject8);
	_app->objectPresentationAddImageToPuzzle(kObject8, 5, kPuzzleMenu, "a07s01n14r01p01l01.tga", Common::Point(90, 24), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject8);
	_app->objectPresentationAddImageToPuzzle(kObject8, 6, kPuzzleMenu, "a07s01n14r01p01l01.tga", Common::Point(110, 24), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject8);
	_app->objectPresentationAddImageToPuzzle(kObject8, 7, kPuzzleMenu, "a07s01n14r01p01l01.tga", Common::Point(130, 24), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject8);
	_app->objectPresentationAddImageToPuzzle(kObject8, 8, kPuzzleMenu, "a07s01n14r01p01l01.tga", Common::Point(150, 24), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject8);
	_app->objectPresentationAddImageToPuzzle(kObject8, 9, kPuzzleMenu, "a07s01n14r01p01l01.tga", Common::Point(170, 24), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject8);
	_app->objectPresentationAddImageToPuzzle(kObject8, 10, kPuzzleMenu, "a07s01n14r01p01l01.tga", Common::Point(190, 24), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject8);
	_app->objectPresentationAddImageToPuzzle(kObject8, 11, kPuzzleMenu, "a07s01n14r01p01l01.tga", Common::Point(210, 24), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject8);
	_app->objectPresentationAddImageToPuzzle(kObject8, 12, kPuzzleMenu, "a07s01n14r01p01l01.tga", Common::Point(230, 24), true, kDrawTypeAlpha, 1100);
	_app->objectAdd(kObject9, "", "", 1);
	_app->objectAddPresentation(kObject9);
	_app->objectPresentationAddImageToPuzzle(kObject9, 0, kPuzzleMenu, "a07s01n14r01p01l02.tga", Common::Point(484, 22), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject9);
	_app->objectPresentationAddImageToPuzzle(kObject9, 1, kPuzzleMenu, "a07s01n14r01p01l02.tga", Common::Point(494, 22), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject9);
	_app->objectPresentationAddImageToPuzzle(kObject9, 2, kPuzzleMenu, "a07s01n14r01p01l02.tga", Common::Point(504, 22), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject9);
	_app->objectPresentationAddImageToPuzzle(kObject9, 3, kPuzzleMenu, "a07s01n14r01p01l02.tga", Common::Point(514, 22), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject9);
	_app->objectPresentationAddImageToPuzzle(kObject9, 4, kPuzzleMenu, "a07s01n14r01p01l02.tga", Common::Point(524, 22), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject9);
	_app->objectPresentationAddImageToPuzzle(kObject9, 5, kPuzzleMenu, "a07s01n14r01p01l02.tga", Common::Point(534, 22), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject9);
	_app->objectPresentationAddImageToPuzzle(kObject9, 6, kPuzzleMenu, "a07s01n14r01p01l02.tga", Common::Point(544, 22), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject9);
	_app->objectPresentationAddImageToPuzzle(kObject9, 7, kPuzzleMenu, "a07s01n14r01p01l02.tga", Common::Point(554, 22), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject9);
	_app->objectPresentationAddImageToPuzzle(kObject9, 8, kPuzzleMenu, "a07s01n14r01p01l02.tga", Common::Point(564, 22), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject9);
	_app->objectPresentationAddImageToPuzzle(kObject9, 9, kPuzzleMenu, "a07s01n14r01p01l02.tga", Common::Point(574, 22), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject9);
	_app->objectPresentationAddImageToPuzzle(kObject9, 10, kPuzzleMenu, "a07s01n14r01p01l02.tga", Common::Point(584, 22), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject9);
	_app->objectPresentationAddImageToPuzzle(kObject9, 11, kPuzzleMenu, "a07s01n14r01p01l02.tga", Common::Point(594, 22), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject9);
	_app->objectPresentationAddImageToPuzzle(kObject9, 12, kPuzzleMenu, "a07s01n14r01p01l02.tga", Common::Point(604, 22), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject9);
	_app->objectPresentationAddImageToPuzzle(kObject9, 13, kPuzzleMenu, "a07s01n14r01p01l02.tga", Common::Point(614, 22), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject9);
	_app->objectPresentationAddImageToPuzzle(kObject9, 14, kPuzzleMenu, "a07s01n14r01p01l02.tga", Common::Point(624, 22), true, kDrawTypeAlpha, 1100);
	_app->objectAdd(kObject10, "", "", 1);
	_app->objectAddPresentation(kObject10);
	_app->objectPresentationAddImageToPuzzle(kObject10, 0, kPuzzleMenu, "a07s01n14r01p01l03.tga", Common::Point(270, 18), true, kDrawTypeAlpha, 1100);
	_app->objectAdd(kObject14, "", "", 1);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 0, kPuzzleMenu, "space.tga", Common::Point(0, 440), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 1, kPuzzleMenu, "spacel_d.tga", Common::Point(0, 440), true, kDrawTypeAlpha, 2100);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 2, kPuzzleMenu, "spacel_h.tga", Common::Point(0, 440), true, kDrawTypeAlpha, 2100);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 3, kPuzzleMenu, "spacer_d.tga", Common::Point(440, 440), true, kDrawTypeAlpha, 2100);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 4, kPuzzleMenu, "spacer_h.tga", Common::Point(440, 440), true, kDrawTypeAlpha, 2100);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 5, kPuzzleMenu, "spacer_d.tga", Common::Point(440, 440), true, kDrawTypeAlpha, 2100);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 6, kPuzzleMenu, "spacer_h.tga", Common::Point(440, 440), true, kDrawTypeAlpha, 2100);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 7, kPuzzleMenu, "space_hP.tga", Common::Point(0, 264), true, kDrawTypeAlpha, 2050);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 8, kPuzzleMenu, "space_hA.tga", Common::Point(0, 264), true, kDrawTypeAlpha, 2050);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 9, kPuzzleMenu, "space_m.tga", Common::Point(440, 264), true, kDrawTypeAlpha, 2050);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 10, kPuzzleMenu, "space_n.tga", Common::Point(440, 264), true, kDrawTypeAlpha, 2050);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 11, kPuzzleMenu, "SY_map_A01.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 12, kPuzzleMenu, "SY_map_A01.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 13, kPuzzleMenu, "SY_map_A03.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 14, kPuzzleMenu, "SY_map_A05.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 15, kPuzzleMenu, "SY_map_A06.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 16, kPuzzleMenu, "SY_map_A07.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 17, kPuzzleMenu, "SY_map_A08.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 18, kPuzzleMenu, "SY_map_A09.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 19, kPuzzleMenu, "SY_map_A11.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 20, kPuzzleMenu, "SY_map_A12.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 21, kPuzzleMenu, "SY_map_A13.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 22, kPuzzleMenu, "SY_map_A14.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 23, kPuzzleMenu, "rol_l_j1.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 24, kPuzzleMenu, "rol_l_j2.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 25, kPuzzleMenu, "rol_nat1.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 26, kPuzzleMenu, "rol_nat2.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 27, kPuzzleMenu, "rol_fra1.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 28, kPuzzleMenu, "rol_fra2.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 29, kPuzzleMenu, "rol_kal1.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 30, kPuzzleMenu, "rol_kal2.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 31, kPuzzleMenu, "rol_han1.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 32, kPuzzleMenu, "rol_han2.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 33, kPuzzleMenu, "rol_tod1.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 34, kPuzzleMenu, "rol_tod2.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 35, kPuzzleMenu, "rol_gis1.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 900);
	_app->objectAddPresentation(kObject14);
	_app->objectPresentationAddImageToPuzzle(kObject14, 36, kPuzzleMenu, "rol_gis2.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 900);
	_app->objectAddPuzzleAccessibility(kObject14, kPuzzleMenu, Common::Rect(7, 443, 169, 459), false, kCursorMenuActive, 0);
	_app->objectAddPuzzleAccessibility(kObject14, kPuzzleMenu, Common::Rect(489, 441, 637, 462), false, kCursorMenuActive, 1);
	_app->objectAddPuzzleAccessibility(kObject14, kPuzzleGeneralMenu, Common::Rect(469, 454, 637, 480), false, kCursorMenuActive, 2);
	_app->objectAddPuzzleAccessibility(kObject14, kPuzzleMenu, Common::Rect(67, 329, 103, 411), false, kCursorMenuActive, 3);
	_app->objectAddPuzzleAccessibility(kObject14, kPuzzleMenu, Common::Rect(0, 0, 1, 1), true, kCursorIdle, 4);
	_app->objectSetPuzzleAccessibilityKey(kObject14, 4, Common::KEYCODE_ESCAPE);
	_app->objectAddPuzzleAccessibility(kObject14, kPuzzleMenu, Common::Rect(346, 55, 585, 423), false, kCursorMenuActive, 5);
	_app->objectAddPuzzleAccessibility(kObject14, kPuzzleMenu, Common::Rect( 81, 56, 288, 418), false, kCursorMenuActive, 6);
	_app->objectAddPuzzleAccessibility(kObject14, kPuzzleGeneralMenu, Common::Rect(0, 420, 640, 480), false, kCursorBack, 99);
	_app->objectAdd(kObject15, "", "", 1);
	_app->objectAddPresentation(kObject15);
	_app->objectPresentationAddAnimationToPuzzle(kObject15, 0, kPuzzleMenu, "limbo", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 2200, 183, 15.0f, 6);
	_app->objectAdd(kObject16, "", "", 1);
	_app->objectAddPresentation(kObject16);
	_app->objectPresentationAddImageToPuzzle(kObject16, 0, kPuzzleMenu, "a01s02_mephisto.tga", Common::Point(80, 57), true, kDrawTypeAlpha, 2100);
	_app->objectAdd(kObject17, "", "", 1);
	_app->objectAddPresentation(kObject17);
	_app->objectPresentationAddImageToPuzzle(kObject17, 0, kPuzzleMenu, "a05s03n01p08.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 2100);
	_app->objectAddPuzzleAccessibility(kObject17, kPuzzleMenu, Common::Rect(0, 0, 640, 480), false, kCursorBack, 0);
	_app->objectAdd(kObjectYesNo, "", "", 1);
	_app->objectAddPresentation(kObjectYesNo);
	_app->objectPresentationAddImageToPuzzle(kObjectYesNo, 0, kPuzzleMenu, "Exit.tga", Common::Point(160, 165), true, kDrawTypeAlpha, 2000);
	_app->objectAddPuzzleAccessibility(kObjectYesNo, kPuzzleMenu, Common::Rect(290, 261, 370, 286), false, kCursorMenuActive, 1);
	_app->objectAddPuzzleAccessibility(kObjectYesNo, kPuzzleMenu, Common::Rect(370, 261, 450, 286), false, kCursorMenuActive, 0);
	_app->objectSetPuzzleAccessibilityKey(kObjectYesNo, 0, Common::KEYCODE_RETURN);
	_app->objectSetPuzzleAccessibilityKey(kObjectYesNo, 1, Common::KEYCODE_ESCAPE);
	_app->objectAddPresentation(kObjectYesNo);
	_app->objectPresentationAddImageToPuzzle(kObjectYesNo, 1, kPuzzleMenu, "box_yes.tga", Common::Point(291, 261), true, kDrawTypeAlpha, 2000);
	_app->objectAddPresentation(kObjectYesNo);
	_app->objectPresentationAddImageToPuzzle(kObjectYesNo, 2, kPuzzleMenu, "box_no.tga", Common::Point(371, 261), true, kDrawTypeAlpha, 2000);
	_app->objectAdd(kObject3, "", "", 1);
	_app->objectAddPresentation(kObject3);
	_app->objectPresentationAddImageToPuzzle(kObject3, 0, kPuzzleMenu, "Warning.tga", Common::Point(160, 165), true, kDrawTypeAlpha, 1000);
	_app->objectPresentationAddTextToPuzzle(kObject3, 0, kPuzzleMenu, "", Common::Point(200, 200), kFontDefault, Color(255, 95, 0), Color(-1, -1, -1));
	_app->objectPresentationAddTextToPuzzle(kObject3, 0, kPuzzleMenu, "", Common::Point(300, 280), kFontDefault, Color(255, 95, 0), Color(-1, -1, -1));
	_app->objectAddPresentation(kObject3);
	_app->objectPresentationAddImageToPuzzle(kObject3, 1, kPuzzleMenu, "box_ok.tga", Common::Point(291, 261), true, kDrawTypeAlpha, 1000);
	_app->objectAddPuzzleAccessibility(kObject3, kPuzzleMenu, Common::Rect(286, 261, 363, 307), false, kCursorMenuActive, 0);
	_app->objectSetPuzzleAccessibilityKey(kObject3, 0, Common::KEYCODE_RETURN);
	_app->objectAdd(kObjectQuestion, "", "", 1);
	_app->objectAddPresentation(kObjectQuestion);
	_app->objectPresentationAddImageToPuzzle(kObjectQuestion, 0, kPuzzleMenu, "Question.tga", Common::Point(160, 165), true, kDrawTypeAlpha, 1000);
	_app->objectPresentationAddTextToPuzzle(kObjectQuestion, 0, kPuzzleMenu, "", Common::Point(200, 200), kFontDefault, Color(255, 95, 0), Color(-1, -1, -1));
	_app->objectPresentationAddTextToPuzzle(kObjectQuestion, 0, kPuzzleMenu, "", Common::Point(200, 280), kFontDefault, Color(255, 95, 0), Color(-1, -1, -1));
	_app->objectAddPresentation(kObjectQuestion);
	_app->objectPresentationAddImageToPuzzle(kObjectQuestion, 1, kPuzzleMenu, "box_yes.tga", Common::Point(291, 261), true, kDrawTypeAlpha, 1000);
	_app->objectAddPresentation(kObjectQuestion);
	_app->objectPresentationAddImageToPuzzle(kObjectQuestion, 2, kPuzzleMenu, "box_no.tga", Common::Point(371, 261), true, kDrawTypeAlpha, 1000);
	_app->objectAddPuzzleAccessibility(kObjectQuestion, kPuzzleMenu, Common::Rect(322, 254, 371, 288), false, kCursorMenuActive, 0);
	_app->objectAddPuzzleAccessibility(kObjectQuestion, kPuzzleMenu, Common::Rect(372, 254, 420, 288), false, kCursorMenuActive, 1);
	_app->objectSetPuzzleAccessibilityKey(kObjectQuestion, 0, Common::KEYCODE_RETURN);
	_app->objectSetPuzzleAccessibilityKey(kObjectQuestion, 1, Common::KEYCODE_ESCAPE);
	_app->objectAddPuzzleAccessibility(kObjectQuestion, kPuzzleMenu, Common::Rect(322, 254, 371, 288), false, kCursorMenuActive, 2);
	_app->objectAddPuzzleAccessibility(kObjectQuestion, kPuzzleMenu, Common::Rect(372, 254, 420, 288), false, kCursorMenuActive, 3);
	_app->objectSetPuzzleAccessibilityKey(kObjectQuestion, 2, Common::KEYCODE_RETURN);
	_app->objectSetPuzzleAccessibilityKey(kObjectQuestion, 3, Common::KEYCODE_ESCAPE);
	_app->objectAddPuzzleAccessibility(kObjectQuestion, kPuzzleMenu, Common::Rect(322, 254, 371, 288), false, kCursorMenuActive, 4);
	_app->objectAddPuzzleAccessibility(kObjectQuestion, kPuzzleMenu, Common::Rect(372, 254, 420, 288), false, kCursorMenuActive, 5);
	_app->objectSetPuzzleAccessibilityKey(kObjectQuestion, 4, Common::KEYCODE_RETURN);
	_app->objectSetPuzzleAccessibilityKey(kObjectQuestion, 5, Common::KEYCODE_ESCAPE);
	_app->objectAddPuzzleAccessibility(kObjectQuestion, kPuzzleMenu, Common::Rect(322, 254, 371, 288), false, kCursorMenuActive, 6);
	_app->objectAddPuzzleAccessibility(kObjectQuestion, kPuzzleMenu, Common::Rect(372, 254, 420, 288), false, kCursorMenuActive, 7);
	_app->objectSetPuzzleAccessibilityKey(kObjectQuestion, 6, Common::KEYCODE_RETURN);
	_app->objectSetPuzzleAccessibilityKey(kObjectQuestion, 7, Common::KEYCODE_ESCAPE);
	_app->objectAddPuzzleAccessibility(kObjectQuestion, kPuzzleMenu, Common::Rect(322, 254, 371, 288), false, kCursorMenuActive, 8);
	_app->objectAddPuzzleAccessibility(kObjectQuestion, kPuzzleMenu, Common::Rect(372, 254, 420, 288), false, kCursorMenuActive, 9);
	_app->objectSetPuzzleAccessibilityKey(kObjectQuestion, 8, Common::KEYCODE_RETURN);
	_app->objectSetPuzzleAccessibilityKey(kObjectQuestion, 9, Common::KEYCODE_ESCAPE);
	_app->objectAdd(kObject5, "", "", 1);
	_app->puzzleAdd(kPuzzleInsertCd);
	_app->puzzleAddBackgroundImage(kPuzzleInsertCd, "insertcd.bmp", Common::Point(0, 16), true);
	_app->objectAdd(kObject55, "", "", 1);
	_app->objectAddPresentation(kObject55);
	_app->objectPresentationAddImageToPuzzle(kObject55, 0, kPuzzleInsertCd, "box_yes.tga", Common::Point(291, 261), true, kDrawTypeAlpha, 1000);
	_app->objectAddPresentation(kObject55);
	_app->objectPresentationAddTextToPuzzle(kObject55, 1, kPuzzleInsertCd, "", Common::Point(320, 240), kFontDefault, Color(255, 95, 0), Color(-1, -1, -1));
	_app->objectPresentationAddTextToPuzzle(kObject55, 1, kPuzzleInsertCd, "", Common::Point(320, 260), kFontDefault, Color(255, 95, 0), Color(-1, -1, -1));
	_app->objectAddPresentation(kObject55);
	_app->objectPresentationAddImageToPuzzle(kObject55, 2, kPuzzleInsertCd, "box_no.tga", Common::Point(371, 261), true, kDrawTypeAlpha, 1000);
	_app->objectPresentationShow(kObject55, 1);
	_app->objectAddPuzzleAccessibility(kObject55, kPuzzleInsertCd, Common::Rect(291, 261, 370, 311), true, kCursorMenuActive, 0);
	_app->objectAddPuzzleAccessibility(kObject55, kPuzzleInsertCd, Common::Rect(291, 261, 370, 311), true, kCursorMenuActive, 1);
	_app->objectAddPuzzleAccessibility(kObject55, kPuzzleInsertCd, Common::Rect(291, 261, 370, 311), true, kCursorMenuActive, 2);
	_app->objectAddPuzzleAccessibility(kObject55, kPuzzleInsertCd, Common::Rect(291, 261, 370, 311), true, kCursorMenuActive, 3);
	_app->objectAddPuzzleAccessibility(kObject55, kPuzzleInsertCd, Common::Rect(291, 261, 370, 311), true, kCursorMenuActive, 4);
	_app->objectAddPuzzleAccessibility(kObject55, kPuzzleInsertCd, Common::Rect(291, 261, 370, 311), true, kCursorMenuActive, 5);
	_app->objectAddPuzzleAccessibility(kObject55, kPuzzleInsertCd, Common::Rect(291, 261, 370, 311), true, kCursorMenuActive, 6);
	_app->objectAddPuzzleAccessibility(kObject55, kPuzzleInsertCd, Common::Rect(291, 261, 370, 311), true, kCursorMenuActive, 7);
	_app->objectAddPuzzleAccessibility(kObject55, kPuzzleInsertCd, Common::Rect(291, 261, 370, 311), true, kCursorMenuActive, 8);
	_app->objectAddPuzzleAccessibility(kObject55, kPuzzleInsertCd, Common::Rect(291, 261, 370, 311), true, kCursorMenuActive, 9);
	_app->objectAddPuzzleAccessibility(kObject55, kPuzzleInsertCd, Common::Rect(371, 261, 450, 311), true, kCursorMenuActive, 99);
	_app->objectSetPuzzleAccessibilityKey(kObject55, 0, Common::KEYCODE_RETURN);
	_app->objectSetPuzzleAccessibilityKey(kObject55, 1, Common::KEYCODE_RETURN);
	_app->objectSetPuzzleAccessibilityKey(kObject55, 2, Common::KEYCODE_RETURN);
	_app->objectSetPuzzleAccessibilityKey(kObject55, 3, Common::KEYCODE_RETURN);
	_app->objectSetPuzzleAccessibilityKey(kObject55, 4, Common::KEYCODE_RETURN);
	_app->objectSetPuzzleAccessibilityKey(kObject55, 5, Common::KEYCODE_RETURN);
	_app->objectSetPuzzleAccessibilityKey(kObject55, 6, Common::KEYCODE_RETURN);
	_app->objectSetPuzzleAccessibilityKey(kObject55, 7, Common::KEYCODE_RETURN);
	_app->objectSetPuzzleAccessibilityKey(kObject55, 8, Common::KEYCODE_RETURN);
	_app->objectSetPuzzleAccessibilityKey(kObject55, 9, Common::KEYCODE_RETURN);
	_app->objectSetPuzzleAccessibilityKey(kObject55, 10, Common::KEYCODE_ESCAPE);
	_app->objectAdd(kObject99500, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99500, kPuzzlePreferences, Common::Rect(132, 413, 252, 440), true, kCursorMenuActive, 1);
	_app->objectAddPuzzleAccessibility(kObject99500, kPuzzlePreferences, Common::Rect(387, 413, 507, 440), true, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99500);
	_app->objectPresentationAddImageToPuzzle(kObject99500, 0, kPuzzlePreferences, "log_l1h.bmp", Common::Point(132, 413), true, kDrawTypeNormal, 1100);
	_app->objectAddPresentation(kObject99500);
	_app->objectPresentationAddImageToPuzzle(kObject99500, 1, kPuzzlePreferences, "log_r1h.bmp", Common::Point(387, 413), true, kDrawTypeNormal, 1100);
	_app->objectSetPuzzleAccessibilityKey(kObject99500, 0, Common::KEYCODE_RETURN);
	_app->objectAdd(kObject99501, "", "", 1);
	_app->objectAddPresentation(kObject99501);
	_app->objectPresentationAddAnimationToPuzzle(kObject99501, 0, kPuzzlePreferences, "kybcur", kImageTypeBMP, Common::Point(0, 0), kDrawTypeNormal, 1000, 6, 12.5f, 16);
	_app->objectPresentationSetAnimationCoordinatesOnPuzzle(kObject99501, 0, Common::Point(233, 334));
	_app->objectPresentationAddTextToPuzzle(kObject99501, 0, kPuzzlePreferences, "", Common::Point(230, 334), kFontDefault, Color(255, 255, 255), Color(-1, -1, -1));
	_app->objectPresentationShow(kObject99501);
	_app->objectAdd(kObject99600, "", "", 1);
	_app->objectAddPresentation(kObject99600);
	_app->objectPresentationAddImageToPuzzle(kObject99600, 0, kPuzzleGeneralMenu, "Evidence_01.bmp", Common::Point(172, 452), true, kDrawTypeNormal, 6000);
	_app->objectAddPresentation(kObject99600);
	_app->objectPresentationAddImageToPuzzle(kObject99600, 1, kPuzzleGeneralMenu, "Evidence_02.bmp", Common::Point(213, 452), true, kDrawTypeNormal, 6000);
	_app->objectAddPresentation(kObject99600);
	_app->objectPresentationAddImageToPuzzle(kObject99600, 2, kPuzzleGeneralMenu, "Evidence_03.bmp", Common::Point(255, 452), true, kDrawTypeNormal, 6000);
	_app->objectAddPresentation(kObject99600);
	_app->objectPresentationAddImageToPuzzle(kObject99600, 3, kPuzzleGeneralMenu, "Evidence_04.bmp", Common::Point(297, 452), true, kDrawTypeNormal, 6000);
	_app->objectAddPresentation(kObject99600);
	_app->objectPresentationAddImageToPuzzle(kObject99600, 4, kPuzzleGeneralMenu, "Evidence_05.bmp", Common::Point(339, 452), true, kDrawTypeNormal, 6000);
	_app->objectAddPresentation(kObject99600);
	_app->objectPresentationAddImageToPuzzle(kObject99600, 5, kPuzzleGeneralMenu, "Evidence_06.bmp", Common::Point(381, 452), true, kDrawTypeNormal, 6000);
	_app->objectAddPresentation(kObject99600);
	_app->objectPresentationAddImageToPuzzle(kObject99600, 6, kPuzzleGeneralMenu, "Evidence_07.bmp", Common::Point(423, 452), true, kDrawTypeNormal, 6000);
	_app->objectAddPresentation(kObject99600);
	_app->objectPresentationAddImageToPuzzle(kObject99600, 7, kPuzzleGeneralMenu, "notebook.tga", Common::Point(456, 453), true, kDrawTypeAlpha, 6000);
	_app->objectAdd(kObject99010, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99010, kPuzzleGeneralMenu, Common::Rect(7, 19, 38, 49), true, kCursorMenuActive, 0);
	_app->objectAddPuzzleAccessibility(kObject99010, kPuzzleGeneralMenu, Common::Rect(600, 19, 633, 50), true, kCursorMenuActive, 1);
	_app->objectAddPresentation(kObject99010);
	_app->objectPresentationAddAnimationToPuzzle(kObject99010, 0, kPuzzleGeneralMenu, "main", kImageTypeBMP, Common::Point(154, 50), kDrawTypeNormal, 2000, 63, 15.0f, 5);
	_app->objectAddPresentation(kObject99010);
	_app->objectPresentationAddImageToPuzzle(kObject99010, 1, kPuzzleGeneralMenu, "tit_ln.bmp", Common::Point(9, 22), true, kDrawTypeNormal, 2000);
	_app->objectAddPresentation(kObject99010);
	_app->objectPresentationAddImageToPuzzle(kObject99010, 2, kPuzzleGeneralMenu, "tit_lh.bmp", Common::Point(9, 22), true, kDrawTypeNormal, 2100);
	_app->objectAddPresentation(kObject99010);
	_app->objectPresentationAddImageToPuzzle(kObject99010, 3, kPuzzleGeneralMenu, "tit_rn.bmp", Common::Point(603, 22), true, kDrawTypeNormal, 2000);
	_app->objectAddPresentation(kObject99010);
	_app->objectPresentationAddImageToPuzzle(kObject99010, 4, kPuzzleGeneralMenu, "tit_rh.bmp", Common::Point(603, 22), true, kDrawTypeNormal, 2100);
	_app->objectAdd(kObject99011, "", "", 3);
	_app->objectAddPresentation(kObject99011);
	_app->objectPresentationAddImageToPuzzle(kObject99011, 0, kPuzzleGeneralMenu, "tit_e00.bmp", Common::Point(48, 20), true, kDrawTypeNormal, 2000);
	_app->objectAddPresentation(kObject99011);
	_app->objectPresentationAddImageToPuzzle(kObject99011, 1, kPuzzleGeneralMenu, "tit_e01.bmp", Common::Point(48, 20), true, kDrawTypeNormal, 2000);
	_app->objectAddPresentation(kObject99011);
	_app->objectPresentationAddImageToPuzzle(kObject99011, 2, kPuzzleGeneralMenu, "tit_e02.bmp", Common::Point(48, 20), true, kDrawTypeNormal, 2000);
	_app->objectAddPresentation(kObject99011);
	_app->objectPresentationAddImageToPuzzle(kObject99011, 3, kPuzzleGeneralMenu, "tit_e03.bmp", Common::Point(48, 20), true, kDrawTypeNormal, 2000);
	_app->objectAddPresentation(kObject99011);
	_app->objectPresentationAddImageToPuzzle(kObject99011, 4, kPuzzleGeneralMenu, "tit_e04.bmp", Common::Point(48, 20), true, kDrawTypeNormal, 2000);
	_app->objectAddPresentation(kObject99011);
	_app->objectPresentationAddImageToPuzzle(kObject99011, 5, kPuzzleGeneralMenu, "tit_e05.bmp", Common::Point(48, 20), true, kDrawTypeNormal, 2000);
	_app->objectAddPresentation(kObject99011);
	_app->objectPresentationAddImageToPuzzle(kObject99011, 6, kPuzzleGeneralMenu, "tit_e06.bmp", Common::Point(48, 20), true, kDrawTypeNormal, 2000);
	_app->objectAddPresentation(kObject99011);
	_app->objectPresentationAddImageToPuzzle(kObject99011, 7, kPuzzleGeneralMenu, "tit_e07.bmp", Common::Point(48, 20), true, kDrawTypeNormal, 2000);
	_app->objectPresentationShow(kObject99011, 0);
	_app->objectAdd(kObject99012, "", "", 3);
	_app->objectAddPresentation(kObject99012);
	_app->objectPresentationAddImageToPuzzle(kObject99012, 0, kPuzzleGeneralMenu, "main.bmp", Common::Point(130, 50), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObject99000, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99000, kPuzzleGeneralMenu, Common::Rect(0, 135, 120, 162), true, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99000);
	_app->objectPresentationAddImageToPuzzle(kObject99000, 0, kPuzzleGeneralMenu, "But_l1h.bmp", Common::Point(0, 135), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject99000);
	_app->objectPresentationAddImageToPuzzle(kObject99000, 1, kPuzzleGeneralMenu, "But_l1d.bmp", Common::Point(0, 135), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObject99001, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99001, kPuzzleGeneralMenu, Common::Rect(0, 185, 120, 212), true, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99001);
	_app->objectPresentationAddImageToPuzzle(kObject99001, 0, kPuzzleGeneralMenu, "But_l2h.bmp", Common::Point(0, 185), true, kDrawTypeNormal, 1200);
	_app->objectAddPresentation(kObject99001);
	_app->objectPresentationAddImageToPuzzle(kObject99001, 1, kPuzzleGeneralMenu, "But_l2d.bmp", Common::Point(0, 185), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject99001);
	_app->objectPresentationAddImageToPuzzle(kObject99001, 2, kPuzzleGeneralMenu, "Load.bmp", Common::Point(130, 50), true, kDrawTypeNormal, 2000);
	_app->objectAdd(kObject99002, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99002, kPuzzleGeneralMenu, Common::Rect(0, 235, 120, 262), true, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99002);
	_app->objectPresentationAddImageToPuzzle(kObject99002, 0, kPuzzleGeneralMenu, "But_l3h.bmp", Common::Point(0, 235), true, kDrawTypeNormal, 1200);
	_app->objectAddPresentation(kObject99002);
	_app->objectPresentationAddImageToPuzzle(kObject99002, 1, kPuzzleGeneralMenu, "But_l3d.bmp", Common::Point(0, 235), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject99002);
	_app->objectPresentationAddImageToPuzzle(kObject99002, 2, kPuzzleGeneralMenu, "Save.bmp", Common::Point(130, 50), true, kDrawTypeNormal, 2000);
	_app->objectAdd(kObject99003, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99003, kPuzzleGeneralMenu, Common::Rect(0, 285, 120, 312), true, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99003);
	_app->objectPresentationAddImageToPuzzle(kObject99003, 0, kPuzzleGeneralMenu, "But_l4h.bmp", Common::Point(0, 285), true, kDrawTypeNormal, 1200);
	_app->objectAddPresentation(kObject99003);
	_app->objectPresentationAddImageToPuzzle(kObject99003, 1, kPuzzleGeneralMenu, "But_l4d.bmp", Common::Point(0, 285), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject99003);
	_app->objectPresentationAddImageToPuzzle(kObject99003, 2, kPuzzleGeneralMenu, "Preferences.bmp", Common::Point(130, 50), true, kDrawTypeNormal, 2000);
	_app->objectAdd(kObject99004, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99004, kPuzzleGeneralMenu, Common::Rect(0, 335, 120, 362), true, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99004);
	_app->objectPresentationAddImageToPuzzle(kObject99004, 0, kPuzzleGeneralMenu, "But_l5h.bmp", Common::Point(0, 335), true, kDrawTypeNormal, 1200);
	_app->objectAddPresentation(kObject99004);
	_app->objectPresentationAddImageToPuzzle(kObject99004, 1, kPuzzleGeneralMenu, "But_l5d.bmp", Common::Point(0, 335), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject99004);
	_app->objectPresentationAddTextToPuzzle(kObject99004, 2, kPuzzleGeneralMenu, "", Common::Point(1, 16), kFontDefault, Color(0, 0, 0), Color(255, 255, 255));
	_app->objectAdd(kObject99005, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99005, kPuzzleGeneralMenu, Common::Rect(520, 135, 640, 162), true, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99005);
	_app->objectPresentationAddImageToPuzzle(kObject99005, 0, kPuzzleGeneralMenu, "But_r1h.bmp", Common::Point(520, 135), true, kDrawTypeNormal, 1200);
	_app->objectAddPresentation(kObject99005);
	_app->objectPresentationAddImageToPuzzle(kObject99005, 1, kPuzzleGeneralMenu, "But_r1d.bmp", Common::Point(520, 135), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject99005);
	_app->objectPresentationAddImageToPuzzle(kObject99005, 2, kPuzzleGeneralMenu, "stars_e01.bmp", Common::Point(130, 50), true, kDrawTypeNormal, 2200);
	_app->objectAddPresentation(kObject99005);
	_app->objectPresentationAddImageToPuzzle(kObject99005, 3, kPuzzleGeneralMenu, "stars_e02.bmp", Common::Point(130, 50), true, kDrawTypeNormal, 2200);
	_app->objectAddPresentation(kObject99005);
	_app->objectPresentationAddImageToPuzzle(kObject99005, 4, kPuzzleGeneralMenu, "stars_e03.bmp", Common::Point(130, 50), true, kDrawTypeNormal, 2200);
	_app->objectAddPresentation(kObject99005);
	_app->objectPresentationAddImageToPuzzle(kObject99005, 5, kPuzzleGeneralMenu, "stars_e04.bmp", Common::Point(130, 50), true, kDrawTypeNormal, 2200);
	_app->objectAddPresentation(kObject99005);
	_app->objectPresentationAddImageToPuzzle(kObject99005, 6, kPuzzleGeneralMenu, "stars_e05.bmp", Common::Point(130, 50), true, kDrawTypeNormal, 2200);
	_app->objectAddPresentation(kObject99005);
	_app->objectPresentationAddImageToPuzzle(kObject99005, 7, kPuzzleGeneralMenu, "stars_e06.bmp", Common::Point(130, 50), true, kDrawTypeNormal, 2200);
	_app->objectAddPresentation(kObject99005);
	_app->objectPresentationAddImageToPuzzle(kObject99005, 8, kPuzzleGeneralMenu, "stars_e07.bmp", Common::Point(130, 50), true, kDrawTypeNormal, 2200);
	_app->objectAdd(kObject99006, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99006, kPuzzleGeneralMenu, Common::Rect(520, 185, 640, 212), true, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99006);
	_app->objectPresentationAddImageToPuzzle(kObject99006, 0, kPuzzleGeneralMenu, "But_r2h.bmp", Common::Point(520, 185), true, kDrawTypeNormal, 1200);
	_app->objectAddPresentation(kObject99006);
	_app->objectPresentationAddImageToPuzzle(kObject99006, 1, kPuzzleGeneralMenu, "But_r2d.bmp", Common::Point(520, 185), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject99006);
	_app->objectPresentationAddImageToPuzzle(kObject99006, 2, kPuzzleGeneralMenu, "Movies.bmp", Common::Point(130, 50), true, kDrawTypeNormal, 2200);
	_app->objectAdd(kObject99007, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99007, kPuzzleGeneralMenu, Common::Rect(520, 235, 640, 262), true, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99007);
	_app->objectPresentationAddImageToPuzzle(kObject99007, 0, kPuzzleGeneralMenu, "But_r3h.bmp", Common::Point(520, 235), true, kDrawTypeNormal, 1200);
	_app->objectAddPresentation(kObject99007);
	_app->objectPresentationAddImageToPuzzle(kObject99007, 1, kPuzzleGeneralMenu, "But_r3d.bmp", Common::Point(520, 235), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject99007);
	_app->objectPresentationAddImageToPuzzle(kObject99007, 2, kPuzzleGeneralMenu, "Music.bmp", Common::Point(130, 50), true, kDrawTypeNormal, 2200);
	_app->objectAdd(kObject99008, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99008, kPuzzleGeneralMenu, Common::Rect(520, 285, 640, 312), true, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99008);
	_app->objectPresentationAddImageToPuzzle(kObject99008, 0, kPuzzleGeneralMenu, "But_r4h.bmp", Common::Point(520, 285), true, kDrawTypeNormal, 1200);
	_app->objectAddPresentation(kObject99008);
	_app->objectPresentationAddImageToPuzzle(kObject99008, 1, kPuzzleGeneralMenu, "But_r4d.bmp", Common::Point(520, 285), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject99008);
	_app->objectPresentationAddImageToPuzzle(kObject99008, 2, kPuzzleGeneralMenu, "Status.bmp", Common::Point(130, 50), true, kDrawTypeNormal, 2200);
	_app->objectAdd(kObject99009, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99009, kPuzzleGeneralMenu, Common::Rect(520, 335, 640, 362), true, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99009);
	_app->objectPresentationAddImageToPuzzle(kObject99009, 0, kPuzzleGeneralMenu, "But_r5h.bmp", Common::Point(520, 335), true, kDrawTypeNormal, 1200);
	_app->objectAddPresentation(kObject99009);
	_app->objectPresentationAddImageToPuzzle(kObject99009, 1, kPuzzleGeneralMenu, "But_r5d.bmp", Common::Point(520, 335), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject99009);
	_app->objectPresentationAddImageToPuzzle(kObject99009, 2, kPuzzleGeneralMenu, "Attraction.bmp", Common::Point(130, 50), true, kDrawTypeNormal, 2200);
	_app->objectAdd(kObject99021, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99021, kPuzzleGeneralMenu, Common::Rect(259, 413, 379, 440), false, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99021);
	_app->objectPresentationAddImageToPuzzle(kObject99021, 0, kPuzzleGeneralMenu, "but_d2h.bmp", Common::Point(259, 413), true, kDrawTypeNormal, 2400);
	_app->objectAddPresentation(kObject99021);
	_app->objectPresentationAddImageToPuzzle(kObject99021, 1, kPuzzleGeneralMenu, "but_d2d.bmp", Common::Point(259, 413), true, kDrawTypeNormal, 2300);
	_app->objectAddPresentation(kObject99021);
	_app->objectPresentationAddImageToPuzzle(kObject99021, 2, kPuzzleGeneralMenu, "but_d2n.bmp", Common::Point(259, 413), true, kDrawTypeNormal, 2300);
	_app->objectAdd(kObject99022, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99022, kPuzzleGeneralMenu, Common::Rect(386, 413, 506, 440), false, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99022);
	_app->objectPresentationAddImageToPuzzle(kObject99022, 0, kPuzzleGeneralMenu, "but_d3h.bmp", Common::Point(386, 413), true, kDrawTypeNormal, 2400);
	_app->objectAddPresentation(kObject99022);
	_app->objectPresentationAddImageToPuzzle(kObject99022, 1, kPuzzleGeneralMenu, "but_d3d.bmp", Common::Point(386, 413), true, kDrawTypeNormal, 2300);
	_app->objectAddPresentation(kObject99022);
	_app->objectPresentationAddImageToPuzzle(kObject99022, 2, kPuzzleGeneralMenu, "but_d3n.bmp", Common::Point(386, 413), true, kDrawTypeNormal, 2300);
	_app->objectSetPuzzleAccessibilityKey(kObject99022, 0, Common::KEYCODE_ESCAPE);
	_app->objectAdd(kObject99023, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99023, kPuzzleGeneralMenu, Common::Rect(131, 413, 251, 440), false, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99023);
	_app->objectPresentationAddImageToPuzzle(kObject99023, 0, kPuzzleGeneralMenu, "but_d1h.bmp", Common::Point(131, 413), true, kDrawTypeNormal, 2400);
	_app->objectAddPresentation(kObject99023);
	_app->objectPresentationAddImageToPuzzle(kObject99023, 1, kPuzzleGeneralMenu, "but_d1d.bmp", Common::Point(131, 413), true, kDrawTypeNormal, 2300);
	_app->objectAddPresentation(kObject99023);
	_app->objectPresentationAddImageToPuzzle(kObject99023, 2, kPuzzleGeneralMenu, "but_d1n.bmp", Common::Point(131, 413), true, kDrawTypeNormal, 2300);
	_app->objectSetPuzzleAccessibilityKey(kObject99023, 0, Common::KEYCODE_RETURN);
	_app->objectAdd(kObject99024, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99024, kPuzzleGeneralMenu, Common::Rect(386, 413, 506, 440), false, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99024);
	_app->objectPresentationAddImageToPuzzle(kObject99024, 0, kPuzzleGeneralMenu, "but_d3h.bmp", Common::Point(386, 413), true, kDrawTypeNormal, 2400);
	_app->objectAddPresentation(kObject99024);
	_app->objectPresentationAddImageToPuzzle(kObject99024, 1, kPuzzleGeneralMenu, "but_d3d.bmp", Common::Point(386, 413), true, kDrawTypeNormal, 2300);
	_app->objectAddPresentation(kObject99024);
	_app->objectPresentationAddImageToPuzzle(kObject99024, 2, kPuzzleGeneralMenu, "but_d3n.bmp", Common::Point(386, 413), true, kDrawTypeNormal, 2300);
	_app->objectSetPuzzleAccessibilityKey(kObject99024, 0, Common::KEYCODE_ESCAPE);
	_app->objectAdd(kObject99025, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99025, kPuzzleGeneralMenu, Common::Rect(131, 413, 251, 440), false, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99025);
	_app->objectPresentationAddImageToPuzzle(kObject99025, 0, kPuzzleGeneralMenu, "but_d1h.bmp", Common::Point(131, 413), true, kDrawTypeNormal, 2400);
	_app->objectAddPresentation(kObject99025);
	_app->objectPresentationAddImageToPuzzle(kObject99025, 1, kPuzzleGeneralMenu, "but_d1d.bmp", Common::Point(131, 413), true, kDrawTypeNormal, 2300);
	_app->objectAddPresentation(kObject99025);
	_app->objectPresentationAddImageToPuzzle(kObject99025, 2, kPuzzleGeneralMenu, "but_d1n.bmp", Common::Point(131, 413), true, kDrawTypeNormal, 2300);
	_app->objectSetPuzzleAccessibilityKey(kObject99025, 0, Common::KEYCODE_RETURN);
	_app->objectAdd(kObject99041, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99041, kPuzzleGeneralMenu, Common::Rect(386, 413, 506, 440), false, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99041);
	_app->objectPresentationAddImageToPuzzle(kObject99041, 0, kPuzzleGeneralMenu, "but_d3h.bmp", Common::Point(386, 413), true, kDrawTypeNormal, 2400);
	_app->objectAddPresentation(kObject99041);
	_app->objectPresentationAddImageToPuzzle(kObject99041, 1, kPuzzleGeneralMenu, "but_d3d.bmp", Common::Point(386, 413), true, kDrawTypeNormal, 2300);
	_app->objectAddPresentation(kObject99041);
	_app->objectPresentationAddImageToPuzzle(kObject99041, 2, kPuzzleGeneralMenu, "but_d3n.bmp", Common::Point(386, 413), true, kDrawTypeNormal, 2300);
	_app->objectSetPuzzleAccessibilityKey(kObject99041, 0, Common::KEYCODE_ESCAPE);
	_app->objectAdd(kObject99042, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99042, kPuzzleGeneralMenu, Common::Rect(131, 413, 251, 440), false, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99042);
	_app->objectPresentationAddImageToPuzzle(kObject99042, 0, kPuzzleGeneralMenu, "but_d1h.bmp", Common::Point(131, 413), true, kDrawTypeNormal, 2400);
	_app->objectAddPresentation(kObject99042);
	_app->objectPresentationAddImageToPuzzle(kObject99042, 1, kPuzzleGeneralMenu, "but_d1d.bmp", Common::Point(131, 413), true, kDrawTypeNormal, 2300);
	_app->objectAddPresentation(kObject99042);
	_app->objectPresentationAddImageToPuzzle(kObject99042, 2, kPuzzleGeneralMenu, "but_d1n.bmp", Common::Point(131, 413), true, kDrawTypeNormal, 2300);
	_app->objectSetPuzzleAccessibilityKey(kObject99042, 0, Common::KEYCODE_RETURN);
	_app->objectAdd(kObject99043, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99043, kPuzzleGeneralMenu, Common::Rect(338, 316, 405, 342), false, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99043);
	_app->objectPresentationAddImageToPuzzle(kObject99043, 0, kPuzzleGeneralMenu, "Pref_off.tga", Common::Point(300, 322), true, kDrawTypeAlpha, 2200);
	_app->objectAddPresentation(kObject99043);
	_app->objectPresentationAddImageToPuzzle(kObject99043, 1, kPuzzleGeneralMenu, "Pref_on.tga", Common::Point(300, 322), true, kDrawTypeAlpha, 2200);
	_app->objectAdd(kObject99044, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99044, kPuzzleGeneralMenu, Common::Rect(338, 251, 405, 277), false, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99044);
	_app->objectPresentationAddImageToPuzzle(kObject99044, 0, kPuzzleGeneralMenu, "Pref_nor.tga", Common::Point(300, 257), true, kDrawTypeAlpha, 2200);
	_app->objectAddPresentation(kObject99044);
	_app->objectPresentationAddImageToPuzzle(kObject99044, 1, kPuzzleGeneralMenu, "Pref_rev.tga", Common::Point(300, 257), true, kDrawTypeAlpha, 2300);
	_app->objectAdd(kObject99045, "", "CUR_DRAG", 4);
	_app->objectSetActiveDrawCursor(kObject99045, Common::Point(15, 15), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveDrawCursor(kObject99045, Common::Point(15, 15), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObject99045, kPuzzleGeneralMenu, Common::Rect(150, 160, 492, 184), false, kCursorDragDrop, 0);
	_app->objectAddPresentation(kObject99045);
	_app->objectPresentationAddImageToPuzzle(kObject99045, 0, kPuzzleGeneralMenu, "Volume.tga", Common::Point(0, 0), true, kDrawTypeAlpha, 2200);
	_app->objectAdd(kObject99046, "", "CUR_DRAG", 4);
	_app->objectSetActiveDrawCursor(kObject99046, Common::Point(15, 15), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveDrawCursor(kObject99046, Common::Point(15, 15), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObject99046, kPuzzleGeneralMenu, Common::Rect(150, 204, 492, 228), false, kCursorDragDrop, 0);
	_app->objectAddPresentation(kObject99046);
	_app->objectPresentationAddImageToPuzzle(kObject99046, 0, kPuzzleGeneralMenu, "Volume.tga", Common::Point(0, 0), true, kDrawTypeAlpha, 2200);
	_app->objectAdd(kObject99601, "", "", 1);
	_app->objectAddPresentation(kObject99601);
	_app->objectPresentationAddAnimationToPuzzle(kObject99601, 0, kPuzzleGeneralMenu, "kybcur", kImageTypeBMP, Common::Point(0, 0), kDrawTypeNormal, 2300, 6, 12.5f, 16);
	_app->objectPresentationSetAnimationCoordinatesOnPuzzle(kObject99601, 0, Common::Point(192, 388));
	_app->objectAddPresentation(kObject99601);
	_app->objectPresentationAddTextToPuzzle(kObject99601, 1, kPuzzleGeneralMenu, "", Common::Point(230, 382), kFontDefault, Color(255, 255, 255), Color(-1, -1, -1));
	_app->objectAddPresentation(kObject99601);

	_app->setArchiveType(kArchiveFile);
	_app->setLoadFrom(kLoadFrom5);
	_app->objectPresentationAddImageToPuzzle(kObject99601, 2, kPuzzleGeneralMenu, "osc.bmp", Common::Point(240, 82), true, kDrawTypeNormal, 5000);
	_app->setLoadFrom(kLoadFromDisk);
	_app->setArchiveType(_app->getZoneArchiveType(kZoneSY));

	_app->objectAdd(kObject99070, "", "", 1);
	_app->objectAddPresentation(kObject99070);
	_app->objectPresentationAddAnimationToPuzzle(kObject99070, 0, kPuzzleGeneralMenu, "movies", kImageTypeBMP, Common::Point(137, 52), kDrawTypeNormal, 2500, 36, 15.0f, 5);
	_app->objectPresentationAddImageToPuzzle(kObject99070, 0, kPuzzleGeneralMenu, "tit_movies.bmp", Common::Point(48, 20), true, kDrawTypeNormal, 2200);
	_app->objectAdd(kObject99071, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99071, kPuzzleGeneralMenu, Common::Rect(200, 220, 430, 399), false, kCursorMenuActive, 0);

	for (uint32 i = 0; i < 32; i++) {
		_app->objectAddPresentation(kObject99071);
		_app->objectPresentationAddImageToPuzzle(kObject99071, i, kPuzzleGeneralMenu, Common::String::format("mov_tit%02d.bmp", i), Common::Point(130, 214), true, kDrawTypeNormal, 2200);
	}

	_app->objectAdd(kObject99080, "", "", 1);
	_app->objectAddPresentation(kObject99080);
	_app->objectPresentationAddAnimationToPuzzle(kObject99080, 0, kPuzzleGeneralMenu, "music", kImageTypeBMP, Common::Point(204, 66), kDrawTypeNormal, 2500, 4, 15.0f, 5);
	_app->objectPresentationAddImageToPuzzle(kObject99080, 0, kPuzzleGeneralMenu, "tit_music.bmp", Common::Point(48, 20), true, kDrawTypeNormal, 2200);
	_app->objectAdd(kObject99081, "", "", 1);

	for (uint32 i = 0; i < 13; i++) {
		_app->objectAddPresentation(kObject99081);
		_app->objectPresentationAddImageToPuzzle(kObject99081, i, kPuzzleGeneralMenu, Common::String::format("mus_tit%02d.bmp", i + 1), Common::Point(135, 300), true, kDrawTypeNormal, 2200);
	}

	_app->objectAdd(kObject99090, "", "", 1);
	_app->objectAddPresentation(kObject99090);
	_app->objectPresentationAddAnimationToPuzzle(kObject99090, 0, kPuzzleGeneralMenu, "status", kImageTypeBMP, Common::Point(181, 102), kDrawTypeNormal, 2500, 50, 15.0f, 6);
	_app->objectPresentationAddImageToPuzzle(kObject99090, 0, kPuzzleGeneralMenu, "tit_status.bmp", Common::Point(48, 20), true, kDrawTypeNormal, 2200);
	_app->objectAdd(kObject99091, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99091, kPuzzleGeneralMenu, Common::Rect(200, 120, 450, 150), false, kCursorMenuActive, 1);
	_app->objectAddPuzzleAccessibility(kObject99091, kPuzzleGeneralMenu, Common::Rect(200, 240, 450, 270), false, kCursorMenuActive, 2);
	_app->objectAddPuzzleAccessibility(kObject99091, kPuzzleGeneralMenu, Common::Rect(200, 360, 450, 390), false, kCursorMenuActive, 3);
	_app->objectAddPresentation(kObject99091);
	_app->objectPresentationAddImageToPuzzle(kObject99091, 0, kPuzzleGeneralMenu, "tit_attraction.bmp", Common::Point(48, 20), true, kDrawTypeNormal, 2200);
	_app->objectAddPresentation(kObject99091);
	_app->objectPresentationAddImageToPuzzle(kObject99091, 1, kPuzzleGeneralMenu, "att_01.bmp", Common::Point(200, 118), true, kDrawTypeNormal, 2200);
	_app->objectAddPresentation(kObject99091);
	_app->objectPresentationAddImageToPuzzle(kObject99091, 2, kPuzzleGeneralMenu, "att_02.bmp", Common::Point(200, 238), true, kDrawTypeNormal, 2200);
	_app->objectAddPresentation(kObject99091);
	_app->objectPresentationAddImageToPuzzle(kObject99091, 3, kPuzzleGeneralMenu, "att_03.bmp", Common::Point(200, 358), true, kDrawTypeNormal, 2200);
	_app->objectAdd(kObject99100, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99100, kPuzzleGeneralMenu, Common::Rect(0, 454, 50, 480), false, kCursorMenuActive, 0);
	_app->objectAdd(kObject99097, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject99097, kPuzzleGeneralMenu, Common::Rect(261, 414, 381, 444), false, kCursorMenuActive, 0);
	_app->objectAddPresentation(kObject99097);
	_app->objectPresentationAddImageToPuzzle(kObject99097, 0, kPuzzleGeneralMenu, "but_d4h.bmp", Common::Point(261, 414), true, kDrawTypeNormal, 2400);
	_app->objectAddPresentation(kObject99097);
	_app->objectPresentationAddImageToPuzzle(kObject99097, 1, kPuzzleGeneralMenu, "but_d4d.bmp", Common::Point(261, 414), true, kDrawTypeNormal, 2300);
	_app->objectAddPresentation(kObject99097);
	_app->objectPresentationAddImageToPuzzle(kObject99097, 2, kPuzzleGeneralMenu, "but_d4n.bmp", Common::Point(261, 414), true, kDrawTypeNormal, 2300);
	_app->objectSetPuzzleAccessibilityKey(kObject99097, 0, Common::KEYCODE_ESCAPE);
	_app->objectAdd(kObject25, "", "", 1);
	_app->objectAddPresentation(kObject25);
	_app->objectPresentationAddImageToPuzzle(kObject25, 0, kPuzzleMenu, "dat01_1.bmp", Common::Point(0, 464), true, kDrawTypeNormal, 3000);
	_app->objectAddPresentation(kObject25);
	_app->objectPresentationAddImageToPuzzle(kObject25, 1, kPuzzleMenu, "dat02_2.bmp", Common::Point(0, 464), true, kDrawTypeNormal, 3000);
	_app->objectAddPresentation(kObject25);
	_app->objectPresentationAddImageToPuzzle(kObject25, 2, kPuzzleMenu, "dat03_2.bmp", Common::Point(0, 464), true, kDrawTypeNormal, 3000);
	_app->objectAddPresentation(kObject25);
	_app->objectPresentationAddImageToPuzzle(kObject25, 3, kPuzzleMenu, "dat04_3.bmp", Common::Point(0, 464), true, kDrawTypeNormal, 3000);
	_app->objectAddPresentation(kObject25);
	_app->objectPresentationAddImageToPuzzle(kObject25, 4, kPuzzleMenu, "dat05_3.bmp", Common::Point(0, 464), true, kDrawTypeNormal, 3000);
	_app->objectAddPresentation(kObject25);
	_app->objectPresentationAddImageToPuzzle(kObject25, 5, kPuzzleMenu, "dat06_4.bmp", Common::Point(0, 464), true, kDrawTypeNormal, 3000);
	_app->objectAddPresentation(kObject25);
	_app->objectPresentationAddImageToPuzzle(kObject25, 6, kPuzzleMenu, "dat07_5.bmp", Common::Point(0, 464), true, kDrawTypeNormal, 3000);
	_app->objectAddPresentation(kObject25);
	_app->objectPresentationAddImageToPuzzle(kObject25, 7, kPuzzleMenu, "dat08_6.bmp", Common::Point(0, 464), true, kDrawTypeNormal, 3000);
	_app->objectAddPresentation(kObject25);
	_app->objectPresentationAddImageToPuzzle(kObject25, 8, kPuzzleMenu, "dat09_7.bmp", Common::Point(0, 464), true, kDrawTypeNormal, 3000);
	_app->objectAddPresentation(kObject25);
	_app->objectPresentationAddImageToPuzzle(kObject25, 9, kPuzzleMenu, "dat10_4.bmp", Common::Point(0, 464), true, kDrawTypeNormal, 3000);
	_app->objectAddPresentation(kObject25);
	_app->objectPresentationAddImageToPuzzle(kObject25, 10, kPuzzleMenu, "dat11_4.bmp", Common::Point(0, 464), true, kDrawTypeNormal, 3000);
	_app->objectAddPresentation(kObject25);
	_app->objectPresentationAddImageToPuzzle(kObject25, 11, kPuzzleMenu, "dat12_4.bmp", Common::Point(0, 464), true, kDrawTypeNormal, 3000);
	_app->objectAddPresentation(kObject25);
	_app->objectPresentationAddImageToPuzzle(kObject25, 12, kPuzzleMenu, "dat13_4.bmp", Common::Point(0, 464), true, kDrawTypeNormal, 3000);

	_app->visualListAddToPuzzle(3, kPuzzlePreferences, 129,
	                            "", "", "", "", "ar_uph.tga", "", "ar_upn.tga", "", "ar_dnh.tga", "", "ar_dnn.tga", "", "",
	                            kDrawTypeAlpha, Common::Point(0, 0), Common::Point(0, 0), 230, 67, 170, 20, 20, 3,
	                            Common::Point(418, 67), 408, 57, 40, 40, Common::Point(418, 276), 408, 266,
	                            40, 40, Common::Point(0, 0), kImageTypeBMP, kDrawTypeNormal, 375, 30, 11,
	                            Color(245, 235, 50), Color(255, 255, 255), Color(-1, -1, -1), kFontDefault, kArchiveFile);

	_app->visualListAddToPuzzle(1, kPuzzleGeneralMenu, 129,
	                            "", "", "", "", "ar_uph.tga", "", "ar_upn.tga", "", "ar_dnh.tga", "", "ar_dnn.tga", "", "",
	                            kDrawTypeAlpha, Common::Point(0, 0), Common::Point(0, 0), 230, 222, 150, 20, 20, 3,
	                            Common::Point(418, 224), 408, 214, 40, 40, Common::Point(418, 351), 408, 341,
	                            40, 40, Common::Point(0, 0), kImageTypeBMP, kDrawTypeNormal, 170, 300, 7,
	                            Color(245, 235, 50), Color(255, 255, 255), Color(-1, -1, -1), kFontDefault, kArchiveFile);

	_app->visualListSetOff(1, kPuzzleGeneralMenu);

	_app->visualListAddToPuzzle(4, kPuzzleGeneralMenu, 65,
	                            "", "", "", "", "ar_uph.tga", "", "ar_upn.tga", "", "ar_dnh.tga", "", "ar_dnn.tga", "", "",
	                            kDrawTypeAlpha, Common::Point(0, 0), Common::Point(0, 0), 230, 222, 150, 20, 20, 3,
	                            Common::Point(418, 224), 408, 214, 40, 40, Common::Point(418, 351), 408, 341,
	                            40, 40, Common::Point(240, 82), kImageTypeBMP, kDrawTypeNormal, 170, 300, 7,
	                            Color(245, 235, 50), Color(255, 255, 255), Color(-1, -1, -1), kFontDefault, kArchiveFile);

	_app->visualListSetOff(4, kPuzzleGeneralMenu);

	_app->soundAdd(90002, kSoundTypeAmbientEffect, "00_Map_Open.wav", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(90003, kSoundTypeAmbientEffect, "00_Rolodex_Open.wav", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(90004, kSoundTypeAmbientEffect, "00_Rolodex_Page_Back.wav", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(90005, kSoundTypeAmbientEffect, "00_Rolodex_Page_Forward.wav", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(90001, kSoundTypeAmbientMusic, "BGR_MUS.wac", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundSetVolume(90001, 90);
	_app->soundAdd(90708, kSoundTypeAmbientMusic, "SY_Daffodil.wac", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->puzzleAddAmbientSound(kPuzzleGeneralMenu, 90001, 100, 0, 1, 1, 10);
	_app->soundAdd(90801, kSoundTypeDialog, "load.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90802, kSoundTypeDialog, "save.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90803, kSoundTypeDialog, "preferenc1.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90804, kSoundTypeDialog, "quit.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90805, kSoundTypeDialog, "confquit.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90806, kSoundTypeDialog, "startnewg.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90301, kSoundTypeDialog, "Hstor301.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90302, kSoundTypeDialog, "Hstor302.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90303, kSoundTypeDialog, "Hstor303.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90304, kSoundTypeDialog, "Hstor304.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90305, kSoundTypeDialog, "Hstor305.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90306, kSoundTypeDialog, "Hstor306.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90307, kSoundTypeDialog, "Hstor307.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90308, kSoundTypeDialog, "Hstor308.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90309, kSoundTypeDialog, "Hstor309.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90401, kSoundTypeDialog, "Hstor401.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90402, kSoundTypeDialog, "Hstor402.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90403, kSoundTypeDialog, "Hstor403.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90404, kSoundTypeDialog, "Hstor404.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90405, kSoundTypeDialog, "Hstor405.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90406, kSoundTypeDialog, "Hstor406.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90407, kSoundTypeDialog, "Hstor407.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90408, kSoundTypeDialog, "Hstor408.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90409, kSoundTypeDialog, "Hstor409.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90410, kSoundTypeDialog, "Hstor410.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90411, kSoundTypeDialog, "Hstor411.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90412, kSoundTypeDialog, "Hstor412.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90501, kSoundTypeDialog, "Hstor501.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90502, kSoundTypeDialog, "Hstor502.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90503, kSoundTypeDialog, "Hstor503.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90504, kSoundTypeDialog, "Hstor504.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90505, kSoundTypeDialog, "Hstor505.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90506, kSoundTypeDialog, "Hstor506.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90507, kSoundTypeDialog, "Hstor507.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90601, kSoundTypeDialog, "Hstor601.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90602, kSoundTypeDialog, "Hstor602.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90603, kSoundTypeDialog, "Hstor603.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90604, kSoundTypeDialog, "Hstor604.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90605, kSoundTypeDialog, "Hstor605.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90606, kSoundTypeDialog, "Hstor606.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90701, kSoundTypeDialog, "Hstor701.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90702, kSoundTypeDialog, "Hstor702.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90703, kSoundTypeDialog, "Hstor703.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90704, kSoundTypeDialog, "Hstor704.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90705, kSoundTypeDialog, "Hstor705.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90706, kSoundTypeDialog, "Hstor706.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90707, kSoundTypeDialog, "Hstor707.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(90800, kSoundTypeDialog, "Preferenc.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->varDefineByte(97001, 0);
	_app->varDefineByte(98001, _app->getSaveManager()->getData()->progressState);
	_app->varDefineByte(98002, 0);
	_app->varDefineByte(97002, 0);
	_app->varDefineByte(97006, 1);
	_app->varDefineByte(97007, 0);
	_app->varDefineByte(97008, 0);
	_app->varDefineByte(97009, 0);
	_app->varDefineByte(97010, 0);
	_app->varDefineByte(97011, 0);
	_app->varDefineByte(97012, 1);

	for (uint32 i = 0; i < 100; i++)
		_app->varDefineByte(98090 + i, 0);

	for (uint32 i = 0; i < 18; i++)
		_app->varDefineByte(99000 + i, 0);

	_app->varDefineByte(98004, 0);
	_app->varDefineByte(98003, 0);
	_app->varDefineByte(98005, 0);
	_app->varDefineByte(98006, 0);
	_app->varDefineByte(98007, 0);
	_app->varDefineByte(98008, 0);
	_app->varDefineByte(98009, 0);
	_app->varDefineByte(98010, 0);
	_app->varDefineByte(98011, 0);
	_app->varDefineByte(98087, 0);
	_app->varDefineByte(98088, 0);
	_app->varDefineWord(97013, 0);
	_app->varDefineDword(90025, 0);
	_app->varDefineDword(90028, 0);
	_app->varDefineDword(90027, 0);
	_app->varDefineDword(90026, 0);
	_app->varDefineByte(98012, 0);
	_app->varDefineByte(98013, 0);
	_app->varDefineByte(98014, 0);
	_app->varDefineByte(98015, 0);
	_app->varDefineByte(98016, 0);
	_app->varDefineByte(98089, 0);
}

void ZoneSystemFaust::onTimer(TimerId id) {
	if (id == kTimer12) {
		_app->timerStop(kTimer12);
		_app->varSetByte(97006, 1);
		_app->objectPresentationHide(kObject14, 7);
		_app->objectPresentationShow(kObject14, 8);
	}
}

// FAUST.EXE 0x45fac0, called for every key press before the puzzle/rotation key handling
void ZoneSystemFaust::onKeyDown(const Common::KeyState &keyState) {
	// The original receives WM_CHAR codes, plus VK_DELETE (0x2E) from WM_KEYDOWN. It
	// doesn't tell them apart, so typing '.' also asks to delete; we only use the Delete key.
	bool isDelete = (keyState.keycode == Common::KEYCODE_DELETE);
	uint16 key = keyState.ascii;

	bool isTextInput = _app->getCurrentPuzzleId() == kPuzzlePreferences
	                || _app->varGetByte(98089)
	                || _app->getCurrentPuzzleId() == kPuzzleGeneralMenu
	                || _app->getCurrentZone() == kZone11
	                || _app->varGetByte(98088);

	if (!isTextInput) {
		// Space opens the in-game menu
		if (key != Common::ASCII_SPACE)
			return;

		_app->varSetWord(97013, (int16)_app->getCurrentZone());
		_app->setSpace(kZoneSY);

		if (_app->varGetByte(97002))
			return;

		_app->puzzleSetMod(kPuzzleMenu, 2, kObject14);
		// The original only logs a warning when there is no current rotation
		if (_app->hasCurrentRotation())
			_app->rotationSetFreOn(_app->getCurrentRotationId());
		_app->objectSetAccessibilityOn(kObject14, 4, 4);
		_app->objectPresentationShow(kObject14, 0);

		if (_app->varGetByte(98001) >= 3) {
			_app->objectPresentationShow(kObject14, _app->varGetByte(97006) + 7);
			_app->objectSetAccessibilityOn(kObject14, 0, 0);
			_app->objectSetAccessibilityOn(kObject14, 3, 3);
		} else {
			_app->objectPresentationShow(kObject14, 1);
			_app->objectSetAccessibilityOff(kObject14, 0, 0);
			_app->objectSetAccessibilityOff(kObject14, 3, 3);
		}

		if (_app->varGetByte(98001) >= 3) {
			_app->objectPresentationShow(kObject14, 9);
			_app->objectSetAccessibilityOn(kObject14, 1, 1);
		} else {
			_app->objectPresentationShow(kObject14, 3);
			_app->objectSetAccessibilityOff(kObject14, 1, 1);
		}

		_app->varSetByte(97002, 1);
		return;
	}

	// Text input: only on the preferences screen, or the general menu while a list is being edited
	if (!_app->hasCurrentPuzzle())
		return;

	PuzzleId puzzleId = _app->getCurrentPuzzleId();
	if (puzzleId != kPuzzlePreferences) {
		if (puzzleId != kPuzzleGeneralMenu)
			return;

		if (!_app->varGetByte(98004) && !_app->varGetByte(98003))
			return;
	}

	if (isDelete) {
		if (puzzleId == kPuzzleGeneralMenu) {
			if (_app->varGetByte(98004) && _app->visualListGetObjectIdClicked(1, kPuzzleGeneralMenu)) {
				_app->messageGet("DoYouWantToDeleteSavedGame");
				_app->messageShowQuestion(4);
			}

			if (_app->varGetByte(98003) && _app->visualListGetObjectIdClicked(4, kPuzzleGeneralMenu)) {
				_app->messageGet("DoYouWantToDeleteSavedGame");
				_app->messageShowQuestion(8);
			}
		} else if (_app->visualListGetObjectIdClicked(3, kPuzzlePreferences)) {
			_app->messageGet("DoYouWantToDeleteUser");
			_app->messageShowQuestion(6);
		}

		return;
	}

	ObjectId objectId;
	uint32 presentationIndex;
	int32 y;
	if (puzzleId == kPuzzlePreferences) {
		_app->visualListResetObjectClicked(3, kPuzzlePreferences);
		objectId = kObject99501;
		presentationIndex = 0;
		y = 334;
	} else {
		if (!_app->varGetByte(98004))
			return;

		_app->visualListResetObjectClicked(1, kPuzzleGeneralMenu);
		objectId = kObject99601;
		presentationIndex = 1;
		y = 382;
	}

	switch (key) {
	case Common::ASCII_BACKSPACE:
		if (!_name.empty())
			_name.deleteLastChar();
		break;

	case Common::ASCII_RETURN:
		break;

	case Common::ASCII_ESCAPE:
		_name.clear();
		break;

	default:
		// The original appends any WM_CHAR code; skip keys without a character
		if (key && _app->objectPresentationGetTextWidth(objectId, presentationIndex, 0) < 150)
			_name += (char)key;
		break;
	}

	_app->objectPresentationSetTextToPuzzle(objectId, presentationIndex, 0, _name);

	uint32 width = _app->objectPresentationGetTextWidth(objectId, presentationIndex, 0);
	_app->objectPresentationSetAnimationCoordinatesOnPuzzle(objectId, 0, Common::Point(width + 233, y));
}

static int16 getSliderKnobX(int32 value);

// FAUST.EXE 0x45b8b0
void ZoneSystemFaust::onButtonUp(ObjectId id, Id target, Id, uint32, const Common::Point &point) {
	// Zone 14 radio parts
	if (id >= 112601 && id <= 112612) {
		_app->objectPresentationHide(kObject13, (uint32)(id - 112600));
		_app->bagAdd(id);
	}

	switch (id) {
	default:
		break;

	case kObject1:
		if (_app->bagHasClickedObject())
			return;

		// Debug overlay toggle (the 3D sound calls are leftovers in the original)
		if (_object1Visible) {
			_app->objectPresentationHideAndRemove(kObject1);
			_object1Visible = false;
		} else {
			_app->objectPresentationShow(kObject1);
			_object1Visible = true;
			_app->rotationSet3DSoundOn(50004, 1);
			_app->puzzleSet3DSoundOn(50001, 1);
		}
		break;

	case kObjectYesNo:
		// Quit confirmation
		switch (target) {
		default:
			break;

		case 0:
			_app->objectPresentationHideAndRemove(kObjectYesNo);
			_app->objectSetAccessibilityOff(kObjectYesNo);
			_app->puzzleSetMod(kPuzzleMenu, 1, 0);
			_app->objectPresentationHide(kObject99004, 0);
			_app->varSetByte(98006, 0);
			break;

		case 1:
			// The original posts WM_DESTROY first, so this runs before the game quits
			if (_app->hasCurrentPuzzle()) {
				if (_app->getCurrentPuzzleId() == kPuzzleGeneralMenu)
					_app->showCredits();

				if (_app->getCurrentPuzzleId() != kPuzzlePreferences)
					_app->getSaveManager()->saveProgress(_app->getSaveManager()->getData()->progressState);
			}

			Engine::quitGame();
			break;
		}
		break;

	case kObject3:
		_app->messageHideWarning((uint32)target);
		break;

	case kObjectQuestion:
		onQuestion(target);
		break;

	case kObject6:
		if (_app->bagHasClickedObject()) {
			if (target == 0 && _app->bagGetClickedObject() == 97001) {
				_app->objectPresentationShow(kObject6, 5);
				_app->objectPresentationHide(kObject6, 3);
				_app->objectPresentationShow(kObject6, 4);
				_app->varSetByte(97001, 1);
			}

			_app->cursorDelete();
		}
		break;

	case kObject14:
		// In-game menu
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			return;
		}

		switch (target) {
		default:
			break;

		case 0:
			// Hint: replays the current hint, or moves to the next one once the timer has run out
			switch (_app->varGetByte(98001)) {
			default:
				break;

			case 3:
				playHint(97007, 9, 90300);
				break;

			case 4:
				playHint(97008, 12, 90400);
				break;

			case 5:
				playHint(97009, 7, 90500);
				break;

			case 6:
				playHint(97010, 6, 90600);
				break;

			case 7:
				playHint(97011, 7, 90700);
				break;
			}
			break;

		case 1: {
			// Map of the current zone
			_app->objectPresentationHide(kObject14);
			_app->objectSetAccessibilityOff(kObject14, 0, 3);
			_app->varSetByte(97002, 0);
			_app->objectPresentationHideAndRemove(kObject14);
			_app->soundPlay(90002);

			int16 zone = _app->varGetWord(97013);
			uint32 index;
			if (zone < 6)
				index = 12;
			else if (zone == 6)
				index = 13;
			else if (zone >= 8 && zone <= 10)
				index = zone + 6;
			else if (zone >= 12 && zone <= 17)
				index = zone + 5;
			else
				index = 11;

			_app->objectPresentationShow(kObject14, index);
			}
			break;

		case 2:
			// Story pages
			hideMainMenuButtons();
			_app->objectPresentationHide(kObject99010, 0);
			_app->objectSetAccessibilityOff(kObject99010);
			_app->objectPresentationHide(kObject99010);
			_app->objectPresentationHide(kObject14);
			_app->objectSetAccessibilityOff(kObject14, 0, 3);
			_app->varSetByte(97002, 0);
			_app->objectPresentationHideAndRemove(kObject14);
			_app->varSetByte(97012, 1);
			_app->objectPresentationShow(kObject14, (uint32)(_app->varGetByte(97012) + 22));
			_app->soundPlay(90003);
			_app->objectSetAccessibilityOn(kObject14, 5, 5);
			_app->objectSetAccessibilityOn(kObject14, 7, 7);
			break;

		case 3:
			// As in onKeyDown, the original only logs a warning without a current rotation (menu opened in a puzzle)
			if (_app->hasCurrentRotation())
				_app->rotationSetFreOff(_app->getCurrentRotationId());
			_app->objectPresentationHide(kObject14);
			_app->objectSetAccessibilityOff(kObject14);
			_app->varSetByte(97002, 0);
			_app->objectPresentationHideAndRemove(kObject14);
			_app->setSpace((ZoneId)_app->varGetWord(97013));

			if (!_app->getSaveManager()->loadSave("Rabbit", kLoadSaveWrite)) {
				_app->exitToMenu(kMenuAction10);
				return;
			}

			_app->puzzleSetMod(kPuzzleMenu, 1, 0);
			_app->sub_460150(2);
			break;

		case 4:
			// Resume
			_app->setSpace((ZoneId)_app->varGetWord(97013));
			_app->puzzleSetMod(kPuzzleMenu, 1, 0);
			if (_app->hasCurrentRotation())
				_app->rotationSetFreOff(_app->getCurrentRotationId());
			_app->objectPresentationHide(kObject14);
			_app->objectSetAccessibilityOff(kObject14);
			_app->varSetByte(97002, 0);
			_app->objectPresentationHideAndRemove(kObject14);
			break;

		case 5: {
			// Next page
			_app->objectSetAccessibilityOn(kObject14, 6, 6);
			_app->soundPlay(90005);

			int32 lastPage = 2 * _app->getSaveManager()->getData()->progressState - 2;
			if ((int8)_app->varGetByte(97012) >= lastPage)
				break;

			_app->varSetByte(97012, _app->varGetByte(97012) + 1);
			int8 page = (int8)_app->varGetByte(97012);
			_app->objectPresentationHide(kObject14, (uint32)(page + 21));
			_app->objectPresentationShow(kObject14, (uint32)(page + 22));

			if (page == lastPage)
				_app->objectSetAccessibilityOff(kObject14, 5, 5);
			}
			break;

		case 6: {
			// Previous page
			_app->objectSetAccessibilityOn(kObject14, 5, 5);
			_app->soundPlay(90004);

			if ((int8)_app->varGetByte(97012) <= 1)
				break;

			_app->varSetByte(97012, _app->varGetByte(97012) - 1);
			int8 page = (int8)_app->varGetByte(97012);
			_app->objectPresentationHide(kObject14, (uint32)(page + 23));
			_app->objectPresentationShow(kObject14, (uint32)(page + 22));

			if (page == 1)
				_app->objectSetAccessibilityOff(kObject14, 6, 6);
			}
			break;

		case 99:
			_app->objectPresentationHide(kObject14);
			_app->objectSetAccessibilityOff(kObject14);
			_app->varSetByte(97002, 0);
			_app->objectPresentationHideAndRemove(kObject14);
			showMainMenu(true);
			break;
		}
		break;

	case kObject17:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			return;
		}

		_app->objectPresentationHide(kObject17);
		_app->objectSetAccessibilityOff(kObject17);
		_app->puzzleSetMod(kPuzzleMenu, 1, 0);
		break;

	case kObject19:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			return;
		}

		_app->varSetByte(49000, 1);
		_app->varSetByte(49003, 1);
		break;

	case kObject20:
		switch (target) {
		default:
			// Close
			if (_app->varGetDword(90027) > 0)
				_app->rotationSetFreOff(_app->varGetDword(90027));

			_app->soundStopType(kSoundTypeDialog, 1024);

			if (_app->varGetDword(90027) == 111206)
				_app->soundPlay(112035);

			_app->objectPresentationHide(kObject11);
			_app->objectSetAccessibilityOff(kObject20);

			if (_app->varGetByte(111000) == 1)
				_app->objectSetAccessibilityOn(kObject20, 0, 0);

			_app->objectSetAccessibilityOff(kObject114503);

			if (target == 69)
				_app->soundPlay(111079, kSoundLoop);
			break;

		case 11:
		case 21:
			_app->objectPresentationHide(kObject11);
			_app->objectPresentationShow(kObject11, target == 11 ? 10 : 12);
			_app->objectSetAccessibilityOff(kObject20);

			if (_app->varGetByte(111000) == 1)
				_app->objectSetAccessibilityOn(kObject20, 0, 0);

			_app->objectSetAccessibilityOn(kObject20, 2, 2);

			if (target == 11)
				_app->objectSetAccessibilityOn(kObject20, 4, 5);
			else
				_app->objectSetAccessibilityOn(kObject20, 7, 8);

			_app->soundPlay(112034);
			break;

		case 12:
			_app->soundPlay(111090);
			break;

		case 22:
			_app->soundPlay(111092);
			break;

		case 23:
			_app->soundPlay(111093);
			break;

		case 31:
			_app->soundPlay(111094);
			break;

		case 41:
			_app->bagAdd(112013);
			_app->varSetByte(112024, 1);
			_app->soundPlay(112020);
			_app->objectSetAccessibilityOff(kObject20, 10, 10);
			_app->objectPresentationHide(kObject11);
			_app->objectPresentationShow(kObject11, 15);
			break;
		}
		break;

	case kObjectPipe:
		if (target == 0) {
			_app->objectPresentationHide(kObject11);

			if (_app->varGetByte(114522) == 1) {
				_app->objectPresentationShow(kObject11, 17);
				_app->objectSetAccessibilityOff(kObjectPipe, 0, 0);
				_app->objectSetAccessibilityOn(kObjectPipe, 1, 1);
				_app->varSetByte(114522, 2);
			} else {
				_app->objectPresentationShow(kObject11, 16);
				_app->varSetByte(114522, 1);
				_app->objectSetAccessibilityOff(kObjectPipe, 1, 1);
				_app->objectSetAccessibilityOn(kObjectPipe, 0, 0);
			}

			_app->soundPlay(112019);
		} else if (target == 9) {
			_app->puzzleSetMod(kPuzzleMenu, 1, 0);
			_app->objectPresentationHide(kObject11);
			_app->objectPresentationHide(kObject11);
			_app->objectSetAccessibilityOff(kObjectPipe);
			_app->varSetByte(114522, 0);
		}
		break;

	case kObject22:
		// Radio tuning knob (zone 14)
		if (_app->varGetByte(114101) <= 0 || _app->varGetByte(114100) <= 0)
			break;

		_app->objectPresentationHide(kObject12, 2);

		if (_app->varGetByte(114101) == 2) {
			_app->objectPresentationHide(kObject12);
			_app->objectSetAccessibilityOff(kObject22);

			if (_app->varGetByte(114100) == 1) {
				_app->objectPresentationShow(kObject12, 3);
				_app->soundPlay(111040);
			} else {
				_app->objectSetAccessibilityOff(kObject114027);
				_app->objectSetAccessibilityOff(kObject114028);
				_app->objectSetAccessibilityOff(kObject114026);
				_app->objectSetAccessibilityOn(kObject114027, 1, 1);
				_app->objectSetAccessibilityOn(kObject114027, 5, 5);
				_app->objectPresentationShow(kObject114027, 3);
				_app->varSetByte(114527, 1);
			}
		} else if (point.x < 350) {
			_app->objectPresentationHide(kObject12, 2);
			_app->objectPresentationHide(kObject12, 1);
			_app->objectSetAccessibilityOff(kObject22);
			handleEvents();
			_app->sub_468290(1);
		}

		_app->varSetByte(114101, 0);
		break;

	case kObject23:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			return;
		}

		if (target == 99) {
			_app->puzzleSetMod(kPuzzleMenu, 1, 0);
			_app->objectPresentationHideAndRemove(kObjectCodingWheel);
			_app->objectSetAccessibilityOff(kObject23);
			_app->varSetByte(114520, 0);
		}
		break;

	case kObject55:
		// Insert CD prompt
		_app->objectPresentationHide(kObject55, 0);

		if (target == 99) {
			_app->_slot = -1;
			_jukeboxIndex = 1;
			_chapterIndex = 0;

			if (_app->getCurrentGameZone())
				_app->puzzleSetActive(kPuzzleGeneralMenu);
			else
				_app->startMenu(false);

			_chapterIndex = 0;
		} else {
			// The original reads the number of the CD in the drive from data/cd.ini and
			// does nothing if it isn't the one holding the episode. All the CDs are
			// installed here, so the episode is always available.
			_app->setCurrentEpisode((ZoneId)target);
			_app->setZone((ZoneId)target, _app->getSaveManager()->getSetupType());
		}
		break;

	case 90911:
		// The original calls 0x472d70, which reactivates a stored puzzle or rotation
		// (like Pompeii's restore()). Faust never stores one, so it does nothing.
		break;

	case kObject99000:
		// Start / continue
		hideMainMenuButtons();

		if (_app->varGetByte(98001) == 0) {
			_app->varSetByte(98001, 1);

			if (_app->getSaveManager()->getData()->progressState == kProgressStateNone)
				_app->getSaveManager()->getData()->progressState = kProgressState1;

			_app->setupZone(kZone7, (SetupType)20000);
			showMainMenu(false);
		} else {
			_app->fadeOut(15, Color(0, 0, 0), 0);
			_app->exitToMenu(kMenuAction1);
		}
		break;

	case kObject99001:
		// Load screen
		_app->soundPlay(90801);
		_app->varSetByte(98003, 1);
		hideMainMenuButtons();
		_app->objectPresentationHide(kObject99010, 0);
		_app->objectPresentationShow(kObject99001, 0);
		_app->objectPresentationShow(kObject99001, 2);
		_app->objectSetAccessibilityOff(kObject99010);

		if ((int8)_app->varGetByte(98001) <= _app->getSaveManager()->getData()->progressState) {
			_app->objectSetAccessibilityOn(kObject99021);
			_app->objectPresentationShow(kObject99021, 2);
		} else {
			_app->objectPresentationShow(kObject99021, 1);
		}

		_app->objectSetAccessibilityOn(kObject99022);
		_app->objectPresentationShow(kObject99022, 2);
		_app->objectPresentationShow(kObject99023, 1);
		_app->objectPresentationShow(kObject99601, 1);
		_name.clear();
		_app->objectPresentationSetTextToPuzzle(kObject99601, 1, 0, _name);
		_app->visualListSetOn(4, kPuzzleGeneralMenu);
		// The original sets the icon directory (the save thumbnails) after loading the list,
		// but our list looks for the icons when items are added
		_app->visualListSetIconDirectory(4, kPuzzleGeneralMenu, _app->getSaveManager()->getIconDirectory());
		_app->loadSaveList(4, kPuzzleGeneralMenu);
		break;

	case kObject99002: {
		// Save screen
		_app->soundPlay(90802);
		_app->varSetByte(98004, 1);
		hideMainMenuButtons();
		_app->objectPresentationHide(kObject99010, 0);
		_app->objectPresentationShow(kObject99002, 0);
		_app->objectPresentationShow(kObject99002, 2);
		_app->objectSetAccessibilityOff(kObject99010);
		_app->objectSetAccessibilityOn(kObject99024);
		_app->objectPresentationShow(kObject99024, 2);
		_app->objectPresentationShow(kObject99025, 2);
		_app->objectSetAccessibilityOn(kObject99025);

		// The original writes data/SY/Image/osc.bmp and copies it next to the savegame
		if (_app->getThumbnail()) {
			ImageSurface *thumbnail = _app->getThumbnail()->zoom(0.25f, 0.22f);
			_app->getSaveManager()->setThumbnail(thumbnail);
			delete thumbnail;
		} else {
			warning("[ZoneSystemFaust::onButtonUp] Save pressed with no thumbnail image");
		}

		_app->objectPresentationShow(kObject99601);
		_app->objectPresentationSetImageCoordinatesOnPuzzle(kObject99601, 2, Common::Point(240, 82));
		_name.clear();
		_app->objectPresentationSetTextToPuzzle(kObject99601, 1, 0, _name);
		uint32 width = _app->objectPresentationGetTextWidth(kObject99601, 1, 0);
		_app->objectPresentationSetAnimationCoordinatesOnPuzzle(kObject99601, 0, Common::Point((int16)(width + 233), 382));
		_app->visualListSetOn(1, kPuzzleGeneralMenu);
		_app->loadSaveList(1, kPuzzleGeneralMenu);
		}
		break;

	case kObject99003:
		// Preferences
		_app->soundPlay(90803);
		_app->varSetByte(98005, 1);
		hideMainMenuButtons();
		_app->objectPresentationHide(kObject99010, 0);
		_app->objectPresentationShow(kObject99003, 0);
		_app->objectPresentationShow(kObject99003, 2);
		_app->objectSetAccessibilityOff(kObject99010);
		_app->objectSetAccessibilityOn(kObject99041);
		_app->objectPresentationShow(kObject99041, 2);
		_app->objectPresentationShow(kObject99042, 2);
		_app->objectSetAccessibilityOn(kObject99042);

		if (_app->getPreferenceHandler()) {
			// FAUST.EXE 0x45d40e: the preferences hold 75..100 and the sliders show 4 * pref - 300
			// (clipped, since ScummVM's own volume sliders can set lower values)
			_prefsVolume        = CLIP<int32>(4 * _app->getPreferenceHandler()->getVolume() - 300, 0, 100);
			_prefsVolumeDialog  = CLIP<int32>(4 * _app->getPreferenceHandler()->getVolumeDialog() - 300, 0, 100);
			_prefsReverseStereo = (_app->getPreferenceHandler()->getReverseStereo() == 1);
			_prefsSubtitles     = _app->getPreferenceHandler()->getShowSubtitles();
		} else {
			_prefsVolume        = 100;
			_prefsVolumeDialog  = 100;
			_prefsReverseStereo = false;
			_prefsSubtitles     = true;
		}

		_app->objectPresentationHide(kObject99043);
		_app->objectSetAccessibilityOn(kObject99043);
		_app->objectPresentationHide(kObject99044);
		_app->objectSetAccessibilityOn(kObject99044);
		_app->objectSetAccessibilityOn(kObject99045);
		_app->objectSetAccessibilityOn(kObject99046);

		if (!g_system->getMixer()->isReady()) {
			_prefsSubtitles = true;
			_app->objectSetAccessibilityOff(kObject99043);
			_app->objectSetAccessibilityOff(kObject99044);
			_app->objectSetAccessibilityOff(kObject99045);
			_app->objectSetAccessibilityOff(kObject99046);
		}

		_app->objectPresentationShow(kObject99043, _prefsSubtitles ? 1 : 0);
		_app->objectPresentationShow(kObject99044, _prefsReverseStereo ? 1 : 0);
		_app->objectPresentationSetImageCoordinatesOnPuzzle(kObject99045, 0, 0, Common::Point(getSliderKnobX(_prefsVolume), 164));
		_app->objectPresentationShow(kObject99045, 0);
		_app->objectPresentationSetImageCoordinatesOnPuzzle(kObject99046, 0, 0, Common::Point(getSliderKnobX(_prefsVolumeDialog), 210));
		_app->objectPresentationShow(kObject99046, 0);

		_prefsVolumeBackup        = _prefsVolume;
		_prefsVolumeDialogBackup  = _prefsVolumeDialog;
		_prefsReverseStereoBackup = _prefsReverseStereo;
		_prefsSubtitlesBackup     = _prefsSubtitles;
		break;

	case kObject99004:
		// Quit: the original posts WM_CLOSE, which shows the confirmation when 98006 is set
		_app->soundPlay(90804);
		_app->varSetByte(98006, 1);
		if (_app->puzzleSetMod(kPuzzleMenu, 2, 2)) {
			_app->objectPresentationShow(kObjectYesNo, 0);
			_app->objectSetAccessibilityOn(kObjectYesNo);
		}
		break;

	case kObject99005:
		// Progress summary
		_app->varSetByte(98007, 1);
		hideMainMenuButtons();
		_app->objectPresentationHide(kObject99010, 0);
		_app->objectPresentationShow(kObject99005, 0);
		_app->objectSetAccessibilityOff(kObject99010);
		_app->objectPresentationHide(kObject99010);
		_app->objectPresentationShow(kObject99005, (uint32)(_app->varGetByte(98001) + 1));
		_app->objectPresentationShow(kObject99097, 2);
		_app->objectSetAccessibilityOn(kObject99097);
		break;

	case kObject99006:
		// Chapter selection
		_app->varSetByte(98008, 1);
		hideMainMenuButtons();
		_app->objectPresentationHide(kObject99010, 0);
		_app->objectPresentationShow(kObject99006, 0);
		_app->objectPresentationShow(kObject99070, 0);
		_app->objectPresentationShow(kObject99006, 2);
		_app->objectSetAccessibilityOff(kObject99010);
		_app->objectPresentationHide(kObject99010);
		_app->objectPresentationShow(kObject99097, 2);
		_app->objectSetAccessibilityOn(kObject99097);
		_app->objectPresentationShow(kObject99071, (uint32)_chapterIndex);
		_app->objectSetAccessibilityOn(kObject99071);

		if (_app->getSaveManager()->getData()->progressState > kProgressState1) {
			_app->objectSetAccessibilityOn(kObject99010);
			_app->objectPresentationShow(kObject99010);
		}
		break;

	case kObject99007:
		// Jukebox
		_app->varSetByte(98009, 1);
		hideMainMenuButtons();
		_app->objectPresentationHide(kObject99010, 0);
		_app->objectPresentationShow(kObject99007, 0);
		_app->objectPresentationShow(kObject99080, 0);
		_jukeboxIndex = 10;
		_app->objectPresentationShow(kObject99081, 9);
		_app->objectPresentationShow(kObject99007, 2);
		_app->objectPresentationShow(kObject99097, 2);
		_app->objectSetAccessibilityOn(kObject99097);
		break;

	case kObject99008:
		// Progress animation
		_app->varSetByte(98010, 1);
		hideMainMenuButtons();
		_app->objectPresentationHide(kObject99010, 0);
		_app->objectPresentationUnpauseAnimation(kObject99090, 0);

		if (_app->getSaveManager()->getData()->progress > 0) {
			_app->objectPresentationSetAnimationOnPuzzle(kObject99090, 0, 0, 2);
			_app->objectPresentationShow(kObject99090, 0);
		}

		_app->objectPresentationShow(kObject99008, 0);
		_app->objectSetAccessibilityOff(kObject99010);
		_app->objectPresentationHide(kObject99010);
		_app->objectPresentationShow(kObject99008, 2);
		_app->objectPresentationShow(kObject99097, 2);
		_app->objectSetAccessibilityOn(kObject99097);
		break;

	case kObject99009:
		// Bonus
		_app->varSetByte(98011, 1);
		hideMainMenuButtons();
		_app->objectPresentationHide(kObject99010, 0);
		_app->objectPresentationShow(kObject99009, 0);
		_app->objectSetAccessibilityOff(kObject99010);
		_app->objectPresentationHide(kObject99010);
		_app->objectPresentationShow(kObject99009, 2);
		_app->objectPresentationShow(kObject99091);
		_app->objectSetAccessibilityOn(kObject99091);
		_app->objectPresentationShow(kObject99097, 2);
		_app->objectSetAccessibilityOn(kObject99097);
		break;

	case kObject99010:
		// Left / right arrows
		if (_app->varGetByte(98009) > 0) {
			onJukebox(target);
			break;
		}

		if (_app->varGetByte(98008) > 0) {
			if (target == 0)
				--_chapterIndex;
			else if (target == 1)
				++_chapterIndex;

			// Last chapter unlocked by each progress state
			static const int8 lastChapters[] = { 0, 5, 7, 12, 17, 20, 26, 31 };
			int32 progressState = _app->getSaveManager()->getData()->progressState;
			int8 lastChapter = (progressState >= 1 && progressState <= 8) ? lastChapters[progressState - 1] : 0;

			if (_chapterIndex < 0)
				_chapterIndex = lastChapter;
			else if (_chapterIndex > lastChapter)
				_chapterIndex = 0;

			_app->objectPresentationHide(kObject99071);
			_app->objectPresentationShow(kObject99071, (uint32)_chapterIndex);
			break;
		}

		{
			// Selected progress state
			int8 slot = (int8)_app->varGetByte(98001);
			if (target == 0)
				--slot;
			else if (target == 1)
				++slot;

			if (slot < 0)
				slot = 7;
			else if (slot > 7)
				slot = 0;

			_app->varSetByte(98001, slot);
			showMainMenu(false);
		}
		break;

	case kObject99021:
		// Load screen: start the selected progress state (initZone sets 98001 back to it afterwards)
		_app->objectPresentationHide(kObject99001);
		_app->_menuSlot = (int8)_app->varGetByte(98001);
		hideMenuButtons(kObject99021, kObject99025);
		_app->exitToMenu(kMenuAction3);
		break;

	case kObject99022:
		// Load screen: cancel
		_app->objectPresentationHide(kObject99001);
		hideMenuButtons(kObject99021, kObject99025);
		_app->objectPresentationHide(kObject99601);
		_app->varSetByte(98004, 0);
		_app->visualListSetOff(4, kPuzzleGeneralMenu);
		_app->visualListRemove(4, kPuzzleGeneralMenu, true);
		_app->varSetByte(98003, 0);
		showMainMenu(true);
		break;

	case kObject99023:
		// Load screen: load the selected savegame
		_app->objectPresentationHide(kObject99001);
		hideMenuButtons(kObject99021, kObject99025);
		_app->exitToMenu(kMenuAction0);
		break;

	case kObject99024:
	case kObject99025:
		// Save screen: cancel / save
		_app->objectPresentationHide(kObject99002);
		hideMenuButtons(kObject99021, kObject99025);

		if (id == kObject99025 && !_app->getSaveManager()->saveAs(_name)) {
			_app->messageFormat("CanNotSaveGame", _name);
			_app->messageShowWarning(0);
			return;
		}

		_app->objectPresentationHide(kObject99601);
		_app->varSetByte(98004, 0);
		_app->visualListSetOff(1, kPuzzleGeneralMenu);
		_app->visualListRemove(1, kPuzzleGeneralMenu, true);
		_app->varSetByte(98004, 0);
		showMainMenu(true);
		break;

	case kObject99041:
	case kObject99042:
		// Preferences: cancel / ok
		_app->objectPresentationHide(kObject99003);
		hideMenuButtons(kObject99041, kObject99046);
		_app->varSetByte(98005, 0);

		if (id == kObject99042) {
			showMainMenu(true);
			break;
		}

		_app->objectSetAccessibilityOn(kObject99010);

		// The original passes the slider values to the preference file unconverted
		// here (unlike every other save), so restore and convert them properly
		_prefsVolume        = _prefsVolumeBackup;
		_prefsVolumeDialog  = _prefsVolumeDialogBackup;
		_prefsReverseStereo = _prefsReverseStereoBackup;
		_prefsSubtitles     = _prefsSubtitlesBackup;
		savePreferences();
		showMainMenu(false);
		break;

	case kObject99043:
		_prefsSubtitles = !_prefsSubtitles;
		_app->objectPresentationHide(kObject99043);
		_app->objectPresentationShow(kObject99043, _prefsSubtitles ? 1 : 0);
		savePreferences();
		break;

	case kObject99044:
		_prefsReverseStereo = !_prefsReverseStereo;
		_app->objectPresentationHide(kObject99044);
		_app->objectPresentationShow(kObject99044, _prefsReverseStereo ? 1 : 0);
		savePreferences();
		break;

	case kObject99071: {
		// Chapter selection: start the chapter
		_app->soundStopType(kSoundTypeAmbientMusic, 1024);
		_app->soundStopType(kSoundTypeBackgroundMusic, 1024);

		// First chapter index of each zone
		static const struct {
			int8 firstChapter;
			ZoneId zone;
			SetupType type;
		} chapters[] = {
			{ 27, kZone8, (SetupType)30000 },
			{ 21, kZone7, (SetupType)30000 },
			{ 18, kZone6, (SetupType)30000 },
			{ 13, kZone5, (SetupType)30000 },
			{  8, kZone4, (SetupType)30000 },
			{  6, kZone3, (SetupType)30000 },
			{  1, kZone2, (SetupType)30000 },
			{  0, kZone7, (SetupType)20000 }
		};

		if (_chapterIndex >= 0 && _chapterIndex <= 31) {
			for (uint32 i = 0; i < ARRAYSIZE(chapters); i++) {
				if (_chapterIndex >= chapters[i].firstChapter) {
					_app->setupZone(chapters[i].zone, chapters[i].type);
					break;
				}
			}
		}

		_jukeboxIndex = 1;
		}
		break;

	case kObject99091:
		// Bonus scenes
		_app->soundStopType(kSoundTypeAmbientMusic, 1024);
		_app->soundStopType(kSoundTypeBackgroundMusic, 1024);

		switch (target) {
		default:
			_jukeboxIndex = 1;
			break;

		case 1:
			_app->varSetByte(98014, 1);
			_app->setupZone(kZone2, kSetupType9);
			break;

		case 2:
			_app->varSetByte(98015, 1);
			_app->setupZone(kZone7, (SetupType)30002);
			break;

		case 3:
			_app->varSetByte(98016, 1);
			_app->setupZone(kZone8, kSetupType99);
			break;
		}
		break;

	case kObject99097:
		// Back from the extra screens
		if (_app->varGetByte(98007) == 1) {
			_app->objectPresentationHide(kObject99005);
			_app->objectPresentationHide(kObject99097);
			_app->objectSetAccessibilityOff(kObject99097);
			_app->varSetByte(98007, 0);
		} else if (_app->varGetByte(98008) == 1) {
			_app->objectPresentationHideAndRemove(kObject99070);
			_app->objectPresentationHideAndRemove(kObject99071);
			_app->objectPresentationHide(kObject99006);
			_app->objectPresentationHide(kObject99097);
			_app->objectSetAccessibilityOff(kObject99071);
			_app->objectSetAccessibilityOff(kObject99097);
			_app->varSetByte(98008, 0);
		} else if (_app->varGetByte(98009) == 1) {
			// Restore the volumes the jukebox set to 100
			_app->soundSetVolume(41001, 90);
			_app->soundSetVolume(13054, 85);
			_app->soundSetVolume(13055, 80);
			_app->soundSetVolume(17019, 85);
			_app->soundSetVolume(31003, 90);
			_app->soundSetVolume(52000, 90);
			_app->soundSetVolume(81107, 90);
			_app->soundSetVolume(81223, 90);
			_app->soundSetVolume(81310, 90);
			_app->soundSetVolume(112074, 90);
			_app->soundSetVolume(90708, 90);
			_app->soundSetVolume(310105, 100);
			_app->objectPresentationHideAndRemove(kObject99080);
			_app->objectPresentationHideAndRemove(kObject99081);
			_app->objectPresentationHide(kObject99007);
			_app->objectPresentationHide(kObject99097);
			_app->objectSetAccessibilityOff(kObject99097);
			_app->varSetByte(98009, 0);
		} else if (_app->varGetByte(98010) == 1) {
			_app->objectPresentationHideAndRemove(kObject99090);
			_app->objectPresentationHide(kObject99008);
			_app->objectPresentationHide(kObject99097);
			_app->objectSetAccessibilityOff(kObject99097);
			_app->varSetByte(98010, 0);
		} else if (_app->varGetByte(98011) == 1) {
			_app->objectPresentationHide(kObject99009);
			_app->objectPresentationHide(kObject99091);
			_app->objectPresentationHide(kObject99097);
			_app->objectSetAccessibilityOff(kObject99097);
			_app->objectSetAccessibilityOff(kObject99091);
			_app->varSetByte(98011, 0);
		}

		showMainMenu(true);
		break;

	case kObject99100: {
		// Plays the closing music of the selected progress state
		static const struct {
			ZoneId zone;
			Id sound;
		} music[] = {
			{ kZone7,  41000 },
			{ kZoneSY, 0     },
			{ kZone12, 81037 },
			{ kZoneSY, 0     },
			{ kZone9,  61300 },
			{ kZoneSY, 0     },
			{ kZone8,  53131 }
		};

		_app->soundStopType(kSoundTypeDialog, 1024);

		int8 slot = (int8)_app->varGetByte(98001);
		if (slot >= 1 && slot <= 7 && music[slot - 1].sound) {
			_app->setCurrentZone(music[slot - 1].zone);
			_app->soundPlay(music[slot - 1].sound);
		}

		_app->setCurrentZone(kZoneSY);
		}
		break;

	case kObject99500:
		// Login
		if (target == 0) {
			_app->varSetByte(98006, 1);
			if (_app->puzzleSetMod(kPuzzleMenu, 2, 2)) {
				_app->objectPresentationShow(kObjectYesNo, 0);
				_app->objectSetAccessibilityOn(kObjectYesNo);
			}
		} else if (target == 1) {
			onLogin();
		}
		break;
	}
}

// 0x45ed80 jump table: the question dialog (object 4). Even targets are "yes", odd ones "no".
void ZoneSystemFaust::onQuestion(Id target) {
	uint32 question = 0;
	int8 slot = (int8)_app->varGetByte(98001);

	switch (target) {
	default:
		break;

	case 2:
		// Restart
		_app->cursorSelect(kCursorBusy);
		unsetFlag();
		handleEvents();
		_app->exitZone();
		_app->initZones();
		// Fallback to next case

	case 3:
		question = 2;
		break;

	case 4:
	case 8: {
		// Delete savegame (4: save screen, 8: load screen)
		question = target;
		Id visualId = (target == 4) ? 1 : 4;

		ObjectId objectId = _app->visualListGetObjectIdClicked(visualId, kPuzzleGeneralMenu);
		if (!objectId)
			break;

		Common::String name = _app->getObject(objectId)->getName();
		if (!_app->getSaveManager()->deleteSavegame(name)) {
			warning("[ZoneSystemFaust::onQuestion] Cannot remove saved game: %s", name.c_str());
			break;
		}

		_app->visualListResetObjectClicked(visualId, kPuzzleGeneralMenu);
		_app->visualListRemove(visualId, kPuzzleGeneralMenu, objectId, true);

		_name.clear();
		_app->objectPresentationSetTextToPuzzle(kObject99601, 1, 0, _name);
		uint32 width = _app->objectPresentationGetTextWidth(kObject99601, 1, 0);
		if (target == 4)
			_app->objectPresentationSetAnimationCoordinatesOnPuzzle(kObject99601, 0, Common::Point((int16)(width + 233), 384));
		else
			_app->objectPresentationSetAnimationCoordinatesOnPuzzle(kObject99601, 0, Common::Point((int16)(width + 195), 388));
		}
		break;

	case 5:
	case 9:
		question = target - 1;
		break;

	case 6: {
		// Delete user
		question = 6;

		ObjectId objectId = _app->visualListGetObjectIdClicked(3, kPuzzlePreferences);
		if (!objectId)
			break;

		Common::String name = _app->getObject(objectId)->getName();
		if (!_app->getSaveManager()->deleteUser(name)) {
			warning("[ZoneSystemFaust::onQuestion] Cannot remove saves for: %s", name.c_str());
			break;
		}

		// 0x45abdf: clear the name field
		_name.clear();
		_app->objectPresentationSetTextToPuzzle(kObject99501, 0, 0, _name);
		uint32 width = _app->objectPresentationGetTextWidth(kObject99501, 0, 0);
		_app->objectPresentationSetAnimationCoordinatesOnPuzzle(kObject99501, 0, Common::Point((int16)(width + 233), 334));

		_app->visualListResetObjectClicked(3, kPuzzlePreferences);
		_app->visualListRemove(3, kPuzzlePreferences, objectId, true);
		}
		break;

	case 7:
		question = 6;
		break;
	}

	_app->varSetByte(98001, slot);
	_app->messageHideQuestion(question);
}

// 0x45d698: jukebox arrows (13 tracks, track 2 is skipped)
void ZoneSystemFaust::onJukebox(Id target) {
	if (target == 0)
		--_jukeboxIndex;
	else if (target == 1)
		++_jukeboxIndex;

	if (_jukeboxIndex < 1)
		_jukeboxIndex = 13;
	else if (_jukeboxIndex > 13)
		_jukeboxIndex = 1;
	else if (_jukeboxIndex == 2 && target <= 1)
		_jukeboxIndex = (target == 0) ? 1 : 3;

	_app->objectPresentationHide(kObject99081);
	_app->objectPresentationShow(kObject99081, (uint32)(_jukeboxIndex - 1));
	_app->soundStopType(kSoundTypeAmbientMusic, 1024);
	_app->soundStopType(kSoundTypeBackgroundMusic, 1024);

	static const struct {
		ZoneId zone;
		Id sound;
	} tracks[] = {
		{ kZone7,  41001  },
		{ kZoneSY, 0      },
		{ kZone12, 81223  },
		{ kZone14, 112074 },
		{ kZone6,  31003  },
		{ kZone12, 81107  },
		{ kZoneSY, 90708  },
		{ kZone4,  13054  },
		{ kZone4,  13055  },
		{ kZone12, 81310  },
		{ kZone5,  17019  },
		{ kZone16, 310105 },
		{ kZone8,  52000  }
	};

	const Id sound = tracks[_jukeboxIndex - 1].sound;
	if (sound) {
		// Track 7 is a system zone sound, the original doesn't switch space for it
		if (tracks[_jukeboxIndex - 1].zone != kZoneSY)
			_app->setCurrentZone(tracks[_jukeboxIndex - 1].zone);

		_app->soundSetVolume(sound, 100);
		_app->soundPlay(sound, kSoundLoop);
	}

	_app->setCurrentZone(kZoneSY);
}

// 0x45e85e: login screen OK
void ZoneSystemFaust::onLogin() {
	if (_name.empty())
		return;

	if (_app->visualListIsIn(3, kPuzzlePreferences, _name)) {
		_app->setUser(_name);
	} else {
		// The original creates Data/Save/userN/, adds it to user.aba and copies zero.aba and aPre.ini into it
		if (!_app->getSaveManager()->createUser(_name))
			warning("[ZoneSystemFaust::onLogin] Cannot create user: %s", _name.c_str());

		_app->setUser(_name);
		_app->getSaveManager()->saveProgress(kProgressStateNone);
	}

	_app->visualListRemove(3, kPuzzlePreferences, true);

	_app->getSaveManager()->loadProgress();
	SaveManager::SavegameData *data = _app->getSaveManager()->getData();
	_app->varSetByte(98001, (byte)data->progressState);

	// Keep the progress animation frame within the range of the progress state
	static const struct {
		int32 min;
		int32 max;
		int32 reset;
	} ranges[] = {
		{  0,  4,  0 },
		{  4, 19,  4 },
		{ 19, 29, 19 },
		{ 29, 36, 29 },
		{ 36, 42, 39 },
		{ 42, 46, 42 },
		{ 46, 50, 46 }
	};

	if (data->progressState == kProgressStateNone) {
		_app->varSetByte(98001, 1);
		data->progressState = kProgressState1;
		data->progress = 0;
	} else if (data->progressState >= kProgressState8) {
		data->progress = 50;
	} else {
		int32 progress = (int8)data->progress;
		const int32 i = data->progressState - 1;
		if (progress < ranges[i].min || progress > ranges[i].max)
			data->progress = ranges[i].reset;
	}

	if (_app->getPreferenceHandler())
		_app->getPreferenceHandler()->load();
	else
		warning("[ZoneSystemFaust::onLogin] No preference handler");

	_app->_currentGameZone = kZoneNone;
	_app->_slot = -1;
	_app->startMenu(false);
	_jukeboxIndex = 1;
	_chapterIndex = 0;
}

// 0x45b410
void ZoneSystemFaust::hideMainMenuButtons() {
	for (uint32 i = kObject99000; i <= kObject99009; i++) {
		_app->objectSetAccessibilityOff((ObjectId)i);
		_app->objectPresentationHide((ObjectId)i);
		_app->objectPresentationShow((ObjectId)i, 1);
	}

	_app->objectSetAccessibilityOff(kObject14, 2, 2);
	_app->objectSetAccessibilityOff(kObject99100);
}

// The tail shared by most screens (0x45c047 / 0x45c053)
void ZoneSystemFaust::showMainMenu(bool enableArrows) {
	if (enableArrows)
		_app->objectSetAccessibilityOn(kObject99010);

	_app->initMenuSave(false);
	_app->initMenu2();
	_app->initMenu3();
}

void ZoneSystemFaust::hideMenuButtons(ObjectId from, ObjectId to) {
	for (int32 i = from; i <= to; i++) {
		_app->objectSetAccessibilityOff((ObjectId)i);
		_app->objectPresentationHide((ObjectId)i);
	}
}

// In-game menu hint for the current progress state
void ZoneSystemFaust::playHint(uint32 counterVar, int8 maxCount, Id baseSound) {
	if ((int8)_app->varGetByte(counterVar) >= maxCount)
		return;

	// 97006 is set by timer 12, so each new hint is only given 5 minutes after the previous one
	if (_app->varGetByte(97006) == 1) {
		_app->varSetByte(counterVar, _app->varGetByte(counterVar) + 1);
		_app->varSetByte(97006, 0);
		_app->timerStart(kTimer12, 300000);
	}

	_app->soundPlay(baseSound + (int8)_app->varGetByte(counterVar));
	_app->objectPresentationHide(kObject14, 8);
	_app->objectPresentationShow(kObject14, 7);
}

void ZoneSystemFaust::onButtonDown(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, const Common::Point &point) {
	if (id == kObject22 && target == 2) {
		_app->objectPresentationShow(kObject12, 2);
		_app->varSetByte(114101, 1);
	}
}

void ZoneSystemFaust::onAnimationNextFrame(Id animationId, const Common::String &name, uint32 frame, uint32 frameCount) {
	if (animationId == 2 && frame == _app->getSaveManager()->getData()->progress)
		_app->objectPresentationPauseAnimation(kObject99090, 0);
}

void ZoneSystemFaust::onSound(Id id, SoundType type, uint32 a3, bool process) {
	if (!process)
		return;

	switch (id) {
	default:
		break;

	case 90806:
		_app->exitToMenu(kMenuAction1);
		break;

	case 111042:
		_app->objectPresentationHide(kObject15);
		_app->objectSetAccessibilityOff(kObject1);
		_app->sub_468290(3);
		break;
	}
}

// Preference slider: drag x -> value (0..100) -> knob x
static int32 getSliderValue(DragControl *dragControl) {
	return CLIP<int32>((int32)((dragControl->getCurrentCoords().x - 166.0) * 0.3225806451612903), 0, 100);
}

static int16 getSliderKnobX(int32 value) {
	return (int16)(int32)((float)(value * 310 / 100) + 152.0f);
}

// FAUST.EXE 0x45ef10 (type: 1 = drag start, 2 = drag end, 3 = drag move)
void ZoneSystemFaust::onBag(ObjectId id, Id, Id, uint32, DragControl *dragControl, byte type) {
	switch (id) {
	default:
		return;

	case kObject23:
		// Coding wheel dial (36 positions)
		switch (type) {
		default:
			break;

		case 1:
			_app->dragControlSetCoords1(Common::Point(320, 240));
			_dialPosition = (int8)_app->varGetByte(114521);
			_dialLastPosition = -1;
			break;

		case 2:
			_app->varSetByte(114521, (byte)_dialPosition);
			break;

		case 3:
			if (!_app->dragControlYEqual() && !_app->dragControlXEqual()) {
				_dialPosition = ApplicationFaust::getDragAngle(dragControl) * 35 / 360 + 1;

				if (_dialLastPosition != _dialPosition) {
					if (_dialPosition < 0)
						_dialPosition += 36;

					_app->objectPresentationHideAndRemove(kObjectCodingWheel);
					if (_dialPosition < 36)
						_app->objectPresentationShow(kObjectCodingWheel, (uint32)(35 - _dialPosition));
					_app->soundPlay(112018);
				}
			}

			_dialLastPosition = _dialPosition;
			break;
		}
		return;

	case kObject99045:
		if (type == 1 || type == 3) {
			_prefsVolume = getSliderValue(dragControl);
			_app->objectPresentationSetImageCoordinatesOnPuzzle(kObject99045, 0, 0, Common::Point(getSliderKnobX(_prefsVolume), 164));
		}
		break;

	case kObject99046:
		switch (type) {
		default:
			break;

		case 1:
		case 3:
			_prefsVolumeDialog = getSliderValue(dragControl);
			_app->objectPresentationSetImageCoordinatesOnPuzzle(kObject99046, 0, 0, Common::Point(getSliderKnobX(_prefsVolumeDialog), 210));
			if (type == 1)
				_app->soundPlay(90800, kSoundLoop);
			break;

		case 2:
			_app->soundStop(90800, 1024);
			break;
		}
		break;
	}

	savePreferences();
}

void ZoneSystemFaust::savePreferences() {
	if (!_app->getPreferenceHandler()) {
		warning("[ZoneSystemFaust::savePreferences] AGV_preferences == NULL");
		return;
	}

	// FAUST.EXE 0x45f0a1: the sliders (0..100) are stored as slider / 4 + 75, so the lowest setting is -25 dB
	_app->getPreferenceHandler()->save(_prefsVolume / 4 + 75, _prefsVolumeDialog / 4 + 75, _prefsReverseStereo ? 1 : -1, _prefsSubtitles);
}

void ZoneSystemFaust::onUpdateBag(const Common::Point &point) {
	if (_app->hasCurrentPuzzle() && _app->getCurrentPuzzleId() == kPuzzleMenu) {
		_app->objectPresentationHide(kObject14, 2);
		_app->objectPresentationHide(kObject14, 4);
		_app->objectPresentationHide(kObject14, 6);
	}

	_app->objectPresentationHide(kObject99091, 1);
	_app->objectPresentationHide(kObject99091, 2);
	_app->objectPresentationHide(kObject99091, 3);
	_app->objectPresentationHide(kObjectYesNo, 2);
	_app->objectPresentationHide(kObjectYesNo, 1);
	_app->objectPresentationHide(kObjectQuestion, 1);
	_app->objectPresentationHide(kObjectQuestion, 2);
	_app->objectPresentationHide(kObject3, 1);
	_app->objectPresentationHide(kObject99500);
	_app->objectPresentationHide(kObject99010, 2);
	_app->objectPresentationHide(kObject99010, 4);
	_app->objectPresentationHide(kObject99000, 0);

	if (!_app->varGetByte(98003))
		_app->objectPresentationHide(kObject99001, 0);

	if (!_app->varGetByte(98004))
		_app->objectPresentationHide(kObject99002, 0);

	if (!_app->varGetByte(98005))
		_app->objectPresentationHide(kObject99003, 0);

	if (!_app->varGetByte(98006))
		_app->objectPresentationHide(kObject99004, 0);

	if (!_app->varGetByte(98007))
		_app->objectPresentationHide(kObject99005, 0);

	if (!_app->varGetByte(98008))
		_app->objectPresentationHide(kObject99006, 0);

	if (!_app->varGetByte(98009))
		_app->objectPresentationHide(kObject99007, 0);

	if (!_app->varGetByte(98010))
		_app->objectPresentationHide(kObject99008, 0);

	if (!_app->varGetByte(98011))
		_app->objectPresentationHide(kObject99009, 0);

	_app->objectPresentationHide(kObject99023, 0);
	_app->objectPresentationHide(kObject99022, 0);
	_app->objectPresentationHide(kObject99021, 0);
	_app->objectPresentationHide(kObject99025, 0);
	_app->objectPresentationHide(kObject99024, 0);
	_app->objectPresentationHide(kObject99042, 0);
	_app->objectPresentationHide(kObject99041, 0);
	_app->objectPresentationHide(kObject99097, 0);
	_app->objectPresentationHide(kObject55, 0);
	_app->objectPresentationHide(kObject55, 2);
}

// FAUST.EXE 0x45f330: mouse-over handler (movabilityFrom is the object id, movabilityTo the accessibility index)
void ZoneSystemFaust::onUpdateBefore(Id movabilityFrom, Id movabilityTo, uint32, Id, const Common::Point &point) {
	ObjectId id = (ObjectId)movabilityFrom;
	Id target = movabilityTo;

	if (id == kObject22) {
		// Radio tuning knob (zone 14)
		_app->objectPresentationSetImageCoordinatesOnPuzzle(kObject12, 1, point);

		if (_app->varGetByte(114101) > 0) {
			if (point.x < 333) {
				_object22Volume = 0;

				int32 distance = ABS(260 - point.y);
				if (distance > 3)
					_object22Volume = 2 * distance + 80;

				if (point.x >= 245 || point.y <= 260) {
					if (_object22Volume > 120) {
						_app->objectPresentationHide(kObject12, 2);
						_app->objectPresentationHide(kObject12, 1);
						_app->objectSetAccessibilityOff(kObject22);
						_app->objectSetAccessibilityOn(kObject22, 0, 0);
						_app->varSetByte(114101, 0);
						_app->soundStop(112016, 1024);
						_app->sub_468290(1);
						return;
					}

					if (_object22Volume > 100)
						_object22Volume = 100;
				} else {
					_object22Volume = 0;
				}
			} else {
				_object22Volume = 0;
				_app->varSetByte(114101, 0);
			}

			_app->varSetByte(114101, (point.x < 245 && point.y > 336) ? 2 : 1);
			_app->soundSetVolume(112016, (uint32)_object22Volume);
		}

		if (point.y > 410 && !_app->varGetByte(114101))
			_app->sub_45FF30();

		return;
	}

	if (id == kObject99010)
		_app->objectPresentationShow(kObject99010, (uint32)(2 * target + 2));

	// Menu buttons: only highlight the hovered one in each group
	if (id >= kObject99000 && id <= kObject99009) {
		for (uint32 i = kObject99000; i <= kObject99009; i++)
			_app->objectPresentationHide((ObjectId)i, 0);
		_app->objectPresentationShow(id, 0);
	}

	if (id >= kObject99021 && id <= kObject99025) {
		for (uint32 i = kObject99021; i <= kObject99025; i++)
			_app->objectPresentationHide((ObjectId)i, 0);
		_app->objectPresentationShow(id, 0);
	}

	if (id >= kObject99041 && id <= kObject99042) {
		for (uint32 i = kObject99041; i <= kObject99042; i++)
			_app->objectPresentationHide((ObjectId)i, 0);
		_app->objectPresentationShow(id, 0);
	}

	switch (id) {
	default:
		break;

	case kObjectYesNo:
		_app->objectPresentationHide(kObjectYesNo, 1);
		_app->objectPresentationHide(kObjectYesNo, 2);
		if (target == 0)
			_app->objectPresentationShow(kObjectYesNo, 2);
		else if (target == 1)
			_app->objectPresentationShow(kObjectYesNo, 1);
		break;

	case kObject3:
		_app->objectPresentationShow(kObject3, 1);
		break;

	case kObjectQuestion:
		// Even accessibility indices are "yes", odd ones "no"
		if (target % 2) {
			_app->objectPresentationHide(kObjectQuestion, 1);
			_app->objectPresentationShow(kObjectQuestion, 2);
		} else {
			_app->objectPresentationHide(kObjectQuestion, 2);
			_app->objectPresentationShow(kObjectQuestion, 1);
		}
		break;

	case kObject14:
		_app->objectPresentationHide(kObject14, 2);
		_app->objectPresentationHide(kObject14, 4);
		_app->objectPresentationHide(kObject14, 6);
		if (target == 0)
			_app->objectPresentationShow(kObject14, 2);
		else if (target == 1)
			_app->objectPresentationShow(kObject14, 4);
		break;

	case kObject55:
		_app->objectPresentationHide(kObject55, 0);
		_app->objectPresentationHide(kObject55, 2);
		_app->objectPresentationShow(kObject55, target == 99 ? 2 : 0);
		break;

	case kObject99091:
		_app->objectPresentationHide(kObject99091, 1);
		_app->objectPresentationHide(kObject99091, 2);
		_app->objectPresentationHide(kObject99091, 3);
		_app->objectPresentationShow(kObject99091, (uint32)target);
		break;

	case kObject99097:
		_app->objectPresentationHide(kObject99097, 0);
		_app->objectPresentationShow(kObject99097, 0);
		break;

	case kObject99500:
		_app->objectPresentationHide(kObject99500);
		_app->objectPresentationShow(kObject99500, target == 1 ? 0 : 1);
		break;
	}
}

void ZoneSystemFaust::onVisualList(Id id, uint32 type, const Common::Point &) {
	switch (id) {
	default:
		break;

	case 1:
		if (type == 3) {
			ObjectId objectId = _app->visualListGetObjectIdClicked(1, kPuzzleGeneralMenu);
			_name = _app->getObject(objectId)->getName();
			_app->objectPresentationSetTextToPuzzle(kObject99601, 1, 0, _name);

			uint32 width = _app->objectPresentationGetTextWidth(kObject99601, 1, 0);
			_app->objectPresentationSetAnimationCoordinatesOnPuzzle(kObject99601, 0, Common::Point(width + 233, 384));
		}
		break;

	case 3:
		if (type == 3) {
			ObjectId objectId = _app->visualListGetObjectIdClicked(3, kPuzzlePreferences);
			_name = _app->getObject(objectId)->getName();
			_app->objectPresentationSetTextToPuzzle(kObject99501, 0, 0, _name);

			uint32 width = _app->objectPresentationGetTextWidth(kObject99501, 0, 0);
			_app->objectPresentationSetAnimationCoordinatesOnPuzzle(kObject99501, 0, Common::Point(width + 233, 334));
		}
		break;

	case 4:
		if (type == 3) {
			ObjectId objectId = _app->visualListGetObjectIdClicked(4, kPuzzleGeneralMenu);
			_name = _app->getObject(objectId)->getName();
			_app->objectPresentationSetTextToPuzzle(kObject99601, 1, 0, _name);

			uint32 width = _app->objectPresentationGetTextWidth(kObject99601, 1, 0);
			_app->objectPresentationSetAnimationCoordinatesOnPuzzle(kObject99601, 0, Common::Point(width + 233, 384));

			_app->objectSetAccessibilityOn(kObject99023);
			_app->objectPresentationHide(kObject99023, 1);
			_app->objectPresentationShow(kObject99023, 2);
		}
		break;
	}
}

} // End of namespace Ring
