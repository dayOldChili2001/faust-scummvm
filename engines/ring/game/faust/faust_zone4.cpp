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

#include "ring/game/faust/faust_zone4.h"

#include "ring/game/faust/faust_application.h"
#include "ring/game/faust/faust_shared.h"

#include "ring/base/saveload.h"

#include "ring/debug.h"
#include "ring/ring.h"
#include "ring/helpers.h"

using namespace FaustGame;

namespace Ring {

Zone4Faust::Zone4Faust(ApplicationFaust *application) : _app(application) {
}

Zone4Faust::~Zone4Faust() {
	// Zero-out passed pointers
	_app = nullptr;
}

void Zone4Faust::onInit() {
	_app->setCurrentZone(kZone4);

	_app->puzzleAdd(kPuzzle13101);
	_app->puzzleAddBackgroundImage(kPuzzle13101, "a01s03n02p02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle13102);
	_app->puzzleAddBackgroundImage(kPuzzle13102, "a01s03n01p03.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle13110);
	_app->puzzleAddBackgroundImage(kPuzzle13110, "a01s03n01p01l01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle13111);
	_app->puzzleAddBackgroundImage(kPuzzle13111, "a01s03n01p01l02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle13112);
	_app->puzzleAddBackgroundImage(kPuzzle13112, "a01s03n01p02l01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle13113);
	_app->puzzleAddBackgroundImage(kPuzzle13113, "a01s03n01p02l02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle13105);
	_app->puzzleAddBackgroundImage(kPuzzle13105, "a01s03n02p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle13106);
	_app->puzzleAddBackgroundImage(kPuzzle13106, "a01s03n02p03.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle13107);
	_app->puzzleAddBackgroundImage(kPuzzle13107, "a01s04n01p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle13108);
	_app->puzzleAddBackgroundImage(kPuzzle13108, "a01s04n02p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle13109);
	_app->puzzleAddBackgroundImage(kPuzzle13109, "a01s06n01p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle13201);
	_app->puzzleAddBackgroundImage(kPuzzle13201, "a01s03n02p04.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle13202);
	_app->puzzleAddBackgroundImage(kPuzzle13202, "a01s03n02p05.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle13203);
	_app->puzzleAddBackgroundImage(kPuzzle13203, "a01s03n02p06.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle13901);
	_app->puzzleAddBackgroundImage(kPuzzle13901, "a01s03n01p06.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle13902);
	_app->puzzleAddBackgroundImage(kPuzzle13902, "a01s03n01p06l03.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle13204);
	_app->puzzleAddBackgroundImage(kPuzzle13204, "a01s03n01p06l04.bmp", Common::Point(0, 16), true);
	_app->rotationAdd(13311, "A01S03N01R01", 0, 14);
	_app->rotationSetCompressionBufferLength(13311, 1800000);
	_app->rotationAdd(13321, "A01S03N02R01", 0, 6);
	_app->rotationSetCompressionBufferLength(13321, 1000000);
	_app->rotationAdd(13312, "A01S03N01R02", 0, 12);
	_app->rotationSetCompressionBufferLength(13312, 1200000);
	_app->rotationAdd(13322, "A01S03N02R02", 0, 1);
	_app->rotationAdd(13411, "A01S04N01R01", 0, 2);
	_app->rotationAdd(13421, "A01S04N02R01", 0, 11);
	_app->rotationSetCompressionBufferLength(13421, 2000000);
	_app->rotationAdd(13412, "A01S04N01R02", 0, 2);
	_app->rotationAdd(13422, "A01S04N02R02", 0, 5);
	_app->rotationAdd(13511, "A01S05N01R01", 0, 2);
	_app->rotationAdd(13521, "A01S05N02R01", 0, 1);
	_app->rotationAdd(13531, "A01S05N03R01", 0, 1);
	_app->rotationAdd(13611, "A01S06N01R01", 0, 5);
	_app->rotationSetCompressionBufferLength(13611, 1500000);
	_app->rotationAddMovabilityToRotation(13311, 13321, "", Common::Rect(1177, 61, 1543, 450), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13311, 0, 90.0f, 16.0f, 87.0f, 0.0f, 2, 90.0f, 16.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(13321, 13311, "", Common::Rect(3025, -8, 3294, 348), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13321, 0, 270.0f, 16.0f, 87.0f, 0.0f, 2, 270.0f, 16.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(13321, kPuzzle13101, "", Common::Rect(868, 188, 1075, 443), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(13321, 1, 53.0f, 26.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(13321, kPuzzle13105, "", Common::Rect(319, 415, 529, 518), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(13321, 2, 0.0f, 26.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(13321, kPuzzle13106, "", Common::Rect(1311, 259, 1511, 359), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(13321, 3, 90.0f, 26.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(13411, 13421, "", Common::Rect(3042, 1, 3299, 247), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13411, 0, 270.0f, 26.0f, 87.0f, 0.0f, 2, 270.0f, 26.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(13411, kPuzzle13107, "", Common::Rect(616, 456, 796, 593), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(13411, 1, 25.0f, 26.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(13421, 13411, "", Common::Rect(1211, 50, 1624, 320), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13421, 0, 94.0f, 26.0f, 87.0f, 0.0f, 2, 94.0f, 26.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(13421, 13321, "surogat", Common::Rect(1618, -155, 1747, 355), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13421, 1, 150.0f, -12.0f, 87.0f, 0.0f, 2, 228.0f, 26.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(13511, 13531, "", Common::Rect(3051, 78, 3350, 458), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13511, 0, 270.0f, 26.0f, 87.0f, 0.0f, 2, 270.0f, 26.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(13511, 13421, "surogat", Common::Rect(1183, 441, 1538, 573), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13511, 1, 90.0f, 26.0f, 87.0f, 0.0f, 2, 90.0f, 26.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(13511, 13422, "surogat", Common::Rect(1183, 441, 1538, 573), false, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13511, 2, 90.0f, 26.0f, 87.0f, 0.0f, 2, 90.0f, 26.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(13521, 13531, "", Common::Rect(210, 48, 827, 505), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13521, 0, 0.0f, 26.0f, 87.0f, 0.0f, 2, 0.0f, 26.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(13531, 13511, "", Common::Rect(1221, 1, 1562, 375), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13531, 0, 90.0f, 26.0f, 87.0f, 0.0f, 2, 90.0f, 26.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(13531, 13521, "", Common::Rect(2081, 61, 2378, 413), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13531, 1, 180.0f, 26.0f, 87.0f, 0.0f, 2, 180.0f, 26.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(13531, 13611, "", Common::Rect(2977, 59, 3299, 448), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13531, 2, 270.0f, 26.0f, 87.0f, 0.0f, 2, 270.0f, 26.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(13611, 13531, "", Common::Rect(1037, 160, 1785, 521), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13611, 0, 90.0f, 26.0f, 87.0f, 0.0f, 2, 90.0f, 26.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(13412, 13422, "", Common::Rect(2717, -38, 3188, 327), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13412, 0, 243.0f, 0.0f, 87.0f, 0.0f, 2, 270.0f, 26.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(13412, kPuzzle13107, "", Common::Rect(634, 118, 740, 254), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(13412, 1, 25.0f, 0.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(13422, 13412, "", Common::Rect(1260, -43, 1529, 298), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13422, 0, 85.0f, 0.0f, 87.0f, 0.0f, 2, 82.0f, 16.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(13422, 13322, "surogat", Common::Rect(1631, -373, 1743, 266), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13422, 1, 120.0f, -17.0f, 87.0f, 0.0f, 2, 228.0f, 26.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(13312, 13322, "", Common::Rect(1212, -73, 1529, 338), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13312, 0, 90.0f, 0.0f, 87.0f, 0.0f, 2, 90.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(13312, 13422, "", Common::Rect(1624, 169, 1829, 315), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13312, 1, 130.0f, 20.0f, 87.0f, 0.0f, 2, 90.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(13322, 13312, "", Common::Rect(3014, -115, 3274, 312), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13322, 0, 270.0f, 0.0f, 87.0f, 0.0f, 2, 270.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(13322, kPuzzle13201, "", Common::Rect(898, 40, 1088, 280), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(13322, 1, 53.0f, 13.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(13322, kPuzzle13202, "", Common::Rect(339, 233, 508, 359), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(13322, 2, 0.0f, 26.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(13322, kPuzzle13203, "", Common::Rect(1328, -97, 1492, 5), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(13322, 3, 90.0f, 0.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(13322, 13422, "", Common::Rect(2634, 170, 2872, 333), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(13322, 4, 230.0f, 23.0f, 87.0f, 0.0f, 2, 90.0f, 0.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle13101, 13321, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle13101, 0, 53.0f, 26.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle13105, 13321, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle13105, 0, 0.0f, 26.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle13106, 13321, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle13106, 0, 90.0f, 26.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle13201, 13322, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle13201, 0, 53.0f, 13.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle13202, 13322, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle13202, 0, 0.0f, 26.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle13203, 13322, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle13203, 0, 90.0f, 0.0f, 87.0f);
	_app->puzzleAddMovabilityToPuzzle(kPuzzle13902, kPuzzle13901, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->objectAdd(kObjectLotteryTicket2, "Lottery ticket", "A03_LotteryTicket", 1);
	_app->objectSetActiveCursor(kObjectLotteryTicket2, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectLotteryTicket2, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObject13901, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject13901, kPuzzle13901, Common::Rect(380, 244, 436, 306), false, kCursorTake, 0);
	_app->objectAddPuzzleAccessibility(kObject13901, kPuzzle13901, Common::Rect(343, 244, 369, 294), false, kCursorTake, 1);
	_app->objectAddPuzzleAccessibility(kObject13901, kPuzzle13901, Common::Rect(315, 259, 341, 286), false, kCursorTake, 2);
	_app->objectAddPuzzleAccessibility(kObject13901, kPuzzle13901, Common::Rect(290, 277, 317, 305), false, kCursorTake, 3);
	_app->objectAddPuzzleAccessibility(kObject13901, kPuzzle13901, Common::Rect(270, 309, 301, 347), false, kCursorTake, 4);
	_app->objectAdd(kObject13902, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject13902, kPuzzle13204, Common::Rect(174, 37, 375, 283), false, kCursorAction, 0);
	_app->objectAddPresentation(kObject13902);

	// FAUST.EXE 0x44cc66: one presentation per card (group * 32 + card), 32 cards for each of the 5 opponent slots
	static const struct {
		int16 x;
		int16 y;
		uint32 priority;
	} opponentCards[5] = {
		{  90, 40, 900 },
		{ 137, 51, 800 },
		{ 155, 39, 700 },
		{ 172, 30, 600 },
		{ 190, 19, 500 }
	};

	uint32 index = 1;
	for (uint32 group = 1; group < 6; group++) {
		for (uint32 i = 1; i < 33; i++) {
			_app->objectAddPresentation(kObject13902);
			_app->objectPresentationAddImageToPuzzle(kObject13902, index, kPuzzle13901, Common::String::format("a01s03n01p06s02.%04d.tga", group), Common::Point(246, 133), true, kDrawTypeAlpha, 900 - opponentCards[group - 1].priority);
			_app->objectPresentationAddImageToPuzzle(kObject13902, index, kPuzzle13902, Common::String::format("a01s03n01p06s01.%d%03d.tga", group, i), Common::Point(opponentCards[group - 1].x, opponentCards[group - 1].y), true, kDrawTypeAlpha, opponentCards[group - 1].priority);
			index++;
		}
	}

	_app->objectAdd(kObject13900, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject13900, kPuzzle13901, Common::Rect(0, 0, 320, 240), false, kCursorActionObject, 0);
	_app->objectAddPuzzleAccessibility(kObject13900, kPuzzle13901, Common::Rect(50, 295, 141, 341), false, kCursorTake, 1);
	_app->objectAddPresentation(kObject13900);
	_app->objectPresentationAddImageToPuzzle(kObject13900, 0, kPuzzle13901, "a01s03n01p06l01.tga", Common::Point(354, 270), true, kDrawTypeAlpha, 3000);
	_app->objectPresentationAddImageToPuzzle(kObject13900, 0, kPuzzle13901, "a01s03n01p06l02.tga", Common::Point(204, 152), true, kDrawTypeAlpha, 3000);
	_app->objectPresentationAddTextToPuzzle(kObject13900, 0, kPuzzle13902, "", Common::Point(320, 220), kFontDefault, Color(255, 255, 255), Color(-1, -1, -1));

	for (int16 i = 0; i < 160; i += 16)
		_app->objectPresentationAddTextToPuzzle(kObject13900, 0, kPuzzle13901, "", Common::Point(420, i + 16), kFontDefault, Color(0, 255, 0), Color(-1, -1, -1));

	for (int16 i = 0; i < 160; i += 16)
		_app->objectPresentationAddTextToPuzzle(kObject13900, 0, kPuzzle13901, "", Common::Point(260, i + 16), kFontDefault, Color(0, 255, 0), Color(-1, -1, -1));

	// FAUST.EXE 0x44cf2e: same layout for the player's 5 slots
	static const struct {
		int16 x1;
		int16 y1;
		int16 x2;
		int16 y2;
		uint32 priority;
	} playerCards[5] = {
		{ 347, 229, 362, 249, 900 },
		{ 338, 235, 343, 255, 800 },
		{ 310, 234, 305, 254, 700 },
		{ 282, 246, 272, 261, 600 },
		{ 263, 268, 238, 288, 500 }
	};

	index = 1;
	for (uint32 group = 1; group < 6; group++) {
		for (uint32 i = 1; i < 33; i++) {
			Common::String filename = Common::String::format("a01s03n01p06s01.%d%03d.tga", group, i);
			_app->objectAddPresentation(kObject13900);
			_app->objectPresentationAddImageToPuzzle(kObject13900, index, kPuzzle13901, filename, Common::Point(playerCards[group - 1].x1, playerCards[group - 1].y1), true, kDrawTypeAlpha, playerCards[group - 1].priority);
			_app->objectPresentationAddImageToPuzzle(kObject13900, index, kPuzzle13902, filename, Common::Point(playerCards[group - 1].x2, playerCards[group - 1].y2), true, kDrawTypeAlpha, playerCards[group - 1].priority);
			index++;
		}
	}

	_app->objectPresentationShow(kObject13900, 0);
	_app->varDefineByte(13900, 0);

	int8 offset = 7;
	int8 offset2 = 4;
	// FAUST.EXE 0x44d0c2: the 32-card deck (card id, rank 7-14, suit 4-1)
	for (int8 i = 0; i < 32; i++) {
		_app->varDefineByte(13902 + i, (byte)(i + 1));
		_app->varDefineByte(13802 + i, offset);
		_app->varDefineByte(13842 + i, offset2);

		++offset;
		if (offset > 14) {
			--offset2;
			offset = 7;
		}
	}

	for (uint32 i = 0; i < 10; i++) {
		_app->varDefineByte(13940 + i, 0);
		_app->varDefineByte(13950 + i, 0);
		_app->varDefineByte(13960 + i, 0);
	}

	_app->varDefineByte(13971, 0);
	_app->varDefineByte(13972, 0);
	_app->varDefineByte(13973, 0);
	_app->varDefineByte(13974, 0);
	_app->varDefineByte(13975, 0);
	_app->varDefineByte(13976, 0);
	_app->varDefineByte(13977, 0);
	_app->varDefineByte(13978, 0);
	_app->varDefineByte(13979, 0);
	_app->objectAdd(kObject13903, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject13903, kPuzzle13901, Common::Rect(0, 0, 640, 480), true, kCursorIdle, 0);
	_app->objectAddPresentation(kObject13903);
	_app->objectAdd(kObject13101, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13101, 13311, Common::Rect(2874, -38, 3582, 460), true, kCursorMove, 0);
	_app->objectAdd(kObject13102, "", "Cur_drag", 4);
	_app->objectSetPassiveDrawCursor(kObject13102, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetActiveDrawCursor(kObject13102, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);

	for (uint32 i = 0; i < 40; i++) {
		_app->objectAddPresentation(kObject13102);
		_app->objectPresentationAddImageToPuzzle(kObject13102, i, kPuzzle13102, Common::String::format("a01s03n01p03s01a.%04d.bmp", i + 1), Common::Point(171, 168), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject13103, "", "Cur_drag", 4);
	_app->objectSetPassiveDrawCursor(kObject13103, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetActiveDrawCursor(kObject13103, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);

	for (uint32 i = 0; i < 40; i++) {
		_app->objectAddPresentation(kObject13103);
		_app->objectPresentationAddImageToPuzzle(kObject13103, i, kPuzzle13102, Common::String::format("a01s03n01p03s01b.%04d.bmp", i + 1), Common::Point(233, 166), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject13104, "", "Cur_drag", 4);
	_app->objectSetPassiveDrawCursor(kObject13104, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetActiveDrawCursor(kObject13104, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);

	for (uint32 i = 0; i < 40; i++) {
		_app->objectAddPresentation(kObject13104);
		_app->objectPresentationAddImageToPuzzle(kObject13104, i, kPuzzle13102, Common::String::format("a01s03n01p03s01c.%04d.bmp", i + 1), Common::Point(286, 168), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject13105, "", "Cur_drag", 4);
	_app->objectSetPassiveDrawCursor(kObject13105, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetActiveDrawCursor(kObject13105, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);

	for (uint32 i = 0; i < 40; i++) {
		_app->objectAddPresentation(kObject13105);
		_app->objectPresentationAddImageToPuzzle(kObject13105, i, kPuzzle13102, Common::String::format("a01s03n01p03s01d.%04d.bmp", i + 1), Common::Point(339, 167), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObject13106, "", "Cur_drag", 4);
	_app->objectSetPassiveDrawCursor(kObject13106, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetActiveDrawCursor(kObject13106, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);

	for (uint32 i = 0; i < 40; i++) {
		_app->objectAddPresentation(kObject13106);
		_app->objectPresentationAddImageToPuzzle(kObject13106, i, kPuzzle13102, Common::String::format("a01s03n01p03s01e.%04d.bmp", i + 1), Common::Point(386, 170), true, kDrawTypeNormal, 1000);
	}

	_app->objectAddPuzzleAccessibility(kObject13102, kPuzzle13102, Common::Rect(170, 169, 224, 271), true, kCursorDragDrop, 0);
	_app->objectAddPuzzleAccessibility(kObject13102, kPuzzle13102, Common::Rect(231, 164, 273, 270), true, kCursorDragDrop, 1);
	_app->objectAddPuzzleAccessibility(kObject13102, kPuzzle13102, Common::Rect(283, 170, 328, 269), true, kCursorDragDrop, 2);
	_app->objectAddPuzzleAccessibility(kObject13102, kPuzzle13102, Common::Rect(338, 169, 384, 271), true, kCursorDragDrop, 3);
	_app->objectAddPuzzleAccessibility(kObject13102, kPuzzle13102, Common::Rect(387, 172, 440, 266), true, kCursorDragDrop, 4);
	_app->objectAdd(kObject13107, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13107, 13321, Common::Rect(2371, 505, 2548, 563), true, kCursorAction, 0);
	_app->objectAddPresentation(kObject13107);
	_app->objectPresentationAddImageToRotation(kObject13107, 0, 13321, 4);
	_app->objectAddPresentation(kObject13107);
	_app->objectPresentationAddAnimationToRotation(kObject13107, 1, 13321, 5, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13107, 1, 0, 13001);
	_app->objectAdd(kObject13108, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13108, 13321, Common::Rect(2061, 387, 2475, 486), true, kCursorAction, 0);
	_app->objectAddPresentation(kObject13108);
	_app->objectPresentationAddImageToRotation(kObject13108, 0, 13321, 2);
	_app->objectAddPresentation(kObject13108);
	_app->objectPresentationAddImageToRotation(kObject13108, 1, 13321, 3);
	_app->objectAddPresentation(kObject13108);
	_app->objectPresentationAddAnimationToRotation(kObject13108, 2, 13321, 5, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject13108);
	_app->objectPresentationAddImageToRotation(kObject13108, 3, 13311, 0);
	_app->objectAddPresentation(kObject13108);
	_app->objectPresentationAddImageToRotation(kObject13108, 4, 13311, 2);
	_app->objectAdd(kObject13113, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13113, 13311, Common::Rect(1655, 348, 1720, 394), false, kCursorZoom, 0);
	_app->objectAddRotationAccessibility(kObject13113, 13311, Common::Rect(1749, 371, 1814, 408), false, kCursorZoom, 1);
	_app->objectAddRotationAccessibility(kObject13113, 13321, Common::Rect(2675, 381, 2747, 423), false, kCursorZoom, 2);
	_app->objectAddRotationAccessibility(kObject13113, 13321, Common::Rect(2692, 343, 2749, 380), false, kCursorZoom, 3);
	_app->objectAddRotationAccessibility(kObject13113, 13311, Common::Rect(1810, 430, 1886, 493), false, kCursorZoom, 4);
	_app->objectAddRotationAccessibility(kObject13113, 13311, Common::Rect(1944, 446, 2010, 495), false, kCursorZoom, 5);
	_app->objectAddRotationAccessibility(kObject13113, 13321, Common::Rect(2808, 319, 2866, 354), false, kCursorZoom, 6);
	_app->objectAddRotationAccessibility(kObject13113, 13321, Common::Rect(2800, 287, 2859, 317), false, kCursorZoom, 7);
	_app->objectAddPuzzleAccessibility(kObject13113, kPuzzle13112, Common::Rect(0, 420, 640, 464), true, kCursorBack, 8);
	_app->objectAddPuzzleAccessibility(kObject13113, kPuzzle13113, Common::Rect(0, 420, 640, 464), true, kCursorBack, 9);
	_app->objectAdd(kObject13109, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13109, 13311, Common::Rect(1634, 305, 1858, 453), false, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject13109, 13321, Common::Rect(2620, 329, 2865, 451), false, kCursorAction, 1);
	_app->objectAddPresentation(kObject13109);
	_app->objectPresentationAddAnimationToRotation(kObject13109, 0, 13311, 13, 15, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13109, 0, 0, 13003);
	_app->objectAddPresentation(kObject13109);
	_app->objectPresentationAddAnimationToRotation(kObject13109, 1, 13321, 1, 15, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13109, 1, 0, 13003);
	_app->objectAdd(kObject13110, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13110, 13311, Common::Rect(1631, 341, 1800, 472), false, kCursorZoom, 0);
	_app->objectAddRotationAccessibility(kObject13110, 13321, Common::Rect(2649, 359, 2847, 470), false, kCursorZoom, 1);
	_app->objectAddPuzzleAccessibility(kObject13110, kPuzzle13102, Common::Rect(0, 420, 640, 464), true, kCursorBack, 2);
	_app->objectAdd(kObjectRing, "Ring", "A03_Ring", 1);
	_app->objectSetActiveCursor(kObjectRing, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectRing, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectStChristopherMedallion, "St. Christopher Medallion", "A03_Medallion", 1);
	_app->objectSetActiveCursor(kObjectStChristopherMedallion, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectStChristopherMedallion, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObject13139, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject13139, kPuzzle13110, Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->objectAddPuzzleAccessibility(kObject13139, kPuzzle13111, Common::Rect(0, 420, 640, 464), true, kCursorBack, 1);
	_app->objectAdd(kObject13111, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13111, 13311, Common::Rect(2214, 511, 2469, 530), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject13111, 13311, Common::Rect(2272, 538, 2364, 577), false, kCursorTake, 1);
	_app->objectAddRotationAccessibility(kObject13111, 13311, Common::Rect(2383, 561, 2431, 575), false, kCursorTake, 2);
	_app->objectAddRotationAccessibility(kObject13111, 13311, Common::Rect(2343, 602, 2413, 618), false, kCursorAction, 3);
	_app->objectAddPresentation(kObject13111);
	_app->objectPresentationAddAnimationToRotation(kObject13111, 0, 13311, 1, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13111, 0, 0, 13004);
	_app->objectAddPresentation(kObject13111);
	_app->objectPresentationAddImageToRotation(kObject13111, 1, 13311, 3);
	_app->objectAddPresentation(kObject13111);
	_app->objectPresentationAddAnimationToRotation(kObject13111, 2, 13311, 9, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13111, 2, 0, 13004);
	_app->objectAddPresentation(kObject13111);
	_app->objectPresentationAddImageToRotation(kObject13111, 3, 13311, 5);
	_app->objectAddPresentation(kObject13111);
	_app->objectPresentationAddAnimationToRotation(kObject13111, 4, 13311, 10, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13111, 4, 0, 13004);
	_app->objectAddPresentation(kObject13111);
	_app->objectPresentationAddImageToRotation(kObject13111, 5, 13311, 4);
	_app->objectAddPresentation(kObject13111);
	_app->objectPresentationAddAnimationToRotation(kObject13111, 6, 13311, 11, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13111, 6, 0, 13004);
	_app->objectAddPresentation(kObject13111);
	_app->objectPresentationAddImageToRotation(kObject13111, 7, 13311, 6);
	_app->objectAddPresentation(kObject13111);
	_app->objectPresentationAddAnimationToRotation(kObject13111, 8, 13311, 1, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject13111, 8, 0, 13005);
	_app->objectAddPresentation(kObject13111);
	_app->objectPresentationAddAnimationToRotation(kObject13111, 9, 13311, 9, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject13111, 9, 0, 13005);
	_app->objectAddPresentation(kObject13111);
	_app->objectPresentationAddAnimationToRotation(kObject13111, 10, 13311, 10, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject13111, 10, 0, 13005);
	_app->objectAddPresentation(kObject13111);
	_app->objectPresentationAddAnimationToRotation(kObject13111, 11, 13311, 11, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject13111, 11, 0, 13005);
	_app->objectAdd(kObject13112, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13112, 13311, Common::Rect(2228, 558, 2464, 572), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject13112, 13311, Common::Rect(2322, 556, 2431, 582), false, kCursorZoom, 1);
	_app->objectAddRotationAccessibility(kObject13112, 13311, Common::Rect(2355, 641, 2411, 651), false, kCursorAction, 2);
	_app->objectAddPresentation(kObject13112);
	_app->objectPresentationAddAnimationToRotation(kObject13112, 0, 13311, 12, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13112, 0, 0, 13006);
	_app->objectAddPresentation(kObject13112);
	_app->objectPresentationAddImageToRotation(kObject13112, 1, 13311, 7);
	_app->objectAddPresentation(kObject13112);
	_app->objectPresentationAddAnimationToRotation(kObject13112, 2, 13311, 12, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject13112, 2, 0, 13007);
	_app->objectAdd(kObject13114, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject13114, kPuzzle13101, Common::Rect(246, 250, 400, 397), true, kCursorZoom, 0);
	_app->objectAddPuzzleAccessibility(kObject13114, kPuzzle13201, Common::Rect(246, 250, 400, 397), true, kCursorZoom, 1);
	_app->objectAdd(kObject13115, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13115, 13311, Common::Rect(2260, -50, 2603, 287), true, kCursorZoom, 0);
	_app->objectAdd(kObject13116, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject13116, kPuzzle13105, Common::Rect(189, 154, 266, 214), true, kCursorAction, 0);
	_app->objectAddPuzzleAccessibility(kObject13116, kPuzzle13105, Common::Rect(396, 160, 465, 222), true, kCursorAction, 1);
	_app->objectAddPuzzleAccessibility(kObject13116, kPuzzle13105, Common::Rect(298, 263, 346, 419), false, kCursorZoom, 2);
	_app->objectAddPresentation(kObject13116);
	_app->objectPresentationAddAnimationToPuzzle(kObject13116, 0, kPuzzle13105, "a01s03n02p01s01", kImageTypeBMP, Common::Point(290, 251), kDrawTypeNormal, 1000, 2, 15.0f, 4);
	_app->objectAddPresentation(kObject13116);
	_app->objectPresentationAddAnimationToPuzzle(kObject13116, 1, kPuzzle13105, "a01s03n02p01s02", kImageTypeBMP, Common::Point(300, 247), kDrawTypeNormal, 1000, 3, 15.0f, 4);
	_app->objectPresentationSetAnimationOnPuzzle(kObject13116, 1, 0, 13024);
	_app->objectAddPresentation(kObject13116);
	_app->objectPresentationAddAnimationToPuzzle(kObject13116, 2, kPuzzle13105, "a01s03n02p01s03", kImageTypeBMP, Common::Point(296, 254), kDrawTypeNormal, 1000, 2, 15.0f, 4);
	_app->objectAdd(kObject13121, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject13121, kPuzzle13106, Common::Rect(270, 212, 368, 325), true, kCursorActionObject, 0);
	_app->objectAddPuzzleAccessibility(kObject13121, kPuzzle13107, Common::Rect(271, 233, 388, 380), true, kCursorAction, 1);
	_app->objectAddPuzzleAccessibility(kObject13121, kPuzzle13107, Common::Rect(  0, 420, 640, 464), true, kCursorBack, 2);
	_app->objectAddPresentation(kObject13121);
	_app->objectPresentationAddImageToRotation(kObject13121, 0, 13321, 0);
	_app->objectAddPresentation(kObject13121);
	_app->objectPresentationAddImageToRotation(kObject13121, 1, 13311, 8);
	_app->objectAddPresentation(kObject13121);
	_app->objectPresentationAddImageToRotation(kObject13121, 2, 13411, 0);
	_app->objectPresentationShow(kObject13121, 2);
	_app->objectAddPresentation(kObject13121);
	_app->objectPresentationAddImageToRotation(kObject13121, 3, 13421, 0);
	_app->objectPresentationShow(kObject13121, 3);
	_app->objectAddPresentation(kObject13121);
	_app->objectPresentationAddImageToPuzzle(kObject13121, 4, kPuzzle13107, "a01s04n01p01l01.bmp", Common::Point(281, 241), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObjectWoodLog, "Wood log", "A03_Log", 1);
	_app->objectSetActiveCursor(kObjectWoodLog, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectWoodLog, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddRotationAccessibility(kObjectWoodLog, 13321, Common::Rect(1230, 371, 1548, 514), true, kCursorTake, 0);
	_app->objectAddRotationAccessibility(kObjectWoodLog, 13411, Common::Rect(1167, 437, 1582, 573), false, kCursorTake, 1);
	_app->objectAdd(kObjectOldNew, "Old newspaper", "A03_OldPaper", 1);
	_app->objectSetActiveCursor(kObjectOldNew, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectOldNew, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddRotationAccessibility(kObjectOldNew, 13421, Common::Rect(1664, 518, 1863, 589), true, kCursorTake, 0);
	_app->objectAdd(kObject13123, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13123, 13411, Common::Rect(3062, 275, 3592, 538), true, kCursorZoom, 0);
	_app->objectAddRotationAccessibility(kObject13123, 13421, Common::Rect(1089, 181, 1376, 427), true, kCursorZoom, 1);
	_app->objectAdd(kObject13124, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13124, 13421, Common::Rect(363, 174, 529, 320), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject13124, 13421, Common::Rect(330, 486, 506, 551), true, kCursorAction, 1);
	_app->objectAddRotationAccessibility(kObject13124, 13421, Common::Rect(488, 144, 632, 294), false, kCursorAction, 2);
	_app->objectAddRotationAccessibility(kObject13124, 13421, Common::Rect(492, 500, 590, 577), false, kCursorAction, 3);
	_app->objectAddRotationAccessibility(kObject13124, 13421, Common::Rect(363, 174, 529, 320), false, kCursorActionObject, 4);
	_app->objectAddPresentation(kObject13124);
	_app->objectPresentationAddAnimationToRotation(kObject13124, 0, 13421, 1, 15, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13124, 0, 0, 13008);
	_app->objectAddPresentation(kObject13124);
	_app->objectPresentationAddAnimationToRotation(kObject13124, 1, 13421, 1, 15, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject13124, 1, 0, 13009);
	_app->objectAddPresentation(kObject13124);
	_app->objectPresentationAddImageToRotation(kObject13124, 2, 13421, 2);
	_app->objectAddPresentation(kObject13124);
	_app->objectPresentationAddAnimationToRotation(kObject13124, 3, 13421, 8, 15, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13124, 3, 0, 13010);
	_app->objectAddPresentation(kObject13124);
	_app->objectPresentationAddAnimationToRotation(kObject13124, 4, 13421, 8, 15, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject13124, 4, 0, 13011);
	_app->objectAddPresentation(kObject13124);
	_app->objectPresentationAddImageToRotation(kObject13124, 5, 13421, 3);
	_app->objectAdd(kObjectBucketWithMolasse, "Bucket with molasse", "A03_FullBucket", 1);
	_app->objectSetActiveCursor(kObjectBucketWithMolasse, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectBucketWithMolasse, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectBucket, "Bucket", "A03_Bucket", 1);
	_app->objectSetActiveCursor(kObjectBucket, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectBucket, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPresentation(kObjectBucket);
	_app->objectPresentationAddImageToRotation(kObjectBucket, 0, 13411, 1);
	_app->objectAddRotationAccessibility(kObjectBucket, 13411, Common::Rect(43, 523, 165, 593), true, kCursorTake, 0);
	_app->objectAdd(kObject13127, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject13127, kPuzzle13108, Common::Rect(157, 178, 487, 352), true, kCursorActionObject, 0);
	_app->objectAddPuzzleAccessibility(kObject13127, kPuzzle13108, Common::Rect(0, 420, 640, 464), true, kCursorBack, 1);
	_app->objectAddPresentation(kObject13127);
	_app->objectPresentationAddImageToPuzzle(kObject13127, 0, kPuzzle13108, "a01s04n02p01l02.bmp", Common::Point(115, 145), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject13127);
	_app->objectPresentationAddImageToPuzzle(kObject13127, 1, kPuzzle13108, "a01s04n02p01l01.bmp", Common::Point(115, 146), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject13127);
	_app->objectPresentationAddImageToPuzzle(kObject13127, 2, kPuzzle13108, "a01s04n02p01l03.bmp", Common::Point(116, 148), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject13127);
	_app->objectPresentationAddAnimationToPuzzle(kObject13127, 3, kPuzzle13108, "a01s04n02p01s02", kImageTypeBMP, Common::Point(118, 145), kDrawTypeNormal, 1000, 40, 25.0f, 4);
	_app->objectAddPresentation(kObject13127);
	_app->objectPresentationAddAnimationToPuzzle(kObject13127, 4, kPuzzle13108, "a01s04n02p01s01", kImageTypeBMP, Common::Point(108, 137), kDrawTypeNormal, 1000, 40, 25.0f, 4);
	_app->objectAdd(kObjectMatches, "Matches", "A05_Matches", 1);
	_app->objectSetActiveCursor(kObjectMatches, Common::Point(11, 27), 5, kCursorTypeAnimated, 12.5f, 4, kLoadFromListIcon);
	_app->objectSetPassiveCursor(kObjectMatches, Common::Point(11, 27), 5, kCursorTypeAnimated, 12.5f, 4, kLoadFromListIcon);
	_app->objectAdd(kObject13130, "", "", 1);
	_app->objectAdd(kObjectTap, "Tap", "A03_Tap", 1);
	_app->objectSetActiveCursor(kObjectTap, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectTap, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddRotationAccessibility(kObject13130, 13421, Common::Rect(3127,  306, 3218, 367), true, kCursorActionObject, 0);
	_app->objectAddRotationAccessibility(kObject13130, 13421, Common::Rect(3287,  455, 3410, 502), true, kCursorActionObject, 1);
	_app->objectAddRotationAccessibility(kObject13130, 13421, Common::Rect(3211, -127, 3459, 116), true, kCursorAction, 2);
	_app->objectAddRotationAccessibility(kObject13130, 13421, Common::Rect(3046,  151, 3301, 368), true, kCursorAction, 3);
	_app->objectAddRotationAccessibility(kObject13130, 13421, Common::Rect(3401,  132, 3587, 293), true, kCursorAction, 4);
	_app->objectAddRotationAccessibility(kObject13130, 13421, Common::Rect(2891,  348, 3109, 526), true, kCursorAction, 5);
	_app->objectAddRotationAccessibility(kObject13130, 13421, Common::Rect(3215,  373, 3485, 477), true, kCursorAction, 6);
	_app->objectAddRotationAccessibility(kObject13130, 13421, Common::Rect(3522,  310, 3600, 397), true, kCursorAction, 7);
	_app->objectAddRotationAccessibility(kObject13130, 13421, Common::Rect(   0,  310,   86, 397), true, kCursorAction, 8);
	_app->objectAddRotationAccessibility(kObject13130, 13421, Common::Rect(2912,  188, 3032, 463), false, kCursorAction, 9);
	_app->objectAddRotationAccessibility(kObject13130, 13421, Common::Rect(3032,  441, 3216, 589), false, kCursorAction, 10);
	_app->objectAddRotationAccessibility(kObject13130, 13421, Common::Rect(   0,    0,    0,   0), false, kCursorAction, 11);
	_app->objectAddRotationAccessibility(kObject13130, 13421, Common::Rect(3215,  373, 3485, 477), false, kCursorMove, 12);
	_app->objectAddPresentation(kObject13130);
	_app->objectPresentationAddImageToRotation(kObject13130, 0, 13421, 4);
	_app->objectAddPresentation(kObject13130);
	_app->objectPresentationAddAnimationToRotation(kObject13130, 1, 13421, 9, 15, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13130, 1, 0, 13012);
	_app->objectAddPresentation(kObject13130);
	_app->objectPresentationAddAnimationToRotation(kObject13130, 2, 13421, 9, 15, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject13130, 2, 0, 13013);
	_app->objectAddPresentation(kObject13130);
	_app->objectPresentationAddImageToRotation(kObject13130, 3, 13421, 5);
	_app->objectAddPresentation(kObject13130);
	_app->objectPresentationAddImageToRotation(kObject13130, 4, 13421, 6);
	_app->objectPresentationShow(kObject13130, 4);
	_app->objectAddPresentation(kObject13130);
	_app->objectPresentationAddAnimationToRotation(kObject13130, 5, 13421, 10, 15, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13130, 5, 0, 13014);
	_app->objectAddPresentation(kObject13130);
	_app->objectPresentationAddAnimationToRotation(kObject13130, 6, 13421, 10, 15, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject13130, 6, 0, 13015);
	_app->objectAddPresentation(kObject13130);
	_app->objectPresentationAddImageToRotation(kObject13130, 7, 13421, 7);
	_app->objectAdd(kObjectBottle, "Bottle", "A03_EmptyBottle", 1);
	_app->objectSetActiveCursor(kObjectBottle, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectBottle, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectBottleOfWhiskey, "Bottle of whiskey", "A03_BottleOfWhisky", 1);
	_app->objectSetActiveCursor(kObjectBottleOfWhiskey, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectBottleOfWhiskey, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectBottleOfMolasse, "Bottle of molasse", "A03_FullBottle", 1);
	_app->objectSetActiveCursor(kObjectBottleOfMolasse, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectBottleOfMolasse, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddRotationAccessibility(kObjectBottle, 13421, Common::Rect(722, 310, 1051, 495), true, kCursorTake, 0);
	_app->objectAdd(kObjectBaseballBat, "Baseball Bat", "A03_BaseballBat", 1);
	_app->objectSetActiveCursor(kObjectBaseballBat, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectBaseballBat, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddRotationAccessibility(kObjectBaseballBat, 13511, Common::Rect(2025, 467, 2177, 615), true, kCursorTake, 0);
	_app->objectAddPresentation(kObjectBaseballBat);
	_app->objectPresentationAddImageToRotation(kObjectBaseballBat, 0, 13511, 0);
	_app->objectAdd(kObject13136, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13136, 13511, Common::Rect(3575, 455, 3600, 561), true, kCursorZoom, 0);
	_app->objectAddRotationAccessibility(kObject13136, 13511, Common::Rect(0, 455, 237, 561), true, kCursorZoom, 1);
	_app->objectAdd(kObject13137, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13137, 13611, Common::Rect( 290, 155,  416, 352), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject13137, 13611, Common::Rect( 441, 134,  599, 327), true, kCursorAction, 1);
	_app->objectAddRotationAccessibility(kObject13137, 13611, Common::Rect(2847, -31, 3425, 460), true, kCursorZoom, 2);
	_app->objectAddRotationAccessibility(kObject13137, 13611, Common::Rect( 583, 179,  785, 420), true, kCursorZoom, 3);
	_app->objectAddPuzzleAccessibility(kObject13137, kPuzzle13109, Common::Rect(0, 420, 640, 464), true, kCursorBack, 4);
	_app->objectAddPuzzleAccessibility(kObject13137, kPuzzle13109, Common::Rect(242, 172, 343, 358), true, kCursorZoom, 5);
	_app->objectAddPresentation(kObject13137);
	_app->objectPresentationAddAnimationToRotation(kObject13137, 0, 13611, 3, 30, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13137, 0, 0, 13016);
	_app->objectAddPresentation(kObject13137);
	_app->objectPresentationAddAnimationToRotation(kObject13137, 1, 13611, 4, 30, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13137, 1, 0, 13017);
	_app->objectAddPresentation(kObject13137);
	_app->objectPresentationAddAnimationToRotation(kObject13137, 2, 13611, 1, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13137, 2, 0, 13018);
	_app->objectAddPresentation(kObject13137);
	_app->objectPresentationAddAnimationToRotation(kObject13137, 3, 13611, 1, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject13137, 3, 0, 13019);
	_app->objectAddPresentation(kObject13137);
	_app->objectPresentationAddImageToRotation(kObject13137, 4, 13611, 0);
	_app->objectAdd(kObject13138, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13138, 13521, Common::Rect(2441, 345, 2659, 573), false, kCursorZoom, 0);
	_app->objectAddRotationAccessibility(kObject13138, 13521, Common::Rect(2441, 345, 2659, 573), true, kCursorAction, 1);
	_app->objectAdd(kObject13140, "", "", 1);
	_app->objectAddPresentation(kObject13140);
	_app->objectPresentationAddImageToRotation(kObject13140, 0, 13521, 0);
	_app->objectAddPresentation(kObject13140);
	_app->objectPresentationAddImageToRotation(kObject13140, 1, 13511, 1);
	_app->objectAddPresentation(kObject13140);
	_app->objectPresentationAddImageToRotation(kObject13140, 2, 13531, 0);
	_app->objectAdd(kObject13201, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13201, 13422, Common::Rect(351, -282, 515, -209), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject13201, 13422, Common::Rect(330,  134, 497,  238), true, kCursorAction, 1);
	_app->objectAddRotationAccessibility(kObject13201, 13422, Common::Rect(492, -320, 601, -212), false, kCursorAction, 2);
	_app->objectAddRotationAccessibility(kObject13201, 13422, Common::Rect(  0,    0,   0,    0), false, kCursorAction, 3);
	_app->objectAddRotationAccessibility(kObject13201, 13422, Common::Rect(351, -282, 515, -209), false, kCursorActionObject, 4);
	_app->objectAddPresentation(kObject13201);
	_app->objectPresentationAddAnimationToRotation(kObject13201, 0, 13422, 1, 15, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13201, 0, 0, 13008);
	_app->objectAddPresentation(kObject13201);
	_app->objectPresentationAddAnimationToRotation(kObject13201, 1, 13422, 1, 15, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject13201, 1, 0, 13009);
	_app->objectAddPresentation(kObject13201);
	_app->objectPresentationAddImageToRotation(kObject13201, 2, 13422, 2);
	_app->objectAddPresentation(kObject13201);
	_app->objectPresentationAddAnimationToRotation(kObject13201, 3, 13422, 4, 15, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13201, 3, 0, 13010);
	_app->objectAddPresentation(kObject13201);
	_app->objectPresentationAddAnimationToRotation(kObject13201, 4, 13422, 4, 15, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject13201, 4, 0, 13011);
	_app->objectAddPresentation(kObject13201);
	_app->objectPresentationAddImageToRotation(kObject13201, 5, 13422, 3);
	_app->objectAddRotationAccessibility(kObjectBottle, 13422,  Common::Rect( 782, 130, 1102, 347), true, kCursorTake, 1);
	_app->objectAddRotationAccessibility(kObjectWoodLog, 13412, Common::Rect(1188, 158, 1529, 413), false, kCursorTake, 2);
	_app->objectAddPuzzleAccessibility(kObject13121, kPuzzle13203, Common::Rect(270, 212, 368, 325), true, kCursorZoom, 3);
	_app->objectAddPresentation(kObject13121);
	_app->objectPresentationAddImageToRotation(kObject13121, 5, 13412, 0);
	_app->objectAddPresentation(kObject13121);
	_app->objectPresentationAddImageToRotation(kObject13121, 6, 13422, 0);
	_app->objectPresentationShow(kObject13121, 5);
	_app->objectPresentationShow(kObject13121, 6);
	_app->objectAddPresentation(kObject13121);
	_app->objectPresentationAddImageToRotation(kObject13121, 7, 13312, 6);
	_app->objectAddPresentation(kObject13121);
	_app->objectPresentationAddImageToRotation(kObject13121, 8, 13322, 0);
	_app->objectAddRotationAccessibility(kObjectOldNew, 13422, Common::Rect(1659, 289, 1870, 390), true, kCursorTake, 1);
	_app->objectAdd(kObject13202, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13202, 13422, Common::Rect(3046, -188, 3308,  64), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject13202, 13422, Common::Rect(3404, -190, 3582,  48), true, kCursorAction, 1);
	_app->objectAddRotationAccessibility(kObject13202, 13422, Common::Rect(2877,   69, 3113, 345), true, kCursorAction, 2);
	_app->objectAddRotationAccessibility(kObject13202, 13422, Common::Rect(3227,   68, 3461, 296), true, kCursorAction, 3);
	_app->objectAddRotationAccessibility(kObject13202, 13422, Common::Rect(3512,   61, 3600, 228), true, kCursorAction, 4);
	_app->objectAddRotationAccessibility(kObject13202, 13422, Common::Rect(   0,   61,   73, 228), true, kCursorAction, 5);
	_app->objectAddPresentation(kObjectBucket);
	_app->objectPresentationAddImageToRotation(kObjectBucket, 1, 13412, 1);
	_app->objectAddRotationAccessibility(kObjectBucket, 13412, Common::Rect(36, 308, 237, 429), true, kCursorTake, 1);
	_app->objectAdd(kObject13203, "", "", 1);
	_app->objectAddPresentation(kObject13203);
	_app->objectPresentationAddAnimationToRotation(kObject13203, 0, 13312, 11, 12, 7.0f, 5);
	_app->objectPresentationShow(kObject13203, 0);
	_app->objectAdd(kObject13204, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject13204, kPuzzle13202, Common::Rect(189, 154, 266, 214), true, kCursorAction, 0);
	_app->objectAddPuzzleAccessibility(kObject13204, kPuzzle13202, Common::Rect(396, 160, 465, 222), true, kCursorAction, 1);
	_app->objectAddPuzzleAccessibility(kObject13204, kPuzzle13202, Common::Rect(298, 263, 346, 419), false, kCursorZoom, 2);
	_app->objectAddPresentation(kObject13204);
	_app->objectPresentationAddAnimationToPuzzle(kObject13204, 0, kPuzzle13202, "a01s03n02p05s01", kImageTypeBMP, Common::Point(288, 248), kDrawTypeNormal, 1000, 2, 15.0f, 4);
	_app->objectAddPresentation(kObject13204);
	_app->objectPresentationAddAnimationToPuzzle(kObject13204, 1, kPuzzle13202, "a01s03n02p05s02", kImageTypeBMP, Common::Point(281, 246), kDrawTypeNormal, 1000, 3, 15.0f, 4);
	_app->objectPresentationSetAnimationOnPuzzle(kObject13204, 1, 0, 13025);
	_app->objectAddPresentation(kObject13204);
	_app->objectPresentationAddAnimationToPuzzle(kObject13204, 2, kPuzzle13202, "a01s03n02p05s03", kImageTypeBMP, Common::Point(292, 248), kDrawTypeNormal, 1000, 2, 15.0f, 4);
	_app->objectAdd(kObject13205, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13205, 13312, Common::Rect(731, 34, 803, 130), true, kCursorActionObject, 0);
	_app->objectAdd(kObject13206, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13206, 13312, Common::Rect(2244, 273, 2443, 326), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject13206, 13312, Common::Rect(2262, 313, 2369, 362), false, kCursorTake, 1);
	_app->objectAddRotationAccessibility(kObject13206, 13312, Common::Rect(2362, 322, 2420, 350), false, kCursorTake, 2);
	_app->objectAddRotationAccessibility(kObject13206, 13312, Common::Rect(2248, 359, 2501, 402), false, kCursorAction, 3);
	_app->objectAddPresentation(kObject13206);
	_app->objectPresentationAddAnimationToRotation(kObject13206, 0, 13312, 1, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13206, 0, 0, 13004);
	_app->objectAddPresentation(kObject13206);
	_app->objectPresentationAddImageToRotation(kObject13206, 1, 13312, 0);
	_app->objectAddPresentation(kObject13206);
	_app->objectPresentationAddAnimationToRotation(kObject13206, 2, 13312, 7, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13206, 2, 0, 13004);
	_app->objectAddPresentation(kObject13206);
	_app->objectPresentationAddImageToRotation(kObject13206, 3, 13312, 3);
	_app->objectAddPresentation(kObject13206);
	_app->objectPresentationAddAnimationToRotation(kObject13206, 4, 13312, 8, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13206, 4, 0, 13004);
	_app->objectAddPresentation(kObject13206);
	_app->objectPresentationAddImageToRotation(kObject13206, 5, 13312, 2);
	_app->objectAddPresentation(kObject13206);
	_app->objectPresentationAddAnimationToRotation(kObject13206, 6, 13312, 9, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13206, 6, 0, 13004);
	_app->objectAddPresentation(kObject13206);
	_app->objectPresentationAddImageToRotation(kObject13206, 7, 13312, 4);
	_app->objectAddPresentation(kObject13206);
	_app->objectPresentationAddAnimationToRotation(kObject13206, 8, 13312, 1, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject13206, 8, 0, 13005);
	_app->objectAddPresentation(kObject13206);
	_app->objectPresentationAddAnimationToRotation(kObject13206, 9, 13312, 7, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject13206, 9, 0, 13005);
	_app->objectAddPresentation(kObject13206);
	_app->objectPresentationAddAnimationToRotation(kObject13206, 10, 13312, 8, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject13206, 10, 0, 13005);
	_app->objectAddPresentation(kObject13206);
	_app->objectPresentationAddAnimationToRotation(kObject13206, 11, 13312, 9, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject13206, 11, 0, 13005);
	_app->objectAdd(kObject13207, "", "", 1);
	_app->objectAddRotationAccessibility(kObject13207, 13312, Common::Rect(2242, 359, 2446, 397), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject13207, 13312, Common::Rect(2315, 366, 2441, 451), false, kCursorZoom, 1);
	_app->objectAddRotationAccessibility(kObject13207, 13312, Common::Rect(2251, 441, 2499, 497), false, kCursorAction, 2);
	_app->objectAddPresentation(kObject13207);
	_app->objectPresentationAddAnimationToRotation(kObject13207, 0, 13312, 10, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject13207, 0, 0, 13006);
	_app->objectAddPresentation(kObject13207);
	_app->objectPresentationAddImageToRotation(kObject13207, 1, 13312, 5);
	_app->objectAddPresentation(kObject13207);
	_app->objectPresentationAddAnimationToRotation(kObject13207, 2, 13312, 10, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject13207, 2, 0, 13007);
	_app->objectAdd(kObject13801, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject13801, kPuzzle13112, Common::Rect(248, 154, 392, 249), true, kCursorIdle, 0);
	_app->objectAddPuzzleAccessibility(kObject13801, kPuzzle13113, Common::Rect(248, 154, 392, 249), true, kCursorIdle, 1);
	_app->objectAddPuzzleAccessibility(kObject13801, kPuzzle13110, Common::Rect(196, 107, 469, 248), true, kCursorIdle, 2);
	_app->objectAddPuzzleAccessibility(kObject13801, kPuzzle13111, Common::Rect(196, 107, 469, 248), true, kCursorIdle, 3);
	_app->soundAdd(13054, kSoundTypeBackgroundMusic, "03_bgrmus1.wac", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(13054, 85);
	_app->soundAdd(13055, kSoundTypeBackgroundMusic, "03_bgrmus2.wac", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(13055, 80);
	_app->soundAdd(13074, kSoundTypeBackgroundMusic, "03_bgrmus3.was", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(13042, kSoundTypeAmbientEffect, "03_barell_open2.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13010, kSoundTypeAmbientEffect, "03_burning_wood.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13009, kSoundTypeAmbientEffect, "03_burning_paper.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13017, kSoundTypeAmbientEffect, "03_telephone.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13023, kSoundTypeAmbientEffect, "03_water_running.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13001, kSoundTypeAmbientEffect, "03_elevator_up.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13071, kSoundTypeAmbientEffect, "03_fawcet_empty_running.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13002, kSoundTypeAmbientEffect, "03_elevator_dn.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13076, kSoundTypeAmbientEffect, "03_smash_mirror.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13065, kSoundTypeAmbientEffect, "03_telephone_empty.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13037, kSoundTypeAmbientEffect, "03_stove_door_close2_nobang.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13033, kSoundTypeAmbientEffect, "03_match.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13040, kSoundTypeAmbientEffect, "03_stove_door_open1.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13048, kSoundTypeAmbientEffect, "03_stove_door_open1_Demf.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13038, kSoundTypeAmbientEffect, "03_stove_door_open2.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13039, kSoundTypeAmbientEffect, "03_stove_door_close1.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13047, kSoundTypeAmbientEffect, "03_stove_door_close1_Demf.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13016, kSoundTypeAmbientEffect, "03_bottle_smash.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13041, kSoundTypeAmbientEffect, "03_barell_close2.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13005, kSoundTypeAmbientEffect, "03_log_take3.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13025, kSoundTypeAmbientEffect, "03_slide_box2.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13004, kSoundTypeAmbientEffect, "03_log_take2.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13070, kSoundTypeAmbientEffect, "03_pouring_whiskey_in_glass.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13018, kSoundTypeAmbientEffect, "03_predal_open.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13024, kSoundTypeAmbientEffect, "03_chain_bike.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13003, kSoundTypeAmbientEffect, "03_log_take1.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13006, kSoundTypeAmbientEffect, "03_paper_take1.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13007, kSoundTypeAmbientEffect, "03_paper_take2.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13008, kSoundTypeAmbientEffect, "03_paper_take3.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13011, kSoundTypeAmbientEffect, "03_barrel_hit_empty.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13012, kSoundTypeAmbientEffect, "03_barrel_hit_full.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13013, kSoundTypeAmbientEffect, "03_bottle_take1.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13014, kSoundTypeAmbientEffect, "03_bottle_take2.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13015, kSoundTypeAmbientEffect, "03_bottle_take3.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13019, kSoundTypeAmbientEffect, "03_predal_close.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13020, kSoundTypeAmbientEffect, "03_predal_bang.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13021, kSoundTypeAmbientEffect, "03_water_dripping2.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13026, kSoundTypeAmbientEffect, "03_cifre_tic_metallic.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13027, kSoundTypeAmbientEffect, "03_barell_open1.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13028, kSoundTypeAmbientEffect, "03_barell_close1.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13029, kSoundTypeAmbientEffect, "03_WC_door_squeak4.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13032, kSoundTypeAmbientEffect, "03_WC_hit_metalic.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundSetVolume(13032, 85);
	_app->soundAdd(13045, kSoundTypeAmbientEffect, "03_stove_door_open1_bang.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13046, kSoundTypeAmbientEffect, "03_stove_door_close1_bang.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13049, kSoundTypeAmbientEffect, "03_stove_door_open1_bang_Demf.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13050, kSoundTypeAmbientEffect, "03_stove_door_close1_bang_Demf.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13036, kSoundTypeAmbientEffect, "03_stove_door_close2_wbang.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13043, kSoundTypeAmbientEffect, "03_tap_take.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13044, kSoundTypeAmbientEffect, "03_tap_put.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13051, kSoundTypeAmbientEffect, "03_tap_screw.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13052, kSoundTypeAmbientEffect, "03_medicine_open.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13053, kSoundTypeAmbientEffect, "03_medicine_close.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13056, kSoundTypeAmbientEffect, "03_sqeak_ventil_01.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13057, kSoundTypeAmbientEffect, "03_sqeak_ventil_02.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13058, kSoundTypeAmbientEffect, "03_sqeak_ventil_03.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13059, kSoundTypeAmbientEffect, "03_sqeak_ventil_04.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13060, kSoundTypeAmbientEffect, "03_sqeak_ventil_05.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13061, kSoundTypeAmbientEffect, "03_sqeak_ventil_06.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13062, kSoundTypeAmbientEffect, "03_sqeak_ventil_07.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13063, kSoundTypeAmbientEffect, "03_Take_Kastrola.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13064, kSoundTypeAmbientEffect, "03_barell_close_short.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13066, kSoundTypeAmbientEffect, "03_Press_Button.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13067, kSoundTypeAmbientEffect, "03_Put_Paper.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13068, kSoundTypeAmbientEffect, "03_Put_wood_log.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13069, kSoundTypeAmbientEffect, "03_pouring_whiskey_in_bottle.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13072, kSoundTypeAmbientEffect, "03_electricity.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundSetVolume(13072, 90);
	_app->soundAdd(13073, kSoundTypeAmbientEffect, "03_water_dripping.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13075, kSoundTypeAmbientEffect, "03_take_baseball_bat.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13077, kSoundTypeAmbientEffect, "03_card_mephisto.wav", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(13078, kSoundTypeAmbientEffect, "03_card_mephisto.wav", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->rotationAdd3DSound(13411, 13010, 1, 1, 15, 90, 290.0f, 10);
	_app->rotationAdd3DSound(13421, 13010, 1, 1, 15, 100, 360.0f, 10);
	_app->rotationAdd3DSound(13412, 13010, 1, 1, 15, 90, 290.0f, 10);
	_app->rotationAdd3DSound(13422, 13010, 1, 1, 15, 100, 360.0f, 10);
	_app->puzzleAdd3DSound(13107, 13010, 1, 1, 15, 90, 250.0f, 10);
	_app->puzzleAdd3DSound(13108, 13010, 1, 1, 15, 100, 180.0f, 10);
	_app->rotationSet3DSoundOff(13411, 13010);
	_app->rotationSet3DSoundOff(13421, 13010);
	_app->rotationSet3DSoundOff(13412, 13010);
	_app->rotationSet3DSoundOff(13422, 13010);
	_app->puzzleSet3DSoundOff(13107, 13010);
	_app->puzzleSet3DSoundOff(13108, 13010);
	_app->rotationAdd3DSound(13611, 13017, 1, 1, 15, 85, 130.0f, 10);
	_app->rotationAdd3DSound(13531, 13017, 1, 1, 15, 95, 180.0f, 10);
	_app->rotationAdd3DSound(13521, 13017, 1, 1, 15, 100, 180.0f, 10);
	_app->rotationAdd3DSound(13511, 13017, 1, 1, 15, 90, 242.0f, 10);
	_app->puzzleAdd3DSound(13109, 13017, 1, 1, 15, 85, 250.0f, 10);
	_app->rotationSet3DSoundOff(13611, 13017);
	_app->rotationSet3DSoundOff(13531, 13017);
	_app->rotationSet3DSoundOff(13521, 13017);
	_app->rotationSet3DSoundOff(13511, 13017);
	_app->puzzleSet3DSoundOff(13109, 13017);
	_app->rotationAdd3DSound(13611, 13073, 1, 1, 15, 90, 183.0f, 10);
	_app->rotationAdd3DSound(13531, 13073, 1, 1, 15, 80, 261.0f, 10);
	_app->rotationAdd3DSound(13521, 13073, 1, 1, 15, 75, 310.0f, 10);
	_app->rotationAdd3DSound(13511, 13073, 1, 1, 15, 75, 270.0f, 10);
	_app->puzzleAdd3DSound(13109, 13073, 1, 1, 15, 90, 250.0f, 10);
	_app->rotationAdd3DSound(13611, 13021, 1, 1, 15, 95, 183.0f, 10);
	_app->rotationAdd3DSound(13531, 13021, 1, 1, 15, 85, 261.0f, 10);
	_app->rotationAdd3DSound(13521, 13021, 1, 1, 15, 80, 310.0f, 10);
	_app->rotationAdd3DSound(13511, 13021, 1, 1, 15, 80, 270.0f, 10);
	_app->puzzleAdd3DSound(13109, 13021, 1, 1, 15, 95, 250.0f, 10);
	_app->soundAdd(13301, kSoundTypeDialog, "E06_06_Mar.WAV", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13302, kSoundTypeDialog, "E06_08_Fra.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13303, kSoundTypeDialog, "E06_10_Tod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13304, kSoundTypeDialog, "E06_11_Gyp.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13305, kSoundTypeDialog, "E06_12_Gyp.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13306, kSoundTypeDialog, "e06_13_poster.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13307, kSoundTypeDialog, "E06_14_Tod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13308, kSoundTypeDialog, "E06_15_Tod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13309, kSoundTypeDialog, "E06_17_Tod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13310, kSoundTypeDialog, "E06_19_Tod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13311, kSoundTypeDialog, "e06_22_label.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13312, kSoundTypeDialog, "E06_23_1Tod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13313, kSoundTypeDialog, "E06_23_2Jer.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13314, kSoundTypeDialog, "E06_23_3Tod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13315, kSoundTypeDialog, "E06_24_1Tod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13316, kSoundTypeDialog, "E06_24_2Mef.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13317, kSoundTypeDialog, "E06_24_3Tod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13318, kSoundTypeDialog, "E06_24_4Mef.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13319, kSoundTypeDialog, "E06_24_5Tod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13320, kSoundTypeDialog, "E06_26_Tod.WAV", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13321, kSoundTypeDialog, "E06_27_Mef.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13322, kSoundTypeDialog, "E06_28_Mef.WAV", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13323, kSoundTypeDialog, "E06_29_Mef.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13324, kSoundTypeDialog, "E06_30_Mef.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13325, kSoundTypeDialog, "E06_31_Mef.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13326, kSoundTypeDialog, "E06_32_Mef.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13327, kSoundTypeDialog, "E06_33_Mef.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13328, kSoundTypeDialog, "E06_35_Mef.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13329, kSoundTypeDialog, "E06_36_Tod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13330, kSoundTypeDialog, "E06_37_Mef.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13331, kSoundTypeDialog, "E06_39_Mef.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13332, kSoundTypeDialog, "E06_40_Tod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13333, kSoundTypeDialog, "E06_41_Mef.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13334, kSoundTypeDialog, "E06_42_Mef.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13336, kSoundTypeDialog, "E06_09_article.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13337, kSoundTypeDialog, "E06_16_gangster.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(13338, kSoundTypeDialog, "e06_34_limbo.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->varDefineByte(13018, 1);
	_app->varDefineByte(13001, 0);
	_app->varDefineByte(13002, 0);
	_app->varDefineByte(13003, 0);
	_app->varDefineByte(13004, 0);
	_app->varDefineByte(13005, 0);
	_app->varDefineByte(13006, 0);
	_app->varDefineByte(13007, 0);
	_app->varDefineByte(13008, 0);
	_app->varDefineByte(13009, 0);
	_app->varDefineByte(13010, 0);
	_app->varDefineByte(13012, 0);
	_app->varDefineByte(13011, 0);
	_app->varDefineByte(13013, 1);
	_app->varDefineByte(13014, 0);
	_app->varDefineByte(13015, 0);
	_app->varDefineByte(13016, 0);
	_app->varDefineByte(13017, 0);
	_app->varDefineByte(13019, 0);
	_app->varDefineByte(13020, 0);
	_app->varDefineByte(13021, 0);
	_app->varDefineByte(13022, 0);
	_app->varDefineByte(13023, 0);
	_app->varDefineByte(13024, 0);
	_app->varDefineByte(13025, 0);
	_app->varDefineByte(13026, 0);
	_app->varDefineByte(13027, 0);
	_app->varDefineByte(13028, 0);
	_app->varDefineByte(13029, 0);
	_app->varDefineWord(13001, 0);
	_app->varDefineWord(13002, 0);
	_app->varDefineWord(13003, 0);
	_app->varDefineDword(13001, 0);
	_app->varDefineFloat(13001, 12.0f);
	_app->varDefineFloat(13002, 29.0f);
	_app->varDefineFloat(13003, 16.0f);
	_app->varDefineFloat(13004, 7.0f);
	_app->varDefineFloat(13005, 33.0f);
	_app->objectPresentationShow(kObject13102, (uint32)_app->varGetFloat(13001));
	_app->objectPresentationShow(kObject13103, (uint32)_app->varGetFloat(13002));
	_app->objectPresentationShow(kObject13104, (uint32)_app->varGetFloat(13003));
	_app->objectPresentationShow(kObject13105, (uint32)_app->varGetFloat(13004));
	_app->objectPresentationShow(kObject13106, (uint32)_app->varGetFloat(13005));
}

// The exe's setup dispatcher (0x47d090) sends episode 4 to 0x460150, which also resumes play in zones 11/12/13
void Zone4Faust::onSetup(SetupType type) {
	_app->sub_460150(type);
}

void Zone4Faust::onTimer(TimerId id) {
	switch (id) {
	default:
		break;

	case kTimer0:
		_app->objectPresentationHide(kObject13121, 4);
		_app->timerStop(kTimer0);
		break;

	case kTimer1:
		if (_app->varGetByte(13019) == 5)
			_app->timerStop(kTimer1);

		_app->soundPlay(_app->varGetByte(13019) + 13322);
		_app->varSetByte(13019, _app->varGetByte(13019) + 1);
		break;

	case kTimer2:
		_app->timerStop(kTimer2);
		_app->soundPlay(13327);
		break;

	case kTimer3:
		_app->varSetByte(13900, _app->varGetByte(13900) + 1);
		_app->varGetByte(13900);
		if (_app->varGetByte(13900) == 5)
			_app->timerStop(kTimer3);
		break;

	case kTimer4:
		_app->timerStop(kTimer4);
		_app->timerStart(kTimer4, rnd(5000) + 10000);
		_app->objectPresentationShow(kObject13140);
		_app->timerStart(kTimer5, 100);
		_app->soundPlay(13072);
		break;

	case kTimer5:
		_app->timerStop(kTimer5);
		_app->objectPresentationHide(kObject13140);
		break;
	}
}

// FAUST.EXE 0x4a2bb0
void Zone4Faust::onButtonUp(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, const Common::Point &point) {
	switch (id) {
	default:
		break;

	case kObject13101:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->sub_4ABA90(5);
		break;

	case kObject13107:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->objectPresentationShow(kObject13107, 1);
		_app->soundPlay(13024);
		break;

	case kObject13108:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (_app->varGetByte(13001) == 0) {
			_app->playMovie("A01S03_E06M06");
			break;
		}

		_app->playMovie("A01S03_E06M06");
		_app->playMovie("a01s03n02a02");
		_app->objectPresentationShow(kObject13108, 0);
		_app->objectPresentationShow(kObject13108, 3);
		_app->objectSetAccessibilityOn(kObject13109, 0, 1);
		_app->objectSetAccessibilityOn(kObject13113, 0, 3);
		_app->objectSetAccessibilityOff(kObject13108);
		break;

	case kObject13109:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->soundPlay(13025);
		_app->objectSetAccessibilityOff(kObject13109, 0, 1);
		_app->objectPresentationShow(kObject13109, 0);
		_app->objectPresentationShow(kObject13109, 1);
		_app->objectSetAccessibilityOff(kObject13113, 0, 3);
		break;

	case kObject13110:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0 || target == 1) {
			if (_app->varGetByte(13002) == 0) {
				saveView();
				_app->puzzleSetActive(kPuzzle13102);
			} else {
				_app->soundStopType(kSoundTypeBackgroundMusic, 1024);
				_app->soundPlay(13055, kSoundLoop);
				_app->playMovie("a01s04a01");
				_app->rotationSetAlp(13421, 270.0f);
				_app->rotationSetBet(13421, 26.0f);
				_app->rotationSetRan(13421, 87.0f);
				_app->rotationSetActive(13421);
			}
		}

		if (target == 2)
			restoreView();
		break;

	case kObject13111:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 0:
			_app->varSetByte(13025, 1);
			_app->soundPlay(13018);
			_app->objectSetAccessibilityOff(kObject13111, 0, 0);
			_app->objectSetAccessibilityOff(kObject13112, 0, 0);
			showBoxes(kObject13111, true, 0, 4, 2, 6);
			break;

		case 3:
			_app->soundPlay(13019);
			_app->objectSetAccessibilityOff(kObject13111);
			_app->varSetByte(13025, 0);
			showBoxes(kObject13111, true, 8, 10, 9, 11);
			break;

		case 1:
			_app->varSetByte(13003, 1);
			_app->bagAdd(kObjectStChristopherMedallion);
			_app->objectPresentationShow(kObject99600, 5);
			_app->objectPresentationHide(kObject13111);
			_app->objectSetAccessibilityOff(kObject13111, 1, 1);
			_app->soundPlay(13304);
			_app->objectPresentationShow(kObject13111, _app->varGetByte(13004) == 0 ? 5 : 7);
			break;

		case 2:
			_app->varSetByte(13004, 1);
			_app->bagAdd(kObjectRing);
			_app->objectPresentationHide(kObject13111);
			_app->objectSetAccessibilityOff(kObject13111, 2, 2);
			_app->showImage("a01s03n01p07l01.bmp", Common::Point(0, 16), 3000, kLoadFromCd, kArchiveInvalid);
			_app->soundPlay(13305);
			_app->objectPresentationShow(kObject13111, _app->varGetByte(13003) == 0 ? 3 : 7);
			break;
		}
		break;

	case kObject13112:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 0:
			_app->varSetByte(13026, 1);
			_app->soundPlay(13018);
			_app->objectSetAccessibilityOff(kObject13112, 0, 0);
			_app->objectSetAccessibilityOff(kObject13111, 0, 0);
			_app->objectPresentationHide(kObject13112);
			_app->objectPresentationShow(kObject13112, 0);
			break;

		case 1:
			_app->puzzleSetActive(kPuzzle13110);
			_app->soundPlay(13303);
			break;

		case 2:
			_app->varSetByte(13026, 0);
			_app->soundPlay(13019);
			_app->objectSetAccessibilityOff(kObject13112, 0, 0);
			_app->objectSetAccessibilityOff(kObject13112, 1, 1);
			_app->objectPresentationHide(kObject13112);
			_app->objectPresentationShow(kObject13112, 2);
			break;
		}
		break;

	case kObject13113:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0 || target == 2 || target == 4 || target == 6)
			_app->soundPlay(13308);

		if (target == 1 || target == 3 || target == 5 || target == 7) {
			saveView();
			_app->puzzleSetActive(_app->varGetByte(13018) == 1 ? kPuzzle13112 : kPuzzle13113);
		}

		if (target == 8 || target == 9)
			restoreView();
		break;

	case kObject13114:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->soundPlay(13302);
		break;

	case kObject13115:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->soundPlay(13307);
		break;

	case kObject13116:
	case kObject13204:
		buttonUpStill(id, target);
		break;

	case kObjectWoodLog:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->bagAdd(kObjectWoodLog);
		_app->soundPlay(13003 + rnd(3));
		break;

	case kObject13121:
		if (_app->bagHasClickedObject()) {
			if ((target == 0 || target == 3) && _app->bagGetClickedObject() == kObjectRing) {
				setFireplace(_app->varGetByte(13009) == 0);
				_app->cursorDelete();
			} else {
				_app->cursorDelete();
			}
			break;
		}

		if (target == 1) {
			// Same as using the ring, but the sounds are swapped
			bool on = (_app->varGetByte(13009) == 0);
			setFireplace(on, true);
			_app->objectPresentationShow(kObject13121, 4);
			_app->timerStart(kTimer0, 400);
		} else if (target == 2) {
			Id rotationId = (_app->varGetByte(13018) == 1) ? 13411 : 13412;
			_app->rotationSetAlp(rotationId, 0.0f);
			_app->rotationSetBet(rotationId, 26.0f);
			_app->rotationSetRan(rotationId, 87.0f);
			_app->rotationSetActive(rotationId);
		}
		break;

	case kObject13123:
		if (_app->bagHasClickedObject()) {
			if (_app->bagGetClickedObject() == kObjectBottle) {
				_app->soundPlay(13016);
				_app->bagRemove(kObjectBottle);
			}

			if (_app->bagGetClickedObject() == kObjectBottleOfWhiskey) {
				_app->soundPlay(13016);
				_app->bagRemove(kObjectBottleOfWhiskey);
			}

			if (_app->bagGetClickedObject() == kObjectBottleOfMolasse) {
				_app->soundPlay(13016);
				_app->bagRemove(kObjectBottleOfMolasse);
			}

			_app->cursorDelete();
			break;
		}

		_app->soundPlay(13309);
		break;

	case kObject13124:
		buttonUpBarrel(kObject13124, target, "A01S04N02A03");
		break;

	case kObject13201:
		buttonUpBarrel(kObject13201, target, "a01s04n02a03");
		break;

	case kObjectBucket:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->bagAdd(kObjectBucket);
		_app->objectPresentationShow(kObjectBucket, 0);
		_app->objectPresentationShow(kObjectBucket, 1);
		_app->objectSetAccessibilityOff(kObjectBucket, 0, 1);
		_app->soundPlay(13063);
		break;

	case kObject13127:
		if (_app->bagHasClickedObject()) {
			if (target == 0) {
				if (_app->bagGetClickedObject() == kObjectWoodLog) {
					_app->objectPresentationShow(kObject13127, _app->varGetByte(13011) == 0 ? 0 : 2);
					_app->soundPlay(13068);
					_app->varSetByte(13012, 1);
					_app->bagRemove(kObjectWoodLog);
				}

				if (_app->bagGetClickedObject() == kObjectOldNew) {
					_app->objectPresentationShow(kObject13127, _app->varGetByte(13012) == 0 ? 1 : 2);
					_app->soundPlay(13067);
					_app->varSetByte(13011, 1);
					_app->bagRemove(kObjectOldNew);
				}
			}

			_app->cursorDelete();
			break;
		}

		if (target == 1) {
			ObjectId objectId = (_app->varGetByte(13018) == 1) ? kObject13124 : kObject13201;
			Id rotationId = (_app->varGetByte(13018) == 1) ? 13421 : 13422;

			_app->objectPresentationHide(objectId, 5);
			_app->objectPresentationShow(objectId, 4);
			_app->objectSetAccessibilityOff(objectId, 3, 3);
			_app->rotationSetAlp(rotationId, 0.0f);
			_app->rotationSetBet(rotationId, 26.0f);
			_app->rotationSetRan(rotationId, 87.0f);
			_app->rotationSetActive(rotationId);
		}
		break;

	case kObjectOldNew:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->bagAdd(kObjectOldNew);
		_app->soundPlay(13006 + rnd(3));
		break;

	case kObject13130:
		if (_app->bagHasClickedObject()) {
			if (_app->bagGetClickedObject() == kObjectTap && (target == 0 || target == 1)) {
				if (target == 0) {
					_app->objectPresentationShow(kObject13130, 1);
					_app->objectSetAccessibilityOff(kObject13130, 0, 0);
					_app->objectSetAccessibilityOff(kObject13130, 3, 3);
				} else {
					_app->objectPresentationShow(kObject13130, 5);
					_app->objectSetAccessibilityOff(kObject13130, 1, 1);
					_app->objectSetAccessibilityOff(kObject13130, 6, 6);
				}

				_app->bagRemove(kObjectTap);
				_app->soundPlay(13044);
				_app->varSetByte(13027, 1);
			}

			fillFromBarrel(target == 2 || target == 4 || target == 5 || target == 7 || target == 8);
			break;
		}

		if (target == 2 || target == 4 || target == 5 || target == 7 || target == 8)
			_app->soundPlay(13012);

		if (target == 3 || target == 6)
			_app->soundPlay(13011);

		switch (target) {
		default:
			break;

		case 0:
			if (_app->varGetByte(13013) != 1)
				break;

			_app->objectPresentationShow(kObject13130, 0);
			_app->bagAdd(kObjectTap);
			_app->varSetByte(13023, 1);
			_app->varSetByte(13013, 0);
			_app->soundPlay(13043);
			break;

		case 9:
			_app->objectPresentationHide(kObject13130, 3);
			_app->objectPresentationShow(kObject13130, 2);
			_app->objectSetAccessibilityOff(kObject13130, 9, 9);
			_app->soundPlay(13028);
			_app->varSetByte(13027, 0);
			break;

		case 10:
		case 11:
			_app->objectPresentationHide(kObject13130, 7);
			_app->objectPresentationShow(kObject13130, 6);
			_app->objectSetAccessibilityOff(kObject13130, 10, 11);
			_app->objectSetAccessibilityOff(kObject13130, 12, 12);
			_app->soundPlay(13041);
			_app->varSetByte(13027, 0);
			break;

		case 12:
			_app->rotationSetAlp(13511, 280.0f);
			_app->rotationSetBet(13511, 16.0f);
			_app->rotationSetRan(13511, 87.0f);
			_app->rotationSetActive(13511);

			if (_app->varGetByte(13029) == 0) {
				_app->varSetByte(13029, 1);
				_app->playMovie("A01S04_E06M07");
			}

			_app->soundStopType(kSoundTypeBackgroundMusic, 1024);
			_app->timerStart(kTimer4, rnd(5000) + 1000);
			_app->soundPlay(13074, kSoundLoop);
			break;
		}
		break;

	case kObjectBottle:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->bagAdd(kObjectBottle);
		_app->soundPlay(13013 + rnd(3));
		break;

	case kObjectBaseballBat:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->bagAdd(kObjectBaseballBat);
		_app->objectPresentationShow(kObjectBaseballBat, 0);
		_app->soundPlay(13075);
		break;

	case kObject13136:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->soundPlay(13310);
		break;

	case kObject13137:
		if (_app->bagHasClickedObject()) {
			if (_app->bagGetClickedObject() == kObjectBaseballBat && target == 2) {
				// Advances the progress animation frame (0x4dc040), it doesn't save
				if (_app->getSaveManager()->getData()->progressState == kProgressState6)
					_app->getSaveManager()->getData()->progress++;

				_app->soundPlay(13076);
				_app->playMovie("A01S05_E06M09");
				_app->objectPresentationShow(kObject13137, 4);
				_app->objectSetAccessibilityOff(kObject13137, 2, 2);
			}

			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 0:
		case 1:
			_app->objectPresentationShow(kObject13137, target);
			_app->objectSetAccessibilityOff(kObject13137, 0, 1);
			_app->objectSetAccessibilityOff(kObject13137, 3, 3);
			_app->soundPlay(13029);
			break;

		case 2:
			_app->playMovie("A01S05_E06M08");
			break;

		case 3:
			_app->objectPresentationShow(kObject13137, 2);
			_app->objectSetAccessibilityOff(kObject13137, 0, 1);
			_app->objectSetAccessibilityOff(kObject13137, 3, 3);
			_app->soundPlay(13052);
			break;

		case 4:
			_app->rotationSetAlp(13611, 24.0f);
			_app->rotationSetBet(13611, 26.0f);
			_app->rotationSetRan(13611, 87.0f);
			_app->rotationSetActive(13611);
			_app->objectPresentationShow(kObject13137, 3);
			_app->varSetByte(13017, 1);

			if (_app->varGetByte(13016) == 0) {
				_app->rotationSet3DSoundOn(13611, 13017);
				_app->rotationSet3DSoundOn(13531, 13017);
				_app->rotationSet3DSoundOn(13521, 13017);
				_app->rotationSet3DSoundOn(13511, 13017);
				_app->puzzleSet3DSoundOn(kPuzzle13109, 13017);
				_app->objectSetAccessibilityOff(kObject13138, 1, 1);
				_app->objectSetAccessibilityOn(kObject13138, 0, 0);
			}
			break;

		case 5:
			_app->soundPlay(13312);
			break;
		}
		break;

	case kObject13138:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			if (_app->varGetByte(13016) != 0 || _app->varGetByte(13017) != 1)
				break;

			_app->varSetByte(13016, 1);
			_app->rotationSetMovabilityOn(13511, 2, 2);
			_app->rotationSetMovabilityOff(13511, 1, 1);
			_app->rotationSet3DSoundOff(13611, 13017);
			_app->rotationSet3DSoundOff(13531, 13017);
			_app->rotationSet3DSoundOff(13521, 13017);
			_app->rotationSet3DSoundOff(13511, 13017);
			_app->puzzleSet3DSoundOff(kPuzzle13109, 13017);
			_app->soundPlay(13315);
		} else if (target == 1) {
			_app->soundPlay(13065);
		}
		break;

	case kObject13139:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (_app->varGetByte(13018) == 1) {
			_app->rotationSetAlp(13311, 186.0f);
			_app->rotationSetBet(13311, 26.0f);
			_app->rotationSetRan(13311, 87.0f);
			_app->rotationSetActive(13311);
		} else {
			_app->rotationSetAlp(13312, 186.0f);
			_app->rotationSetBet(13312, 26.0f);
			_app->rotationSetRan(13312, 87.0f);
			_app->rotationSetActive(13312);
		}
		break;

	case kObject13202:
		if (_app->bagHasClickedObject()) {
			fillFromBarrel(target == 1 || target == 2 || target == 4 || target == 5 || target == 6);
			break;
		}

		if (target == 1 || target == 2 || target == 4 || target == 5 || target == 6)
			_app->soundPlay(13012);

		if (target == 0 || target == 3)
			_app->soundPlay(13011);
		break;

	case kObject13205:
		if (!_app->bagHasClickedObject())
			break;

		if (_app->bagGetClickedObject() == kObjectBottleOfWhiskey) {
			// Advances the progress animation frame (0x4dc040), it doesn't save
			if (_app->getSaveManager()->getData()->progressState == kProgressState6)
				_app->getSaveManager()->getData()->progress++;

			_app->soundPlay(13070);
		}

		_app->cursorDelete();
		break;

	case kObject13206:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 0:
			_app->objectSetAccessibilityOff(kObject13206, 0, 0);
			_app->objectSetAccessibilityOff(kObject13207, 0, 0);
			_app->varSetByte(13025, 1);
			_app->soundPlay(13018);
			showBoxes(kObject13206, false, 0, 4, 2, 6);
			break;

		case 3:
			_app->soundPlay(13019);
			_app->objectSetAccessibilityOff(kObject13206);
			_app->varSetByte(13025, 0);
			showBoxes(kObject13206, false, 8, 10, 9, 11);
			break;

		case 1:
			_app->varSetByte(13003, 1);
			_app->bagAdd(kObjectStChristopherMedallion);
			_app->objectPresentationHide(kObject13206);
			_app->objectSetAccessibilityOff(kObject13206, 1, 1);
			_app->soundPlay(13304);
			_app->objectPresentationShow(kObject13206, _app->varGetByte(13004) == 0 ? 5 : 7);
			break;

		case 2:
			_app->varSetByte(13004, 1);
			_app->bagAdd(kObjectRing);
			_app->objectPresentationHide(kObject13206);
			_app->objectSetAccessibilityOff(kObject13206, 2, 2);
			_app->showImage("a01s03n01p07l02.bmp", Common::Point(0, 16), 3000, kLoadFromCd, kArchiveInvalid);
			_app->soundPlay(13305);
			_app->objectPresentationShow(kObject13206, _app->varGetByte(13003) == 0 ? 3 : 7);
			break;
		}
		break;

	case kObject13207:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 0:
			_app->varSetByte(13026, 1);
			_app->soundPlay(13018);
			_app->objectSetAccessibilityOff(kObject13207, 0, 0);
			_app->objectSetAccessibilityOff(kObject13111, 0, 0);
			_app->objectPresentationShow(kObject13207, 0);
			break;

		case 1:
			_app->puzzleSetActive(kPuzzle13111);
			_app->soundPlay(13303);
			break;

		case 2:
			_app->varSetByte(13026, 0);
			_app->soundPlay(13019);
			_app->objectSetAccessibilityOff(kObject13207, 0, 0);
			_app->objectSetAccessibilityOff(kObject13207, 1, 1);
			_app->objectPresentationShow(kObject13207, 2);
			break;
		}
		break;

	case kObject13900:
		if (target == 0) {
			// New hand
			_app->objectSetAccessibilityOff(kObject13901);
			pokerShuffle();
			pokerClearTable();
			pokerDeal();
			pokerSortHand(0);
			pokerSortHand(5);
			_app->objectSetAccessibilityOn(kObject13901);
			pokerEvaluatePlayer();
			pokerEvaluateOpponent(1);
			_app->objectSetAccessibilityOn(kObject13900, 1, 1);
		} else if (target == 1) {
			// Draw new cards for the discarded ones, then compare the hands
			_app->objectSetAccessibilityOn(kObject13903);
			_app->objectSetAccessibilityOff(kObject13900, 1, 1);

			for (int32 slot = 4; slot >= 0; slot--) {
				if (_app->varGetByte(13940 + slot) == 0)
					_app->objectPresentationShow(kObject13900, pokerDealCard(slot) + 32 * slot);

				_app->soundPlay(13078);
				_app->_vm->update();
			}

			for (int32 slot = 4; slot >= 0; slot--) {
				if (_app->varGetByte(13945 + slot) == 0)
					_app->objectPresentationShow(kObject13902, pokerDealCard(slot + 5) + 32 * slot);

				_app->soundPlay(13078);
				_app->_vm->update();
			}

			pokerSortHand(0);
			pokerSortHand(5);
			_app->objectSetAccessibilityOn(kObject13901);
			pokerEvaluatePlayer();
			pokerEvaluateOpponent(0);
			_app->objectSetAccessibilityOff(kObject13903);

			// Category, then high card rank, then its suit. On a complete tie, the previous message is shown again.
			int32 compare = 0;
			for (uint32 i = 0; i < 3 && compare == 0; i++)
				compare = (int8)_app->varGetByte(13975 + i) - (int8)_app->varGetByte(13972 + i);

			if (compare > 0) {
				_app->messageGet("PokerYouLoose");
			} else if (compare < 0) {
				_app->messageGet("PokerYouWin");
				_app->varSetByte(13979, _app->varGetByte(13979) + 1);
			}

			_app->objectPresentationSetTextToPuzzle(kObject13900, 0, 0, _app->getMessage());
			_app->puzzleSetActive(kPuzzle13902);
		}
		break;

	case kObject13901:
		// Discard one of the player's cards
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if ((int8)_app->varGetByte(13940 + target) <= 0)
			break;

		_app->soundPlay(13078);
		_app->objectSetAccessibilityOff(kObject13901, target, target);
		_app->objectPresentationHide(kObject13900, _app->varGetByte(13940 + target) + 32 * target);
		_app->varSetByte(13940 + target, 0);
		_app->varSetByte(13950 + target, 0);
		_app->varSetByte(13960 + target, 0);
		break;

	case kObject13902:
		if (!_app->bagHasClickedObject())
			break;

		if (_app->bagGetClickedObject() == kObjectLotteryTicket2) {
			_app->objectSetAccessibilityOff(kObject13902);
			_app->timerStop(kTimer2);
			_app->soundPlay(13332);
		}

		_app->cursorDelete();
		break;
	}
}

// Words 13001-13003 hold the rotation to go back to (FAUST.EXE 0x4a2d5b)
void Zone4Faust::saveView() {
	Id rotationId = _app->getCurrentRotationId();
	_app->varSetWord(13001, (int16)rotationId);
	_app->varSetWord(13002, (int16)_app->rotationGetAlp(rotationId));
	_app->varSetWord(13003, (int16)_app->rotationGetBet(rotationId));
}

// FAUST.EXE 0x4a2e37
void Zone4Faust::restoreView() {
	Id rotationId = (Id)_app->varGetWord(13001);
	_app->rotationSetAlp(rotationId, (float)_app->varGetWord(13002));
	_app->rotationSetBet(rotationId, (float)_app->varGetWord(13003));
	_app->rotationSetRan(rotationId, 87.0f);
	_app->rotationSetActive(rotationId);
}

// The jewel box: one presentation for each combination of the medallion (13003) and the ring (13004) being taken
void Zone4Faust::showBoxes(ObjectId objectId, bool hideAll, uint32 none, uint32 medallion, uint32 ring, uint32 both) {
	byte medallionTaken = _app->varGetByte(13003);
	byte ringTaken = _app->varGetByte(13004);
	uint32 index;

	if (medallionTaken == 0 && ringTaken == 0)
		index = none;
	else if (medallionTaken == 1 && ringTaken == 0)
		index = medallion;
	else if (medallionTaken == 0 && ringTaken == 1)
		index = ring;
	else if (medallionTaken == 1 && ringTaken == 1)
		index = both;
	else
		return;

	if (hideAll)
		_app->objectPresentationHide(objectId);

	_app->objectPresentationShow(objectId, index);
}

// The fireplace lit by the ring (13121, FAUST.EXE 0x4a3894); the button (target 1) plays the sounds the other way around
void Zone4Faust::setFireplace(bool on, bool button) {
	static const uint32 shown[4] = { 0, 1, 7, 8 };
	static const uint32 hidden[4] = { 2, 3, 5, 6 };

	for (uint32 i = 0; i < 4; i++) {
		if (on) {
			_app->objectPresentationShow(kObject13121, shown[i]);
		} else {
			_app->objectPresentationHide(kObject13121, shown[i]);
		}
	}

	for (uint32 i = 0; i < 4; i++) {
		if (on) {
			_app->objectPresentationHide(kObject13121, hidden[i]);
		} else {
			_app->objectPresentationShow(kObject13121, hidden[i]);
		}
	}

	if (on) {
		_app->objectSetAccessibilityOff(kObjectWoodLog, 0, 0);
		_app->objectSetAccessibilityOn(kObjectWoodLog, 1, 2);
	} else {
		_app->objectSetAccessibilityOn(kObjectWoodLog, 0, 0);
		_app->objectSetAccessibilityOff(kObjectWoodLog, 1, 2);
	}

	_app->soundPlay((on != button) ? 13002 : 13001);
	_app->soundPlay(13066);
	_app->varSetByte(13009, on ? 1 : 0);
}

// The still (13116 in A01S03, 13204 in A01S04): FAUST.EXE 0x4a351f and 0x4a4cf0
void Zone4Faust::buttonUpStill(ObjectId objectId, Id target) {
	if (_app->bagHasClickedObject()) {
		if (target == 2 && _app->bagGetClickedObject() == kObjectBottle && _app->varGetByte(13007) == 1) {
			if (objectId == kObject13204) {
				_app->soundPlay(13069);
				_app->playMovie("A01S03N02P05A02");
			} else {
				_app->playMovie("a01s03n02p01a02");
			}

			_app->bagRemove(kObjectBottle);
			_app->bagAdd(kObjectBottleOfWhiskey);
		}

		_app->cursorDelete();
		return;
	}

	switch (target) {
	default:
		break;

	case 0:
		_app->objectPresentationHide(objectId);
		_app->soundPlay(13056 + rnd(7));

		if (_app->varGetByte(13005) == 0) {
			_app->soundPlay(13071);

			if (_app->varGetByte(13006) != 0) {
				stopStill(objectId);
				break;
			}

			_app->soundStop(13023, 1024);
			_app->objectPresentationShow(objectId, 1);
			_app->varSetByte(13006, 1);
			_app->varSetByte(13007, 0);
		} else {
			if (_app->varGetByte(13007) != 0) {
				stopStill(objectId);
				break;
			}

			_app->soundStop(13023, 1024);
			_app->soundPlay(13023, kSoundLoop);
			_app->objectPresentationShow(objectId, 2);
			_app->varSetByte(13006, 0);
			_app->varSetByte(13007, 1);
		}

		_app->varSetByte(13008, 0);
		_app->objectSetAccessibilityOn(objectId, 2, 2);
		break;

	case 1:
		_app->objectPresentationHide(objectId);
		_app->soundPlay(13056 + rnd(7));

		if (_app->varGetByte(13008) != 0) {
			_app->objectPresentationHide(objectId);
			stopStill(objectId);
			break;
		}

		_app->soundStop(13023, 1024);
		_app->soundPlay(13023, kSoundLoop);
		_app->objectPresentationShow(objectId, 0);
		_app->varSetByte(13008, 1);
		_app->varSetByte(13006, 0);
		_app->varSetByte(13007, 0);
		_app->objectSetAccessibilityOn(objectId, 2, 2);
		break;

	case 2:
		if (_app->varGetByte(13008) == 1)
			_app->soundPlay(13301);

		if (_app->varGetByte(13006) == 1 || _app->varGetByte(13007) == 1)
			_app->playMovie("A01S03_E06M05");
		break;
	}
}

void Zone4Faust::stopStill(ObjectId objectId) {
	_app->soundStop(13023, 1024);
	_app->varSetByte(13006, 0);
	_app->varSetByte(13007, 0);
	_app->varSetByte(13008, 0);
	_app->objectSetAccessibilityOff(objectId, 2, 2);
}

// The barrels (13124 in 13421, 13201 in 13422): FAUST.EXE 0x4a3d1f and 0x4a49b7
void Zone4Faust::buttonUpBarrel(ObjectId objectId, Id target, const char *bucketMovie) {
	if (_app->bagHasClickedObject()) {
		if (target == 4) {
			if (_app->bagGetClickedObject() == kObjectBucketWithMolasse) {
				_app->playMovie(bucketMovie);
				_app->varSetByte(13010, 1);
				_app->bagRemove(kObjectBucketWithMolasse);
				_app->bagAdd(kObjectBucket);

				if (_app->varGetByte(13015) == 1)
					_app->varSetByte(13005, 1);
			}

			if (_app->bagGetClickedObject() == kObjectBottleOfMolasse) {
				_app->playMovie("a01s04n02a05");
				_app->varSetByte(13010, 1);
				_app->bagRemove(kObjectBottleOfMolasse);
				_app->bagAdd(kObjectBottle);

				if (_app->varGetByte(13015) == 1)
					_app->varSetByte(13005, 1);
			}
		}

		_app->cursorDelete();
		return;
	}

	switch (target) {
	default:
		break;

	case 0:
		_app->objectPresentationShow(objectId, 0);
		_app->objectSetAccessibilityOff(objectId, 0, 0);
		_app->varSetByte(13028, 1);
		_app->soundPlay(_app->varGetByte(13010) ? 13048 : 13040);
		break;

	case 1:
		_app->objectPresentationShow(objectId, 3);
		_app->objectSetAccessibilityOff(objectId, 1, 1);
		_app->soundPlay(13038);
		break;

	case 2:
		_app->objectPresentationHide(objectId, 2);
		_app->objectPresentationShow(objectId, 1);
		_app->objectSetAccessibilityOff(objectId, 2, 2);
		_app->objectSetAccessibilityOff(objectId, 4, 4);
		_app->varSetByte(13028, 0);
		_app->soundPlay(_app->varGetByte(13010) ? 13047 : 13039);
		break;
	}
}

// Filling the bucket or a bottle at the barrel taps (13130/13202, FAUST.EXE 0x4a4310 and 0x4a4c4a), then dropping the item
void Zone4Faust::fillFromBarrel(bool atTap) {
	if (_app->bagGetClickedObject() == kObjectBucket && atTap) {
		_app->playMovie("a01s04n02a01");
		_app->bagRemove(kObjectBucket);
		_app->bagAdd(kObjectBucketWithMolasse);
	}

	if (_app->bagGetClickedObject() == kObjectBottle && atTap) {
		_app->playMovie("a01s04n02a04");
		_app->bagRemove(kObjectBottle);
		_app->bagAdd(kObjectBottleOfMolasse);
	}

	_app->cursorDelete();
}

// FAUST.EXE 0x4a66f0
void Zone4Faust::onAnimationNextFrame(Id animationId, const Common::String &name, uint32 frame, uint32 frameCount) {
	switch (animationId) {
	default:
		break;

	case 13001:
		if (frame != 10)
			break;

		_app->objectPresentationHide(kObject13107);
		_app->objectPresentationShow(kObject13107, 0);
		_app->objectSetAccessibilityOff(kObject13107, 0, 0);
		_app->varSetByte(13001, 1);
		break;

	case 13003:
		if (frame != 15)
			break;

		_app->objectPresentationHide(kObject13109);
		_app->objectPresentationShow(kObject13108, 1);
		_app->objectPresentationShow(kObject13108, 4);
		_app->objectSetAccessibilityOn(kObject13110, 0, 1);
		_app->objectSetAccessibilityOn(kObject13113, 4, 7);
		break;

	case 13004: {
		if (frame != 10)
			break;

		_app->objectPresentationHide(kObject13111);
		_app->objectPresentationHide(kObject13206);

		// The same state is shown on both objects
		static const ObjectId objects[2] = { kObject13111, kObject13206 };
		byte left = _app->varGetByte(13003);
		byte right = _app->varGetByte(13004);

		for (uint32 i = 0; i < 2; i++) {
			if (left == 0 && right == 0) {
				_app->objectPresentationShow(objects[i], 1);
				_app->objectSetAccessibilityOn(objects[i], 1, 1);
				_app->objectSetAccessibilityOn(objects[i], 2, 2);
				_app->objectSetAccessibilityOn(objects[i], 3, 3);
			}
		}

		for (uint32 i = 0; i < 2; i++) {
			if (_app->varGetByte(13003) == 1 && _app->varGetByte(13004) == 0) {
				_app->objectPresentationShow(objects[i], 5);
				_app->objectSetAccessibilityOn(objects[i], 2, 2);
				_app->objectSetAccessibilityOn(objects[i], 3, 3);
			}
		}

		for (uint32 i = 0; i < 2; i++) {
			if (_app->varGetByte(13003) == 0 && _app->varGetByte(13004) == 1) {
				_app->objectPresentationShow(objects[i], 3);
				_app->objectSetAccessibilityOn(objects[i], 1, 1);
				_app->objectSetAccessibilityOn(objects[i], 3, 3);
			}
		}

		for (uint32 i = 0; i < 2; i++) {
			if (_app->varGetByte(13003) == 1 && _app->varGetByte(13004) == 1) {
				_app->objectPresentationShow(objects[i], 7);
				_app->objectSetAccessibilityOn(objects[i], 3, 3);
			}
		}
		}
		break;

	case 13005:
		if (frame != 1)
			break;

		_app->soundPlay(13020);
		_app->objectSetAccessibilityOn(kObject13111, 0, 0);
		_app->objectSetAccessibilityOn(kObject13112, 0, 0);
		_app->objectSetAccessibilityOn(kObject13206, 0, 0);
		_app->objectSetAccessibilityOn(kObject13207, 0, 0);
		break;

	case 13006:
		if (frame != 10)
			break;

		_app->objectPresentationHide(kObject13112);
		_app->objectPresentationShow(kObject13112, 1);
		_app->objectSetAccessibilityOn(kObject13112, 1, 1);
		_app->objectSetAccessibilityOn(kObject13112, 2, 2);
		_app->objectPresentationHide(kObject13207);
		_app->objectPresentationShow(kObject13207, 1);
		_app->objectSetAccessibilityOn(kObject13207, 1, 1);
		_app->objectSetAccessibilityOn(kObject13207, 2, 2);
		break;

	case 13007:
		if (frame != 1)
			break;

		_app->soundPlay(13020);
		_app->objectPresentationHide(kObject13112);
		_app->objectSetAccessibilityOn(kObject13112, 0, 0);
		_app->objectSetAccessibilityOn(kObject13111, 0, 0);
		_app->objectPresentationHide(kObject13207);
		_app->objectSetAccessibilityOn(kObject13207, 0, 0);
		_app->objectSetAccessibilityOn(kObject13206, 0, 0);
		break;

	case 13008:
		if (frame != 15)
			break;

		_app->objectPresentationHide(kObject13124, 0);
		_app->objectPresentationShow(kObject13124, 2);
		_app->objectSetAccessibilityOn(kObject13124, 2, 2);
		_app->objectSetAccessibilityOn(kObject13124, 4, 4);
		_app->objectPresentationHide(kObject13201, 0);
		_app->objectPresentationShow(kObject13201, 2);
		_app->objectSetAccessibilityOn(kObject13201, 2, 2);
		_app->objectSetAccessibilityOn(kObject13201, 4, 4);
		_app->soundPlay(_app->varGetByte(13010) ? 13049 : 13045);
		break;

	case 13009:
		if (frame != 1)
			break;

		_app->objectPresentationHide(kObject13124, 0);
		_app->objectSetAccessibilityOn(kObject13124, 0, 0);
		_app->objectPresentationHide(kObject13201, 0);
		_app->objectSetAccessibilityOn(kObject13201, 0, 0);
		_app->soundPlay(_app->varGetByte(13010) ? 13050 : 13046);
		break;

	case 13010:
		if (frame != 15)
			break;

		_app->objectPresentationHide(_app->varGetByte(13018) == 1 ? kObject13124 : kObject13201, 3);
		_app->puzzleSetActive(kPuzzle13108);
		break;

	case 13011:
		if (frame == 1) {
			_app->objectPresentationHide(kObject13124, 4);
			_app->objectSetAccessibilityOn(kObject13124, 1, 1);
			_app->objectPresentationHide(kObject13201, 4);
			_app->objectSetAccessibilityOn(kObject13201, 1, 1);
			_app->soundPlay(13036);
		} else if (frame == 15) {
			_app->soundPlay(13037);
		}
		break;

	case 13012:
		if (frame == 5) {
			_app->soundPlay(13027);
		} else if (frame == 15) {
			_app->objectPresentationHide(kObject13130, 0);
			_app->objectPresentationHide(kObject13130, 1);
			_app->objectPresentationShow(kObject13130, 3);
			_app->objectSetAccessibilityOn(kObject13130, 9, 9);
		}
		break;

	case 13013:
		if (frame == 1) {
			_app->objectPresentationHide(kObject13130, 0);
			_app->objectPresentationHide(kObject13130, 1);
			_app->objectPresentationHide(kObject13130, 2);
			_app->objectPresentationHide(kObject13130, 3);
			_app->objectSetAccessibilityOn(kObject13130, 0, 0);
			_app->objectSetAccessibilityOn(kObject13130, 3, 3);
			_app->objectPresentationShow(kObject13130, 0);
			_app->bagAdd(13134);
		} else if (frame == 5) {
			_app->soundPlay(13051);
		}
		break;

	case 13014:
		if (frame == 5) {
			_app->soundPlay(13042);
		} else if (frame == 15) {
			_app->objectPresentationHide(kObject13130, 4);
			_app->objectPresentationHide(kObject13130, 5);
			_app->objectPresentationShow(kObject13130, 7);
			_app->objectSetAccessibilityOn(kObject13130, 10, 11);
			_app->objectSetAccessibilityOn(kObject13130, 12, 12);
		}
		break;

	case 13015:
		if (frame == 1) {
			_app->objectPresentationHide(kObject13130, 4);
			_app->objectPresentationHide(kObject13130, 5);
			_app->objectPresentationHide(kObject13130, 6);
			_app->objectPresentationHide(kObject13130, 7);
			_app->objectSetAccessibilityOn(kObject13130, 1, 1);
			_app->objectSetAccessibilityOn(kObject13130, 6, 6);
			_app->objectPresentationShow(kObject13130, 4);
			_app->bagAdd(13134);
		} else if (frame == 5) {
			_app->soundPlay(13051);
		}
		break;

	case 13016:
	case 13017:
		if (frame == 11) {
			_app->soundStop(13029, 1024);
			_app->soundSetVolume(13029, 95);
			_app->soundPlay(13029);
		} else if (frame == 17) {
			_app->soundStop(13029, 1024);
			_app->soundSetVolume(13029, 92);
			_app->soundPlay(13029);
			_app->soundPlay(13032);
		} else if (frame == 30) {
			_app->soundStop(13029, 1024);
			_app->soundSetVolume(13029, 100);
			_app->objectPresentationHide(kObject13137, animationId == 13016 ? 0 : 1);
			_app->objectSetAccessibilityOn(kObject13137, 0, 1);
			_app->objectSetAccessibilityOn(kObject13137, 3, 3);
		}
		break;

	case 13018:
		if (frame != 10)
			break;

		_app->objectPresentationHide(kObject13137, 2);
		_app->puzzleSetActive(kPuzzle13109);
		break;

	case 13019:
		if (frame != 1)
			break;

		_app->objectPresentationHide(kObject13137, 2);
		_app->objectPresentationHide(kObject13137, 3);
		_app->objectSetAccessibilityOn(kObject13137, 3, 3);
		_app->objectSetAccessibilityOn(kObject13137, 0, 1);
		_app->soundPlay(13053);
		break;

	case 13024:
	case 13025:
		if (frame != 3)
			break;

		_app->soundPlay(13021);
		_app->varSetByte(13024, _app->varGetByte(13024) + 1);

		if (_app->varGetByte(13024) == 15) {
			_app->varSetByte(13024, 0);
			_app->objectPresentationHide(kObject13116, 1);
			_app->objectPresentationHide(kObject13204, 1);
			_app->varSetByte(13006, 0);
			_app->objectSetAccessibilityOff(kObject13116, 2, 2);
		}
		break;
	}
}

// FAUST.EXE 0x4a7410
void Zone4Faust::onSound(Id id, SoundType type, uint32 a3, bool process) {
	if (!process)
		return;

	switch (id) {
	default:
		break;

	case 13009:
		_app->objectPresentationHide(kObject13127);
		break;

	case 13070:
		_app->timerStop(kTimer1);
		setupPoker(2);
		break;

	case 13312:
		_app->soundPlay(13313);
		break;

	case 13313:
		_app->soundPlay(13314);
		break;

	case 13315:
		_app->soundPlay(13316);
		break;

	case 13316:
		_app->soundPlay(13317);
		break;

	case 13317:
		_app->soundPlay(13318);
		break;

	case 13318:
		_app->soundPlay(13319);
		break;

	case 13320:
		_app->soundPlay(13321);
		break;

	case 13321:
		_app->timerStart(kTimer1, 20000);
		break;

	case 13327:
		setupPoker(3);
		break;

	case 13328:
		_app->soundPlay(13329);
		break;

	case 13329:
		_app->soundPlay(13330);
		break;

	case 13330:
		// The first hand has been dealt
		_app->objectSetAccessibilityOn(kObject13903);
		pokerSortHand(0);
		pokerSortHand(5);
		_app->objectSetAccessibilityOn(kObject13901);
		pokerEvaluatePlayer();
		pokerEvaluateOpponent(1);
		_app->objectSetAccessibilityOff(kObject13903);
		_app->objectSetAccessibilityOn(kObject13900, 1, 1);
		break;

	case 13331:
		_app->timerStart(kTimer2, 10000);
		break;

	case 13332:
		_app->soundPlay(13333);
		break;

	case 13333:
		_app->puzzleSetActive(kPuzzle13901);
		pokerNewHand();
		break;

	case 13334:
		// The end of episode 6
		_app->fadeOut(15, Color(0, 0, 0), 0);
		_app->playMovie("a05s02_e06m12");
		_app->playMovie("a05s02_e06m13");
		_app->playMovie("a05s02_e06m14");
		_app->fadeOut(15, Color(0, 0, 0), 0);
		_app->varSetByte(98089, 0);

		// Sets the progress animation frame (0x4dc040), it doesn't save
		if (_app->getSaveManager()->getData()->progressState == kProgressState6)
			_app->getSaveManager()->getData()->progress = 0x2e;

		_app->exitToMenu(kMenuAction0);
		break;

	case 13338:
		_app->objectPresentationHide(kObject15);
		_app->objectSetAccessibilityOff(kObject1);

		if (_app->varGetByte(13019) == 6) {
			_app->rotationSetActive(13312);
			_app->soundPlay(13322);
			_app->varSetByte(13019, 1);
			_app->timerStart(kTimer1, 20000);
		} else {
			_app->varSetByte(13978, 0);
			_app->varSetByte(13979, 0);
			setupPoker(2);
		}
		break;
	}
}

// FAUST.EXE 0x4a58e0: the five dials (float vars 13001-13005, presentations 0-39 of objects 13102-13106)
void Zone4Faust::onBag(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, DragControl *dragControl, byte type) {
	if (id != kObject13102)
		return;

	switch (type) {
	default:
		break;

	case 1:
		_app->dragControlSetField45(2);
		break;

	case 2:
		if (floor(_app->varGetFloat(13001)) != 36.0
		 || floor(_app->varGetFloat(13002)) != 36.0
		 || floor(_app->varGetFloat(13003)) != 36.0
		 || floor(_app->varGetFloat(13004)) != 28.0
		 || floor(_app->varGetFloat(13005)) != 4.0)
			break;

		_app->soundPlay(13003);
		_app->soundPlay(13004);
		_app->soundPlay(13005);
		_app->playMovie("a01s03a01");
		_app->soundStop(13054, 1024);
		_app->soundPlay(13055, kSoundLoop);
		_app->playMovie("a01s04a01");
		_app->varSetByte(13002, 1);
		_app->rotationSetAlp(13421, 270.0f);
		_app->rotationSetBet(13421, 26.0f);
		_app->rotationSetRan(13421, 87.0f);
		_app->rotationSetActive(13421);
		break;

	case 3: {
		if (_app->dragControlYEqual())
			break;

		Id varId = 13001 + target;

		if (_app->dragControlYHigher())
			_app->varSetFloat(varId, (float)(_app->varGetFloat(varId) - (double)_app->dragControlGetOffsetY() * 0.06666666666666667));

		if (_app->dragControlYLower())
			_app->varSetFloat(varId, (float)(_app->varGetFloat(varId) + (double)_app->dragControlGetOffsetY() * 0.06666666666666667));

		// Kept as in the original: going below 0 sets 40, which the second check turns into 0
		if (_app->varGetFloat(varId) < 0.0f)
			_app->varSetFloat(varId, 40.0f);

		if (_app->varGetFloat(varId) > 39.0f)
			_app->varSetFloat(varId, 0.0f);

		ObjectId objectId = (ObjectId)(kObject13102 + target);
		_app->objectPresentationHide(objectId);
		_app->objectPresentationShow(objectId, (uint32)_app->varGetFloat(varId));

		_app->varSetByte(13021, (byte)floor(_app->varGetFloat(varId)));
		if (_app->varGetByte(13021) != _app->varGetByte(13022)) {
			_app->soundSetVolume(13026, _app->dragControlGetOffsetY() / 2 + 70);
			_app->soundPlay(13026);
			_app->varSetByte(13022, (byte)floor(_app->varGetFloat(varId)));
		}
		}
		break;
	}
}

void Zone4Faust::onUpdateBag(const Common::Point &point) {
	_app->soundStop(_app->varGetDword(13001), 1024);
	_app->varSetDword(13001, 0);
}

void Zone4Faust::onBagClickedObject(ObjectId id) {
	if (id == kObjectMatches)
		_app->soundPlay(13033);
}

// FAUST.EXE 0x4a7170: the first two arguments are the object and accessibility index under the cursor
void Zone4Faust::onUpdateBefore(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, const Common::Point &point) {
	switch (movabilityFrom) {
	default:
		break;

	case 13114:
		if (_app->soundIsPlayingType(kSoundTypeDialog) || (movabilityTo != 0 && movabilityTo != 1))
			break;

		_app->varSetDword(13001, 13311);
		_app->soundPlay(_app->varGetDword(13001));
		break;

	case 13115:
		if (_app->soundIsPlayingType(kSoundTypeDialog) || movabilityTo != 0)
			break;

		_app->varSetDword(13001, 13306);
		_app->soundPlay(_app->varGetDword(13001));
		break;

	case 13127:
		// Lighting the candles with the matches
		if (movabilityTo != 0 || _app->bagGetClickedObject() != kObjectMatches)
			break;

		if (_app->varGetByte(13011) == 1 && _app->varGetByte(13012) == 0) {
			_app->soundPlay(13009);
			_app->objectPresentationHide(kObject13127);
			_app->objectPresentationShow(kObject13127, 3);
			_app->varSetByte(13011, 0);
		}

		if (_app->varGetByte(13011) == 1 && _app->varGetByte(13012) == 1) {
			_app->rotationSet3DSoundOn(13421, 13010);
			_app->rotationSet3DSoundOn(13411, 13010);
			_app->rotationSet3DSoundOn(13422, 13010);
			_app->rotationSet3DSoundOn(13412, 13010);
			_app->puzzleSet3DSoundOn(kPuzzle13107, 13010);
			_app->puzzleSet3DSoundOn(kPuzzle13108, 13010);
			_app->objectPresentationHide(kObject13127);
			_app->objectPresentationShow(kObject13127, 4);
			_app->varSetByte(13011, 0);
			_app->varSetByte(13012, 0);
			_app->objectSetAccessibilityOff(kObject13127, 0, 0);
			_app->varSetByte(13015, 1);

			if (_app->varGetByte(13010) == 1)
				_app->varSetByte(13005, 1);
		}
		break;

	case 13801:
		if (_app->soundIsPlayingType(kSoundTypeDialog))
			break;

		if (movabilityTo == 0 || movabilityTo == 1) {
			_app->varSetDword(13001, 13337);
			_app->soundPlay(_app->varGetDword(13001));
		}

		if (movabilityTo == 2 || movabilityTo == 3) {
			_app->varSetDword(13001, 13336);
			_app->soundPlay(_app->varGetDword(13001));
		}
		break;
	}
}

void Zone4Faust::onBeforeRide(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, MovabilityType movabilityType) {
	switch (movabilityType) {
	default:
		break;

	case kMovabilityRotationToRotation:
		if (movabilityTo == 13611) {
			if (movabilityFrom == 13531)
				_app->timerStop(kTimer4);
		} else if (movabilityTo == 13531) {
			if (movabilityFrom == 13611)
				_app->timerStart(kTimer4, rnd(4000));
		}
		break;

	case kMovabilityPuzzleToPuzzle:
		if (movabilityFrom == kPuzzle13902)
			pokerClearTable();
		break;
	}
}

// FAUST.EXE 0x4a5d50
// The first argument is the new rotation (or puzzle) and the second the one we came from
void Zone4Faust::onAfterRide(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, MovabilityType movabilityType) {
	Id current = movabilityFrom;
	Id previous = movabilityTo;

	switch (movabilityType) {
	default:
		break;

	case kMovabilityRotationToRotation:
		switch (current) {
		default:
			break;

		case 13321:
			if (previous == 13311) {
				_app->objectSetAccessibilityOff(kObject13111);
				_app->objectPresentationHide(kObject13111);
				_app->objectSetAccessibilityOn(kObject13111, 0, 0);
				_app->objectSetAccessibilityOff(kObject13112);
				_app->objectPresentationHide(kObject13112);
				_app->objectSetAccessibilityOn(kObject13112, 0, 0);

				if (_app->varGetByte(13025) == 1 || _app->varGetByte(13026) == 1) {
					_app->varSetByte(13025, 0);
					_app->varSetByte(13026, 0);
					_app->soundPlay(13020);
				}
			} else if (previous == 13421) {
				_app->soundStopType(kSoundTypeBackgroundMusic, 1024);
				_app->soundPlay(13054, kSoundLoop);
			}
			break;

		case 13322:
			if (previous != 13422)
				break;

			if (_app->varGetByte(13020) == 0) {
				_app->soundPlay(13320);
				_app->varSetByte(13020, 1);
			}

			for (Id soundId = 13322; soundId <= 13327; soundId++)
				_app->soundSetVolume(soundId, 100);

			_app->soundStopType(kSoundTypeBackgroundMusic, 1024);
			_app->soundPlay(13054, kSoundLoop);
			break;

		case 13422:
			if (previous == 13322) {
				for (Id soundId = 13322; soundId <= 13327; soundId++)
					_app->soundSetVolume(soundId, 80);

				_app->soundStopType(kSoundTypeBackgroundMusic, 1024);
				_app->soundPlay(13055, kSoundLoop);
			} else if (previous == 13511) {
				_app->soundStopType(kSoundTypeBackgroundMusic, 1024);
				_app->soundPlay(13055, kSoundLoop);
				_app->timerStop(kTimer4);

				if (_app->varGetByte(13016) == 1) {
					_app->varSetByte(13018, 2);
					_app->playMovie("A01S04_E06M10");
				}
			}
			break;

		case 13411:
		case 13412:
			if (current == 13411) {
				if (previous != 13421)
					break;

				_app->objectSetAccessibilityOn(kObject13130, 0, 8);
				_app->objectSetAccessibilityOff(kObject13130, 9, 12);
				_app->objectPresentationHide(kObject13130);
				_app->objectPresentationShow(kObject13130, 4);

				if (_app->varGetByte(13023) == 1) {
					_app->objectPresentationShow(kObject13130, 0);
					_app->bagAdd(13134);
				}

				_app->objectSetAccessibilityOn(kObject13124, 0, 1);
				_app->objectSetAccessibilityOff(kObject13124, 2, 4);
				_app->objectPresentationHide(kObject13124);
			} else {
				if (previous != 13422)
					break;

				_app->objectSetAccessibilityOn(kObject13201, 0, 1);
				_app->objectSetAccessibilityOff(kObject13201, 2, 4);
				_app->objectPresentationHide(kObject13201);
			}

			if (_app->varGetByte(13027) == 1) {
				_app->soundPlay(13064);
				_app->varSetByte(13027, 0);
			}

			if (_app->varGetByte(13028) == 1) {
				_app->soundPlay(13050);
				_app->varSetByte(13028, 0);
			}
			break;

		case 13421:
			if (previous != 13511)
				break;

			_app->soundStopType(kSoundTypeBackgroundMusic, 1024);
			_app->soundPlay(13055, kSoundLoop);
			_app->timerStop(kTimer4);
			break;
		}
		break;

	case kMovabilityPuzzleToRotation: {
		ObjectId objectId;
		if (current == 13321 && previous == 13105)
			objectId = kObject13116;
		else if (current == 13322 && previous == 13202)
			objectId = kObject13204;
		else if ((current == 13421 || current == 13422) && previous == 13108) {
			objectId = (current == 13421) ? kObject13124 : kObject13201;
			_app->objectPresentationHide(objectId, 5);
			_app->objectPresentationShow(objectId, 4);
			_app->objectSetAccessibilityOff(objectId, 3, 3);
			break;
		} else
			break;

		_app->objectPresentationHide(objectId);

		if (_app->varGetByte(13006) == 1 || _app->varGetByte(13007) == 1 || _app->varGetByte(13008) == 1) {
			_app->soundPlay(13056 + rnd(7));
			_app->varSetByte(13006, 0);
			_app->varSetByte(13007, 0);
			_app->varSetByte(13008, 0);
		}

		_app->objectSetAccessibilityOff(objectId, 2, 2);
		_app->soundStop(13023, 1024);
		}
		break;

	case kMovabilityPuzzleToPuzzle:
		if (current != kPuzzle13901)
			break;

		// The end of a poker hand
		_app->varSetByte(13978, _app->varGetByte(13978) + 1);

		if (_app->varGetByte(13978) == 3) {
			if (_app->varGetByte(98015) > 0) {
				_app->varSetByte(98015, 0);
				_app->setCurrentZone(kZoneSY);
				_app->soundPlay(90001, kSoundLoop);
				_app->puzzleSetActive(kPuzzleGeneralMenu);
				break;
			}

			_app->puzzleSetActive(kPuzzle13204);

			if (_app->varGetByte(13979) > 1) {
				_app->soundPlay(13334);
			} else {
				_app->soundPlay(13331);
				_app->objectSetAccessibilityOn(kObject13902);
			}

			_app->varSetByte(13979, 0);
		} else if (_app->varGetByte(13978) == 6) {
			if (_app->varGetByte(13979) > 1) {
				_app->puzzleSetActive(kPuzzle13204);
				_app->soundPlay(13334);
			} else {
				_app->playMovie("A01S03_E06M11");
				_app->fadeOut(15, Color(0, 0, 0), 0);
				_app->objectSetAccessibilityOn(kObject1);
				_app->objectPresentationShow(kObject15);
				_app->soundPlay(13338);
			}
		} else {
			pokerNewHand();
		}
		break;
	}
}

// FAUST.EXE 0x4a7790 (episode 6)
void Zone4Faust::setupPoker(uint32 type) {
	switch (type) {
	default:
		break;

	case 1:
		_app->exitToMenu(kMenuAction1);
		break;

	case 2:
		_app->setSpace(kZone4);

		// Advances the progress animation frame (0x4dc040), it doesn't save
		if (_app->getSaveManager()->getData()->progressState == kProgressState6)
			_app->getSaveManager()->getData()->progress++;

		_app->varSetByte(98089, 1);
		_app->puzzleSetActive(kPuzzle13901);
		_app->varSetByte(13979, 0);
		_app->varSetByte(13978, 0);
		_app->objectSetAccessibilityOn(kObject13903);
		_app->soundPlay(13328);
		_app->objectSetAccessibilityOff(kObject13901);
		pokerShuffle();
		pokerClearTable();
		pokerDeal();
		break;

	case 3:
		_app->playMovie("A01S03_E06M11");
		_app->fadeOut(15, Color(0, 0, 0), 0);
		_app->objectSetAccessibilityOn(kObject1);
		_app->objectPresentationShow(kObject15);
		_app->soundPlay(13338);
		break;
	}
}

// Deal a new hand: FAUST.EXE 0x4a5eea (onAfterRide) and 0x4a75ad (onSound)
void Zone4Faust::pokerNewHand() {
	_app->objectSetAccessibilityOff(kObject13901);
	pokerShuffle();
	pokerDeal();
	pokerSortHand(0);
	pokerSortHand(5);
	_app->objectSetAccessibilityOn(kObject13901);
	pokerEvaluatePlayer();
	pokerEvaluateOpponent(1);
	_app->objectSetAccessibilityOn(kObject13900, 1, 1);
}

// Discard one of the opponent's cards (slot 0-4)
void Zone4Faust::pokerDiscard(uint32 slot) {
	_app->objectPresentationHide(kObject13902, _app->varGetByte(13945 + slot) + 32 * slot);
	_app->_vm->update();
	_app->varSetByte(13945 + slot, 0);
	_app->varSetByte(13955 + slot, 0);
	_app->varSetByte(13965 + slot, 0);
}

// FAUST.EXE 0x4a1980: rate the opponent's hand (slots 5-9) into 13975-13977, then pick the cards it discards.
// Kept as in the original: the suit checks skip the last card, and the royal flush and flush/straight high card
// read the player's first card (13950/13960).
void Zone4Faust::pokerEvaluateOpponent(int32 discard) {
	_app->objectSetAccessibilityOn(kObject13903);
	_app->varSetByte(13975, 0);
	_app->varSetByte(13976, 0);
	_app->varSetByte(13977, 0);

	// Royal flush, straight flush, four of a kind, full house, flush, straight, three of a kind, two pairs, pair
	int32 categories[9] = { 9, 8, 0, 0, 5, 4, 0, 0, 0 };
	int32 suitCount[5] = { 0, 0, 0, 0, 0 };
	bool suitMark[5][5];
	bool sequenceMark[5] = { false, false, false, false, false };
	bool pairMark[5] = { false, false, false, false, false };
	int32 sequence = 0;

	memset(&suitMark, 0, sizeof(suitMark));

	for (uint32 i = 0; i < 4; i++) {
		if (_app->varGetByte(13966 + i) != _app->varGetByte(13965 + i)) {
			categories[4] = 0;
			categories[0] = 0;
			categories[1] = 0;
		}

		byte suit = _app->varGetByte(13965 + i);
		if (suit < 5) {
			suitMark[i][suit] = true;
			suitCount[suit]++;
		}
	}

	for (uint32 i = 0; i < 4; i++) {
		if (_app->varGetByte(13955 + i) != _app->varGetByte(13956 + i) + 1) {
			categories[5] = 0;
			categories[0] = 0;
			categories[1] = 0;
			--sequence;
		} else {
			sequenceMark[i] = true;
			sequenceMark[i + 1] = true;
			++sequence;
		}
	}

	if (categories[4] && categories[5] && _app->varGetByte(13950) != 14)
		categories[0] = 0;

	if (categories[4] > 0 || categories[5] > 0) {
		if ((int8)_app->varGetByte(13976) < (int8)_app->varGetByte(13950))
			_app->varSetByte(13976, _app->varGetByte(13950));

		if ((int8)_app->varGetByte(13977) < (int8)_app->varGetByte(13960))
			_app->varSetByte(13977, _app->varGetByte(13960));
	}

	int32 counts[5] = { 0, 0, 0, 0, 0 };
	uint32 group = 0;
	for (uint32 i = 0; i < 4; i++) {
		if (_app->varGetByte(13955 + i) == _app->varGetByte(13956 + i)) {
			counts[group]++;
			pairMark[i] = true;
			pairMark[i + 1] = true;

			if ((int8)_app->varGetByte(13976) < (int8)_app->varGetByte(13955 + i)) {
				_app->varSetByte(13976, _app->varGetByte(13955 + i));
				_app->varSetByte(13977, _app->varGetByte(13965 + i));
			}
		} else {
			group++;
		}
	}

	for (uint32 i = 0; i < 5; i++) {
		if (counts[i] == 3)
			categories[2] = 7;

		if (counts[i] == 2)
			categories[6] = 3;
		else if (counts[i] == 1) {
			if (categories[8] == 0)
				categories[8] = 1;
			else
				categories[7] = 2;
		}
	}

	if (categories[8] > 0 && categories[6] > 0)
		categories[3] = 6;

	if (_app->varGetByte(13976) == 0) {
		_app->varSetByte(13976, _app->varGetByte(13955));
		_app->varSetByte(13977, _app->varGetByte(13965));
	}

	int32 category = -1;
	for (uint32 i = 0; i < 9; i++) {
		if (categories[i] > 0) {
			_app->varSetByte(13975, (byte)categories[i]);
			category = (int32)i;
			break;
		}
	}

	if (discard > 0) {
		if (category > -1) {
			// Pairs, two pairs and three of a kind: change the other cards
			if (category == 6 || category == 7 || category == 8) {
				for (uint32 i = 0; i < 5; i++)
					if (!pairMark[i])
						pokerDiscard(i);
			}
		} else {
			bool found = false;

			// Four cards of the same suit: try for the flush
			for (uint32 suit = 1; suit < 5; suit++) {
				if (suitCount[suit] > 3) {
					for (uint32 i = 0; i < 5; i++) {
						if (!suitMark[i][suit]) {
							found = true;
							pokerDiscard(i);
						}
					}
				}
			}

			if (sequence > 1) {
				if (!found) {
					for (uint32 i = 0; i < 5; i++) {
						if (!sequenceMark[i]) {
							found = true;
							pokerDiscard(i);
						}
					}

					if (!found)
						pokerDiscard(4);
				}
			} else if (!found) {
				for (uint32 suit = 1; suit < 5; suit++) {
					if (suitCount[suit] > 2) {
						for (uint32 i = 0; i < 5; i++) {
							if (!suitMark[i][suit]) {
								found = true;
								pokerDiscard(i);
							}
						}
					}
				}

				if (!found) {
					for (uint32 i = 2; i < 5; i++)
						pokerDiscard(i);
				}
			}
		}
	}

	_app->objectSetAccessibilityOff(kObject13903);
}

// FAUST.EXE 0x4a21c0: rate the player's hand (slots 0-4) into 13972-13974
void Zone4Faust::pokerEvaluatePlayer() {
	_app->objectSetAccessibilityOn(kObject13903);
	_app->varSetByte(13972, 0);
	_app->varSetByte(13973, 0);
	_app->varSetByte(13974, 0);

	// Royal flush, straight flush, four of a kind, full house, flush, straight, three of a kind, two pairs, pair
	int32 categories[9] = { 10, 9, 0, 0, 6, 5, 0, 0, 0 };

	for (uint32 i = 0; i < 4; i++) {
		if (_app->varGetByte(13961 + i) != _app->varGetByte(13960 + i)) {
			categories[4] = 0;
			categories[0] = 0;
			categories[1] = 0;
		}
	}

	for (uint32 i = 0; i < 4; i++) {
		if (_app->varGetByte(13950 + i) != _app->varGetByte(13951 + i) + 1) {
			categories[5] = 0;
			categories[0] = 0;
			categories[1] = 0;
		}
	}

	if (categories[4] && categories[5] && _app->varGetByte(13950) != 14)
		categories[0] = 0;

	if (categories[4] > 0 || categories[5] > 0) {
		if ((int8)_app->varGetByte(13973) < (int8)_app->varGetByte(13950))
			_app->varSetByte(13973, _app->varGetByte(13950));

		if ((int8)_app->varGetByte(13974) < (int8)_app->varGetByte(13960))
			_app->varSetByte(13974, _app->varGetByte(13960));
	}

	int32 counts[5] = { 0, 0, 0, 0, 0 };
	uint32 group = 0;
	for (uint32 i = 0; i < 4; i++) {
		if (_app->varGetByte(13950 + i) == _app->varGetByte(13951 + i)) {
			counts[group]++;

			if ((int8)_app->varGetByte(13973) < (int8)_app->varGetByte(13950 + i)) {
				_app->varSetByte(13973, _app->varGetByte(13950 + i));
				_app->varSetByte(13974, _app->varGetByte(13960 + i));
			}
		} else {
			group++;
		}
	}

	for (uint32 i = 0; i < 5; i++) {
		if (counts[i] == 3)
			categories[2] = 7;

		if (counts[i] == 2)
			categories[6] = 3;
		else if (counts[i] == 1) {
			if (categories[8] == 0)
				categories[8] = 1;
			else
				categories[7] = 2;
		}
	}

	if (categories[8] > 0 && categories[6] > 0)
		categories[3] = 6;

	if (_app->varGetByte(13973) == 0) {
		_app->varSetByte(13973, _app->varGetByte(13950));
		_app->varSetByte(13974, _app->varGetByte(13960));
	}

	for (uint32 i = 0; i < 9; i++) {
		if (categories[i] > 0) {
			_app->varSetByte(13972, (byte)categories[i]);
			break;
		}
	}

	_app->objectSetAccessibilityOff(kObject13903);
}

// FAUST.EXE 0x4a2550: deal the next card of the deck into a slot (0-4 player, 5-9 opponent)
byte Zone4Faust::pokerDealCard(uint32 slot) {
	_app->objectSetAccessibilityOn(kObject13903);

	_app->varSetByte(13971, _app->varGetByte(13971) + 1);
	uint32 position = _app->varGetByte(13971);

	_app->varSetByte(13940 + slot, _app->varGetByte(13901 + position));
	_app->varSetByte(13950 + slot, _app->varGetByte(13801 + position));
	_app->varSetByte(13960 + slot, _app->varGetByte(13841 + position));

	_app->objectSetAccessibilityOff(kObject13903);

	return _app->varGetByte(13901 + position);
}

// FAUST.EXE 0x4a2630
void Zone4Faust::pokerDeal() {
	_app->objectSetAccessibilityOn(kObject13903);
	_app->varSetByte(13971, 0);

	for (int32 slot = 4; slot >= 0; slot--) {
		_app->objectPresentationShow(kObject13900, pokerDealCard(slot) + 32 * slot);
		_app->soundPlay(13078);
		_app->_vm->update();
		_app->_vm->update();
		_app->_vm->update();

		_app->objectPresentationShow(kObject13902, pokerDealCard(slot + 5) + 32 * slot);
		_app->soundPlay(13077);
		_app->_vm->update();
		_app->_vm->update();
		_app->_vm->update();
	}

	_app->objectSetAccessibilityOff(kObject13903);
}

// FAUST.EXE 0x4a2720
void Zone4Faust::pokerShuffle() {
	_app->objectSetAccessibilityOn(kObject13903);

	for (uint32 i = 0; i < 1000; i++) {
		uint32 first = rnd(32) + 1;
		uint32 second = rnd(32) + 1;

		byte card = _app->varGetByte(13901 + first);
		byte rank = _app->varGetByte(13801 + first);
		byte suit = _app->varGetByte(13841 + first);

		_app->varSetByte(13901 + first, _app->varGetByte(13901 + second));
		_app->varSetByte(13801 + first, _app->varGetByte(13801 + second));
		_app->varSetByte(13841 + first, _app->varGetByte(13841 + second));
		_app->varSetByte(13901 + second, card);
		_app->varSetByte(13801 + second, rank);
		_app->varSetByte(13841 + second, suit);
	}

	_app->objectSetAccessibilityOff(kObject13903);
}

// FAUST.EXE 0x4a2880
void Zone4Faust::pokerClearTable() {
	_app->objectSetAccessibilityOn(kObject13903);

	for (uint32 slot = 0; slot < 5; slot++) {
		if ((int8)_app->varGetByte(13940 + slot) > 0) {
			_app->objectPresentationHide(kObject13900, _app->varGetByte(13940 + slot) + 32 * slot);
			_app->soundPlay(13077);
			_app->_vm->update();
		}

		if ((int8)_app->varGetByte(13945 + slot) > 0) {
			_app->objectPresentationHide(kObject13902, _app->varGetByte(13945 + slot) + 32 * slot);
			_app->soundPlay(13077);
			_app->_vm->update();
		}
	}

	_app->objectSetAccessibilityOff(kObject13903);
}

// FAUST.EXE 0x4a2970: sort a hand (offset 0 = player, 5 = opponent) by descending rank, moving the cards on screen
void Zone4Faust::pokerSortHand(uint32 offset) {
	_app->objectSetAccessibilityOn(kObject13903);

	bool swapped;
	do {
		swapped = false;

		for (uint32 i = offset; i < offset + 4; i++) {
			ObjectId objectId = (i > 4) ? kObject13902 : kObject13900;
			uint32 base = 32 * (i > 4 ? i - 5 : i);

			if ((int8)_app->varGetByte(13950 + i) >= (int8)_app->varGetByte(13951 + i))
				continue;

			swapped = true;
			_app->objectPresentationHide(objectId, _app->varGetByte(13940 + i) + base);
			_app->objectPresentationHide(objectId, _app->varGetByte(13941 + i) + base + 32);

			byte card = _app->varGetByte(13940 + i);
			byte rank = _app->varGetByte(13950 + i);
			byte suit = _app->varGetByte(13960 + i);

			_app->varSetByte(13940 + i, _app->varGetByte(13941 + i));
			_app->varSetByte(13950 + i, _app->varGetByte(13951 + i));
			_app->varSetByte(13960 + i, _app->varGetByte(13961 + i));
			_app->varSetByte(13941 + i, card);
			_app->varSetByte(13951 + i, rank);
			_app->varSetByte(13961 + i, suit);

			_app->objectPresentationShow(objectId, _app->varGetByte(13940 + i) + base);
			_app->objectPresentationShow(objectId, _app->varGetByte(13941 + i) + base + 32);
			_app->_vm->update();
		}
	} while (swapped);

	_app->objectSetAccessibilityOff(kObject13903);
}

} // End of namespace Ring
