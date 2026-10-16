/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 12
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 012110-1301, USA.
 */

#include "ring/game/faust/faust_zone12.h"

#include "ring/game/faust/faust_application.h"
#include "ring/game/faust/faust_shared.h"

#include "ring/base/saveload.h"

#include "ring/debug.h"
#include "ring/ring.h"
#include "ring/helpers.h"

using namespace FaustGame;

namespace Ring {

Zone12Faust::Zone12Faust(ApplicationFaust *application) : _app(application) {
}

Zone12Faust::~Zone12Faust() {
	// Zero-out passed pointers
	_app = nullptr;
}

void Zone12Faust::onInit() {
	_app->setCurrentZone(kZone12);

	_app->puzzleAdd(kPuzzle81201);
	_app->puzzleAddBackgroundImage(kPuzzle81201, "a08s02n02p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81401);
	_app->puzzleAddBackgroundImage(kPuzzle81401, "a08s04n01p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81402);
	_app->puzzleAddBackgroundImage(kPuzzle81402, "a08s04n02p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81202);
	_app->puzzleAddBackgroundImage(kPuzzle81202, "a08s02n03p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81205);
	_app->puzzleAddBackgroundImage(kPuzzle81205, "a08s02n05p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81206);
	_app->puzzleAddBackgroundImage(kPuzzle81206, "a08s02n05p02s01.0001.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81207);
	_app->puzzleAddBackgroundImage(kPuzzle81207, "a08s02n05p02s01.0002.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81208);
	_app->puzzleAddBackgroundImage(kPuzzle81208, "a08s02n05p02s01.0003.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81209);
	_app->puzzleAddBackgroundImage(kPuzzle81209, "a08s02n05p02s01.0004.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81210);
	_app->puzzleAddBackgroundImage(kPuzzle81210, "a08s02n05p02s01.0005.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81211);
	_app->puzzleAddBackgroundImage(kPuzzle81211, "a08s02n05p02s01.0006.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81212);
	_app->puzzleAddBackgroundImage(kPuzzle81212, "a08s02n05p02s01.0007.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81213);
	_app->puzzleAddBackgroundImage(kPuzzle81213, "a08s02n05p02s01.0008.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81403);
	_app->puzzleAddBackgroundImage(kPuzzle81403, "a08s04n02p02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81404);
	_app->puzzleAddBackgroundImage(kPuzzle81404, "a08s04n02p03.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81405);
	_app->puzzleAddBackgroundImage(kPuzzle81405, "a08s04n02p04.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81301);
	_app->puzzleAddBackgroundImage(kPuzzle81301, "a08s03n02p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81302);
	_app->puzzleAddBackgroundImage(kPuzzle81302, "a08s03n03p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81303);
	_app->puzzleAddBackgroundImage(kPuzzle81303, "a08s03n03p03l01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81304);
	_app->puzzleAddBackgroundImage(kPuzzle81304, "a08s03n03p03l02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81305);
	_app->puzzleAddBackgroundImage(kPuzzle81305, "a08s03n03p03l03.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81306);
	_app->puzzleAddBackgroundImage(kPuzzle81306, "a08s03n03p03l04.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81307);
	_app->puzzleAddBackgroundImage(kPuzzle81307, "a08s03n02p02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81308);
	_app->puzzleAddBackgroundImage(kPuzzle81308, "a08s03n03p02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81214);
	_app->puzzleAddBackgroundImage(kPuzzle81214, "a08s02n06p02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81215);
	_app->puzzleAddBackgroundImage(kPuzzle81215, "a08s02n06p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81216);
	_app->puzzleAddBackgroundImage(kPuzzle81216, "a08s02n04p03.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81217);
	_app->puzzleAddBackgroundImage(kPuzzle81217, "a08s02n04p02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81218);
	_app->puzzleAddBackgroundImage(kPuzzle81218, "a08s02n04p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle81220);
	_app->puzzleAddBackgroundImage(kPuzzle81220, "a08s02n04p04.bmp", Common::Point(0, 16), true);
	_app->rotationAdd(81011, "A08S01N01R01", 0, 1);
	_app->rotationAdd(81021, "A08S01N02R01", 0, 1);
	_app->rotationAdd(81031, "A08S01N03R01", 0, 1);
	_app->rotationAdd(81041, "A08S01N04R01", 0, 1);
	_app->rotationAdd(82011, "A08S02N01R01", 0, 1);
	_app->rotationAdd(82021, "A08S02N02R01", 0, 2);
	_app->rotationAdd(82031, "A08S02N03R01", 0, 8);
	_app->rotationAdd(82041, "A08S02N04R01", 0, 1);
	_app->rotationAdd(82051, "A08S02N05R01", 0, 1);
	_app->rotationAdd(82061, "A08S02N06R01", 0, 6);
	_app->rotationAdd(83011, "A08S03N01R01", 0, 5);
	_app->rotationAdd(83021, "A08S03N02R01", 0, 8);
	_app->rotationAdd(83031, "A08S03N03R01", 0, 8);
	_app->rotationAdd(83041, "A08S03N04R01", 0, 11);
	_app->rotationAdd(84011, "A08S04N01R01", 0, 3);
	_app->rotationAdd(84021, "A08S04N02R01", 0, 7);
	_app->rotationAddMovabilityToRotation(81011, 81021, "", Common::Rect(240, -12, 650, 310), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(81011, 0, 0.0f, 0.0f, 87.0f, 0.0f, 2, 0.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(81021, 81031, "", Common::Rect(1065, -366, 1555, 130), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(81021, 0, 88.0f, -14.0f, 87.0f, 0.0f, 2, 88.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(81021, 81041, "", Common::Rect(2888, -24, 3376, 333), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(81021, 1, 270.0f, 0.0f, 87.0f, 0.0f, 2, 270.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(81021, 81011, "", Common::Rect(2091, -24, 2446, 388), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(81021, 2, 180.0f, 0.0f, 87.0f, 0.0f, 2, 180.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(81031, 81021, "", Common::Rect(3053, 182, 3350, 537), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(81031, 0, 270.0f, 26.0f, 87.0f, 0.0f, 2, 270.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(81041, 81021, "", Common::Rect(1154, -26, 1583, 350), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(81041, 0, 90.0f, 0.0f, 87.0f, 0.0f, 2, 90.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(81041, 82011, "", Common::Rect(1910, 240, 2666, 507), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(81041, 1, 180.0f, 26.0f, 87.0f, 0.0f, 2, 180.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82011, 82021, "", Common::Rect(1137, -24, 1546, 298), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82011, 0, 90.0f, 0.0f, 87.0f, 0.0f, 2, 90.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82011, 81041, "", Common::Rect(168, -195, 740, 266), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82011, 1, 0.0f, -5.0f, 87.0f, 0.0f, 2, 0.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82011, 82061, "", Common::Rect(3211, -136, 3600, 301), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82011, 2, 297.0f, 0.0f, 87.0f, 0.0f, 2, 297.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82011, 82061, "", Common::Rect(0, -136, 56, 301), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82011, 3, 297.0f, 0.0f, 87.0f, 0.0f, 2, 297.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82021, 82031, "", Common::Rect(1056, -22, 1406, 402), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82021, 0, 71.0f, 0.0f, 87.0f, 0.0f, 2, 71.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82021, 82011, "", Common::Rect(2893, -47, 3269, 416), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82021, 1, 270.0f, 0.0f, 87.0f, 0.0f, 2, 270.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82021, 82041, "", Common::Rect(462, -52, 863, 322), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82021, 2, 15.0f, 0.0f, 87.0f, 0.0f, 2, 15.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82021, 82051, "", Common::Rect(35, -15, 244, 240), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82021, 3, 334.0f, 0.0f, 87.0f, 0.0f, 2, 334.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82021, 83011, "", Common::Rect(61, 252, 428, 542), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82021, 4, 334.0f, 26.0f, 87.0f, 0.0f, 2, 334.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82031, 82021, "", Common::Rect(2889, -177, 3278, 333), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82031, 0, 270.0f, 0.0f, 87.0f, 0.0f, 2, 270.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82031, 82041, "", Common::Rect(256, -62, 583, 280), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82031, 1, 355.0f, 0.0f, 87.0f, 0.0f, 2, 355.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82031, 82051, "", Common::Rect(3418, -47, 3600, 200), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82031, 2, 313.0f, 0.0f, 87.0f, 0.0f, 2, 313.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82031, 82051, "", Common::Rect(128, -47, 128, 200), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82031, 3, 313.0f, 0.0f, 87.0f, 0.0f, 2, 313.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82041, 82011, "", Common::Rect(2492, -85, 2754, 233), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82041, 0, 213.0f, 0.0f, 87.0f, 0.0f, 2, 213.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82041, 82021, "", Common::Rect(2237, -80, 2511, 251), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82041, 1, 193.0f, 0.0f, 87.0f, 0.0f, 2, 193.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82041, 82031, "", Common::Rect(1836, -27, 2155, 326), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82041, 2, 153.0f, 0.0f, 87.0f, 0.0f, 2, 153.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82041, 82051, "", Common::Rect(2972, -47, 3244, 247), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82041, 3, 265.0f, 0.0f, 87.0f, 0.0f, 2, 265.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82051, 82021, "", Common::Rect(1675, -31, 1988, 289), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82051, 0, 136.0f, 0.0f, 87.0f, 0.0f, 2, 136.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82051, 82031, "", Common::Rect(1467, -41, 1743, 226), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82051, 1, 119.0f, 0.0f, 87.0f, 0.0f, 2, 119.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82051, 82041, "", Common::Rect(1084, -48, 1415, 251), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82051, 2, 84.0f, 0.0f, 87.0f, 0.0f, 2, 84.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82051, 82061, "", Common::Rect(2935, -62, 3308, 282), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82051, 3, 260.0f, 0.0f, 87.0f, 0.0f, 2, 260.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(82051, kPuzzle81205, "", Common::Rect(2056, 172, 2550, 308), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(82051, 4, 180.0f, 20.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(82061, 82011, "", Common::Rect(1794, -55, 2170, 251), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82061, 0, 148.0f, 0.0f, 87.0f, 0.0f, 2, 148.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(82061, 82051, "", Common::Rect(1070, -94, 1548, 291), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(82061, 1, 88.0f, 0.0f, 87.0f, 0.0f, 2, 88.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(83011, 83021, "", Common::Rect(2907, -177, 3394, 408), false, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(83011, 0, 270.0f, 0.0f, 87.0f, 0.0f, 2, 270.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(83011, 82021, "", Common::Rect(1381, -226, 1740, 310), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(83011, 1, 110.0f, -5.0f, 87.0f, 0.0f, 2, 110.0f, -5.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(83021, 83011, "", Common::Rect(1420, -109, 1743, 381), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(83021, 0, 113.0f, 0.0f, 87.0f, 0.0f, 2, 111.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(83021, 83031, "", Common::Rect(3568, 0, 3600, 155), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(83021, 1, 344.0f, 0.0f, 87.0f, 0.0f, 2, 344.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(83021, 83031, "", Common::Rect(0, 0, 571, 155), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(83021, 2, 344.0f, 0.0f, 87.0f, 0.0f, 2, 344.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(83021, 83041, "", Common::Rect(2875, -62, 3346, 273), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(83021, 3, 267.0f, 0.0f, 87.0f, 0.0f, 2, 270.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(83021, 84011, "A08S03_E03M05a", Common::Rect(1130, 422, 1351, 575), false, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(83021, 4, 71.0f, 26.0f, 87.0f, 0.0f, 2, 0.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(83021, kPuzzle81301, "", Common::Rect(91, 336, 221, 456), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(83021, 5, 180.0f, 20.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(83031, 83011, "", Common::Rect(1807, -64, 1937, 266), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(83031, 0, 164.0f, 0.0f, 87.0f, 0.0f, 2, 164.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(83031, 83021, "", Common::Rect(2010, -143, 2478, 397), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(83031, 1, 177.0f, 0.0f, 87.0f, 0.0f, 2, 177.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(83031, 83041, "", Common::Rect(2531, -90, 2684, 279), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(83031, 2, 215.0f, 0.0f, 87.0f, 0.0f, 2, 215.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(83031, kPuzzle81302, "", Common::Rect(58, 57, 263, 326), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(83031, 3, 180.0f, 20.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(83031, kPuzzle81308, "", Common::Rect(1582, -520, 2620, -162), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(83031, 4, 180.0f, -26.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(83041, 83031, "", Common::Rect(856, -111, 1117, 235), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(83041, 0, 54.0f, 0.0f, 87.0f, 0.0f, 2, 54.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(83041, 83021, "", Common::Rect(1165, -50, 1529, 345), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(83041, 1, 90.0f, 0.0f, 87.0f, 0.0f, 2, 90.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(84011, 84021, "", Common::Rect(247, -101, 747, 331), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(84011, 0, 0.0f, 0.0f, 87.0f, 0.0f, 2, 0.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(84011, 83021, "A08S03_E03M05b", Common::Rect(2075, -481, 2367, 563), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(84011, 1, 180.0f, -26.0f, 87.0f, 0.0f, 2, 270.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(84021, 84011, "", Common::Rect(1954, -123, 2309, 306), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(84021, 0, 180.0f, 0.0f, 87.0f, 0.0f, 2, 180.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(84021, kPuzzle81402, "", Common::Rect(792, 186, 1170, 420), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(84021, 1, 53.0f, 19.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(84021, kPuzzle81403, "", Common::Rect(3403, 218, 3561, 319), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(84021, 2, 53.0f, 19.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(84021, kPuzzle81405, "", Common::Rect(3295, -45, 3427, 59), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(84021, 3, 53.0f, 19.0f, 87.0f, 0.0f, 2);
	_app->puzzleAddMovabilityToRotation(kPuzzle81402, 84021, "", Common::Rect(0, 420, 580, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle81402, 0, 53.0f, 19.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle81205, 82051, "", Common::Rect(0, 420, 580, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle81205, 0, 180.0f, 20.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle81403, 84021, "", Common::Rect(0, 420, 580, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle81403, 0, 306.0f, 19.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle81404, 84021, "", Common::Rect(0, 420, 580, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle81404, 0, 306.0f, 19.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle81405, 84021, "", Common::Rect(0, 420, 580, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle81405, 0, 291.0f, 0.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle81301, 83021, "", Common::Rect(0, 420, 580, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle81301, 0, 338.0f, 26.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle81303, 83031, "", Common::Rect(0, 420, 580, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle81303, 0, 279.0f, 26.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle81304, 83031, "", Common::Rect(0, 420, 580, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle81304, 0, 83.0f, 26.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle81305, 83031, "", Common::Rect(0, 420, 580, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle81305, 0, 279.0f, 26.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle81306, 83031, "", Common::Rect(0, 420, 580, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle81306, 0, 83.0f, 26.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle81214, 82061, "", Common::Rect(0, 420, 580, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle81214, 0, 350.0f, 0.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle81215, 82061, "", Common::Rect(0, 420, 580, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle81215, 0, 284.0f, 0.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle81220, 82041, "", Common::Rect(0, 420, 580, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle81220, 0, 15.0f, 0.0f, 87.0f);
	_app->objectAdd(kObject81101, "", "Cur_drag", 4);
	_app->objectSetPassiveDrawCursor(kObject81101, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetActiveDrawCursor(kObject81101, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPresentation(kObject81101);
	_app->objectPresentationAddAnimationToRotation(kObject81101, 0, 81011, 0, 13, 12.5f, 5);
	_app->objectAddPresentation(kObject81101);
	_app->objectPresentationAddAnimationToRotation(kObject81101, 1, 81021, 0, 13, 12.5f, 5);
	_app->objectAddPresentation(kObject81101);
	_app->objectPresentationAddAnimationToRotation(kObject81101, 2, 81031, 0, 13, 12.5f, 5);
	_app->objectAddPresentation(kObject81101);
	_app->objectPresentationAddAnimationToRotation(kObject81101, 3, 81041, 0, 13, 12.5f, 5);
	_app->objectPresentationShow(kObject81101);
	_app->objectAdd(kObject81201, "", "Cur_drag", 4);
	_app->objectSetPassiveDrawCursor(kObject81201, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetActiveDrawCursor(kObject81201, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObject81202, "", "", 1);
	_app->objectAdd(kObject81203, "", "", 1);
	_app->objectAdd(kObject81221, "", "", 1);

	for (uint32 i = 0; i < 60; i++) {
		_app->objectAddPresentation(kObject81203);
		_app->objectPresentationAddImageToPuzzle(kObject81203, i, kPuzzle81201, Common::String::format("a08s02n02p01s01.%04d.tga", i + 1), Common::Point(212, 133), true, kDrawTypeAlpha, 1100);
	}

	for (uint32 i = 0; i < 60; i++) {
		_app->objectAddPresentation(kObject81202);
		_app->objectPresentationAddImageToPuzzle(kObject81202, i, kPuzzle81201, Common::String::format("a08s02n02p01s02.%04d.bmp", i + 1), Common::Point(245, 172), true, kDrawTypeNormal, 1000);
	}

	_app->objectAddPuzzleAccessibility(kObject81201, kPuzzle81201, Common::Rect(263, 194, 375, 302), true, kCursorDragDrop, 0);
	_app->objectAddPuzzleAccessibility(kObject81201, kPuzzle81201, Common::Rect(203, 133, 438, 363), true, kCursorDragDrop, 1);
	_app->objectAddPuzzleAccessibility(kObject81202, kPuzzle81201, Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->objectAddRotationAccessibility(kObject81202, 82021, Common::Rect(1770, -158, 2114, 188), true, kCursorActionObject, 1);
	_app->objectAddPresentation(kObject81221);
	_app->objectPresentationAddAnimationToRotation(kObject81221, 0, 82021, 0, 15, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject81221, 0, 0, 81203);
	_app->objectAddPresentation(kObject81221);
	_app->objectPresentationAddAnimationToRotation(kObject81221, 1, 82021, 0, 15, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject81221, 1, 0, 81204);
	_app->objectAdd(kObjectFrankFirstPrize, "Frank's 1st Prize", "a08_1stPrize", 1);
	_app->objectSetActiveCursor(kObjectFrankFirstPrize, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectFrankFirstPrize, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObject81204, "", "", 1);
	_app->objectAddRotationAccessibility(kObject81204, 82061, Common::Rect(256, -40, 474, 81), true, kCursorZoom, 0);
	_app->objectAddRotationAccessibility(kObject81204, 82061, Common::Rect(0, 0, 0, 0), false, kCursorTake, 1);
	_app->objectAddPuzzleAccessibility(kObject81204, kPuzzle81214, Common::Rect(0, 0, 0, 0), false, kCursorTake, 2);
	_app->objectAddPuzzleAccessibility(kObject81204, kPuzzle81214, Common::Rect(0, 0, 0, 0), false, kCursorTake, 3);
	_app->objectAddPuzzleAccessibility(kObject81204, kPuzzle81214, Common::Rect(0, 0, 0, 0), false, kCursorTake, 4);
	_app->objectAddPuzzleAccessibility(kObject81204, kPuzzle81214, Common::Rect(39, 72, 594, 413), false, kCursorTake, 5);
	_app->objectAddPresentation(kObject81204);
	_app->objectPresentationAddImageToRotation(kObject81204, 0, 82061, 2);
	_app->objectAddPresentation(kObject81204);
	_app->objectPresentationAddImageToRotation(kObject81204, 1, 82061, 0);
	_app->objectAddPresentation(kObject81204);
	_app->objectPresentationAddImageToPuzzle(kObject81204, 2, kPuzzle81214, "a08s02n06p02l01.bmp", Common::Point(81, 109), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObject81205, "", "", 1);
	_app->objectAddRotationAccessibility(kObject81205, 82041, Common::Rect(625, -47, 676, 73), true, kCursorZoom, 0);
	_app->objectAddRotationAccessibility(kObject81205, 82041, Common::Rect(530, -52, 608, 64), true, kCursorZoom, 1);
	_app->objectAdd(kObject81206, "", "", 1);
	_app->objectAddRotationAccessibility(kObject81206, 82041, Common::Rect(1372, -115, 1543, -24), true, kCursorZoom, 0);
	_app->objectAddRotationAccessibility(kObject81206, 82041, Common::Rect(1601, -102, 1727, -17), true, kCursorZoom, 1);
	_app->objectAddRotationAccessibility(kObject81206, 82041, Common::Rect(1766,  -85, 1852, -12), true, kCursorZoom, 2);
	_app->objectAddRotationAccessibility(kObject81206, 82031, Common::Rect( 699,  -75,  757, -24), true, kCursorZoom, 3);
	_app->objectAddRotationAccessibility(kObject81206, 82031, Common::Rect( 785, -101,  892, -27), true, kCursorZoom, 4);
	_app->objectAddRotationAccessibility(kObject81206, 82031, Common::Rect( 947, -134, 1147, -29), true, kCursorZoom, 5);
	_app->objectAddPuzzleAccessibility(kObject81206, kPuzzle81216, Common::Rect(0, 420, 640, 464), true, kCursorBack, 6);
	_app->objectAddPuzzleAccessibility(kObject81206, kPuzzle81217, Common::Rect(0, 420, 640, 464), true, kCursorBack, 7);
	_app->objectAddPuzzleAccessibility(kObject81206, kPuzzle81218, Common::Rect(0, 420, 640, 464), true, kCursorBack, 8);
	_app->objectAdd(kObject81208, "", "", 1);
	_app->objectAdd(kObjectThinPencil, "Thin pencil", "a08_Pencil", 1);
	_app->objectSetActiveCursor(kObjectThinPencil, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectThinPencil, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectCompassNeedle, "Compass needle", "a08_CompassNeedle", 1);
	_app->objectSetActiveCursor(kObjectCompassNeedle, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectCompassNeedle, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddRotationAccessibility(kObject81208, 82031, Common::Rect(1509, 90, 1754, 280), true, kCursorZoom, 0);
	_app->objectAddPuzzleAccessibility(kObject81208, kPuzzle81202, Common::Rect(  0, 420, 640, 464), true, kCursorBack, 1);
	_app->objectAddPuzzleAccessibility(kObject81208, kPuzzle81202, Common::Rect(  0,   0,   0,   0), true, kCursorZoom, 2);
	_app->objectAddPuzzleAccessibility(kObject81208, kPuzzle81202, Common::Rect(439,  46, 560, 180), true, kCursorTake, 3);
	_app->objectAddPuzzleAccessibility(kObject81208, kPuzzle81202, Common::Rect(203, 227, 528, 267), false, kCursorTake, 4);
	_app->objectAddPresentation(kObject81208);
	_app->objectPresentationAddAnimationToRotation(kObject81208, 0, 82031, 1, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject81208, 0, 0, 81201);
	_app->objectAddPresentation(kObject81208);
	_app->objectPresentationAddAnimationToRotation(kObject81208, 1, 82031, 1, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject81208, 1, 0, 81202);
	_app->objectAddPresentation(kObject81208);
	_app->objectPresentationAddImageToPuzzle(kObject81208, 2, kPuzzle81202, "a08s02n04p01.tga", Common::Point(58, 218), true, kDrawTypeAlpha, 1000);
	_app->objectAddPresentation(kObject81208);
	_app->objectPresentationAddImageToPuzzle(kObject81208, 3, kPuzzle81202, "a08s02n04p01l01.tga", Common::Point(64, 230), true, kDrawTypeAlpha, 1000);
	_app->objectAdd(kObject81220, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject81220, kPuzzle81202, Common::Rect( 32,  94, 124, 233), false, kCursorZoom, 0);
	_app->objectAddPuzzleAccessibility(kObject81220, kPuzzle81202, Common::Rect(181,  97, 344, 397), false, kCursorZoom, 1);
	_app->objectAddPuzzleAccessibility(kObject81220, kPuzzle81202, Common::Rect(421,  67, 610, 425), false, kCursorZoom, 2);
	_app->objectAddPuzzleAccessibility(kObject81220, kPuzzle81202, Common::Rect(196, 295, 341, 401), true, kCursorZoom, 3);
	_app->objectAddPresentation(kObject81220);
	_app->objectPresentationAddImageToPuzzle(kObject81220, 0, kPuzzle81202, "a08s02n03p01l01.tga", Common::Point(20, 58), true, kDrawTypeAlpha, 1200);
	_app->objectAddPresentation(kObject81220);
	_app->objectPresentationAddImageToPuzzle(kObject81220, 1, kPuzzle81202, "a08s02n03p02.tga", Common::Point(120, 24), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject81220);
	_app->objectPresentationAddImageToPuzzle(kObject81220, 2, kPuzzle81202, "a08s02n03p03.tga", Common::Point(330, 30), true, kDrawTypeAlpha, 1000);
	_app->objectAddPresentation(kObject81220);
	_app->objectPresentationAddImageToPuzzle(kObject81220, 3, kPuzzle81202, "a08s02n03p01l01.tga", Common::Point(20, 58), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject81220);
	_app->objectPresentationAddImageToPuzzle(kObject81220, 4, kPuzzle81202, "a08s02n03p02.tga", Common::Point(120, 24), true, kDrawTypeAlpha, 1200);
	_app->objectAddPresentation(kObject81220);
	_app->objectPresentationAddImageToPuzzle(kObject81220, 5, kPuzzle81202, "a08s02n03p03.tga", Common::Point(330, 30), true, kDrawTypeAlpha, 1000);
	_app->objectAddPresentation(kObject81220);
	_app->objectPresentationAddImageToPuzzle(kObject81220, 6, kPuzzle81202, "a08s02n03p01l01.tga", Common::Point(20, 58), true, kDrawTypeAlpha, 1000);
	_app->objectAddPresentation(kObject81220);
	_app->objectPresentationAddImageToPuzzle(kObject81220, 7, kPuzzle81202, "a08s02n03p02.tga", Common::Point(120, 24), true, kDrawTypeAlpha, 1100);
	_app->objectAddPresentation(kObject81220);
	_app->objectPresentationAddImageToPuzzle(kObject81220, 8, kPuzzle81202, "a08s02n03p03.tga", Common::Point(330, 30), true, kDrawTypeAlpha, 1200);
	_app->objectAdd(kObject81211, "", "", 1);
	_app->objectAdd(kObjectBoxOfSlides, "Box of slides", "a08_Slides", 1);
	_app->objectSetActiveCursor(kObjectBoxOfSlides, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectBoxOfSlides, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectMagnifyingGlass, "Magnifying glass", "a08_MagGlass", 1);
	_app->objectSetActiveCursor(kObjectMagnifyingGlass, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectMagnifyingGlass, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddRotationAccessibility(kObject81211, 82031, Common::Rect(1495, 387, 1548, 477), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject81211, 82031, Common::Rect(1847, 289, 2214, 519), false, kCursorAction, 1);
	_app->objectAddRotationAccessibility(kObject81211, 82031, Common::Rect(1483, 375, 1560, 446), false, kCursorTake, 2);
	_app->objectAddRotationAccessibility(kObject81211, 82031, Common::Rect(1585, 355, 1683, 415), false, kCursorTake, 3);
	_app->objectAddRotationAccessibility(kObject81211, 82031, Common::Rect(   0,   0,    0,   0), false, kCursorTake, 4);
	_app->objectAddRotationAccessibility(kObject81211, 82031, Common::Rect(   0,   0,    0,   0), false, kCursorTake, 5);
	_app->objectAddPresentation(kObject81211);
	_app->objectPresentationAddImageToRotation(kObject81211, 0, 82031, 2);
	_app->objectAddPresentation(kObject81211);
	_app->objectPresentationAddImageToRotation(kObject81211, 1, 82031, 0);
	_app->objectAddPresentation(kObject81211);
	_app->objectPresentationAddImageToRotation(kObject81211, 2, 82031, 3);
	_app->objectAddPresentation(kObject81211);
	_app->objectPresentationAddImageToRotation(kObject81211, 3, 82031, 4);
	_app->objectAdd(kObject81215, "", "", 1);
	_app->objectAdd(kObject81216, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject81215, kPuzzle81205, Common::Rect( 20, 399,  58, 422), true, kCursorAction, 0);
	_app->objectAddPuzzleAccessibility(kObject81215, kPuzzle81205, Common::Rect( 51,  26, 599, 355), true, kCursorAction, 1);
	_app->objectAddPuzzleAccessibility(kObject81215, kPuzzle81205, Common::Rect(158, 111, 223, 170), false, kCursorTake, 2);
	_app->objectAddPuzzleAccessibility(kObject81215, kPuzzle81205, Common::Rect(247, 116, 318, 171), false, kCursorTake, 3);
	_app->objectAddPuzzleAccessibility(kObject81215, kPuzzle81205, Common::Rect(338, 123, 416, 182), false, kCursorTake, 4);
	_app->objectAddPuzzleAccessibility(kObject81215, kPuzzle81205, Common::Rect(418,  99, 498, 148), false, kCursorTake, 5);
	_app->objectAddPuzzleAccessibility(kObject81215, kPuzzle81205, Common::Rect(163, 180, 239, 238), false, kCursorTake, 6);
	_app->objectAddPuzzleAccessibility(kObject81215, kPuzzle81205, Common::Rect(262, 193, 336, 252), false, kCursorTake, 7);
	_app->objectAddPuzzleAccessibility(kObject81215, kPuzzle81205, Common::Rect(353, 202, 433, 265), false, kCursorTake, 8);
	_app->objectAddPuzzleAccessibility(kObject81215, kPuzzle81205, Common::Rect(445, 182, 534, 243), false, kCursorTake, 9);
	_app->objectAddPuzzleAccessibility(kObject81215, kPuzzle81206, Common::Rect(  0,  16, 640, 464), true, kCursorBack, 10);
	_app->objectAddPuzzleAccessibility(kObject81215, kPuzzle81207, Common::Rect(  0,  16, 640, 464), true, kCursorBack, 11);
	_app->objectAddPuzzleAccessibility(kObject81215, kPuzzle81208, Common::Rect(  0,  16, 640, 464), true, kCursorBack, 12);
	_app->objectAddPuzzleAccessibility(kObject81215, kPuzzle81209, Common::Rect(  0,  16, 640, 464), true, kCursorBack, 13);
	_app->objectAddPuzzleAccessibility(kObject81215, kPuzzle81210, Common::Rect(  0,  16, 640, 464), true, kCursorBack, 14);
	_app->objectAddPuzzleAccessibility(kObject81215, kPuzzle81211, Common::Rect(  0,  16, 640, 464), true, kCursorBack, 15);
	_app->objectAddPuzzleAccessibility(kObject81215, kPuzzle81212, Common::Rect(  0,  16, 640, 464), true, kCursorBack, 16);
	_app->objectAddPuzzleAccessibility(kObject81215, kPuzzle81213, Common::Rect(  0,  16, 640, 464), true, kCursorBack, 17);
	_app->objectAddPresentation(kObject81215);
	_app->objectPresentationAddImageToPuzzle(kObject81215, 0, kPuzzle81205, "a08s02n05p01l01.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject81215);
	_app->objectPresentationAddImageToPuzzle(kObject81215, 1, kPuzzle81205, "a08s02n05p01l02.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject81215);
	_app->objectPresentationAddImageToPuzzle(kObject81215, 2, kPuzzle81205, "a08s02n05p01l03.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject81216);
	_app->objectPresentationAddImageToPuzzle(kObject81216, 0, kPuzzle81206, "a08s02n05p02s01.0010.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject81216);
	_app->objectPresentationAddImageToPuzzle(kObject81216, 1, kPuzzle81207, "a08s02n05p02s01.0010.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject81216);
	_app->objectPresentationAddImageToPuzzle(kObject81216, 2, kPuzzle81208, "a08s02n05p02s01.0010.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject81216);
	_app->objectPresentationAddImageToPuzzle(kObject81216, 3, kPuzzle81209, "a08s02n05p02s01.0010.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject81216);
	_app->objectPresentationAddImageToPuzzle(kObject81216, 4, kPuzzle81210, "a08s02n05p02s01.0010.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject81216);
	_app->objectPresentationAddImageToPuzzle(kObject81216, 5, kPuzzle81211, "a08s02n05p02s01.0010.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject81216);
	_app->objectPresentationAddImageToPuzzle(kObject81216, 6, kPuzzle81212, "a08s02n05p02s01.0010.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject81216);
	_app->objectPresentationAddImageToPuzzle(kObject81216, 7, kPuzzle81213, "a08s02n05p02s01.0010.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectPresentationShow(kObject81216);
	_app->objectAdd(kObject81217, "", "", 1);
	_app->objectAdd(kObjectLittleWig, "Little wig", "a08_Wig", 1);
	_app->objectSetActiveCursor(kObjectLittleWig, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectLittleWig, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectKey3, "Key", "a08_MirrorKey", 1);
	_app->objectSetActiveCursor(kObjectKey3, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectKey3, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddRotationAccessibility(kObject81217, 82061, Common::Rect(3552,  140, 3598, 178), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject81217, 82061, Common::Rect(3415,  -82, 3434, -57), false, kCursorZoom, 1);
	_app->objectAddRotationAccessibility(kObject81217, 82061, Common::Rect(3415,  -82, 3434, -57), false, kCursorZoom, 2);
	_app->objectAddRotationAccessibility(kObject81217, 82061, Common::Rect(3475, -220, 3550, 434), false, kCursorAction, 3);
	_app->objectAddPuzzleAccessibility(kObject81217, kPuzzle81215, Common::Rect(271,  43, 360, 190), true, kCursorTake, 4);
	_app->objectAddPuzzleAccessibility(kObject81217, kPuzzle81215, Common::Rect(197, 100, 378, 417), false, kCursorTake, 5);
	_app->objectAddPresentation(kObject81217);
	_app->objectPresentationAddImageToRotation(kObject81217, 0, 82061, 1);
	_app->objectAddPresentation(kObject81217);
	_app->objectPresentationAddImageToRotation(kObject81217, 1, 82061, 3);
	_app->objectAddPresentation(kObject81217);
	_app->objectPresentationAddImageToRotation(kObject81217, 2, 82061, 4);
	_app->objectAddPresentation(kObject81217);
	_app->objectPresentationAddImageToRotation(kObject81217, 3, 82061, 5);
	_app->objectAddPresentation(kObject81217);
	_app->objectPresentationAddImageToPuzzle(kObject81217, 4, kPuzzle81215, "a08s02n06p01l01.bmp", Common::Point(187, 39), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject81217);
	_app->objectPresentationAddImageToPuzzle(kObject81217, 5, kPuzzle81215, "a08s02n06p01l02.bmp", Common::Point(186, 23), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObject81222, "", "", 1);
	_app->objectAddRotationAccessibility(kObject81222, 82031, Common::Rect(2283, 224, 2315, 254), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject81222, 82031, Common::Rect(2285, 255, 2315, 282), true, kCursorAction, 1);
	_app->objectAddRotationAccessibility(kObject81222, 82031, Common::Rect(2283, 283, 2316, 310), true, kCursorAction, 2);
	_app->objectAddPresentation(kObject81222);
	_app->objectPresentationAddImageToRotation(kObject81222, 0, 82031, 5);
	_app->objectAddPresentation(kObject81222);
	_app->objectPresentationAddImageToRotation(kObject81222, 1, 82031, 6);
	_app->objectAddPresentation(kObject81222);
	_app->objectPresentationAddImageToRotation(kObject81222, 2, 82031, 7);
	_app->objectAdd(kObject81301, "", "", 1);
	_app->objectAddRotationAccessibility(kObject81301, 83011, Common::Rect(3255, 189, 3338, 262), true, kCursorActionObject, 0);
	_app->objectAddPresentation(kObject81301);
	_app->objectPresentationAddImageToRotation(kObject81301, 0, 83011, 2);
	_app->objectAddPresentation(kObject81301);
	_app->objectPresentationAddImageToRotation(kObject81301, 1, 83011, 0);
	_app->objectPresentationShow(kObject81301, 1);
	_app->objectAdd(kObject81302, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject81302, kPuzzle81301, Common::Rect(242, 179, 433, 335), true, kCursorActionObject, 0);
	_app->objectAddPresentation(kObject81302);
	_app->objectPresentationAddImageToPuzzle(kObject81302, 0, kPuzzle81301, "a08s03n02p01l01.bmp", Common::Point(309, 184), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject81302);
	_app->objectPresentationAddImageToRotation(kObject81302, 1, 83021, 4);
	_app->objectAddPresentation(kObject81302);
	_app->objectPresentationAddImageToRotation(kObject81302, 2, 83041, 3);
	_app->objectPresentationShow(kObject81302, 0);
	_app->objectPresentationShow(kObject81302, 1);
	_app->objectPresentationShow(kObject81302, 2);
	_app->objectAddPresentation(kObject81302);
	_app->objectPresentationAddAnimationToPuzzle(kObject81302, 3, kPuzzle81301, "a08s03n02p01s01", kImageTypeBMP, Common::Point(261, 169), kDrawTypeNormal, 1020, 36, 25.0f, 6);
	_app->objectAdd(kObject81303, "", "", 1);
	_app->objectAdd(kObjectKey4, "Key", "a08_AutomatKey", 1);
	_app->objectSetActiveCursor(kObjectKey4, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectKey4, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObject81303, kPuzzle81302, Common::Rect(350, 288, 407, 337), true, kCursorAction, 0);
	_app->objectAddPuzzleAccessibility(kObject81303, kPuzzle81302, Common::Rect(299,  79, 332, 125), true, kCursorActionObject, 1);
	_app->objectAddPuzzleAccessibility(kObject81303, kPuzzle81302, Common::Rect(219, 389, 252, 418), false, kCursorTake, 2);
	_app->objectAddPuzzleAccessibility(kObject81303, kPuzzle81302, Common::Rect(  0, 420, 640, 464), true, kCursorBack, 3);
	_app->objectAddPresentation(kObject81303);
	_app->objectPresentationAddImageToPuzzle(kObject81303, 0, kPuzzle81302, "a08s03n03p01l01.bmp", Common::Point(299, 80), true, kDrawTypeNormal, 1000);
	_app->objectPresentationShow(kObject81303, 0);
	_app->objectAddPresentation(kObject81303);
	_app->objectPresentationAddImageToPuzzle(kObject81303, 1, kPuzzle81302, "a08s03n03p01l02.bmp", Common::Point(178, 342), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject81303);
	_app->objectPresentationAddImageToPuzzle(kObject81303, 2, kPuzzle81302, "a08s03n03p01l03.bmp", Common::Point(173, 348), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject81303);
	_app->objectPresentationAddAnimationToPuzzle(kObject81303, 3, kPuzzle81302, "a08s03n03p01s01", kImageTypeBMP, Common::Point(136, 16), kDrawTypeNormal, 1000, 27, 25.0f, 6);
	_app->objectPresentationSetAnimationOnPuzzle(kObject81303, 3, 0, 81301);
	_app->objectAddPresentation(kObject81303);
	_app->objectPresentationAddAnimationToPuzzle(kObject81303, 4, kPuzzle81302, "a08s03n03p01s01", kImageTypeBMP, Common::Point(136, 16), kDrawTypeNormal, 1000, 27, 25.0f, 10);
	_app->objectPresentationSetAnimationOnPuzzle(kObject81303, 4, 0, 81302);
	_app->objectAddPresentation(kObject81303);
	_app->objectPresentationAddAnimationToPuzzle(kObject81303, 5, kPuzzle81302, "a08s03n03p01s02", kImageTypeBMP, Common::Point(170, 354), kDrawTypeNormal, 1000, 10, 25.0f, 6);
	_app->objectPresentationSetAnimationOnPuzzle(kObject81303, 5, 0, 81303);
	_app->objectAddPresentation(kObject81303);
	_app->objectPresentationAddAnimationToPuzzle(kObject81303, 6, kPuzzle81302, "a08s03n03p01s02", kImageTypeBMP, Common::Point(170, 354), kDrawTypeNormal, 1000, 10, 25.0f, 10);
	_app->objectPresentationSetAnimationOnPuzzle(kObject81303, 6, 0, 81304);
	_app->objectAddPresentation(kObject81303);
	_app->objectPresentationAddAnimationToPuzzle(kObject81303, 7, kPuzzle81302, "a08s03n03p01s03", kImageTypeBMP, Common::Point(174, 347), kDrawTypeNormal, 1000, 10, 25.0f, 6);
	_app->objectPresentationSetAnimationOnPuzzle(kObject81303, 7, 0, 81305);
	_app->objectAddPresentation(kObject81303);
	_app->objectPresentationAddAnimationToPuzzle(kObject81303, 8, kPuzzle81302, "a08s03n03p01s03", kImageTypeBMP, Common::Point(174, 347), kDrawTypeNormal, 1000, 10, 25.0f, 10);
	_app->objectPresentationSetAnimationOnPuzzle(kObject81303, 8, 0, 81306);
	_app->objectAddPresentation(kObject81303);
	_app->objectPresentationAddImageToRotation(kObject81303, 9, 83021, 3);
	_app->objectPresentationShow(kObject81303, 9);
	_app->objectAddPresentation(kObject81303);
	_app->objectPresentationAddImageToRotation(kObject81303, 10, 83031, 0);
	_app->objectPresentationShow(kObject81303, 10);
	_app->objectAdd(kObject81305, "", "", 1);
	_app->objectAddRotationAccessibility(kObject81305, 83031, Common::Rect(3118, 280, 3401, 357), true, kCursorZoom, 0);
	_app->objectAddRotationAccessibility(kObject81305, 83031, Common::Rect(1139, 247, 1385, 366), true, kCursorZoom, 1);
	_app->objectAdd(kObject81306, "", "", 1);
	_app->objectAddRotationAccessibility(kObject81306, 83031, Common::Rect(3447,  12, 3489, 54), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject81306, 83031, Common::Rect(1012, -15, 1084, 52), true, kCursorAction, 1);
	_app->objectAddRotationAccessibility(kObject81306, 83031, Common::Rect(1726, -12, 1789, 52), true, kCursorAction, 2);
	_app->objectAddRotationAccessibility(kObject81306, 83031, Common::Rect(2689,   0, 2754, 66), true, kCursorAction, 3);
	_app->objectAddPresentation(kObject81306);
	_app->objectPresentationAddImageToRotation(kObject81306, 0, 83031, 6);
	_app->objectAddPresentation(kObject81306);
	_app->objectPresentationAddImageToRotation(kObject81306, 1, 83031, 3);
	_app->objectAddPresentation(kObject81306);
	_app->objectPresentationAddImageToRotation(kObject81306, 2, 83031, 4);
	_app->objectAddPresentation(kObject81306);
	_app->objectPresentationAddImageToRotation(kObject81306, 3, 83031, 5);
	_app->objectAddPresentation(kObject81306);
	_app->objectPresentationAddImageToRotation(kObject81306, 4, 83031, 2);
	_app->objectAddPresentation(kObject81306);
	_app->objectPresentationAddImageToRotation(kObject81306, 5, 83021, 0);
	_app->objectAddPresentation(kObject81306);
	_app->objectPresentationAddImageToRotation(kObject81306, 6, 83041, 0);
	_app->objectAdd(kObject81307, "", "", 1);
	_app->objectAddRotationAccessibility(kObject81307, 83021, Common::Rect(63, -141, 400, -26), false, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject81307, 83021, Common::Rect(63, -141, 400, -26), false, kCursorZoom, 1);
	_app->objectAddPuzzleAccessibility(kObject81307, kPuzzle81307, Common::Rect(0, 420, 640, 464), true, kCursorBack, 2);
	_app->objectAddPresentation(kObject81307);
	_app->objectPresentationAddImageToRotation(kObject81307, 0, 83021, 2);
	_app->objectAddPresentation(kObject81307);
	_app->objectPresentationAddAnimationToRotation(kObject81307, 1, 83021, 1, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject81307, 1, 0, 81307);
	_app->objectAddPresentation(kObject81307);
	_app->objectPresentationAddAnimationToRotation(kObject81307, 2, 83021, 1, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject81307, 2, 0, 81308);
	_app->objectAdd(kObject81311, "", "", 1);
	_app->objectAdd(kObject81308, "", "Cur_drag", 4);
	_app->objectSetPassiveDrawCursor(kObject81308, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetActiveDrawCursor(kObject81308, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObject81309, "", "Cur_drag", 4);
	_app->objectSetPassiveDrawCursor(kObject81309, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetActiveDrawCursor(kObject81309, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObject81310, "", "Cur_drag", 4);
	_app->objectSetPassiveDrawCursor(kObject81310, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetActiveDrawCursor(kObject81310, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObject81311, kPuzzle81308, Common::Rect(  0, 420, 640, 464), true, kCursorBack, 0);
	_app->objectAddPuzzleAccessibility(kObject81310, kPuzzle81308, Common::Rect(319,  18, 632, 400), true, kCursorDragDrop, 0);
	_app->objectAddPuzzleAccessibility(kObject81310, kPuzzle81308, Common::Rect(  0,  18, 309, 441), true, kCursorDragDrop, 1);

	for (uint32 i = 0; i < 15; i++) {
		_app->objectAddPresentation(kObject81308);
		_app->objectPresentationAddImageToPuzzle(kObject81308, i, kPuzzle81308, Common::String::format("a08s03n03p02s02.%04d.bmp", i + 1), Common::Point(316, 16), true, kDrawTypeNormal, 1000);
	}

	for (uint32 i = 0; i < 15; i++) {
		_app->objectAddPresentation(kObject81309);
		_app->objectPresentationAddImageToPuzzle(kObject81309, i, kPuzzle81308, Common::String::format("a08s03n03p02s01.%04d.bmp", i + 1), Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject81312, "", "", 1);
	_app->objectAddPresentation(kObject81312);
	_app->objectPresentationAddImageToRotation(kObject81312, 0, 83021, 5);
	_app->objectAddPresentation(kObject81312);
	_app->objectPresentationAddImageToRotation(kObject81312, 1, 83041, 2);
	_app->objectAdd(kObject81313, "", "", 1);
	_app->objectAddRotationAccessibility(kObject81313, 83021, Common::Rect(2765, 301, 2937, 519), true, kCursorZoom, 0);
	_app->objectAddRotationAccessibility(kObject81313, 83021, Common::Rect(1988, 158, 2225, 530), true, kCursorZoom, 1);
	_app->objectAddRotationAccessibility(kObject81313, 83021, Common::Rect(3598, 127, 3600, 318), true, kCursorZoom, 2);
	_app->objectAddRotationAccessibility(kObject81313, 83021, Common::Rect(   0, 127,  506, 318), true, kCursorZoom, 3);
	_app->objectAdd(kObject81314, "", "", 1);
	_app->objectAddRotationAccessibility(kObject81314, 83041, Common::Rect(2271,  8, 2336, 56), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject81314, 83041, Common::Rect(2434, 17, 2459, 52), false, kCursorAction, 1);
	_app->objectAddRotationAccessibility(kObject81314, 83041, Common::Rect(2128, 19, 2149, 56), false, kCursorAction, 2);
	_app->objectAddPresentation(kObject81314);
	_app->objectPresentationAddAnimationToRotation(kObject81314, 0, 83041, 8, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject81314, 0, 0, 81309);
	_app->objectAddPresentation(kObject81314);
	_app->objectPresentationAddAnimationToRotation(kObject81314, 1, 83041, 8, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject81314, 1, 0, 81310);
	_app->objectAddPresentation(kObject81314);
	_app->objectPresentationAddImageToRotation(kObject81314, 2, 83041, 6);
	_app->objectAdd(kObject81315, "", "", 1);
	_app->objectAdd(kObject81316, "", "", 1);
	_app->objectAdd(kObject81317, "", "", 1);
	_app->objectAddRotationAccessibility(kObject81315, 83041, Common::Rect(2585, 56, 2615,  91), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject81315, 83041, Common::Rect(2619, 50, 2645,  87), true, kCursorAction, 1);
	_app->objectAddRotationAccessibility(kObject81315, 83041, Common::Rect(2520, 78, 2545, 110), true, kCursorAction, 2);
	_app->objectAddRotationAccessibility(kObject81315, 83041, Common::Rect(2678, 57, 2701,  89), true, kCursorAction, 3);
	_app->objectAddPresentation(kObject81316);
	_app->objectPresentationAddAnimationToRotation(kObject81316, 0, 83041, 7, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject81316, 0, 0, 81311);
	_app->objectAddPresentation(kObject81316);
	_app->objectPresentationAddAnimationToRotation(kObject81316, 1, 83041, 7, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject81316, 1, 0, 81312);
	_app->objectAddPresentation(kObject81316);
	_app->objectPresentationAddImageToRotation(kObject81316, 2, 83041, 5);
	_app->objectAddPresentation(kObject81317);
	_app->objectPresentationAddAnimationToRotation(kObject81317, 0, 83041, 1, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject81317, 0, 0, 81313);
	_app->objectAddPresentation(kObject81317);
	_app->objectPresentationAddAnimationToRotation(kObject81317, 1, 83041, 1, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject81317, 1, 0, 81314);
	_app->objectAddPresentation(kObject81317);
	_app->objectPresentationAddImageToRotation(kObject81317, 2, 83041, 4);
	_app->objectAdd(kObject81401, "", "", 1);
	_app->objectAdd(kObjectYellowBulb, "Yellow bulb", "a08_BulbYella", 1);
	_app->objectSetActiveCursor(kObjectYellowBulb, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectYellowBulb, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectRedBulb, "Red bulb", "a08_BulbRed", 1);
	_app->objectSetActiveCursor(kObjectRedBulb, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectRedBulb, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddRotationAccessibility(kObject81401, 84011, Common::Rect(1337, 98, 1460, 257), true, kCursorAction, 0);
	_app->objectAddPuzzleAccessibility(kObject81401, kPuzzle81401, Common::Rect(158, 222, 325, 352), true, kCursorTake, 1);
	_app->objectAddPuzzleAccessibility(kObject81401, kPuzzle81401, Common::Rect(  0, 420, 640, 464), true, kCursorBack, 2);
	_app->objectAddPresentation(kObject81401);
	_app->objectPresentationAddAnimationToRotation(kObject81401, 0, 84011, 1, 15, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject81401, 0, 0, 81401);
	_app->objectAddPresentation(kObject81401);
	_app->objectPresentationAddAnimationToRotation(kObject81401, 1, 84011, 1, 15, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject81401, 1, 0, 81402);
	_app->objectAddPresentation(kObject81401);
	_app->objectPresentationAddAnimationToRotation(kObject81401, 2, 84011, 2, 15, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject81401, 2, 0, 81401);
	_app->objectAddPresentation(kObject81401);
	_app->objectPresentationAddAnimationToRotation(kObject81401, 3, 84011, 2, 15, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject81401, 3, 0, 81402);
	_app->objectAddPresentation(kObject81401);
	_app->objectPresentationAddImageToPuzzle(kObject81401, 4, kPuzzle81401, "a08s04n01p01l01.bmp", Common::Point(133, 234), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObject81404, "", "", 1);
	_app->objectAddRotationAccessibility(kObject81404, 84021, Common::Rect(0, 0, 0, 0), true, kCursorZoom, 0);
	_app->objectAddPuzzleAccessibility(kObject81404, kPuzzle81402, Common::Rect(146,  54, 448, 397), true, kCursorActionObject, 1);
	_app->objectAddPuzzleAccessibility(kObject81404, kPuzzle81402, Common::Rect(580, 394, 628, 450), true, kCursorAction, 2);
	_app->objectAddPuzzleAccessibility(kObject81404, kPuzzle81402, Common::Rect(  0, 420, 640, 464), true, kCursorBack, 3);
	_app->objectAddPresentation(kObject81404);
	_app->objectPresentationAddImageToPuzzle(kObject81404, 0, kPuzzle81402, "a08s04n02p01l01.bmp", Common::Point(73, 100), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject81404);
	_app->objectPresentationAddImageToPuzzle(kObject81404, 1, kPuzzle81402, "a08s04n02p01l02.bmp", Common::Point(568, 392), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject81404);
	_app->objectPresentationAddImageToPuzzle(kObject81404, 2, kPuzzle81402, "a08s04n02p01l03.bmp", Common::Point(43, 34), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject81404);
	_app->objectPresentationAddImageToPuzzle(kObject81404, 3, kPuzzle81402, "a08s04n02p01l04.bmp", Common::Point(44, 32), true, kDrawTypeNormal, 1010);
	_app->objectAddPresentation(kObject81404);
	_app->objectPresentationAddImageToPuzzle(kObject81404, 4, kPuzzle81402, "a08s04n02p01l05.bmp", Common::Point(34, 35), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject81404);
	_app->objectPresentationAddImageToPuzzle(kObject81404, 5, kPuzzle81402, "a08s04n02p01l06.bmp", Common::Point(41, 32), true, kDrawTypeNormal, 1010);
	_app->objectAddPresentation(kObject81404);
	_app->objectPresentationAddAnimationToPuzzle(kObject81404, 6, kPuzzle81402, "a08s04n02p01s01", kImageTypeBMP, Common::Point(152, 218), kDrawTypeNormal, 1020, 68, 15.0f, 6);
	_app->objectAdd(kObject81405, "", "", 1);
	_app->objectAddRotationAccessibility(kObject81405, 84021, Common::Rect( 915, -116, 1028, -24), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject81405, 84021, Common::Rect( 945,  -94,  980, -66), false, kCursorActionObject, 1);
	_app->objectAddRotationAccessibility(kObject81405, 84021, Common::Rect(1003,  -99, 1052, -26), false, kCursorAction, 2);
	_app->objectAddPresentation(kObject81405);
	_app->objectPresentationAddAnimationToRotation(kObject81405, 0, 84021, 6, 15, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject81405, 0, 0, 81403);
	_app->objectAddPresentation(kObject81405);
	_app->objectPresentationAddAnimationToRotation(kObject81405, 1, 84021, 6, 15, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject81405, 1, 0, 81404);
	_app->objectAddPresentation(kObject81405);
	_app->objectPresentationAddAnimationToRotation(kObject81405, 2, 84021, 1, 15, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject81405, 2, 0, 81403);
	_app->objectAddPresentation(kObject81405);
	_app->objectPresentationAddAnimationToRotation(kObject81405, 3, 84021, 1, 15, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject81405, 3, 0, 81404);
	_app->objectAddPresentation(kObject81405);
	_app->objectPresentationAddAnimationToRotation(kObject81405, 4, 84021, 5, 15, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject81405, 4, 0, 81403);
	_app->objectAddPresentation(kObject81405);
	_app->objectPresentationAddAnimationToRotation(kObject81405, 5, 84021, 5, 15, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject81405, 5, 0, 81404);
	_app->objectAddPresentation(kObject81405);
	_app->objectPresentationAddImageToRotation(kObject81405, 6, 84021, 3);
	_app->objectAddPresentation(kObject81405);
	_app->objectPresentationAddImageToRotation(kObject81405, 7, 84021, 0);
	_app->objectAddPresentation(kObject81405);
	_app->objectPresentationAddImageToRotation(kObject81405, 8, 84021, 2);
	_app->objectAdd(kObject81406, "", "", 1);
	_app->objectAddRotationAccessibility(kObject81406, 84021, Common::Rect(476, 104, 667, 313), true, kCursorZoom, 0);
	_app->objectAdd(kObjectDiaryOfASeducer, "Diary of a Seducer", "a08_SeducersDiary", 1);
	_app->objectSetActiveCursor(kObjectDiaryOfASeducer, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectDiaryOfASeducer, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectDiaryOfASeducer, kPuzzle81403, Common::Rect(136,  71, 468, 371), false, kCursorTake, 0);
	_app->objectAddPuzzleAccessibility(kObjectDiaryOfASeducer, kPuzzle81403, Common::Rect(305, 278, 512, 422), true, kCursorTake, 1);
	_app->objectAddPresentation(kObjectDiaryOfASeducer);
	_app->objectPresentationAddImageToPuzzle(kObjectDiaryOfASeducer, 0, kPuzzle81403, "a08s04n02p02l01.bmp", Common::Point(10, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObjectDiaryOfASeducer);
	_app->objectPresentationAddImageToRotation(kObjectDiaryOfASeducer, 1, 84011, 0);
	_app->objectAddPresentation(kObjectDiaryOfASeducer);
	_app->objectPresentationAddImageToRotation(kObjectDiaryOfASeducer, 2, 84021, 4);
	_app->objectAdd(kObject81408, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject81408, kPuzzle81405, Common::Rect(94, 77, 523, 418), false, kCursorZoom, 0);
	_app->objectAdd(kObject81900, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject81900, kPuzzle81303, Common::Rect(135, 281, 371, 410), true, kCursorIdle, 0);
	_app->objectAddPuzzleAccessibility(kObject81900, kPuzzle81304, Common::Rect(256,  33, 550, 154), true, kCursorIdle, 1);
	_app->objectAddPuzzleAccessibility(kObject81900, kPuzzle81305, Common::Rect(236,  68, 503, 232), true, kCursorIdle, 2);
	_app->objectAddPuzzleAccessibility(kObject81900, kPuzzle81306, Common::Rect(245,  70, 497, 220), true, kCursorIdle, 3);
	_app->objectAddPuzzleAccessibility(kObject81900, kPuzzle81214, Common::Rect(148, 140, 501, 259), true, kCursorIdle, 4);
	_app->objectAdd(kObject81901, "", "", 1);
	_app->objectAddRotationAccessibility(kObject81901, 82021, Common::Rect(2109, 259, 2153, 299), true, kCursorAction, 0);
	_app->objectAddPresentation(kObject81901);
	_app->objectPresentationAddAnimationToRotation(kObject81901, 0, 82011, 0, 20, 12.5f, 6);
	_app->objectAddPresentation(kObject81901);
	_app->objectPresentationAddAnimationToRotation(kObject81901, 1, 82021, 1, 20, 12.5f, 6);
	_app->objectAddPresentation(kObject81901);
	_app->objectPresentationAddAnimationToRotation(kObject81901, 2, 82041, 0, 20, 12.5f, 6);
	_app->objectAddPresentation(kObject81901);
	_app->objectPresentationAddAnimationToRotation(kObject81901, 3, 82051, 0, 20, 12.5f, 6);
	_app->objectAdd(kObject81902, "", "", 1);
	_app->objectAddPresentation(kObject81902);
	_app->objectPresentationAddAnimationToRotation(kObject81902, 0, 83021, 6, 20, 12.5f, 6);
	_app->objectAddPresentation(kObject81902);
	_app->objectPresentationAddAnimationToRotation(kObject81902, 0, 83031, 1, 20, 12.5f, 6);
	_app->objectAddPresentation(kObject81902);
	_app->objectPresentationAddAnimationToRotation(kObject81902, 0, 83041, 10, 20, 12.5f, 6);
	_app->objectAdd(kObject81904, "", "", 1);
	_app->objectAddPresentation(kObject81904);
	_app->objectPresentationAddAnimationToRotation(kObject81904, 0, 83011, 1, 30, 12.5f, 5);
	_app->objectAddPresentation(kObject81904);
	_app->objectPresentationAddAnimationToRotation(kObject81904, 1, 83011, 3, 30, 12.5f, 5);
	_app->objectAddPresentation(kObject81904);
	_app->objectPresentationAddAnimationToRotation(kObject81904, 2, 83011, 4, 30, 12.5f, 5);
	_app->objectPresentationShow(kObject81904, 0);
	_app->objectPresentationShow(kObject81904, 1);
	_app->objectAdd(kObject81903, "", "", 1);
	_app->objectAddPresentation(kObject81903);
	_app->objectPresentationAddAnimationToRotation(kObject81903, 0, 83021, 7, 30, 12.5f, 5);
	_app->objectAddPresentation(kObject81903);
	_app->objectPresentationAddAnimationToRotation(kObject81903, 1, 83031, 7, 30, 12.5f, 5);
	_app->objectAddPresentation(kObject81903);
	_app->objectPresentationAddAnimationToRotation(kObject81903, 2, 83041, 9, 30, 12.5f, 5);
	_app->objectPresentationShow(kObject81903);
	_app->soundAdd(81107, kSoundTypeBackgroundMusic, "08_BGR_s01.wac", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(81107, 90);
	_app->soundAdd(81223, kSoundTypeBackgroundMusic, "08_BGR_s02.wac", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(81223, 90);
	_app->soundAdd(81310, kSoundTypeBackgroundMusic, "08_BGR_s03.wac", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(81310, 90);
	_app->soundAdd(81101, kSoundTypeAmbientMusic, "08_waves1.was", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->rotationAddAmbientSound(81011, 81101, 100, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(81021, 81101, 95, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(81031, 81101, 98, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(81041, 81101, 93, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(82011, 81101, 88, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(82021, 81101, 85, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(82031, 81101, 85, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(82041, 81101, 85, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(82051, 81101, 85, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(82061, 81101, 85, 0, 1, 1, 10);
	_app->soundAdd(81419, kSoundTypeAmbientMusic, "08_sex.WAS", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->rotationAddAmbientSound(84011, 81419, 90, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(84021, 81419, 90, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle81401, 81419, 90, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle81402, 81419, 90, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle81403, 81419, 90, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle81404, 81419, 90, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle81405, 81419, 90, 0, 1, 1, 10);
	_app->soundAdd(81415, kSoundTypeEffect, "08_scream01.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81416, kSoundTypeEffect, "08_scream02.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81417, kSoundTypeEffect, "08_scream03.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81418, kSoundTypeEffect, "08_scream04.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81204, kSoundTypeEffect, "08_Navijanje.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81301, kSoundTypeEffect, "08_drsno_odpiranje2.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81230, kSoundTypeEffect, "08_air_release.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(81230, 90);
	_app->soundAdd(81306, kSoundTypeEffect, "08_automaton_bow.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81302, kSoundTypeEffect, "08_stopanje_na_strozak_wood.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81403, kSoundTypeEffect, "08_foto_unfold.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81402, kSoundTypeEffect, "08_foto_fold.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81202, kSoundTypeEffect, "08_open_trap_door.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81201, kSoundTypeEffect, "08_ura.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81203, kSoundTypeEffect, "08_kuku.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81206, kSoundTypeEffect, "08_open_box.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81205, kSoundTypeEffect, "08_close_box.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81207, kSoundTypeEffect, "08_take_needle.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81208, kSoundTypeEffect, "08_take_pencil.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81209, kSoundTypeEffect, "08_take_paper_newsclip.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81210, kSoundTypeEffect, "08_put_paper_newsclip.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81211, kSoundTypeEffect, "08_switch.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81213, kSoundTypeEffect, "08_diasi_put.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81214, kSoundTypeEffect, "08_switch_mirror.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81303, kSoundTypeEffect, "08_stopanje_na_strozak_wood2.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(81303, 93);
	_app->soundAdd(81304, kSoundTypeEffect, "08_switch_mermaids.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81305, kSoundTypeEffect, "08_put_wig.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81307, kSoundTypeEffect, "08_auto_predal.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81308, kSoundTypeEffect, "08_key_take.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81309, kSoundTypeEffect, "08_open_closet_under_bed.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81215, kSoundTypeEffect, "08_unlock_clock.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81404, kSoundTypeEffect, "08_take_bulbs.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81405, kSoundTypeEffect, "08_bulb_screw.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81406, kSoundTypeEffect, "08_bulb_unscrew.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81407, kSoundTypeEffect, "08_open_osvetljevalec.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81408, kSoundTypeEffect, "08_close_osvetljevalec.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81409, kSoundTypeEffect, "08_switch_osvetlj.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81410, kSoundTypeEffect, "08_electricity.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(81410, 90);
	_app->soundAdd(81411, kSoundTypeEffect, "08_paper_polaganje_pacta.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81412, kSoundTypeEffect, "08_paper_pobiranje_pacta.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81413, kSoundTypeEffect, "08_take_suicide_paper.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81414, kSoundTypeEffect, "08_take_book.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81216, kSoundTypeEffect, "08_take_1st_from_frame.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81311, kSoundTypeEffect, "08_WC_open_omarca.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81312, kSoundTypeEffect, "08_WC_close_omarca_start.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81313, kSoundTypeEffect, "08_WC_close_omarca_end.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81314, kSoundTypeEffect, "08_WC_open_vratca.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81315, kSoundTypeEffect, "08_WC_close_vratca_start.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81316, kSoundTypeEffect, "08_WC_close_vratca_end.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81224, kSoundTypeEffect, "08_close_mirror.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81225, kSoundTypeEffect, "08_close_closet_z_leco.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81226, kSoundTypeEffect, "08_take_wig.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81227, kSoundTypeEffect, "08_take_key.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81319, kSoundTypeEffect, "08_book_put.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81320, kSoundTypeEffect, "08_book_take.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81231, kSoundTypeEffect, "08_air_release.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(81231, 90);
	_app->soundAdd(81232, kSoundTypeEffect, "08_air_release.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(81232, 90);
	_app->soundAdd(81233, kSoundTypeEffect, "08_air_release.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(81233, 90);
	_app->soundAdd(81234, kSoundTypeEffect, "08_air_release.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(81234, 90);
	_app->soundAdd(81235, kSoundTypeEffect, "08_air_release.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(81235, 90);
	_app->soundAdd(81321, kSoundTypeEffect, "08_compass_put.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81236, kSoundTypeEffect, "08_press_key.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(81401, kSoundTypeAmbientEffect, "08_faceless_vibrating.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->rotationAdd3DSound(84011, 81401, 1, 1, 15, 85, 347.0f, 10);
	_app->rotationAdd3DSound(84021, 81401, 1, 1, 15, 95, 339.0f, 10);
	_app->rotationSet3DSoundOff(84011, 81401);
	_app->rotationSet3DSoundOff(84021, 81401);
	_app->soundAdd(81318, kSoundTypeAmbientEffect, "08_water_dripping2.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->rotationAdd3DSound(83021, 81318, 1, 1, 15, 80, 245.0f, 10);
	_app->rotationAdd3DSound(83031, 81318, 1, 1, 15, 80, 219.0f, 10);
	_app->rotationAdd3DSound(83041, 81318, 1, 1, 15, 85, 226.0f, 10);
	_app->puzzleAdd3DSound(81301, 81318, 1, 1, 15, 75, 333.0f, 10);
	_app->puzzleAdd3DSound(81302, 81318, 1, 1, 15, 70, 392.0f, 10);
	_app->puzzleAdd3DSound(81303, 81318, 1, 1, 15, 70, 270.0f, 10);
	_app->puzzleAdd3DSound(81304, 81318, 1, 1, 15, 70, 90.0f, 10);
	_app->puzzleAdd3DSound(81305, 81318, 1, 1, 15, 70, 270.0f, 10);
	_app->puzzleAdd3DSound(81306, 81318, 1, 1, 15, 70, 90.0f, 10);
	_app->puzzleAdd3DSound(81307, 81318, 1, 1, 15, 75, 342.0f, 10);
	_app->puzzleAdd3DSound(81308, 81318, 1, 1, 15, 70, 180.0f, 10);
	_app->soundAdd(81102, kSoundTypeAmbientEffect, "08_bird.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(81317, kSoundTypeAmbientEffect, "08_water_dripping.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->rotationAdd3DSound(83021, 81317, 1, 1, 15, 70, 270.0f, 10);
	_app->rotationAdd3DSound(83031, 81317, 1, 1, 15, 70, 219.0f, 10);
	_app->rotationAdd3DSound(83041, 81317, 1, 1, 15, 75, 0.0f, 10);
	_app->puzzleAdd3DSound(81301, 81317, 1, 1, 15, 75, 333.0f, 10);
	_app->puzzleAdd3DSound(81302, 81317, 1, 1, 15, 70, 392.0f, 10);
	_app->puzzleAdd3DSound(81303, 81317, 1, 1, 15, 70, 270.0f, 10);
	_app->puzzleAdd3DSound(81304, 81317, 1, 1, 15, 70, 90.0f, 10);
	_app->puzzleAdd3DSound(81305, 81317, 1, 1, 15, 70, 270.0f, 10);
	_app->puzzleAdd3DSound(81306, 81317, 1, 1, 15, 70, 90.0f, 10);
	_app->puzzleAdd3DSound(81307, 81317, 1, 1, 15, 75, 342.0f, 10);
	_app->puzzleAdd3DSound(81308, 81317, 1, 1, 15, 70, 180.0f, 10);
	_app->soundAdd(81103, kSoundTypeAmbientEffect, "08_bird_LtoR.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(81217, kSoundTypeAmbientEffect, "08_bubbles01.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(81218, kSoundTypeAmbientEffect, "08_bubbles02.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(81219, kSoundTypeAmbientEffect, "08_bubbles03.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(81220, kSoundTypeAmbientEffect, "08_bubbles04.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(81221, kSoundTypeAmbientEffect, "08_bubbles05.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(81222, kSoundTypeAmbientEffect, "08_bubbles06.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(81212, kSoundTypeAmbientEffect, "08_neonka.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundSetVolume(81212, 90);
	_app->soundAdd(81104, kSoundTypeAmbientEffect, "08_frog1.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(81105, kSoundTypeAmbientEffect, "08_frog2.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(81106, kSoundTypeAmbientEffect, "08_frog3.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(81001, kSoundTypeDialog, "e03_02_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81015, kSoundTypeDialog, "e03_17_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81017, kSoundTypeDialog, "e03_19_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81026, kSoundTypeDialog, "e03_29_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81028, kSoundTypeDialog, "e03_31_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81042, kSoundTypeDialog, "E03_38_title.WAV", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81002, kSoundTypeDialog, "E03_03_Fra.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81003, kSoundTypeDialog, "E03_04_Pu1.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81004, kSoundTypeDialog, "E03_05_Pu2.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81005, kSoundTypeDialog, "E03_06_Pu3.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81006, kSoundTypeDialog, "E03_07_FF.waC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81007, kSoundTypeDialog, "E03_08_FM.waC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81008, kSoundTypeDialog, "E03_09_Fra.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81009, kSoundTypeDialog, "E03_10_Fra.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81010, kSoundTypeDialog, "E03_11_Mar.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81011, kSoundTypeDialog, "E03_12_Hom.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81012, kSoundTypeDialog, "E03_13_Fra.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81013, kSoundTypeDialog, "E03_14_Fra.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81014, kSoundTypeDialog, "E03_15_poem.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81016, kSoundTypeDialog, "E03_18_Fra.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81018, kSoundTypeDialog, "E03_20_Fra.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81019, kSoundTypeDialog, "E03_21_Fra.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81020, kSoundTypeDialog, "E03_23_Fra.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81021, kSoundTypeDialog, "E03_24_Pu1.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81022, kSoundTypeDialog, "E03_25_Pu2.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81023, kSoundTypeDialog, "E03_26_Pu3.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81024, kSoundTypeDialog, "E03_27_FF.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81025, kSoundTypeDialog, "E03_28_FM.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81027, kSoundTypeDialog, "E03_30_Hom.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81029, kSoundTypeDialog, "E03_32_Hom.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81030, kSoundTypeDialog, "E03_34_1Fra.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81031, kSoundTypeDialog, "E03_34_2Mef.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81032, kSoundTypeDialog, "E03_35_Fra.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81033, kSoundTypeDialog, "E03_36_Fra.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81034, kSoundTypeDialog, "E03_37_Fra.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81035, kSoundTypeDialog, "E03_39_Fra.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81036, kSoundTypeDialog, "E03_41_Fra.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81037, kSoundTypeDialog, "E03_42_pact.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81039, kSoundTypeDialog, "E03_44_letter.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81040, kSoundTypeDialog, "E03_45_Mef.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(81041, kSoundTypeDialog, "E03_40_Cin.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->varDefineByte(81003, 1);
	_app->varDefineByte(81001, 0);
	_app->varDefineByte(81002, 0);
	_app->varDefineByte(81004, 0);
	_app->varDefineByte(81005, 0);
	_app->varDefineByte(81006, 0);
	_app->varDefineByte(81007, 0);
	_app->varDefineByte(81008, 0);
	_app->varDefineByte(81009, 3);
	_app->varDefineByte(81010, 0);
	_app->varDefineByte(81011, 0);
	_app->varDefineByte(81012, 0);
	_app->varDefineByte(81022, 0);
	_app->varDefineByte(81013, 0);
	_app->varDefineByte(81014, 0);
	_app->varDefineByte(81015, 0);
	_app->varDefineByte(81016, 0);
	_app->varDefineByte(81017, 0);
	_app->varDefineByte(81018, 0);
	_app->varDefineByte(81019, 0);
	_app->varDefineByte(81020, 0);
	_app->varDefineByte(81021, 0);
	_app->varDefineByte(81023, 0);
	_app->varDefineByte(81024, 0);
	_app->varDefineByte(81025, 0);
	_app->varDefineByte(81026, 0);
	_app->varDefineByte(81027, 0);
	_app->varDefineByte(81028, 0);
	_app->varDefineByte(81029, 0);
	_app->varDefineByte(81030, 0);
	_app->varDefineByte(81031, 0);
	_app->varDefineFloat(81001, 0.0f);
	_app->objectPresentationShow(kObject81203, (uint32)_app->varGetFloat(81001));
	_app->varDefineFloat(81002, 10.0f);
	_app->objectPresentationShow(kObject81202, (uint32)_app->varGetFloat(81002));
	_app->varDefineFloat(81003, 1.0f);
	_app->varDefineFloat(81004, 0.0f);
	_app->varDefineFloat(81005, 0.0f);
	_app->varDefineString(81001, "00000");
	_app->varDefineDword(81002, 0);
	_app->varDefineDword(81003, 0);
	_app->varDefineDword(81004, 0);
	_app->varDefineDword(81001, 0);
}

void Zone12Faust::onTimer(TimerId id) {
	switch (id) {
	default:
		break;

	case kTimer0:
		if (_app->varGetFloat(81001) == 0.0f) {
			_app->timerStop(kTimer0);

			if (!_app->hasTimer(kTimer1)) {
				_app->objectSetAccessibilityOn(kObject81201);
				_app->objectSetAccessibilityOn(kObject81202);
				_app->rotationSetAlp(82021, 152.0f);
				_app->rotationSetBet(82021, 0);
				_app->rotationSetRan(82021, 87.0f);
				_app->rotationSetActive(82021);
				_app->soundStop(81204, 1024);
				_app->objectPresentationShow(kObject81221, 1);
			}
		} else {
			_app->varSetFloat(81001, _app->varGetFloat(81001) - 1.0f);
			if (_app->varGetFloat(81001) < 0.0f)
				_app->varSetFloat(81001, 0);

			_app->objectPresentationHide(kObject81203);
			_app->objectPresentationShow(kObject81203, (uint32)_app->varGetFloat(81001));

			if (_app->varGetFloat(81001) != 25.0f
				&& _app->varGetFloat(81001) != 50.0f)
				break;

			_app->soundPlay(81203);
		}
		break;

	case kTimer1:
		if (_app->varGetFloat(81002) == 10.0f) {
			_app->timerStop(kTimer1);

			if (!_app->hasTimer(kTimer0)) {
				_app->objectSetAccessibilityOn(kObject81201);
				_app->objectSetAccessibilityOn(kObject81202);
				_app->rotationSetAlp(82021, 152.0f);
				_app->rotationSetBet(82021, 0);
				_app->rotationSetRan(82021, 87.0f);
				_app->rotationSetActive(82021);
				_app->soundStop(81204, 1024);
				_app->objectPresentationShow(kObject81221, 1);
			}
		} else {
			_app->varSetFloat(81002, _app->varGetFloat(81002) + 1.0f);
			if (_app->varGetFloat(81002) > 59.0f)
				_app->varSetFloat(81002, 0);

			_app->objectPresentationHide(kObject81202);
			_app->objectPresentationShow(kObject81202, (uint32)_app->varGetFloat(81002));


			if (_app->varGetFloat(81002) != 25.0f
				&& _app->varGetFloat(81002) != 50.0f)
				break;

			_app->soundPlay(81203);
		}
		break;

	case kTimer2:
		_app->objectPresentationHide(kObject81404, 1);
		_app->timerStop(kTimer2);

		if (_app->varGetByte(81007) == 1) {
			_app->objectPresentationHide(kObject81404);
			_app->objectPresentationShow(kObject81404, 0);
			_app->timerStart(kTimer3, 100);
			_app->varSetByte(81007, 0);
		} else {
			_app->objectPresentationHide(kObject81404);
			_app->rotationSetAlp(84021, 53.0f);
			_app->rotationSetBet(84021, 0);
			_app->rotationSetRan(84021, 87.0f);
			_app->rotationSetActive(84021);

			if (_app->varGetByte(81006) == 1)
				_app->soundPlay(81409);

			_app->soundStop(81410, 1024);
			_app->varSetByte(81006, 0);
		}

		if (_app->varGetByte(81012) == 1
		 && _app->varGetByte(81022) == 1
		 && _app->bagHas(kObjectDiaryOfASeducer)) {
			_app->soundStopAll(1024);
			_app->exitToMenu(kMenuAction0);
		}
		break;

	case kTimer3:
		_app->objectPresentationHide(kObject81404, 0);
		_app->bagAdd(81207);
		_app->timerStop(kTimer3);
		_app->rotationSetAlp(84021, 53.0f);
		_app->rotationSetBet(84021, 0);
		_app->rotationSetRan(84021, 87.0f);
		_app->rotationSetActive(84021);

		if (_app->varGetByte(81006) == 1)
			_app->soundPlay(81409);
		_app->soundStop(81410, 1024);
		_app->varSetByte(81006, 0);
		break;

	case kTimer4:
		_app->objectPresentationHide(kObject81306, _app->varGetByte(81021));
		_app->timerStop(kTimer4);
		break;

	case kTimer5:
		if (floor(_app->varGetFloat(81005)) == 0.0f
		 && floor(_app->varGetFloat(81004)) == 0.0f) {
			 _app->soundStop(81301, 1024);
			 _app->timerStop(kTimer5);
			 _app->rotationSetAlp(83031, 180.0f);
			 _app->rotationSetBet(83031, -26.0f);
			 _app->rotationSetRan(83031, 87.0f);
			 _app->rotationSetActive(83031);
			 break;
		}

		if (floor(_app->varGetFloat(81005)) != 0.0f) {
			_app->varSetFloat(81005, _app->varGetFloat(81005) - 1.0f);
			_app->objectPresentationHide(kObject81308);
			_app->objectPresentationShow(kObject81308, (uint32)_app->varGetFloat(81005));
		}

		if (floor(_app->varGetFloat(81004)) != 0.0f) {
			_app->varSetFloat(81004, _app->varGetFloat(81004) - 1.0f);
			_app->objectPresentationHide(kObject81309);
			_app->objectPresentationShow(kObject81309, (uint32)_app->varGetFloat(81004));
		}
		break;

	case kTimer6:
		_app->timerStop(kTimer6);
		_app->objectPresentationHide(kObject81303, 6);
		_app->objectPresentationHide(kObject81303, 8);
		_app->rotationSetAlp(83031, 334.0f);
		_app->rotationSetBet(83031, 16.0f);
		_app->rotationSetRan(83031, 87.0f);
		_app->rotationSetActive(83031);
		break;

	case kTimer7: {
		_app->timerStop(kTimer7);
		_app->timerStart(kTimer7, rnd(15000) + 15000);

		Id soundId = 81102 + rnd(2);
		_app->soundSetVolume(soundId, rnd(10) + 90);
		_app->soundSetPan(soundId, rnd(10) - 10);
		_app->soundPlay(soundId);
		}
		break;

	case kTimer8: {
		_app->timerStop(kTimer8);
		_app->timerStart(kTimer8, rnd(3000) + 6000);
		Id soundId = 81104 + rnd(3);
		_app->soundSetVolume(soundId, rnd(10) + 90);
		_app->soundSetPan(soundId, rnd(10) - 10);
		_app->soundPlay(soundId);
		}
		break;

	case kTimer9: {
		_app->timerStop(kTimer9);
		_app->timerStart(kTimer9, rnd(5000) + 5000);

		Id soundId = 81415 + rnd(4);
		_app->soundSetVolume(soundId, rnd(10) + 90);
		_app->soundSetPan(soundId, rnd(10) - 10);
		_app->soundPlay(soundId);
		}
		break;

	case kTimer10: {
		_app->timerStop(kTimer10);
		_app->timerStart(kTimer10, rnd(10000) + 5000);

		_app->objectPresentationShow(kObject81901);
		if (!_app->varGetByte(81023))
			_app->objectPresentationShow(kObject81902);

		Id soundId = 81217 + rnd(6);
		_app->soundSetVolume(soundId, 80 + rnd(10));
		_app->soundPlay(soundId);
		}
		break;

	case kTimer11:
		_app->objectPresentationHide(kObject81222);
		_app->timerStop(kTimer11);
		break;
	}
}

// FAUST.EXE 0x494e10
void Zone12Faust::onButtonUp(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, const Common::Point &point) {
	_app->objectPresentationHide(kObject25);

	switch (id) {
	default:
		break;

	case kObject81202:
		if (_app->bagHasClickedObject()) {
			if (target == 1 && _app->bagGetClickedObject() == kObjectKey3) {
				_app->soundPlay(81215);
				_app->objectPresentationShow(kObject81221, 0);
			}

			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->objectSetAccessibilityOff(kObject81201);
			_app->objectSetAccessibilityOff(kObject81202);
			_app->soundPlay(81204, kSoundLoop);
			_app->timerStart(kTimer0, 50);
			_app->timerStart(kTimer1, 100);
		}
		break;

	case kObject81204:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->puzzleSetActive(kPuzzle81214);
			_app->soundPlay(_app->varGetByte(81003) == 1 ? 81002 : 81020);
		} else if (target >= 1 && target <= 5) {
			_app->objectPresentationShow(kObject81204, 1);
			_app->objectPresentationHide(kObject81204, 0);
			_app->objectPresentationHide(kObject81204, 2);
			_app->bagAdd(kObjectFrankFirstPrize);
			if (target == 1)
				advanceProgress();
			_app->playMovie("A08S02N06A03");
			_app->soundPlay(81216);
			_app->objectSetAccessibilityOff(kObject81204);

			if (target != 1)
				setRotation(82061, 353.0f, 0.0f);
		}
		break;

	case kObject81205:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->puzzleSetActive(kPuzzle81220);
			_app->soundPlay(_app->varGetByte(81003) == 1 ? 81007 : 81025);
		} else if (target == 1) {
			_app->puzzleSetActive(kPuzzle81220);
			_app->soundPlay(_app->varGetByte(81003) == 1 ? 81006 : 81024);
		}
		break;

	case kObject81206:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 0:
		case 3:
			saveRotation();
			_app->puzzleSetActive(kPuzzle81216);
			_app->soundPlay(_app->varGetByte(81003) == 1 ? 81003 : 81021);
			break;

		case 1:
		case 4:
			saveRotation();
			_app->puzzleSetActive(kPuzzle81217);
			_app->soundPlay(_app->varGetByte(81003) == 1 ? 81004 : 81022);
			break;

		case 2:
		case 5:
			saveRotation();
			_app->puzzleSetActive(kPuzzle81218);
			_app->soundPlay(_app->varGetByte(81003) == 1 ? 81005 : 81023);
			break;

		case 6:
		case 7:
		case 8:
			// Back to the rotation saved by saveRotation()
			setRotation(_app->varGetDword(81002), (float)_app->varGetDword(81003), (float)_app->varGetDword(81004));
			break;
		}
		break;

	case kObject81208:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 0:
			_app->objectPresentationShow(kObject81208, 0);
			_app->objectSetAccessibilityOff(kObject81208, 0, 0);
			_app->soundPlay(81206);
			break;

		case 1:
			if (_app->varGetByte(81008) == 0) {
				_app->objectPresentationHide(kObject81208);
				_app->objectPresentationShow(kObject81208, 1);
				setRotation(82031, 118.0f, 16.0f);
				_app->soundPlay(81205);
				break;
			}

			_app->objectPresentationHide(kObject81208, 2);
			_app->objectPresentationHide(kObject81208, 3);
			_app->objectPresentationHide(kObject81220);
			_app->objectSetAccessibilityOff(kObject81220, 0, 2);
			_app->objectSetAccessibilityOn(kObject81220, 3, 3);
			_app->soundStop(81008, 1024);
			_app->soundStop(81027, 1024);
			_app->soundStop(81029, 1024);
			_app->varSetByte(81008, 0);
			_app->objectSetAccessibilityOn(kObject81208, 2, 2);
			_app->soundPlay(81210);
			if (!_app->bagHas(kObjectThinPencil))
				_app->objectSetAccessibilityOn(kObject81208, 3, 3);
			break;

		case 3:
			_app->objectPresentationShow(kObject81208, _app->bagHas(kObjectCompassNeedle) ? 3 : 2);
			_app->varSetByte(81008, 1);
			_app->objectSetAccessibilityOff(kObject81208, 2, 4);
			_app->objectSetAccessibilityOn(kObject81208, 4, 4);
			_app->soundPlay(81208);
			break;

		case 4:
			if (!_app->bagHas(kObjectCompassNeedle)) {
				_app->objectPresentationHide(kObject81208, 2);
				_app->objectPresentationShow(kObject81208, 3);
				_app->bagAdd(kObjectCompassNeedle);
				advanceProgress();
				_app->soundPlay(81207);
			} else {
				_app->objectPresentationHide(kObject81208, 3);
				_app->bagAdd(kObjectThinPencil);
				_app->objectSetAccessibilityOn(kObject81208, 2, 2);
				_app->objectSetAccessibilityOff(kObject81208, 4, 4);
				_app->varSetByte(81008, 0);
			}
			break;
		}
		break;

	case kObject81211:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 0:
			_app->objectPresentationHide(kObject81211);
			_app->playMovie("A08S02N03A01");
			_app->varSetByte(81030, 1);
			if (_app->varGetByte(81003) == 2)
				_app->objectSetAccessibilityOn(kObject81211, 4, 5);

			if (_app->varGetByte(81009) == 0) {
				_app->objectPresentationShow(kObject81211, 0);
				_app->objectSetAccessibilityOff(kObject81211, 0, 0);
				_app->objectSetAccessibilityOn(kObject81211, 1, 3);
			}

			if (_app->varGetByte(81009) == 1) {
				_app->objectPresentationShow(kObject81211, 2);
				_app->objectSetAccessibilityOff(kObject81211, 0, 0);
				_app->objectSetAccessibilityOn(kObject81211, 1, 2);
			}

			if (_app->varGetByte(81009) == 2) {
				_app->objectPresentationShow(kObject81211, 3);
				_app->objectSetAccessibilityOff(kObject81211, 0, 0);
				_app->objectSetAccessibilityOn(kObject81211, 1, 1);
				_app->objectSetAccessibilityOn(kObject81211, 3, 3);
			}

			if (_app->varGetByte(81009) == 3) {
				_app->objectPresentationShow(kObject81211, 1);
				_app->objectSetAccessibilityOff(kObject81211, 0, 0);
				_app->objectSetAccessibilityOn(kObject81211, 1, 1);
			}
			break;

		case 1:
			_app->playMovie("A08S02N03A02");
			_app->varSetByte(81030, 0);
			_app->soundPlay(81225);
			_app->objectPresentationHide(kObject81211);
			_app->objectSetAccessibilityOn(kObject81211, 0, 0);
			_app->objectSetAccessibilityOff(kObject81211, 1, 5);
			break;

		case 2:
			// Take the box of slides
			_app->objectPresentationHide(kObject81211);
			if (_app->varGetByte(81009) == 1) {
				_app->objectPresentationShow(kObject81211, 1);
				_app->varSetByte(81009, 3);
			} else {
				_app->objectPresentationShow(kObject81211, 3);
				_app->varSetByte(81009, 2);
			}
			_app->objectSetAccessibilityOff(kObject81211, 2, 2);
			_app->bagAdd(kObjectBoxOfSlides);
			_app->soundPlay(81227);
			break;

		case 3:
			// Take the magnifying glass
			_app->objectPresentationHide(kObject81211);
			if (_app->varGetByte(81009) == 2) {
				_app->objectPresentationShow(kObject81211, 1);
				_app->varSetByte(81009, 3);
			} else {
				_app->objectPresentationShow(kObject81211, 2);
				_app->varSetByte(81009, 1);
			}
			_app->objectSetAccessibilityOff(kObject81211, 3, 3);
			_app->bagAdd(kObjectMagnifyingGlass);
			_app->soundPlay(81308);
			break;
		}
		break;

	case kObject81215:
		// Slide projector: var 81010 = lamp on, var 81011 = slides loaded
		if (_app->bagHasClickedObject()) {
			if (target == 1) {
				if (_app->bagGetClickedObject() == kObjectBoxOfSlides) {
					_app->objectPresentationShow(kObject81215, _app->varGetByte(81010) == 0 ? 0 : 2);
					_app->varSetByte(81011, 1);
					_app->bagRemove(kObjectBoxOfSlides);
					_app->objectSetAccessibilityOff(kObject81215, 1, 1);
					_app->objectSetAccessibilityOn(kObject81215, 2, 9);
					_app->soundPlay(81213);
				}

				_app->cursorDelete();
				break;
			}

			// The original doesn't delete the cursor for the other targets
			if (target >= 2 && target <= 9 && _app->bagGetClickedObject() == kObjectMagnifyingGlass) {
				_app->puzzleSetActive((PuzzleId)(81204 + target));
				if (_app->varGetByte(81010) == 1)
					_app->soundSetVolume(81212, 95);
			}
		} else {
			if (target == 0) {
				if (_app->varGetByte(81010) == 0) {
					_app->objectPresentationHide(kObject81215);
					_app->objectPresentationShow(kObject81215, _app->varGetByte(81011) == 0 ? 1 : 2);
					_app->varSetByte(81010, 1);
					_app->objectPresentationHide(kObject81216);
					_app->soundPlay(81211);
					_app->soundPlay(81212, kSoundLoop);
				} else {
					_app->objectPresentationHide(kObject81215);
					if (_app->varGetByte(81011) != 0)
						_app->objectPresentationShow(kObject81215, 0);
					_app->varSetByte(81010, 0);
					_app->objectPresentationShow(kObject81216);
					_app->soundPlay(81211);
					_app->soundStop(81212, 1024);
				}
				break;
			}

			if (target >= 2 && target <= 9) {
				// Take the slides back
				_app->objectPresentationHide(kObject81215);
				if (_app->varGetByte(81010) != 0)
					_app->objectPresentationShow(kObject81215, 1);
				_app->varSetByte(81011, 0);
				_app->bagAdd(kObjectBoxOfSlides);
				_app->objectSetAccessibilityOn(kObject81215, 1, 1);
				_app->objectSetAccessibilityOff(kObject81215, 2, 9);
			}
		}

		if (target >= 10 && target <= 17) {
			_app->puzzleSetActive(kPuzzle81205);
			if (_app->varGetByte(81010) == 1)
				_app->soundSetVolume(81212, 90);
		}
		break;

	case kObject81217:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 0:
			if (_app->varGetByte(81013) == 0) {
				_app->objectPresentationShow(kObject81217, 0);
				_app->varSetByte(81013, 1);
				_app->soundPlay(81214);
				break;
			}

			if (_app->varGetByte(81003) == 1 && !_app->bagHas(kObjectLittleWig)) {
				_app->objectPresentationHide(kObject81217);
				_app->objectPresentationShow(kObject81217, 1);
				_app->objectSetAccessibilityOn(kObject81217, 1, 1);
				_app->playMovie("A08S02N06A01");
				_app->soundPlay(81009);
			} else if (_app->varGetByte(81003) != 1 && !_app->bagHas(kObjectKey3)) {
				_app->objectPresentationHide(kObject81217);
				_app->objectPresentationShow(kObject81217, 2);
				_app->objectSetAccessibilityOn(kObject81217, 2, 2);
				_app->playMovie("A08S02N06A02");
				_app->soundPlay(81030);
			} else {
				_app->playMovie("A08S02N06A05");
				_app->objectPresentationHide(kObject81217);
				_app->objectPresentationShow(kObject81217, 3);
			}

			_app->objectSetAccessibilityOff(kObject81217, 0, 0);
			_app->objectSetAccessibilityOn(kObject81217, 3, 3);
			_app->varSetByte(81031, 1);
			break;

		case 1:
			_app->puzzleSetActive(kPuzzle81215);
			break;

		case 2:
			_app->objectPresentationHide(kObject81217);
			_app->objectPresentationShow(kObject81217, 4);
			_app->puzzleSetActive(kPuzzle81215);
			break;

		case 3:
			_app->playMovie("A08S02N06A04");
			_app->soundPlay(81224);
			_app->objectPresentationHide(kObject81217);
			_app->objectSetAccessibilityOff(kObject81217, 0, 3);
			_app->objectSetAccessibilityOn(kObject81217, 0, 0);
			_app->varSetByte(81013, 0);
			_app->varSetByte(81031, 0);
			break;

		case 4:
			_app->objectPresentationHide(kObject81217);
			_app->objectPresentationShow(kObject81217, 3);
			_app->objectPresentationShow(kObject81217, 5);
			_app->objectSetAccessibilityOff(kObject81217, 1, 1);
			_app->objectSetAccessibilityOff(kObject81217, 4, 4);
			_app->bagAdd(kObjectLittleWig);
			_app->soundPlay(81226);
			break;

		case 5:
			_app->objectPresentationHide(kObject81217);
			_app->objectPresentationShow(kObject81217, 3);
			_app->objectPresentationShow(kObject81217, 5);
			_app->objectSetAccessibilityOff(kObject81217, 2, 2);
			_app->objectSetAccessibilityOff(kObject81217, 5, 5);
			_app->bagAdd(kObjectKey3);
			_app->soundPlay(81227);
			break;
		}
		break;

	case kObject81220:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->varSetByte(81008, 1);
		_app->objectSetAccessibilityOff(kObject81208, 2, 4);

		switch (target) {
		default:
			break;

		case 3:
			_app->objectPresentationHide(kObject81220);
			_app->objectSetAccessibilityOff(kObject81220, 3, 3);
			_app->objectSetAccessibilityOn(kObject81220, 0, 0);
			_app->objectPresentationShow(kObject81220, 0);
			if (_app->varGetByte(81003) == 2) {
				_app->objectSetAccessibilityOn(kObject81220, 0, 2);
				_app->objectPresentationShow(kObject81220, 1);
				_app->objectPresentationShow(kObject81220, 2);
			}
			break;

		case 0:
		case 1:
		case 2:
			_app->soundPlay(81209);
			_app->soundPlay(target == 0 ? 81008 : (target == 1 ? 81027 : 81029));
			_app->objectPresentationHide(kObject81220);
			_app->objectPresentationShow(kObject81220, 3 * target);
			if (_app->varGetByte(81003) == 2) {
				_app->objectPresentationShow(kObject81220, 3 * target + 1);
				_app->objectPresentationShow(kObject81220, 3 * target + 2);
			}
			break;
		}
		break;

	case kObject81222:
		// Clock: target 0 = hours (var 81029, 1..12), target 1 = minutes (var 81028, 1..59), target 2 = check
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->soundPlay(81236);
		_app->timerStart(kTimer11, 50);

		if (target == 0) {
			_app->objectPresentationShow(kObject81222, 0);
			_app->varSetByte(81029, _app->varGetByte(81029) + 1);
			if ((int8)_app->varGetByte(81029) > 12)
				_app->varSetByte(81029, 1);
		} else if (target == 1) {
			_app->objectPresentationShow(kObject81222, 1);
			_app->varSetByte(81028, _app->varGetByte(81028) + 1);
			if ((int8)_app->varGetByte(81028) > 59)
				_app->varSetByte(81028, 1);
		} else if (target == 2) {
			_app->objectPresentationShow(kObject81222, 2);
			if (_app->varGetByte(81029) == 5 && _app->varGetByte(81028) == 30 && _app->varGetByte(81003) == 2) {
				_app->soundPlay(81202);
				_app->rotationSetMovabilityOn(83021, 4, 4);
				_app->objectPresentationShow(kObject81312);
			}
			_app->varSetByte(81029, 0);
			_app->varSetByte(81028, 0);
		}
		break;

	case kObject81301:
		if (!_app->bagHasClickedObject()) {
			_app->soundPlay(81010);
			break;
		}

		if (_app->bagGetClickedObject() == kObjectHomunculus) {
			_app->objectPresentationShow(kObject81301, 0);
			_app->soundPlay(81011);
		}

		if (_app->bagGetClickedObject() == kObjectThinPencil) {
			_app->objectPresentationHide(kObject81301);
			_app->rotationSetMovabilityOn(83011, 0, 0);
			_app->objectSetAccessibilityOff(kObject81301);
			_app->playMovie("a08s03n01a01");
			_app->objectPresentationShow(kObject81904, 2);
			advanceProgress();
		}

		_app->cursorDelete();
		break;

	case kObject81302:
		if (!_app->bagHasClickedObject())
			break;

		if (_app->bagGetClickedObject() == kObjectCompassNeedle) {
			_app->objectPresentationHide(kObject81302);
			_app->objectPresentationShow(kObject81302, 3);
			_app->objectSetAccessibilityOff(kObject81302);
			_app->bagRemove(kObjectCompassNeedle);
			_app->soundPlay(81321);
		}

		_app->cursorDelete();
		break;

	case kObject81303:
		if (_app->bagHasClickedObject()) {
			if (target == 1 && _app->bagGetClickedObject() == kObjectLittleWig) {
				_app->soundPlay(81305);
				_app->objectPresentationHide(kObject81303, 0);
				_app->objectPresentationHide(kObject81303, 9);
				_app->objectPresentationHide(kObject81303, 10);
				_app->bagRemove(kObjectLittleWig);
				_app->varSetByte(81014, 1);
			}

			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 0:
			if (_app->varGetByte(81014) != 1)
				break;

			_app->soundPlay(81306);
			_app->objectPresentationShow(kObject81303, 3);
			_app->objectSetAccessibilityOff(kObject81303, 0, 0);
			_app->objectSetAccessibilityOff(kObject81303, 3, 3);
			_app->soundPlay(_app->varGetByte(81003) == 1 ? 81019 : 81041);
			break;

		case 2:
			_app->bagAdd(kObjectKey4);
			advanceProgress();
			_app->varSetByte(81015, 1);
			_app->objectPresentationHide(kObject81303, 1);
			_app->objectPresentationShow(kObject81303, 2);
			_app->objectSetAccessibilityOff(kObject81303, 2, 2);
			_app->soundPlay(81308);
			break;

		case 3:
			_app->objectSetAccessibilityOn(kObject81303, 0, 1);
			_app->objectSetAccessibilityOff(kObject81303, 2, 2);
			for (uint32 i = 1; i <= 8; i++)
				_app->objectPresentationHide(kObject81303, i);

			if (_app->varGetByte(81016) == 1) {
				_app->soundPlay(81307);
				_app->timerStart(kTimer6, 400);
				_app->varSetByte(81016, 0);
				_app->objectPresentationShow(kObject81303, _app->varGetByte(81015) == 0 ? 6 : 8);
			} else {
				setRotation(83031, 334.0f, 16.0f);
			}
			break;
		}
		break;

	case kObject81305:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			if (_app->varGetByte(81003) == 1) {
				_app->puzzleSetActive(kPuzzle81303);
				_app->soundPlay(81016);
			} else {
				_app->puzzleSetActive(kPuzzle81305);
				_app->soundPlay(81035);
			}
			_app->soundPlay(81320);
		} else if (target == 1) {
			if (_app->varGetByte(81003) == 1) {
				_app->puzzleSetActive(kPuzzle81304);
				_app->soundPlay(81018);
			} else {
				_app->puzzleSetActive(kPuzzle81306);
				_app->soundPlay(81035);
			}
			_app->soundPlay(81320);
		}
		break;

	case kObject81306: {
		// Four buttons; the last four presses are kept in string var 81001
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target > 3)
			break;

		_app->objectPresentationShow(kObject81306, target);
		_app->varSetByte(81021, (byte)target);
		_app->timerStart(kTimer4, 500);
		_app->soundPlay(81304);

		Common::String code = _app->varGetString(81001);
		code = code.empty() ? "" : Common::String(code.c_str() + 1, MIN<uint32>(3, code.size() - 1));
		code += Common::String::format("%d", target);
		_app->varSetString(81001, code);

		if (code != "1032")
			break;

		advanceProgress();
		_app->playMovie("A08S03N03P04S01");
		_app->objectPresentationShow(kObject81306, 4);
		_app->objectPresentationShow(kObject81306, 5);
		_app->objectPresentationShow(kObject81306, 6);
		_app->objectSetAccessibilityOff(kObject81306, 0, 3);
		_app->objectSetAccessibilityOn(kObject81307, 0, 0);
		_app->varSetByte(81023, 1);
		}
		break;

	case kObject81307:
		if (_app->bagHasClickedObject()) {
			if (target == 0 && _app->bagGetClickedObject() == kObjectKey4) {
				// Sets the progress animation frame (0x4dc040), it doesn't save
				if (_app->getSaveManager()->getData()->progressState == kProgressState3)
					_app->getSaveManager()->getData()->progress = 0x18;

				_app->playMovie("a08s03_e03m03a");
				_app->objectSetAccessibilityOff(kObject81307, 0, 0);
				_app->soundStopAll(1024);
				_app->playMovie("a08s01_e03m03");
				_app->varSetByte(81003, 2);
				_app->timerStart(kTimer7, 1000);
				_app->timerStart(kTimer8, 500);
				_app->objectPresentationHide(kObject81307);
				_app->objectPresentationHide(kObject81306);
				_app->objectPresentationShow(kObject81306, 4);
				_app->objectPresentationShow(kObject81306, 5);
				_app->objectPresentationShow(kObject81306, 6);
				_app->objectSetAccessibilityOn(kObject81307, 1, 1);
				_app->objectSetAccessibilityOn(kObject81217, 5, 5);
				_app->varSetByte(81009, 0);
				_app->objectSetAccessibilityOn(kObject81211, 4, 5);
				_app->objectPresentationShow(kObject81204, 0);
				_app->objectPresentationShow(kObject81204, 2);
				_app->objectSetAccessibilityOn(kObject81204, 1, 5);
				_app->objectSetAccessibilityOn(kObject81301, 0, 0);
				_app->objectPresentationHide(kObject81301);
				_app->objectPresentationShow(kObject81301, 1);
				_app->rotationSetMovabilityOff(83011, 0, 0);
				_app->objectPresentationHide(kObject81904, 2);
				_app->objectSetAccessibilityOn(kObject81211, 0, 0);
				_app->soundPlay(81107, kSoundLoop);
				setRotation(81011, 275.0f, 0.0f);
				_app->objectPresentationHide(kObject81101);
				_app->_vm->update();
				_app->objectPresentationShow(kObject25, 4);
			}

			_app->cursorDelete();
			break;
		}

		if (target == 1) {
			_app->objectPresentationShow(kObject81307, 1);
			_app->objectSetAccessibilityOff(kObject81307, 1, 1);
			_app->soundPlay(81309);
		} else if (target == 2) {
			setRotation(83021, 346.0f, 0.0f);
			_app->objectPresentationShow(kObject81307, 2);
			_app->soundPlay(81309);
		}
		break;

	case kObject81311:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->soundPlay(81301, kSoundLoop);
		_app->soundSetVolume(81301, 100);
		_app->timerStart(kTimer5, 80);
		break;

	case kObject81313:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0)
			_app->soundPlay(_app->varGetByte(81003) == 1 ? 81012 : 81032);
		else if (target == 1)
			_app->soundPlay(_app->varGetByte(81003) == 1 ? 81013 : 81033);
		else if (target == 2 || target == 3)
			_app->playMovie(_app->varGetByte(81003) == 1 ? "A08S03_E03M02" : "A08S03_E03M04");
		break;

	case kObject81314:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->objectSetAccessibilityOff(kObject81314);
			_app->objectPresentationShow(kObject81314, 0);
			_app->varSetByte(81024, 1);
			_app->soundPlay(81311);
		} else if (target == 1 || target == 2) {
			_app->objectSetAccessibilityOff(kObject81314);
			_app->objectPresentationHide(kObject81314);
			_app->objectPresentationShow(kObject81314, 1);
			_app->soundPlay(81312);
		}
		break;

	case kObject81315:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0 || target == 1) {
			_app->objectSetAccessibilityOff(kObject81315);
			_app->objectPresentationShow(target == 0 ? kObject81316 : kObject81317, 0);
			_app->varSetByte(target == 0 ? 81025 : 81026, 1);
			_app->soundPlay(81314);
		} else if (target == 2 || target == 3) {
			ObjectId objectId = (target == 2) ? kObject81316 : kObject81317;
			_app->objectSetAccessibilityOff(kObject81315);
			_app->objectPresentationHide(objectId);
			_app->objectPresentationShow(objectId, 1);
			_app->soundPlay(81315);
		}
		break;

	case kObject81401:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->objectPresentationShow(kObject81401, _app->varGetByte(81004) == 0 ? 0 : 2);
			_app->objectSetAccessibilityOff(kObject81401, 0, 0);
			_app->soundPlay(81402);
		} else if (target == 1) {
			_app->objectPresentationShow(kObject81401, 4);
			_app->objectSetAccessibilityOff(kObject81401, 1, 1);
			_app->varSetByte(81004, 1);
			_app->bagAdd(kObjectYellowBulb);
			_app->bagAdd(kObjectRedBulb);
			_app->soundPlay(81404);
		} else if (target == 2) {
			setRotation(84011, 85.0f, 0.0f);
			_app->soundPlay(81403);
			_app->objectPresentationShow(kObject81401, _app->varGetByte(81004) == 0 ? 1 : 3);
		}
		break;

	case kObject81404:
		// Projector: var 81005 = bulb in the lamp (1 red, 2 yellow), var 81006 = switched on, var 81007 = picture loaded
		if (_app->bagHasClickedObject()) {
			if (target == 1 && _app->bagGetClickedObject() == kObjectFrankFirstPrize) {
				_app->soundPlay(81411);

				byte on = _app->varGetByte(81006);
				byte loaded = _app->varGetByte(81007);
				byte bulb = _app->varGetByte(81005);

				if ((on == 0 && loaded == 0) || (on == 1 && loaded == 0 && bulb == 0)) {
					_app->varSetByte(81007, 1);
					_app->objectPresentationShow(kObject81404, 0);
					_app->bagRemove(kObjectFrankFirstPrize);
				} else if (on == 1 && loaded == 0 && bulb == 1) {
					_app->varSetByte(81007, 1);
					_app->objectPresentationShow(kObject81404, 6);
					_app->objectPresentationShow(kObject81404, 5);
					_app->soundPlay(81037);
					advanceProgress();
					_app->varSetByte(81022, 1);
					_app->bagRemove(kObjectFrankFirstPrize);
				} else if (on == 1 && loaded == 0 && bulb == 2) {
					_app->varSetByte(81007, 1);
					_app->objectPresentationShow(kObject81404, 3);
					_app->bagRemove(kObjectFrankFirstPrize);
				}
			}

			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 1:
			if (_app->varGetByte(81007) != 1)
				break;

			_app->objectPresentationHide(kObject81404, 0);
			for (uint32 i = 2; i <= 6; i++)
				_app->objectPresentationHide(kObject81404, i);
			_app->bagAdd(kObjectFrankFirstPrize);
			_app->varSetByte(81007, 0);
			_app->soundStop(81037, 1024);
			_app->soundPlay(81412);

			if (_app->varGetByte(81006) == 1 && _app->varGetByte(81005) == 1)
				_app->objectPresentationShow(kObject81404, 4);

			if (_app->varGetByte(81006) == 1 && _app->varGetByte(81005) == 2)
				_app->objectPresentationShow(kObject81404, 2);
			break;

		case 2:
			_app->soundPlay(81409);

			if (_app->varGetByte(81006) == 0) {
				_app->objectPresentationShow(kObject81404, 1);

				if (_app->varGetByte(81005) == 1) {
					_app->soundPlay(81410, kSoundLoop);
					if (_app->varGetByte(81007) == 0) {
						_app->objectPresentationShow(kObject81404, 4);
					} else {
						_app->objectPresentationShow(kObject81404, 6);
						_app->objectPresentationShow(kObject81404, 5);
						_app->varSetByte(81022, 1);
						_app->soundPlay(81037);
					}
				}

				if (_app->varGetByte(81005) == 2) {
					_app->soundPlay(81410, kSoundLoop);
					_app->objectPresentationShow(kObject81404, _app->varGetByte(81007) == 0 ? 2 : 3);
				}

				_app->varSetByte(81006, 1);
			} else {
				_app->objectPresentationHide(kObject81404);
				_app->varSetByte(81006, 0);
				_app->objectPresentationHide(kObject81404, 6);
				_app->soundStop(81037, 1024);
				_app->soundStop(81410, 1024);
				if (_app->varGetByte(81007) == 1)
					_app->objectPresentationShow(kObject81404, 0);
			}
			break;

		case 3:
			_app->timerStart(kTimer2, 100);
			break;
		}
		break;

	case kObject81405:
		// Lamp: var 81005 = bulb (1 red, 2 yellow)
		if (_app->bagHasClickedObject()) {
			if (target == 1
			 && (_app->bagGetClickedObject() == kObjectRedBulb || _app->bagGetClickedObject() == kObjectYellowBulb)
			 && _app->varGetByte(81005) == 0) {
				_app->soundPlay(81405);

				if (_app->bagGetClickedObject() == kObjectRedBulb) {
					_app->objectPresentationHide(kObject81405);
					_app->objectPresentationShow(kObject81405, 3);
					_app->varSetByte(81005, 1);
					_app->bagRemove(kObjectRedBulb);
				}

				if (_app->bagGetClickedObject() == kObjectYellowBulb) {
					_app->objectPresentationHide(kObject81405);
					_app->objectPresentationShow(kObject81405, 5);
					_app->varSetByte(81005, 2);
					_app->bagRemove(kObjectYellowBulb);
				}

				_app->objectSetAccessibilityOff(kObject81405);
			}

			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->objectPresentationShow(kObject81405, 2 * _app->varGetByte(81005));
			_app->objectSetAccessibilityOff(kObject81405, 0, 0);
			_app->soundPlay(81407);
		} else if (target == 1) {
			if (_app->varGetByte(81005) == 1) {
				_app->objectPresentationShow(kObject81405, 6);
				_app->varSetByte(81005, 0);
				_app->bagAdd(kObjectRedBulb);
				_app->soundPlay(81406);
			}

			if (_app->varGetByte(81005) == 2) {
				_app->objectPresentationShow(kObject81405, 6);
				_app->varSetByte(81005, 0);
				_app->bagAdd(kObjectYellowBulb);
				_app->soundPlay(81406);
			}
		} else if (target == 2) {
			_app->objectPresentationShow(kObject81405, 2 * _app->varGetByte(81005) + 1);
			_app->objectSetAccessibilityOff(kObject81405);
		}
		break;

	case kObject81406:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->soundPlay(81036);
		break;

	case kObjectDiaryOfASeducer:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 1) {
			advanceProgress();
			_app->objectSetAccessibilityOff(kObjectDiaryOfASeducer);
			_app->bagAdd(kObjectDiaryOfASeducer);
			_app->varSetByte(98012, 3);
			_app->puzzleSetActive(kPuzzle81404);
			_app->varSetByte(81012, 1);
			_app->objectSetAccessibilityOn(kObject81408, 0, 0);
			_app->rotationSet3DSoundOn(84011, 81401);
			_app->rotationSet3DSoundOn(84021, 81401);
			_app->soundPlay(81401, kSoundLoop);
			_app->soundSetPan(81401, 20);
			_app->soundPlay(81413);
			_app->soundPlay(81039);
			_app->objectSetAccessibilityOn(kObjectDiaryOfASeducer, 0, 0);
		}
		break;

	case kObject81408:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->playMovie("A08S04N02P04A01");
		_app->soundPlay(81040);
		break;

	case kObject81901:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->objectPresentationShow(kObject81901, 1);
		_app->soundPlay(81409);
		_app->soundPlay(81217 + _app->varGetByte(81027));
		_app->soundPlay(81230 + _app->varGetByte(81027));
		_app->varSetByte(81027, _app->varGetByte(81027) + 1);
		if (_app->varGetByte(81027) == 6)
			_app->varSetByte(81027, 0);
		break;
	}
}

// FAUST.EXE 0x499060
void Zone12Faust::onAnimationNextFrame(Id animationId, const Common::String &name, uint32 frame, uint32 frameCount) {
	switch (animationId) {
	default:
		break;

	case 81201:
		if (frame == 10)
			_app->puzzleSetActive(kPuzzle81202);
		break;

	case 81202:
		if (frame == 1)
			_app->objectSetAccessibilityOn(kObject81208, 0, 0);
		break;

	case 81203:
		if (frame == 15)
			_app->puzzleSetActive(kPuzzle81201);
		break;

	case 81204:
		if (frame == 1)
			_app->soundPlay(81215);
		break;

	case 81301:
		if (frame == 15) {
			_app->soundPlay(81307);

			if (_app->varGetByte(81015)) {
				if (!_app->varGetByte(81016)) {
					_app->objectPresentationShow(kObject81303, 7);
					_app->varSetByte(81016, 1);
				} else {
					_app->objectPresentationHide(kObject81303, 2);
					_app->objectPresentationShow(kObject81303, 8);
					_app->varSetByte(81016, 0);
				}
			} else {
				if (!_app->varGetByte(81016)) {
					_app->objectPresentationShow(kObject81303, 5);
					_app->varSetByte(81016, 1);
				} else {
					_app->objectPresentationHide(kObject81303, 1);
					_app->objectPresentationShow(kObject81303, 6);
					_app->varSetByte(81016, 0);
					_app->objectSetAccessibilityOff(kObject81303, 2, 2);
				}
			}
		} else if (frame == 27) {
			_app->objectPresentationShow(kObject81303, 4);
		}
		break;

	case 81302:
		if (frame == 1) {
			_app->objectSetAccessibilityOn(kObject81303, 0, 0);
			_app->objectSetAccessibilityOn(kObject81303, 3, 3);

			if (!_app->varGetByte(81015) && _app->varGetByte(81016) == 1)
				_app->objectSetAccessibilityOn(kObject81303, 2, 2);
		}
		break;

	case 81303:
		if (frame == 10)
			_app->objectPresentationShow(kObject81303, 1);
		break;

	case 81305:
		if (frame == 10)
			_app->objectPresentationShow(kObject81303, 2);
		break;

	case 81307:
		if (frame == 10) {
			_app->puzzleSetActive(kPuzzle81307);
			_app->objectPresentationHide(kObject81307, 1);
			_app->soundPlay(81034);
		}
		break;

	case 81308:
		if (frame == 1) {
			_app->objectSetAccessibilityOn(kObject81307, 1, 1);
			_app->objectPresentationHide(kObject81307);
			_app->objectPresentationHide(kObject81306);
			_app->objectPresentationShow(kObject81306, 4);
			_app->objectPresentationShow(kObject81306, 5);
			_app->objectPresentationShow(kObject81306, 6);
		}
		break;

	case 81309:
		if (frame == 10) {
			_app->objectPresentationHide(kObject81314);
			_app->objectPresentationShow(kObject81314, 2);
			_app->objectSetAccessibilityOn(kObject81314, 1, 2);
		}
		break;

	case 81310:
		if (frame == 1) {
			_app->objectPresentationHide(kObject81314);
			_app->objectSetAccessibilityOn(kObject81314, 0, 0);
			_app->varSetByte(81024, 0);
			_app->soundPlay(81313);
		}
		break;

	case 81311:
		if (frame == 10) {
			_app->objectPresentationHide(kObject81316);
			_app->objectPresentationShow(kObject81316, 2);
			_app->objectSetAccessibilityOn(kObject81315, 2, 2);
		}
		break;

	case 81312:
		if (frame == 1) {
			_app->objectPresentationHide(kObject81316);
			_app->objectSetAccessibilityOn(kObject81315, 0, 1);
			_app->varSetByte(81025, 0);
			_app->soundPlay(81316);
		}
		break;

	case 81313:
		if (frame == 10) {
			_app->objectPresentationHide(kObject81317);
			_app->objectPresentationShow(kObject81317, 2);
			_app->objectSetAccessibilityOn(kObject81315, 3, 3);
		}
		break;

	case 81314:
		if (frame == 1) {
			_app->objectPresentationHide(kObject81317);
			_app->objectSetAccessibilityOn(kObject81315, 0, 1);
			_app->varSetByte(81026, 0);
			_app->soundPlay(81316);
		}
		break;

	case 81401:
		if (frame == 15) {
			_app->puzzleSetActive(kPuzzle81401);

			if (_app->varGetByte(81012) == 1) {
				_app->soundPlay(81401, kSoundLoop);
				_app->soundSetVolume(81401, 90);
				_app->soundSetPan(81401, -5);
			}
		}
		break;

	case 81402:
		if (frame == 1)
			_app->objectSetAccessibilityOn(kObject81401, 0, 0);
		break;

	case 81403:
		if (frame == 15) {
			_app->objectPresentationHide(kObject81405);
			_app->objectSetAccessibilityOn(kObject81405, 1, 2);

			switch (_app->varGetByte(81005)) {
			default:
				break;

			case 0:
				_app->objectPresentationShow(kObject81405, 6);
				break;

			case 1:
				_app->objectPresentationShow(kObject81405, 7);
				break;

			case 2:
				_app->objectPresentationShow(kObject81405, 8);
				break;
			}
		}
		break;

	case 81404:
		if (frame == 1) {
			_app->objectSetAccessibilityOn(kObject81405, 0, 0);
			_app->objectPresentationHide(kObject81405);
			_app->soundPlay(81408);
		}
		break;
	}
}

void Zone12Faust::onSound(Id id, SoundType type, uint32 a3, bool process) {
	if (!process)
		return;

	switch (id) {
	default:
		break;

	case 81030:
		_app->soundPlay(81031);
		break;

	case 81040:
		if (_app->varGetByte(81012) == 1
		 && _app->varGetByte(81022) == 1
		 && _app->bagHas(kObjectDiaryOfASeducer)) {
			_app->soundStopAll(1024);
			_app->exitToMenu(kMenuAction0);
		}
		break;

	case 81041:
		_app->playMovie("A08S03N03A01");
		break;
	}
}

// FAUST.EXE 0x497ac0
void Zone12Faust::onBag(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, DragControl *dragControl, byte type) {
	switch (id) {
	default:
		break;

	case kObject81201:
		// Two 60-step dials (81202 driven by target 0 into var 81002, 81203 by target 1 into var 81001)
		if (target != 0 && target != 1)
			break;

		switch (type) {
		default:
			break;

		case 1:
			_app->dragControlSetHotspot(Common::Rect(200, 125, 441, 366));
			_app->dragControlSetCoords1(Common::Point(320, 245));
			break;

		case 2:
			if (_app->varGetFloat(81001) != 30.0f)
				break;

			if (_app->varGetFloat(81002) != 26.0f
			 && _app->varGetFloat(81002) != 27.0f
			 && _app->varGetFloat(81002) != 28.0f
			 && _app->varGetFloat(81002) != 29.0f)
				break;

			advanceProgress();

			_app->soundPlay(81202);
			_app->rotationSetMovabilityOn(83021, 4, 4);
			_app->objectPresentationShow(kObject81312);
			break;

		case 3: {
			int32 position = ApplicationFaust::getDragAngle(dragControl) * 59 / 360;
			ObjectId objectId = target ? kObject81203 : kObject81202;

			_app->objectPresentationHide(objectId);
			_app->objectPresentationShow(objectId, position);
			_app->varSetFloat(target ? 81001 : 81002, (float)position);

			if (!_app->dragControlYEqual() && !_app->dragControlXEqual())
				_app->soundPlay(81201);
			}
			break;
		}
		break;

	case kObject81310:
		// Two 15-step levers (81308 driven by target 0 into var 81005, 81309 by target 1 into var 81004)
		if (target != 0 && target != 1)
			break;

		switch (type) {
		default:
			break;

		case 1:
			_app->cursorDelete();
			_app->dragControlSetField45(2);
			_app->soundPlay(81301, kSoundLoop);
			_app->soundSetVolume(81301, 0);
			_app->soundSetPan(81301, target ? -5 : 5);
			break;

		case 2:
			_app->soundStop(81301, 1024);

			if (_app->varGetFloat(81005) >= 14.0 && _app->varGetFloat(81004) >= 14.0)
				_app->soundPlay(81014);
			break;

		case 3: {
			Id varId = target ? 81004 : 81005;
			float delta = (float)(_app->dragControlGetOffsetX() * 0.0625);

			// Dragging left lowers lever 0 but raises lever 1
			if (_app->dragControlXLower())
				_app->varSetFloat(varId, _app->varGetFloat(varId) + (target ? delta : -delta));

			if (_app->dragControlXHigher())
				_app->varSetFloat(varId, _app->varGetFloat(varId) + (target ? -delta : delta));

			if (_app->varGetFloat(varId) < 0.0)
				_app->varSetFloat(varId, 0);

			if (_app->varGetFloat(varId) >= 15.0)
				_app->varSetFloat(varId, 14.0f);

			ObjectId objectId = target ? kObject81309 : kObject81308;
			_app->objectPresentationHide(objectId);
			_app->objectPresentationShow(objectId, (uint32)_app->varGetFloat(varId));

			if (_app->dragControlYEqual() || _app->dragControlXEqual())
				_app->soundSetVolume(81301, 0);
			else
				_app->soundSetVolume(81301, (int32)_app->dragControlGetOffsetX() / 2 + 80);
			}
			break;
		}
		break;
	}
}

void Zone12Faust::onUpdateBag(const Common::Point &point) {
	_app->soundStop(_app->varGetDword(81001), 1024);
	_app->varSetDword(81001, 0);
}

void Zone12Faust::onUpdateBefore(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, const Common::Point &point) {
	if (movabilityFrom == 81900 && !_app->soundIsPlayingType(kSoundTypeDialog)) {
		switch (movabilityTo) {
		default:
			return;

		case 0:
			_app->varSetDword(81001, 81015);
			break;

		case 1:
			_app->varSetDword(81001, 81017);
			break;

		case 2:
			case 3:
			_app->varSetDword(81001, 81042);
			break;

		case 4:
			_app->varSetDword(81001, 81001);
		}

		_app->soundPlay(_app->varGetDword(81001));
	}
}

// FAUST.EXE 0x498150
void Zone12Faust::onAfterRide(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, MovabilityType movabilityType) {
	Id current = movabilityFrom;
	Id previous = movabilityTo;

	_app->objectPresentationHide(kObject25);

	switch (movabilityType) {
	default:
		break;

	case kMovabilityRotationToRotation:
		if (previous == 82031) {
			_app->objectPresentationHide(kObject81211);
			_app->objectSetAccessibilityOff(kObject81211);
			_app->objectSetAccessibilityOn(kObject81211, 0, 0);

			if (_app->varGetByte(81030) == 1) {
				_app->soundPlay(81225);
				_app->varSetByte(81030, 0);
			}
		} else if (previous == 82061) {
			_app->objectPresentationHide(kObject81217);
			_app->objectSetAccessibilityOff(kObject81217, 0, 3);
			_app->objectSetAccessibilityOn(kObject81217, 0, 0);
			_app->varSetByte(81013, 0);

			if (_app->varGetByte(81031) == 1) {
				_app->soundPlay(81224);
				_app->varSetByte(81031, 0);
			}
		}

		if (current == 82011 && previous == 81041) {
			_app->timerStop(kTimer7);
			_app->timerStop(kTimer8);
			_app->timerStart(kTimer10, 500);
			_app->soundStopType(kSoundTypeBackgroundMusic, 1024);
			_app->soundPlay(81223, kSoundLoop);
		} else if (current == 81041 && previous == 82011) {
			_app->timerStart(kTimer7, 1000);
			_app->timerStart(kTimer8, 500);
			_app->timerStop(kTimer10);
			_app->soundStopType(kSoundTypeBackgroundMusic, 1024);
			_app->soundPlay(81107, kSoundLoop);
		} else if (current == 83021 && previous == 83031) {
			_app->soundPlay(81303);
		} else if (current == 83031 && previous == 83021) {
			_app->soundPlay(81302);
		} else if (current == 84011 && previous == 83021) {
			_app->timerStart(kTimer9, 1000);
			_app->soundStopType(kSoundTypeBackgroundMusic, 1024);
			_app->soundStop(81310, 1024);
		} else if (current == 83021 && previous == 84011) {
			_app->timerStop(kTimer9);
			_app->soundStopType(kSoundTypeBackgroundMusic, 1024);
			_app->soundPlay(81310, kSoundLoop);
		} else if (current == 83011 && previous == 83021) {
			_app->soundStopType(kSoundTypeBackgroundMusic, 1024);
			_app->soundPlay(81223, kSoundLoop);
		} else if (current == 83021 && previous == 83011) {
			_app->soundStopType(kSoundTypeBackgroundMusic, 1024);
			_app->soundPlay(81310, kSoundLoop);
		}
		break;

	case kMovabilityRotationToPuzzle:
		if (previous != 84021 || _app->varGetByte(81012) != 1)
			break;

		if (current == kPuzzle81402) {
			_app->soundPlay(81401, kSoundLoop);
			_app->soundSetPan(81401, -15);
		} else if (current == kPuzzle81403) {
			_app->soundPlay(81401, kSoundLoop);
			_app->soundSetPan(81401, 20);
		} else if (current == kPuzzle81405) {
			_app->soundPlay(81401, kSoundLoop);
			_app->soundSetVolume(81401, 100);
		}
		break;

	case kMovabilityPuzzleToRotation:
		if (current == 82051 && previous == kPuzzle81205) {
			if (_app->varGetByte(81010) == 1)
				_app->soundPlay(81211);

			if (_app->varGetByte(81011) == 1)
				_app->bagAdd(kObjectBoxOfSlides);

			_app->varSetByte(81010, 0);
			_app->varSetByte(81011, 0);
			_app->objectPresentationHide(kObject81215);
			_app->objectPresentationShow(kObject81216);
			_app->objectSetAccessibilityOff(kObject81215, 2, 9);
			_app->objectSetAccessibilityOn(kObject81215, 0, 1);
			_app->soundStop(81212, 1024);
			break;
		}

		if (previous == kPuzzle81303 || previous == kPuzzle81304 || previous == kPuzzle81305 || previous == kPuzzle81306)
			_app->soundPlay(81319);

		if (current != 84021)
			break;

		if (previous == kPuzzle81404) {
			_app->objectPresentationShow(kObjectDiaryOfASeducer);
			_app->objectSetAccessibilityOff(kObjectDiaryOfASeducer);
			_app->soundPlay(81414);
			_app->rotationSetMovabilityOff(84021, 2, 2);
		} else if (previous == kPuzzle81402 || previous == kPuzzle81403 || previous == kPuzzle81405) {
			if (_app->varGetByte(81012) == 1
			 && _app->varGetByte(81022) == 1
			 && _app->bagHas(kObjectDiaryOfASeducer)) {
				_app->soundStopAll(1024);
				_app->exitToMenu(kMenuAction0);
			}
		}
		break;
	}
}

// Advances the progress animation frame (0x4dc040), it doesn't save
void Zone12Faust::advanceProgress() {
	if (_app->getSaveManager()->getData()->progressState == kProgressState3)
		_app->getSaveManager()->getData()->progress++;
}

// Remembers the current rotation and view (vars 81002-81004) before opening a close-up
void Zone12Faust::saveRotation() {
	_app->varSetDword(81002, (int32)_app->getCurrentRotationId());
	_app->varSetDword(81003, (int32)_app->rotationGetAlp(_app->getCurrentRotationId()));
	_app->varSetDword(81004, (int32)_app->rotationGetBet(_app->getCurrentRotationId()));
}

void Zone12Faust::setRotation(Id rotationId, float alp, float bet) {
	_app->rotationSetAlp(rotationId, alp);
	_app->rotationSetBet(rotationId, bet);
	_app->rotationSetRan(rotationId, 87.0f);
	_app->rotationSetActive(rotationId);
}

} // End of namespace Ring
