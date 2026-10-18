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

#include "ring/game/faust/faust_zone14.h"

#include "ring/game/faust/faust_application.h"
#include "ring/game/faust/faust_shared.h"

#include "ring/base/saveload.h"

#include "ring/debug.h"
#include "ring/ring.h"
#include "ring/helpers.h"

using namespace FaustGame;

namespace Ring {

Zone14Faust::Zone14Faust(ApplicationFaust *application) : _app(application), _dragValue(0), _dragPrevious(0) {
}

Zone14Faust::~Zone14Faust() {
	// Zero-out passed pointers
	_app = nullptr;
}

void Zone14Faust::onInit() {
	_app->setCurrentZone(kZone14);

	_app->puzzleAdd(kPuzzle114032);
	_app->puzzleAddBackgroundImage(kPuzzle114032, "a11s04n01p13.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle112001);
	_app->puzzleAddBackgroundImage(kPuzzle112001, "a11s02n06p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle112002);
	_app->puzzleAddBackgroundImage(kPuzzle112002, "a11s02n06p04.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle112005);
	_app->puzzleAddBackgroundImage(kPuzzle112005, "a11s02n06p09.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle112004);
	_app->puzzleAddBackgroundImage(kPuzzle112004, "a11s02n06p03.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle112010);
	_app->puzzleAddBackgroundImage(kPuzzle112010, "a11s02n06p05.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle112014);
	_app->puzzleAddBackgroundImage(kPuzzle112014, "a11s02n06p02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle112000);
	_app->puzzleAddBackgroundImage(kPuzzle112000, "a11s02n05p07.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle112011);
	_app->puzzleAddBackgroundImage(kPuzzle112011, "a11s02n05p04.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle112012);
	_app->puzzleAddBackgroundImage(kPuzzle112012, "a11s02n05p05.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle112013);
	_app->puzzleAddBackgroundImage(kPuzzle112013, "a11s02n05p06.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114001);
	_app->puzzleAddBackgroundImage(kPuzzle114001, "a11s04n01p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114002);
	_app->puzzleAddBackgroundImage(kPuzzle114002, "a11s04n01p02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114003);
	_app->puzzleAddBackgroundImage(kPuzzle114003, "a11s04n01p03.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114004);
	_app->puzzleAddBackgroundImage(kPuzzle114004, "a11s04n01p04.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114005);
	_app->puzzleAddBackgroundImage(kPuzzle114005, "a11s04n01p05.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114006);
	_app->puzzleAddBackgroundImage(kPuzzle114006, "a11s04n01p06.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114007);
	_app->puzzleAddBackgroundImage(kPuzzle114007, "a11s04n01p13.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114008);
	_app->puzzleAddBackgroundImage(kPuzzle114008, "a11s04n01p08.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114009);
	_app->puzzleAddBackgroundImage(kPuzzle114009, "a11s04n01p10.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114010);
	_app->puzzleAddBackgroundImage(kPuzzle114010, "a11s04n01p09.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114030);
	_app->puzzleAddBackgroundImage(kPuzzle114030, "a11s04n01p09l01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114011);
	_app->puzzleAddBackgroundImage(kPuzzle114011, "a11s04n01p12.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114012);
	_app->puzzleAddBackgroundImage(kPuzzle114012, "a11s04n01p12l01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114013);
	_app->puzzleAddBackgroundImage(kPuzzle114013, "a11s04n01p08.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114014);
	_app->puzzleAddBackgroundImage(kPuzzle114014, "a11s04n01p10l03.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114015);
	_app->puzzleAddBackgroundImage(kPuzzle114015, "a11s04n01p07.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114016);
	_app->puzzleAddBackgroundImage(kPuzzle114016, "a11s04n02p02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114017);
	_app->puzzleAddBackgroundImage(kPuzzle114017, "a11s04n02p03.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114019);
	_app->puzzleAddBackgroundImage(kPuzzle114019, "a11s01n03p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114031);
	_app->puzzleAddBackgroundImage(kPuzzle114031, "a11s01n03p02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114020);
	_app->puzzleAddBackgroundImage(kPuzzle114020, "a11s01n08p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114021);
	_app->puzzleAddBackgroundImage(kPuzzle114021, "a11s01n08p02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114022);
	_app->puzzleAddBackgroundImage(kPuzzle114022, "a11s01n07p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114023);
	_app->puzzleAddBackgroundImage(kPuzzle114023, "a11s01n06p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114024);
	_app->puzzleAddBackgroundImage(kPuzzle114024, "a11s04n02p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114025);
	_app->puzzleAddBackgroundImage(kPuzzle114025, "a11s04n01p15.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114026);
	_app->puzzleAddBackgroundImage(kPuzzle114026, "a11s04n02p04.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114027);
	_app->puzzleAddBackgroundImage(kPuzzle114027, "a11s03n01p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114028);
	_app->puzzleAddBackgroundImage(kPuzzle114028, "a11s03n01p02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114033);
	_app->puzzleAddBackgroundImage(kPuzzle114033, "a11s02n05p08.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114034);
	_app->puzzleAddBackgroundImage(kPuzzle114034, "a11s04n01p05l05.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle114035);
	_app->puzzleAddBackgroundImage(kPuzzle114035, "a11s04n01p17.bmp", Common::Point(0, 16), true);
	_app->rotationAdd(111101, "A11S01N01R01", 0, 1);
	_app->rotationAdd(111102, "A11S01N02R01", 0, 3);
	_app->rotationAdd(111103, "A11S01N03R01", 0, 4);
	_app->rotationAdd(111104, "A11S01N04R01", 0, 0);
	_app->rotationAdd(111105, "A11S01N05R01", 0, 1);
	_app->rotationAdd(111106, "A11S01N06R01", 0, 4);
	_app->rotationSetCompressionBufferLength(111106, 1900000);
	_app->rotationAdd(111107, "A11S01N07R01", 0, 3);
	_app->rotationAdd(111108, "A11S01N08R01", 0, 3);
	_app->rotationAdd(111109, "A11S01N09R01", 0, 2);
	_app->rotationAdd(111110, "A11S01N10R01", 0, 2);
	_app->rotationAdd(111201, "A11S02N01R01", 0, 0);
	_app->rotationAdd(111202, "A11S02N02R01", 0, 0);
	_app->rotationAdd(111203, "A11S02N03R01", 0, 0);
	_app->rotationAdd(111204, "A11S02N04R01", 0, 0);
	_app->rotationAdd(111205, "A11S02N05R01", 0, 8);
	_app->rotationAdd(111206, "A11S02N06R01", 0, 5);
	_app->rotationSetCompressionBufferLength(111206, 1300000);
	_app->rotationAdd(111207, "A11S02N07R01", 0, 3);
	_app->rotationAdd(111301, "A11S03N01R01", 0, 8);
	_app->rotationSetCompressionBufferLength(111301, 2100000);
	_app->rotationAdd(111401, "A11S04N01R01", 0, 11);
	_app->rotationSetCompressionBufferLength(111401, 2200000);
	_app->rotationAdd(111402, "A11S04N02R01", 0, 1);
	_app->rotationAdd(111403, "A11S04N01R02", 0, 2);
	_app->rotationAdd(111404, "A11S04N02R02", 0, 0);
	_app->rotationAdd(111405, "A11S04N01R03", 0, 1);
	_app->rotationAdd(111406, "A11S04N02R03", 0, 0);
	_app->rotationAdd(111501, "A11S05N01R01", 0, 0);
	_app->rotationAddMovabilityToRotation(111101, 111102, "", Common::Rect(2141, -34, 2351, 286), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111101, 0, 180.0f, 13.0f, 87.0f, 0.0f, 2, 180.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111102, 111101, "", Common::Rect(358, -57, 488, 61), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111102, 0, 0.0f, 0.0f, 87.0f, 0.0f, 2, 0.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111102, 111103, "", Common::Rect(3060, -80, 3236, 216), true, kCursorMove, 1);
	_app->rotationSetMovabilityToRotation(111102, 1, 272.0f, 0.0f, 87.0f, 0.0f, 2, 281.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111103, 111102, "", Common::Rect(1276, -85, 1422, 179), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111103, 0, 92.0f, 0.0f, 87.0f, 0.0f, 2, 92.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111103, 111104, "", Common::Rect(2209, 38, 2525, 324), true, kCursorMove, 1);
	_app->rotationSetMovabilityToRotation(111103, 1, 180.0f, 0.0f, 87.0f, 0.0f, 2, 175.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111103, 111107, "", Common::Rect(3215, -55, 3411, 144), true, kCursorMove, 2);
	_app->rotationSetMovabilityToRotation(111103, 2, 280.0f, 0.0f, 87.0f, 0.0f, 2, 277.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(111103, kPuzzle114019, "", Common::Rect(182, -47, 297, 62), false, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111103, 3, 335.0f, 26.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(111103, kPuzzle114031, "", Common::Rect(170, 98, 307, 173), false, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111103, 4, 335.0f, 26.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(111104, 111103, "", Common::Rect(363, -104, 525, 97), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111104, 0, 11.0f, 0.0f, 87.0f, 0.0f, 2, 0.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111104, 111105, "", Common::Rect(1729, -97, 1986, 270), true, kCursorMove, 1);
	_app->rotationSetMovabilityToRotation(111104, 1, 149.0f, 0.0f, 87.0f, 0.0f, 2, 100.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111104, 111110, "", Common::Rect(3125, -41, 3355, 158), true, kCursorMove, 2);
	_app->rotationSetMovabilityToRotation(111104, 2, 265.0f, 0.0f, 87.0f, 0.0f, 2, 280.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111105, 111104, "", Common::Rect(3315, -31, 3438, 162), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111105, 0, 286.0f, 0.0f, 87.0f, 0.0f, 2, 0.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111105, 111106, "", Common::Rect(1256, -99, 1487, 125), true, kCursorMove, 1);
	_app->rotationSetMovabilityToRotation(111105, 1, 100.0f, 0.0f, 87.0f, 0.0f, 2, 80.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111105, 111201, "", Common::Rect(667, -258, 942, 279), true, kCursorMove, 2);
	_app->rotationSetMovabilityToRotation(111105, 2, 30.0f, 0.0f, 87.0f, 0.0f, 2, 0.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111106, 111105, "", Common::Rect(3081, -134, 3304, 146), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111106, 0, 270.0f, 0.0f, 87.0f, 0.0f, 2, 270.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(111106, kPuzzle114023, "", Common::Rect(659, 12, 812, 109), false, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111106, 1, 30.0f, 0.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(111107, 111103, "", Common::Rect(1400, -1, 1550, 156), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111107, 0, 99.0f, 0.0f, 87.0f, 0.0f, 2, 100.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111107, 111108, "", Common::Rect(2315, -92, 2622, 249), true, kCursorMove, 1);
	_app->rotationSetMovabilityToRotation(111107, 1, 190.0f, 0.0f, 87.0f, 0.0f, 2, 180.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(111107, kPuzzle114022, "", Common::Rect(3216, -387, 3338, -262), false, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111107, 2, 280.0f, -20.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(111108, 111107, "", Common::Rect(439, -94, 769, 188), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111108, 0, 15.0f, 0.0f, 87.0f, 0.0f, 2, 35.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111108, 111109, "", Common::Rect(2329, 12, 2603, 273), true, kCursorMove, 1);
	_app->rotationSetMovabilityToRotation(111108, 1, 197.0f, 0.0f, 87.0f, 0.0f, 2, 197.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111109, 111108, "", Common::Rect(502, -169, 798, 69), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111109, 0, 32.0f, 0.0f, 87.0f, 0.0f, 2, 30.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111109, 111110, "", Common::Rect(1599, 0, 1824, 219), true, kCursorMove, 1);
	_app->rotationSetMovabilityToRotation(111109, 1, 128.0f, 0.0f, 87.0f, 0.0f, 2, 94.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111110, 111109, "", Common::Rect(3492, -129, 3600, 45), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111110, 0, 318.0f, 0.0f, 87.0f, 0.0f, 2, 267.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111110, 111104, "", Common::Rect(1346, -109, 1662, 205), true, kCursorMove, 1);
	_app->rotationSetMovabilityToRotation(111110, 1, 94.0f, 0.0f, 87.0f, 0.0f, 2, 142.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111201, 111105, "", Common::Rect(2021, -437, 2399, 101), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111201, 0, 180.0f, -13.0f, 87.0f, 0.0f, 2, 212.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111201, 111202, "", Common::Rect(1125, -138, 1582, 206), true, kCursorMove, 1);
	_app->rotationSetMovabilityToRotation(111201, 1, 80.0f, 0.0f, 87.0f, 0.0f, 2, 70.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111201, 111204, "", Common::Rect(755, -233, 928, -29), true, kCursorMove, 2);
	_app->rotationSetMovabilityToRotation(111201, 2, 35.0f, -16.0f, 87.0f, 0.0f, 2, 0.0f, 7.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111201, 111205, "", Common::Rect(0, -298, 196, -97), true, kCursorMove, 3);
	_app->rotationSetMovabilityToRotation(111201, 3, 325.0f, -20.0f, 87.0f, 0.0f, 2, 0.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111201, 111401, "", Common::Rect(87, -76, 212, 230), true, kCursorMove, 3);
	_app->rotationSetMovabilityToRotation(111201, 4, 335.0f, 0.0f, 87.0f, 0.0f, 2, 0.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111201, 111205, "", Common::Rect(3376, -82, 3600, 243), true, kCursorMove, 3);
	_app->rotationSetMovabilityToRotation(111201, 5, 325.0f, -20.0f, 87.0f, 0.0f, 2, 0.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111201, 111205, "", Common::Rect(3376, -82, 3600, 243), true, kCursorMove, 3);
	_app->rotationSetMovabilityToRotation(111201, 6, 325.0f, -20.0f, 87.0f, 0.0f, 2, 0.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111202, 111201, "", Common::Rect(2842, -75, 2998, 181), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111202, 0, 256.0f, 0.0f, 87.0f, 0.0f, 2, 212.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111202, 111203, "", Common::Rect(446, 139, 602, 380), true, kCursorMove, 1);
	_app->rotationSetMovabilityToRotation(111202, 1, 5.0f, 26.0f, 87.0f, 0.0f, 2, 0.0f, 26.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111203, 111202, "", Common::Rect(2255, -308, 2473, -64), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111203, 0, 194.0f, -16.0f, 87.0f, 0.0f, 2, 180.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111203, 111301, "", Common::Rect(219, -75, 894, 604), false, kCursorMove, 1);
	_app->rotationSetMovabilityToRotation(111203, 1, 360.0f, 26.0f, 87.0f, 0.0f, 2, 0.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111204, 111201, "", Common::Rect(2494, 99, 2664, 303), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111204, 0, 208.0f, 26.0f, 87.0f, 0.0f, 2, 205.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111204, 111501, "", Common::Rect(175, -212, 836, 268), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111204, 1, 0.0f, 0.0f, 87.0f, 0.0f, 2, 0.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111205, 111201, "", Common::Rect(1847, 122, 2135, 413), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111205, 0, 165.0f, 26.0f, 87.0f, 0.0f, 2, 143.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111205, 111206, "", Common::Rect(356, -13, 502, 252), true, kCursorMove, 1);
	_app->rotationSetMovabilityToRotation(111205, 1, 353.0f, 0.0f, 87.0f, 0.0f, 2, 254.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111206, 111205, "", Common::Rect(1323, -97, 1582, 268), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111206, 0, 94.0f, 0.0f, 87.0f, 0.0f, 2, 180.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111206, 111207, "", Common::Rect(75, -118, 388, 301), true, kCursorMove, 1);
	_app->rotationSetMovabilityToRotation(111206, 1, 336.0f, 0.0f, 87.0f, 0.0f, 2, 93.0f, 17.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111207, 111206, "", Common::Rect(2798, -66, 3063, 303), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111207, 0, 249.0f, 0.0f, 87.0f, 0.0f, 2, 159.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111301, 111203, "", Common::Rect(1965, -90, 2176, 235), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111301, 0, 163.0f, -2.0f, 87.0f, 0.0f, 2, 180.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(111301, kPuzzle114027, "", Common::Rect(3404, -75, 3483, 90), false, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111301, 1, 300.0f, 0.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(111301, kPuzzle114028, "", Common::Rect(244, -118, 643, 186), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111301, 2, 0.0f, 0.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(111401, 111201, "", Common::Rect(2176, -75, 2337, 219), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111401, 0, 180.0f, 0.0f, 87.0f, 0.0f, 2, 180.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111401, 111402, "", Common::Rect(1167, -195, 1603, 169), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111401, 1, 90.0f, 0.0f, 87.0f, 0.0f, 2, 90.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(111401, kPuzzle114001, "", Common::Rect(708, 233, 810, 357), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111401, 2, 35.0f, 26.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(111401, kPuzzle114002, "", Common::Rect(791, 116, 863, 207), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111401, 3, 35.0f, 13.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(111401, kPuzzle114003, "", Common::Rect(217, 109, 286, 167), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111401, 4, 340.0f, 12.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(111401, kPuzzle114004, "", Common::Rect(395, 88, 460, 143), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111401, 5, 355.0f, 10.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(111401, kPuzzle114015, "", Common::Rect(86, -52, 203, 20), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111401, 6, 330.0f, 0.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(111401, kPuzzle114025, "", Common::Rect(1683, -8, 1889, 211), false, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111401, 7, 330.0f, 0.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(111402, 111401, "", Common::Rect(2715, -75, 3174, 272), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111402, 0, 250.0f, 0.0f, 87.0f, 0.0f, 2, 250.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(111402, kPuzzle114016, "", Common::Rect(2624, 197, 2808, 348), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111402, 1, 225.0f, 23.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(111402, kPuzzle114024, "", Common::Rect(689, -108, 805, 27), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111402, 2, 30.0f, 0.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(111403, 111201, "", Common::Rect(2176, -75, 2337, 219), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111403, 0, 180.0f, 0.0f, 87.0f, 0.0f, 2, 180.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111403, 111404, "", Common::Rect(1167, -195, 1603, 169), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111403, 1, 90.0f, 0.0f, 87.0f, 0.0f, 2, 90.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(111403, kPuzzle114025, "", Common::Rect(1683, -8, 1889, 211), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111403, 2, 330.0f, 0.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(111403, kPuzzle114015, "", Common::Rect(86, -52, 203, 20), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111403, 3, 330.0f, 0.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(111404, 111403, "", Common::Rect(2715, -75, 3174, 272), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111404, 0, 250.0f, 0.0f, 87.0f, 0.0f, 2, 250.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(111404, kPuzzle114016, "", Common::Rect(2624, 197, 2808, 348), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111404, 1, 225.0f, 23.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(111404, kPuzzle114024, "", Common::Rect(689, -108, 805, 27), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111404, 2, 30.0f, 0.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(111405, 111201, "", Common::Rect(2176, -75, 2337, 219), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111405, 0, 180.0f, 0.0f, 87.0f, 0.0f, 2, 180.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(111405, 111406, "", Common::Rect(1167, -195, 1603, 169), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111405, 1, 90.0f, 0.0f, 87.0f, 0.0f, 2, 90.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(111405, kPuzzle114025, "", Common::Rect(1683, -8, 1889, 211), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111405, 2, 330.0f, 0.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(111405, kPuzzle114015, "", Common::Rect(86, -52, 203, 20), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111405, 3, 330.0f, 0.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(111406, 111405, "", Common::Rect(2715, -75, 3174, 272), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111406, 0, 250.0f, 0.0f, 87.0f, 0.0f, 2, 250.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(111406, kPuzzle114016, "", Common::Rect(2624, 197, 2808, 348), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111406, 1, 225.0f, 23.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(111406, kPuzzle114024, "", Common::Rect(689, -108, 805, 27), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111406, 2, 30.0f, 0.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(111406, kPuzzle114026, "", Common::Rect(917, -133, 1592, 282), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(111406, 3, 30.0f, 0.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(111501, 111204, "", Common::Rect(2193, -26, 2459, 218), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(111501, 0, 185.0f, 0.0f, 87.0f, 0.0f, 2, 205.0f, 0.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle114028, 111301, "", Common::Rect(100, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle114028, 0, 0.0f, 0.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle114026, 111406, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle114026, 0, 82.0f, 13.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle114032, 111401, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle114032, 0, 130.0f, 0.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle114023, 111106, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle114023, 0, 30.0f, 0.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle114022, 111107, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle114022, 0, 280.0f, -20.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle114020, 111108, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle114020, 0, 90.0f, 20.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle114021, 111108, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle114021, 0, 18.0f, -11.0f, 87.0f);
	_app->puzzleAddMovabilityToPuzzle(kPuzzle114021, kPuzzle114022, "", Common::Rect(255, 279, 430, 427), false, kCursorMove, 0);
	_app->puzzleAddMovabilityToRotation(kPuzzle114019, 111103, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle114019, 0, 335.0f, 0.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle114031, 111103, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle114031, 0, 335.0f, 0.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle112000, 111205, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle112000, 0, 23.0f, 23.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle114016, 111402, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle114016, 0, 225.0f, 23.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle114016, 111404, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle114016, 1, 225.0f, 23.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle114016, 111406, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle114016, 2, 225.0f, 23.0f, 87.0f);
	_app->puzzleAddMovabilityToPuzzle(kPuzzle114008, kPuzzle114011, "", Common::Rect(494, 34, 540, 300), false, kCursorZoom, 0);
	_app->puzzleAddMovabilityToPuzzle(kPuzzle114013, kPuzzle114008, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleAddMovabilityToPuzzle(kPuzzle114014, kPuzzle114008, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleAddMovabilityToPuzzle(kPuzzle114011, kPuzzle114008, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleAddMovabilityToPuzzle(kPuzzle114011, kPuzzle114012, "", Common::Rect(93, 72, 551, 407), true, kCursorZoom, 0);
	_app->puzzleAddMovabilityToPuzzle(kPuzzle114010, kPuzzle114009, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleAddMovabilityToPuzzle(kPuzzle114030, kPuzzle114009, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleAddMovabilityToPuzzle(kPuzzle114012, kPuzzle114008, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleAddMovabilityToRotation(kPuzzle112010, 111206, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle112010, 0, 210.0f, 40.0f, 87.0f);
	_app->puzzleAddMovabilityToPuzzle(kPuzzle112002, kPuzzle112001, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleAddMovabilityToPuzzle(kPuzzle112004, kPuzzle112001, "", Common::Rect(0, 16, 640, 464), true, kCursorBack, 0);
	_app->puzzleAddMovabilityToPuzzle(kPuzzle112005, kPuzzle112001, "", Common::Rect(0, 16, 640, 464), true, kCursorBack, 0);
	_app->puzzleAddMovabilityToRotation(kPuzzle112014, 111206, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle112014, 0, 40.0f, 35.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle112011, 111205, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle112011, 0, 315.0f, 26.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle112012, 111205, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle112012, 0, 315.0f, 26.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle112013, 111205, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle112013, 0, 315.0f, 26.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle114001, 111401, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle114001, 0, 35.0f, 26.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle114002, 111401, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle114002, 0, 35.0f, 13.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle114003, 111401, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle114003, 0, 340.0f, 12.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle114004, 111401, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle114004, 0, 355.0f, 10.0f, 87.0f);
	_app->puzzleAddMovabilityToPuzzle(kPuzzle114034, kPuzzle114005, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->objectAdd(kObject20, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject20, kPuzzle112010, Common::Rect(330, 319, 409, 382), false, kCursorZoom, 0);
	_app->objectAddPuzzleAccessibility(kObject20, kPuzzleMenu, Common::Rect(0, 0, 640, 480), false, kCursorBack, 99);
	_app->objectAddPuzzleAccessibility(kObject20, kPuzzleMenu, Common::Rect(0, 420, 640, 464), false, kCursorBack, 89);
	_app->objectAddPuzzleAccessibility(kObject20, kPuzzleMenu, Common::Rect(219, 53, 444, 425), false, kCursorZoom, 11);
	_app->objectAddPuzzleAccessibility(kObject20, kPuzzleMenu, Common::Rect(93, 64, 543, 418), false, kCursorZoom, 12);
	_app->objectAddPuzzleAccessibility(kObject20, kPuzzleMenu, Common::Rect(339, 65, 543, 418), false, kCursorZoom, 12);
	_app->objectAddPuzzleAccessibility(kObject20, kPuzzleMenu, Common::Rect(219, 53, 444, 425), false, kCursorZoom, 21);
	_app->objectAddPuzzleAccessibility(kObject20, kPuzzleMenu, Common::Rect(93, 64, 299, 418), false, kCursorZoom, 22);
	_app->objectAddPuzzleAccessibility(kObject20, kPuzzleMenu, Common::Rect(339, 65, 543, 418), false, kCursorZoom, 23);
	_app->objectAddPuzzleAccessibility(kObject20, kPuzzleMenu, Common::Rect(219, 53, 444, 425), false, kCursorZoom, 31);
	_app->objectAddPuzzleAccessibility(kObject20, kPuzzleMenu, Common::Rect(440, 96, 490, 136), false, kCursorTake, 41);
	_app->objectAddPuzzleAccessibility(kObject20, kPuzzleMenu, Common::Rect(0, 0, 640, 480), false, kCursorBack, 79);
	_app->objectAddPuzzleAccessibility(kObject20, kPuzzle114022, Common::Rect(387, 311, 422, 363), false, kCursorZoom, 61);
	_app->objectAddPuzzleAccessibility(kObject20, kPuzzleMenu, Common::Rect(0, 0, 640, 480), false, kCursorBack, 69);
	_app->objectAdd(kObject114503, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject114503, kPuzzleMenu, Common::Rect(0, 0, 640, 480), false, kCursorIdle, 79);
	_app->objectAdd(kObject112080, "", "", 1);
	_app->objectAddRotationAccessibility(kObject112080, 111206, Common::Rect(1696, 301, 1720, 331), true, kCursorZoom, 18);
	_app->objectAdd(kObject112081, "", "", 1);
	_app->objectAddRotationAccessibility(kObject112081, 111206, Common::Rect(1838, -36, 1882, 38), true, kCursorZoom, 19);
	_app->objectAdd(kObject112082, "", "", 1);
	_app->objectAddRotationAccessibility(kObject112082, 111206, Common::Rect(1924, 202, 1975, 291), true, kCursorZoom, 20);
	_app->objectAdd(kObject112083, "", "", 1);
	_app->objectAddRotationAccessibility(kObject112083, 111206, Common::Rect(1800, -100, 1900, 300), true, kCursorIdle, 0);
	_app->objectAddRotationAccessibility(kObject112083, 111206, Common::Rect(1800, -100, 1900, 300), false, kCursorZoom, 2);
	_app->objectAdd(kObjectKey5, "Key", "a11_WDKey", 1);
	_app->objectSetActiveCursor(kObjectKey5, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectKey5, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObject112011, "", "", 1);
	_app->objectAddRotationAccessibility(kObject112011, 111206, Common::Rect(2742, 19, 2823, 101), true, kCursorActionObject, 0);
	_app->objectAddPuzzleAccessibility(kObject112011, kPuzzle112001, Common::Rect(0, 420, 640, 464), true, kCursorBack, 9);
	_app->objectAddPresentation(kObject112011);
	_app->objectPresentationAddAnimationToPuzzle(kObject112011, 0, kPuzzle112001, "a11s02n06p01s13", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1500, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112011);
	_app->objectPresentationAddAnimationToPuzzle(kObject112011, 1, kPuzzle112001, "a11s02n06p01s14", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1500, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112011);
	_app->objectPresentationAddAnimationToPuzzle(kObject112011, 2, kPuzzle112001, "a11s02n06p01s15", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1500, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112011);
	_app->objectPresentationAddAnimationToPuzzle(kObject112011, 3, kPuzzle112001, "a11s02n06p01s16", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1500, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112011);
	_app->objectPresentationAddAnimationToPuzzle(kObject112011, 4, kPuzzle112001, "a11s02n06p01s13", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1500, 10, 12.5f, 10);
	_app->objectAddPresentation(kObject112011);
	_app->objectPresentationAddAnimationToPuzzle(kObject112011, 5, kPuzzle112001, "a11s02n06p01s14", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1500, 10, 12.5f, 10);
	_app->objectAddPresentation(kObject112011);
	_app->objectPresentationAddAnimationToPuzzle(kObject112011, 6, kPuzzle112001, "a11s02n06p01s15", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1500, 10, 12.5f, 10);
	_app->objectAddPresentation(kObject112011);
	_app->objectPresentationAddAnimationToPuzzle(kObject112011, 7, kPuzzle112001, "a11s02n06p01s16", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1500, 10, 12.5f, 10);
	_app->objectAdd(kObject112028, "", "", 1);
	_app->objectAddPresentation(kObject112028);
	_app->objectPresentationAddImageToPuzzle(kObject112028, 0, kPuzzle112001, "a11s02n06p01l13.bmp", Common::Point(264, 173), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject112028);
	_app->objectPresentationAddImageToPuzzle(kObject112028, 1, kPuzzle112001, "a11s02n06p01l14.bmp", Common::Point(264, 173), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObject112015, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject112015, kPuzzle112001, Common::Rect(74, 59, 215, 143), true, kCursorZoom, 0);
	_app->objectAddPuzzleAccessibility(kObject112015, kPuzzle112001, Common::Rect(0, 201, 192, 311), false, kCursorAction, 1);
	_app->objectAddPresentation(kObject112015);
	_app->objectPresentationAddAnimationToPuzzle(kObject112015, 0, kPuzzle112001, "a11s02n06p01s03", kImageTypeBMP, Common::Point(0, 38), kDrawTypeNormal, 1000, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112015);
	_app->objectPresentationAddImageToPuzzle(kObject112015, 1, kPuzzle112001, "a11s02n06p01s03.bmp", Common::Point(0, 38), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject112015);
	_app->objectPresentationAddAnimationToPuzzle(kObject112015, 2, kPuzzle112001, "a11s02n06p01s03", kImageTypeBMP, Common::Point(0, 38), kDrawTypeNormal, 1000, 10, 12.5f, 10);
	_app->objectAddPresentation(kObject112015);
	_app->objectPresentationAddAnimationToPuzzle(kObject112015, 3, kPuzzle112001, "a11s02n06p01s04", kImageTypeBMP, Common::Point(0, 38), kDrawTypeNormal, 1000, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112015);
	_app->objectPresentationAddImageToPuzzle(kObject112015, 4, kPuzzle112001, "a11s02n06p01s04.bmp", Common::Point(0, 38), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject112015);
	_app->objectPresentationAddAnimationToPuzzle(kObject112015, 5, kPuzzle112001, "a11s02n06p01s04", kImageTypeBMP, Common::Point(0, 38), kDrawTypeNormal, 1000, 10, 12.5f, 10);
	_app->objectAddPresentation(kObject112015);
	_app->objectPresentationAddAnimationToPuzzle(kObject112015, 6, kPuzzle112001, "a11s02n06p01s05", kImageTypeBMP, Common::Point(0, 38), kDrawTypeNormal, 1000, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112015);
	_app->objectPresentationAddImageToPuzzle(kObject112015, 7, kPuzzle112001, "a11s02n06p01s05.bmp", Common::Point(0, 38), true, kDrawTypeNormal, 1000);
	_app->objectPresentationAddImageToPuzzle(kObject112015, 7, kPuzzle112005, "a11s02n06p01s05.bmp", Common::Point(0, 38), true, kDrawTypeNormal, 500);
	_app->objectAddPresentation(kObject112015);
	_app->objectPresentationAddAnimationToPuzzle(kObject112015, 8, kPuzzle112001, "a11s02n06p01s05", kImageTypeBMP, Common::Point(0, 38), kDrawTypeNormal, 1000, 10, 12.5f, 10);
	_app->objectAddPresentation(kObject112015);
	_app->objectPresentationAddAnimationToPuzzle(kObject112015, 9, kPuzzle112001, "a11s02n06p01s06", kImageTypeBMP, Common::Point(0, 38), kDrawTypeNormal, 1000, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112015);
	_app->objectPresentationAddImageToPuzzle(kObject112015, 10, kPuzzle112001, "a11s02n06p01s06.bmp", Common::Point(0, 38), true, kDrawTypeNormal, 1000);
	_app->objectPresentationAddImageToPuzzle(kObject112015, 10, kPuzzle112005, "a11s02n06p01s06.bmp", Common::Point(0, 38), true, kDrawTypeNormal, 500);
	_app->objectAddPresentation(kObject112015);
	_app->objectPresentationAddAnimationToPuzzle(kObject112015, 11, kPuzzle112001, "a11s02n06p01s06", kImageTypeBMP, Common::Point(0, 38), kDrawTypeNormal, 1000, 10, 12.5f, 10);
	_app->objectAdd(kObject112014, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject112014, kPuzzle112001, Common::Rect(110, 185, 225, 252), true, kCursorZoom, 0);
	_app->objectAddPuzzleAccessibility(kObject112014, kPuzzle112001, Common::Rect(20, 340, 208, 422), false, kCursorAction, 1);
	_app->objectAddPresentation(kObject112014);
	_app->objectPresentationAddAnimationToPuzzle(kObject112014, 0, kPuzzle112001, "a11s02n06p01s01", kImageTypeBMP, Common::Point(14, 166), kDrawTypeNormal, 1000, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112014);
	_app->objectPresentationAddImageToPuzzle(kObject112014, 1, kPuzzle112001, "a11s02n06p01s01.bmp", Common::Point(14, 166), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject112014);
	_app->objectPresentationAddAnimationToPuzzle(kObject112014, 2, kPuzzle112001, "a11s02n06p01s01", kImageTypeBMP, Common::Point(14, 166), kDrawTypeNormal, 1000, 10, 12.5f, 10);
	_app->objectAddPresentation(kObject112014);
	_app->objectPresentationAddAnimationToPuzzle(kObject112014, 3, kPuzzle112001, "a11s02n06p01s02", kImageTypeBMP, Common::Point(14, 166), kDrawTypeNormal, 1000, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112014);
	_app->objectPresentationAddImageToPuzzle(kObject112014, 4, kPuzzle112001, "a11s02n06p01s02.bmp", Common::Point(14, 166), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject112014);
	_app->objectPresentationAddAnimationToPuzzle(kObject112014, 5, kPuzzle112001, "a11s02n06p01s02", kImageTypeBMP, Common::Point(14, 166), kDrawTypeNormal, 1000, 10, 12.5f, 10);
	_app->objectAdd(kObject112016, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject112016, kPuzzle112001, Common::Rect(246, 54, 390, 146), true, kCursorZoom, 0);
	_app->objectAddPuzzleAccessibility(kObject112016, kPuzzle112001, Common::Rect(217, 197, 409, 303), false, kCursorAction, 1);
	_app->objectAddPresentation(kObject112016);
	_app->objectPresentationAddAnimationToPuzzle(kObject112016, 0, kPuzzle112001, "a11s02n06p01s07", kImageTypeBMP, Common::Point(199, 39), kDrawTypeNormal, 1000, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112016);
	_app->objectPresentationAddImageToPuzzle(kObject112016, 1, kPuzzle112001, "a11s02n06p01s07.bmp", Common::Point(199, 39), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject112016);
	_app->objectPresentationAddAnimationToPuzzle(kObject112016, 2, kPuzzle112001, "a11s02n06p01s07", kImageTypeBMP, Common::Point(199, 39), kDrawTypeNormal, 1000, 10, 12.5f, 10);
	_app->objectAddPresentation(kObject112016);
	_app->objectPresentationAddAnimationToPuzzle(kObject112016, 3, kPuzzle112001, "a11s02n06p01s07a", kImageTypeBMP, Common::Point(199, 39), kDrawTypeNormal, 1000, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112016);
	_app->objectPresentationAddImageToPuzzle(kObject112016, 4, kPuzzle112001, "a11s02n06p01s07.bmp", Common::Point(199, 39), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject112016);
	_app->objectPresentationAddAnimationToPuzzle(kObject112016, 5, kPuzzle112001, "a11s02n06p01s07a", kImageTypeBMP, Common::Point(199, 39), kDrawTypeNormal, 1000, 10, 12.5f, 10);
	_app->objectAdd(kObject112017, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject112017, kPuzzle112001, Common::Rect(430, 59, 560, 147), true, kCursorZoom, 0);
	_app->objectAddPuzzleAccessibility(kObject112017, kPuzzle112001, Common::Rect(471, 205, 632, 292), false, kCursorAction, 1);
	_app->objectAddPresentation(kObject112017);
	_app->objectPresentationAddAnimationToPuzzle(kObject112017, 0, kPuzzle112001, "a11s02n06p01s08", kImageTypeBMP, Common::Point(411, 41), kDrawTypeNormal, 1000, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112017);
	_app->objectPresentationAddImageToPuzzle(kObject112017, 1, kPuzzle112001, "a11s02n06p01s08.bmp", Common::Point(411, 41), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject112017);
	_app->objectPresentationAddAnimationToPuzzle(kObject112017, 2, kPuzzle112001, "a11s02n06p01s08", kImageTypeBMP, Common::Point(411, 41), kDrawTypeNormal, 1000, 10, 12.5f, 10);
	_app->objectAddPresentation(kObject112017);
	_app->objectPresentationAddAnimationToPuzzle(kObject112017, 3, kPuzzle112001, "a11s02n06p01s09", kImageTypeBMP, Common::Point(411, 41), kDrawTypeNormal, 1000, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112017);
	_app->objectPresentationAddImageToPuzzle(kObject112017, 4, kPuzzle112001, "a11s02n06p01s09.bmp", Common::Point(411, 41), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject112017);
	_app->objectPresentationAddAnimationToPuzzle(kObject112017, 5, kPuzzle112001, "a11s02n06p01s09", kImageTypeBMP, Common::Point(411, 41), kDrawTypeNormal, 1000, 10, 12.5f, 10);
	_app->objectAdd(kObject112018, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject112018, kPuzzle112001, Common::Rect(425, 187, 528, 261), true, kCursorZoom, 0);
	_app->objectAddPuzzleAccessibility(kObject112018, kPuzzle112001, Common::Rect(418, 238, 562, 321), false, kCursorAction, 1);
	_app->objectAddPuzzleAccessibility(kObject112018, kPuzzle112001, Common::Rect(431, 338, 617, 415), false, kCursorAction, 1);
	_app->objectAddPresentation(kObject112018);
	_app->objectPresentationAddAnimationToPuzzle(kObject112018, 0, kPuzzle112001, "a11s02n06p01s10", kImageTypeBMP, Common::Point(399, 163), kDrawTypeNormal, 1100, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112018);
	_app->objectPresentationAddImageToPuzzle(kObject112018, 1, kPuzzle112001, "a11s02n06p01s10.bmp", Common::Point(399, 163), true, kDrawTypeNormal, 1100);
	_app->objectAddPresentation(kObject112018);
	_app->objectPresentationAddAnimationToPuzzle(kObject112018, 2, kPuzzle112001, "a11s02n06p01s10", kImageTypeBMP, Common::Point(399, 163), kDrawTypeNormal, 1100, 10, 12.5f, 10);
	_app->objectAddPresentation(kObject112018);
	_app->objectPresentationAddAnimationToPuzzle(kObject112018, 3, kPuzzle112001, "a11s02n06p01s11a", kImageTypeBMP, Common::Point(399, 156), kDrawTypeNormal, 1100, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112018);
	_app->objectPresentationAddImageToPuzzle(kObject112018, 4, kPuzzle112001, "a11s02n06p01s11.bmp", Common::Point(399, 156), true, kDrawTypeNormal, 1100);
	_app->objectAddPresentation(kObject112018);
	_app->objectPresentationAddAnimationToPuzzle(kObject112018, 5, kPuzzle112001, "a11s02n06p01s11a", kImageTypeBMP, Common::Point(399, 156), kDrawTypeNormal, 1100, 10, 12.5f, 10);
	_app->objectAddPresentation(kObject112018);
	_app->objectPresentationAddAnimationToPuzzle(kObject112018, 6, kPuzzle112001, "a11s02n06p01s12a", kImageTypeBMP, Common::Point(399, 156), kDrawTypeNormal, 1100, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112018);
	_app->objectPresentationAddImageToPuzzle(kObject112018, 7, kPuzzle112001, "a11s02n06p01s12.bmp", Common::Point(399, 156), true, kDrawTypeNormal, 1100);
	_app->objectAddPresentation(kObject112018);
	_app->objectPresentationAddAnimationToPuzzle(kObject112018, 8, kPuzzle112001, "a11s02n06p01s12a", kImageTypeBMP, Common::Point(399, 156), kDrawTypeNormal, 1100, 10, 12.5f, 10);
	_app->objectAddPresentation(kObject112018);
	_app->objectPresentationAddAnimationToPuzzle(kObject112018, 9, kPuzzle112001, "a11s02n06p01s11", kImageTypeBMP, Common::Point(399, 156), kDrawTypeNormal, 1100, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112018);
	_app->objectPresentationAddImageToPuzzle(kObject112018, 10, kPuzzle112001, "a11s02n06p01s11.bmp", Common::Point(399, 156), true, kDrawTypeNormal, 1100);
	_app->objectAddPresentation(kObject112018);
	_app->objectPresentationAddAnimationToPuzzle(kObject112018, 11, kPuzzle112001, "a11s02n06p01s11", kImageTypeBMP, Common::Point(399, 156), kDrawTypeNormal, 1100, 10, 12.5f, 10);
	_app->objectAddPresentation(kObject112018);
	_app->objectPresentationAddAnimationToPuzzle(kObject112018, 12, kPuzzle112001, "a11s02n06p01s12", kImageTypeBMP, Common::Point(399, 156), kDrawTypeNormal, 1100, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject112018);
	_app->objectPresentationAddImageToPuzzle(kObject112018, 13, kPuzzle112001, "a11s02n06p01s12.bmp", Common::Point(399, 156), true, kDrawTypeNormal, 1100);
	_app->objectAddPresentation(kObject112018);
	_app->objectPresentationAddAnimationToPuzzle(kObject112018, 14, kPuzzle112001, "a11s02n06p01s12", kImageTypeBMP, Common::Point(399, 156), kDrawTypeNormal, 1100, 10, 12.5f, 10);
	_app->objectAdd(kObject112027, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject112027, kPuzzle112001, Common::Rect(281, 108, 346, 194), false, kCursorZoom, 0);
	_app->objectAddPuzzleAccessibility(kObject112027, kPuzzle112002, Common::Rect(100,  50, 540, 410), false, kCursorZoom, 5);
	_app->objectAdd(kObjectGeologicalSurveyMap, "Geological Survey Map", "a11_GeoMap", 1);
	_app->objectSetActiveCursor(kObjectGeologicalSurveyMap, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectGeologicalSurveyMap, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectGeologicalSurveyMap, kPuzzle112001, Common::Rect(521, 362, 568, 442), true, kCursorTake, 0);
	_app->objectAddRotationAccessibility(kObjectGeologicalSurveyMap, 111401, Common::Rect(1703, 36, 1850, 176), true, kCursorZoom, 1);
	_app->objectAddPresentation(kObjectGeologicalSurveyMap);
	_app->objectPresentationAddImageToPuzzle(kObjectGeologicalSurveyMap, 0, kPuzzle112001, "a11s02n06p01l15.bmp", Common::Point(522, 351), true, kDrawTypeNormal, 1000);
	_app->objectPresentationAddImageToPuzzle(kObjectGeologicalSurveyMap, 0, kPuzzle112005, "a11s02n06p01l15.bmp", Common::Point(522, 351), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObject112001, "", "", 1);
	_app->objectAddRotationAccessibility(kObject112001, 111206, Common::Rect(1657, -48, 1691, -27), true, kCursorIdle, 0);
	_app->objectAddRotationAccessibility(kObject112001, 111206, Common::Rect(1655,   5, 1692,  24), true, kCursorIdle, 1);
	_app->objectAddRotationAccessibility(kObject112001, 111206, Common::Rect(1659,  68, 1692,  88), true, kCursorIdle, 2);
	_app->objectAddRotationAccessibility(kObject112001, 111206, Common::Rect(1657, 137, 1689, 160), true, kCursorIdle, 3);
	_app->objectAddRotationAccessibility(kObject112001, 111206, Common::Rect(1655, 205, 1692, 233), true, kCursorIdle, 4);
	_app->objectAddRotationAccessibility(kObject112001, 111206, Common::Rect(1657, 270, 1692, 293), true, kCursorIdle, 5);
	_app->objectAddRotationAccessibility(kObject112001, 111206, Common::Rect(1657, 308, 1691, 334), true, kCursorIdle, 6);
	_app->objectAddRotationAccessibility(kObject112001, 111206, Common::Rect(1784, -69, 1838, -36), true, kCursorIdle, 7);
	_app->objectAddRotationAccessibility(kObject112001, 111206, Common::Rect(1784,  31, 1843,  59), true, kCursorIdle, 8);
	_app->objectAddRotationAccessibility(kObject112001, 111206, Common::Rect(1782, 143, 1843, 179), true, kCursorIdle, 9);
	_app->objectAddRotationAccessibility(kObject112001, 111206, Common::Rect(1782, 249, 1842, 284), true, kCursorIdle, 10);
	_app->objectAddRotationAccessibility(kObject112001, 111206, Common::Rect(1782, 333, 1843, 364), true, kCursorIdle, 11);
	_app->objectAddRotationAccessibility(kObject112001, 111206, Common::Rect(1782, 387, 1842, 415), true, kCursorIdle, 12);
	_app->objectAddRotationAccessibility(kObject112001, 111206, Common::Rect(2017,  69, 2088, 104), true, kCursorIdle, 13);
	_app->objectAddRotationAccessibility(kObject112001, 111206, Common::Rect(2012, 177, 2090, 214), true, kCursorIdle, 14);
	_app->objectAddRotationAccessibility(kObject112001, 111206, Common::Rect(2016, 284, 2091, 317), true, kCursorIdle, 15);
	_app->objectAddRotationAccessibility(kObject112001, 111206, Common::Rect(2014, 376, 2090, 408), true, kCursorIdle, 16);
	_app->objectAddRotationAccessibility(kObject112001, 111207, Common::Rect(1040, 266, 1098, 306), false, kCursorIdle, 44);
	_app->objectAddRotationAccessibility(kObject112001, 111207, Common::Rect(1284, -43, 1357, -15), false, kCursorIdle, 45);
	_app->objectAddRotationAccessibility(kObject112001, 111207, Common::Rect(1284,  91, 1355, 127), false, kCursorIdle, 46);
	_app->objectAddRotationAccessibility(kObject112001, 111207, Common::Rect(1284, 215, 1357, 248), false, kCursorIdle, 47);
	_app->objectAddRotationAccessibility(kObject112001, 111207, Common::Rect(1284, 313, 1357, 341), false, kCursorIdle, 48);
	_app->objectAddRotationAccessibility(kObject112001, 111207, Common::Rect(1284, 373, 1357, 401), false, kCursorIdle, 49);
	_app->objectAddRotationAccessibility(kObject112001, 111207, Common::Rect(1487, -47, 1553, -14), false, kCursorIdle, 50);
	_app->objectAddRotationAccessibility(kObject112001, 111207, Common::Rect(1483,  91, 1553, 120), false, kCursorIdle, 51);
	_app->objectAddRotationAccessibility(kObject112001, 111207, Common::Rect(1488, 203, 1560, 241), false, kCursorIdle, 52);
	_app->objectAddRotationAccessibility(kObject112001, 111207, Common::Rect(1495, 304, 1566, 338), false, kCursorIdle, 53);
	_app->objectAddRotationAccessibility(kObject112001, 111207, Common::Rect(1494, 369, 1567, 396), false, kCursorIdle, 54);
	_app->objectAddRotationAccessibility(kObject112001, 111207, Common::Rect(1645, -43, 1701,  -5), false, kCursorIdle, 55);
	_app->objectAddRotationAccessibility(kObject112001, 111207, Common::Rect(1645,  73, 1701, 108), false, kCursorIdle, 56);
	_app->objectAdd(kObjectPaperKnife, "Paper Knife", "a11_PaperKnife", 1);
	_app->objectSetActiveCursor(kObjectPaperKnife, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectPaperKnife, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectPaperKnife, kPuzzle112001, Common::Rect(155, 221, 189, 282), false, kCursorTake, 0);
	_app->objectAdd(kObjectRedWax, "Red Wax", "a11_WaxRed", 1);
	_app->objectSetActiveCursor(kObjectRedWax, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectRedWax, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectRedWax, kPuzzle112001, Common::Rect(89, 114, 170, 196), false, kCursorTake, 0);
	_app->objectAdd(kObjectWhiteWax, "White Wax", "a11_WaxWhite", 1);
	_app->objectSetActiveCursor(kObjectWhiteWax, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectWhiteWax, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectBlackWax, "Black Wax", "a11_WaxBlack", 1);
	_app->objectSetActiveCursor(kObjectBlackWax, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectBlackWax, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectSealingRing, "Seal Ring", "a11_SealRing", 1);
	_app->objectSetActiveCursor(kObjectSealingRing, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectSealingRing, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectSealingRing, kPuzzle112001, Common::Rect(132, 102, 185, 153), false, kCursorTake, 0);
	_app->objectAddPresentation(kObjectSealingRing);
	_app->objectPresentationAddImageToPuzzle(kObjectSealingRing, 0, kPuzzle112005, "a11s02n06p09l01.tga", Common::Point(188, 96), true, kDrawTypeAlpha, 1000);
	_app->objectAdd(kObjectMagnifyingGlass2, "Magnifying glass", "a11_MagGlass", 1);
	_app->objectSetActiveCursor(kObjectMagnifyingGlass2, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectMagnifyingGlass2, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectMagnifyingGlass2, kPuzzle112001, Common::Rect(463, 123, 531, 190), false, kCursorTake, 0);
	_app->objectAdd(kObjectWoodenHead, "Wooden Head", "a11_HercHead", 1);
	_app->objectSetActiveCursor(kObjectWoodenHead, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectWoodenHead, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectWoodenHead, kPuzzle112001, Common::Rect(431, 198, 511, 247), false, kCursorTake, 0);
	_app->objectAddRotationAccessibility(kObjectWoodenHead, 111206, Common::Rect(2515, 463, 2601, 507), true, kCursorActionObject, 1);
	_app->objectAddRotationAccessibility(kObjectWoodenHead, 111206, Common::Rect(2515, 463, 2601, 507), true, kCursorActionObject, 2);
	_app->objectAddPresentation(kObjectWoodenHead);
	_app->objectPresentationAddImageToRotation(kObjectWoodenHead, 0, 111206, 3);
	_app->objectPresentationAddImageToRotation(kObjectWoodenHead, 0, 111205, 7);
	_app->objectPresentationAddImageToRotation(kObjectWoodenHead, 0, 111207, 2);
	_app->objectAddPresentation(kObjectWoodenHead);
	_app->objectPresentationAddAnimationToRotation(kObjectWoodenHead, 1, 111206, 4, 15, 12.5f, 6);
	_app->objectAddPresentation(kObjectWoodenHead);
	_app->objectPresentationAddAnimationToRotation(kObjectWoodenHead, 2, 111206, 4, 15, 12.5f, 10);
	_app->objectAdd(kObjectTape1, "Tape 1", "a11_Tape", 1);
	_app->objectSetActiveCursor(kObjectTape1, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectTape1, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectTape1, kPuzzle112010, Common::Rect(253, 211, 483, 300), true, kCursorTake, 0);
	_app->objectAddPuzzleAccessibility(kObjectTape1, kPuzzle112010, Common::Rect(399,  72, 496, 142), true, kCursorAction, 1);
	_app->objectAddPuzzleAccessibility(kObjectTape1, kPuzzle112010, Common::Rect(423, 145, 467, 184), true, kCursorMenuActive, 2);
	_app->objectAddPuzzleAccessibility(kObjectTape1, kPuzzle112010, Common::Rect(394, 155, 431, 190), false, kCursorMenuActive, 3);
	_app->objectAddPresentation(kObjectTape1);
	_app->objectPresentationAddImageToPuzzle(kObjectTape1, 0, kPuzzle112010, "a11s02n06p05l03.bmp", Common::Point(253, 211), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObjectTape1);
	_app->objectPresentationAddImageToPuzzle(kObjectTape1, 1, kPuzzle112010, "a11s02n06p05l02.bmp", Common::Point(379, 54), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObjectTape1);
	_app->objectPresentationAddImageToPuzzle(kObjectTape1, 2, kPuzzle112010, "a11s02n06p05l01.bmp", Common::Point(334, 318), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObjectTape1);
	_app->objectPresentationAddAnimationToPuzzle(kObjectTape1, 3, kPuzzle112010, "a11s02n06p05s01", kImageTypeBMP, Common::Point(278, 63), kDrawTypeNormal, 1000, 20, 12.5f, 8);
	_app->objectPresentationAddImageToPuzzle(kObjectTape1, 3, kPuzzle112010, "a11s02n06p05l04.bmp", Common::Point(424, 147), true, kDrawTypeNormal, 1100);
	_app->objectAddPresentation(kObjectTape1);
	_app->objectPresentationAddImageToPuzzle(kObjectTape1, 4, kPuzzle112010, "a11s02n06p05l05.bmp", Common::Point(394, 152), true, kDrawTypeNormal, 1100);
	_app->objectAdd(kObjectTape2, "Tape 2", "a11_Tape", 1);
	_app->objectSetActiveCursor(kObjectTape2, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectTape2, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectTape3, "Tape 3", "a11_Tape", 1);
	_app->objectSetActiveCursor(kObjectTape3, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectTape3, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectTape4, "Tape 4", "a11_Tape", 1);
	_app->objectAddPuzzleAccessibility(kObjectTape4, kPuzzle112001, Common::Rect(284, 175, 354, 219), false, kCursorTake, 0);
	_app->objectSetActiveCursor(kObjectTape4, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectTape4, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObject112036, "", "", 1);
	_app->objectAddRotationAccessibility(kObject112036, 111206, Common::Rect(907, 141, 1005, 213), true, kCursorZoom, 0);
	_app->objectAdd(kObject114527, "", "", 1);
	_app->objectAddRotationAccessibility(kObject114527, 111206, Common::Rect(794, 261, 901, 436), true, kCursorZoom, 0);
	_app->objectAddPuzzleAccessibility(kObject114527, kPuzzle112014, Common::Rect(0, 420, 640, 464), true, kCursorBack, 9);
	_app->objectAddPresentation(kObject114527);
	_app->objectPresentationAddAnimationToRotation(kObject114527, 0, 111206, 1, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject114527);
	_app->objectPresentationAddAnimationToRotation(kObject114527, 1, 111206, 1, 10, 12.5f, 10);
	_app->objectAdd(kObjectMatches3, "Matches", "a11_Matchbox", 1);
	_app->objectSetActiveCursor(kObjectMatches3, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectMatches3, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectMatches3, kPuzzle112014, Common::Rect(334, 272, 447, 376), true, kCursorTake, 0);
	_app->objectAddPuzzleAccessibility(kObjectMatches3, kPuzzle112014, Common::Rect(276, 121, 358, 202), true, kCursorTake, 1);
	_app->objectAddPuzzleAccessibility(kObjectMatches3, kPuzzle112014, Common::Rect(357, 185, 470, 275), true, kCursorTake, 1);
	_app->objectAddPresentation(kObjectMatches3);
	_app->objectPresentationAddImageToPuzzle(kObjectMatches3, 0, kPuzzle112014, "a11s02n06p02l02.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObjectMatches3);
	_app->objectPresentationAddImageToPuzzle(kObjectMatches3, 1, kPuzzle112014, "a11s02n06p02l03.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObjectMatches3);
	_app->objectPresentationAddImageToPuzzle(kObjectMatches3, 2, kPuzzle112014, "a11s02n06p02l04.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObjectPipe, "Pipe", "a11_Pipe", 1);
	_app->objectSetActiveCursor(kObjectPipe, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectPipe, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectPipe, kPuzzleMenu, Common::Rect(410, 110, 576, 289), false, kCursorAction, 0);
	_app->objectAddPuzzleAccessibility(kObjectPipe, kPuzzleMenu, Common::Rect(420, 197, 630, 371), false, kCursorAction, 0);
	_app->objectAddPuzzleAccessibility(kObjectPipe, kPuzzleMenu, Common::Rect(  0,   0, 640, 480), false, kCursorBack, 9);
	_app->objectAdd(kObjectShowel, "Showel", "a11_Showel", 1);
	_app->objectSetActiveCursor(kObjectShowel, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectShowel, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddRotationAccessibility(kObjectShowel, 111205, Common::Rect(796, 231, 889, 438), false, kCursorTake, 0);
	_app->objectAddPresentation(kObjectShowel);
	_app->objectPresentationAddImageToRotation(kObjectShowel, 0, 111205, 2);
	_app->objectPresentationShow(kObjectShowel, 0);
	_app->objectAdd(kObject112035, "", "", 1);
	_app->objectAddRotationAccessibility(kObject112035, 111205, Common::Rect(534, 175, 857, 415), true, kCursorZoom, 1);
	_app->objectAddPuzzleAccessibility(kObject112035, kPuzzle112000, Common::Rect(130, 158, 199, 246), true, kCursorZoom, 0);
	_app->objectAdd(kObject112033, "", "", 1);
	_app->objectAddRotationAccessibility(kObject112033, 111205, Common::Rect(1100, 348, 1233, 451), true, kCursorZoom, 0);
	_app->objectAdd(kObject112032, "", "", 1);
	_app->objectAddRotationAccessibility(kObject112032, 111205, Common::Rect(2930, -6, 3382, 258), true, kCursorZoom, 0);
	_app->objectAddRotationAccessibility(kObject112032, 111205, Common::Rect(3461, -5, 3600, 197), true, kCursorZoom, 1);
	_app->objectAddRotationAccessibility(kObject112032, 111205, Common::Rect(0, -5, 105, 197), true, kCursorZoom, 1);
	_app->objectAddRotationAccessibility(kObject112032, 111205, Common::Rect(128, -12, 235, 137), true, kCursorZoom, 2);
	_app->objectAddPuzzleAccessibility(kObject112032, kPuzzle112011, Common::Rect(72, 82, 560, 398), false, kCursorZoom, 3);
	_app->objectAddPresentation(kObject112032);
	_app->objectPresentationAddImageToPuzzle(kObject112032, 0, kPuzzle112011, "a11s02n05p04l01.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObject114201, "", "", 1);
	_app->objectAddRotationAccessibility(kObject114201, 111401, Common::Rect(1678, -115, 1886, 296), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject114201, 111401, Common::Rect(1699,   35, 1863, 173), true, kCursorAction, 1);
	_app->objectAddRotationAccessibility(kObject114201, 111401, Common::Rect(1494, -112, 1666, 315), true, kCursorAction, 2);
	_app->objectAddPresentation(kObject114201);
	_app->objectPresentationAddAnimationToRotation(kObject114201, 0, 111401, 5, 8, 12.5f, 6);
	_app->objectAddPresentation(kObject114201);
	_app->objectPresentationAddAnimationToRotation(kObject114201, 1, 111401, 5, 8, 12.5f, 10);
	_app->objectAddPresentation(kObject114201);
	_app->objectPresentationAddAnimationToRotation(kObject114201, 2, 111401, 6, 8, 12.5f, 6);
	_app->objectAddPresentation(kObject114201);
	_app->objectPresentationAddAnimationToRotation(kObject114201, 3, 111401, 6, 8, 12.5f, 10);
	_app->objectAddPresentation(kObject114201);
	_app->objectPresentationAddImageToRotation(kObject114201, 4, 111401, 7);
	_app->objectAddPresentation(kObject114201);
	_app->objectPresentationAddImageToRotation(kObject114201, 5, 111401, 0);
	_app->objectPresentationAddImageToPuzzle(kObject114201, 5, kPuzzle114032, "a11s04n01p13l01.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObject114001, "", "CUR_DRAG", 4);
	_app->objectSetActiveDrawCursor(kObject114001, Common::Point(15, 15), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveDrawCursor(kObject114001, Common::Point(15, 15), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObject114001, kPuzzle114001, Common::Rect(257, 293, 387, 415), true, kCursorDragDrop, 0);
	_app->varDefineWord(114001, 320);
	_app->varDefineWord(114005, 356);
	_app->objectAddPuzzleAccessibility(kObject114001, kPuzzle114002, Common::Rect(257, 292, 389, 413), true, kCursorDragDrop, 1);
	_app->varDefineWord(114002, 325);
	_app->varDefineWord(114006, 355);
	_app->objectAddPuzzleAccessibility(kObject114001, kPuzzle114003, Common::Rect(257, 293, 387, 415), true, kCursorDragDrop, 2);
	_app->varDefineWord(114003, 320);
	_app->varDefineWord(114007, 356);
	_app->objectAddPuzzleAccessibility(kObject114001, kPuzzle114004, Common::Rect(257, 292, 389, 413), true, kCursorDragDrop, 3);
	_app->varDefineWord(114004, 320);
	_app->varDefineWord(114008, 358);
	_app->objectAddPresentation(kObject114001);
	_app->objectPresentationAddAnimationToRotation(kObject114001, 0, 111401, 1, 8, 12.5f, 6);
	_app->objectAddPresentation(kObject114001);
	_app->objectPresentationAddImageToRotation(kObject114001, 1, 111401, 0);
	_app->objectAddPresentation(kObject114001);
	_app->objectPresentationAddImageToRotation(kObject114001, 2, 111401, 4);
	_app->objectPresentationAddImageToRotation(kObject114001, 2, 111401, 8);
	_app->objectAdd(kObject114002, "", "", 1);

	for (uint32 i = 0; i < 36; i++) {
		_app->objectAddPresentation(kObject114002);
		_app->objectPresentationAddImageToPuzzle(kObject114002, i, kPuzzle114001, Common::String::format("a11s04n01p01s01.%04d.bmp", i + 1), Common::Point(251, 286), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject114003, "", "", 1);

	for (uint32 i = 0; i < 36; i++) {
		_app->objectAddPresentation(kObject114003);
		_app->objectPresentationAddImageToPuzzle(kObject114003, i, kPuzzle114002, Common::String::format("a11s04n01p02s01.%04d.bmp", i + 1), Common::Point(256, 287), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject114004, "", "", 1);

	for (uint32 i = 0; i < 36; i++) {
		_app->objectAddPresentation(kObject114004);
		_app->objectPresentationAddImageToPuzzle(kObject114004, i, kPuzzle114003, Common::String::format("a11s04n01p03s01.%04d.bmp", i + 1), Common::Point(253, 288), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject114005, "", "", 1);

	for (uint32 i = 0; i < 36; i++) {
		_app->objectAddPresentation(kObject114005);
		_app->objectPresentationAddImageToPuzzle(kObject114005, i, kPuzzle114004, Common::String::format("a11s04n01p04s01.%04d.bmp", i + 1), Common::Point(250, 289), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject114006, "", "", 1);
	_app->objectAddRotationAccessibility(kObject114006, 111401, Common::Rect(200, 265, 390, 371), false, kCursorIdle, 0);
	_app->objectAddRotationAccessibility(kObject114006, 111401, Common::Rect(200, 265, 390, 371), false, kCursorZoom, 1);
	_app->objectAddPuzzleAccessibility(kObject114006, kPuzzle114005, Common::Rect(291, 216, 337, 253), true, kCursorZoom, 2);
	_app->objectAddPuzzleAccessibility(kObject114006, kPuzzle114005, Common::Rect(291, 216, 337, 253), false, kCursorTake, 3);
	_app->objectAddPuzzleAccessibility(kObject114006, kPuzzle114005, Common::Rect(147, 152, 458, 372), false, kCursorIdle, 4);
	_app->objectAddPuzzleAccessibility(kObject114006, kPuzzle114005, Common::Rect(147, 152, 458, 372), false, kCursorAction, 5);
	_app->objectAddPuzzleAccessibility(kObject114006, kPuzzle114005, Common::Rect(147, 152, 458, 372), false, kCursorIdle, 6);
	_app->objectAddPuzzleAccessibility(kObject114006, kPuzzle114005, Common::Rect(147, 152, 458, 372), false, kCursorZoom, 7);
	_app->objectAddPuzzleAccessibility(kObject114006, kPuzzle114005, Common::Rect(252, 272, 344, 326), false, kCursorTake, 8);
	_app->objectAddPuzzleAccessibility(kObject114006, kPuzzle114005, Common::Rect(  0, 420, 640, 464), true, kCursorBack, 99);
	_app->objectAddPuzzleAccessibility(kObject114006, kPuzzle114034, Common::Rect(245, 167, 355, 261), true, kCursorActionObject, 2);
	_app->objectAddPresentation(kObject114006);
	_app->objectPresentationAddImageToPuzzle(kObject114006, 0, kPuzzle114005, "a11s04n01p05l01.bmp", Common::Point(260, 95), true, kDrawTypeNormal, 800);
	_app->objectPresentationAddAnimationToPuzzle(kObject114006, 0, kPuzzle114005, "a11s04n01p05s01", kImageTypeBMP, Common::Point(245, 88), kDrawTypeNormal, 1000, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject114006);
	_app->objectPresentationAddAnimationToPuzzle(kObject114006, 1, kPuzzle114005, "a11s04n01p05s01", kImageTypeBMP, Common::Point(245, 88), kDrawTypeNormal, 1000, 10, 12.5f, 10);
	_app->objectAddPresentation(kObject114006);
	_app->objectPresentationAddImageToPuzzle(kObject114006, 2, kPuzzle114005, "a11s04n01p05l01.bmp", Common::Point(260, 95), true, kDrawTypeNormal, 200);
	_app->objectPresentationAddImageToPuzzle(kObject114006, 2, kPuzzle114005, "a11s04n01p05l02.bmp", Common::Point(280, 219), true, kDrawTypeNormal, 300);
	_app->objectPresentationAddAnimationToPuzzle(kObject114006, 2, kPuzzle114005, "a11s04n01p05s02", kImageTypeBMP, Common::Point(245, 88), kDrawTypeNormal, 1000, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject114006);
	_app->objectPresentationAddAnimationToPuzzle(kObject114006, 3, kPuzzle114005, "a11s04n01p05s02", kImageTypeBMP, Common::Point(245, 88), kDrawTypeNormal, 1000, 10, 12.5f, 10);
	_app->objectAddPresentation(kObject114006);
	_app->objectPresentationAddImageToPuzzle(kObject114006, 4, kPuzzle114005, "a11s04n01p05l02.bmp", Common::Point(280, 219), true, kDrawTypeNormal, 800);
	_app->objectAddPresentation(kObject114006);
	_app->objectPresentationAddImageToPuzzle(kObject114006, 5, kPuzzle114005, "a11s04n01p05l03.bmp", Common::Point(59, 29), true, kDrawTypeNormal, 800);
	_app->objectPresentationAddAnimationToPuzzle(kObject114006, 5, kPuzzle114005, "a11s04n01p05s03", kImageTypeBMP, Common::Point(62, 16), kDrawTypeNormal, 1000, 15, 12.5f, 6);
	_app->objectAddPresentation(kObject114006);
	_app->objectPresentationAddAnimationToPuzzle(kObject114006, 6, kPuzzle114005, "a11s04n01p05s03", kImageTypeBMP, Common::Point(62, 16), kDrawTypeNormal, 1000, 15, 12.5f, 10);
	_app->objectAddPresentation(kObject114006);
	_app->objectPresentationAddImageToPuzzle(kObject114006, 7, kPuzzle114005, "a11s04n01p05l04.bmp", Common::Point(132, 19), true, kDrawTypeNormal, 800);
	_app->objectPresentationAddAnimationToPuzzle(kObject114006, 7, kPuzzle114005, "a11s04n01p05s04", kImageTypeBMP, Common::Point(131, 16), kDrawTypeNormal, 1000, 15, 12.5f, 6);
	_app->objectAddPresentation(kObject114006);
	_app->objectPresentationAddAnimationToPuzzle(kObject114006, 8, kPuzzle114005, "a11s04n01p05s04", kImageTypeBMP, Common::Point(131, 16), kDrawTypeNormal, 1000, 15, 12.5f, 10);
	_app->objectAdd(kObject22, "", "", 3);
	_app->objectAddPuzzleAccessibility(kObject22, kPuzzleMenu, Common::Rect(253, 233, 383, 354), false, kCursorAction, 0);
	_app->objectAddPuzzleAccessibility(kObject22, kPuzzleMenu, Common::Rect(355, 241, 390, 280), false, kCursorDefault, 2);
	_app->objectAddPuzzleAccessibility(kObject22, kPuzzleMenu, Common::Rect(  0,   0, 640, 480), false, kCursorDefault, 1);
	_app->objectAddPuzzleAccessibility(kObject22, kPuzzle114017, Common::Rect(0, 0, 640, 420), false, kCursorIdle, 77);
	_app->objectAdd(kObject114007, "", "CUR_DRAG", 4);
	_app->objectSetActiveDrawCursor(kObject114007, Common::Point(15, 15), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveDrawCursor(kObject114007, Common::Point(15, 15), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObject114007, kPuzzle114006, Common::Rect(270,  76, 360, 119), true, kCursorDragDrop, 0);
	_app->objectAddPuzzleAccessibility(kObject114007, kPuzzle114006, Common::Rect(270, 123, 360, 165), true, kCursorDragDrop, 1);
	_app->objectAddPuzzleAccessibility(kObject114007, kPuzzle114006, Common::Rect(270, 170, 360, 214), true, kCursorDragDrop, 2);
	_app->objectAddPuzzleAccessibility(kObject114007, kPuzzle114006, Common::Rect(270, 218, 360, 261), true, kCursorDragDrop, 3);
	_app->objectAddPuzzleAccessibility(kObject114007, kPuzzle114006, Common::Rect(270, 265, 360, 307), true, kCursorDragDrop, 4);
	_app->objectAddPuzzleAccessibility(kObject114007, kPuzzle114006, Common::Rect(270, 311, 360, 354), true, kCursorDragDrop, 5);
	_app->objectAddPuzzleAccessibility(kObject114007, kPuzzle114006, Common::Rect(270, 358, 360, 401), true, kCursorDragDrop, 6);
	_app->objectAddPresentation(kObject114007);
	_app->objectPresentationAddAnimationToRotation(kObject114007, 0, 111401, 10, 10, 12.5f, 4);
	_app->objectPresentationAddAnimationToRotation(kObject114007, 0, 111403, 1, 10, 12.5f, 4);
	_app->objectPresentationAddAnimationToRotation(kObject114007, 0, 111405, 0, 10, 12.5f, 4);
	_app->objectPresentationShow(kObject114007, 0);
	_app->objectAdd(kObject114010, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject114010, kPuzzle114006, Common::Rect(0, 420, 640, 464), true, kCursorBack, 9);

	for (uint32 i = 0; i < 10; i++) {
		_app->objectAddPresentation(kObject114010);
		_app->objectPresentationAddImageToPuzzle(kObject114010, i, kPuzzle114006, Common::String::format("a11s04n01p06s01.%04d.bmp", i + 1), Common::Point(267, 77), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject114011, "", "", 1);

	for (uint32 i = 0; i < 10; i++) {
		_app->objectAddPresentation(kObject114011);
		_app->objectPresentationAddImageToPuzzle(kObject114011, i, kPuzzle114006, Common::String::format("a11s04n01p06s02.%04d.bmp", i + 1), Common::Point(268, 124), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject114012, "", "", 1);

	for (uint32 i = 0; i < 10; i++) {
		_app->objectAddPresentation(kObject114012);
		_app->objectPresentationAddImageToPuzzle(kObject114012, i, kPuzzle114006, Common::String::format("a11s04n01p06s03.%04d.bmp", i + 1), Common::Point(269, 172), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject114013, "", "", 1);

	for (uint32 i = 0; i < 10; i++) {
		_app->objectAddPresentation(kObject114013);
		_app->objectPresentationAddImageToPuzzle(kObject114013, i, kPuzzle114006, Common::String::format("a11s04n01p06s04.%04d.bmp", i + 1), Common::Point(269, 219), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject114014, "", "", 1);

	for (uint32 i = 0; i < 10; i++) {
		_app->objectAddPresentation(kObject114014);
		_app->objectPresentationAddImageToPuzzle(kObject114014, i, kPuzzle114006, Common::String::format("a11s04n01p06s05.%04d.bmp", i + 1), Common::Point(271, 267), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject114015, "", "", 1);

	for (uint32 i = 0; i < 10; i++) {
		_app->objectAddPresentation(kObject114015);
		_app->objectPresentationAddImageToPuzzle(kObject114015, i, kPuzzle114006, Common::String::format("a11s04n01p06s06.%04d.bmp", i + 1), Common::Point(270, 312), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject114016, "", "", 1);

	for (uint32 i = 0; i < 10; i++) {
		_app->objectAddPresentation(kObject114016);
		_app->objectPresentationAddImageToPuzzle(kObject114016, i, kPuzzle114006, Common::String::format("a11s04n01p06s07.%04d.bmp", i + 1), Common::Point(270, 358), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject114020, "", "", 1);
	_app->objectAddRotationAccessibility(kObject114020, 111401, Common::Rect(2612, -151, 2728, 294), true, kCursorZoom, 1);
	_app->objectAddRotationAccessibility(kObject114020, 111401, Common::Rect(2749, -176, 2937, 341), true, kCursorZoom, 2);
	_app->objectAddRotationAccessibility(kObject114020, 111401, Common::Rect(2972, -170, 3200, 373), true, kCursorZoom, 3);
	_app->objectAddRotationAccessibility(kObject114020, 111401, Common::Rect(3244, -169, 3433, 362), true, kCursorZoom, 4);
	_app->objectAddPuzzleAccessibility(kObject114020, kPuzzle114008, Common::Rect(  0,  32, 142, 420), false, kCursorBack, 99);
	_app->objectAddPuzzleAccessibility(kObject114020, kPuzzle114008, Common::Rect( 60,  18, 299, 420), false, kCursorBack, 99);
	_app->objectAddPuzzleAccessibility(kObject114020, kPuzzle114009, Common::Rect(329,  16, 561, 452), false, kCursorBack, 99);
	_app->objectAddPuzzleAccessibility(kObject114020, kPuzzle114009, Common::Rect(576, 193, 639, 424), false, kCursorBack, 99);
	_app->objectAddPuzzleAccessibility(kObject114020, kPuzzle114008, Common::Rect(0, 420, 640, 464), true, kCursorBack, 99);
	_app->objectAddPuzzleAccessibility(kObject114020, kPuzzle114009, Common::Rect(0, 420, 640, 464), true, kCursorBack, 99);
	_app->objectAddRotationAccessibility(kObject114020, 111403, Common::Rect(2612, -151, 2728, 294), true, kCursorZoom, 1);
	_app->objectAddRotationAccessibility(kObject114020, 111403, Common::Rect(2749, -176, 2937, 341), true, kCursorZoom, 2);
	_app->objectAddRotationAccessibility(kObject114020, 111403, Common::Rect(2972, -170, 3200, 373), true, kCursorZoom, 3);
	_app->objectAddRotationAccessibility(kObject114020, 111403, Common::Rect(3244, -169, 3433, 362), true, kCursorZoom, 4);
	_app->objectAddRotationAccessibility(kObject114020, 111405, Common::Rect(2612, -151, 2728, 294), true, kCursorZoom, 1);
	_app->objectAddRotationAccessibility(kObject114020, 111405, Common::Rect(2749, -176, 2937, 341), true, kCursorZoom, 2);
	_app->objectAddRotationAccessibility(kObject114020, 111405, Common::Rect(2972, -170, 3200, 373), true, kCursorZoom, 3);
	_app->objectAddRotationAccessibility(kObject114020, 111405, Common::Rect(3244, -169, 3433, 362), true, kCursorZoom, 4);
	_app->objectAddPresentation(kObject114020);
	_app->objectPresentationAddImageToPuzzle(kObject114020, 0, kPuzzle114008, "a11s04n01p08l01.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114020);
	_app->objectPresentationAddImageToPuzzle(kObject114020, 1, kPuzzle114008, "a11s04n01p08l02.bmp", Common::Point(21, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114020);
	_app->objectPresentationAddImageToPuzzle(kObject114020, 2, kPuzzle114009, "a11s04n01p10l01.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114020);
	_app->objectPresentationAddImageToPuzzle(kObject114020, 3, kPuzzle114009, "a11s04n01p10l02.bmp", Common::Point(345, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114020);
	_app->objectPresentationAddImageToPuzzle(kObject114020, 4, kPuzzle114008, "a11s04n01p08l06.bmp", Common::Point(423, 358), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObject114021, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject114021, kPuzzle114009, Common::Rect(157,  57, 238,  90), false, kCursorZoom, 0);
	_app->objectAddPuzzleAccessibility(kObject114021, kPuzzle114010, Common::Rect(187, 148, 454, 333), true, kCursorZoom, 1);
	_app->objectAdd(kObject114022, "", "", 1);
	_app->objectAdd(kObject114027, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject114027, kPuzzle114017, Common::Rect(0, 420, 640, 464), true, kCursorBack, 9);
	_app->objectAddPuzzleAccessibility(kObject114027, kPuzzle114017, Common::Rect(0, 420, 640, 464), false, kCursorBack, 99);
	_app->objectAddRotationAccessibility(kObject114027, 111402, Common::Rect(1938, -220, 2582, 355), false, kCursorZoom, 0);
	_app->objectAddRotationAccessibility(kObject114027, 111404, Common::Rect(1938, -220, 2582, 355), false, kCursorZoom, 1);
	_app->objectAddRotationAccessibility(kObject114027, 111406, Common::Rect(1938, -220, 2582, 355), false, kCursorZoom, 2);
	_app->objectAddPuzzleAccessibility(kObject114027, kPuzzle114017, Common::Rect(100, 50, 540, 410), false, kCursorZoom, 5);
	_app->objectAddPresentation(kObject114027);
	_app->objectPresentationAddImageToPuzzle(kObject114027, 0, kPuzzle114017, "a11s04n02p03l01.bmp", Common::Point(249, 252), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114027);
	_app->objectPresentationAddImageToPuzzle(kObject114027, 1, kPuzzle114017, "a11s04n02p03l02.bmp", Common::Point(101, 162), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114027);
	_app->objectPresentationAddImageToPuzzle(kObject114027, 2, kPuzzle114017, "a11s04n02p03l03.bmp", Common::Point(196, 193), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114027);
	_app->objectPresentationAddImageToPuzzle(kObject114027, 3, kPuzzle114017, "a11s04n02p03l04.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectPresentationShow(kObject114027, 0);
	_app->objectAdd(kObject114316, "", "CUR_DRAG", 4);
	_app->objectSetActiveDrawCursor(kObject114316, Common::Point(15, 15), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveDrawCursor(kObject114316, Common::Point(15, 15), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObject114316, kPuzzle114016, Common::Rect(136,  75, 200, 169), true, kCursorDragDrop, 0);
	_app->objectAddPuzzleAccessibility(kObject114316, kPuzzle114016, Common::Rect(225,  80, 289, 170), true, kCursorDragDrop, 1);
	_app->objectAddPuzzleAccessibility(kObject114316, kPuzzle114016, Common::Rect(330,  77, 391, 167), true, kCursorDragDrop, 2);
	_app->objectAddPuzzleAccessibility(kObject114316, kPuzzle114016, Common::Rect(430,  60, 500, 154), true, kCursorDragDrop, 3);
	_app->objectAddPuzzleAccessibility(kObject114316, kPuzzle114016, Common::Rect(112, 190, 179, 285), true, kCursorDragDrop, 4);
	_app->objectAddPuzzleAccessibility(kObject114316, kPuzzle114016, Common::Rect(218, 196, 276, 290), true, kCursorDragDrop, 5);
	_app->objectAddPuzzleAccessibility(kObject114316, kPuzzle114016, Common::Rect(330, 195, 400, 290), true, kCursorDragDrop, 6);
	_app->objectAddPuzzleAccessibility(kObject114316, kPuzzle114016, Common::Rect(443, 186, 515, 279), true, kCursorDragDrop, 7);
	_app->objectAddPuzzleAccessibility(kObject114316, kPuzzle114016, Common::Rect( 47, 289, 108, 396), true, kCursorDragDrop, 8);
	_app->objectAddPuzzleAccessibility(kObject114316, kPuzzle114016, Common::Rect(151, 308, 210, 407), true, kCursorDragDrop, 9);
	_app->objectAddPuzzleAccessibility(kObject114316, kPuzzle114016, Common::Rect(274, 312, 335, 415), true, kCursorDragDrop, 10);
	_app->objectAddPuzzleAccessibility(kObject114316, kPuzzle114016, Common::Rect(396, 308, 469, 415), true, kCursorDragDrop, 11);
	_app->objectAddPuzzleAccessibility(kObject114316, kPuzzle114016, Common::Rect(523, 296, 599, 402), true, kCursorDragDrop, 12);

	_app->objectAdd(kObject114317, "", "", 1);
	_app->objectAdd(kObject114318, "", "", 1);
	_app->objectAdd(kObject114319, "", "", 1);
	_app->objectAdd(kObject114320, "", "", 1);
	_app->objectAdd(kObject114321, "", "", 1);
	_app->objectAdd(kObject114322, "", "", 1);
	_app->objectAdd(kObject114323, "", "", 1);
	_app->objectAdd(kObject114324, "", "", 1);
	_app->objectAdd(kObject114325, "", "", 1);
	_app->objectAdd(kObject114326, "", "", 1);
	_app->objectAdd(kObject114327, "", "", 1);
	_app->objectAdd(kObject114328, "", "", 1);
	_app->objectAdd(kObject114329, "", "", 1);

	for (uint32 i = 0; i < 10; i++)  {
		_app->objectAddPresentation(kObject114317);
		_app->objectPresentationAddImageToPuzzle(kObject114317, i, kPuzzle114016, Common::String::format("a11s04n02p02s%02d.%04d.bmp", 1, i + 1), Common::Point(139, 76), true, kDrawTypeNormal, 1000);
	}

	for (uint32 i = 0; i < 10; i++)  {
		_app->objectAddPresentation(kObject114318);
		_app->objectPresentationAddImageToPuzzle(kObject114318, i, kPuzzle114016, Common::String::format("a11s04n02p02s%02d.%04d.bmp", 2, i + 1), Common::Point(234, 79), true, kDrawTypeNormal, 1000);
	}

	for (uint32 i = 0; i < 10; i++)  {
		_app->objectAddPresentation(kObject114319);
		_app->objectPresentationAddImageToPuzzle(kObject114319, i, kPuzzle114016, Common::String::format("a11s04n02p02s%02d.%04d.bmp", 3, i + 1), Common::Point(331, 71), true, kDrawTypeNormal, 1000);
	}

	for (uint32 i = 0; i < 10; i++)  {
		_app->objectAddPresentation(kObject114320);
		_app->objectPresentationAddImageToPuzzle(kObject114320, i, kPuzzle114016, Common::String::format("a11s04n02p02s%02d.%04d.bmp", 4, i + 1), Common::Point(440, 61), true, kDrawTypeNormal, 1000);
	}

	for (uint32 i = 0; i < 10; i++)  {
		_app->objectAddPresentation(kObject114321);
		_app->objectPresentationAddImageToPuzzle(kObject114321, i, kPuzzle114016, Common::String::format("a11s04n02p02s%02d.%04d.bmp", 5, i + 1), Common::Point(124, 194), true, kDrawTypeNormal, 1000);
	}

	for (uint32 i = 0; i < 10; i++)  {
		_app->objectAddPresentation(kObject114322);
		_app->objectPresentationAddImageToPuzzle(kObject114322, i, kPuzzle114016, Common::String::format("a11s04n02p02s%02d.%04d.bmp", 6, i + 1), Common::Point(224, 200), true, kDrawTypeNormal, 1000);
	}

	for (uint32 i = 0; i < 10; i++)  {
		_app->objectAddPresentation(kObject114323);
		_app->objectPresentationAddImageToPuzzle(kObject114323, i, kPuzzle114016, Common::String::format("a11s04n02p02s%02d.%04d.bmp", 7, i + 1), Common::Point(337, 197), true, kDrawTypeNormal, 1000);
	}

	for (uint32 i = 0; i < 10; i++)  {
		_app->objectAddPresentation(kObject114324);
		_app->objectPresentationAddImageToPuzzle(kObject114324, i, kPuzzle114016, Common::String::format("a11s04n02p02s%02d.%04d.bmp", 8, i + 1), Common::Point(451, 186), true, kDrawTypeNormal, 1000);
	}

	for (uint32 i = 0; i < 10; i++)  {
		_app->objectAddPresentation(kObject114325);
		_app->objectPresentationAddImageToPuzzle(kObject114325, i, kPuzzle114016, Common::String::format("a11s04n02p02s%02d.%04d.bmp", 9, i + 1), Common::Point(51, 298), true, kDrawTypeNormal, 1000);
	}

	for (uint32 i = 0; i < 10; i++)  {
		_app->objectAddPresentation(kObject114326);
		_app->objectPresentationAddImageToPuzzle(kObject114326, i, kPuzzle114016, Common::String::format("a11s04n02p02s%02d.%04d.bmp", 10, i + 1), Common::Point(152, 312), true, kDrawTypeNormal, 1000);
	}

	for (uint32 i = 0; i < 10; i++)  {
		_app->objectAddPresentation(kObject114327);
		_app->objectPresentationAddImageToPuzzle(kObject114327, i, kPuzzle114016, Common::String::format("a11s04n02p02s%02d.%04d.bmp", 11, i + 1), Common::Point(278, 315), true, kDrawTypeNormal, 1000);
	}

	for (uint32 i = 0; i < 10; i++)  {
		_app->objectAddPresentation(kObject114328);
		_app->objectPresentationAddImageToPuzzle(kObject114328, i, kPuzzle114016, Common::String::format("a11s04n02p02s%02d.%04d.bmp", 12, i + 1), Common::Point(403, 313), true, kDrawTypeNormal, 1000);
	}

	for (uint32 i = 0; i < 10; i++)  {
		_app->objectAddPresentation(kObject114329);
		_app->objectPresentationAddImageToPuzzle(kObject114329, i, kPuzzle114016, Common::String::format("a11s04n02p02s%02d.%04d.bmp", 13, i + 1), Common::Point(529, 298), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject114028, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject114028, kPuzzle114017, Common::Rect(265, 250, 382, 323), true, kCursorZoom, 0);
	_app->objectAdd(kObject114026, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject114026, kPuzzle114017, Common::Rect(421, 288, 526, 379), true, kCursorZoom, 0);
	_app->objectAdd(kObject112031, "", "", 1);
	_app->objectAddPresentation(kObject112031);
	_app->objectPresentationAddImageToRotation(kObject112031, 0, 111205, 0);
	_app->objectPresentationAddImageToRotation(kObject112031, 0, 111206, 0);
	_app->objectPresentationAddImageToRotation(kObject112031, 0, 111206, 2);
	_app->objectPresentationAddImageToRotation(kObject112031, 0, 111207, 0);
	_app->objectPresentationAddImageToRotation(kObject112031, 0, 111207, 1);
	_app->objectAdd(kObject114500, "", "", 1);
	_app->objectAddPresentation(kObject114500);
	_app->objectPresentationAddImageToRotation(kObject114500, 0, 111206, 4);
	_app->objectAdd(kObjectHandle2, "Handle", "a11_WellHandle", 1);
	_app->objectSetActiveCursor(kObjectHandle2, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectHandle2, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectHandle2, kPuzzle114033, Common::Rect(269, 207, 406, 315), false, kCursorTake, 0);
	_app->objectAddRotationAccessibility(kObjectHandle2, 111103, Common::Rect(490, 120, 541, 190), true, kCursorActionObject, 1);
	_app->objectAddPresentation(kObjectHandle2);
	_app->objectPresentationAddImageToPuzzle(kObjectHandle2, 0, kPuzzle114033, "a11s02n05p08l02.bmp", Common::Point(240, 167), true, kDrawTypeNormal, 2000);
	_app->objectAddPresentation(kObjectHandle2);
	_app->objectPresentationAddImageToRotation(kObjectHandle2, 1, 111103, 0);
	_app->objectPresentationAddImageToRotation(kObjectHandle2, 1, 111103, 1);
	_app->objectPresentationAddImageToRotation(kObjectHandle2, 1, 111102, 2);
	_app->objectPresentationAddImageToRotation(kObjectHandle2, 1, 111107, 1);
	_app->objectPresentationAddImageToRotation(kObjectHandle2, 1, 111110, 1);
	_app->objectAdd(kObject114505, "", "", 1);
	_app->objectAddRotationAccessibility(kObject114505, 111205, Common::Rect(926, 453, 1095, 580), false, kCursorAction, 0);
	_app->objectAddPresentation(kObject114505);
	_app->objectPresentationAddImageToRotation(kObject114505, 0, 111205, 3);
	_app->objectPresentationShow(kObject114505);
	_app->objectAdd(kObject114506, "", "", 1);
	_app->objectAddRotationAccessibility(kObject114506, 111205, Common::Rect(1144, 247, 1223, 334), false, kCursorAction, 0);
	_app->objectAddPuzzleAccessibility(kObject114506, kPuzzle114033, Common::Rect(0, 420, 640, 464), true, kCursorBack, 9);
	_app->objectAddPresentation(kObject114506);
	_app->objectPresentationAddAnimationToRotation(kObject114506, 0, 111205, 1, 15, 12.5f, 6);
	_app->objectAddPresentation(kObject114506);
	_app->objectPresentationAddAnimationToRotation(kObject114506, 1, 111205, 1, 15, 12.5f, 10);
	_app->objectAddPresentation(kObject114506);
	_app->objectAddPresentation(kObject114506);
	_app->objectAddPresentation(kObject114506);
	_app->objectAddPresentation(kObject114506);
	_app->objectAdd(kObject114507, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject114507, kPuzzle114033, Common::Rect(269, 207, 406, 315), true, kCursorTake, 0);
	_app->objectAddPresentation(kObject114507);
	_app->objectPresentationAddImageToPuzzle(kObject114507, 0, kPuzzle114033, "a11s02n05p08l01.bmp", Common::Point(246, 193), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114507);
	_app->objectAdd(kObjectMoonMilk, "Moon Milk", "a11_MoonMilk", 1);
	_app->objectSetActiveCursor(kObjectMoonMilk, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectMoonMilk, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectMoonMilk, kPuzzle114019, Common::Rect(211, 303, 313, 357), true, kCursorTake, 0);
	_app->objectAddPuzzleAccessibility(kObjectMoonMilk, kPuzzle114031, Common::Rect(276, 376, 377, 416), true, kCursorZoom, 1);
	_app->objectAddPresentation(kObjectMoonMilk);
	_app->objectPresentationAddImageToPuzzle(kObjectMoonMilk, 0, kPuzzle114019, "a11s01n03p01l01.bmp", Common::Point(196, 300), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObjectMonocular, "Monocular", "a11_Monocular", 1);
	_app->objectSetActiveCursor(kObjectMonocular, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectMonocular, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectMonocular, kPuzzle114020, Common::Rect(258, 174, 428, 327), true, kCursorIdle, 0);
	_app->objectAddPuzzleAccessibility(kObjectMonocular, kPuzzle114020, Common::Rect(258, 174, 428, 327), false, kCursorTake, 1);
	_app->objectAddRotationAccessibility(kObjectMonocular, 111108, Common::Rect(564, -278, 748, -103), true, kCursorZoom, 4);
	_app->objectAddPuzzleAccessibility(kObjectMonocular, kPuzzle114021, Common::Rect(267, 148, 398, 279), true, kCursorActionObject, 5);
	_app->objectAddPuzzleAccessibility(kObjectMonocular, kPuzzle114021, Common::Rect(94, 70, 179, 152), false, kCursorZoom, 6);
	_app->objectAddPresentation(kObjectMonocular);
	_app->objectPresentationAddImageToRotation(kObjectMonocular, 0, 111107, 0);
	_app->objectPresentationAddImageToRotation(kObjectMonocular, 0, 111108, 2);
	_app->objectPresentationAddImageToRotation(kObjectMonocular, 0, 111109, 1);
	_app->objectAddPresentation(kObjectMonocular);
	_app->objectPresentationAddImageToPuzzle(kObjectMonocular, 1, kPuzzle114021, "a11s01n08p02l01.bmp", Common::Point(101, 74), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObjectMonocular);
	_app->objectPresentationAddImageToPuzzle(kObjectMonocular, 2, kPuzzle114021, "a11s01n08p03.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectPresentationShow(kObjectMonocular, 1);
	_app->objectAdd(kObject114512, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject114512, kPuzzle114020, Common::Rect(300, 180, 450, 270), true, kCursorIdle, 0);
	_app->objectAddPuzzleAccessibility(kObject114512, kPuzzle114020, Common::Rect(300, 180, 450, 270), false, kCursorZoom, 1);
	_app->objectAdd(kObject114510, "", "", 1);
	_app->objectAddRotationAccessibility(kObject114510, 111108, Common::Rect(1230, 201, 1425, 366), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject114510, 111108, Common::Rect(1230, 290, 1425, 366), false, kCursorActionObject, 1);
	_app->objectAddRotationAccessibility(kObject114510, 111108, Common::Rect(1230, 290, 1425, 366), false, kCursorZoom, 2);
	_app->objectAddPresentation(kObject114510);
	_app->objectPresentationAddImageToRotation(kObject114510, 0, 111102, 0);
	_app->objectPresentationAddImageToRotation(kObject114510, 0, 111103, 2);
	_app->objectPresentationAddImageToRotation(kObject114510, 0, 111108, 0);
	_app->objectPresentationAddImageToRotation(kObject114510, 0, 111109, 0);
	_app->objectPresentationAddImageToRotation(kObject114510, 0, 111110, 0);
	_app->objectAddPresentation(kObject114510);
	_app->objectPresentationAddImageToRotation(kObject114510, 1, 111108, 1);
	_app->objectAddPresentation(kObject114510);
	_app->objectPresentationAddImageToPuzzle(kObject114510, 2, kPuzzle114020, "a11s01n08p01l01.bmp", Common::Point(294, 158), true, kDrawTypeNormal, 1100);
	_app->objectAddPresentation(kObject114510);
	_app->objectPresentationAddImageToPuzzle(kObject114510, 3, kPuzzle114020, "a11s01n08p01l02.bmp", Common::Point(263, 157), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObjectMagnesium, "Magnesia", "a11_Magnesia", 1);
	_app->objectSetActiveCursor(kObjectMagnesium, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectMagnesium, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectMagnesium, kPuzzle114020, Common::Rect(297, 164, 325, 197), true, kCursorTake, 0);
	_app->objectAdd(kObjectHandle3, "Handle", "a11_WWHandle", 1);
	_app->objectSetActiveCursor(kObjectHandle3, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectHandle3, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectHandle3, kPuzzle114022, Common::Rect(272, 198, 332, 258), true, kCursorTake, 0);
	_app->objectAddPuzzleAccessibility(kObjectHandle3, kPuzzle114022, Common::Rect(272, 198, 332, 258), false, kCursorTake, 1);
	_app->objectAddPresentation(kObjectHandle3);
	_app->objectPresentationAddImageToPuzzle(kObjectHandle3, 0, kPuzzle114022, "a11s01n07p01l01.bmp", Common::Point(272, 198), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObjectHandle3);
	_app->objectPresentationAddImageToPuzzle(kObjectHandle3, 1, kPuzzle114022, "a11s01n07p01l02.bmp", Common::Point(272, 198), true, kDrawTypeNormal, 900);
	_app->objectPresentationShow(kObjectHandle3);
	_app->objectAdd(kObjectSulphur, "Sulphur", "a11_Sulphur", 1);
	_app->objectSetActiveCursor(kObjectSulphur, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectSulphur, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectKey6, "Key", "a11_LightKey", 1);
	_app->objectSetActiveCursor(kObjectKey6, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectKey6, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectKey6, kPuzzle114023, Common::Rect(252, 326, 314, 369), true, kCursorTake, 0);
	_app->objectAdd(kObjectMercury, "Mercury", "a11_Mercury", 1);
	_app->objectSetActiveCursor(kObjectMercury, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectMercury, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectMercury, kPuzzle114023, Common::Rect(350, 308, 423, 387), false, kCursorTake, 0);
	_app->objectAdd(kObject114517, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject114517, kPuzzle114023, Common::Rect(282, 402, 366, 432), false, kCursorZoom, 0);
	_app->objectAdd(kObject114516, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject114516, kPuzzle114023, Common::Rect(379, 331, 477, 423), true, kCursorZoom, 0);
	_app->objectAddPuzzleAccessibility(kObject114516, kPuzzle114023, Common::Rect(90, 24, 335, 238), false, kCursorAction, 1);
	_app->objectAddPresentation(kObject114516);
	_app->objectPresentationAddImageToPuzzle(kObject114516, 0, kPuzzle114023, "a11s01n06p01l01.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114516);
	_app->objectPresentationAddImageToPuzzle(kObject114516, 1, kPuzzle114023, "a11s01n06p01l02.bmp", Common::Point(237, 316), true, kDrawTypeNormal, 1100);
	_app->objectAddPresentation(kObject114516);
	_app->objectPresentationAddImageToPuzzle(kObject114516, 2, kPuzzle114023, "a11s01n06p01l03.bmp", Common::Point(353, 300), true, kDrawTypeNormal, 1100);
	_app->objectAddPresentation(kObject114516);
	_app->objectPresentationAddImageToPuzzle(kObject114516, 3, kPuzzle114023, "a11s01n06p01l02.bmp", Common::Point(237, 316), true, kDrawTypeNormal, 1100);
	_app->objectAdd(kObject114515, "", "", 1);
	_app->objectAddRotationAccessibility(kObject114515, 111106, Common::Rect(458, -64, 555, 150), true, kCursorActionObject, 0);
	_app->objectAddRotationAccessibility(kObject114515, 111106, Common::Rect(458, -64, 555, 150), false, kCursorAction, 1);
	_app->objectAddRotationAccessibility(kObject114515, 111106, Common::Rect(458, -64, 555, 150), false, kCursorAction, 2);
	_app->objectAddRotationAccessibility(kObject114515, 111106, Common::Rect(458, -64, 555, 150), false, kCursorAction, 3);
	_app->objectAddPresentation(kObject114515);
	_app->objectPresentationAddImageToRotation(kObject114515, 0, 111105, 0);
	_app->objectPresentationAddImageToRotation(kObject114515, 0, 111106, 0);
	_app->objectAddPresentation(kObject114515);
	_app->objectPresentationAddAnimationToRotation(kObject114515, 1, 111106, 1, 10, 15.0f, 6);
	_app->objectAddPresentation(kObject114515);
	_app->objectPresentationAddAnimationToRotation(kObject114515, 2, 111106, 2, 15, 15.0f, 6);
	_app->objectAddPresentation(kObject114515);
	_app->objectPresentationAddAnimationToRotation(kObject114515, 3, 111106, 3, 43, 15.0f, 6);
	_app->objectAddPresentation(kObject114515);
	_app->objectPresentationAddAnimationToRotation(kObject114515, 4, 111106, 1, 10, 15.0f, 10);
	_app->objectPresentationShow(kObject114515, 0);
	_app->objectAdd(kObject114025, "", "", 1);
	_app->objectAddPresentation(kObject114025);
	_app->objectPresentationAddImageToRotation(kObject114025, 0, 111101, 0);
	_app->objectPresentationAddImageToRotation(kObject114025, 0, 111102, 1);
	_app->objectPresentationAddImageToRotation(kObject114025, 0, 111103, 3);
	_app->objectPresentationAddImageToRotation(kObject114025, 0, 111107, 2);
	_app->objectPresentationAddImageToRotation(kObject114025, 0, 111401, 3);
	_app->objectPresentationAddImageToRotation(kObject114025, 0, 111402, 0);
	_app->objectPresentationShow(kObject1, 0);
	_app->objectAdd(kObject114529, "", "", 1);
	_app->objectAddPresentation(kObject114529);
	_app->objectPresentationAddImageToPuzzle(kObject114529, 0, kPuzzle114028, "a11s03n01p02l21.bmp", Common::Point(285, 349), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114529);
	_app->objectPresentationAddImageToPuzzle(kObject114529, 1, kPuzzle114028, "a11s03n01p02l22.bmp", Common::Point(284, 389), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114529);
	_app->objectPresentationAddImageToPuzzle(kObject114529, 2, kPuzzle114028, "a11s03n01p02l23.bmp", Common::Point(283, 396), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114529);
	_app->objectPresentationAddImageToPuzzle(kObject114529, 3, kPuzzle114028, "a11s03n01p02l24.bmp", Common::Point(284, 357), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114529);
	_app->objectPresentationAddImageToPuzzle(kObject114529, 4, kPuzzle114028, "a11s03n01p02l25.bmp", Common::Point(278, 381), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114529);
	_app->objectPresentationAddImageToPuzzle(kObject114529, 5, kPuzzle114028, "a11s03n01p02l26.bmp", Common::Point(287, 373), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114529);
	_app->objectPresentationAddImageToPuzzle(kObject114529, 6, kPuzzle114028, "a11s03n01p02l27.bmp", Common::Point(291, 373), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114529);
	_app->objectPresentationAddImageToPuzzle(kObject114529, 7, kPuzzle114028, "a11s03n01p02l28.bmp", Common::Point(291, 377), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114529);
	_app->objectPresentationAddAnimationToPuzzle(kObject114529, 8, kPuzzle114028, "a11s03n01p02s11", kImageTypeBMP, Common::Point(181, 292), kDrawTypeNormal, 2000, 6, 12.5f, 6);
	_app->objectAddPresentation(kObject114529);
	_app->objectPresentationAddAnimationToPuzzle(kObject114529, 9, kPuzzle114028, "a11s03n01p02s12", kImageTypeBMP, Common::Point(217, 353), kDrawTypeNormal, 2000, 6, 12.5f, 6);
	_app->objectAddPresentation(kObject114529);
	_app->objectPresentationAddAnimationToPuzzle(kObject114529, 10, kPuzzle114028, "a11s03n01p02s13", kImageTypeBMP, Common::Point(373, 364), kDrawTypeNormal, 2000, 6, 12.5f, 6);
	_app->objectAddPresentation(kObject114529);
	_app->objectPresentationAddAnimationToPuzzle(kObject114529, 11, kPuzzle114028, "a11s03n01p02s14", kImageTypeBMP, Common::Point(431, 319), kDrawTypeNormal, 2000, 6, 12.5f, 6);
	_app->objectAdd(kObject114525, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject114525, kPuzzle114028, Common::Rect(273, 157, 355, 206), true, kCursorAction, 0);
	_app->objectAddPuzzleAccessibility(kObject114525, kPuzzle114028, Common::Rect(393,  42, 461, 125), false, kCursorActionObject, 1);
	_app->objectAddPuzzleAccessibility(kObject114525, kPuzzle114028, Common::Rect(131, 147, 176, 199), false, kCursorActionObject, 2);
	_app->objectAddPuzzleAccessibility(kObject114525, kPuzzle114028, Common::Rect(251, 265, 291, 315), false, kCursorActionObject, 3);
	_app->objectAddPuzzleAccessibility(kObject114525, kPuzzle114028, Common::Rect(294, 269, 333, 315), false, kCursorActionObject, 4);
	_app->objectAddPuzzleAccessibility(kObject114525, kPuzzle114028, Common::Rect(337, 267, 378, 315), false, kCursorActionObject, 5);
	_app->objectAddPuzzleAccessibility(kObject114525, kPuzzle114028, Common::Rect(193, 285, 239, 351), false, kCursorActionObject, 6);
	_app->objectAddPuzzleAccessibility(kObject114525, kPuzzle114028, Common::Rect(239, 337, 291, 397), false, kCursorActionObject, 7);
	_app->objectAddPuzzleAccessibility(kObject114525, kPuzzle114028, Common::Rect(329, 322, 389, 398), false, kCursorActionObject, 8);
	_app->objectAddPuzzleAccessibility(kObject114525, kPuzzle114028, Common::Rect(389, 304, 445, 368), false, kCursorActionObject, 9);
	_app->objectAddPuzzleAccessibility(kObject114525, kPuzzle114028, Common::Rect(291, 305, 332, 337), false, kCursorActionObject, 10);
	_app->objectAddPuzzleAccessibility(kObject114525, kPuzzle114028, Common::Rect(273, 157, 355, 206), false, kCursorActionObject, 11);
	_app->objectAddPresentation(kObject114525);
	_app->objectPresentationAddAnimationToPuzzle(kObject114525, 0, kPuzzle114028, "a11s03n01p02s01", kImageTypeBMP, Common::Point(127, 44), kDrawTypeNormal, 900, 28, 12.5f, 4);
	_app->objectAddPresentation(kObject114525);
	_app->objectPresentationAddAnimationToPuzzle(kObject114525, 1, kPuzzle114028, "a11s03n01p02s02", kImageTypeBMP, Common::Point(127, 44), kDrawTypeNormal, 900, 28, 12.5f, 4);
	_app->objectAddPresentation(kObject114525);
	_app->objectAddPresentation(kObject114525);
	_app->objectAddPresentation(kObject114525);
	_app->objectPresentationAddImageToPuzzle(kObject114525, 4, kPuzzle114028, "a11s03n01p02l01.bmp", Common::Point(253, 264), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114525);
	_app->objectPresentationAddImageToPuzzle(kObject114525, 5, kPuzzle114028, "a11s03n01p02l02.bmp", Common::Point(253, 264), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114525);
	_app->objectPresentationAddImageToPuzzle(kObject114525, 6, kPuzzle114028, "a11s03n01p02l03.bmp", Common::Point(253, 264), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114525);
	_app->objectPresentationAddImageToPuzzle(kObject114525, 7, kPuzzle114028, "a11s03n01p02l04.bmp", Common::Point(309, 269), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114525);
	_app->objectPresentationAddImageToPuzzle(kObject114525, 8, kPuzzle114028, "a11s03n01p02l05.bmp", Common::Point(309, 269), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114525);
	_app->objectPresentationAddImageToPuzzle(kObject114525, 9, kPuzzle114028, "a11s03n01p02l06.bmp", Common::Point(309, 269), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114525);
	_app->objectPresentationAddImageToPuzzle(kObject114525, 10, kPuzzle114028, "a11s03n01p02l07.bmp", Common::Point(342, 265), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114525);
	_app->objectPresentationAddImageToPuzzle(kObject114525, 11, kPuzzle114028, "a11s03n01p02l08.bmp", Common::Point(342, 265), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114525);
	_app->objectPresentationAddImageToPuzzle(kObject114525, 12, kPuzzle114028, "a11s03n01p02l09.bmp", Common::Point(342, 265), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114525);
	_app->objectAddPresentation(kObject114525);
	_app->objectAddPresentation(kObject114525);
	_app->objectAddPresentation(kObject114525);
	_app->objectPresentationAddImageToPuzzle(kObject114525, 16, kPuzzle114028, "a11s03n01p02l14.bmp", Common::Point(380, 315), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114525);
	_app->objectPresentationAddImageToPuzzle(kObject114525, 17, kPuzzle114028, "a11s03n01p02l10.bmp", Common::Point(296, 302), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObjectRockSalt, "Rock Salt", "a11_SaltRock", 1);
	_app->objectSetActiveCursor(kObjectRockSalt, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectRockSalt, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectRockSalt, kPuzzle114027, Common::Rect(386, 220, 456, 320), true, kCursorTake, 0);
	_app->objectAddPresentation(kObjectRockSalt);
	_app->objectPresentationAddImageToPuzzle(kObjectRockSalt, 0, kPuzzle114027, "a11s03n01p01l02.bmp", Common::Point(378, 217), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObjectSaltOfTheWise, "Salt of the wise", "a11_SaltWise", 1);
	_app->objectSetActiveCursor(kObjectSaltOfTheWise, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectSaltOfTheWise, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectSaltOfTheWise, kPuzzle114027, Common::Rect(457, 220, 536, 320), true, kCursorTake, 0);
	_app->objectAddPresentation(kObjectSaltOfTheWise);
	_app->objectPresentationAddImageToPuzzle(kObjectSaltOfTheWise, 0, kPuzzle114027, "a11s03n01p01l03.bmp", Common::Point(455, 219), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObjectCommonSalt, "Common Salt", "a11_SaltComm", 1);
	_app->objectSetActiveCursor(kObjectCommonSalt, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectCommonSalt, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectCommonSalt, kPuzzle114027, Common::Rect(136, 220, 208, 320), true, kCursorTake, 0);
	_app->objectAddPuzzleAccessibility(kObjectCommonSalt, kPuzzle114027, Common::Rect(0, 420, 640, 464), true, kCursorBack, 9);
	_app->objectAddPresentation(kObjectCommonSalt);
	_app->objectPresentationAddImageToPuzzle(kObjectCommonSalt, 0, kPuzzle114027, "a11s03n01p01l01.bmp", Common::Point(125, 216), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObject114522, "", "", 1);
	_app->objectAddRotationAccessibility(kObject114522, 111301, Common::Rect(2877, -80, 3067,  97), true, kCursorZoom, 0);
	_app->objectAddRotationAccessibility(kObject114522, 111301, Common::Rect(3100, -81, 3295, 102), true, kCursorZoom, 1);
	_app->objectAddRotationAccessibility(kObject114522, 111301, Common::Rect(3324, -78, 3485,  92), true, kCursorZoom, 2);
	_app->objectAddPresentation(kObject114522);
	_app->objectPresentationAddImageToRotation(kObject114522, 0, 111301, 0);
	_app->objectAddPresentation(kObject114522);
	_app->objectPresentationAddImageToRotation(kObject114522, 1, 111301, 2);
	_app->objectAddPresentation(kObject114522);
	_app->objectPresentationAddAnimationToRotation(kObject114522, 2, 111301, 1, 15, 12.5f, 6);
	_app->objectAddPresentation(kObject114522);
	_app->objectPresentationAddAnimationToRotation(kObject114522, 3, 111301, 1, 15, 12.5f, 10);
	_app->objectAddPresentation(kObject114522);
	_app->objectPresentationAddAnimationToRotation(kObject114522, 4, 111301, 3, 15, 12.5f, 6);
	_app->objectAddPresentation(kObject114522);
	_app->objectPresentationAddAnimationToRotation(kObject114522, 5, 111301, 3, 15, 12.5f, 10);
	_app->objectAddPresentation(kObject114522);
	_app->objectPresentationAddAnimationToRotation(kObject114522, 6, 111301, 4, 15, 12.5f, 6);
	_app->objectAddPresentation(kObject114522);
	_app->objectPresentationAddAnimationToRotation(kObject114522, 7, 111301, 4, 15, 12.5f, 10);
	_app->objectAddPresentation(kObject114522);
	_app->objectPresentationAddAnimationToRotation(kObject114522, 8, 111301, 5, 15, 12.5f, 6);
	_app->objectAddPresentation(kObject114522);
	_app->objectPresentationAddAnimationToRotation(kObject114522, 9, 111301, 5, 15, 12.5f, 10);
	_app->objectAddPresentation(kObject114522);
	_app->objectPresentationAddAnimationToRotation(kObject114522, 10, 111301, 6, 15, 12.5f, 6);
	_app->objectAddPresentation(kObject114522);
	_app->objectPresentationAddAnimationToRotation(kObject114522, 11, 111301, 6, 15, 12.5f, 10);
	_app->objectAddPresentation(kObject114522);
	_app->objectPresentationAddAnimationToRotation(kObject114522, 12, 111301, 7, 15, 12.5f, 6);
	_app->objectAddPresentation(kObject114522);
	_app->objectPresentationAddAnimationToRotation(kObject114522, 13, 111301, 7, 15, 12.5f, 10);
	_app->objectAdd(kObjectSunSpirit, "Sun Spirit", "a11_SunSpirit", 1);
	_app->objectSetActiveCursor(kObjectSunSpirit, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectSunSpirit, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectSunSpirit, kPuzzle114026, Common::Rect(449, 81, 502, 144), true, kCursorTake, 0);
	_app->objectAddPuzzleAccessibility(kObjectSunSpirit, kPuzzle114026, Common::Rect(312, 358, 358, 401), true, kCursorTake, 1);
	_app->objectAddPresentation(kObjectSunSpirit);
	_app->objectPresentationAddImageToPuzzle(kObjectSunSpirit, 0, kPuzzle114026, "a11s04n02p04l01.bmp", Common::Point(306, 348), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObjectSunSpirit);
	_app->objectPresentationAddAnimationToPuzzle(kObjectSunSpirit, 1, kPuzzle114026, "a11s04n02p04s01", kImageTypeBMP, Common::Point(436, 62), kDrawTypeNormal, 1000, 16, 12.5f, 4);
	_app->objectPresentationShow(kObjectSunSpirit, 0);
	_app->objectPresentationShow(kObjectSunSpirit, 1);
	_app->objectAdd(kObjectLead, "Lead", "a11_Lead", 1);
	_app->objectSetActiveCursor(kObjectLead, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectLead, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectLead, kPuzzle114024, Common::Rect(298, 233, 341, 277), true, kCursorTake, 0);
	_app->objectAddPuzzleAccessibility(kObjectLead, kPuzzle114024, Common::Rect(  0, 420, 640, 464), true, kCursorBack, 9);
	_app->objectAdd(kObject114521, "", "", 1);
	_app->objectAddPresentation(kObject114521);
	_app->objectPresentationAddImageToPuzzle(kObject114521, 0, kPuzzle114024, "a11s04n02p01l01.bmp", Common::Point(302, 238), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114521);
	_app->objectPresentationAddImageToPuzzle(kObject114521, 1, kPuzzle114024, "a11s04n02p01l02.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject114521);
	_app->objectPresentationAddImageToPuzzle(kObject114521, 2, kPuzzle114024, "a11s04n02p01l03.bmp", Common::Point(276, 16), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObject114520, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject114520, kPuzzle114015, Common::Rect(198, 293, 323, 343), true, kCursorActionObject, 0);
	_app->objectAddPuzzleAccessibility(kObject114520, kPuzzle114015, Common::Rect(182, 129, 229, 177), false, kCursorAction, 1);
	_app->objectAddPuzzleAccessibility(kObject114520, kPuzzle114015, Common::Rect(264, 132, 306, 175), false, kCursorAction, 2);
	_app->objectAddPuzzleAccessibility(kObject114520, kPuzzle114015, Common::Rect(  0, 420, 640, 464), true, kCursorBack, 9);
	_app->objectAddPresentation(kObject114520);
	_app->objectPresentationAddImageToPuzzle(kObject114520, 0, kPuzzle114015, "a11s04n01p07l01.bmp", Common::Point(0, 18), true, kDrawTypeNormal, 900);
	_app->objectPresentationAddAnimationToPuzzle(kObject114520, 0, kPuzzle114015, "a11s04n01p07s01", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1000, 16, 12.5f, 6);
	_app->objectAddPresentation(kObject114520);
	_app->objectPresentationAddAnimationToPuzzle(kObject114520, 1, kPuzzle114015, "a11s04n01p07s01", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1000, 16, 12.5f, 10);
	_app->objectAddPresentation(kObject114520);
	_app->objectPresentationAddImageToPuzzle(kObject114520, 2, kPuzzle114015, "a11s04n01p07l02.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 900);
	_app->objectPresentationAddAnimationToPuzzle(kObject114520, 2, kPuzzle114015, "a11s04n01p07s02", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1000, 16, 12.5f, 6);
	_app->objectAddPresentation(kObject114520);
	_app->objectPresentationAddAnimationToPuzzle(kObject114520, 3, kPuzzle114015, "a11s04n01p07s02", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1000, 16, 12.5f, 10);
	_app->objectAddPresentation(kObject114520);
	_app->objectPresentationAddImageToPuzzle(kObject114520, 4, kPuzzle114015, "a11s04n01p07l02.bmp", Common::Point(0, 16), true, kDrawTypeNormal, 900);
	_app->objectAddPresentation(kObject114520);
	_app->objectPresentationAddImageToPuzzle(kObject114520, 5, kPuzzle114015, "a11s04n01p07l01.bmp", Common::Point(0, 18), true, kDrawTypeNormal, 900);
	_app->objectAdd(kObjectMirror, "Mirror", "a11_PMirror", 1);
	_app->objectSetActiveCursor(kObjectMirror, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectMirror, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddRotationAccessibility(kObjectMirror, 111401, Common::Rect(246, 301, 365, 383), false, kCursorZoom, 0);
	_app->objectAddRotationAccessibility(kObjectMirror, 111403, Common::Rect(246, 301, 365, 383), false, kCursorZoom, 0);
	_app->objectAddPuzzleAccessibility(kObjectMirror, kPuzzle114025, Common::Rect(240, 207, 278, 245), true, kCursorActionObject, 2);
	_app->objectAddPuzzleAccessibility(kObjectMirror, kPuzzle114025, Common::Rect(  0, 420, 640, 464), true, kCursorBack, 9);
	_app->objectAddPuzzleAccessibility(kObjectMirror, kPuzzle114035, Common::Rect(262, 153, 409, 273), true, kCursorTake, 1);
	_app->objectAddPuzzleAccessibility(kObjectMirror, kPuzzle114035, Common::Rect(  0, 420, 640, 464), true, kCursorBack, 99);
	_app->objectAddPresentation(kObjectMirror);
	_app->objectPresentationAddImageToRotation(kObjectMirror, 0, 111401, 9);
	_app->objectPresentationAddImageToRotation(kObjectMirror, 0, 111403, 0);
	_app->objectAddPresentation(kObjectMirror);
	_app->objectPresentationAddImageToPuzzle(kObjectMirror, 1, kPuzzle114025, "a11s04n01p15l01.bmp", Common::Point(243, 209), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObjectMirror);
	_app->objectPresentationAddImageToPuzzle(kObjectMirror, 2, kPuzzle114025, "a11s04n01p15l02.bmp", Common::Point(241,  16), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObjectMirror);
	_app->objectPresentationAddImageToPuzzle(kObjectMirror, 3, kPuzzle114025, "a11s04n01p15l03.bmp", Common::Point(244,  16), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObject114023, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject114023, kPuzzle114008, Common::Rect(120, 318, 289, 378), false, kCursorAction, 0);
	_app->objectAddPuzzleAccessibility(kObject114023, kPuzzle114008, Common::Rect(422, 365, 533, 458), false, kCursorTake, 1);
	_app->objectAddPresentation(kObject114023);
	_app->objectPresentationAddImageToPuzzle(kObject114023, 0, kPuzzle114008, "a11s04n01p18.tga", Common::Point(65, 87), true, kDrawTypeAlpha, 1000);
	_app->objectAddPresentation(kObject114023);
	_app->objectPresentationAddAnimationToPuzzle(kObject114023, 1, kPuzzle114008, "a11s04n01p08s01", kImageTypeTGA, Common::Point(68, 297), kDrawTypeAlpha, 1000, 9, 12.5f, 6);
	_app->objectAdd(kObject112000, "", "", 1);
	_app->objectAddRotationAccessibility(kObject112000, 111203, Common::Rect(261, -33, 771, 552), true, kCursorMove, 0);
	_app->objectAdd(kObjectVitriol, "V.I.T.R.I.O.L.", "a11_Vitriol", 1);
	_app->objectSetActiveCursor(kObjectVitriol, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectVitriol, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectVitriol, kPuzzle114017, Common::Rect(194, 199, 334, 298), false, kCursorAction, 0);
	_app->soundAdd(111079, kSoundTypeBackgroundMusic, "11_bgrmus1.wac", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(111080, kSoundTypeBackgroundMusic, "11_bgrmus2.wac", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(111079, 90);
	_app->soundSetVolume(111080, 85);
	_app->soundAdd(112074, kSoundTypeBackgroundMusic, "11_BGR_MUS.wac", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(111077, kSoundTypeAmbientEffect, "11_mus1.wac", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(111078, kSoundTypeAmbientEffect, "11_mus2.wac", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(111078, 95);
	_app->soundAdd(112059, kSoundTypeAmbientMusic, "11_ZUN_ambient_voda.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->rotationAddAmbientSound(111101, 112059, 87, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(111102, 112059, 87, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(111103, 112059, 84, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(111104, 112059, 84, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(111105, 112059, 87, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(111106, 112059, 90, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(111107, 112059, 80, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(111108, 112059, 80, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(111109, 112059, 80, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(111110, 112059, 80, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle114023, 112059, 90, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle114019, 112059, 84, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle114020, 112059, 80, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle114021, 112059, 80, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle114022, 112059, 80, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle114031, 112059, 80, 0, 1, 1, 10);
	_app->soundAdd(112056, kSoundTypeAmbientMusic, "11_ZUN_ambience_crickets.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->rotationAddAmbientSound(111101, 112056, 60, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(111102, 112056, 70, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(111103, 112056, 80, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(111104, 112056, 80, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(111105, 112056, 70, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(111106, 112056, 70, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(111107, 112056, 80, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(111108, 112056, 85, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(111109, 112056, 90, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(111110, 112056, 85, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle114023, 112056, 70, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle114019, 112056, 84, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle114020, 112056, 85, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle114021, 112056, 85, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle114022, 112056, 80, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle114031, 112056, 80, 0, 1, 1, 10);
	_app->soundAdd(112057, kSoundTypeAmbientMusic, "11_ZUN_ambience_sova01.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(112057, 90);
	_app->soundAdd(112058, kSoundTypeAmbientMusic, "11_ZUN_ambience_sova02.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(112058, 90);
	_app->soundAdd(112055, kSoundTypeAmbientMusic, "11_WC_water_dripping.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->rotationAddAmbientSound(111501, 112055, 100, 0, 1, 1, 10);
	_app->soundAdd(112021, kSoundTypeAmbientMusic, "11_KIT_boilnig_naprava.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112066, kSoundTypeAmbientEffect, "11_ZUN_mlin_se_vrti.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(112066, 90);
	_app->soundAdd(112067, kSoundTypeAmbientEffect, "11_ZUN_mlin_se_vrti_brez_vode.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(112067, 90);
	_app->soundAdd(112016, kSoundTypeAmbientEffect, "11_BED_sumenje_pecata.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112024, kSoundTypeAmbientEffect, "11_KIT_levitacija.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112025, kSoundTypeAmbientEffect, "11_KIT_levitacija01.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112026, kSoundTypeAmbientEffect, "11_KIT_levitacija02.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112065, kSoundTypeAmbientEffect, "11_ZUN_mlin_bremzanje.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112046, kSoundTypeAmbientEffect, "11_TPM_omarica_open.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112064, kSoundTypeAmbientEffect, "11_ZUN_lopatica_open.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112037, kSoundTypeAmbientEffect, "11_LIB_kamin_predal_open.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112045, kSoundTypeAmbientEffect, "11_TPM_omarica_close_start.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112063, kSoundTypeAmbientEffect, "11_ZUN_lopatica_close_start.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112001, kSoundTypeAmbientEffect, "11_BED_abs_open.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112000, kSoundTypeAmbientEffect, "11_BED_abs_close.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112002, kSoundTypeAmbientEffect, "11_BED_globus_stevilke.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112003, kSoundTypeAmbientEffect, "11_BED_knjiga_odklep_zapore.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112004, kSoundTypeAmbientEffect, "11_BED_knjiga_predal_close_end.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112005, kSoundTypeAmbientEffect, "11_BED_knjiga_predal_close_start.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112006, kSoundTypeAmbientEffect, "11_BED_knjiga_predal_open.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112007, kSoundTypeAmbientEffect, "11_BED_knjiga_prva_stran_close.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112008, kSoundTypeAmbientEffect, "11_BED_knjiga_prva_stran_open.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112009, kSoundTypeAmbientEffect, "11_BED_knjiga_zaklep_zapore.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112010, kSoundTypeAmbientEffect, "11_BED_mornarski_stevec.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112011, kSoundTypeAmbientEffect, "11_BED_peta_cevlja.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112012, kSoundTypeAmbientEffect, "11_BED_predal_open_end.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112013, kSoundTypeAmbientEffect, "11_BED_predal_open_start.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112014, kSoundTypeAmbientEffect, "11_BED_stikalo_odklep.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112015, kSoundTypeAmbientEffect, "11_BED_stikalo_zaklep.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112017, kSoundTypeAmbientEffect, "11_BED_switch.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112018, kSoundTypeAmbientEffect, "11_BED_vrtenje_sifranta.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112022, kSoundTypeAmbientEffect, "11_KIT_closet_close.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112023, kSoundTypeAmbientEffect, "11_KIT_closet_open.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112027, kSoundTypeAmbientEffect, "11_KIT_prstan_v_lezisce.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112028, kSoundTypeAmbientEffect, "11_KIT_put_Mg.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112029, kSoundTypeAmbientEffect, "11_KIT_put_Pb.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112030, kSoundTypeAmbientEffect, "11_KIT_sol_v_steklenico.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112031, kSoundTypeAmbientEffect, "11_KIT_steklenica_put.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112032, kSoundTypeAmbientEffect, "11_KIT_zivo_srebro_v_steklenico.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112033, kSoundTypeAmbientEffect, "11_KIT_zveplo_v_steklenico.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112034, kSoundTypeAmbientEffect, "11_KNP_book_open.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112035, kSoundTypeAmbientEffect, "11_KNP_book_put.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112036, kSoundTypeAmbientEffect, "11_KNP_book_take.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112038, kSoundTypeAmbientEffect, "11_LIB_lopata_take.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112039, kSoundTypeAmbientEffect, "11_LIB_specialna_skatla_take.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112040, kSoundTypeAmbientEffect, "11_LIB_vodnjakova_rocica_take.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112041, kSoundTypeAmbientEffect, "11_TPM_geo_map.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112042, kSoundTypeAmbientEffect, "11_TPM_head_put.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112043, kSoundTypeAmbientEffect, "11_TPM_klik_zadnji_predal.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112044, kSoundTypeAmbientEffect, "11_TPM_omarica_close_end.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112047, kSoundTypeAmbientEffect, "11_TPM_predal_close_end.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(112047, 90);
	_app->soundAdd(112048, kSoundTypeAmbientEffect, "11_TPM_predal_close_start.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(112048, 90);
	_app->soundAdd(112049, kSoundTypeAmbientEffect, "11_TPM_predal_open_end.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(112049, 90);
	_app->soundAdd(112050, kSoundTypeAmbientEffect, "11_TPM_predal_open_start.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(112050, 90);
	_app->soundAdd(112051, kSoundTypeAmbientEffect, "11_TPM_recorder_insert_reel.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112052, kSoundTypeAmbientEffect, "11_TPM_recorder_press_play.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112053, kSoundTypeAmbientEffect, "11_TPM_recorder_remove_reel.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112054, kSoundTypeAmbientEffect, "11_TPM_recorder_take_reel.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112060, kSoundTypeAmbientEffect, "11_ZUN_daljnogled_na_vejo.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112061, kSoundTypeAmbientEffect, "11_ZUN_daljnogled_take.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112062, kSoundTypeAmbientEffect, "11_ZUN_lopatica_close_end.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112068, kSoundTypeAmbientEffect, "11_ZUN_odkop_skrinje.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112069, kSoundTypeAmbientEffect, "11_ZUN_rocaj_za_mlin.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112070, kSoundTypeAmbientEffect, "11_ZUN_daljn_na_vejo_shorter.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112071, kSoundTypeAmbientEffect, "11_Door_close.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112072, kSoundTypeAmbientEffect, "11_paper_take.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(112072, 90);
	_app->soundAdd(112073, kSoundTypeAmbientEffect, "11_paper_put.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(112073, 85);
	_app->soundAdd(112019, kSoundTypeAmbientEffect, "11_generic_put.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112020, kSoundTypeAmbientEffect, "11_generic_take.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(112075, kSoundTypeAmbientEffect, "11_BED_voda_loop.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->rotationAdd3DSound(111401, 112075, 1, 1, 15, 95, 110.0f, 10);
	_app->rotationAdd3DSound(111403, 112075, 1, 1, 15, 95, 110.0f, 10);
	_app->rotationAdd3DSound(111405, 112075, 1, 1, 15, 95, 110.0f, 10);
	_app->rotationAdd3DSound(111402, 112075, 1, 1, 15, 90, 110.0f, 10);
	_app->rotationAdd3DSound(111404, 112075, 1, 1, 15, 90, 110.0f, 10);
	_app->rotationAdd3DSound(111406, 112075, 1, 1, 15, 90, 110.0f, 10);
	_app->puzzleAdd3DSound(114001, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->puzzleAdd3DSound(114002, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->puzzleAdd3DSound(114003, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->puzzleAdd3DSound(114004, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->puzzleAdd3DSound(114005, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->puzzleAdd3DSound(114034, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->puzzleAdd3DSound(114006, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->puzzleAdd3DSound(114007, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->puzzleAdd3DSound(114025, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->puzzleAdd3DSound(114008, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->puzzleAdd3DSound(114009, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->puzzleAdd3DSound(114010, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->puzzleAdd3DSound(114011, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->puzzleAdd3DSound(114012, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->puzzleAdd3DSound(114013, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->puzzleAdd3DSound(114014, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->puzzleAdd3DSound(114015, 112075, 1, 1, 15, 80, 180.0f, 10);
	_app->puzzleAdd3DSound(114016, 112075, 1, 1, 15, 90, 90.0f, 10);
	_app->puzzleAdd3DSound(114017, 112075, 1, 1, 15, 80, 90.0f, 10);
	_app->puzzleAdd3DSound(114030, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->puzzleAdd3DSound(114032, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->puzzleAdd3DSound(114024, 112075, 1, 1, 15, 80, 180.0f, 10);
	_app->puzzleAdd3DSound(114026, 112075, 1, 1, 15, 80, 180.0f, 10);
	_app->puzzleAdd3DSound(114035, 112075, 1, 1, 15, 90, 180.0f, 10);
	_app->soundAdd(111090, kSoundTypeDialog, "E02_21_Nat.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111092, kSoundTypeDialog, "E02_23_Nat.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111093, kSoundTypeDialog, "E02_24_Nat.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111020, kSoundTypeDialog, "E02_25_title.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111094, kSoundTypeDialog, "E02_26_Nat.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111095, kSoundTypeDialog, "E02_27_Mar.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111027, kSoundTypeDialog, "E02_29_Nat.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111028, kSoundTypeDialog, "E02_30_Col.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111033, kSoundTypeDialog, "E02_36_Nat.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111035, kSoundTypeDialog, "E02_40_paper.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundSetVolume(111035, 80);
	_app->soundAdd(111036, kSoundTypeDialog, "E02_41_1Nat.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111037, kSoundTypeDialog, "E02_41_2Teo.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111038, kSoundTypeDialog, "E02_42_colonel.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111039, kSoundTypeDialog, "E02_43_Mar.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111040, kSoundTypeDialog, "E02_44_Mar.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111041, kSoundTypeDialog, "E02_45_Nat.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111042, kSoundTypeDialog, "E02_46_limbo.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111057, kSoundTypeDialog, "E02_63_letter.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111058, kSoundTypeDialog, "E02_65_Nat.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111059, kSoundTypeDialog, "E02_66_Mar.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111060, kSoundTypeDialog, "E02_67_Nat.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111061, kSoundTypeDialog, "E02_68_Nat.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111064, kSoundTypeDialog, "E02_71_Nat.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111066, kSoundTypeDialog, "E02_73_Nat.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111068, kSoundTypeDialog, "E02_75_Nat.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111069, kSoundTypeDialog, "E02_76_1Nat.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111070, kSoundTypeDialog, "E02_76_2Mar.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111071, kSoundTypeDialog, "E02_78_Nat.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111072, kSoundTypeDialog, "E02_79_Nat.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111076, kSoundTypeDialog, "E02_83_limbo.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111081, kSoundTypeDialog, "E02_99_resign.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111000, kSoundTypeDialog, "E02_02_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111001, kSoundTypeDialog, "E02_03_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111002, kSoundTypeDialog, "E02_04_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111003, kSoundTypeDialog, "E02_05_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111004, kSoundTypeDialog, "E02_06_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111005, kSoundTypeDialog, "E02_07_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111006, kSoundTypeDialog, "E02_08_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111007, kSoundTypeDialog, "E02_09_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111008, kSoundTypeDialog, "E02_10_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111009, kSoundTypeDialog, "E02_11_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111010, kSoundTypeDialog, "E02_12_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111011, kSoundTypeDialog, "E02_13_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111017, kSoundTypeDialog, "E02_14_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111012, kSoundTypeDialog, "E02_15_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111013, kSoundTypeDialog, "E02_16_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111014, kSoundTypeDialog, "E02_17_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111015, kSoundTypeDialog, "E02_18_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111016, kSoundTypeDialog, "E02_19_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111018, kSoundTypeDialog, "E02_20_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111021, kSoundTypeDialog, "E02_21_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111019, kSoundTypeDialog, "E02_22_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111029, kSoundTypeDialog, "E02_32_note.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111030, kSoundTypeDialog, "E02_33_note.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111031, kSoundTypeDialog, "E02_34_note.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111032, kSoundTypeDialog, "E02_35_contract.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111043, kSoundTypeDialog, "E02_47_panel.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111044, kSoundTypeDialog, "E02_49_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111045, kSoundTypeDialog, "E02_50_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111046, kSoundTypeDialog, "E02_51_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111047, kSoundTypeDialog, "E02_52_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111048, kSoundTypeDialog, "E02_53_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111049, kSoundTypeDialog, "E02_54_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111050, kSoundTypeDialog, "E02_55_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111051, kSoundTypeDialog, "E02_56_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111052, kSoundTypeDialog, "E02_57_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111053, kSoundTypeDialog, "E02_58_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111054, kSoundTypeDialog, "E02_59_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111055, kSoundTypeDialog, "E02_60_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111056, kSoundTypeDialog, "E02_61_title.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111062, kSoundTypeDialog, "E02_69_label.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111063, kSoundTypeDialog, "E02_70_label.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111065, kSoundTypeDialog, "E02_72_label.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111067, kSoundTypeDialog, "E02_74_label.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111073, kSoundTypeDialog, "E02_80_label.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111074, kSoundTypeDialog, "E02_81_label.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(111075, kSoundTypeDialog, "E02_82_label.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->varDefineByte(111000, 0);
	_app->varDefineByte(112000, 0);
	_app->varDefineByte(112001, 0);
	_app->varDefineByte(112002, 0);
	_app->varDefineByte(112003, 0);
	_app->varDefineByte(112004, 0);
	_app->varDefineByte(112005, 0);
	_app->varDefineByte(112009, 3);
	_app->varDefineByte(112010, 0);
	_app->varDefineByte(112011, 0);
	_app->varDefineByte(112012, 0);
	_app->varDefineByte(112013, 0);
	_app->varDefineByte(112014, 0);
	_app->varDefineByte(112015, 0);
	_app->varDefineByte(112016, 0);
	_app->varDefineByte(112006, 0);
	_app->varDefineByte(112007, 99);
	_app->varDefineByte(112008, 99);
	_app->varDefineByte(112020, 0);
	_app->varDefineByte(112021, 1);
	_app->varDefineByte(112022, 0);
	_app->varDefineByte(112023, -1);
	_app->varDefineByte(114001, 0);
	_app->varDefineByte(114002, 0);
	_app->varDefineByte(114003, 0);
	_app->varDefineByte(114004, 0);
	_app->varDefineByte(114005, 0);
	_app->varDefineByte(114006, 0);
	_app->varDefineByte(114007, 7);
	_app->varDefineByte(114008, 0);
	_app->varDefineByte(114010, 0);
	_app->varDefineByte(114011, 0);
	_app->varDefineByte(114012, 0);
	_app->varDefineByte(114013, 0);
	_app->varDefineByte(114014, 0);
	_app->varDefineByte(114015, 0);
	_app->varDefineByte(114016, 0);
	_app->varDefineByte(114017, 0);
	_app->varDefineByte(114018, 0);
	_app->varDefineByte(114100, 0);
	_app->varDefineByte(114101, 0);

	for (uint32 i = 0; i < 13; i++)
		_app->varDefineByte(114301 + i, 5);

	_app->varDefineByte(114501, 0);
	_app->varDefineByte(114502, 0);
	_app->varDefineByte(114503, 0);
	_app->varDefineByte(114504, 0);
	_app->varDefineByte(114505, 0);
	_app->varDefineByte(114506, 0);
	_app->varDefineByte(114507, 0);
	_app->varDefineByte(114508, 0);
	_app->varDefineByte(114509, 0);
	_app->varDefineByte(114511, 0);
	_app->varDefineByte(114512, 0);
	_app->varDefineByte(114513, 0);
	_app->varDefineByte(114514, 6);
	_app->varDefineByte(114515, 0);
	_app->varDefineByte(114516, 0);
	_app->varDefineByte(114517, 0);
	_app->varDefineByte(114518, 0);
	_app->varDefineByte(114510, 0);
	_app->varDefineByte(114519, 0);
	_app->varDefineByte(112017, 0);
	_app->varDefineByte(112024, 0);
	_app->varDefineByte(114009, 0);
	_app->varDefineByte(114520, 0);
	_app->varDefineByte(114521, 9);
	_app->varDefineByte(114522, 0);
	_app->varDefineByte(112025, 0);
	_app->varDefineByte(114523, 0);
	_app->varDefineByte(114524, 0);
	_app->varDefineByte(114525, 0);
	_app->varDefineByte(114526, 0);
	_app->varDefineByte(114527, 0);
	_app->varDefineByte(114528, 0);
}

// FAUST.EXE 0x466d50
void Zone14Faust::onTimer(TimerId id) {
	switch (id) {
	default:
		break;

	case kTimer0: {
		// Two random ambient sounds in six
		int32 index = rnd(6);
		if (index < 2)
			_app->soundPlay(112057 + index);
		break;
	}

	case kTimer1:
		// The alchemy sequence, one step per tick
		_app->varSetByte(114515, _app->varGetByte(114515) + 1);

		switch (_app->varGetByte(114515)) {
		default:
			break;

		case 1:
			_app->objectPresentationHide(kObject114529);
			_app->objectPresentationShow(kObject114529, 0);
			_app->objectPresentationShow(kObject114529, 1);
			break;

		case 2:
			_app->soundPlay(112019);
			_app->objectPresentationHide(kObject114529, 0);
			_app->objectPresentationHide(kObject13, 3);
			break;

		case 3:
			_app->soundPlay(112019);
			_app->objectPresentationHide(kObject114529, 1);
			_app->objectPresentationHide(kObject13, 5);
			break;

		case 4:
			_app->objectPresentationShow(kObject114525, 0);
			_app->soundPlay(112024, kSoundLoop);
			_app->objectPresentationSetAnimationOnPuzzle(kObject114525, 0, 0, 112591);
			_app->objectPresentationShow(kObject114529, 2);
			_app->objectPresentationShow(kObject114529, 3);
			break;

		case 5:
			_app->soundPlay(112029);
			_app->objectPresentationHide(kObject114529, 3);
			_app->objectPresentationHide(kObject13, 1);
			break;

		case 6:
			_app->soundPlay(112028);
			_app->objectPresentationHide(kObject114529, 2);
			_app->objectPresentationHide(kObject13, 2);
			break;

		case 7:
			_app->objectPresentationHide(kObject114529);
			_app->objectPresentationShow(kObject114529, 7);
			break;

		case 8:
			_app->soundPlay(112031);
			_app->objectPresentationHide(kObject114529, 7);
			_app->objectPresentationShow(kObject114529, 11);
			_app->objectPresentationShow(kObject114525, 16);
			_app->objectPresentationHide(kObject13, 9);
			break;

		case 9:
			_app->objectPresentationHide(kObject114529);
			_app->objectPresentationShow(kObject114529, 6);
			break;

		case 10:
			_app->soundPlay(112032);
			_app->objectPresentationHide(kObject114529, 6);
			_app->objectPresentationShow(kObject114529, 10);
			_app->objectPresentationHide(kObject13, 4);
			break;

		case 11:
			_app->objectPresentationHide(kObject114529);
			_app->objectPresentationShow(kObject114529, 5);
			break;

		case 12:
			_app->soundPlay(112033);
			_app->objectPresentationHide(kObject114529, 5);
			_app->objectPresentationShow(kObject114529, 9);
			_app->objectPresentationHide(kObject13, 10);
			break;

		case 13:
			_app->objectPresentationHide(kObject114529);
			_app->objectPresentationShow(kObject114529, 4);
			break;

		case 14:
			_app->soundPlay(112030);
			_app->objectPresentationHide(kObject114529, 4);
			_app->objectPresentationShow(kObject114529, 8);
			_app->objectPresentationHide(kObject13, 11);
			break;

		case 15:
			_app->soundPlay(112019);
			_app->objectPresentationShow(kObject114525, 4);
			_app->objectPresentationHide(kObject13, 8);
			break;

		case 16:
			_app->soundPlay(112019);
			_app->objectPresentationShow(kObject114525, 7);
			_app->objectPresentationHide(kObject13, 6);
			break;

		case 17:
			_app->soundPlay(112019);
			_app->objectPresentationShow(kObject114525, 10);
			_app->objectPresentationHide(kObject13, 7);
			break;

		case 18:
			_app->objectPresentationHide(kObject13);
			break;

		case 19:
			// End of episode Two
			_app->timerStop(kTimer1);
			_app->bagRemove(kObjectSealingRing);
			_app->soundStopAll(1024);
			_app->playMovie("A11S03_E02M04");
			_app->fadeOut(15, Color(0, 0, 0), 0);
			_app->varSetByte(98012, 2);
			_app->objectSetAccessibilityOff(kObject114503);
			_app->puzzleSetMod(kPuzzleMenu, 1, 0);
			_app->exitToMenu(kMenuAction0);
			break;
		}
		break;

	case kTimer2:
		_app->timerStop(kTimer2);
		_app->puzzleSetMod(kPuzzleMenu, 1, 0);
		_app->objectPresentationHide(kObjectCodingWheel);
		_app->objectSetAccessibilityOff(kObject114006, 3, 3);
		_app->objectSetAccessibilityOn(kObject114006, 4, 5);
		_app->varSetByte(114008, 2);
		break;
	}
}

// FAUST.EXE 0x460f70
void Zone14Faust::onButtonUp(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, const Common::Point &point) {
	_app->objectPresentationHide(kObject25);

	switch (id) {
	default:
		break;

	case kObject20:
		// Close-up overlay (object 11) exits
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->varSetDword(90027, 0);
			_app->objectPresentationHide(kObject11);
			_app->objectPresentationShow(kObject11, 0);
			_app->objectSetAccessibilityOn(kObject20, 1, 1);
			_app->objectSetAccessibilityOn(kObject114503);
			_app->soundPlay(111058);
		} else if (target == 61) {
			_app->varSetDword(90027, 0);
			_app->objectPresentationHide(kObject11);
			_app->objectPresentationShow(kObject11, 4);
			_app->objectSetAccessibilityOn(kObject20, 1, 1);
			_app->objectSetAccessibilityOn(kObject114503);
			_app->soundPlay(111066);
		}
		break;

	case kObject112000:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0 && !_app->varGetByte(111000))
			_app->soundPlay(111036);
		break;

	case kObject112011:
		// Desk: unlock with the key (target 0), close the open drawer or take the key back (target 9)
		if (_app->bagHasClickedObject()) {
			if (target == 0 && _app->bagGetClickedObject() == kObjectKey5) {
				if (!_app->varGetByte(111000)) {
					_app->varSetByte(112002, _app->varGetByte(112011) == 1 ? 9 : 3);
					_app->varSetByte(112012, 1);
				} else {
					if (!_app->varGetByte(114501))
						_app->objectSetAccessibilityOn(kObjectTape4);

					int8 state = 0;
					if (_app->varGetByte(112011) == 1)
						state = _app->varGetByte(112012) ? 9 : 6;
					_app->varSetByte(112002, state);
				}

				_app->puzzleSetActive(kPuzzle112001);
				_app->objectSetAccessibilityOn(kObject112011, 1, 1);
				_app->varSetByte(112007, 99);

				if (!_app->varGetByte(112017))
					_app->objectPresentationShow(kObjectGeologicalSurveyMap, 0);

				_app->soundPlay(112046);

				if (!_app->varGetByte(111000)) {
					_app->objectPresentationShow(kObject112011, 0);
					_app->objectPresentationSetAnimationOnPuzzle(kObject112011, 0, 0, 112599);
				} else {
					if (!_app->varGetByte(112000)) {
						uint32 presentation = _app->varGetByte(114501) ? 3 : 2;
						_app->objectPresentationShow(kObject112011, presentation);
						_app->objectPresentationSetAnimationOnPuzzle(kObject112011, presentation, 0, 112599);
					}

					_app->objectPresentationShow(kObject112028, 0);
				}

				_app->bagRemove(kObjectKey5);
				_app->soundPlay(112019);
			}

			_app->cursorDelete();
			break;
		}

		if (target != 9)
			break;

		_app->objectSetAccessibilityOff(kObject112011, 1, 1);
		_app->soundPlay(112045);

		if (_app->varGetByte(112007) != 99) {
			// Close the open drawer first: the 112001 callback then gives the key back (var 112008 = 98)
			_app->objectSetAccessibilityOff(kObjectPaperKnife, 0, 0);
			_app->objectSetAccessibilityOff(kObjectSealingRing, 0, 0);
			_app->objectSetAccessibilityOff(kObjectRedWax, 0, 0);
			_app->objectSetAccessibilityOff(kObject112027, 0, 1);
			_app->objectSetAccessibilityOff(kObjectMagnifyingGlass2, 0, 0);
			_app->objectSetAccessibilityOff(kObjectWoodenHead, 0, 0);
			_app->varSetByte(112008, 98);

			int32 drawer = _app->varGetByte(112007);
			int32 state = _app->varGetByte(112001 + drawer);
			_app->varSetByte(112007, (int8)drawer);

			ObjectId objectId = 112014 + drawer;
			_app->objectPresentationHide(objectId);
			_app->objectPresentationShow(objectId, (uint32)(state + 2));
			_app->objectPresentationSetAnimationOnPuzzle(objectId, (uint32)(state + 2), 0, 112001);
			_app->objectSetAccessibilityOff(objectId);
			_app->objectSetAccessibilityOn(objectId, 0, 0);
			_app->soundPlay(112050);
			break;
		}

		{
			uint32 presentation = 7;
			if (!_app->varGetByte(111000))
				presentation = 4;
			else if (!_app->varGetByte(114501))
				presentation = 6;

			_app->objectPresentationShow(kObject112011, presentation);
			_app->objectPresentationSetAnimationOnPuzzle(kObject112011, presentation, 0, 112598);
		}
		break;

	case kObject112014:
	case kObject112015:
	case kObject112016:
	case kObject112017:
	case kObject112018: {
		// Desk drawers: open (target 0) or close (target 1). Var 112007 is the open drawer (99 = none).
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->objectSetAccessibilityOn(kObject114503);
		_app->objectSetAccessibilityOff(kObjectPaperKnife, 0, 0);
		_app->objectSetAccessibilityOff(kObjectSealingRing, 0, 0);
		_app->objectSetAccessibilityOff(kObjectRedWax, 0, 0);
		_app->objectSetAccessibilityOff(kObject112027, 0, 1);
		_app->objectSetAccessibilityOff(kObjectMagnifyingGlass2, 0, 0);
		_app->objectSetAccessibilityOff(kObjectWoodenHead, 0, 0);

		int32 drawer = (int32)id - 112014;

		if (target == 0) {
			if (_app->varGetByte(112007) != 99) {
				// Close the open drawer, then the 112001 callback opens this one (var 112008)
				_app->varSetByte(112008, (int8)drawer);

				int32 open = _app->varGetByte(112007);
				int32 presentation = _app->varGetByte(112001 + open);
				if (open == 2 && _app->varGetByte(111000) > 0)
					presentation += 3;

				_app->varSetByte(112007, (int8)open);

				ObjectId objectId = 112014 + open;
				_app->objectPresentationHide(objectId);
				_app->objectPresentationShow(objectId, (uint32)(presentation + 2));
				_app->objectPresentationSetAnimationOnPuzzle(objectId, (uint32)(presentation + 2), 0, 112001);
				_app->objectSetAccessibilityOff(objectId);
				_app->objectSetAccessibilityOff(id);
				_app->objectSetAccessibilityOff(kObject112011, 1, 1);
				_app->soundPlay(112050);
				break;
			}

			_app->varSetByte(112008, 99);

			int32 presentation = _app->varGetByte(112001 + drawer);
			if (id == kObject112016 && _app->varGetByte(111000) > 0)
				presentation += 3;

			_app->varSetByte(112007, (int8)drawer);
			_app->objectPresentationSetAnimationOnPuzzle(id, (uint32)presentation, 0, 112000);
			_app->objectPresentationShow(id, (uint32)presentation);
			_app->objectSetAccessibilityOff(id);
			_app->objectSetAccessibilityOff(kObject112011, 1, 1);
			_app->soundPlay(112048);
		} else if (target == 1) {
			int32 presentation = _app->varGetByte(112001 + drawer);
			if (id == kObject112016 && _app->varGetByte(111000) > 0)
				presentation += 3;

			_app->varSetByte(112007, (int8)drawer);
			_app->objectPresentationHide(id);
			_app->objectPresentationShow(id, (uint32)(presentation + 2));
			_app->objectPresentationSetAnimationOnPuzzle(id, (uint32)(presentation + 2), 0, 112001);
			_app->objectSetAccessibilityOff(id);
			_app->objectSetAccessibilityOff(kObject112011, 1, 1);
			_app->soundPlay(112048);
		}
		break;
	}

	case kObjectPaperKnife:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target != 0)
			break;

		_app->bagAdd(kObjectPaperKnife);
		_app->soundPlay(112020);
		_app->objectSetAccessibilityOff(kObjectPaperKnife, 0, 0);
		_app->varSetByte(112010, 1);
		_app->varSetByte(112001, 3);
		_app->objectPresentationShow(kObject112014, 4);
		break;

	case kObjectSealingRing:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target != 0)
			break;

		_app->bagAdd(kObjectSealingRing);
		_app->soundPlay(112020);
		_app->objectSetAccessibilityOff(kObjectSealingRing, 0, 0);
		_app->varSetByte(112011, 1);

		if (!_app->varGetByte(112002)) {
			_app->varSetByte(112002, 6);
			_app->objectPresentationShow(kObject112015, 7);
		} else {
			_app->varSetByte(112002, 9);
			_app->objectPresentationShow(kObject112015, 10);
		}

		_app->objectPresentationShow(kObjectSealingRing, 0);
		_app->puzzleSetActive(kPuzzle112005);
		break;

	case kObjectMagnifyingGlass2:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target != 0)
			break;

		_app->bagAdd(kObjectMagnifyingGlass2);
		_app->soundPlay(112020);
		_app->objectSetAccessibilityOff(kObjectMagnifyingGlass2, 0, 0);
		_app->varSetByte(112015, 1);
		_app->varSetByte(112004, 3);
		_app->objectPresentationShow(kObject112017, 4);
		break;

	case kObjectWoodenHead:
		if (_app->bagHasClickedObject()) {
			if (target == 1 && _app->bagGetClickedObject() == kObjectWoodenHead) {
				// Put the head back on its stand
				if (_app->varGetByte(111000) == 1)
					_app->objectPresentationShow(kObjectTape1, 2);

				_app->soundPlay(112042);
				_app->objectPresentationShow(kObjectWoodenHead, 0);
				_app->bagRemove(kObjectWoodenHead);
				_app->varSetByte(112020, 1);
				_app->objectSetAccessibilityOff(kObjectWoodenHead, 1, 1);
				_app->objectSetAccessibilityOn(kObjectWoodenHead, 2, 2);

				// The original shows this presentation twice
				if (_app->varGetByte(111000) == 1)
					_app->objectPresentationShow(kObjectTape1, 2);

				_app->soundPlay(112046);
				_app->objectPresentationSetAnimationOnRotation(kObjectWoodenHead, 1, 0, 112002);
				_app->objectPresentationShow(kObjectWoodenHead, 1);
			}

			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->bagAdd(kObjectWoodenHead);
			_app->soundPlay(112020);
			_app->objectSetAccessibilityOff(kObjectWoodenHead, 0, 0);
			_app->varSetByte(112016, 1);

			if (!_app->varGetByte(112017)) {
				_app->varSetByte(112005, 6);
				_app->varSetByte(112009, 6);
				_app->objectPresentationShow(kObject112018, 7);
			} else {
				_app->varSetByte(112005, 12);
				_app->varSetByte(112009, 12);
				_app->objectPresentationShow(kObject112018, 13);
			}
		} else if (target == 2) {
			if (_app->varGetByte(111000) == 1)
				_app->objectPresentationShow(kObjectTape1, 2);

			_app->soundPlay(112046);
			_app->objectPresentationSetAnimationOnRotation(kObjectWoodenHead, 1, 0, 112002);
			_app->objectPresentationShow(kObjectWoodenHead, 1);
		}
		break;

	case kObject112027:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		// The original then has unreachable code for object 112029 (take it, progress++)
		if (target == 0)
			_app->puzzleSetActive(kPuzzle112002);
		break;

	case kObjectGeologicalSurveyMap:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target != 0) {
			_app->puzzleSetActive(kPuzzle114032);
			break;
		}

		_app->soundPlay(112041);
		_app->bagAdd(kObjectGeologicalSurveyMap);
		_app->objectSetAccessibilityOff(kObjectGeologicalSurveyMap, 0, 0);
		_app->objectPresentationHide(kObjectGeologicalSurveyMap, 0);
		_app->puzzleSetActive(kPuzzle112004);
		_app->varSetByte(112017, 1);
		_app->varSetByte(112009, _app->varGetByte(112016) ? 12 : 9);
		break;

	case kObjectTape1:
		// Tape recorder. Var 112022: 0 = empty, 2 = tape in, 3 = playing, 7 = tape 114501 in, 8 = playing it.
		// Var 114009 = which tape (1 = 112030, 2 = 112090, 3 = 112091).
		if (_app->bagHasClickedObject()) {
			ObjectId clicked = _app->bagGetClickedObject();

			if (clicked == kObjectTape1) {
				if (target == 1) {
					if (!_app->varGetByte(112022)) {
						_app->bagRemove(kObjectTape1);
						_app->varSetByte(112022, 2);
						_app->objectPresentationShow(kObjectTape1, 1);
						_app->varSetByte(114009, 1);
						_app->soundPlay(112051);
					}
				} else if (target == 0) {
					_app->bagRemove(kObjectTape1);
					_app->varSetByte(112021, 1);
					_app->varSetByte(112022, 0);
					_app->objectPresentationHide(kObjectTape1, 0);
				}
			} else if (clicked == kObjectTape4) {
				if (target == 1) {
					_app->bagRemove(kObjectTape4);
					_app->varSetByte(112022, 7);
					_app->objectPresentationShow(kObjectTape1, 1);
					_app->soundPlay(112051);
				}
			} else if (clicked == kObjectTape2 || clicked == kObjectTape3) {
				if (target == 1 && !_app->varGetByte(112022)) {
					_app->bagRemove(clicked);
					_app->varSetByte(112022, 2);
					_app->objectPresentationShow(kObjectTape1, 1);
					_app->varSetByte(114009, clicked == kObjectTape2 ? 2 : 3);
					_app->soundPlay(112051);
				}
			}

			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 0:
			// Take the recorder
			if (!_app->varGetByte(112022)) {
				_app->bagAdd(kObjectTape1);
				_app->bagAdd(kObjectTape2);
				_app->bagAdd(kObjectTape3);
				_app->varSetByte(112021, 3);
			} else if (_app->varGetByte(112022) > 5) {
				_app->bagAdd(kObjectTape1);
				_app->bagAdd(kObjectTape2);
				_app->bagAdd(kObjectTape3);
			} else {
				break;
			}

			_app->objectSetAccessibilityOff(kObjectTape1, 0, 0);
			_app->objectPresentationShow(kObjectTape1, 0);
			_app->soundPlay(112054);
			break;

		case 1:
			// Eject
			if (_app->varGetByte(112022) == 2) {
				_app->bagAdd(kObjectTape1);
				_app->bagAdd(kObjectTape2);
				_app->bagAdd(kObjectTape3);
			} else if (_app->varGetByte(112022) == 7) {
				_app->bagAdd(kObjectTape4);
			} else {
				break;
			}

			_app->varSetByte(112022, 0);
			_app->objectPresentationHide(kObjectTape1, 1);
			_app->soundPlay(112054);
			break;

		case 2:
			// Play
			if (_app->varGetByte(112022) == 2) {
				_app->objectPresentationShow(kObjectTape1, 3);
				_app->objectSetAccessibilityOff(kObjectTape1, 2, 2);
				_app->objectSetAccessibilityOn(kObjectTape1, 3, 3);
				_app->varSetByte(112022, 3);
				_app->soundPlay(112052);

				switch (_app->varGetByte(114009)) {
				default:
					break;

				case 1:
					_app->soundPlay(111033);
					break;

				case 2:
					_app->soundStop(111079, 1024);
					_app->soundStop(111080, 1024);
					_app->soundPlay(111077, kSoundLoop);
					break;

				case 3:
					_app->soundStop(111079, 1024);
					_app->soundStop(111080, 1024);
					_app->soundPlay(111078, kSoundLoop);
					break;
				}
			} else if (_app->varGetByte(112022) == 7) {
				_app->objectPresentationShow(kObjectTape1, 3);
				_app->objectSetAccessibilityOff(kObjectTape1, 2, 2);
				_app->objectSetAccessibilityOn(kObjectTape1, 3, 3);
				_app->varSetByte(112022, 8);
				_app->soundPlay(112052);
				_app->soundPlay(111057);
			} else {
				break;
			}

			_app->puzzleSetMovabilityOff(kPuzzle112010);
			break;

		case 3: {
			// Stop
			int8 state;
			if (_app->varGetByte(112022) == 3) {
				_app->soundPlay(112052);

				switch (_app->varGetByte(114009)) {
				default:
					break;

				case 1:
					_app->soundStop(111033, 1024);
					break;

				case 2:
				case 3:
					_app->soundStop(_app->varGetByte(114009) == 2 ? 111077 : 111078, 1024);
					_app->soundPlay(_app->varGetByte(111000) == 1 ? 111080 : 111079, kSoundLoop);
					break;
				}

				state = 2;
			} else if (_app->varGetByte(112022) == 8) {
				_app->soundPlay(112052);
				_app->soundStop(111057, 1024);
				state = 7;
			} else {
				break;
			}

			_app->objectPresentationHide(kObjectTape1, 3);
			_app->objectPresentationShow(kObjectTape1, 4);
			for (int i = 0; i < 6; i++)
				_app->_vm->update();
			_app->objectPresentationHide(kObjectTape1, 4);
			_app->soundPlay(112052);
			_app->varSetByte(112022, state);
			_app->objectSetAccessibilityOn(kObjectTape1, 2, 2);
			_app->objectSetAccessibilityOff(kObjectTape1, 3, 3);
			_app->puzzleSetMovabilityOn(kPuzzle112010);
			break;
		}
		}
		break;

	case kObject112032:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 0:
			_app->puzzleSetActive(kPuzzle112011);
			_app->soundPlay(111027);
			if (_app->varGetByte(111000) == 1)
				_app->objectSetAccessibilityOn(kObject112032);
			break;

		case 1:
			_app->puzzleSetActive(kPuzzle112012);
			_app->soundPlay(111028);
			break;

		case 2:
			_app->puzzleSetActive(kPuzzle112013);
			break;

		case 3:
			_app->objectPresentationShow(kObject112032);
			break;
		}
		break;

	case kObject112033:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->varSetDword(90027, 111205);
		_app->rotationSetFreOn(111205);
		_app->objectPresentationHide(kObject11);
		_app->objectPresentationShow(kObject11, 8);
		_app->objectSetAccessibilityOn(kObject20, 13, 13);
		_app->objectSetAccessibilityOn(kObject114503);
		_app->soundStop(111079, 1024);
		_app->soundStop(111080, 1024);
		_app->soundPlay(112072);
		_app->soundPlay(111035);
		break;

	case kObjectMatches3:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->bagAdd(kObjectMatches3);
			_app->objectPresentationShow(kObjectMatches3, _app->bagHas(kObjectPipe) ? 2 : 0);
			_app->objectSetAccessibilityOff(kObjectMatches3, 0, 0);
		} else if (target == 1) {
			_app->bagAdd(kObjectPipe);
			_app->objectPresentationShow(kObjectMatches3, _app->bagHas(kObjectMatches3) ? 2 : 1);
			_app->objectSetAccessibilityOff(kObjectMatches3, 1, 2);
		} else {
			break;
		}

		_app->soundPlay(112020);
		break;

	case kObject112035:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0)
			playMovieWithMusic("A11S02_E02M02b");
		else if (target == 1)
			_app->puzzleSetActive(kPuzzle112000);
		break;

	case kObject112036:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		playMovieWithMusic("A11S02_E02M02a");
		break;

	case kObject112080:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 18 && _app->varGetByte(111000) == 1) {
			playMovieWithMusic("A11S02_E02M03");
			break;
		}

		showCloseUp(9, 3);
		break;

	case kObject112081:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		showCloseUp(11, 6);
		break;

	case kObject112082:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		showCloseUp(13, 9);
		break;

	case kObject112083:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target != 2)
			break;

		_app->varSetDword(90027, 111206);
		_app->rotationSetFreOn(111206);
		_app->objectSetAccessibilityOff(kObject20);
		if (_app->varGetByte(111000) == 1)
			_app->objectSetAccessibilityOn(kObject20, 0, 0);
		_app->objectPresentationHide(kObject11);

		if (!_app->varGetByte(112024)) {
			_app->objectSetAccessibilityOn(kObject20, 10, 10);
			_app->objectPresentationShow(kObject11, 14);
		} else {
			_app->objectSetAccessibilityOff(kObject20, 10, 10);
			_app->objectPresentationShow(kObject11, 15);
		}

		_app->objectSetAccessibilityOn(kObject20, 2, 2);
		_app->objectSetAccessibilityOn(kObject114503);
		_app->soundPlay(112036);
		break;

	case kObjectLead:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->bagAdd(kObjectLead);
			advanceProgress();
			_app->soundPlay(112020);
			_app->varSetByte(114510, 1);
			_app->objectSetAccessibilityOff(kObjectLead, 0, 0);
			sub_4605A0();
		} else if (target == 9) {
			sub_4605A0();
			_app->rotationSetActive(_app->varGetDword(90025));
		}
		break;

	case kObjectMagnesium:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target != 0)
			break;

		_app->bagAdd(kObjectMagnesium);
		_app->soundPlay(112020);
		_app->objectPresentationShow(kObject114510, 2);
		_app->objectSetAccessibilityOff(kObjectMagnesium, 0, 0);
		break;

	case kObjectMoonMilk:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->varSetByte(114528, 1);
			_app->bagAdd(kObjectMoonMilk);
			_app->soundPlay(112020);
			_app->objectSetAccessibilityOff(kObjectMoonMilk, 0, 0);
			_app->objectPresentationShow(kObjectMoonMilk, 0);
		} else if (target == 1) {
			_app->objectPresentationHide(kObject11);
			_app->objectPresentationShow(kObject11, 2);
			_app->objectSetAccessibilityOn(kObject20, 1, 1);
			_app->objectSetAccessibilityOn(kObject114503);
			_app->soundPlay(111061);
		}
		break;

	case kObjectMercury:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target != 0)
			break;

		_app->varSetByte(114506, 1);
		_app->objectPresentationShow(kObject114516, 2);
		_app->bagAdd(kObjectMercury);
		_app->soundPlay(112020);
		_app->objectSetAccessibilityOff(kObjectMercury, 0, 0);
		break;

	case kObjectSunSpirit:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->objectPresentationHide(kObjectSunSpirit, 1);
			_app->bagAdd(kObjectSunSpirit);
			_app->soundPlay(112020);
			_app->varSetByte(114519, 1);
			_app->objectSetAccessibilityOff(kObjectSunSpirit, 0, 0);
		} else if (target == 1) {
			_app->soundPlay(112020);
			_app->objectPresentationHide(kObjectSunSpirit, 0);
			_app->objectPresentationHide(kObject11);
			_app->objectPresentationShow(kObject11, 6);
			_app->objectSetAccessibilityOn(kObject20, 1, 1);
			_app->objectSetAccessibilityOn(kObject114503);
			_app->soundPlay(111069);
			_app->objectSetAccessibilityOff(kObjectSunSpirit, 1, 1);
			_app->objectSetAccessibilityOn(kObject114027, 4, 4);
		}
		break;

	case kObjectRedWax:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target != 0)
			break;

		// Taking one wax takes all three
		_app->bagAdd(kObjectWhiteWax);
		_app->soundPlay(112020);
		_app->bagAdd(kObjectRedWax);
		_app->bagAdd(kObjectBlackWax);
		_app->objectSetAccessibilityOff(kObjectRedWax, 0, 0);
		_app->varSetByte(112012, 1);
		advanceProgress();

		if (!_app->varGetByte(112002)) {
			_app->varSetByte(112002, 3);
			_app->objectPresentationShow(kObject112015, 4);
		} else {
			_app->varSetByte(112002, 9);
			_app->objectPresentationShow(kObject112015, 10);
		}
		break;

	case kObjectVitriol:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target != 0)
			break;

		_app->objectPresentationHide(kObject114027, 2);
		_app->bagAdd(kObjectVitriol);
		_app->soundPlay(112020);
		_app->objectSetAccessibilityOff(kObjectVitriol, 0, 0);
		_app->objectPresentationHide(kObject11);
		_app->objectPresentationShow(kObject11, 7);
		_app->objectSetAccessibilityOn(kObject20, 1, 1);
		_app->objectSetAccessibilityOn(kObject114503);
		_app->soundPlay(111071);
		break;

	case kObjectRockSalt:
	case kObjectSaltOfTheWise:
	case kObjectCommonSalt:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			if (id == kObjectRockSalt) {
				_app->varSetByte(114514, _app->varGetByte(114514) == 6 ? 8 : 12);
				_app->objectSetAccessibilityOn(kObject114525, 0, 0);
				_app->varSetByte(114526, 1);
			} else if (id == kObjectSaltOfTheWise) {
				_app->varSetByte(114514, _app->varGetByte(114514) == 6 ? 10 : 12);
			}

			_app->bagAdd(id);
			_app->soundPlay(112020);
			_app->objectPresentationShow(id, 0);
			_app->objectSetAccessibilityOff(id, 0, 0);
		} else if (target == 9) {
			_app->varSetByte(114513, 2);

			uint32 presentation = (uint32)(_app->varGetByte(114514) + 1);
			_app->objectPresentationShow(kObject114522, presentation);
			_app->objectPresentationSetAnimationOnRotation(kObject114522, presentation, 0, 112510);
			_app->varSetByte(114513, -1);
			_app->varSetByte(114512, (int8)(_app->varGetByte(114514) + 1));
			_app->rotationSetActive(111301);
			_app->varSetByte(114511, 0);
		}
		break;

	case kObject114006:
		// Cabinet (see sub_460AB0 for var 114008)
		if (_app->bagHasClickedObject()) {
			if (target == 2 && _app->bagGetClickedObject() == kObjectSealingRing) {
				_app->puzzleSetActive(kPuzzle114005);
				_app->soundPlay(112003);
				_app->objectPresentationShow(kObject114006, (uint32)_app->varGetByte(114006));
				_app->objectSetAccessibilityOff(kObject114006, 2, 2);

				if (!_app->varGetByte(114006)) {
					_app->objectSetAccessibilityOn(kObject114006, 3, 3);
					_app->varSetByte(114008, 1);
				} else {
					_app->objectSetAccessibilityOn(kObject114006, 4, 5);
					_app->varSetByte(114008, 2);
				}
			}

			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 1:
			_app->puzzleSetActive(kPuzzle114005);
			break;

		case 2:
			_app->puzzleSetActive(kPuzzle114034);
			break;

		case 3:
			_app->bagAdd(kObjectCodingWheel);
			advanceProgress();
			_app->puzzleSetMod(kPuzzleMenu, 2, 0);
			_app->objectPresentationShow(kObjectCodingWheel, (uint32)(35 - _app->varGetByte(114521)));
			_app->timerStart(kTimer2, 1000);
			_app->soundPlay(112020);
			_app->objectPresentationShow(kObject114006, 4);
			_app->varSetByte(114006, 2);
			break;

		case 5:
			_app->soundPlay(112008);
			_app->objectPresentationShow(kObject114006, 5);
			_app->objectSetAccessibilityOff(kObject114006, 4, 5);
			_app->objectSetAccessibilityOn(kObject114006, 6, 6);
			_app->varSetByte(114008, 3);
			break;

		case 7:
			_app->puzzleSetActive(kPuzzle114006);
			break;

		case 8:
			_app->objectSetAccessibilityOff(kObject114006, 8, 8);
			_app->objectPresentationShow(kObject12, 0);
			_app->objectSetAccessibilityOn(kObject22, 3, 3);
			_app->varSetByte(114100, 1);
			break;

		case 99:
			sub_460490();
			_app->objectPresentationHide(kObject12);
			_app->varSetByte(114100, 0);
			_app->objectSetAccessibilityOff(kObject114503);
			sub_460AB0();
			break;
		}
		break;

	case kObject114010: {
		// Spin the seven wheels back to zero
		int32 sum;
		do {
			sum = 0;
			for (uint32 i = 0; i < 7; i++)
				sum += _app->varGetByte(114010 + i);

			for (uint32 i = 0; i < 7; i++) {
				ObjectId wheelId = (ObjectId)(114010 + i);
				if (_app->varGetByte(wheelId) > 0) {
					_app->varSetByte(wheelId, _app->varGetByte(wheelId) - 1);
					_app->objectPresentationHideAndRemove(wheelId);
					_app->objectPresentationShow(wheelId, (uint32)_app->varGetByte(wheelId));
				}
			}

			_app->_vm->update();
		} while (sum > 0);

		_app->puzzleSetActive(kPuzzle114005);
		}
		break;

	case kObject114020: {
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		bool hasMirror = _app->varGetByte(111000) == 1 && _app->varGetByte(114519) > 0;

		switch (target) {
		default:
			break;

		case 1:
			_app->varSetDword(90025, (int32)_app->getCurrentRotationId());
			_app->puzzleSetActive(kPuzzle114008);
			_app->_vm->update();
			_app->playMovie("a11s04n01a01");
			_app->objectPresentationShow(kObject114020, 0);
			_app->varSetByte(114018, 1);
			_app->objectSetAccessibilityOn(kObject114020, 4, 4);
			break;

		case 2:
			_app->varSetDword(90025, (int32)_app->getCurrentRotationId());
			_app->puzzleSetActive(kPuzzle114008);
			_app->_vm->update();
			_app->playMovie(hasMirror ? "a11s04n01a03" : "a11s04n01a03c");
			_app->objectPresentationShow(kObject114020, 1);
			_app->varSetByte(114018, 2);
			_app->objectSetAccessibilityOn(kObject114020, 5, 5);
			_app->puzzleSetMovabilityOn(kPuzzle114008, 0, 0);

			if (hasMirror)
				_app->objectSetAccessibilityOn(kObject114023, 1, 1);
			else
				_app->objectPresentationShow(kObject114020, 4);
			break;

		case 3:
			_app->varSetDword(90025, (int32)_app->getCurrentRotationId());
			_app->puzzleSetActive(kPuzzle114009);
			_app->_vm->update();
			_app->playMovie("a11s04n01a05");
			_app->objectPresentationShow(kObject114020, 2);
			_app->varSetByte(114018, 3);
			_app->objectSetAccessibilityOn(kObject114020, 6, 6);
			_app->objectSetAccessibilityOn(kObject114021);
			break;

		case 4:
			_app->varSetDword(90025, (int32)_app->getCurrentRotationId());
			_app->puzzleSetActive(kPuzzle114009);
			_app->_vm->update();
			_app->playMovie("a11s04n01a07");
			_app->objectPresentationShow(kObject114020, 3);
			_app->varSetByte(114018, 4);
			_app->objectSetAccessibilityOn(kObject114020, 7, 7);
			break;

		case 99:
			_app->objectPresentationHide(kObject114023);
			_app->objectPresentationHide(kObject114020);

			switch (_app->varGetByte(114018)) {
			default:
				break;

			case 1:
				_app->playMovie("a11s04n01a02");
				break;

			case 2:
				_app->playMovie(hasMirror ? "a11s04n01a04" : "a11s04n01a04c");
				break;

			case 3:
				_app->playMovie("a11s04n01a06");
				break;

			case 4:
				_app->playMovie("a11s04n01a08");
				break;
			}

			_app->objectSetAccessibilityOff(kObject114020, 4, 7);
			_app->objectSetAccessibilityOff(kObject114021);
			_app->puzzleSetMovabilityOff(kPuzzle114008);
			_app->varSetByte(114018, 0);
			_app->_vm->update();
			_app->rotationSetActive((Id)_app->varGetDword(90025));
			break;
		}
		}
		break;

	case kObject114021:
		if (_app->bagHasClickedObject()) {
			if (_app->bagGetClickedObject() == kObjectMagnifyingGlass2)
				_app->puzzleSetActive(kPuzzle114030);

			_app->cursorDelete();
			break;
		}

		if (target == 0)
			_app->puzzleSetActive(kPuzzle114010);
		break;

	case kObject114026:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->soundPlay(111041);
		break;

	case kObject114027:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 0:
		case 1:
		case 2:
			_app->playMovie("a11s04n02a01");
			_app->puzzleSetActive(kPuzzle114017);
			_app->varSetDword(90025, 111402 + 2 * (int32)target);
			break;

		case 9:
			sub_460490();
			_app->objectPresentationHide(kObject12);
			_app->objectSetAccessibilityOff(kObject22);
			_app->varSetByte(114100, 0);
			_app->playMovie("a11s04n02a02");
			_app->rotationSetActive((Id)_app->varGetDword(90025));
			break;

		case 99:
			if (_app->varGetByte(111000)) {
				_app->playMovie("a11s04n02a02");
				_app->rotationSetActive((Id)_app->varGetDword(90025));
				break;
			}

			_app->objectSetAccessibilityOff(kObject114027);
			sub_460490();
			_app->objectPresentationHide(kObject12);
			_app->objectSetAccessibilityOff(kObject22);
			_app->varSetByte(114100, 0);

			if (_app->varGetByte(114527) > 0) {
				sub_4607E0();
				_app->rotationSetAlp(111207, 90.0f);
				_app->rotationSetBet(111207, 20.0f);
				_app->rotationSetActive(111207);
				_app->soundStop(111079, 1024);
				_app->soundStop(111080, 1024);
				_app->playMovie("A11S02_E02M02");
				_app->fadeOut(15, Color(0, 0, 0), 0);
				_app->displayFade("a11_black.bmp", "a11s02n07p01.bmp", 15, 0, kLoadFromCd, kArchiveArt);
				_app->objectPresentationShow(kObject25, 2);
				_app->soundPlay(111080, kSoundLoop);
			} else {
				_app->objectSetAccessibilityOn(kObject114027, 0, 0);
			}
			break;
		}
		break;

	case kObject114028:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->objectPresentationShow(kObject12, 0);
		_app->objectSetAccessibilityOn(kObject22, 3, 3);
		_app->varSetByte(114100, 2);
		_app->objectSetAccessibilityOff(kObject114027, 0, 0);
		_app->objectSetAccessibilityOn(kObject114027, 1, 1);
		break;

	case kObject114023:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->objectPresentationShow(kObject114023, 1);
			_app->soundPlay(112011);
			_app->objectPresentationSetAnimationOnPuzzle(kObject114023, 1, 0, 112006);
			advanceProgress();
			_app->objectSetAccessibilityOff(kObject114023);
		} else {
			_app->objectPresentationShow(kObject114023, 0);
			_app->objectSetAccessibilityOn(kObject114023, 0, 0);
			_app->objectSetAccessibilityOff(kObject114023, 1, 1);
			_app->objectSetAccessibilityOff(kObject114020, 5, 5);
		}
		break;

	case kObject114201:
		if (_app->bagHasClickedObject()) {
			if (target == 1 && _app->bagGetClickedObject() == kObjectGeologicalSurveyMap) {
				_app->bagRemove(kObjectGeologicalSurveyMap);
				_app->soundPlay(112041);
				_app->objectPresentationUnpauseAnimation(kObject114201, 0);
				_app->objectPresentationShow(kObject114201, 4);
				_app->varSetByte(114017, 1);
				_app->objectSetAccessibilityOff(kObject114201, 1, 1);
			}

			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->soundPlay(112001);
			_app->objectSetAccessibilityOff(kObject114201);
			_app->objectSetAccessibilityOff(kObjectGeologicalSurveyMap, 1, 1);

			if (!_app->varGetByte(114017)) {
				_app->objectPresentationShow(kObject114201, 0);
				_app->objectPresentationSetAnimationOnRotation(kObject114201, 0, 0, 112595);
				_app->objectSetAccessibilityOn(kObject114201, 1, 1);
			} else {
				_app->objectPresentationShow(kObject114201, 2);
				_app->objectPresentationSetAnimationOnRotation(kObject114201, 2, 0, 112594);
			}
		} else if (target == 2) {
			_app->objectPresentationUnpauseAnimation(kObject114201, 0);
			_app->objectPresentationUnpauseAnimation(kObject114201, 2);
			_app->objectSetAccessibilityOff(kObject114201);

			uint32 presentation = _app->varGetByte(114017) ? 3 : 1;
			_app->objectPresentationShow(kObject114201, presentation);
			_app->objectPresentationSetAnimationOnRotation(kObject114201, presentation, 0, 112593);
			_app->objectSetAccessibilityOn(kObject114201, 0, 0);
		}
		break;

	case kObjectTape4:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (!_app->varGetByte(111000))
			break;

		_app->objectPresentationHide(kObject112028, 0);
		_app->objectPresentationShow(kObject112028, 1);
		_app->bagAdd(kObjectTape4);
		_app->soundPlay(112020);
		_app->varSetByte(114501, 1);
		_app->objectSetAccessibilityOff(kObjectTape4);
		_app->objectSetAccessibilityOff(kObject112016, 0, 0);
		break;

	case kObject114505:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->playMovie("a11s02n05a01");
		_app->objectSetAccessibilityOff(kObject114505);
		_app->rotationSetActive(111205);
		_app->objectPresentationSetAnimationOnRotation(kObject114506, 0, 0, 112007);
		_app->soundPlay(112037);
		_app->objectPresentationShow(kObject114506, 0);
		_app->rotationSetRolTo(111205, 72.0f, 27.0f, 87.0f);
		break;

	case kObject114507:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->objectPresentationHide(kObject114506);
		_app->objectPresentationShow(kObject114507, 0);
		_app->objectPresentationShow(kObject13, 0);
		advanceProgress();
		_app->objectSetAccessibilityOff(kObject114507, 0, 0);
		_app->objectSetAccessibilityOn(kObjectHandle2, 0, 0);
		_app->varSetByte(114502, 1);
		_app->soundPlay(112039);
		_app->varSetByte(112025, 2);
		break;

	case kObject114506:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->soundPlay(112037);
			_app->objectPresentationShow(kObject114506, 0);
			_app->objectPresentationSetAnimationOnRotation(kObject114506, 0, 0, 112007);
		} else {
			_app->rotationSetActive(111205);
			_app->objectSetAccessibilityOn(kObject114506, 0, 0);
			_app->objectPresentationShow(kObject114506, 1);
			_app->soundPlay(112037);
		}
		break;

	case kObjectShowel:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->objectPresentationShow(kObjectShowel, 0);
			_app->soundPlay(112038);
			_app->bagAdd(kObjectShowel);
			_app->objectSetAccessibilityOff(kObjectShowel);
		}
		break;

	case kObjectHandle2:
		if (_app->bagHasClickedObject()) {
			if (target == 1 && _app->bagGetClickedObject() == kObjectHandle2) {
				_app->bagRemove(kObjectHandle2);
				_app->soundPlay(112019);
				_app->objectPresentationShow(kObjectHandle2, 1);
				_app->objectSetAccessibilityOff(kObjectHandle2);
				_app->playMovie("a11s01n03a01");
				advanceProgress();
				_app->rotationSetMovabilityOn(111103, 3, 4);
				_app->objectSetAccessibilityOff(kObjectHandle2);
			}

			_app->cursorDelete();
			break;
		}

		if (target != 0) {
			_app->soundPlay(112019);
			break;
		}

		_app->bagAdd(kObjectHandle2);
		_app->objectPresentationShow(kObjectHandle2, 0);
		_app->soundPlay(112040);
		_app->objectSetAccessibilityOff(kObjectHandle2, 0, 0);
		_app->objectPresentationHide(kObject11);
		_app->objectPresentationShow(kObject11, 1);
		_app->objectSetAccessibilityOn(kObject20, 11, 11);
		_app->objectSetAccessibilityOn(kObject114503);
		_app->soundPlay(111060);
		break;

	case kObject114510:
		if (_app->bagHasClickedObject()) {
			// The original checks for the shovel but leaves it in the bag
			if (target == 1 && _app->bagGetClickedObject() == kObjectShowel) {
				_app->objectPresentationShow(kObject114510, 1);
				_app->objectSetAccessibilityOff(kObject114510);
				_app->objectSetAccessibilityOn(kObject114510, 2, 2);
				advanceProgress();
				_app->soundPlay(112068);
				_app->playMovie("a11s01n08p01s01");
				_app->puzzleSetActive(kPuzzle114020);
			}

			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->playMovie("a11s01n08a01");
			_app->objectPresentationShow(kObject114510, 0);
			_app->objectSetAccessibilityOff(kObject114510);
			_app->objectSetAccessibilityOn(kObject114510, 1, 1);
		} else if (target == 2) {
			_app->puzzleSetActive(kPuzzle114020);
		}
		break;

	case kObject114527:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->objectPresentationShow(kObject114527, 0);
			_app->soundPlay(112050);
			_app->objectPresentationSetAnimationOnRotation(kObject114527, 0, 0, 112597);
		} else if (target == 9) {
			_app->objectPresentationShow(kObject114527, 1);
			_app->objectPresentationSetAnimationOnRotation(kObject114527, 1, 0, 112596);
			_app->rotationSetAlp(111206, 40.0f);
			_app->rotationSetBet(111206, 35.0f);
			_app->rotationSetRan(111206, 87.0f);
			_app->rotationSetActive(111206);
			_app->soundPlay(112048);
		}
		break;

	case kObject114525:
		// Alchemy table
		if (_app->bagHasClickedObject()) {
			if (!onAlchemyIngredient(target))
				return;

			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 0:
			_app->objectPresentationHide(kObject114529);
			_app->objectPresentationShow(kObject114529, 0);
			_app->objectPresentationShow(kObject114529, 1);
			_app->objectSetAccessibilityOn(kObject114525, 1, 2);
			_app->objectSetAccessibilityOff(kObject114525, 0, 0);
			break;

		case 3:
		case 4:
		case 5: {
			// Take back the wax from slot 3, 4 or 5
			Id slotVar = 114513 + target;
			if (_app->varGetByte(slotVar) <= 0)
				break;

			uint32 presentation = 3 * target - 5;
			_app->objectPresentationHide(kObject114525, presentation);
			_app->objectPresentationHide(kObject114525, presentation + 1);
			_app->objectPresentationHide(kObject114525, presentation + 2);
			_app->bagAdd((ObjectId)(kObjectLead + _app->varGetByte(slotVar)));
			_app->soundPlay(112020);
			_app->varSetByte(slotVar, 0);
			}
			break;

		case 6:
		case 7:
		case 8:
		case 9:
			_app->objectPresentationHide(kObject114529);
			_app->objectPresentationShow(kObject114529, target - 2);
			break;
		}
		break;

	case kObject114522:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->objectSetAccessibilityOff(kObject114522);

		if (!_app->varGetByte(114511)) {
			_app->varSetByte(114513, (int8)target);
			uint32 presentation = (target == 2) ? (uint32)_app->varGetByte(114514) : 2 * target + 2;

			_app->objectPresentationShow(kObject114522, presentation);
			_app->soundPlay(112023);
			_app->objectPresentationSetAnimationOnRotation(kObject114522, presentation, 0, 112509);
			_app->varSetByte(114512, (int8)presentation);
			_app->varSetByte(114511, 1);
		} else {
			_app->objectPresentationUnpauseAnimation(kObject114522, (uint32)_app->varGetByte(114512));

			uint32 presentation = (uint32)(_app->varGetByte(114512) + 1);
			if (_app->varGetByte(114513) == 2)
				presentation = (uint32)(_app->varGetByte(114514) + 1);

			_app->varSetByte(114513, _app->varGetByte(114513) == (int32)target ? -1 : (int8)target);
			_app->objectPresentationShow(kObject114522, presentation);
			_app->objectPresentationSetAnimationOnRotation(kObject114522, presentation, 0, 112510);
			_app->varSetByte(114512, (int8)presentation);
		}
		break;

	case kObject114520:
		if (_app->bagHasClickedObject()) {
			if (target == 0 && _app->bagGetClickedObject() == kObjectKey6) {
				_app->objectSetAccessibilityOff(kObject114520, 0, 0);
				_app->bagRemove(kObjectKey6);
				_app->soundPlay(112019);
				_app->varSetByte(114509, 1);
				_app->soundPlay(112014);

				if (!_app->varGetByte(114508)) {
					_app->objectSetAccessibilityOn(kObject114520, 1, 1);
					_app->objectPresentationShow(kObject114520, 0);
				}

				if (_app->varGetByte(114508) == 1) {
					_app->objectSetAccessibilityOn(kObject114520, 2, 2);
					_app->objectPresentationShow(kObject114520, 2);
				}
			}

			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 1:
			_app->objectSetAccessibilityOff(kObject114520, 1, 1);
			_app->objectSetAccessibilityOn(kObject114520, 2, 2);
			_app->objectPresentationHide(kObject114520);
			_app->objectPresentationShow(kObject114520, 4);
			if (_app->varGetByte(114510) == 1)
				_app->objectSetAccessibilityOn(kObjectMirror, 1, 1);
			_app->varSetByte(114508, 1);
			_app->soundPlay(112017);
			_app->objectPresentationShow(kObject114025);
			break;

		case 2:
			_app->objectSetAccessibilityOn(kObject114520, 1, 1);
			_app->objectSetAccessibilityOff(kObject114520, 2, 2);
			_app->objectPresentationHide(kObject114520);
			_app->objectPresentationShow(kObject114520, 5);
			if (_app->varGetByte(114510) == 1)
				_app->objectSetAccessibilityOff(kObjectMirror, 1, 1);
			_app->varSetByte(114508, 0);
			_app->soundPlay(112017);
			_app->objectPresentationHide(kObject114025);
			break;

		case 9:
			if (_app->varGetByte(114509) <= 0) {
				sub_4605A0();
				_app->rotationSetActive((Id)_app->varGetDword(90025));
				break;
			}

			_app->objectPresentationHide(kObject114520);
			_app->objectSetAccessibilityOff(kObject114520, 1, 2);
			_app->objectSetAccessibilityOn(kObject114520, 0, 0);
			_app->bagAdd(kObjectKey6);
			_app->soundPlay(112020);

			if (!_app->varGetByte(114508)) {
				_app->objectPresentationSetAnimationOnPuzzle(kObject114520, 1, 0, 112508);
				_app->objectPresentationShow(kObject114520, 1);
				_app->objectPresentationSetAnimationOnPuzzle(kObject114520, 1, 0, 112512);
			}

			if (_app->varGetByte(114508) == 1) {
				_app->objectPresentationSetAnimationOnPuzzle(kObject114520, 3, 0, 112508);
				_app->objectPresentationShow(kObject114520, 3);
				_app->objectPresentationSetAnimationOnPuzzle(kObject114520, 3, 0, 112512);
			}

			_app->varSetByte(114509, 0);
			break;
		}
		break;

	case kObjectMirror:
		if (_app->bagHasClickedObject()) {
			if (target == 2 && _app->bagGetClickedObject() == kObjectMirror) {
				_app->varSetByte(114525, 1);
				_app->bagRemove(kObjectMirror);
				_app->soundPlay(112019);
				_app->objectPresentationShow(kObjectMirror, 0);
				_app->objectPresentationShow(kObjectSunSpirit, 0);
				_app->objectSetAccessibilityOn(kObjectSunSpirit, 0, 0);
				_app->objectSetAccessibilityOff(kObjectMirror, 2, 2);
				sub_4605A0();
			}

			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 0:
			_app->varSetDword(90026, (int32)_app->getCurrentRotationId());
			_app->puzzleSetActive(kPuzzle114035);
			break;

		case 1:
			if (_app->varGetDword(90026) > 0)
				_app->rotationSetActive((Id)_app->varGetDword(90026));

			_app->varSetDword(90026, 0);
			_app->bagAdd(kObjectMirror);
			_app->soundPlay(112020);
			_app->objectPresentationShow(kObjectMirror, 0);
			_app->objectSetAccessibilityOff(kObjectMirror, 0, 1);
			break;

		case 9:
			sub_4605A0();
			_app->rotationSetActive((Id)_app->varGetDword(90025));
			_app->varSetDword(90025, 0);
			break;

		case 99:
			_app->rotationSetActive((Id)_app->varGetDword(90026));
			_app->varSetDword(90026, 0);
			break;
		}
		break;

	case kObject114517:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->objectPresentationHide(kObject11);
			_app->objectPresentationShow(kObject11, 5);
			_app->objectSetAccessibilityOn(kObject20, 1, 1);
			_app->objectSetAccessibilityOn(kObject114503);
			_app->soundPlay(111068);
		}
		break;

	case kObjectKey6:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->varSetByte(114507, 1);
			_app->objectPresentationShow(kObject114516, 1);
			_app->bagAdd(kObjectKey6);
			advanceProgress();
			_app->soundPlay(112020);
			_app->objectSetAccessibilityOff(kObjectKey6, 0, 0);
		}
		break;

	case kObject114516: {
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target != 0 && target != 1)
			break;

		bool open = (target == 0);
		_app->varSetByte(114524, open ? 1 : 0);
		_app->objectPresentationHide(kObject114516);

		if (open) {
			_app->objectSetAccessibilityOn(kObjectKey6, 0, 0);
			_app->objectSetAccessibilityOn(kObjectMercury, 0, 0);
			_app->objectSetAccessibilityOn(kObject114517, 0, 0);
			_app->objectSetAccessibilityOff(kObject114516, 0, 0);
			_app->objectSetAccessibilityOn(kObject114516, 1, 1);
		} else {
			_app->objectSetAccessibilityOff(kObjectKey6, 0, 0);
			_app->objectSetAccessibilityOff(kObjectMercury, 0, 0);
			_app->objectSetAccessibilityOff(kObject114517, 0, 0);
			_app->objectSetAccessibilityOn(kObject114516, 0, 0);
			_app->objectSetAccessibilityOff(kObject114516, 1, 1);
		}

		// The movie depends on what is still in the drawer
		int32 movie = 0;
		if (_app->varGetByte(114507) > 0) {
			movie = 2;
			if (open) {
				_app->objectPresentationShow(kObject114516, 1);
				_app->objectSetAccessibilityOff(kObjectKey6, 0, 0);
			}
		}

		if (_app->varGetByte(114506) > 0) {
			movie++;
			if (open) {
				_app->objectPresentationShow(kObject114516, 2);
				_app->objectSetAccessibilityOff(kObjectMercury, 0, 0);
			}
		}

		movie++;

		if (open) {
			_app->soundPlay(112064);
			_app->playMovie(Common::String::format("a11s01n06p01s0%d", movie));
			_app->objectPresentationShow(kObject114516, 0);
		} else {
			_app->soundPlay(112063);
			_app->playMovie(Common::String::format("a11s01n06p01s0%dr", movie));
			_app->soundPlay(112062);
		}
		}
		break;

	case kObject114515:
		if (_app->bagHasClickedObject()) {
			if (target == 0 && _app->bagGetClickedObject() == kObjectHandle3) {
				_app->bagRemove(kObjectHandle3);
				_app->objectPresentationHide(kObject114515);
				_app->objectSetAccessibilityOff(kObject114515);
				_app->objectSetAccessibilityOn(kObject114515, 1, 1);
				_app->soundPlay(112069);
			}

			_app->cursorDelete();
			break;
		}

		if (target == 1) {
			_app->objectPresentationShow(kObject114515, 1);
			_app->objectPresentationSetAnimationOnRotation(kObject114515, 1, 0, 112592);
			_app->objectPresentationSetAnimationOnRotation(kObject114515, 2, 0, 112507);
			_app->rotationSetMovabilityOff(111106, 1, 1);
			_app->objectPresentationShow(kObject114515, 2);
			_app->varSetByte(114505, 1);
			_app->objectSetAccessibilityOff(kObject114515);
			_app->objectSetAccessibilityOn(kObject114515, 2, 2);

			if (!_app->soundIsPlaying(112066))
				_app->soundPlay(112066, kSoundLoop);
		} else if (target == 2) {
			// The original really plays 112065 looped and 112066 once
			_app->soundPlay(112065, kSoundLoop);
			_app->varSetByte(114505, 0);
			_app->soundPlay(112066);
			_app->objectPresentationUnpauseAnimation(kObject114515, 1);
			_app->objectPresentationHide(kObject114515, 1);
			_app->objectPresentationShow(kObject114515, 4);
			_app->objectSetAccessibilityOff(kObject114515);
			_app->objectSetAccessibilityOn(kObject114515, 1, 1);
		} else {
			_app->soundPlay(112019);
		}
		break;

	case kObjectHandle3:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->bagAdd(kObjectSulphur);
			_app->soundPlay(112020);
			_app->objectPresentationHide(kObjectHandle3, 0);
			_app->objectSetAccessibilityOff(kObjectHandle3);
			_app->objectSetAccessibilityOn(kObjectHandle3, 1, 1);
			_app->varSetByte(114504, 1);
		} else if (target == 1) {
			_app->bagAdd(kObjectHandle3);
			advanceProgress();
			_app->soundPlay(112020);
			_app->objectPresentationHide(kObjectHandle3);
			_app->objectSetAccessibilityOff(kObjectHandle3);
			_app->varSetByte(114503, 1);

			for (uint32 i = 0; i < 10; i++)
				_app->_vm->update();

			_app->objectPresentationHide(kObject11);
			_app->objectPresentationShow(kObject11, 4);
			_app->objectSetAccessibilityOn(kObject20, 1, 1);
			_app->objectSetAccessibilityOn(kObject114503);
			_app->soundPlay(111066);
		}
		break;

	case kObject114512:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 1) {
			_app->objectPresentationHide(kObject11);
			_app->objectPresentationShow(kObject11, 3);
			_app->objectSetAccessibilityOn(kObject20, 1, 1);
			_app->objectSetAccessibilityOn(kObject114503);
			_app->soundPlay(111064);
		}
		break;

	case kObjectMonocular:
		if (_app->bagHasClickedObject()) {
			if (target == 5 && _app->bagGetClickedObject() == kObjectMonocular) {
				_app->soundPlay(112060);
				_app->objectSetAccessibilityOff(kObjectMonocular, 3, 3);
				_app->objectSetAccessibilityOn(kObjectMonocular, 4, 4);
				_app->bagRemove(kObjectMonocular);
				_app->objectPresentationShow(kObjectMonocular, 0);
				_app->objectPresentationHide(kObjectMonocular, 1);
			}

			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 1:
			_app->bagAdd(kObjectMonocular);
			_app->objectPresentationShow(kObject114510, 3);
			_app->objectSetAccessibilityOff(kObjectMonocular, 0, 1);
			_app->soundPlay(112061);
			break;

		case 4:
			_app->puzzleSetActive(kPuzzle114021);
			break;

		case 6:
			_app->playMovie("a11s01n08p03a01");
			_app->objectPresentationShow(kObjectMonocular, 2);
			_app->puzzleSetMovabilityOn(kPuzzle114021, 1, 1);
			_app->rotationSetMovabilityOn(111107, 2, 2);
			_app->objectSetAccessibilityOff(kObjectMonocular, 4, 4);
			break;
		}
		break;
	}

	sub_460A20();
}

// FAUST.EXE 0x4642df: an ingredient dropped on the alchemy table (object 114525).
// Returns false when the episode ended and the caller must not touch the zone any more.
bool Zone14Faust::onAlchemyIngredient(Id target) {
	ObjectId clicked = _app->bagGetClickedObject();

	// Wax slots 3/4/5 each take one wax (the right one is black/red/white); the slot var keeps clicked - 112601
	static const struct {
		int32 wax;
		uint32 offset;
	} waxSlots[3][3] = {
		{ {kObjectBlackWax, 0}, {kObjectRedWax, 2}, {kObjectWhiteWax, 1} },
		{ {kObjectRedWax, 0},   {kObjectBlackWax, 1}, {kObjectWhiteWax, 2} },
		{ {kObjectWhiteWax, 0}, {kObjectBlackWax, 2}, {kObjectRedWax, 1} }
	};

	bool wrong = false;

	switch (target) {
	default:
		break;

	case 1:
	case 2:
		if (clicked != (target == 1 ? kObjectMoonMilk : kObjectSunSpirit)) {
			wrong = true;
			break;
		}

		_app->bagRemove(clicked);
		_app->objectPresentationHide(kObject114529, target - 1);
		_app->soundPlay(112019);
		_app->varSetByte(114515, _app->varGetByte(114515) + 1);
		_app->objectSetAccessibilityOff(kObject114525, target, target);
		break;

	case 3:
	case 4:
	case 5: {
		Id slotVar = 114513 + target;
		if (_app->varGetByte(slotVar))
			break;

		_app->soundPlay(112019);

		uint32 first = 3 * target - 5;
		uint32 i;
		for (i = 0; i < 3; i++)
			if (clicked == waxSlots[target - 3][i].wax)
				break;

		if (i == 3) {
			wrong = true;
			break;
		}

		uint32 shown = first + waxSlots[target - 3][i].offset;
		for (uint32 p = first; p < first + 3; p++)
			if (p != shown)
				_app->objectPresentationHide(kObject114525, p);
		_app->objectPresentationShow(kObject114525, shown);
		_app->bagRemove(clicked);

		// Only the right wax counts
		if (i == 0) {
			_app->varSetByte(114515, _app->varGetByte(114515) + 1);
			_app->objectSetAccessibilityOff(kObject114525, target, target);
		}

		_app->varSetByte(slotVar, (int8)(clicked - kObjectLead));
		}
		break;

	case 6:
	case 7:
	case 8:
	case 9: {
		static const int32 ingredients[4] = { kObjectRockSalt, kObjectSulphur, kObjectMercury, kObjectVitriol };
		static const Id sounds[4] = { 112030, 112033, 112032, 112031 };

		if (clicked != ingredients[target - 6]) {
			wrong = true;
			break;
		}

		_app->objectPresentationHide(kObject114529, target - 2);
		_app->objectPresentationShow(kObject114529, target + 2);
		_app->bagRemove(clicked);
		_app->soundPlay(sounds[target - 6]);
		if (target == 9)
			_app->objectPresentationShow(kObject114525, 16);
		_app->objectSetAccessibilityOff(kObject114525, target, target);
		_app->varSetByte(114515, _app->varGetByte(114515) + 1);
		}
		break;

	case 10:
		if (clicked == kObjectSealingRing) {
			_app->objectPresentationShow(kObject114525, 17);
			_app->objectSetAccessibilityOff(kObject114525, 10, 10);
			_app->varSetByte(114515, _app->varGetByte(114515) + 1);
			_app->soundPlay(112027);
		}
		break;

	case 11:
		if (clicked == kObjectLead) {
			_app->bagRemove(clicked);
			_app->soundPlay(112029);
			_app->objectPresentationHide(kObject114529, 3);
			_app->varSetByte(114515, _app->varGetByte(114515) + 1);
		} else if (clicked == kObjectMagnesium) {
			_app->bagRemove(clicked);
			_app->soundPlay(112028);
			_app->varSetByte(114515, _app->varGetByte(114515) + 1);
			_app->objectPresentationHide(kObject114529, 2);
		} else {
			wrong = true;
		}
		break;
	}

	if (wrong)
		_app->sub_468290(2);

	int8 count = _app->varGetByte(114515);
	if (count >= 12) {
		// End of episode Two
		_app->_vm->update();
		_app->soundStopAll(1024);
		_app->playMovie("A11S03_E02M04");
		_app->fadeOut(15, Color(0, 0, 0), 0);
		_app->varSetByte(98012, 2);
		_app->exitToMenu(kMenuAction0);
		return false;
	}

	if (count == 2) {
		_app->objectPresentationShow(kObject114525, 0);
		_app->soundPlay(112024, kSoundLoop);
		_app->objectPresentationSetAnimationOnPuzzle(kObject114525, 0, 0, 112591);
		_app->objectSetAccessibilityOn(kObject114525, 11, 11);
		_app->objectPresentationShow(kObject114529, 2);
		_app->objectPresentationShow(kObject114529, 3);
	} else if (count == 4) {
		_app->objectSetAccessibilityOff(kObject114525, 11, 11);
		_app->objectSetAccessibilityOn(kObject114525, 6, 9);
	} else if (count == 8) {
		_app->objectSetAccessibilityOff(kObject114525, 6, 9);
		_app->objectSetAccessibilityOn(kObject114525, 3, 5);
	} else if (count == 11) {
		_app->objectSetAccessibilityOff(kObject114525, 3, 5);
		_app->objectSetAccessibilityOn(kObject114525, 10, 10);
	}

	return true;
}

// FAUST.EXE 0x4607e0: the room after the desk drawer secret is found (var 111000)
void Zone14Faust::sub_4607E0() {
	_app->varSetByte(111000, 1);

	if (_app->getSaveManager()->getData()->progressState == kProgressState2)
		_app->getSaveManager()->getData()->progress = 9;

	_app->objectPresentationHide(kObjectShowel);
	_app->objectPresentationHide(kObject114505);
	_app->objectPresentationHide(kObject114001);
	_app->objectPresentationShow(kObject114001, 2);
	_app->objectPresentationShow(kObject112031, 0);
	_app->objectPresentationHide(kObject114027);
	_app->objectPresentationShow(kObject114027, 1);
	_app->objectPresentationShow(kObject114027, 2);
	_app->objectSetAccessibilityOff(kObject114028);
	_app->objectSetAccessibilityOff(kObject114026);
	_app->objectSetAccessibilityOff(kObject112000);
	_app->objectSetAccessibilityOff(kObject114006);
	_app->objectSetAccessibilityOff(kObject112033);
	_app->objectSetAccessibilityOff(kObject114201);
	_app->objectSetAccessibilityOff(kObjectGeologicalSurveyMap, 1, 1);
	_app->objectSetAccessibilityOn(kObjectTape4);
	_app->objectSetAccessibilityOn(kObjectShowel);
	_app->objectSetAccessibilityOn(kObject114505);
	_app->objectSetAccessibilityOn(kObjectMirror, 0, 1);
	_app->objectSetAccessibilityOn(kObjectVitriol, 0, 0);
	_app->objectSetAccessibilityOn(kObject20, 0, 0);
	_app->objectSetAccessibilityOn(kObject112001, 17, 29);
	_app->objectSetAccessibilityOn(kObjectVitriol, 0, 0);
	_app->rotationSetMovabilityOn(111401, 7, 7);
	_app->rotationSetMovabilityOff(111402, 1, 1);
	_app->rotationSetMovabilityOff(111404, 1, 1);
	_app->rotationSetMovabilityOff(111406, 1, 1);
	_app->objectSetAccessibilityOff(kObject114027, 1, 1);
	_app->objectSetAccessibilityOn(kObject114027, 0, 0);
	_app->varSetByte(112012, 0);
}

// FAUST.EXE 0x467210
void Zone14Faust::onAnimationNextFrame(Id animationId, const Common::String &name, uint32 frame, uint32 frameCount) {
	switch (animationId) {
	default:
		break;

	case 112000: {
		if (frame != frameCount)
			break;

		// A drawer has opened
		int32 drawer = _app->varGetByte(112007);
		int32 state = _app->varGetByte(112001 + drawer);
		ObjectId objectId = 112014 + drawer;

		_app->objectPresentationShow(objectId, (uint32)(state + 1));
		_app->objectSetAccessibilityOn(objectId, 1, 1);

		if (drawer == 4 && state != 0) {
			_app->objectSetAccessibilityOff(kObject112018, 1, 1);
			_app->objectSetAccessibilityOn(kObject112018, 2, 2);
		}

		_app->soundPlay(112049);

		switch (drawer) {
		default:
			break;

		case 0:
			_app->soundPlay(112043);
			if (!_app->varGetByte(112010))
				_app->objectSetAccessibilityOn(kObjectPaperKnife, 0, 0);
			break;

		case 1:
			if (!_app->varGetByte(112011))
				_app->objectSetAccessibilityOn(kObjectSealingRing, 0, 0);

			if (!_app->varGetByte(112012))
				_app->objectSetAccessibilityOn(kObjectRedWax, 0, 0);
			break;

		case 2:
			_app->objectSetAccessibilityOn(kObject112027, 0, 1);
			break;

		case 3:
			if (!_app->varGetByte(112015))
				_app->objectSetAccessibilityOn(kObjectMagnifyingGlass2, 0, 0);
			break;

		case 4:
			if ((state == 3 || state == 9) && !_app->varGetByte(112016))
				_app->objectSetAccessibilityOn(kObjectWoodenHead, 0, 0);
			break;
		}

		_app->objectSetAccessibilityOn(kObject112011, 1, 1);
		_app->objectSetAccessibilityOff(kObject114503);
		break;
	}

	case 112001: {
		if (frame != 1)
			break;

		// A drawer has closed
		_app->varSetByte(112005, 0);
		_app->soundPlay(112047);

		int32 drawer = _app->varGetByte(112007);

		if (_app->varGetByte(112008) == 98) {
			_app->objectPresentationHide(112014 + drawer);

			uint32 presentation = 7;
			if (!_app->varGetByte(111000))
				presentation = 4;
			else if (!_app->varGetByte(114501))
				presentation = 6;

			_app->objectPresentationShow(kObject112011, presentation);
			_app->objectPresentationSetAnimationOnPuzzle(kObject112011, presentation, 0, 112598);
			_app->bagAdd(kObjectKey5);
			break;
		}

		_app->objectSetAccessibilityOn(112014 + drawer, 0, 0);
		_app->varSetByte(112007, 99);

		if (_app->varGetByte(112008) >= 98) {
			_app->objectSetAccessibilityOn(kObject112011, 1, 1);
			_app->objectSetAccessibilityOff(kObject114503);
			break;
		}

		// Open the next drawer
		_app->soundPlay(112050);

		if (_app->varGetByte(112008) != 4)
			_app->varSetByte(112005, 0);

		if (drawer == 0 && _app->varGetByte(112008) == 4)
			_app->varSetByte(112005, _app->varGetByte(112009));

		int32 next = _app->varGetByte(112008);
		int32 presentation = _app->varGetByte(112001 + next);
		if (next == 2 && _app->varGetByte(111000) > 0)
			presentation += 3;

		_app->varSetByte(112008, 99);
		_app->varSetByte(112007, (int8)next);

		ObjectId objectId = 112014 + next;
		_app->objectPresentationSetAnimationOnPuzzle(objectId, (uint32)presentation, 0, 112000);
		_app->objectPresentationShow(objectId, (uint32)presentation);
		_app->objectSetAccessibilityOff(objectId);
		break;
	}

	case 112002:
		if (frame != frameCount)
			break;

		_app->puzzleSetActive(kPuzzle112010);
		_app->objectPresentationPauseAnimation(kObjectWoodenHead, 1);
		break;

	case 112003:
		if (frame != 1)
			break;

		_app->objectPresentationHide(kObjectWoodenHead);
		_app->objectPresentationShow(kObjectWoodenHead, 0);
		_app->soundPlay(112044);
		break;

	case 112004:
		if (frame != frameCount)
			break;

		_app->objectPresentationPauseAnimation(kObject114001, 0);
		_app->soundPlay(112012);
		_app->objectPresentationShow(kObject114001, 1);
		_app->objectSetAccessibilityOn(kObject114006, 0, 1);
		break;

	case 112005:
		if (frame != 1)
			break;

		switch (_app->varGetByte(114008)) {
		default:
			break;

		case 4:
			_app->soundPlay(112004);
			break;

		case 3:
			_app->soundPlay(112007);
			break;

		case 1:
			_app->soundPlay(112009);
			break;
		}

		_app->varSetByte(114008, _app->varGetByte(114008) - 1);
		sub_460AB0();
		break;

	case 112006:
		if (frame != frameCount)
			break;

		_app->objectPresentationHide(114023);
		_app->rotationSetMovabilityOn(111203, 1, 1);
		_app->objectPresentationHide(kObject11);
		_app->objectPresentationShow(kObject11, 18);
		_app->objectSetAccessibilityOn(kObject20, 1, 1);
		_app->objectSetAccessibilityOn(kObject114503);
		_app->soundPlay(111072);
		_app->objectSetAccessibilityOn(kObject114020, 5, 5);
		break;

	case 112007:
		if (frame != frameCount)
			break;

		_app->puzzleSetActive(kPuzzle114033);
		break;

	case 112507:
		if (frame != frameCount)
			break;

		if (_app->varGetByte(114505) > 0) {
			if (_app->varGetByte(114523) == 1) {
				_app->objectPresentationShow(kObject114515, 3);
				_app->objectPresentationSetAnimationOnRotation(kObject114515, 3, 0, 112507);
				_app->varSetByte(114523, _app->varGetByte(114523) + 3);
				break;
			}

			_app->objectPresentationShow(kObject114515, 2);
			_app->objectPresentationSetAnimationOnRotation(kObject114515, 2, 0, 112507);
			_app->varSetByte(114523, _app->varGetByte(114523) + 1);
			if (_app->varGetByte(114523) > 16)
				_app->varSetByte(114523, 0);
			break;
		}

		_app->varSetByte(114523, _app->varGetByte(114523) + 1);
		if (_app->varGetByte(114523) > 16)
			_app->varSetByte(114523, 0);

		_app->soundStop(112066, 1024);
		_app->soundStop(112065, 1024);

		if (_app->varGetByte(114523) == 10)
			_app->rotationSetMovabilityOn(111106, 1, 1);
		break;

	case 112508:
		if (frame != 1)
			break;

		if (!_app->varGetByte(114508) || _app->varGetByte(114510) != 1)
			_app->rotationSetActive(111401);
		else
			_app->rotationSetActive(111403);
		break;

	case 112509:
		if (frame != frameCount)
			break;

		_app->objectPresentationPauseAnimation(kObject114522, (uint32)_app->varGetByte(114512));

		if (_app->varGetByte(114513) == 2) {
			_app->objectPresentationUnpauseAnimation(kObject114522, (uint32)_app->varGetByte(114512));
			_app->puzzleSetActive(kPuzzle114027);
		}

		_app->objectSetAccessibilityOn(kObject114522);
		_app->objectSetAccessibilityOff(kObject114522, (uint32)_app->varGetByte(114513), (uint32)_app->varGetByte(114513));
		break;

	case 112510: {
		if (frame != 1)
			break;

		_app->soundPlay(112022);

		if (_app->varGetByte(114513) < 0) {
			_app->varSetByte(114511, 0);
			_app->objectSetAccessibilityOn(kObject114522);
			break;
		}

		int32 presentation = 2 * _app->varGetByte(114513) + 2;
		if (_app->varGetByte(114513) == 2)
			presentation = _app->varGetByte(114514);

		_app->objectPresentationShow(kObject114522, (uint32)presentation);
		_app->objectPresentationSetAnimationOnRotation(kObject114522, (uint32)presentation, 0, 112509);
		_app->varSetByte(114512, (int8)presentation);
		break;
	}

	case 112512:
		if (frame == 1)
			_app->soundPlay(112015);
		break;

	case 112591:
		if (frame != frameCount)
			break;

		if (_app->varGetByte(114515) >= 4) {
			_app->soundPlay(112021, kSoundLoop);
			_app->objectPresentationHide(kObject114525, 0);
			_app->objectPresentationShow(kObject114525, 1);
		}
		break;

	case 112592:
		if (frame == frameCount)
			_app->objectPresentationPauseAnimation(kObject114515, 1);
		break;

	case 112593:
		if (frame != 1)
			break;

		_app->objectSetAccessibilityOn(kObjectGeologicalSurveyMap, 1, 1);
		_app->objectPresentationHide(kObject114201);

		if (_app->varGetByte(114017) > 0) {
			_app->objectPresentationHide(kObject114201, 3);
			_app->objectPresentationHide(kObject114201, 5);
			_app->objectPresentationShow(kObject114201, 5);
			_app->varSetByte(114017, _app->varGetByte(114017) + 1);
		}

		_app->soundPlay(112000);

		if (_app->varGetByte(114017) == 2) {
			// Advances the progress animation frame (0x4dc040), it doesn't save
			if (_app->getSaveManager()->getData()->progressState == kProgressState2)
				_app->getSaveManager()->getData()->progress++;

			_app->puzzleSetActive(kPuzzle114032);
			_app->puzzleSetMovabilityOff(kPuzzle114032);
			_app->soundPlay(111038);
		}
		break;

	case 112594:
	case 112595:
		if (frame != frameCount)
			break;

		_app->objectPresentationPauseAnimation(kObject114201, animationId == 112594 ? 2 : 0);
		_app->objectSetAccessibilityOn(kObject114201, 2, 2);
		break;

	case 112596:
		if (frame != 1)
			break;

		_app->soundStop(112048, 1024);
		_app->soundPlay(112047);
		break;

	case 112597:
		if (frame != frameCount)
			break;

		_app->soundStop(112050, 1024);
		_app->soundPlay(112049);
		_app->puzzleSetActive(kPuzzle112014);
		break;

	case 112598:
		if (frame != 1)
			break;

		_app->soundPlay(112047);
		_app->rotationSetAlp(111206, 205.0f);
		_app->rotationSetActive(111206);
		_app->bagAdd(kObjectKey5);
		_app->objectSetAccessibilityOff(kObject114503);
		break;

	case 112599:
		if (frame != frameCount)
			break;

		_app->soundPlay(112047);
		_app->objectSetAccessibilityOff(kObject114503);
		break;
	}
}

// FAUST.EXE 0x4683c0
void Zone14Faust::onSound(Id id, SoundType type, uint32 a3, bool process) {
	if (!process)
		return;

	switch (id) {
	default:
		break;

	case 111033:
	case 111057:
		_app->soundPlay(112052);
		_app->objectPresentationHide(kObjectTape1, 3);
		_app->varSetByte(112022, 2);
		_app->puzzleSetMovabilityOn(kPuzzle112010);
		_app->objectSetAccessibilityOn(kObjectTape1, 2, 2);
		_app->objectSetAccessibilityOff(kObjectTape1, 3, 3);
		break;

	case 111036:
		_app->soundPlay(111037);
		break;

	case 111038: {
		// The first nine wheels of the code lock turn by themselves
		_app->varSetByte(114017, _app->varGetByte(114017) + 1);

		float alp = _app->rotationGetAlp(111401);
		float bet = _app->rotationGetBet(111401);

		_app->rotationSetActive(111401);
		_app->rotationSetRolTo(111401, 88.0f, 0.0f, 87.0f);
		_app->rotationSetRolTo(111401, 88.0f, 0.0f, 65.0f);

		for (uint32 i = 0; i < 13; i++)
			_app->objectPresentationShow(114317 + i, (uint32)_app->varGetByte(114301 + i));

		_app->puzzleSetActive(kPuzzle114016);

		static const int32 digits[9] = { 2, 8, 2, 8, 3, 1, 6, 6, 2 };
		for (uint32 i = 0; i < 9; i++) {
			Id varId = 114301 + i;
			ObjectId objectId = 114317 + i;
			bool reached;

			do {
				reached = (_app->varGetByte(varId) == digits[i]);

				if (_app->varGetByte(varId) != digits[i]) {
					int32 digit = _app->varGetByte(varId) + (_app->varGetByte(varId) > digits[i] ? -1 : 1);
					_app->varSetByte(varId, (int8)digit);
					_app->objectPresentationHideAndRemove(objectId);
					_app->objectPresentationShow(objectId, (uint32)digit);
				}

				_app->soundPlay(112002);
				_app->_vm->update();
				_app->_vm->update();
				_app->_vm->update();
			} while (!reached);
		}

		for (uint32 i = 0; i < 8; i++)
			_app->_vm->update();

		_app->rotationSetAlp(111401, alp);
		_app->rotationSetBet(111401, bet);
		_app->rotationSetRan(111401, 87.0f);
		_app->rotationSetActive(111401);
		_app->puzzleSetMovabilityOn(kPuzzle114032);
		break;
	}

	case 111042:
		_app->objectPresentationHide(kObject15);
		_app->objectSetAccessibilityOff(kObject1);
		_app->soundPlay(_app->varGetByte(111000) == 1 ? 111080 : 111079, kSoundLoop);
		_app->sub_468290(3);
		break;

	case 111069:
		_app->soundPlay(111070);
		break;

	case 111076:
		_app->objectPresentationHide(kObject15);
		_app->objectSetAccessibilityOff(kObject1);
		_app->soundPlay(_app->varGetByte(111000) == 1 ? 111080 : 111079, kSoundLoop);
		break;

	case 111094:
		_app->soundPlay(111095);
		break;
	}
}

// FAUST.EXE 0x465ed0
void Zone14Faust::onBag(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, DragControl *dragControl, byte type) {
	switch (id) {
	default:
		break;

	case 114001:
		// Four dials, turned by angle
		switch (type) {
		default:
			break;

		case 1:
			_app->dragControlSetCoords1(Common::Point(_app->varGetWord(114001 + target), _app->varGetWord(114005 + target)));
			break;

		case 2:
			_app->varSetByte(114001 + target, (int8)_dragPrevious);

			if (_app->varGetByte(114001) == 0 && _app->varGetByte(114002) == 27
			 && _app->varGetByte(114003) == 10 && _app->varGetByte(114004) == 12) {
				_app->objectPresentationShow(kObject114001, 0);
				_app->objectPresentationSetAnimationOnRotation(kObject114001, 0, 0, 112004);
				_app->rotationSetMovabilityOff(111401, 2, 5);
				_app->rotationSetActive(111401);
				_app->soundPlay(112013);
			}
			break;

		case 3: {
			int32 position = ApplicationFaust::getDragAngle(dragControl) * 36 / 360;
			if (position > 36)
				position = 0;

			if (_dragPrevious != position) {
				if (position < 0)
					position += 36;

				ObjectId objectId = 114002 + target;
				_app->objectPresentationHideAndRemove(objectId);
				_app->objectPresentationShow(objectId, (uint32)position);
				_app->soundPlay(112010);
			}

			_dragPrevious = position;
			break;
		}
		}
		break;

	case 114007:
		// Seven wheels, dragged sideways
		switch (type) {
		default:
			break;

		case 1:
			_app->dragControlSetField45(2);
			_app->dragControlSetHotspot(Common::Rect(0, 0, 640, 480));
			_dragPrevious = -1;
			break;

		case 2: {
			_app->varSetByte(114010 + target, (int8)_dragValue);

			// The original checks 114010 and 114012 twice (8 or 9, 6 or 5)
			int32 count = 0;
			if (_app->varGetByte(114010) == 8)
				count++;
			if (_app->varGetByte(114010) == 9)
				count++;
			if (_app->varGetByte(114011) == 7)
				count++;
			if (_app->varGetByte(114012) == 6)
				count++;
			if (_app->varGetByte(114012) == 5)
				count++;
			if (_app->varGetByte(114013) == 4)
				count++;
			if (_app->varGetByte(114014) == 3)
				count++;
			if (_app->varGetByte(114015) == 1)
				count++;
			if (_app->varGetByte(114016) == 0)
				count++;

			if (count != 7)
				break;

			// Spin all wheels back to zero
			int32 sum;
			do {
				sum = 0;
				for (Id varId = 114010; varId < 114017; varId++)
					sum += _app->varGetByte(varId);

				for (Id varId = 114010; varId < 114017; varId++) {
					if (_app->varGetByte(varId) > 0) {
						_app->varSetByte(varId, _app->varGetByte(varId) - 1);
						_app->objectPresentationHideAndRemove(varId);
						_app->objectPresentationShow(varId, (uint32)_app->varGetByte(varId));
					}
				}

				_app->_vm->update();
			} while (sum > 0);

			_app->puzzleSetActive(kPuzzle114005);
			_app->objectPresentationShow(kObject114006, (uint32)_app->varGetByte(114007));
			_app->varSetByte(114008, 4);
			_app->objectSetAccessibilityOff(kObject114006, 2, 8);
			if (_app->varGetByte(114007) == 7)
				_app->objectSetAccessibilityOn(kObject114006, 8, 8);
			_app->soundPlay(112006);
			break;
		}

		case 3: {
			if (_app->dragControlXEqual0())
				break;

			int32 offset = (int32)_app->dragControlGetOffsetX0() / 25;
			Id varId = 114010 + target;

			if (_app->dragControlXLower0())
				_dragValue = wrapDigit(_app->varGetByte(varId) + offset);
			else
				_dragValue = wrapDigit(_app->varGetByte(varId) - offset);

			_app->objectPresentationHideAndRemove(varId);
			_app->objectPresentationShow(varId, (uint32)_dragValue);
			break;
		}
		}
		break;

	case 114316:
		// Thirteen wheels, dragged vertically
		switch (type) {
		default:
			break;

		case 1:
			_app->dragControlSetField45(2);
			_app->dragControlSetHotspot(Common::Rect(0, 0, 640, 480));
			_dragPrevious = -1;
			break;

		case 2: {
			_app->varSetByte(114301 + target, (int8)_dragValue);

			static const int8 code[13] = { 2, 8, 2, 8, 3, 1, 6, 6, 9, 1, 2, 5, 2 };
			for (uint32 i = 0; i < 13; i++)
				if (_app->varGetByte(114301 + i) != code[i])
					return;

			_app->playMovie("a11s04n02a01");
			_app->puzzleSetActive(kPuzzle114017);
			_app->varSetDword(90025, 111402);
			_app->objectSetAccessibilityOn(kObject114027, 2, 4);
			break;
		}

		case 3: {
			if (_app->dragControlYEqual0())
				break;

			int32 offset = (int32)_app->dragControlGetOffsetY0() / 25;
			Id varId = 114301 + target;

			if (_app->dragControlYLower0())
				_dragValue = wrapDigit(_app->varGetByte(varId) + offset);
			else
				_dragValue = wrapDigit(_app->varGetByte(varId) - offset);

			if (_dragPrevious != _dragValue) {
				_app->soundPlay(112002);

				ObjectId objectId = 114317 + target;
				_app->objectPresentationHideAndRemove(objectId);
				_app->objectPresentationShow(objectId, (uint32)_dragValue);
			}

			_dragPrevious = _dragValue;
			break;
		}
		}
		break;
	}
}

// FAUST.EXE 0x468370
void Zone14Faust::onUpdateBag(const Common::Point &point) {
	if (_app->varGetByte(112023) > -1) {
		_app->soundStop(111000 + _app->varGetByte(112023), 1024);
		_app->varSetByte(112023, -1);
	}
}

// FAUST.EXE 0x466630
void Zone14Faust::onBagClickedObject(ObjectId id) {
	switch (id) {
	default:
		break;

	case kObjectPipe:
		if (!_app->varGetByte(114522)) {
			_app->cursorDelete();
			_app->puzzleSetMod(kPuzzleMenu, 2, 21);
			_app->objectSetAccessibilityOff(20, 13, 13);
			_app->objectSetAccessibilityOff(kObject114503);
			_app->objectPresentationHide(kObject11);
			_app->objectPresentationShow(kObject11, 16);
			_app->objectSetAccessibilityOn(kObjectPipe, 0, 0);
			_app->objectSetAccessibilityOn(kObjectPipe, 2, 2);
			_app->varSetByte(114522, 1);
		}
		break;

	case kObjectCodingWheel:
		if (!_app->varGetByte(114520)) {
			_app->cursorDelete();
			_app->puzzleSetMod(kPuzzleMenu, 2, 23);
			_app->objectPresentationShow(kObjectCodingWheel, 35 - _app->varGetByte(114521));
			_app->objectSetAccessibilityOn(kObject23);
			_app->varSetByte(114520, 1);
		}
		break;

	case kObjectPaperKnife:
		if (_app->varGetByte(114100) > 0) {
			if (_app->soundIsPlaying(112016)) {
				_app->sub_45FF30();
			} else {
				_app->objectPresentationShow(kObject12, 1);
				_app->cursorDelete();
				_app->objectSetAccessibilityOff(kObject22);
				_app->objectSetAccessibilityOn(kObject22, 1, 2);
				_app->soundPlay(112016, kSoundLoop);
				_app->soundSetVolume(112016, 1);
			}
		}
		break;
	}
}

// FAUST.EXE 0x467e40
void Zone14Faust::onUpdateBefore(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, const Common::Point &point) {
	// The original passes the object id and its accessibility index
	Id objectId = movabilityFrom;
	Id index = movabilityTo;

	switch (objectId) {
	default:
		break;

	case 112001:
	case 112080:
	case 112081:
	case 112082:
		// Hovering plays a sound per accessibility
		if (index >= 60)
			break;

		if (_app->varGetByte(112023) == -1) {
			_app->soundPlay(111000 + index);
			_app->varSetByte(112023, (int8)index);
		}

		if (_app->varGetByte(112023) != (int32)index) {
			_app->soundStop(111000 + _app->varGetByte(112023), 1024);
			_app->varSetByte(112023, -1);
		}
		break;

	case 112027:
		if (index == 5 && !_app->soundIsPlaying(111032))
			_app->soundPlay(111032);
		break;

	case 112083:
		if (_app->varGetByte(112023) > -1) {
			_app->soundStop(111000 + _app->varGetByte(112023), 1024);
			_app->varSetByte(112023, -1);
		}

		if (isInsideQuad(point.x, point.y, 1856, 191, 1889, 209, 1868, 273, 1833, 251)) {
			_app->objectSetAccessibilityOff(objectId, 0, 0);
			_app->objectSetAccessibilityOn(objectId, 1, 1);

			if (!_app->soundIsPlaying(111021)) {
				_app->soundPlay(111021);
				_app->varSetByte(112023, 21);
			}
		} else {
			_app->objectSetAccessibilityOn(objectId, 0, 0);
			_app->objectSetAccessibilityOff(objectId, 1, 1);
		}
		break;

	case 114006: {
		uint32 from, to;
		bool inside;

		switch (index) {
		default:
			return;

		case 0:
		case 1:
			from = 0;
			to = 1;
			inside = isInsideQuad(point.x, point.y, 214, 286, 291, 268, 372, 319, 279, 348);
			break;

		case 4:
		case 5:
			from = 4;
			to = 5;
			inside = isInsideQuad(point.x, point.y, 164, 194, 323, 159, 450, 301, 243, 363);
			break;

		case 6:
		case 7:
			from = 6;
			to = 7;
			inside = isInsideQuad(point.x, point.y, 164, 194, 323, 159, 450, 301, 243, 363);
			break;
		}

		if (inside) {
			_app->objectSetAccessibilityOff(kObject114006, from, from);
			_app->objectSetAccessibilityOn(kObject114006, to, to);
		} else {
			_app->objectSetAccessibilityOn(kObject114006, from, from);
			_app->objectSetAccessibilityOff(kObject114006, to, to);
		}
		break;
	}

	case 114027:
		if (index == 5 && !_app->soundIsPlaying(111081))
			_app->soundPlay(111081);
		break;

	case 114511:
	case 114512: {
		bool inside = (objectId == 114511)
			? isInsideQuad(point.x, point.y, 290, 193, 421, 284, 391, 322, 279, 206)
			: isInsideQuad(point.x, point.y, 323, 185, 435, 243, 427, 270, 311, 213);

		if (inside) {
			_app->objectSetAccessibilityOff(objectId, 0, 0);
			_app->objectSetAccessibilityOn(objectId, 1, 1);
		} else {
			_app->objectSetAccessibilityOn(objectId, 0, 0);
			_app->objectSetAccessibilityOff(objectId, 1, 1);
		}
		break;
	}
	}
}

// FAUST.EXE 0x4667b0
void Zone14Faust::onBeforeRide(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, MovabilityType movabilityType) {
	_app->objectPresentationHide(kObject25);

	switch (movabilityType) {
	default:
		break;

	case kMovabilityRotationToRotation:
		if ((movabilityFrom == 111403 || movabilityFrom == 111405) && movabilityTo == 111201)
			_app->varSetDword(90028, (int32)movabilityFrom);
		break;

	case kMovabilityRotationToPuzzle:
		if (movabilityTo == kPuzzle114016) {
			for (uint32 i = 0; i < 13; i++) {
				_app->objectPresentationHideAndRemove(114317 + i);
				_app->objectPresentationShow(114317 + i, (uint32)_app->varGetByte(114301 + i));
			}
		}
		break;

	case kMovabilityPuzzleToRotation:
		if (movabilityFrom == kPuzzle114023) {
			if (_app->varGetByte(114524) != 1)
				break;

			_app->objectPresentationHide(kObject114516);
			_app->objectSetAccessibilityOff(kObjectKey6, 0, 0);
			_app->objectSetAccessibilityOff(kObjectMercury, 0, 0);
			_app->objectSetAccessibilityOff(kObject114517, 0, 0);
			_app->objectSetAccessibilityOn(kObject114516, 0, 0);
			_app->objectSetAccessibilityOff(kObject114516, 1, 1);

			int32 index = 1;
			if (_app->varGetByte(114507) > 0)
				index += 2;
			if (_app->varGetByte(114506) > 0)
				index++;

			_app->soundPlay(112063);
			_app->playMovie(Common::String::format("a11s01n06p01s0%dr", index));
			_app->soundPlay(112062);
		} else if (movabilityFrom == kPuzzle112010) {
			_app->objectPresentationHide(kObjectTape1, 1);
			_app->objectPresentationHide(kObjectTape1, 0);
			_app->bagRemove(kObjectTape1);
			_app->bagRemove(kObjectTape2);
			_app->bagRemove(kObjectTape3);
			_app->objectSetAccessibilityOn(kObjectTape1, 0, 0);

			if (_app->varGetByte(112022) == 7)
				_app->bagAdd(kObjectTape4);

			_app->soundPlay(112053);
			_app->_vm->update();
			_app->_vm->update();
			_app->varSetByte(112021, 0);
			_app->varSetByte(112022, 0);
		}
		break;
	}
}

// FAUST.EXE 0x466a00
void Zone14Faust::onAfterRide(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, MovabilityType movabilityType) {
	Id current = movabilityFrom;
	Id previous = movabilityTo;

	switch (movabilityType) {
	default:
		break;

	case kMovabilityRotationToRotation:
		switch (current) {
		default:
			break;

		case 111401:
			// Passing through the hallway to the room picked in onBeforeRide
			if (previous == 111201) {
				// Var 90028 is 0 until the player has left 111403/111405; the original then
				// only logs errors for the unknown rotation and stays in 111401
				Id rotationId = (Id)_app->varGetDword(90028);
				if (rotationId) {
					_app->rotationSetAlp(rotationId, 335.0f);
					_app->rotationSetActive(rotationId);
				}
				_app->soundPlay(112071);
			}
			break;

		case 111105:
			if (previous == 111201) {
				_app->soundStop(111079, 1024);
				_app->soundStop(111080, 1024);
				_app->soundPlay(112071);
				_app->timerStart(kTimer0, 12000);
			}
			break;

		case 111201:
			if (previous == 111105) {
				_app->soundPlay(112071);
				_app->soundPlay(_app->varGetByte(111000) == 1 ? 111080 : 111079, kSoundLoop);
				_app->timerStop(kTimer0);
			} else if (previous == 111401 || previous == 111403 || previous == 111405) {
				_app->soundPlay(112071);
			}
			break;

		case 111203:
			if (previous == 111301)
				_app->soundPlay(112071);
			break;

		case 111204:
			if (previous == 111501)
				_app->soundPlay(112071);
			break;

		case 111301:
			if (previous == 111203)
				_app->soundPlay(112071);
			break;

		case 111403:
		case 111405:
			if (previous == 111201)
				_app->soundPlay(112071);
			break;

		case 111501:
			if (previous == 111204)
				_app->soundPlay(112071);
			break;
		}
		break;

	case kMovabilityRotationToPuzzle:
		if (current == kPuzzle114028) {
			if (_app->varGetByte(114526) > 0)
				sub_4604F0();
		} else if (current == kPuzzle114015 || current == kPuzzle114024 || current == kPuzzle114025) {
			_app->varSetDword(90025, (int32)previous);
		}
		break;

	case kMovabilityPuzzleToRotation:
		if (previous == kPuzzle114021) {
			_app->puzzleSetMovabilityOff(kPuzzle114021, 1, 1);
			_app->objectPresentationHide(kObjectMonocular, 2);
			_app->objectSetAccessibilityOn(kObjectMonocular, 4, 4);
		} else if (previous == kPuzzle112010) {
			_app->soundPlay(112045);
			_app->objectPresentationSetAnimationOnRotation(kObjectWoodenHead, 2, 0, 112003);
			_app->objectPresentationShow(kObjectWoodenHead, 2);
			_app->objectPresentationUnpauseAnimation(kObjectWoodenHead, 1);
			_app->objectPresentationHide(kObjectWoodenHead, 1);
		}
		break;

	case kMovabilityPuzzleToPuzzle:
		if (current == kPuzzle114011) {
			_app->soundPlay(112072);
			_app->soundPlay(111039);
		} else if (current == kPuzzle114012) {
			_app->soundPlay(112073);
		}
		break;
	}
}

// FAUST.EXE 0x4604f0: the alchemy furnace starts once everything is in place
void Zone14Faust::sub_4604F0() {
	if (_app->varGetByte(114526) != 1 || _app->varGetByte(114528) != 1 || !_app->bagHas(kObjectSealingRing))
		return;

	_app->varSetByte(114526, 2);
	_app->objectSetAccessibilityOn(kObject114503);
	_app->puzzleSetMod(kPuzzleMenu, 2, 114503);
	_app->varSetByte(114515, 0);
	_app->timerStart(kTimer1, 1000);
	advanceProgress();
}

// FAUST.EXE 0x460a20: once var 114502 is set, alchemy ingredients in the bag move to object 13
void Zone14Faust::sub_460A20() {
	if (_app->varGetByte(114526) > 1 || _app->varGetByte(114502) <= 0)
		return;

	for (Id objectId = kObjectLead; objectId <= kObjectRockSalt; objectId++) {
		if (!_app->bagHas(objectId))
			continue;

		_app->cursorDelete();
		_app->objectPresentationShow(kObject13, (uint32)(objectId - 112600));
		_app->bagRemove(objectId);
		_app->soundPlay(112019);
	}
}

// FAUST.EXE 0x460ab0: next step of the cabinet sequence (var 114008 counts down)
void Zone14Faust::sub_460AB0() {
	if (_app->varGetByte(114008) == 4) {
		_app->soundPlay(112005);
		_app->objectPresentationHide(kObject114006, (uint32)_app->varGetByte(114007));
		_app->objectSetAccessibilityOn(kObject114006, 6, 6);
		_app->objectSetAccessibilityOff(kObject114006, 8, 8);
		_app->objectPresentationShow(kObject114006, (uint32)(_app->varGetByte(114007) + 1));
		_app->objectPresentationSetAnimationOnPuzzle(kObject114006, (uint32)(_app->varGetByte(114007) + 1), 0, 112005);
	}

	if (_app->varGetByte(114008) == 3) {
		_app->objectPresentationHide(kObject114006);
		_app->objectSetAccessibilityOn(kObject114006, 4, 5);
		_app->objectSetAccessibilityOff(kObject114006, 6, 6);
		_app->objectPresentationShow(kObject114006, 6);
		_app->objectPresentationSetAnimationOnPuzzle(kObject114006, 6, 0, 112005);
	}

	if (_app->varGetByte(114008) == 2) {
		_app->objectSetAccessibilityOn(kObject114006, 3, 3);
		_app->objectSetAccessibilityOff(kObject114006, 4, 5);
		_app->varSetByte(114008, _app->varGetByte(114008) - 1);
	}

	if (_app->varGetByte(114008) == 1) {
		_app->objectPresentationHide(kObject114006, (uint32)_app->varGetByte(114006));
		_app->objectSetAccessibilityOn(kObject114006, 2, 2);
		_app->objectSetAccessibilityOff(kObject114006, 3, 3);
		_app->objectPresentationShow(kObject114006, (uint32)(_app->varGetByte(114006) + 1));
		_app->objectPresentationSetAnimationOnPuzzle(kObject114006, (uint32)(_app->varGetByte(114006) + 1), 0, 112005);
	}

	if (_app->varGetByte(114008) == 0) {
		_app->objectPresentationHide(kObject114006);
		_app->rotationSetActive(111401);
	}
}

// FAUST.EXE 0x460490: stop the sound playing at the cabinet
void Zone14Faust::sub_460490() {
	if (!_app->soundIsPlaying(112016))
		return;

	_app->objectPresentationHide(kObject12, 1);
	_app->objectSetAccessibilityOff(kObject22);
	_app->soundStop(112016, 1024);
	_app->varSetByte(114100, 0);
}

// FAUST.EXE 0x4605a0: refresh the alchemy table and pick the matching view (var 90025 = rotation 111402..111406)
void Zone14Faust::sub_4605A0() {
	_app->objectPresentationHide(kObject114521);
	_app->objectPresentationHide(kObjectMirror, 1);
	_app->objectPresentationHide(kObjectMirror, 2);
	_app->objectPresentationHide(kObjectMirror, 3);

	if (_app->varGetByte(114525) == 1)
		_app->objectPresentationShow(kObjectMirror, 1);

	if (_app->varGetByte(114510) == 1)
		_app->objectPresentationShow(kObject114521, 0);

	if (!_app->varGetByte(114508)) {
		uint32 rotationId = _app->varGetDword(90025);
		if (rotationId > 111402)
			_app->varSetDword(90025, rotationId - (rotationId > 111404 ? 4 : 2));
		return;
	}

	_app->objectPresentationHide(kObject114521);
	_app->objectPresentationShow(kObject114521, 1);

	if (_app->varGetByte(114510) != 1)
		return;

	_app->objectPresentationShow(kObject114521, 2);
	_app->objectPresentationHide(kObjectMirror, 1);

	if (_app->varGetByte(114525) == 1) {
		_app->objectPresentationShow(kObjectMirror, 3);

		if (_app->varGetDword(90025) < 111403)
			_app->varSetDword(90025, _app->varGetDword(90025) + 4);

		if (_app->varGetDword(90025) < 111405)
			_app->varSetDword(90025, _app->varGetDword(90025) + 2);
	} else {
		_app->objectPresentationShow(kObjectMirror, 2);

		if (_app->varGetDword(90025) < 111403)
			_app->varSetDword(90025, _app->varGetDword(90025) + 2);
	}
}

// Inlined in 0x460f70: a movie interrupts the background music, which then restarts
void Zone14Faust::playMovieWithMusic(const Common::String &name) {
	_app->soundStop(111079, 1024);
	_app->soundStop(111080, 1024);
	_app->playMovie(name);
	_app->soundPlay(_app->varGetByte(111000) == 1 ? 111080 : 111079, kSoundLoop);
}

// Inlined in 0x460f70: show a close-up (object 11) from rotation 111206 with exit 20
void Zone14Faust::showCloseUp(uint32 presentation, uint32 accessibility) {
	_app->varSetDword(90027, 111206);
	_app->rotationSetFreOn(111206);
	_app->objectPresentationHide(kObject11);
	_app->objectPresentationShow(kObject11, presentation);
	_app->objectSetAccessibilityOff(kObject20);
	if (_app->varGetByte(111000) == 1)
		_app->objectSetAccessibilityOn(kObject20, 0, 0);
	_app->objectSetAccessibilityOn(kObject20, 2, 2);
	_app->objectSetAccessibilityOn(kObject20, accessibility, accessibility);
	_app->objectSetAccessibilityOn(kObject114503);
	_app->soundPlay(112036);
}

// Advances the progress animation frame (0x4dc040), it doesn't save
void Zone14Faust::advanceProgress() {
	if (_app->getSaveManager()->getData()->progressState == kProgressState2)
		_app->getSaveManager()->getData()->progress++;
}

// FAUST.EXE 0x460e10: is (x, y) inside the quad p1-p2-p3-p4 (top, bottom, right and left edges)?
bool Zone14Faust::isInsideQuad(int32 x, int32 y, int32 x1, int32 y1, int32 x2, int32 y2, int32 x3, int32 y3, int32 x4, int32 y4) {
	// The original nudges coordinates to avoid dividing by zero
	if (x1 == x2)
		x2++;
	if (x3 == x4)
		x4++;
	if (y1 == y4)
		y4++;
	if (y2 == y3)
		y3++;

	if (y < (int32)((double)(y2 - y1) / (x2 - x1) * (x - x1)) + y1)
		return false;

	if (y > (int32)((double)(y4 - y3) / (x4 - x3) * (x - x4)) + y4)
		return false;

	if (x > (int32)((double)(x2 - x3) / (y2 - y3) * (y - y2)) + x2)
		return false;

	return x >= (int32)((double)(x1 - x4) / (y1 - y4) * (y - y1)) + x1;
}

int32 Zone14Faust::wrapDigit(int32 value) {
	value %= 10;
	if (value < 0)
		value += 10;

	return value;
}

} // End of namespace Ring
