/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 5
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 05110-1301, USA.
 */

#include "ring/game/faust/faust_zone5.h"

#include "ring/base/saveload.h"

#include "ring/game/faust/faust_application.h"
#include "ring/game/faust/faust_shared.h"

#include "ring/debug.h"
#include "ring/ring.h"
#include "ring/helpers.h"

 using namespace FaustGame;

namespace Ring {

Zone5Faust::Zone5Faust(ApplicationFaust *application) : _app(application), _dragValue(0), _dragPrevious(0) {
}

Zone5Faust::~Zone5Faust() {
	// Zero-out passed pointers
	_app = nullptr;
}

void Zone5Faust::onInit() {
	_app->setCurrentZone(kZone5);

	_app->puzzleAdd(kPuzzle17021);
	_app->puzzleAddBackgroundImage(kPuzzle17021, "a01s07n02p01.0001.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle17031);
	_app->puzzleAddBackgroundImage(kPuzzle17031, "a01s07n03p01.0001.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle17042);
	_app->puzzleAddBackgroundImage(kPuzzle17042, "a01s07n04p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle17022);
	_app->puzzleAddBackgroundImage(kPuzzle17022, "a01s07n02p02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle17051);
	_app->puzzleAddBackgroundImage(kPuzzle17051, "a01s07n05p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle17062);
	_app->puzzleAddBackgroundImage(kPuzzle17062, "a01s07n0xp02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle17063);
	_app->puzzleAddBackgroundImage(kPuzzle17063, "a01s07n0xp03.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle17064);
	_app->puzzleAddBackgroundImage(kPuzzle17064, "a01s07n0xp04.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle17065);
	_app->puzzleAddBackgroundImage(kPuzzle17065, "a01s07n0xp05.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle17066);
	_app->puzzleAddBackgroundImage(kPuzzle17066, "a01s07n0xp06.bmp", Common::Point(0, 16), true);
	_app->rotationAdd(17001, "A01S07N01R01", 0, 13);
	_app->rotationAdd(17002, "A01S07N02R01", 0, 8);
	_app->rotationAdd(17003, "A01S07N03R01", 0, 8);
	_app->rotationAdd(17004, "A01S07N04R01", 0, 6);
	_app->rotationAdd(17005, "A01S07N05R01", 0, 13);
	_app->rotationSetCompressionBufferLength(17005, 1600000);
	_app->rotationAddMovabilityToRotation(17001, 17002, "", Common::Rect(0, -140, 103, 436), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17001, 0, 306.0f, 0.3f, 87.0f, 0.0f, 2, 306.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17001, 17002, "", Common::Rect(3334, 148, 3600, 452), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17001, 1, 306.0f, 0.3f, 87.0f, 0.0f, 2, 306.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17001, 17003, "", Common::Rect(3285, -99, 3550, 145), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17001, 2, 294.0f, 0.3f, 87.0f, 0.0f, 2, 294.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17001, 17004, "", Common::Rect(3056, -77, 3269, 266), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17001, 3, 273.0f, 0.3f, 87.0f, 0.0f, 2, 273.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17001, 17005, "", Common::Rect(2750, -24, 3033, 271), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17001, 4, 248.0f, 0.3f, 87.0f, 0.0f, 2, 248.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17002, 17001, "", Common::Rect(1648, -143, 2141, 343), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17002, 0, 126.0f, 0.3f, 87.0f, 0.0f, 2, 126.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17002, 17003, "", Common::Rect(3178, -59, 3566, 343), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17002, 1, 283.0f, 0.3f, 87.0f, 0.0f, 2, 283.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17002, 17004, "", Common::Rect(2661, -87, 2988, 287), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17002, 2, 252.0f, 0.3f, 87.0f, 0.0f, 2, 252.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17002, 17005, "", Common::Rect(2184, -92, 2634, 327), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17002, 3, 198.0f, 0.3f, 87.0f, 0.0f, 2, 198.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17003, 17001, "", Common::Rect(1486, -75, 1686, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17003, 0, 114.0f, 0.3f, 87.0f, 0.0f, 2, 114.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17003, 17002, "", Common::Rect(1096, -141, 1599, 462), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17003, 1, 103.0f, 0.3f, 87.0f, 0.0f, 2, 103.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17003, 17004, "", Common::Rect(2415, -75, 2615, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17003, 2, 207.0f, 0.3f, 87.0f, 0.0f, 2, 207.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17003, 17005, "", Common::Rect(1863, -75, 2063, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17003, 3, 151.0f, 0.3f, 87.0f, 0.0f, 2, 151.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(17003, kPuzzle17031, "", Common::Rect(2300, 448, 2589, 511), false, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(17003, 4, 0.0f, 15.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(17004, 17001, "", Common::Rect(1218, -129, 1532, 375), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17004, 0, 93.0f, 0.3f, 87.0f, 0.0f, 2, 93.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17004, 17002, "", Common::Rect(718, -129, 1225, 327), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17004, 1, 72.0f, 0.3f, 87.0f, 0.0f, 2, 72.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17004, 17003, "", Common::Rect(114, -126, 789, 348), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17004, 2, 27.0f, 0.3f, 87.0f, 0.0f, 2, 27.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17004, 17005, "", Common::Rect(1583, -115, 2149, 345), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17004, 3, 119.0f, 0.3f, 87.0f, 0.0f, 2, 119.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17005, 17001, "", Common::Rect(810, -3, 1165, 460), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17005, 0, 68.0f, 0.3f, 87.0f, 0.0f, 2, 68.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17005, 17002, "", Common::Rect(416, -43, 806, 425), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17005, 1, 18.0f, 0.3f, 87.0f, 0.0f, 2, 18.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17005, 17003, "", Common::Rect(63, -24, 432, 241), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17005, 2, 331.0f, 0.3f, 87.0f, 0.0f, 2, 331.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(17005, 17004, "", Common::Rect(3251, -7, 3600, 448), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(17005, 3, 299.0f, 0.3f, 87.0f, 0.0f, 2, 299.0f, 0.3f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle17031, 17003, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 99);
	_app->puzzleSetMovabilityToRotation(kPuzzle17031, 0, 184.0f, 26.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle17022, 17002, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 99);

	_app->objectAdd(kObject18, "", "", 1);
	_app->objectAddRotationAccessibility(kObject18, 17001, Common::Rect(1007, -188, 1232, 322), true, kCursorMove, 0);
	_app->objectAddPuzzleAccessibility(kObject18, kPuzzleMenu, Common::Rect(0, 0, 640, 480), false, kCursorIdle, 77);

	_app->objectAdd(kObjectRat, "Rat", "a06_Rat", 1);
	_app->objectSetActiveCursor(kObjectRat, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectRat, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddRotationAccessibility(kObjectRat, 17004, Common::Rect(1719, 156, 1850, 251), false, kCursorTake, 0);
	_app->objectAddRotationAccessibility(kObjectRat, 17001, Common::Rect(2814, 108, 2879, 173), false, kCursorTake, 0);
	_app->objectAddRotationAccessibility(kObjectRat, 17002, Common::Rect(2350, 131, 2441, 192), false, kCursorTake, 0);
	_app->objectAddPresentation(kObjectRat);
	_app->objectPresentationAddImageToRotation(kObjectRat, 0, 17001, 9);
	_app->objectPresentationAddImageToRotation(kObjectRat, 0, 17002, 4);
	_app->objectPresentationAddImageToRotation(kObjectRat, 0, 17003, 6);
	_app->objectPresentationAddImageToRotation(kObjectRat, 0, 17004, 5);
	_app->objectPresentationShow(kObjectRat);
	_app->objectAdd(kObject17006, "", "", 1);
	_app->objectAddRotationAccessibility(kObject17006, 17003, Common::Rect(59, 170, 724, 486), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject17006, 17003, Common::Rect(174, 34, 624, 291), false, kCursorAction, 1);
	_app->objectAddPresentation(kObject17006);
	_app->objectPresentationAddImageToRotation(kObject17006, 0, 17003, 0);
	_app->objectAddPresentation(kObject17006);
	_app->objectPresentationAddImageToRotation(kObject17006, 1, 17003, 2);
	_app->objectAdd(kObject17304, "", "", 1);
	_app->objectAddRotationAccessibility(kObject17304, 17003, Common::Rect(3086, -24, 3304, 371), true, kCursorZoom, 0);
	_app->objectAdd(kObjectHandle, "Handle", "a06_Handle", 1);
	_app->objectSetActiveCursor(kObjectHandle, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectHandle, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddRotationAccessibility(kObjectHandle, 17003, Common::Rect(202, 326, 597, 453), false, kCursorTake, 0);
	_app->objectAddRotationAccessibility(kObjectHandle, 17002, Common::Rect(367, 333, 497, 451), true, kCursorActionObject, 1);
	_app->objectAddPuzzleAccessibility(kObjectHandle, kPuzzle17022, Common::Rect(77, 126, 154, 223), true, kCursorAction, 2);
	_app->objectAddRotationAccessibility(kObjectHandle, 17002, Common::Rect(465, 174, 940, 394), false, kCursorMove, 3);
	_app->objectAddPresentation(kObjectHandle);
	_app->objectAddPresentation(kObjectHandle);
	_app->objectPresentationAddAnimationToPuzzle(kObjectHandle, 1, kPuzzle17022, "a01s07n02p02s01", kImageTypeBMP, Common::Point(92, 140), kDrawTypeNormal, 1000, 10, 20.0f, 6);
	_app->objectAddPresentation(kObjectHandle);
	_app->objectPresentationAddAnimationToPuzzle(kObjectHandle, 2, kPuzzle17022, "a01s07n02p02s02a", kImageTypeBMP, Common::Point(168, 93), kDrawTypeNormal, 1000, 5, 25.0f, 6);
	_app->objectAddPresentation(kObjectHandle);
	_app->objectPresentationAddAnimationToPuzzle(kObjectHandle, 3, kPuzzle17022, "a01s07n02p02s02b", kImageTypeBMP, Common::Point(245, 84), kDrawTypeNormal, 1000, 5, 25.0f, 6);
	_app->objectAddPresentation(kObjectHandle);
	_app->objectPresentationAddAnimationToPuzzle(kObjectHandle, 4, kPuzzle17022, "a01s07n02p02s02c", kImageTypeBMP, Common::Point(319, 92), kDrawTypeNormal, 1000, 5, 25.0f, 6);
	_app->objectAddPresentation(kObjectHandle);
	_app->objectPresentationAddAnimationToPuzzle(kObjectHandle, 5, kPuzzle17022, "a01s07n02p02s02d", kImageTypeBMP, Common::Point(396, 92), kDrawTypeNormal, 1000, 5, 25.0f, 6);
	_app->objectAddPresentation(kObjectHandle);
	_app->objectPresentationAddAnimationToPuzzle(kObjectHandle, 6, kPuzzle17022, "a01s07n02p02s02e", kImageTypeBMP, Common::Point(468, 95), kDrawTypeNormal, 1000, 5, 25.0f, 6);
	_app->objectAddPresentation(kObjectHandle);
	_app->objectPresentationAddAnimationToPuzzle(kObjectHandle, 7, kPuzzle17022, "a01s07n02p02s02a", kImageTypeBMP, Common::Point(168, 93), kDrawTypeNormal, 1000, 5, 25.0f, 10);
	_app->objectAddPresentation(kObjectHandle);
	_app->objectPresentationAddAnimationToPuzzle(kObjectHandle, 8, kPuzzle17022, "a01s07n02p02s02b", kImageTypeBMP, Common::Point(245, 84), kDrawTypeNormal, 1000, 5, 25.0f, 10);
	_app->objectAddPresentation(kObjectHandle);
	_app->objectPresentationAddAnimationToPuzzle(kObjectHandle, 9, kPuzzle17022, "a01s07n02p02s02c", kImageTypeBMP, Common::Point(319, 92), kDrawTypeNormal, 1000, 5, 25.0f, 10);
	_app->objectAddPresentation(kObjectHandle);
	_app->objectPresentationAddAnimationToPuzzle(kObjectHandle, 10, kPuzzle17022, "a01s07n02p02s02d", kImageTypeBMP, Common::Point(396, 92), kDrawTypeNormal, 1000, 5, 25.0f, 10);
	_app->objectAddPresentation(kObjectHandle);
	_app->objectPresentationAddAnimationToPuzzle(kObjectHandle, 11, kPuzzle17022, "a01s07n02p02s02e", kImageTypeBMP, Common::Point(468, 95), kDrawTypeNormal, 1000, 5, 25.0f, 10);
	_app->objectAddPresentation(kObjectHandle);
	_app->objectPresentationAddImageToRotation(kObjectHandle, 12, 17005, 8);
	_app->objectAddPresentation(kObjectHandle);
	_app->objectPresentationAddImageToRotation(kObjectHandle, 13, 17002, 6);
	_app->objectPresentationShow(kObjectHandle, 13);
	_app->objectAdd(kObject17001, "", "", 1);
	_app->objectAddRotationAccessibility(kObject17001, 17001, Common::Rect(2490, 429, 2724, 526), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject17001, 17001, Common::Rect(2770, 284, 3056, 458), false, kCursorAction, 1);
	_app->objectAddRotationAccessibility(kObject17001, 17001, Common::Rect(2221, 430, 2525, 591), false, kCursorAction, 1);
	_app->objectAddPresentation(kObject17001);
	_app->objectPresentationAddImageToRotation(kObject17001, 0, 17001, 0);
	_app->objectAddPresentation(kObject17001);
	_app->objectAdd(kObject17002, "", "", 1);
	_app->objectAddRotationAccessibility(kObject17002, 17001, Common::Rect(2490,    0, 2724, 200), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject17002, 17001, Common::Rect(2719,  -83, 2975, 235), false, kCursorAction, 1);
	_app->objectAddRotationAccessibility(kObject17002, 17001, Common::Rect(2100, -181, 2258, 415), false, kCursorAction, 1);
	_app->objectAddPresentation(kObject17002);
	_app->objectPresentationAddImageToRotation(kObject17002, 0, 17001, 2);
	_app->objectAdd(kObject17003, "", "", 1);
	_app->objectAddPresentation(kObject17003);
	_app->objectPresentationAddImageToRotation(kObject17003, 0, 17001, 3);
	_app->objectAddPresentation(kObject17003);
	_app->objectPresentationAddImageToRotation(kObject17003, 1, 17001, 4);
	_app->objectAdd(kObject17022, "", "", 3);
	_app->objectAddRotationAccessibility(kObject17022, 17001, Common::Rect(2590, -45, 2624, 12), false, kCursorMenuActive, 0);
	_app->objectAddRotationAccessibility(kObject17022, 17001, Common::Rect(2626, -45, 2664, 12), false, kCursorMenuActive, 1);
	_app->objectAddRotationAccessibility(kObject17022, 17001, Common::Rect(2666, -45, 2690, 12), false, kCursorMenuActive, 2);
	_app->objectAddPresentation(kObject17022);
	_app->objectPresentationAddImageToRotation(kObject17022, 0, 17001, 10);
	_app->objectAddPresentation(kObject17022);
	_app->objectPresentationAddImageToRotation(kObject17022, 1, 17001, 11);
	_app->objectAddPresentation(kObject17022);
	_app->objectPresentationAddImageToRotation(kObject17022, 2, 17001, 12);
	_app->objectAdd(kObjectKey, "Key", "a06_BarKey", 1);
	_app->objectSetActiveCursor(kObjectKey, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectKey, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddRotationAccessibility(kObjectKey, 17001, Common::Rect(2255, 146, 2334, 233), false, kCursorTake, 0);
	_app->objectAdd(kObject17029, "", "", 1);
	_app->objectAddRotationAccessibility(kObject17029, 17001, Common::Rect(2269, -71, 2700,  81), false, kCursorZoom, 0);
	_app->objectAddRotationAccessibility(kObject17029, 17001, Common::Rect(2325, 102, 2541, 218), false, kCursorZoom, 0);
	_app->objectAdd(kObject17504, "", "", 1);
	_app->objectAddRotationAccessibility(kObject17504, 17004, Common::Rect(2116, 174, 2380, 333), true, kCursorZoom, 0);
	_app->objectAddRotationAccessibility(kObject17504, 17005, Common::Rect(2988, 312, 3290, 455), true, kCursorZoom, 0);
	_app->objectAddPuzzleAccessibility(kObject17504, kPuzzle17042, Common::Rect(0, 420, 640, 464), true, kCursorBack, 1);
	_app->objectAdd(kObject17506, "", "CUR_DRAG", 4);
	_app->objectSetActiveDrawCursor(kObject17506, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveDrawCursor(kObject17506, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObject17506, kPuzzle17042, Common::Rect(82, 296, 160, 372), true, kCursorDragDrop, 0);

	for (uint32 i = 0; i < 15; i++) {
		_app->objectAddPresentation(kObject17506);
		_app->objectPresentationAddImageToPuzzle(kObject17506, i, kPuzzle17042, Common::String::format("a01s07n04p01s02.%04d.bmp", i + 1), Common::Point(0, 92), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject17401, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject17401, kPuzzle17042, Common::Rect(434, 221, 503, 352), true, kCursorActionObject, 0);
	_app->objectAddPuzzleAccessibility(kObject17401, kPuzzle17042, Common::Rect(313, 176, 502, 355), true, kCursorActionObject, 1);
	_app->objectAddPresentation(kObject17401);
	_app->objectPresentationAddAnimationToPuzzle(kObject17401, 0, kPuzzle17042, "a01s07n04p01s01", kImageTypeBMP, Common::Point(271, 174), kDrawTypeNormal, 1000, 5, 12.5f, 4);
	_app->objectPresentationAddAnimationToRotation(kObject17401, 0, 17001, 1, 5, 12.5f, 4);
	_app->objectPresentationAddAnimationToRotation(kObject17401, 0, 17002, 1, 5, 12.5f, 4);
	_app->objectPresentationAddAnimationToRotation(kObject17401, 0, 17003, 1, 5, 12.5f, 4);
	_app->objectPresentationAddAnimationToRotation(kObject17401, 0, 17004, 1, 5, 12.5f, 4);
	_app->objectAddPresentation(kObject17401);
	_app->objectPresentationAddAnimationToRotation(kObject17401, 1, 17005, 11, 5, 12.5f, 4);
	_app->objectAddPresentation(kObject17401);
	_app->objectPresentationAddAnimationToRotation(kObject17401, 2, 17005, 12, 5, 12.5f, 4);
	_app->objectAdd(kObject17505, "", "", 1);
	_app->objectAddPresentation(kObject17505);
	_app->objectPresentationAddImageToPuzzle(kObject17505, 0, kPuzzle17042, "a01s07n04p01s02.0015.bmp", Common::Point(0, 92), true, kDrawTypeNormal, 1000);
	_app->objectPresentationAddImageToRotation(kObject17505, 0, 17001, 8);
	_app->objectPresentationAddImageToRotation(kObject17505, 0, 17002, 5);
	_app->objectPresentationAddImageToRotation(kObject17505, 0, 17003, 7);
	_app->objectPresentationAddImageToRotation(kObject17505, 0, 17004, 2);
	_app->objectPresentationAddImageToRotation(kObject17505, 0, 17005, 7);
	_app->objectAdd(kObjectCylinder, "Cylinder", "a06_RoulCyl", 1);
	_app->objectSetActiveCursor(kObjectCylinder, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectCylinder, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddRotationAccessibility(kObjectCylinder, 17004, Common::Rect(2833, -83, 3093, 172), true, kCursorTake, 0);
	_app->objectAddRotationAccessibility(kObjectCylinder, 17002, Common::Rect(2787, 305, 3171, 497), true, kCursorActionObject, 1);
	_app->objectAddRotationAccessibility(kObjectCylinder, 17004, Common::Rect(808,  263, 1179, 427), true, kCursorActionObject, 1);
	_app->objectAddRotationAccessibility(kObjectCylinder, 17003, Common::Rect(1761, 286, 2112, 456), true, kCursorActionObject, 1);
	_app->objectAddRotationAccessibility(kObjectCylinder, 17002, Common::Rect(2787, 305, 3171, 497), false, kCursorActionObject, 2);
	_app->objectAddRotationAccessibility(kObjectCylinder, 17004, Common::Rect(808,  263, 1179, 427), false, kCursorActionObject, 2);
	_app->objectAddRotationAccessibility(kObjectCylinder, 17003, Common::Rect(1761, 286, 2112, 456), false, kCursorActionObject, 2);
	_app->objectAddPuzzleAccessibility(kObjectCylinder, kPuzzle17021, Common::Rect(274, 174, 333, 233), true, kCursorMenuActive, 3);
	_app->objectAddPuzzleAccessibility(kObjectCylinder, kPuzzle17021, Common::Rect(  0, 420, 640, 464), true, kCursorBack, 9);
	_app->objectAddPresentation(kObjectCylinder);
	_app->objectPresentationAddImageToRotation(kObjectCylinder, 0, 17001, 5);
	_app->objectPresentationAddImageToRotation(kObjectCylinder, 0, 17002, 0);
	_app->objectPresentationAddImageToRotation(kObjectCylinder, 0, 17003, 3);
	_app->objectPresentationAddImageToRotation(kObjectCylinder, 0, 17004, 0);
	_app->objectPresentationAddImageToRotation(kObjectCylinder, 0, 17005, 4);
	_app->objectAddPresentation(kObjectCylinder);
	_app->objectPresentationAddImageToRotation(kObjectCylinder, 1, 17001, 6);
	_app->objectPresentationAddImageToRotation(kObjectCylinder, 1, 17002, 2);
	_app->objectPresentationAddImageToRotation(kObjectCylinder, 1, 17003, 4);
	_app->objectPresentationAddImageToRotation(kObjectCylinder, 1, 17004, 3);
	_app->objectPresentationAddImageToRotation(kObjectCylinder, 1, 17005, 5);
	_app->objectAddPresentation(kObjectCylinder);
	_app->objectPresentationAddImageToPuzzle(kObjectCylinder, 2, kPuzzle17021, "a01s07n02p01l01.0001.bmp", Common::Point(294, 186), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObjectWhip, "Whip", "a06_Whip", 1);
	_app->objectSetActiveCursor(kObjectWhip, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectWhip, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectWhip, kPuzzle17031, Common::Rect( 84, 188, 302, 289), true, kCursorTake, 0);
	_app->objectAddPuzzleAccessibility(kObjectWhip, kPuzzle17022, Common::Rect(160,  90, 220, 150), false, kCursorActionObject, 10);
	_app->objectAddPuzzleAccessibility(kObjectWhip, kPuzzle17022, Common::Rect(240,  90, 300, 150), false, kCursorActionObject, 11);
	_app->objectAddPuzzleAccessibility(kObjectWhip, kPuzzle17022, Common::Rect(320,  90, 380, 150), false, kCursorActionObject, 12);
	_app->objectAddPuzzleAccessibility(kObjectWhip, kPuzzle17022, Common::Rect(400,  90, 460, 150), false, kCursorActionObject, 13);
	_app->objectAddPuzzleAccessibility(kObjectWhip, kPuzzle17022, Common::Rect(480,  90, 540, 150), false, kCursorActionObject, 14);
	_app->objectAddPresentation(kObjectWhip);
	_app->objectPresentationAddImageToPuzzle(kObjectWhip, 0, kPuzzle17031, "a01s07n03p01l01.0001.bmp", Common::Point(91, 195), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObjectReel, "Reel", "a06_Reel", 1);
	_app->objectSetActiveCursor(kObjectReel, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectReel, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectReel, kPuzzle17031, Common::Rect(349, 179, 522, 239), true, kCursorTake, 0);
	_app->objectAddPresentation(kObjectReel);
	_app->objectPresentationAddImageToPuzzle(kObjectReel, 0, kPuzzle17031, "a01s07n03p01l02.0001.bmp", Common::Point(367, 187), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObject17201, "", "CUR_DRAG", 4);
	_app->objectSetActiveDrawCursor(kObject17201, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveDrawCursor(kObject17201, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObject17201, kPuzzle17021, Common::Rect(4, 239, 531, 459), true, kCursorDragDrop, 0);

	for (uint32 i = 0; i < 76; i++) {
		_app->objectAddPresentation(kObject17201);
		_app->objectPresentationAddImageToPuzzle(kObject17201, i, kPuzzle17021, Common::String::format("a01s07n02p01s01.%04d.bmp", i + 1), Common::Point(0, 228), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject17203, "", "", 1);
	_app->objectAddPresentation(kObject17203);
	_app->objectPresentationAddImageToPuzzle(kObject17203, 0, kPuzzle17021, "a01s07n02p01s02.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 800);
	_app->objectPresentationAddAnimationToPuzzle(kObject17203, 0, kPuzzle17021, "a01s07n02p01s02", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 800, 15, 12.5f, 6);
	_app->objectPresentationSetAnimationOnPuzzle(kObject17203, 0, 0, 17008);
	_app->objectPresentationAddImageToRotation(kObject17203, 0, 17001, 7);
	_app->objectPresentationAddImageToRotation(kObject17203, 0, 17002, 3);
	_app->objectPresentationAddImageToRotation(kObject17203, 0, 17003, 5);
	_app->objectPresentationAddImageToRotation(kObject17203, 0, 17004, 4);
	_app->objectPresentationAddImageToRotation(kObject17203, 0, 17005, 6);
	_app->objectAdd(kObject17204, "", "", 1);
	_app->objectAddRotationAccessibility(kObject17204, 17002, Common::Rect(3596, 92, 3600, 493), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject17204, 17002, Common::Rect(0, 92, 346, 493), true, kCursorAction, 0);
	_app->objectAddPresentation(kObject17204);
	_app->objectPresentationAddImageToRotation(kObject17204, 0, 17002, 7);
	_app->objectAdd(kObject17402, "", "", 1);
	_app->objectAddRotationAccessibility(kObject17402, 17004, Common::Rect(2358, 169, 2657, 470), true, kCursorZoom, 0);
	_app->objectAdd(kObject17403, "", "", 1);
	_app->objectAddRotationAccessibility(kObject17403, 17004, Common::Rect(3366, 162, 3564, 240), true, kCursorZoom, 0);
	_app->objectAdd(kObject17205, "", "", 1);
	_app->objectAddRotationAccessibility(kObject17205, 17002, Common::Rect(3577, -219, 3600, -139), true, kCursorZoom, 4);
	_app->objectAddRotationAccessibility(kObject17205, 17002, Common::Rect(   0, -219,  131, -139), true, kCursorZoom, 4);
	_app->objectAddRotationAccessibility(kObject17205, 17002, Common::Rect( 383, -286,  588, -174), true, kCursorZoom, 5);
	_app->objectAddRotationAccessibility(kObject17205, 17003, Common::Rect( 416, -401,  718, -261), true, kCursorZoom, 4);
	_app->objectAddRotationAccessibility(kObject17205, 17003, Common::Rect( 383, -286,  588, -174), true, kCursorZoom, 5);
	_app->objectAddRotationAccessibility(kObject17205, 17003, Common::Rect(2626, -198, 2743, -136), true, kCursorZoom, 1);
	_app->objectAddRotationAccessibility(kObject17205, 17003, Common::Rect(2768, -240, 2921, -158), true, kCursorZoom, 2);
	_app->objectAddRotationAccessibility(kObject17205, 17003, Common::Rect(2965, -300, 3142, -177), true, kCursorZoom, 3);
	_app->objectAddRotationAccessibility(kObject17205, 17004, Common::Rect(2990, -347, 3264, -223), true, kCursorZoom, 1);
	_app->objectAddRotationAccessibility(kObject17205, 17004, Common::Rect(3341, -336, 3550, -181), true, kCursorZoom, 2);
	_app->objectAddRotationAccessibility(kObject17205, 17004, Common::Rect(3566, -263, 3600, -144), true, kCursorZoom, 3);
	_app->objectAddPuzzleAccessibility(kObject17205, kPuzzle17062, Common::Rect(0, 420, 640, 464), true, kCursorBack, 999);
	_app->objectAddPuzzleAccessibility(kObject17205, kPuzzle17063, Common::Rect(0, 420, 640, 464), true, kCursorBack, 999);
	_app->objectAddPuzzleAccessibility(kObject17205, kPuzzle17064, Common::Rect(0, 420, 640, 464), true, kCursorBack, 999);
	_app->objectAddPuzzleAccessibility(kObject17205, kPuzzle17065, Common::Rect(0, 420, 640, 464), true, kCursorBack, 999);
	_app->objectAddPuzzleAccessibility(kObject17205, kPuzzle17066, Common::Rect(0, 420, 640, 464), true, kCursorBack, 999);
	_app->objectAdd(kObject17004, "", "", 1);
	_app->objectAddRotationAccessibility(kObject17004, 17005, Common::Rect(2097, -71, 2429, 317), true, kCursorAction, 0);
	_app->objectAddPresentation(kObject17004);
	_app->objectPresentationAddAnimationToRotation(kObject17004, 0, 17005, 1, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject17004);
	_app->objectPresentationAddImageToRotation(kObject17004, 1, 17005, 0);
	_app->objectAddPresentation(kObject17004);
	_app->objectPresentationAddAnimationToRotation(kObject17004, 2, 17005, 1, 10, 12.5f, 10);
	_app->objectAdd(kObject17005, "", "", 1);
	_app->objectAddRotationAccessibility(kObject17005, 17005, Common::Rect(2237, 144, 2343, 228), false, kCursorActionObject, 0);
	_app->objectAddPresentation(kObject17005);
	_app->objectPresentationAddAnimationToRotation(kObject17005, 0, 17005, 9, 7, 12.5f, 6);
	_app->objectAddPresentation(kObject17005);
	_app->objectPresentationAddAnimationToRotation(kObject17005, 1, 17005, 10, 7, 12.5f, 6);
	_app->objectAddPresentation(kObject17005);
	_app->objectPresentationAddImageToRotation(kObject17005, 2, 17005, 2);
	_app->objectPresentationAddImageToPuzzle(kObject17005, 2, kPuzzle17051, "a01s07n05p01l01.bmp", Common::Point(276, 17), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject17005);
	_app->objectPresentationAddImageToRotation(kObject17005, 3, 17005, 3);
	_app->objectAddPresentation(kObject17005);
	_app->objectPresentationAddAnimationToRotation(kObject17005, 4, 17005, 9, 7, 12.5f, 10);
	_app->objectAddPresentation(kObject17005);
	_app->objectPresentationAddAnimationToRotation(kObject17005, 5, 17005, 10, 7, 12.5f, 10);
	_app->objectAdd(kObject17503, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject17503, kPuzzle17051, Common::Rect(250,  24, 342, 254), true, kCursorActionObject, 0);
	_app->objectAddPuzzleAccessibility(kObject17503, kPuzzle17051, Common::Rect(  0, 420, 640, 464), true, kCursorBack, 9);
	_app->objectAddPuzzleAccessibility(kObject17503, kPuzzle17051, Common::Rect(266, 340, 303, 390), true, kCursorAction, 3);
	_app->objectAddPresentation(kObject17503);
	_app->objectPresentationAddImageToPuzzle(kObject17503, 0, kPuzzle17051, "a01s07n05p01l02.bmp", Common::Point(262, 328), true, kDrawTypeNormal, 1000);
	_app->soundAdd(17020, kSoundTypeBackgroundMusic, "0107_ambience.was", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(17020, 95);
	_app->soundAdd(17019, kSoundTypeBackgroundMusic, "0107_BGR_MUS.wac", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(17019, 85);
	_app->soundAdd(17045, kSoundTypeAmbientEffect, "0107_rat_steroidi_loop.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17044, kSoundTypeAmbientEffect, "0107_rat_se_utrudi.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17034, kSoundTypeAmbientEffect, "0107_open_skrinja.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17047, kSoundTypeAmbientEffect, "0107_rat_valj_se_vrti_loop.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundSetVolume(17047, 85);
	_app->soundAdd(17038, kSoundTypeAmbientEffect, "0107_police_up_loop.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17027, kSoundTypeAmbientEffect, "0107_han_image_nazaj_start.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17035, kSoundTypeAmbientEffect, "0107_police_down_loop.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17028, kSoundTypeAmbientEffect, "0107_han_image_vstran.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17032, kSoundTypeAmbientEffect, "0107_open_closet_1.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17033, kSoundTypeAmbientEffect, "0107_open_closet_2.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17025, kSoundTypeAmbientEffect, "0107_close_skrinja_start.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17030, kSoundTypeAmbientEffect, "0107_omarica_za_sliko_close.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17021, kSoundTypeAmbientEffect, "0107_close_closet_1.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17022, kSoundTypeAmbientEffect, "0107_close_closet_2_end.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17023, kSoundTypeAmbientEffect, "0107_close_closet_2_start.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17024, kSoundTypeAmbientEffect, "0107_close_skrinja_end.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17026, kSoundTypeAmbientEffect, "0107_han_image_nazaj_end.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17029, kSoundTypeAmbientEffect, "0107_navijanje.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17031, kSoundTypeAmbientEffect, "0107_omarica_za_sliko_open.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17036, kSoundTypeAmbientEffect, "0107_police_down_start.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17037, kSoundTypeAmbientEffect, "0107_police_up_end.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17039, kSoundTypeAmbientEffect, "0107_poster_se_obrne.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17041, kSoundTypeAmbientEffect, "0107_rat_cici_01.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17042, kSoundTypeAmbientEffect, "0107_rat_cici_02.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17043, kSoundTypeAmbientEffect, "0107_rat_cici_03.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17046, kSoundTypeAmbientEffect, "0107_rat_steroidi_start.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17048, kSoundTypeAmbientEffect, "0107_reel_put.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17049, kSoundTypeAmbientEffect, "0107_rocaj_za_tarce_put.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17050, kSoundTypeAmbientEffect, "0107_roulete_open_drawer_end.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17051, kSoundTypeAmbientEffect, "0107_roulete_open_drawer_start.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17052, kSoundTypeAmbientEffect, "0107_roulete_put.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17053, kSoundTypeAmbientEffect, "0107_roulete_rotate.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17054, kSoundTypeAmbientEffect, "0107_roulete_take.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17055, kSoundTypeAmbientEffect, "0107_tarca_dn.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17056, kSoundTypeAmbientEffect, "0107_tarca_up.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17057, kSoundTypeAmbientEffect, "0107_whip.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17058, kSoundTypeAmbientEffect, "0107_kabel_prikl.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17059, kSoundTypeAmbientEffect, "0107_kabel_pobere.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17060, kSoundTypeAmbientEffect, "0107_kabel_pade.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundSetVolume(17060, 95);
	_app->soundAdd(17061, kSoundTypeAmbientEffect, "14_Projector.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17062, kSoundTypeAmbientEffect, "0107_drapes.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(17000, kSoundTypeDialog, "E05_02_Han.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(17002, kSoundTypeDialog, "E05_03_Han.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(17003, kSoundTypeDialog, "E05_04_Han.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(17004, kSoundTypeDialog, "E05_06_Han.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(17005, kSoundTypeDialog, "E05_07_Han.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(17006, kSoundTypeDialog, "E05_08_Han.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(17007, kSoundTypeDialog, "E05_09_Han.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(17009, kSoundTypeDialog, "E05_12_Mar.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(17010, kSoundTypeDialog, "E05_13_Han.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(17013, kSoundTypeDialog, "E05_18_1Mef.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(17014, kSoundTypeDialog, "E05_18_2Mef.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(17015, kSoundTypeDialog, "E05_18_3Mef.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);

	for (uint32 i = 0; i < 11; i++) {
		_app->varDefineByte(17000 + i, 99);
		_app->varDefineDword(17000 + i, 0);
	}

	_app->varDefineByte(17011, 9);
	_app->varDefineByte(17020, 0);
	_app->varDefineByte(17021, 0);
	_app->varDefineByte(17022, 0);
	_app->varDefineByte(17023, 1);
	_app->varDefineByte(17024, 0);
	_app->varDefineByte(17025, 0);
	_app->varDefineWord(17001, 0);
	_app->varDefineWord(17002, 0);
	_app->varDefineWord(17003, 0);
	_app->varDefineWord(17004, 0);
	_app->varDefineDword(17021, 0);
	_app->varDefineDword(17022, 0);
	_app->varDefineString(17001, "99999");
	_app->varDefineByte(17800, 18);
	_app->varDefineByte(17850, 2);
	_app->varDefineByte(17801, 6);
	_app->varDefineByte(17851, 1);
	_app->varDefineByte(17802, 21);
	_app->varDefineByte(17852, 2);
	_app->varDefineByte(17803, 33);
	_app->varDefineByte(17853, 1);
	_app->varDefineByte(17804, 16);
	_app->varDefineByte(17854, 2);
	_app->varDefineByte(17805, 4);
	_app->varDefineByte(17855, 1);
	_app->varDefineByte(17806, 23);
	_app->varDefineByte(17856, 2);
	_app->varDefineByte(17807, 35);
	_app->varDefineByte(17857, 1);
	_app->varDefineByte(17808, 14);
	_app->varDefineByte(17858, 2);
	_app->varDefineByte(17809, 2);
	_app->varDefineByte(17859, 1);
	_app->varDefineByte(17810, 100);
	_app->varDefineByte(17860, 3);
	_app->varDefineByte(17811, 28);
	_app->varDefineByte(17861, 1);
	_app->varDefineByte(17812, 9);
	_app->varDefineByte(17862, 2);
	_app->varDefineByte(17813, 26);
	_app->varDefineByte(17863, 1);
	_app->varDefineByte(17814, 30);
	_app->varDefineByte(17864, 2);
	_app->varDefineByte(17815, 11);
	_app->varDefineByte(17865, 1);
	_app->varDefineByte(17816, 7);
	_app->varDefineByte(17866, 2);
	_app->varDefineByte(17817, 20);
	_app->varDefineByte(17867, 1);
	_app->varDefineByte(17818, 32);
	_app->varDefineByte(17868, 2);
	_app->varDefineByte(17819, 17);
	_app->varDefineByte(17869, 1);
	_app->varDefineByte(17820, 5);
	_app->varDefineByte(17870, 2);
	_app->varDefineByte(17821, 22);
	_app->varDefineByte(17871, 1);
	_app->varDefineByte(17822, 34);
	_app->varDefineByte(17872, 2);
	_app->varDefineByte(17823, 15);
	_app->varDefineByte(17873, 1);
	_app->varDefineByte(17824, 3);
	_app->varDefineByte(17874, 2);
	_app->varDefineByte(17825, 24);
	_app->varDefineByte(17875, 1);
	_app->varDefineByte(17826, 36);
	_app->varDefineByte(17876, 2);
	_app->varDefineByte(17827, 13);
	_app->varDefineByte(17877, 1);
	_app->varDefineByte(17828, 1);
	_app->varDefineByte(17878, 2);
	_app->varDefineByte(17829, 50);
	_app->varDefineByte(17879, 3);
	_app->varDefineByte(17830, 27);
	_app->varDefineByte(17880, 2);
	_app->varDefineByte(17831, 10);
	_app->varDefineByte(17881, 1);
	_app->varDefineByte(17832, 25);
	_app->varDefineByte(17882, 2);
	_app->varDefineByte(17833, 29);
	_app->varDefineByte(17883, 1);
	_app->varDefineByte(17834, 12);
	_app->varDefineByte(17884, 2);
	_app->varDefineByte(17835, 8);
	_app->varDefineByte(17885, 1);
	_app->varDefineByte(17836, 19);
	_app->varDefineByte(17886, 2);
	_app->varDefineByte(17837, 31);
	_app->varDefineByte(17887, 1);
	_app->varDefineByte(17900, 19);
	_app->varDefineByte(17910, -1);
	_app->varDefineByte(17901, 100);
	_app->varDefineByte(17911, -1);
	_app->varDefineByte(17902, -1);
	_app->varDefineByte(17912, 1);
	_app->varDefineByte(17903, 7);
	_app->varDefineByte(17913, -1);
	_app->varDefineByte(17904, -1);
	_app->varDefineByte(17914, 2);
	_app->varDefineByte(17920, 0);
	_app->varDefineByte(17930, 0);
	_app->varDefineByte(17921, 0);
	_app->varDefineByte(17931, 0);
	_app->varDefineByte(17922, 0);
	_app->varDefineByte(17932, 0);
	_app->varDefineByte(17923, 0);
	_app->varDefineByte(17933, 0);
	_app->varDefineByte(17924, 0);
	_app->varDefineByte(17934, 0);
	_app->varDefineByte(17940, 0);
	_app->varDefineByte(17950, 0);
	_app->varDefineByte(17027, 2);
	_app->varDefineByte(17026, 0);
	_app->varDefineByte(17042, 0);
	_app->varDefineByte(17028, 0);
	_app->varDefineByte(17029, 0);
	_app->varDefineByte(17030, 0);
	_app->varDefineByte(17031, 2);
	_app->varDefineByte(17032, 5);
	_app->varDefineByte(17033, 4);
	_app->varDefineByte(17034, 3);
	_app->varDefineByte(17035, 1);
	_app->varDefineByte(17041, 0);
	_app->varDefineByte(17036, 1);
	_app->varDefineByte(17037, 1);
	_app->varDefineByte(17038, 1);
	_app->varDefineByte(17039, 10);
	_app->varDefineByte(17040, 1);
	_app->varDefineByte(17043, 0);
	_app->varDefineByte(17012, 0);
	_app->varDefineByte(17013, 0);
	_app->varDefineByte(17014, 0);
	_app->varDefineByte(17015, 0);
	_app->varDefineByte(17016, 0);
	_app->varDefineByte(17017, 0);
	_app->varDefineByte(17101, 0);
	_app->varDefineByte(17102, 0);
}

// FAUST.EXE 0x4abb80: episode 5 setup (A12 = zone 15, A13 = zone 16)
void Zone5Faust::onSetup(SetupType type) {
	switch (type) {
	default:
		break;

	case kSetupType1:
		_app->timerStopAll();
		_app->bagRemoveAll();
		_app->setSpace(kZone15);
		_app->playMovie("A12S01_E04M01");
		_app->fadeOut(15, Color(0, 0, 0), 0);
		_app->playMovie("A12S01_E04M13");
		_app->rotationSetAlp(120101, 90.0f);
		_app->rotationSetBet(120101, 0.0f);
		_app->rotationSetRan(120101, 87.0f);
		_app->rotationSetActive(120101);
		_app->bagAdd(13899);
		_app->bagAdd(120036);
		_app->bagAdd(97001);
		_app->timerStart(kTimer4, 1000);
		_app->timerStart(kTimer5, 5000);
		_app->objectPresentationShow(kObject25, 5);
		break;

	case kSetupType2:
		// FAUST.EXE 0x4abba4 goes through setupZone (0x4736a0), which also checks the CD
		_app->setupZone(kZone5, kSetupType3);
		break;

	case kSetupType3:
		_app->timerStopAll();
		_app->bagAdd(13899);
		_app->bagAdd(13129);
		_app->bagAdd(97001);

		// FAUST.EXE 0x4abcb4 sets the progress animation frame (0x4dc040), it doesn't save
		if (_app->getSaveManager()->getData()->progressState == kProgressState4)
			_app->getSaveManager()->getData()->progress = 35;

		_app->setSpace(kZone16);
		_app->displayFade("a13_black.bmp", "A13S01N01R01_2.bmp", 12, 0, kLoadFromCd, kArchiveArt);
		_app->rotationSetAlp(311111, 90.0f);
		_app->rotationSetBet(311111, 26.0f);
		_app->rotationSetRan(311111, 87.0f);
		_app->rotationSetActive(311111);
		_app->soundPlay(310105, kSoundLoop);
		break;

	case kSetupType99:
		_app->timerStopAll();
		_app->bagRemoveAll();
		_app->setSpace(kZone15);
		_app->puzzleSetActive(kPuzzle120009);
		break;

	case kSetupType30000:
		switch (_app->getChapterIndex()) {
		default:
			break;

		case 13:
			_app->setCurrentZone(kZone15);
			_app->playMovie("A12S01_E04M01");
			break;

		case 14:
			_app->setCurrentZone(kZone15);
			_app->playMovie("A12S01_E04M02");
			break;

		case 15:
			_app->setCurrentZone(kZone15);
			_app->playMovie("A12S07_E04M05");
			break;

		case 16:
			_app->setCurrentZone(kZone15);
			_app->playMovie("A12S01_E04M10");
			break;

		case 17:
			_app->setCurrentZone(kZone16);
			_app->playMovie("A13S02_E04M12");
			break;
		}

		_app->setCurrentZone(kZoneSY);
		_app->soundPlay(90001, kSoundLoop);
		_app->puzzleSetActive(kPuzzleGeneralMenu);
		break;
	}
}

void Zone5Faust::onTimer(TimerId id) {
	switch (id) {
	default:
		break;

	case kTimer0:
		_app->timerStop(kTimer0);
		_app->soundStop(17047, 1024);
		_app->soundPlay(17044);
		_app->objectPresentationHide(kObject17401);

		if (_app->varGetByte(17027) == 1) {
			_app->objectPresentationHide(kObject17505);
			_app->objectPresentationShow(kObject17505);
		}
		break;

	case kTimer2:
		_app->timerStop(kTimer2);
		_app->puzzleSetActive(kPuzzle17022);
		break;

	case kTimer3:
		if (_app->varGetByte(17030) == 5) {
			_app->varSetByte(17030, 0);
			_app->timerStop(kTimer3);

			if (_app->varGetByte(17041) == 4) {
				_app->varSetByte(17102, 1);

				if ((_app->varGetByte(17101) + _app->varGetByte(17102)) >= 2) {
					_app->playMovie("A01S07_E05M05");
					_app->fadeOut(15, Color(0, 0, 0), 0);

					if (_app->getSaveManager()->getData()->progressState == 5)
						_app->getSaveManager()->getData()->progress++;

					_app->setupRotation(2);
				}
			}

			_app->objectSetAccessibilityOn(kObjectHandle, 2, 2);

		} else {
			_app->varSetByte(17030, _app->varGetByte(17030) + 1);

			uint32 index = _app->varGetByte(_app->varGetByte(17030) + 17030) + 1;
			_app->objectPresentationSetAnimationOnPuzzle(kObjectHandle, index, 0, 17006);
			_app->objectPresentationShow(kObjectHandle, index);
			_app->soundPlay(17056);
		}
		break;

	case kTimer4: {
		_app->timerStop(kTimer4);
		_app->objectSetAccessibilityOff(17301, 1, 5);

		uint32 index = _app->varGetByte(_app->varGetByte(17030) + 17030);
		_app->objectPresentationUnpauseAnimation(17303, index + 1);
		_app->objectPresentationShow(kObjectHandle, index + 6);
		_app->objectPresentationHide(kObjectHandle, index + 1);
		_app->soundPlay(17055);
		}
		break;

	case kTimer5:
		if (rnd(2) == 0)
			_app->soundPlay(17041 + rnd(3));
		break;

	case kTimer6:
		_app->timerStop(kTimer6);
		_app->soundStop(17047, 1024);
		_app->soundPlay(17044);
		_app->objectPresentationHide(kObject17401);

		if (_app->varGetByte(17027) == 1) {
			_app->objectPresentationHide(kObject17505);
			_app->objectPresentationShow(kObject17505);
		}

		_app->varSetByte(17042, 1);
		break;

	case kTimer7:
		_app->timerStop(kTimer7);
		_app->timerStart(kTimer7, rnd(5000) + 8000);
		_app->soundPlay(17020);
		break;

	case kTimer8:
		_app->timerStop(kTimer8);
		_app->soundStop(17047, 1024);
		_app->objectPresentationHide(kObject17401);

		if (_app->varGetByte(17027) == 1) {
			_app->objectPresentationHide(kObject17505);
			_app->objectPresentationShow(kObject17505);
		}
		break;
	}
}

// FAUST.EXE 0x468980
void Zone5Faust::addToByte(Id id, int8 value) {
	_app->varSetByte(id, _app->varGetByte(id) + value);
}

// FAUST.EXE 0x4689b0: remember the view before a close-up
void Zone5Faust::saveView() {
	Id rotationId = _app->getCurrentRotationId();

	_app->varSetWord(17001, (int16)rotationId);
	_app->varSetWord(17002, (int16)_app->rotationGetAlp(rotationId));
	_app->varSetWord(17003, (int16)_app->rotationGetBet(rotationId));
	_app->varSetWord(17004, (int16)_app->rotationGetRan(rotationId));
}

// FAUST.EXE 0x468a40: back to the view saved by saveView()
void Zone5Faust::restoreView() {
	Id rotationId = _app->varGetWord(17001);

	_app->rotationSetActive(rotationId);
	_app->rotationSetAlp(rotationId, (float)_app->varGetWord(17002));
	_app->rotationSetBet(rotationId, (float)_app->varGetWord(17003));
	_app->rotationSetRan(rotationId, (float)_app->varGetWord(17004));
}

// Close the drawer 17003 (inlined in onButtonUp; the exe uses lower- or upper-case movie names)
void Zone5Faust::closeCupboard(bool upperCase) {
	_app->soundPlay(17038, kSoundLoop);

	if (_app->varGetByte(17021) == 0)
		_app->playMovie(upperCase ? "A01S07N01A03r" : "a01s07n01a03r");
	else
		_app->playMovie(upperCase ? "A01S07N01A04r" : "a01s07n01a04r");

	_app->soundStop(17038, 1024);
	_app->soundPlay(17037);
	_app->objectPresentationHide(kObject17003);
	_app->varSetByte(17014, 0);
	_app->objectSetAccessibilityOff(kObject17029);
	_app->objectSetAccessibilityOff(kObjectKey);
}

// Close door 17001 / 17002 (inlined in onButtonUp)
void Zone5Faust::closeDoor(ObjectId id, uint32 door, bool upperCase) {
	_app->soundPlay(17023);

	if (door == 0)
		_app->playMovie(upperCase ? "A01S07N01A01r" : "a01s07n01a01r");
	else
		_app->playMovie(upperCase ? "A01S07N01A02r" : "a01s07n01a02r");

	_app->soundPlay(17022);
	_app->objectPresentationHide(id, 0);
	_app->varSetByte(17012 + door, 0);
	_app->objectSetAccessibilityOn(id, 0, 0);
	_app->objectSetAccessibilityOff(id, 1, 2);
}

void Zone5Faust::onButtonUp(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, const Common::Point &point) {
	switch (id) {
	default:
		break;

	case kObject18:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		// Leave the tent
		_app->setupZone(kZone6, kSetupType12);
		break;

	case kObject17001:
	case kObject17002: {
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		uint32 door = (id == kObject17001) ? 0 : 1;

		if (target == 0) {
			// Open a door, closing whatever else is open first
			if (_app->varGetByte(17014) == 1)
				closeCupboard(false);

			if (_app->varGetByte(17012) == 1)
				closeDoor(kObject17001, 0, false);

			if (_app->varGetByte(17013) == 1) {
				closeDoor(kObject17002, 1, false);
				_app->objectSetAccessibilityOff(kObject17022, 0, 2);

				if (_app->varGetByte(17027) == 1) {
					_app->objectPresentationHide(kObject17505);
					_app->objectPresentationShow(kObject17505);
				}

				if (_app->varGetByte(17020) != 2) {
					_app->objectPresentationHide(kObjectRat);
					_app->objectPresentationShow(kObjectRat);
				} else {
					_app->objectSetAccessibilityOn(kObjectRat);
				}
			}

			if (door == 0) {
				_app->objectSetAccessibilityOff(kObjectRat);
				_app->soundPlay(17033);
				_app->playMovie("a01s07n01a01");
			} else {
				_app->soundPlay(17032);
				_app->playMovie("a01s07n01a02");
			}

			_app->objectPresentationShow(id, 0);
			_app->objectSetAccessibilityOff(id, 0, 0);
			_app->objectSetAccessibilityOn(id, 1, 2);
			_app->varSetByte(17012 + door, 1);

			if (id == kObject17002) {
				_app->objectSetAccessibilityOn(kObject17022, 0, 2);
				_app->objectPresentationHide(kObject17401);
			}
		} else if (target == 1) {
			// Close it
			if (_app->varGetByte(17014) == 1)
				closeCupboard(true);

			closeDoor(id, door, true);
			_app->objectSetAccessibilityOff(kObject17022, 0, 2);

			if (_app->varGetByte(17020) != 2) {
				_app->objectPresentationHide(kObjectRat);
				_app->objectPresentationShow(kObjectRat);
			} else {
				_app->objectSetAccessibilityOn(kObjectRat);
			}
		}
		}
		break;

	case kObject17004:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->soundPlay(17028);
			_app->objectPresentationShow(kObject17004, 0);
			_app->objectPresentationSetAnimationOnRotation(kObject17004, 0, 0, 17010);
			_app->varSetByte(17016, 1);
			_app->objectSetAccessibilityOff(kObject17004);
			_app->objectSetAccessibilityOn(kObject17005);
		}
		break;

	case kObject17005:
		if (!_app->bagHasClickedObject())
			break;

		if (target == 0 && _app->bagGetClickedObject() == kObjectKey) {
			_app->soundPlay(17031);
			_app->varSetByte(17016, 2);

			if (_app->varGetByte(17026) == 0) {
				_app->objectPresentationShow(kObject17005, 0);
				_app->objectPresentationSetAnimationOnRotation(kObject17005, 0, 0, 17011);
			} else {
				_app->objectPresentationShow(kObject17005, 1);
				_app->objectPresentationSetAnimationOnRotation(kObject17005, 1, 0, 17012);
			}

			_app->bagRemove(kObjectKey);
			_app->objectSetAccessibilityOff(kObject17005);
		}

		_app->cursorDelete();
		break;

	case kObject17006:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->soundPlay(17034);
			_app->playMovie("A01S07N03A01");

			if (_app->varGetByte(17029) == 0) {
				_app->objectPresentationShow(kObject17006, 0);
				_app->objectSetAccessibilityOn(kObjectHandle, 0, 0);
			} else {
				_app->objectPresentationShow(kObject17006, 1);
			}

			_app->objectSetAccessibilityOff(kObject17006, 0, 0);
			_app->objectSetAccessibilityOn(kObject17006, 1, 1);
			_app->varSetByte(17015, 1);
		} else {
			_app->soundPlay(17025);
			_app->playMovie("A01S07N03A01R");
			_app->soundPlay(17024);
			_app->objectPresentationHide(kObject17006);
			_app->objectSetAccessibilityOff(kObjectHandle, 0, 0);
			_app->objectSetAccessibilityOn(kObject17006, 0, 0);
			_app->objectSetAccessibilityOff(kObject17006, 1, 1);
			_app->varSetByte(17015, 0);
		}
		break;

	case kObjectRat:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->objectPresentationShow(kObjectRat);
			_app->bagAdd(kObjectRat);
			_app->varSetByte(17020, 3);
			_app->objectSetAccessibilityOff(kObjectRat);
			_app->soundPlay(17009);
			_app->timerStop(kTimer5);
		}
		break;

	case kObject17022: {
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		// Code buttons: the string var keeps the last five digits
		_app->objectPresentationHide(kObject17022, target);
		_app->objectPresentationHide(kObject17002, 0);
		_app->objectPresentationShow(kObject17002, 0);
		_app->soundPlay(17053);

		Common::String code = Common::String::format("%s%d", _app->varGetString(17001).c_str() + 1, target);
		_app->varSetString(17001, code);

		if (code != "20122")
			break;

		_app->objectSetAccessibilityOff(kObject17022, 0, 2);
		_app->objectSetAccessibilityOn(kObject17029);
		_app->soundPlay(17036);
		_app->soundPlay(17035, kSoundLoop);

		if (_app->varGetByte(17021) == 0) {
			_app->playMovie("A01S07N01A03");
			_app->objectSetAccessibilityOn(kObjectKey);
		} else {
			_app->playMovie("A01S07N01A04");
		}

		_app->objectPresentationShow(kObject17003, 0);
		if (_app->varGetByte(17021) > 0)
			_app->objectPresentationShow(kObject17003, 1);

		if (_app->varGetByte(17020) == 0)
			_app->objectSetAccessibilityOn(kObject17029);

		_app->varSetByte(17014, 1);
		_app->soundStop(17035, 1024);
		}
		break;

	case kObject17029:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->playMovie("A01S07_E05M04");

		if (_app->varGetByte(17020) != 0)
			break;

		_app->objectPresentationHide(kObjectRat);
		_app->objectPresentationHide(kObject17002, 0);
		_app->objectPresentationHide(kObject17003);
		_app->objectPresentationShow(kObject17002, 0);
		_app->objectPresentationShow(kObject17003, 0);
		if (_app->varGetByte(17021) > 0)
			_app->objectPresentationShow(kObject17003, 1);

		_app->varSetByte(17020, 2);
		_app->objectSetAccessibilityOff(kObject17029);
		_app->timerStart(kTimer5, 1000);
		break;

	case kObjectKey:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->objectPresentationShow(kObject17003, 1);
		_app->bagAdd(kObjectKey);
		_app->soundPlay(17054);
		_app->objectSetAccessibilityOff(kObjectKey);
		_app->varSetByte(17021, 1);
		break;

	case kObjectCylinder:
		if (_app->bagHasClickedObject()) {
			if (target == 1 && _app->bagGetClickedObject() == kObjectCylinder) {
				_app->bagRemove(kObjectCylinder);
				_app->objectPresentationShow(kObjectCylinder, 1);
				_app->objectSetAccessibilityOff(kObjectCylinder, 1, 3);
				_app->objectSetAccessibilityOn(kObjectCylinder, 4, 6);
				_app->soundPlay(17052);
			}

			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 0:
			if (_app->bagHas(kObjectCylinder))
				break;

			_app->objectPresentationShow(kObjectCylinder, 0);
			_app->objectSetAccessibilityOff(kObjectCylinder, 0, 0);
			_app->bagAdd(kObjectCylinder);
			_app->soundPlay(17054);
			break;

		case 1:
			_app->soundPlay(17000);
			break;

		case 2:
			saveView();
			_app->objectPresentationShow(kObject17201, _app->varGetByte(17023));
			_app->puzzleSetActive(kPuzzle17021);
			break;

		case 3: {
			// Crank the cylinder: on odd positions, shift one more note into the tune
			int32 matches = target;
			int8 position = _app->varGetByte(17023);

			if (((position + 1) % 2) == 0) {
				for (uint32 i = 0; i < 4; i++) {
					_app->varSetByte(17920 + i, _app->varGetByte(17921 + i));
					_app->varSetByte(17930 + i, _app->varGetByte(17931 + i));
				}

				_app->varSetByte(17924, _app->varGetByte(17837 - position / 2));
				_app->varSetByte(17934, _app->varGetByte(17887 - position / 2));

				matches = 0;
				for (uint32 i = 0; i < 5; i++) {
					bool match;
					if (_app->varGetByte(17900 + i) > -1)
						match = (_app->varGetByte(17900 + i) == _app->varGetByte(17920 + i));
					else
						match = (_app->varGetByte(17910 + i) == _app->varGetByte(17930 + i));

					matches = match ? matches + 1 : 0;
				}
			}

			_app->objectPresentationShow(kObjectCylinder, 2);
			_app->soundPlay(17053);
			_app->_vm->update();
			_app->_vm->update();
			_app->_vm->update();
			_app->objectPresentationHide(kObjectCylinder, 2);

			if (matches != 5)
				break;

			// Sets the progress animation frame (0x4dc040), it doesn't save
			if (_app->getSaveManager()->getData()->progressState == kProgressState5)
				_app->getSaveManager()->getData()->progress++;

			_app->objectPresentationShow(kObject17203, 0);
			_app->soundPlay(17051);
			_app->objectSetAccessibilityOff(kObjectCylinder, 7, 7);
			_app->rotationSetMovabilityOn(17003, 4, 4);
			}
			break;

		case 9:
			restoreView();
			break;
		}
		break;

	case kObject17204:
		if (_app->bagHasClickedObject())
			_app->cursorDelete();

		_app->playMovie("A01S07N02A01");
		_app->objectPresentationShow(kObject17204, 0);
		_app->soundPlay(17002);
		_app->rotationSetMovabilityOff(17002);
		_app->objectSetAccessibilityOn(kObject18, 1, 1);
		break;

	case kObject17205:
		if (_app->bagHasClickedObject())
			_app->cursorDelete();

		if (target == 999) {
			_app->rotationSetActive(_app->varGetDword(90025));
			break;
		}

		_app->varSetDword(90025, _app->getCurrentRotationId());
		_app->puzzleSetActive((PuzzleId)(target + 17061));
		_app->soundPlay(17004 + (target > 3 ? 0 : target));
		break;

	case kObjectWhip:
		if (_app->bagHasClickedObject()) {
			if (_app->bagGetClickedObject() != kObjectWhip) {
				_app->cursorDelete();
				break;
			}

			if (target <= 9)
				break;

			addToByte(17041, _app->varGetByte(17026 + target));
			_app->soundPlay(17057);
			break;
		}

		if (target == 0) {
			_app->objectPresentationShow(kObjectWhip, 0);
			_app->bagAdd(kObjectWhip);
			_app->soundPlay(17054);
			_app->objectSetAccessibilityOff(kObjectWhip, 0, 0);
			_app->varSetByte(98012, 5);
		}
		break;

	case kObjectReel:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->objectPresentationShow(kObjectReel, 0);
			_app->bagAdd(kObjectReel);
			_app->soundPlay(17054);
			_app->objectSetAccessibilityOff(kObjectReel);
		}
		break;

	case kObjectHandle:
		if (_app->bagHasClickedObject()) {
			if (target == 1 && _app->bagGetClickedObject() == kObjectHandle) {
				_app->soundPlay(17049);
				_app->bagRemove(kObjectHandle);
				_app->objectPresentationHide(kObjectHandle, 13);
				_app->objectPresentationShow(kObjectHandle, 12);
				_app->varSetByte(17030, 0);
				_app->timerStart(kTimer2, 500);
				_app->objectSetAccessibilityOff(kObjectHandle, 1, 1);
				_app->objectSetAccessibilityOn(kObjectHandle, 3, 3);
			}

			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 0:
			_app->varSetByte(17006, 3);
			_app->varSetByte(17029, 3);
			_app->objectPresentationHide(kObject17006, 0);
			_app->objectPresentationShow(kObject17006, 1);
			_app->bagAdd(kObjectHandle);
			_app->objectSetAccessibilityOff(kObjectHandle, 0, 0);
			_app->soundPlay(17054);
			break;

		case 2:
			addToByte(17030, 1);
			_app->objectSetAccessibilityOff(kObjectHandle, 2, 2);
			_app->objectPresentationSetAnimationOnPuzzle(kObjectHandle, 1, 0, 17005);
			_app->objectPresentationShow(kObjectHandle, 1);
			_app->soundPlay(17029);
			break;

		case 3:
			_app->varSetByte(17030, 0);
			_app->timerStart(kTimer2, 500);
			break;
		}
		break;

	case kObject17304:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->displayFade("a01s07n03m0100.bmp", "a01s07n03m0100.bmp", 5, 0, kLoadFromCd, kArchiveArt);
		_app->soundPlay(17010);
		_app->displayFade("a01s07n03m0100.bmp", "a01s07n03m0102.bmp", 18, 0, kLoadFromCd, kArchiveArt);
		_app->displayFade("a01s07n03m0102.bmp", "a01s07n03m0100.bmp", 18, 0, kLoadFromCd, kArchiveArt);
		_app->displayFade("a01s07n03m0100.bmp", "a01s07n03m0104.bmp", 18, 0, kLoadFromCd, kArchiveArt);
		_app->displayFade("a01s07n03m0104.bmp", "a01s07n03m0100.bmp", 18, 0, kLoadFromCd, kArchiveArt);
		_app->displayFade("a01s07n03m0100.bmp", "a01s07n03m0103.bmp", 18, 0, kLoadFromCd, kArchiveArt);
		_app->displayFade("a01s07n03m0103.bmp", "a01s07n03m0100.bmp", 18, 0, kLoadFromCd, kArchiveArt);
		_app->displayFade("a01s07n03m0100.bmp", "a01s07n03m0101.bmp", 18, 0, kLoadFromCd, kArchiveArt);
		_app->displayFade("a01s07n03m0101.bmp", "a01s07n03m0100.bmp", 18, 0, kLoadFromCd, kArchiveArt);
		break;

	case kObject17401:
		if (_app->bagHasClickedObject()) {
			if (target == 0 && _app->bagGetClickedObject() == kObjectRat) {
				_app->bagRemove(kObjectRat);
				_app->varSetByte(17028, 1);
				_app->objectSetAccessibilityOff(kObject17401, 0, 0);
				_app->soundPlay(17043);
				_app->objectPresentationShow(kObject17401, 0);
				_app->objectPresentationShow(kObject17401, _app->varGetByte(17027) ? 2 : 1);
				_app->soundPlay(17047, kSoundLoop);
				_app->timerStart(kTimer0, 2000);
				_app->timerStart(kTimer5, 1000);
			} else if (_app->bagGetClickedObject() == kObjectWhip) {
				_app->soundPlay(17057);

				if (_app->varGetByte(17028) > 0) {
					_app->objectPresentationShow(kObject17401, 0);
					_app->objectPresentationShow(kObject17401, _app->varGetByte(17027) ? 2 : 1);
					_app->soundPlay(17047, kSoundLoop);
					_app->timerStart(kTimer6, 10000);
				}
			}

			_app->cursorDelete();
			break;
		}

		if (_app->varGetByte(17028) == 1) {
			_app->soundPlay(17043);
			_app->objectPresentationShow(kObject17401, 0);
			_app->objectPresentationShow(kObject17401, _app->varGetByte(17027) ? 2 : 1);
			_app->soundPlay(17047, kSoundLoop);
			_app->timerStart(kTimer0, 2000);
		} else {
			_app->objectPresentationShow(kObject17401, 0);
			_app->soundPlay(17047, kSoundLoop);
			_app->timerStart(kTimer8, 500);
		}
		break;

	case kObject17402:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->soundPlay(17003);
		break;

	case kObject17403:
		if (_app->bagHasClickedObject())
			_app->cursorDelete();

		_app->playMovie("A01S07_E05M02");
		break;

	case kObject17503:
		if (_app->bagHasClickedObject()) {
			if (target == 0 && _app->bagGetClickedObject() == kObjectReel) {
				_app->soundPlay(17048);
				_app->objectPresentationHide(kObject17005, 2);
				_app->objectPresentationShow(kObject17005, 3);
				_app->objectSetAccessibilityOff(kObject17503, 0, 0);
				_app->varSetByte(17026, 3);
				_app->bagRemove(kObjectReel);
			}

			_app->cursorDelete();
			break;
		}

		if (target == 3) {
			_app->objectPresentationShow(kObject17503);
			_app->soundPlay(17052);
			for (uint32 i = 0; i < 10; i++)
				_app->_vm->update();

			if (_app->varGetByte(17042) > 0 && _app->varGetByte(17027) > 0 && _app->varGetByte(17026) > 0) {
				// Sets the progress animation frame (0x4dc040), it doesn't save
				if (_app->getSaveManager()->getData()->progressState == kProgressState5)
					_app->getSaveManager()->getData()->progress++;

				_app->soundPlay(17061, kSoundLoop);
				_app->playMovie("A01S07_E05M03");
				_app->soundStop(17061, 1024);
				_app->varSetByte(17042, 0);
				_app->varSetByte(17101, 1);

				if ((_app->varGetByte(17102) + _app->varGetByte(17101)) >= 2) {
					_app->fadeOut(15, Color(0, 0, 0), 0);
					_app->setupRotation(2);
				}
			}

			_app->objectPresentationHide(kObject17503);
		} else if (target == 9) {
			_app->rotationSetActive(17005);
			_app->objectPresentationHide(kObject17005);
			_app->objectPresentationHide(kObject17004);
			_app->soundPlay(17030);

			if (_app->varGetByte(17026) == 0) {
				_app->objectPresentationShow(kObject17005, 4);
				_app->objectPresentationSetAnimationOnRotation(kObject17005, 4, 0, 17013);
			} else {
				_app->objectPresentationShow(kObject17005, 5);
				_app->objectPresentationSetAnimationOnRotation(kObject17005, 5, 0, 17013);
			}

			_app->bagAdd(kObjectKey);
		}
		break;

	case kObject17504:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			saveView();
			_app->puzzleSetActive(kPuzzle17042);
		} else if (target == 1) {
			restoreView();
		}
		break;
	}
}

void Zone5Faust::onButtonDown(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, const Common::Point &point) {
	if (id == kObject17022) {
		if (_app->bagHasClickedObject())
			_app->cursorDelete();
		else
			_app->objectPresentationShow(kObject17022, target);
	}
}

void Zone5Faust::onAnimationNextFrame(Id animationId, const Common::String &name, uint32 frame, uint32 frameCount) {
	switch (animationId) {
	default:
		break;

	case 17005:
		if (frame != frameCount)
			break;

		_app->objectSetAccessibilityOn(kObjectHandle, 2, 2);

		if (_app->varGetByte(17030) == 1) {
			_app->objectSetAccessibilityOff(kObjectHandle, 2, 2);
			_app->varSetByte(17030, 0);
			_app->timerStart(kTimer3, 4000);
			_app->varSetByte(17041, 0);
		}
		break;

	case 17006:
		if (frame == frameCount) {
			int8 index = _app->varGetByte(17030 + _app->varGetByte(17030));

			_app->objectPresentationPauseAnimation(kObjectHandle, index + 1);
			_app->timerStart(kTimer4, 2000);
			_app->objectSetAccessibilityOn(kObjectWhip, index, index);
		}
		break;

	case 17008:
		if (frame == frameCount)
			_app->soundPlay(17050);
		break;

	case 17010:
		if (frame == frameCount) {
			_app->objectPresentationHide(kObject17004, 0);
			_app->objectPresentationShow(kObject17004, 1);
		}
		break;

	case 17011:
	case 17012:
		if (frame != frameCount)
			break;

		_app->objectPresentationHide(kObject17005, animationId == 17011 ? 0 : 1);
		_app->objectPresentationShow(kObject17005, animationId == 17011 ? 2 : 3);
		_app->puzzleSetActive(kPuzzle17051);
		break;

	case 17013:
		if (frame == 1) {
			_app->soundPlay(17027);
			_app->objectPresentationSetAnimationOnRotation(kObject17004, 2, 0, 17014);
			_app->objectPresentationHide(kObject17005);
			_app->objectPresentationShow(kObject17004, 2);
			_app->objectSetAccessibilityOn(kObject17004);
		}
		break;

	case 17014:
		if (frame == 1) {
			_app->soundStop(17027, 1024);
			_app->soundPlay(17026);
		}
		break;
	}
}

void Zone5Faust::onSound(Id id, SoundType type, uint32 a3, bool process) {
	if (!process)
		return;

	if (id == 17002) {
		_app->playMovie("A01S07N02A01R");
		_app->objectPresentationHide(kObject17204, 0);
		_app->rotationSetMovabilityOn(17002);
		_app->objectSetAccessibilityOff(kObject18, 1, 1);
	}
}

void Zone5Faust::onBag(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, DragControl *dragControl, byte type) {
	switch (id) {
	default:
		break;

	case kObject17201:
		// Music cylinder: drag horizontally to turn it (76 positions)
		switch (type) {
		default:
			break;

		case 1:
			_dragValue = _app->varGetByte(17023);
			break;

		case 2:
			_app->varSetByte(17023, (int8)_dragValue);
			break;

		case 3: {
			if (_app->dragControlXEqual())
				break;

			int32 offset = (int32)_app->dragControlGetOffsetX0() / 20;
			if (offset != _dragPrevious) {
				if (_app->dragControlXLower0())
					_dragValue = _app->varGetByte(17023) - offset;
				else if (_app->dragControlXHigher0())
					_dragValue = _app->varGetByte(17023) + offset;

				if (_app->dragControlXLower())
					_app->varSetByte(17024, 0);
				else if (_app->dragControlXHigher())
					_app->varSetByte(17024, 1);

				_dragValue = ((_dragValue % 76) + 76) % 76;

				_app->objectPresentationHideAndRemove(kObject17201);
				_app->objectPresentationShow(kObject17201, _dragValue);
			}

			_dragPrevious = offset;
			}
			break;
		}
		break;

	case kObject17506:
		// Pull down the lever: past frame 11 it snaps to the end, otherwise it springs back
		switch (type) {
		default:
			break;

		case 1:
			_app->dragControlSetField45(2);
			_app->dragControlSetHotspot(Common::Rect(50, 60, 300, 380));
			_app->soundPlay(17059);
			_dragValue = 1;
			_app->objectPresentationHide(kObject17506);
			_app->objectPresentationShow(kObject17506, _dragValue);
			break;

		case 2:
			if (_dragValue > 11) {
				for (++_dragValue; _dragValue <= 14; ++_dragValue) {
					_app->objectPresentationHide(kObject17506);
					_app->objectPresentationShow(kObject17506, _dragValue);
					_app->_vm->update();
				}

				_app->soundPlay(17058);
				_app->objectSetAccessibilityOff(kObject17506);
				_app->objectPresentationShow(kObject17505);
				_app->varSetByte(17027, 1);
			} else {
				for (--_dragValue; _dragValue >= 0; --_dragValue) {
					_app->objectPresentationHide(kObject17506);
					_app->objectPresentationShow(kObject17506, _dragValue);
					_app->_vm->update();
				}

				_app->soundPlay(17060);
			}
			break;

		case 3:
			if (_app->dragControlXEqual() || !_app->dragControlYLower0())
				break;

			_dragValue = CLIP<int32>((int32)_app->dragControlGetOffsetY0() / 16, 0, 14);
			_app->objectPresentationHide(kObject17506);
			_app->objectPresentationShow(kObject17506, _dragValue);
			break;
		}
		break;
	}
}

// FAUST.EXE 0x46a800
void Zone5Faust::onBeforeRide(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, MovabilityType movabilityType) {
	switch (movabilityType) {
	default:
		break;

	case kMovabilityRotationToRotation:
		// Close everything that is open before walking away
		if (_app->varGetByte(17016) > 0) {
			_app->objectPresentationHide(kObject17005);
			_app->objectPresentationHide(kObject17004);
			_app->soundPlay(17026);
			_app->objectSetAccessibilityOff(kObject17005);
			_app->objectSetAccessibilityOn(kObject17004);

			if (_app->varGetByte(17016) > 1)
				_app->bagAdd(kObjectKey);

			_app->varSetByte(17016, 0);
		}

		if (_app->varGetByte(17014) > 0) {
			_app->soundPlay(17037);
			_app->objectPresentationHide(kObject17003);
			_app->objectSetAccessibilityOff(kObject17029);
			_app->objectSetAccessibilityOff(kObjectKey);
			_app->varSetByte(17014, 0);
			_app->_vm->update();
		}

		if (_app->varGetByte(17012) > 0) {
			_app->soundPlay(17022);
			_app->objectPresentationHide(kObject17001, 0);
			_app->objectSetAccessibilityOn(kObject17001, 0, 0);
			_app->objectSetAccessibilityOff(kObject17001, 1, 2);
			_app->varSetByte(17012, 0);
			_app->_vm->update();
		}

		if (_app->varGetByte(17013) > 0) {
			_app->soundPlay(17022);
			_app->objectPresentationHide(kObject17002, 0);
			_app->objectSetAccessibilityOn(kObject17002, 0, 0);
			_app->objectSetAccessibilityOff(kObject17002, 1, 2);
			_app->objectSetAccessibilityOff(kObject17022, 0, 2);

			if (_app->varGetByte(17020) != 2) {
				_app->objectPresentationHide(kObjectRat);
				_app->objectPresentationShow(kObjectRat);
			} else {
				_app->objectSetAccessibilityOn(kObjectRat);
			}

			_app->varSetByte(17013, 0);
			_app->_vm->update();
		}

		if (_app->varGetByte(17015) > 0) {
			_app->soundPlay(17024);
			_app->objectPresentationHide(kObject17006);
			_app->objectSetAccessibilityOff(kObjectHandle, 0, 0);
			_app->objectSetAccessibilityOn(kObject17006, 0, 0);
			_app->objectSetAccessibilityOff(kObject17006, 1, 1);
			_app->varSetByte(17015, 0);
			_app->_vm->update();
		}
		break;

	case kMovabilityPuzzleToRotation:
		if (movabilityFrom != kPuzzle17022 || movabilityTo != 17002)
			break;

		// Leaving the whip puzzle resets it
		_app->varSetByte(17030, 0);
		_app->timerStop(kTimer3);
		_app->timerStop(kTimer4);
		_app->objectPresentationHide(kObjectHandle);
		_app->objectSetAccessibilityOff(kObjectWhip, 1, 5);
		_app->objectSetAccessibilityOn(kObjectHandle, 2, 2);

		for (uint32 i = 0; i < 12; i++)
			_app->objectPresentationUnpauseAnimation(kObjectHandle, i);
		break;
	}
}

} // End of namespace Ring
