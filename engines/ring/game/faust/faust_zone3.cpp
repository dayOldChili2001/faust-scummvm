/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 03110-1301, USA.
 */

#include "ring/game/faust/faust_zone3.h"

#include "ring/game/faust/faust_application.h"
#include "ring/game/faust/faust_shared.h"

#include "ring/base/saveload.h"

#include "ring/graphics/drag_control.h"

#include "ring/debug.h"
#include "ring/ring.h"
#include "ring/helpers.h"

using namespace FaustGame;

namespace Ring {

Zone3Faust::Zone3Faust(ApplicationFaust *application) : _app(application) {
}

Zone3Faust::~Zone3Faust() {
	// Zero-out passed pointers
	_app = nullptr;
}

void Zone3Faust::onInit() {
	_app->setCurrentZone(kZone3);

	_app->puzzleAdd(kPuzzle12001);
	_app->puzzleAddBackgroundImage(kPuzzle12001, "a01s02n02p02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle12002);
	_app->puzzleAddBackgroundImage(kPuzzle12002, "a01s02n02p04.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle12004);
	_app->puzzleAddBackgroundImage(kPuzzle12004, "a01s02n03p02l01a.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle12005);
	_app->puzzleAddBackgroundImage(kPuzzle12005, "a01s02n03p02l02a.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle12006);
	_app->puzzleAddBackgroundImage(kPuzzle12006, "a01s02n03p02l01b.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle12007);
	_app->puzzleAddBackgroundImage(kPuzzle12007, "a01s02n03p02l02b.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle12008);
	_app->puzzleAddBackgroundImage(kPuzzle12008, "a01s02n03p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle12009);
	_app->puzzleAddBackgroundImage(kPuzzle12009, "a01s02n03p03.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle12010);
	_app->puzzleAddBackgroundImage(kPuzzle12010, "a01s02n03p04.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle12011);
	_app->puzzleAddBackgroundImage(kPuzzle12011, "a01s02n02p03.bmp", Common::Point(0, 16), true);
	_app->rotationAdd(12001, "a01s02n02r01", 0, 10);
	_app->rotationSetCompressionBufferLength(12001, 1400000);
	_app->rotationAdd(12002, "a01s02n03r01", 0, 5);
	_app->rotationAdd(12003, "a01s02n04r01", 0, 1);
	_app->rotationAdd(12004, "a01s02n05r01", 0, 8);
	_app->rotationSetCompressionBufferLength(12004, 2000000);
	_app->rotationAddMovabilityToRotation(12001, 12002, "A01S02N02_N03", Common::Rect(311, -122, 599, 256), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(12001, 0, 0.0f, 0.0f, 87.0f, 0.0f, 2, 0.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(12001, kPuzzle12011, "", Common::Rect(956, -52, 1221, 143), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(12001, 1, 65.0f, 0.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(12002, 12001, "A01S02N03_N02", Common::Rect(2056, -170, 2436, 242), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(12002, 0, 180.0f, 0.0f, 87.0f, 0.0f, 2, 180.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(12002, 12003, "A01S02N03_N04", Common::Rect(253, -163, 660, 268), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(12002, 1, 0.0f, 0.0f, 87.0f, 0.0f, 2, 0.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(12002, kPuzzle12011, "", Common::Rect(1538, -132, 1785, 78), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(12002, 2, 122.0f, 0.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(12003, 12002, "A01S02N04_N03", Common::Rect(2107, -122, 2371, 237), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(12003, 0, 180.0f, 0.0f, 87.0f, 0.0f, 2, 180.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(12003, 12004, "A01S02N04_N05", Common::Rect(286, -177, 638, 270), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(12003, 1, 0.0f, 0.0f, 87.0f, 0.0f, 2, 0.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(12004, 12003, "A01S02N05_N04", Common::Rect(2142, -289, 2571, 280), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(12004, 0, 180.0f, 0.0f, 87.0f, 0.0f, 2, 180.0f, 0.3f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle12001, 12001, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle12001, 0, 90.0f, 26.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle12004, 12002, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleAddMovabilityToRotation(kPuzzle12005, 12002, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleAddMovabilityToRotation(kPuzzle12006, 12003, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleAddMovabilityToRotation(kPuzzle12007, 12003, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleAddMovabilityToRotation(kPuzzle12008, 12002, "", Common::Rect(320, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle12008, 0, 67.0f, 12.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle12008, 12003, "", Common::Rect(0, 420, 320, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle12008, 1, 138.0f, 12.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle12009, 12002, "", Common::Rect(320, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle12009, 0, 67.0f, 12.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle12009, 12003, "", Common::Rect(0, 420, 320, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle12009, 1, 138.0f, 12.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle12010, 12002, "", Common::Rect(320, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle12010, 0, 67.0f, 12.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle12010, 12003, "", Common::Rect(0, 420, 320, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle12010, 1, 138.0f, 12.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle12011, 12001, "", Common::Rect(320, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle12011, 0, 65.0f, 0.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle12011, 12002, "", Common::Rect(0, 420, 320, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle12011, 1, 122.0f, 0.0f, 87.0f);
	_app->objectAdd(kObject12013, "", "", 1);
	_app->objectAddRotationAccessibility(kObject12013, 12001, Common::Rect(1914, -214, 2649, 327), true, kCursorMove, 0);
	_app->objectAdd(kObjectAshShovel, "Ash shovel", "A01_Shovel", 9);
	_app->objectSetActiveCursor(kObjectAshShovel, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectAshShovel, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPresentation(kObjectAshShovel);
	_app->objectPresentationAddImageToRotation(kObjectAshShovel, 0, 12001, 0);
	_app->objectAdd(kObject12007, "", "", 1);
	_app->objectAdd(kObjectBurnedKey, "Burned Key", "A01_BurnedKey", 1);
	_app->objectSetActiveCursor(kObjectBurnedKey, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectBurnedKey, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectShovelWithAshes, "Shovel with ashes", "A01_ShovelAshes", 1);
	_app->objectSetActiveCursor(kObjectShovelWithAshes, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectShovelWithAshes, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPresentation(kObject12007);
	_app->objectPresentationAddImageToPuzzle(kObject12007, 0, kPuzzle12001, "a01s02n02p02l01.tga", Common::Point(309, 304), true, kDrawTypeAlpha, 1000);
	_app->objectAddPresentation(kObject12007);
	_app->objectPresentationAddImageToPuzzle(kObject12007, 1, kPuzzle12001, "a01s02n02p02l02.tga", Common::Point(264, 285), true, kDrawTypeAlpha, 1001);
	_app->objectAddPresentation(kObject12007);
	_app->objectPresentationAddImageToPuzzle(kObject12007, 2, kPuzzle12001, "a01s02n02p02l03.tga", Common::Point(281, 268), true, kDrawTypeAlpha, 1002);
	_app->objectAddPresentation(kObject12007);
	_app->objectPresentationAddImageToPuzzle(kObject12007, 3, kPuzzle12001, "a01s02n02p02l04.tga", Common::Point(307, 286), true, kDrawTypeAlpha, 1003);
	_app->objectAddPresentation(kObject12007);
	_app->objectPresentationAddImageToPuzzle(kObject12007, 4, kPuzzle12001, "a01s02n02p02l05.bmp", Common::Point(467, 56), true, kDrawTypeNormal, 1000);
	_app->objectPresentationShow(kObject12007, 0);
	_app->objectPresentationShow(kObject12007, 1);
	_app->objectPresentationShow(kObject12007, 2);
	_app->objectPresentationShow(kObject12007, 3);
	_app->objectAddPuzzleAccessibility(kObjectAshShovel, kPuzzle12001, Common::Rect(466, 48, 553, 241), true, kCursorTake, 0);
	_app->objectAddPuzzleAccessibility(kObject12007, kPuzzle12001, Common::Rect(314, 309, 356, 324), false, kCursorTake, 0);
	_app->objectAddPuzzleAccessibility(kObject12007, kPuzzle12001, Common::Rect(267, 287, 304, 321), true, kCursorActionObject, 1);
	_app->objectAddPuzzleAccessibility(kObject12007, kPuzzle12001, Common::Rect(297, 277, 333, 309), true, kCursorActionObject, 2);
	_app->objectAddPuzzleAccessibility(kObject12007, kPuzzle12001, Common::Rect(321, 294, 355, 325), true, kCursorActionObject, 3);
	_app->objectAdd(kObject12003, "", "", 1);
	_app->objectAdd(kObjectBronzeKey, "Bronze key", "A01_BronzeKey", 1);
	_app->objectSetActiveCursor(kObjectBronzeKey, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectBronzeKey, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPresentation(kObject12003);
	_app->objectPresentationAddAnimationToRotation(kObject12003, 0, 12001, 3, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject12003, 0, 0, 12002);
	_app->objectAddPresentation(kObject12003);
	_app->objectPresentationAddImageToPuzzle(kObject12003, 1, kPuzzle12002, "a01s02n02p04l02.tga", Common::Point(170, 132), true, kDrawTypeAlpha, 1000);
	_app->objectAddPresentation(kObject12003);
	_app->objectPresentationAddImageToPuzzle(kObject12003, 2, kPuzzle12002, "a01s02n02p04l01.tga", Common::Point(233, 145), true, kDrawTypeAlpha, 1000);
	_app->objectPresentationHide(kObject12003, 1);
	_app->objectPresentationHide(kObject12003, 2);
	_app->objectAddPresentation(kObject12003);
	_app->objectPresentationAddAnimationToRotation(kObject12003, 3, 12001, 3, 10, 12.5f, 10);
	_app->objectAddPresentation(kObject12003);
	_app->objectPresentationAddAnimationToRotation(kObject12003, 4, 12002, 4, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject12003, 4, 0, 12002);
	_app->objectAddPresentation(kObject12003);
	_app->objectPresentationAddAnimationToRotation(kObject12003, 5, 12002, 4, 10, 12.5f, 10);
	_app->objectAddRotationAccessibility(kObject12003, 12001, Common::Rect(945, 169, 1031, 225), true, kCursorZoom, 0);
	_app->objectAddPuzzleAccessibility(kObject12003, kPuzzle12002, Common::Rect(352, 249, 390, 305), true, kCursorZoom, 1);
	_app->objectAddPuzzleAccessibility(kObject12003, kPuzzle12002, Common::Rect(213, 243, 323, 302), true, kCursorZoom, 2);
	_app->objectAddPuzzleAccessibility(kObject12003, kPuzzle12002, Common::Rect(0, 420, 640, 464), false, kCursorBack, 3);
	_app->objectAddRotationAccessibility(kObject12003, 12002, Common::Rect(1590, 92, 1712, 167), true, kCursorZoom, 4);
	_app->objectAddPuzzleAccessibility(kObject12003, kPuzzle12002, Common::Rect(0, 420, 640, 464), true, kCursorBack, 5);
	_app->objectAdd(kObject12004, "", "", 1);
	_app->objectAddPresentation(kObject12004);
	_app->objectPresentationAddAnimationToRotation(kObject12004, 0, 12001, 1, 15, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject12004, 0, 0, 12001);
	_app->objectAddPresentation(kObject12004);
	_app->objectPresentationAddAnimationToRotation(kObject12004, 1, 12001, 1, 15, 12.5f, 10);
	_app->objectAddRotationAccessibility(kObject12004, 12001, Common::Rect(1255, 387, 1369, 441), true, kCursorZoom, 0);
	_app->objectAdd(kObject12005, "", "", 1);
	_app->objectAddPresentation(kObject12005);
	_app->objectPresentationAddAnimationToRotation(kObject12005, 0, 12001, 4, 15, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject12005, 0, 0, 12006);
	_app->objectAddPresentation(kObject12005);
	_app->objectPresentationAddAnimationToRotation(kObject12005, 1, 12001, 4, 15, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject12005, 1, 0, 12007);
	_app->objectAddRotationAccessibility(kObject12005, 12001, Common::Rect(3058, 359, 3373, 446), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject12005, 12001, Common::Rect(3343, 352, 3570, 418), false, kCursorAction, 1);
	_app->objectAddRotationAccessibility(kObject12005, 12001, Common::Rect(2921, 350, 3069, 495), false, kCursorAction, 2);
	_app->objectAddRotationAccessibility(kObject12005, 12001, Common::Rect(3076, 368, 3359, 441), false, kCursorZoom, 3);
	_app->objectAdd(kObject12006, "", "", 1);
	_app->objectAddPresentation(kObject12006);
	_app->objectPresentationAddAnimationToRotation(kObject12006, 0, 12001, 5, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject12006, 0, 0, 12008);
	_app->objectAddPresentation(kObject12006);
	_app->objectPresentationAddAnimationToRotation(kObject12006, 1, 12001, 6, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject12006, 1, 0, 12008);
	_app->objectAddPresentation(kObject12006);
	_app->objectPresentationAddAnimationToRotation(kObject12006, 2, 12001, 7, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject12006, 2, 0, 12008);
	_app->objectAddPresentation(kObject12006);
	_app->objectPresentationAddAnimationToRotation(kObject12006, 3, 12001, 8, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject12006, 3, 0, 12008);
	_app->objectAddPresentation(kObject12006);
	_app->objectPresentationAddAnimationToRotation(kObject12006, 4, 12001, 5, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject12006, 4, 0, 12009);
	_app->objectAddPresentation(kObject12006);
	_app->objectPresentationAddAnimationToRotation(kObject12006, 5, 12001, 6, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject12006, 5, 0, 12009);
	_app->objectAddPresentation(kObject12006);
	_app->objectPresentationAddAnimationToRotation(kObject12006, 6, 12001, 7, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject12006, 6, 0, 12009);
	_app->objectAddPresentation(kObject12006);
	_app->objectPresentationAddAnimationToRotation(kObject12006, 7, 12001, 8, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject12006, 7, 0, 12009);
	_app->objectAddRotationAccessibility(kObject12006, 12001, Common::Rect(3454, 320, 3527, 345), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject12006, 12001, Common::Rect(3454, 354, 3533, 364), true, kCursorAction, 1);
	_app->objectAddRotationAccessibility(kObject12006, 12001, Common::Rect(3454, 373, 3527, 381), true, kCursorAction, 2);
	_app->objectAddRotationAccessibility(kObject12006, 12001, Common::Rect(3454, 390, 3529, 404), true, kCursorAction, 3);
	_app->objectAddRotationAccessibility(kObject12006, 12001, Common::Rect(3443, 319, 3564, 406), false, kCursorAction, 4);
	_app->objectAdd(kObject12010, "", "", 1);
	_app->objectAddPresentation(kObject12010);
	_app->objectPresentationAddAnimationToRotation(kObject12010, 0, 12002, 1, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject12010, 0, 0, 12004);
	_app->objectAddPresentation(kObject12010);
	_app->objectPresentationAddAnimationToRotation(kObject12010, 1, 12002, 1, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject12010, 1, 0, 12004);
	_app->objectAddPresentation(kObject12010);
	_app->objectPresentationAddAnimationToRotation(kObject12010, 2, 12002, 3, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject12010, 2, 0, 12004);
	_app->objectAddPresentation(kObject12010);
	_app->objectPresentationAddAnimationToRotation(kObject12010, 3, 12002, 3, 10, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject12010, 3, 0, 12004);
	_app->objectAddPresentation(kObject12010);
	_app->objectPresentationAddAnimationToRotation(kObject12010, 4, 12002, 4, 10, 12.5f, 6);
	_app->objectAddPresentation(kObject12010);
	_app->objectPresentationAddAnimationToRotation(kObject12010, 5, 12002, 4, 10, 12.5f, 10);
	_app->objectAddPresentation(kObject12010);
	_app->objectPresentationAddImageToRotation(kObject12010, 6, 12002, 0);
	_app->objectAddPresentation(kObject12010);
	_app->objectPresentationAddImageToRotation(kObject12010, 7, 12002, 2);
	_app->objectAddRotationAccessibility(kObject12010, 12002, Common::Rect(666, 279, 864, 352), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject12010, 12002, Common::Rect(683, 312, 736, 355), false, kCursorTake, 1);
	_app->objectAddRotationAccessibility(kObject12010, 12002, Common::Rect(646, 357, 838, 394), false, kCursorAction, 2);
	_app->objectAdd(kObject12034, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject12034, kPuzzle12010, Common::Rect(314, 375, 355, 422), true, kCursorActionObject, 0);
	_app->objectAddPuzzleAccessibility(kObject12034, kPuzzle12010, Common::Rect(197, 359, 228, 401), true, kCursorActionObject, 1);
	_app->objectAddPresentation(kObject12034);
	_app->objectPresentationAddImageToPuzzle(kObject12034, 0, kPuzzle12010, "a01s02n03p04l01.bmp", Common::Point(298, 366), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject12034);
	_app->objectPresentationAddImageToPuzzle(kObject12034, 1, kPuzzle12010, "a01s02n03p04l02.bmp", Common::Point(177, 355), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObject12009, "", "", 1);
	_app->objectAdd(kObjectLotteryTicket, "Lottery ticket", "A01_LotteryTicket", 1);
	_app->objectSetActiveCursor(kObjectLotteryTicket, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectLotteryTicket, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddRotationAccessibility(kObject12009, 12002, Common::Rect(965, -155, 1228, 392), true, kCursorMove, 0);
	_app->objectAddPuzzleAccessibility(kObject12009, kPuzzle12008, Common::Rect(265, 63, 372, 168), false, kCursorZoom, 1);
	_app->objectAddPuzzleAccessibility(kObject12009, kPuzzle12009, Common::Rect(277, 292, 357, 331), false, kCursorTake, 2);
	_app->objectAddRotationAccessibility(kObject12009, 12003, Common::Rect(1780, -132, 1908, 238), true, kCursorMove, 3);
	_app->objectAddPresentation(kObject12009);
	_app->objectPresentationAddImageToPuzzle(kObject12009, 0, kPuzzle12009, "a01s02n03p03l01.bmp", Common::Point(176, 42), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject12009);
	_app->objectPresentationAddImageToPuzzle(kObject12009, 1, kPuzzle12009, "a01s02n03p03l02.bmp", Common::Point(252, 289), true, kDrawTypeNormal, 1000);
	_app->objectAdd(kObject12028, "", "Cur_drag", 4);
	_app->objectSetPassiveDrawCursor(kObject12028, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetActiveDrawCursor(kObject12028, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);

	for (uint32 i = 0; i < 40; i++) {
		_app->objectAddPresentation(kObject12028);
		_app->objectPresentationAddImageToPuzzle(kObject12028, i, kPuzzle12009, Common::String::format("a01s02n03p03s01.%04d.bmp", i + 1), Common::Point(239, 157), true, kDrawTypeNormal, 1000);
	}

	_app->objectAddPuzzleAccessibility(kObject12028, kPuzzle12009, Common::Rect(207, 132, 442, 349), true, kCursorDragDrop, 0);
	_app->objectAdd(kObject12025, "", "Cur_drag", 4);
	_app->objectSetPassiveDrawCursor(kObject12025, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetActiveDrawCursor(kObject12025, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObject12026, "", "Cur_drag", 4);
	_app->objectSetPassiveDrawCursor(kObject12026, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetActiveDrawCursor(kObject12026, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObject12027, "", "Cur_drag", 4);
	_app->objectSetPassiveDrawCursor(kObject12027, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetActiveDrawCursor(kObject12027, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObject12027, kPuzzle12008, Common::Rect(113, 180, 380, 420), true, kCursorDragDrop, 0);
	_app->objectAddPuzzleAccessibility(kObject12027, kPuzzle12008, Common::Rect(386, 180, 639, 420), true, kCursorDragDrop, 1);

	for (uint32 i = 0; i < 15; i++) {
		_app->objectAddPresentation(kObject12025);
		_app->objectPresentationAddImageToPuzzle(kObject12025, i, kPuzzle12008, Common::String::format("a01s02n03p01s02.%04d.bmp", i + 1), Common::Point(100, 16), true, kDrawTypeNormal, 1000);
	}

	for (uint32 i = 0; i < 15; i++) {
		_app->objectAddPresentation(kObject12026);
		_app->objectPresentationAddImageToPuzzle(kObject12026, i, kPuzzle12008, Common::String::format("a01s02n03p01s03.%04d.bmp", i + 1), Common::Point(382, 16), true, kDrawTypeNormal, 1000);
	}

	_app->objectAdd(kObjectTooth, "Tooth", "A01_Tooth", 1);
	_app->objectSetActiveCursor(kObjectTooth, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectTooth, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObject12012, "", "Cur_drag", 4);
	_app->objectSetPassiveDrawCursor(kObject12012, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetActiveDrawCursor(kObject12012, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);

	for (uint32 i = 0; i < 15; i++) {
		_app->objectAddPresentation(kObject12012);
		_app->objectPresentationAddImageToPuzzle(kObject12012, i, kPuzzle12001, Common::String::format("a01s02n02p01s01.%04d.tga", i + 1), Common::Point(208, 129), true, kDrawTypeAlpha, 1100);
	}

	_app->objectAddPuzzleAccessibility(kObject12012, kPuzzle12001, Common::Rect(0, 16, 640, 420), false, kCursorDragDrop, 0);
	_app->objectAdd(kObject12018, "", "Cur_drag", 4);
	_app->objectSetPassiveDrawCursor(kObject12018, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetActiveDrawCursor(kObject12018, Common::Point(20, 20), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);

	for (uint32 i = 0; i < 15; i++) {
		_app->objectAddPresentation(kObject12018);
		_app->objectPresentationAddImageToPuzzle(kObject12018, i, kPuzzle12001, Common::String::format("a01s02n02p01s02.%04d.tga", i + 1), Common::Point(207, 144), true, kDrawTypeAlpha, 1100);
	}

	_app->objectAddPuzzleAccessibility(kObject12018, kPuzzle12001, Common::Rect(0, 16, 640, 420), false, kCursorDragDrop, 0);
	_app->objectAdd(kObjectStrainer, "Strainer", "A01_Strainer", 1);
	_app->objectSetActiveCursor(kObjectStrainer, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectStrainer, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPresentation(kObjectStrainer);
	_app->objectPresentationAddImageToRotation(kObjectStrainer, 0, 12001, 2);
	_app->objectAddRotationAccessibility(kObjectStrainer, 12001, Common::Rect(3111, 261, 3218, 301), true, kCursorTake, 0);
	_app->objectAddPuzzleAccessibility(kObjectStrainer, kPuzzle12001, Common::Rect(250, 164, 391, 259), false, kCursorAction, 1);
	_app->objectAddPresentation(kObjectStrainer);
	_app->objectPresentationAddImageToPuzzle(kObjectStrainer, 1, kPuzzle12001, "a01s02n02p01s02.0015.tga", Common::Point(207, 144), true, kDrawTypeAlpha, 1100);
	_app->objectAdd(kObject12030, "", "", 1);
	_app->objectAdd(kObject12031, "", "", 1);
	_app->objectAdd(kObject12032, "", "", 1);
	_app->objectAdd(kObjectButcherKnife, "Butcher knife", "A01_Knife", 1);
	_app->objectSetActiveCursor(kObjectButcherKnife, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectButcherKnife, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPresentation(kObject12030);
	_app->objectPresentationAddAnimationToRotation(kObject12030, 0, 12004, 1, 15, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject12030, 0, 0, 12012);
	_app->objectAddPresentation(kObject12030);
	_app->objectPresentationAddAnimationToRotation(kObject12030, 1, 12004, 1, 15, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject12030, 1, 0, 12012);
	_app->objectAddPresentation(kObject12030);
	_app->objectPresentationAddImageToRotation(kObject12030, 2, 12004, 3);
	_app->objectAddPresentation(kObject12031);
	_app->objectPresentationAddAnimationToRotation(kObject12031, 0, 12004, 4, 10, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject12031, 0, 0, 12010);
	_app->objectAddPresentation(kObject12031);
	_app->objectPresentationAddAnimationToRotation(kObject12031, 1, 12004, 4, 10, 8.0f, 10);
	_app->objectAddPresentation(kObject12031);
	_app->objectPresentationAddAnimationToRotation(kObject12031, 2, 12004, 4, 3, 12.5f, 6);
	_app->objectAddPresentation(kObject12031);
	_app->objectPresentationAddAnimationToRotation(kObject12031, 3, 12004, 4, 3, 12.5f, 10);
	_app->objectAddPresentation(kObject12032);
	_app->objectPresentationAddAnimationToRotation(kObject12032, 0, 12004, 5, 9, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject12032, 0, 0, 12013);
	_app->objectAddPresentation(kObject12032);
	_app->objectPresentationAddAnimationToRotation(kObject12032, 1, 12004, 5, 9, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject12032, 1, 0, 12014);
	_app->objectAddPresentation(kObject12032);
	_app->objectPresentationAddAnimationToRotation(kObject12032, 2, 12004, 6, 9, 12.5f, 6);
	_app->objectPresentationSetAnimationOnRotation(kObject12032, 2, 0, 12013);
	_app->objectAddPresentation(kObject12032);
	_app->objectPresentationAddAnimationToRotation(kObject12032, 3, 12004, 6, 9, 12.5f, 10);
	_app->objectPresentationSetAnimationOnRotation(kObject12032, 3, 0, 12014);
	_app->objectAddPresentation(kObject12032);
	_app->objectPresentationAddImageToRotation(kObject12032, 4, 12004, 0);
	_app->objectAddPresentation(kObject12032);
	_app->objectPresentationAddImageToRotation(kObject12032, 5, 12004, 2);
	_app->objectAddRotationAccessibility(kObject12030, 12004, Common::Rect(2875, 294, 3436, 526), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject12030, 12004, Common::Rect(2958, 118, 3382, 322), false, kCursorAction, 1);
	_app->objectAddRotationAccessibility(kObject12031, 12004, Common::Rect(3255, 80, 3350, 115), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject12032, 12004, Common::Rect(3004, 71, 3260, 129), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject12032, 12004, Common::Rect(3028, 12, 3329, 78), false, kCursorAction, 1);
	_app->objectAddRotationAccessibility(kObjectButcherKnife, 12004, Common::Rect(3065, 80, 3148, 115), false, kCursorTake, 0);
	_app->objectAdd(kObject12038, "", "", 1);
	_app->objectAddPresentation(kObject12038);
	_app->objectPresentationAddAnimationToRotation(kObject12038, 0, 12004, 7, 2, 15.0f, 5);
	_app->objectAddRotationAccessibility(kObject12038, 12004, Common::Rect(1246, 261, 1284, 297), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject12038, 12004, Common::Rect(1318, 255, 1355, 289), true, kCursorAction, 1);
	_app->objectAdd(kObject12039, "", "", 1);
	_app->objectAddPresentation(kObject12039);
	_app->objectPresentationAddImageToRotation(kObject12039, 0, 12003, 0);
	_app->objectAdd(kObject12040, "", "", 1);
	_app->objectAddPresentation(kObject12040);
	_app->objectPresentationAddAnimationToRotation(kObject12040, 0, 12001, 9, 60, 12.5f, 6);
	_app->objectPresentationShow(kObject12040, 0);
	_app->objectPresentationPauseAnimation(kObject12040, 0);
	_app->objectAdd(kObject12020, "", "", 1);
	_app->objectAddRotationAccessibility(kObject12020, 12003, Common::Rect(2758, 111, 2826, 160), true, kCursorZoom, 0);
	_app->objectAdd(kObject12021, "", "", 1);
	_app->objectAddRotationAccessibility(kObject12021, 12002, Common::Rect(3243, -78, 3533, 144), true, kCursorZoom, 0);
	_app->objectAddRotationAccessibility(kObject12021, 12003, Common::Rect(2675, -83, 2888, 99), true, kCursorZoom, 1);
	_app->objectAdd(kObject12022, "", "", 1);
	_app->objectAddRotationAccessibility(kObject12022, 12003, Common::Rect(1119, 216, 1743, 383), true, kCursorZoom, 0);
	_app->objectAdd(kObject12019, "", "", 1);
	_app->objectAddRotationAccessibility(kObject12019, 12002, Common::Rect(660,  205,  718, 275), true, kCursorZoom, 0);
	_app->objectAddRotationAccessibility(kObject12019, 12002, Common::Rect(903,  113,  942, 162), true, kCursorZoom, 1);
	_app->objectAddRotationAccessibility(kObject12019, 12003, Common::Rect(1782, 333, 1842, 427), true, kCursorZoom, 2);
	_app->objectAddRotationAccessibility(kObject12019, 12003, Common::Rect(1488, 150, 1529, 209), true, kCursorZoom, 3);
	_app->objectAdd(kObject12024, "", "", 1);
	_app->objectAddRotationAccessibility(kObject12024, 12003, Common::Rect(2891, 47, 2970, 158), true, kCursorZoom, 0);
	_app->objectAdd(kObject12011, "", "", 1);
	_app->objectAddRotationAccessibility(kObject12011, 12003, Common::Rect(2990, 296, 3086, 373), true, kCursorZoom, 0);
	_app->objectAdd(kObject12036, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject12036, kPuzzle12002, Common::Rect(222, 161, 322, 229), false, kCursorIdle, 0);
	_app->objectAddPuzzleAccessibility(kObject12036, kPuzzle12002, Common::Rect(258, 168, 477, 348), false, kCursorIdle, 1);
	_app->soundAdd(12201, kSoundTypeBackgroundMusic, "02_bgr_music.wac", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(12201, 90);
	_app->soundAdd(12109, kSoundTypeEffect, "02_shaking_strainer.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12110, kSoundTypeEffect, "02_shaking_tooth.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12101, kSoundTypeEffect, "02_predal_open.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12102, kSoundTypeEffect, "02_predal_close.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12103, kSoundTypeEffect, "02_pecica_open.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12104, kSoundTypeEffect, "02_pecica_close.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12105, kSoundTypeEffect, "02_Closet_door_open.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12106, kSoundTypeEffect, "02_Closet_door_close.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12107, kSoundTypeEffect, "02_strainer_posoda.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12108, kSoundTypeEffect, "02_predal_velik_open.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12111, kSoundTypeEffect, "02_predal_open_mali.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12112, kSoundTypeEffect, "02_predal_close_mali.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12113, kSoundTypeEffect, "02_zavesa.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12114, kSoundTypeEffect, "02_sef_tic_metallic.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12115, kSoundTypeEffect, "02_sef_cifra.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12116, kSoundTypeEffect, "02_toilet_flush.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(12116, 75);
	_app->soundAdd(12117, kSoundTypeEffect, "02_toilet_empty_flush.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12119, kSoundTypeEffect, "02_creak_medium.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(12119, 95);
	_app->soundAdd(12126, kSoundTypeEffect, "02_WC_hit_metalic.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(12126, 95);
	_app->soundAdd(12120, kSoundTypeEffect, "02_WC_tap.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(12120, 90);
	_app->soundAdd(12122, kSoundTypeEffect, "02_WC_lid_close_start.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12124, kSoundTypeEffect, "02_WC_lid_close_end.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(12124, 95);
	_app->soundAdd(12123, kSoundTypeEffect, "02_WC_lid_open_start.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(12123, 95);
	_app->soundAdd(12125, kSoundTypeEffect, "02_WC_lid_open_end.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(12125, 90);
	_app->soundAdd(12121, kSoundTypeEffect, "02_safe_latch.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12127, kSoundTypeEffect, "02_Front_Door_close.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12128, kSoundTypeEffect, "02_Take_grebljica.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12129, kSoundTypeEffect, "02_Take_ash.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12130, kSoundTypeEffect, "02_Put_ash.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12131, kSoundTypeEffect, "02_water_start01.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12132, kSoundTypeEffect, "02_water_start02.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12134, kSoundTypeEffect, "02_sqeak_ventil_01.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(12134, 90);
	_app->soundAdd(12135, kSoundTypeEffect, "02_sqeak_ventil_02.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(12135, 90);
	_app->soundAdd(12136, kSoundTypeEffect, "02_sqeak_ventil_03.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(12136, 90);
	_app->soundAdd(12137, kSoundTypeEffect, "02_sqeak_ventil_04.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(12137, 90);
	_app->soundAdd(12138, kSoundTypeEffect, "02_sqeak_ventil_05.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(12138, 90);
	_app->soundAdd(12139, kSoundTypeEffect, "02_sqeak_ventil_06.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(12139, 90);
	_app->soundAdd(12140, kSoundTypeEffect, "02_sqeak_ventil_07.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(12140, 90);
	_app->soundAdd(12141, kSoundTypeEffect, "02_key_lock1.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12142, kSoundTypeEffect, "02_key_lock2.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12143, kSoundTypeEffect, "02_electricity.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12144, kSoundTypeEffect, "02_Take_key_pec.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12145, kSoundTypeEffect, "02_book_take.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12146, kSoundTypeEffect, "02_key_take.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12147, kSoundTypeEffect, "02_key_lock_wrong.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(12133, kSoundTypeAmbientEffect, "02_water_running.wav", _app->getConfiguration().backgroundMusic.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->rotationAdd3DSound(12004, 12133, 1, 1, 15, 100, 85.0f, 10);
	_app->rotationAdd3DSound(12003, 12133, 1, 1, 15, 95, 41.0f, 10);
	_app->rotationAdd3DSound(12002, 12133, 1, 1, 15, 85, 15.0f, 10);
	_app->rotationAdd3DSound(12001, 12133, 1, 1, 15, 80, 12.0f, 10);
	_app->rotationSet3DSoundOff(12001, 12133);
	_app->rotationSet3DSoundOff(12002, 12133);
	_app->rotationSet3DSoundOff(12003, 12133);
	_app->rotationSet3DSoundOff(12004, 12133);
	_app->puzzleAdd3DSound(12006, 12133, 1, 1, 15, 95, 270.0f, 10);
	_app->puzzleAdd3DSound(12007, 12133, 1, 1, 15, 95, 270.0f, 10);
	_app->puzzleAdd3DSound(12004, 12133, 1, 1, 15, 85, 180.0f, 10);
	_app->puzzleAdd3DSound(12005, 12133, 1, 1, 15, 85, 180.0f, 10);
	_app->puzzleAdd3DSound(12008, 12133, 1, 1, 15, 90, 250.0f, 10);
	_app->puzzleAdd3DSound(12009, 12133, 1, 1, 15, 90, 250.0f, 10);
	_app->puzzleAdd3DSound(12010, 12133, 1, 1, 15, 90, 250.0f, 10);
	_app->puzzleAdd3DSound(12011, 12133, 1, 1, 15, 83, 250.0f, 10);
	_app->puzzleAdd3DSound(12002, 12133, 1, 1, 15, 83, 250.0f, 10);
	_app->puzzleAdd3DSound(12001, 12133, 1, 1, 15, 80, 250.0f, 10);
	_app->puzzleSet3DSoundOff(12006, 12133);
	_app->puzzleSet3DSoundOff(12007, 12133);
	_app->puzzleSet3DSoundOff(12004, 12133);
	_app->puzzleSet3DSoundOff(12005, 12133);
	_app->puzzleSet3DSoundOff(12008, 12133);
	_app->puzzleSet3DSoundOff(12009, 12133);
	_app->puzzleSet3DSoundOff(12010, 12133);
	_app->puzzleSet3DSoundOff(12011, 12133);
	_app->puzzleSet3DSoundOff(12002, 12133);
	_app->puzzleSet3DSoundOff(12001, 12133);
	_app->soundAdd(12001, kSoundTypeDialog, "E01_02_1Lil.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12002, kSoundTypeDialog, "E01_02_2Jod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12003, kSoundTypeDialog, "E01_02_3Lil.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12004, kSoundTypeDialog, "E01_03_1Jod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12005, kSoundTypeDialog, "E01_03_2Lil.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12006, kSoundTypeDialog, "E01_03_3Jod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12008, kSoundTypeDialog, "E01_04_1Lil.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12009, kSoundTypeDialog, "E01_04_2Jod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12010, kSoundTypeDialog, "E01_04_3Lil.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12011, kSoundTypeDialog, "E01_04_4Jod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12012, kSoundTypeDialog, "E01_05_Lil.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12013, kSoundTypeDialog, "E01_06_Jod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12014, kSoundTypeDialog, "E01_08_1Jod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12015, kSoundTypeDialog, "E01_08_2Lil.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12016, kSoundTypeDialog, "E01_08_3Jod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12017, kSoundTypeDialog, "E01_10_1Jod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12018, kSoundTypeDialog, "E01_10_2Lil.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12019, kSoundTypeDialog, "E01_10_3Jod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12020, kSoundTypeDialog, "E01_11_Jod.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12022, kSoundTypeDialog, "E01_07_Title.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12023, kSoundTypeDialog, "E01_09_Title.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12024, kSoundTypeDialog, "load.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(12025, kSoundTypeDialog, "preferenc.WAC", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->varDefineByte(12001, 0);
	_app->varDefineByte(12002, -1);
	_app->varDefineByte(12003, 0);
	_app->varDefineByte(12004, 0);
	_app->varDefineByte(12005, 0);
	_app->varDefineByte(12006, 0);
	_app->varDefineByte(12007, 0);
	_app->varDefineByte(12008, 0);
	_app->varDefineByte(12009, 0);
	_app->varDefineByte(12010, 0);
	_app->varDefineByte(12011, 0);
	_app->varDefineByte(12012, 0);
	_app->varDefineByte(12013, 0);
	_app->varDefineByte(12014, 0);
	_app->varDefineByte(12015, 0);
	_app->varDefineWord(12001, 208);
	_app->varDefineWord(12002, 169);
	_app->varDefineWord(12003, 1);
	_app->varDefineWord(12004, 0);
	_app->varDefineWord(12005, 0);
	_app->varDefineWord(12006, 0);
	_app->varDefineDword(12001, 0);
	_app->varDefineFloat(12001, 0.0f);
	_app->varDefineFloat(12002, 0.0f);
	_app->varDefineFloat(12003, 0.0f);
	_app->varDefineFloat(12004, 0.0f);
	_app->varDefineFloat(12005, 1.0f);
	_app->varDefineFloat(12007, 0.0f);
	_app->varDefineString(12001, "000");
}

void Zone3Faust::onSetup(SetupType type) {
	switch (type) {
	default:
		break;

	case kSetupType1:
		_app->timerStopAll();
		_app->bagRemoveAll();
		_app->bagAdd(13899);
		_app->setSpace(kZone14);
		_app->playMovie("A11S02_E02M01");
		_app->fadeOut(15, Color(0, 0, 0), 0);
		_app->rotationSetAlp(111101, 180.0f);
		_app->rotationSetBet(111101, 0.0f);
		_app->rotationSetRan(111101, 87.0f);
		_app->rotationSetActive(111101);
		_app->displayFade("a11_black.bmp", "a11s01n01p01.bmp", 15, 0, kLoadFromCd, kArchiveArt);
		_app->objectPresentationShow(kObject25, 1);
		_app->timerStart(kTimer0, 12000);
		break;

	case kSetupType3:
		_app->timerStopAll();
		_app->setSpace(kZone10);

		// FAUST.EXE 0x4abe6d sets the progress animation frame (0x4dc040), it doesn't save
		if (_app->getSaveManager()->getData()->progressState == kProgressState2)
			_app->getSaveManager()->getData()->progress = 18;

		_app->bagAdd(13899);
		_app->bagAdd(13129);
		_app->bagAdd(97001);
		_app->varSetByte(97001, 1);
		_app->rotationSetAlp(71006, 90.0f);
		_app->rotationSetBet(71006, 20.0f);
		_app->rotationSetRan(71006, 87.0f);
		_app->rotationSetActive(71006);
		_app->displayFade("a07_black.bmp", "a07s01n06p01.bmp", 15, 0, kLoadFromCd, kArchiveArt);
		_app->objectPresentationShow(kObject71201, 2);
		_app->objectPresentationShow(kObject71201, 3);
		_app->timerStart(kTimer0, 200);
		break;

	case kSetupType99:
		_app->timerStopAll();
		_app->bagRemoveAll();
		_app->setSpace(kZone14);
		_app->bagAdd(112021);
		_app->bagAdd(114501);
		_app->bagAdd(112025);
		_app->bagAdd(24);
		_app->bagAdd(112029);
		_app->bagAdd(112026);
		_app->bagAdd(114504);
		_app->bagAdd(114514);
		_app->bagAdd(114518);
		_app->bagAdd(21);
		_app->bagAdd(112020);
		_app->bagAdd(114511);
		_app->bagAdd(112013);
		_app->bagAdd(112601);
		_app->bagAdd(112602);
		_app->bagAdd(112603);
		_app->bagAdd(112604);
		_app->bagAdd(112605);
		_app->bagAdd(112606);
		_app->bagAdd(112607);
		_app->bagAdd(112608);
		_app->bagAdd(112609);
		_app->bagAdd(112610);
		_app->sub_460280();
		_app->rotationSetActive(111301);
		break;

	case kSetupType30000:
		switch (_app->getChapterIndex())
		{
		default:
			break;

		case 6:
			_app->setCurrentZone(kZone14);
			_app->playMovie("A11S02_E02M02");
			break;

		case 7:
			_app->setCurrentZone(kZone14);
			_app->playMovie("A11S02_E02M06");
			break;
		}

		_app->setCurrentZone(kZoneSY);
		_app->soundPlay(90001, kSoundLoop);
		_app->puzzleSetActive(kPuzzleGeneralMenu);
		break;
	}
}

// FAUST.EXE 0x4aa6d0
void Zone3Faust::onTimer(TimerId id) {
	switch (id) {
	default:
		break;

	case kTimer0:
		if (_app->varGetFloat(12004) == 0.0f) {
			_app->timerStop(kTimer0);
			_app->objectPresentationHide(kObject12028);
			_app->objectPresentationHide(kObject16);

			if (_app->varGetByte(12004) == 0) {
				_app->playMovie("A01S02N03P03A01");
				_app->objectPresentationShow(kObject12009, 0);
				_app->objectSetAccessibilityOn(kObject12009, 2, 2);
			} else {
				_app->playMovie("A01S02N03P03A02");
				_app->objectPresentationShow(kObject12009, 0);
				_app->objectPresentationShow(kObject12009, 1);
			}
			break;
		}

		_app->varSetFloat(12004, floor(_app->varGetFloat(12004)) - 1.0f);
		_app->objectPresentationHide(kObject12028);
		_app->objectPresentationShow(kObject12028, (uint32)_app->varGetFloat(12004));
		_app->soundPlay(12114, kSoundOnce);
		break;

	case kTimer1:
		_app->objectPresentationUnpauseAnimation(kObject12031, 0);
		_app->objectPresentationShow(kObject12031, 1);
		_app->objectSetAccessibilityOn(kObject12032, 0, 0);
		_app->objectSetAccessibilityOn(kObject12031, 0, 0);
		_app->timerStop(kTimer1);
		break;

	case kTimer2:
		if (!_app->bagHas(kObjectLotteryTicket) || !_app->bagHas(kObjectTooth) || !_app->bagHas(kObjectButcherKnife))
			break;

		if (_app->varGetByte(12013) != 1)
			break;

		_app->soundStop(12201, 1024);
		_app->objectPresentationHide(kObject16);

		// Sets the progress animation frame (0x4dc040), it doesn't save
		if (_app->getSaveManager()->getData()->progressState == kProgressState1)
			_app->getSaveManager()->getData()->progress = 3;

		_app->playMovie("A01S02_E01M05");
		_app->displayFade("a01s02_e01m05.bmp", "a01_black.bmp", 12, 0, kLoadFromCd, kArchiveArt);
		_app->timerStopAll();
		_app->setupZone(kZone2, kSetupType2);
		break;

	case kTimer3:
		_app->timerStop(kTimer3);
		_app->objectPresentationHide(kObject12039, 0);
		_app->timerStart(kTimer4, 30);
		break;

	case kTimer4:
		_app->timerStop(kTimer4);
		_app->objectPresentationShow(kObject12039, 0);
		_app->timerStart(kTimer5, 60);
		break;

	case kTimer5:
		_app->timerStop(kTimer5);
		_app->objectPresentationHide(kObject12039, 0);
		break;

	case kTimer6:
		_app->timerStop(kTimer6);
		_app->objectPresentationHide(kObject12034, 0);
		break;

	case kTimer7:
		_app->timerStop(kTimer7);
		_app->objectPresentationHide(kObject12034, 1);
		break;

	case kTimer8: {
		int32 alp = (int32)(_app->rotationGetAlp(12001) - 186.0f);
		if (alp <= 0 || alp >= 96)
			break;

		_app->objectPresentationSetAnimationActiveFrame(kObject12040, 0, (uint32)CLIP<int32>((int32)(alp * 0.625), 0, 60));
		break;
	}

	case kTimer9:
		_app->objectPresentationHide(kObject16);
		_app->timerStop(kTimer9);
		break;
	}
}

// FAUST.EXE 0x4a7890
void Zone3Faust::onButtonUp(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, const Common::Point &point) {
	// Objects that accept an item from the bag
	switch (id) {
	default:
		break;

	case kObjectStrainer:
		if (_app->bagHasClickedObject()) {
			if (target == 1 && _app->bagGetClickedObject() == kObjectShovelWithAshes) {
				_app->soundPlay(12130);

				if (_app->varGetByte(12012) == 3) {
					_app->objectPresentationHide(kObjectStrainer, 1);
					_app->objectPresentationShow(kObject12012, 1);
					_app->objectSetAccessibilityOn(kObject12012, 0, 0);
					_app->objectSetAccessibilityOff(kObjectStrainer, 1, 1);
				}

				if (_app->varGetByte(12012) <= 2) {
					_app->objectPresentationHide(kObjectStrainer, 1);
					_app->objectPresentationShow(kObject12018, 1);
					_app->objectSetAccessibilityOn(kObject12018, 0, 0);
					_app->objectSetAccessibilityOff(kObjectStrainer, 1, 1);
				}
			}

			_app->cursorDelete();
			return;
		}

		if (target != 0)
			return;

		_app->objectPresentationShow(kObjectStrainer, 0);
		_app->objectSetAccessibilityOff(kObjectStrainer, 0, 0);
		_app->varSetByte(12011, 1);
		_app->bagAdd(kObjectStrainer);
		_app->soundPlay(12121);
		_app->soundStop(12201, 1024);
		_app->objectPresentationHide(kObject16);
		_app->playMovie("A02S01_E01M04");
		_app->soundPlay(12201, kSoundLoop);
		return;

	case kObject12007:
		// Ash pit: dig with the shovel (targets 1-3), or pick up the burned key (target 0)
		if (_app->bagHasClickedObject()) {
			if (_app->bagGetClickedObject() == kObjectAshShovel) {
				_app->varSetByte(12012, (int8)target);
				_app->objectPresentationHide(kObject12007, target);
				_app->objectSetAccessibilityOff(kObject12007, target, target);
				_app->bagRemove(kObjectAshShovel);
				_app->bagAdd(kObjectShovelWithAshes);
				_app->soundPlay(12129);

				if (target == 3)
					_app->objectSetAccessibilityOn(kObject12007, 0, 0);
			}

			_app->cursorDelete();
			return;
		}

		if (target != 0)
			return;

		_app->bagAdd(kObjectBurnedKey);
		_app->soundPlay(12129);
		_app->objectPresentationHide(kObject12007, 0);
		_app->objectSetAccessibilityOff(kObject12007, 0, 0);
		return;

	case kObject12034:
		// Two keyholes: burned key and bronze key
		if (_app->bagHasClickedObject()) {
			if (target == 0) {
				if (_app->bagGetClickedObject() == kObjectBurnedKey) {
					_app->objectPresentationShow(kObject12034, 0);
					_app->bagRemove(kObjectBurnedKey);
					_app->varSetByte(12006, 1);
					_app->soundPlay(12141);
				} else if (_app->bagGetClickedObject() == kObjectBronzeKey) {
					_app->soundPlay(12147);
					_app->objectPresentationShow(kObject12034, 0);
					_app->timerStart(kTimer6, 200);
				}
			} else if (target == 1) {
				if (_app->bagGetClickedObject() == kObjectBronzeKey) {
					_app->objectPresentationShow(kObject12034, 1);
					_app->bagRemove(kObjectBronzeKey);
					_app->varSetByte(12005, 1);
					_app->soundPlay(12142);
				} else if (_app->bagGetClickedObject() == kObjectBurnedKey) {
					_app->soundPlay(12147);
					_app->objectPresentationShow(kObject12034, 1);
					_app->timerStart(kTimer7, 200);
				}
			}

			if (_app->varGetByte(12006) == 1 && _app->varGetByte(12005) == 1) {
				_app->objectPresentationHide(kObject16);
				_app->playMovie("A01S02N03P01A01");
				_app->puzzleSetActive(kPuzzle12008);
			}

			_app->cursorDelete();
			return;
		}

		if (target == 0) {
			if (_app->varGetByte(12006) == 1) {
				_app->objectPresentationHide(kObject12034, 0);
				_app->bagAdd(kObjectBurnedKey);
				_app->varSetByte(12006, 0);
			}
		} else if (target == 1) {
			if (_app->varGetByte(12005) == 1) {
				_app->objectPresentationHide(kObject12034, 1);
				_app->bagAdd(kObjectBronzeKey);
				_app->varSetByte(12005, 0);
			}
		}
		return;
	}

	// Every other object rejects bag items
	if (_app->bagHasClickedObject()) {
		_app->cursorDelete();
		return;
	}

	switch (id) {
	default:
		break;

	case kObjectAshShovel:
		_app->objectPresentationShow(kObjectAshShovel, 0);
		_app->objectPresentationShow(kObject12007, 4);
		_app->objectSetAccessibilityOff(kObjectAshShovel, 0, 0);
		_app->bagAdd(kObjectAshShovel);
		_app->soundPlay(12128);
		_app->objectPresentationHide(kObjectStrainer, 1);
		_app->objectSetAccessibilityOff(kObjectStrainer, 1, 1);
		break;

	case kObject12003:
		switch (target) {
		default:
			break;

		case 0:
		case 4: {
			// Remember the view so that target 5 can restore it
			Id rotationId = _app->getCurrentRotationId();
			_app->varSetWord(12004, (int16)rotationId);
			_app->varSetWord(12005, (int16)_app->rotationGetAlp(rotationId));
			_app->varSetWord(12006, (int16)_app->rotationGetBet(rotationId));

			if (_app->getCurrentRotationId() == 12001)
				_app->objectPresentationShow(kObject12003, 0);

			if (_app->getCurrentRotationId() == 12002)
				_app->objectPresentationShow(kObject12003, 4);

			_app->soundPlay(12101);
			break;
		}

		case 1:
			_app->objectPresentationShow(kObject12003, 2);
			_app->soundPlay(12145);
			_app->soundPlay(12017);
			_app->objectSetAccessibilityOff(kObject12003, 1, 2);
			_app->objectSetAccessibilityOn(kObject12003, 3, 3);
			_app->objectSetAccessibilityOn(kObject12036, 1, 1);
			break;

		case 2:
			_app->objectPresentationShow(kObject12003, 1);
			_app->soundPlay(12145);
			_app->soundPlay(12014);
			_app->objectSetAccessibilityOff(kObject12003, 1, 2);
			_app->objectSetAccessibilityOn(kObject12003, 3, 3);
			_app->objectSetAccessibilityOn(kObject12036, 0, 0);
			break;

		case 3:
			_app->objectPresentationHide(kObject12003, 2);
			_app->objectPresentationHide(kObject12003, 1);
			_app->objectSetAccessibilityOn(kObject12003, 1, 2);
			_app->objectSetAccessibilityOff(kObject12003, 3, 3);
			_app->objectSetAccessibilityOff(kObject12036, 0, 1);
			_app->soundStop(12014, 1024);
			_app->soundStop(12015, 1024);
			_app->soundStop(12016, 1024);
			_app->soundStop(12017, 1024);
			_app->soundStop(12018, 1024);
			_app->soundStop(12019, 1024);
			break;

		case 5: {
			Id rotationId = _app->varGetWord(12004);
			_app->rotationSetAlp(rotationId, (float)_app->varGetWord(12005));
			_app->rotationSetBet(rotationId, (float)_app->varGetWord(12006));
			_app->rotationSetRan(rotationId, 87.0f);
			_app->rotationSetActive(rotationId);

			if (_app->varGetWord(12004) == 12001)
				_app->objectPresentationShow(kObject12003, 3);

			if (_app->varGetWord(12004) == 12002)
				_app->objectPresentationShow(kObject12003, 5);

			_app->soundPlay(12102);
			break;
		}
		}
		break;

	case kObject12004:
		_app->objectPresentationShow(kObject12004, 0);
		_app->soundPlay(12103);
		break;

	case kObject12005:
		if (target == 0) {
			if (_app->varGetByte(12002) != -1) {
				_app->objectPresentationUnpauseAnimation(kObject12006, (uint32)_app->varGetByte(12002));
				_app->soundPlay(12112);
				_app->varSetByte(12002, -1);
				_app->objectPresentationHide(kObject12006);
			}

			_app->objectSetAccessibilityOff(kObject12006);
			_app->objectSetAccessibilityOff(kObject12005, 0, 0);
			_app->objectSetAccessibilityOff(kObject12005, 1, 1);
			_app->objectPresentationShow(kObject12005, 0);
			_app->soundSetVolume(12105, 91 + rnd(10));
			_app->soundPlay(12105);
		} else if (target == 1 || target == 2) {
			_app->objectSetAccessibilityOff(kObject12005, 0, 2);
			_app->objectPresentationShow(kObject12005, 1);
			_app->soundSetVolume(12106, 91 + rnd(10));
			_app->soundPlay(12106);
		} else if (target == 3) {
			_app->soundPlay(12004);
		}
		break;

	case kObject12006:
		if (target <= 3) {
			_app->objectSetAccessibilityOff(kObject12006);
			_app->objectPresentationShow(kObject12006, target);
			_app->soundPlay(12111);
			_app->varSetByte(12002, (int8)target);
		} else if (target == 4) {
			_app->objectSetAccessibilityOff(kObject12006);
			_app->objectPresentationHide(kObject12006);
			_app->objectPresentationShow(kObject12006, (uint32)(_app->varGetByte(12002) + 4));
			_app->soundPlay(12112);
		}
		break;

	case kObject12009:
		if (target == 0 || target == 3)
			_app->puzzleSetActive(kPuzzle12010);

		if (target == 1) {
			_app->puzzleSetActive(kPuzzle12009);
			_app->objectPresentationHide(kObject12025);
			_app->objectPresentationHide(kObject12026);
			_app->varSetFloat(12002, 0.0f);
			_app->varSetFloat(12003, 0.0f);
			_app->soundPlay(12020);
			break;
		}

		if (target != 2)
			break;

		// Lottery ticket
		_app->objectSetAccessibilityOff(kObject12009, 2, 2);
		_app->objectPresentationShow(kObject12009, 1);
		_app->bagAdd(kObjectLotteryTicket);

		// Advances the progress animation frame (0x4dc040), it doesn't save
		if (_app->getSaveManager()->getData()->progressState == kProgressState1)
			_app->getSaveManager()->getData()->progress++;

		_app->varSetByte(98012, 1);
		_app->objectPresentationHide(kObject16);
		_app->playMovie("a01s02_e01m05c");
		_app->timerStart(kTimer2, 3000);
		_app->objectPresentationHide(kObject16);
		_app->playMovie("a01s02n03p01a02");
		_app->rotationSetActive(12002);
		_app->varSetByte(12004, 1);
		_app->objectPresentationHide(kObject12025);
		_app->objectPresentationHide(kObject12026);
		_app->varSetFloat(12002, 0.0f);
		_app->varSetFloat(12003, 0.0f);
		_app->objectPresentationHide(kObject12028);
		_app->objectPresentationHide(kObject12009);
		_app->varSetFloat(12004, 0.0f);
		_app->varSetString(12001, "000000");
		_app->objectSetAccessibilityOn(kObject12028, 0, 0);
		_app->objectSetAccessibilityOff(kObject12009, 2, 2);
		_app->objectPresentationHide(kObject12034, 0);
		_app->bagAdd(kObjectBurnedKey);
		_app->varSetByte(12006, 0);
		_app->objectPresentationHide(kObject12034, 1);
		_app->bagAdd(kObjectBronzeKey);
		_app->varSetByte(12005, 0);
		break;

	case kObject12010:
		if (target == 0) {
			_app->soundPlay(12108);
			_app->objectPresentationShow(kObject12010, _app->varGetByte(12003) == 0 ? 2 : 0);
			_app->objectSetAccessibilityOff(kObject12010);
		} else if (target == 1) {
			_app->objectSetAccessibilityOff(kObject12010, 1, 1);
			_app->objectPresentationHide(kObject12010, 7);
			_app->objectPresentationShow(kObject12010, 6);
			_app->varSetByte(12003, 1);
			_app->soundPlay(12146);
			_app->bagAdd(kObjectBronzeKey);
		} else if (target == 2) {
			_app->soundPlay(12108);
			_app->objectSetAccessibilityOff(kObject12010);
			_app->objectPresentationShow(kObject12010, _app->varGetByte(12003) == 0 ? 3 : 1);
		}
		break;

	case kObject12011:
		_app->soundStop(12201, 1024);
		_app->objectPresentationHide(kObject16);
		_app->playMovie("A01S02_E01M03");
		_app->soundPlay(12201, kSoundLoop);

		// Advances the progress animation frame (0x4dc040), it doesn't save
		if (_app->varGetByte(12013) == 0 && _app->getSaveManager()->getData()->progressState == kProgressState1)
			_app->getSaveManager()->getData()->progress++;

		_app->varSetByte(12013, 1);
		_app->timerStart(kTimer2, 500);
		break;

	case kObject12013:
		_app->sub_4AC4E0(1);
		break;

	case kObject12019: {
		// Close-ups: return to the current view when leaving the puzzle
		static const PuzzleId puzzles[4] = { kPuzzle12004, kPuzzle12005, kPuzzle12006, kPuzzle12007 };
		static const Id sounds[4] = { 12012, 12013, 12012, 12013 };

		if (target > 3)
			break;

		Id rotationId = _app->getCurrentRotationId();
		_app->puzzleSetMovabilityToRotation(puzzles[target], 0, _app->rotationGetAlp(rotationId), _app->rotationGetBet(rotationId), 87.0f);
		_app->puzzleSetActive(puzzles[target]);
		_app->soundPlay(sounds[target]);
		break;
	}

	case kObject12020:
		_app->soundPlay(12001);
		break;

	case kObject12021:
		_app->soundPlay(12024 + rnd(2));
		_app->objectPresentationShow(kObject16);
		_app->timerStart(kTimer9, 4000);
		break;

	case kObject12022:
		_app->soundPlay(12008);
		break;

	case kObject12024:
		if (_app->varGetByte(12015) == 0) {
			_app->varSetByte(12015, 1);
			_app->objectPresentationShow(kObject12039, 0);
			_app->soundPlay(12143);
			_app->timerStart(kTimer3, 100);
			break;
		}

		_app->soundStop(12201, 1024);
		_app->objectPresentationHide(kObject16);
		_app->playMovie("A01S01_E01M02");
		_app->soundPlay(12201, kSoundLoop);
		break;

	case kObject12030:
		if (target != 0 && target != 1)
			break;

		_app->objectPresentationShow(kObject12030, target);
		_app->objectSetAccessibilityOff(kObject12030, target, target);
		_app->soundPlay(12119);
		break;

	case kObject12031:
		if (_app->varGetByte(12007) == 0) {
			_app->objectPresentationShow(kObject12031, 2);
			_app->soundPlay(12117);
		} else {
			_app->objectPresentationShow(kObject12031, 0);
			_app->soundPlay(12116);
			_app->objectSetAccessibilityOff(kObject12032, 0, 0);
			_app->objectSetAccessibilityOff(kObject12031, 0, 0);
		}
		break;

	case kObject12032:
		if (target == 0) {
			_app->soundPlay(12123);
			_app->objectPresentationShow(kObject12032, _app->varGetByte(12007) == 0 ? 0 : 2);
			_app->varSetByte(12009, 1);
			_app->objectSetAccessibilityOff(kObject12032, 0, 0);
			_app->objectSetAccessibilityOff(kObject12031, 0, 0);
		} else if (target == 1) {
			_app->soundPlay(12122);

			if (_app->varGetByte(12007) == 0) {
				_app->objectPresentationHide(kObject12032, 5);
				_app->objectPresentationShow(kObject12032, 1);
			} else {
				_app->objectPresentationHide(kObject12032, 4);
				_app->objectPresentationShow(kObject12032, 3);
			}

			_app->varSetByte(12009, 0);
			_app->objectSetAccessibilityOn(kObject12032, 0, 0);
			_app->objectSetAccessibilityOff(kObject12032, 1, 1);
			_app->objectSetAccessibilityOn(kObject12031, 0, 0);
		}
		break;

	case kObjectButcherKnife:
		if (_app->varGetByte(12007) != 0)
			break;

		_app->objectPresentationHide(kObject12032, 5);
		_app->objectPresentationShow(kObject12032, 4);
		_app->varSetByte(12007, 1);
		_app->objectSetAccessibilityOff(kObjectButcherKnife, 0, 0);
		_app->bagAdd(kObjectButcherKnife);
		_app->objectPresentationHide(kObject16);
		_app->playMovie("a01s02_e01m05a");

		// Advances the progress animation frame (0x4dc040), it doesn't save
		if (_app->getSaveManager()->getData()->progressState == kProgressState1)
			_app->getSaveManager()->getData()->progress++;

		_app->timerStart(kTimer2, 3000);
		break;

	case kObject12038: {
		// Light switch: toggles the 3D sound 12133 everywhere in the zone
		static const Id rotations[4] = { 12001, 12002, 12003, 12004 };
		static const PuzzleId puzzles[10] = { kPuzzle12006, kPuzzle12007, kPuzzle12004, kPuzzle12005, kPuzzle12008,
		                                      kPuzzle12009, kPuzzle12010, kPuzzle12011, kPuzzle12002, kPuzzle12001 };

		if (target == 1) {
			_app->soundPlay(12134 + rnd(7));
			_app->soundPlay(12131 + rnd(2));
			break;
		}

		if (target != 0)
			break;

		bool on = (_app->varGetByte(12014) == 0);
		_app->varSetByte(12014, on ? 1 : 0);

		if (on)
			_app->objectPresentationShow(kObject12038, 0);
		else
			_app->objectPresentationHide(kObject12038, 0);

		_app->soundPlay(12134 + rnd(7));

		for (uint i = 0; i < ARRAYSIZE(rotations); i++) {
			if (on)
				_app->rotationSet3DSoundOn(rotations[i], 12133);
			else
				_app->rotationSet3DSoundOff(rotations[i], 12133);
		}

		for (uint i = 0; i < ARRAYSIZE(puzzles); i++) {
			if (on)
				_app->puzzleSet3DSoundOn(puzzles[i], 12133);
			else
				_app->puzzleSet3DSoundOff(puzzles[i], 12133);
		}
		break;
	}
	}
}

// FAUST.EXE 0x4aaa60
void Zone3Faust::onAnimationNextFrame(Id animationId, const Common::String &name, uint32 frame, uint32 frameCount) {
	switch (animationId) {
	default:
		break;

	case 12001:
		if (frame == 15)
			_app->puzzleSetActive(kPuzzle12001);
		break;

	case 12002:
		if (frame == 10)
			_app->puzzleSetActive(kPuzzle12002);
		break;

	case 12004:
		if (_app->varGetByte(12010) == 0) {
			if (frame != 10)
				break;

			_app->objectSetAccessibilityOn(kObject12010, 2, 2);
			_app->objectPresentationHide(kObject12010);

			if (_app->varGetByte(12003) == 1) {
				_app->objectPresentationShow(kObject12010, 6);
			} else {
				_app->objectPresentationShow(kObject12010, 7);
				_app->objectSetAccessibilityOn(kObject12010, 2, 2);
				_app->objectSetAccessibilityOn(kObject12010, 1, 1);
			}

			_app->varSetByte(12010, 1);
		} else if (frame == 1) {
			_app->objectPresentationHide(kObject12010);
			_app->objectSetAccessibilityOn(kObject12010, 0, 0);
			_app->varSetByte(12010, 0);
		}
		break;

	case 12006:
		if (frame == 15) {
			_app->objectPresentationPauseAnimation(kObject12005, 0);
			_app->objectSetAccessibilityOn(kObject12005, 1, 3);
			_app->varSetByte(12001, 1);
		}
		break;

	case 12007:
		if (frame == 1) {
			_app->objectPresentationUnpauseAnimation(kObject12005, 0);
			_app->objectSetAccessibilityOn(kObject12005, 0, 0);
			_app->varSetByte(12001, 0);
			_app->objectPresentationHide(kObject12005, 0);
			_app->objectPresentationHide(kObject12005, 1);
			_app->objectSetAccessibilityOn(kObject12006, 0, 3);
		}
		break;

	case 12008:
		if (frame == 10) {
			_app->objectPresentationPauseAnimation(kObject12006, (uint32)(int8)_app->varGetByte(12002));
			_app->objectSetAccessibilityOn(kObject12006, 4, 4);
		}
		break;

	case 12009:
		if (frame == 1) {
			_app->objectPresentationUnpauseAnimation(kObject12006, (uint32)(int8)_app->varGetByte(12002));
			_app->objectSetAccessibilityOn(kObject12006, 0, 3);
			_app->objectPresentationHide(kObject12006);
			_app->varSetByte(12002, -1);
		}
		break;

	case 12010:
		if (frame == 10) {
			_app->objectPresentationPauseAnimation(kObject12031, 0);
			_app->timerStart(kTimer1, 1000);
		}
		break;

	case 12012:
		_app->soundSetVolume(12116, frame + 75);

		if (_app->varGetByte(12008) == 0) {
			if (frame != 15)
				break;

			_app->objectPresentationHide(kObject12030);
			_app->objectPresentationShow(kObject12030, 2);
			_app->varSetByte(12008, 1);
			_app->objectSetAccessibilityOn(kObject12030, 1, 1);
			_app->soundPlay(12126);
		} else if (frame == 1) {
			_app->objectPresentationHide(kObject12030);
			_app->varSetByte(12008, 0);
			_app->objectSetAccessibilityOn(kObject12030, 0, 0);
			_app->soundPlay(12120);
		}
		break;

	case 12013:
		if (frame != 9)
			break;

		_app->objectSetAccessibilityOn(kObject12032, 1, 1);
		_app->soundPlay(12125);
		_app->objectPresentationHide(kObject12032);

		if (_app->varGetByte(12007) == 0) {
			_app->objectPresentationShow(kObject12032, 5);
			_app->objectSetAccessibilityOn(kObjectButcherKnife, 0, 0);
		} else {
			_app->objectPresentationShow(kObject12032, 4);
		}
		break;

	case 12014:
		if (frame == 1)
			_app->soundPlay(12124);
		break;
	}
}

void Zone3Faust::onSound(Id id, SoundType type, uint32 a3, bool process) {
	if (!process)
		return;

	switch (id) {
	default:
		break;

	case 12001:
		_app->soundPlay(12002);
		break;

	case 12002:
		_app->soundPlay(12003);
		break;

	case 12004:
		_app->soundPlay(12005);
		break;

	case 12005:
		_app->soundPlay(12006);
		break;

	case 12008:
		_app->soundPlay(12009);
		break;

	case 12009:
		_app->soundPlay(12010);
		break;

	case 12010:
		_app->soundPlay(12011);
		break;

	case 12014:
		_app->soundPlay(12015);
		break;

	case 12015:
		_app->soundPlay(12016);
		break;

	case 12017:
		_app->soundPlay(12018);
		break;

	case 12018:
		_app->soundPlay(12019);
		break;

	case 12024:
	case 12025:
		_app->objectPresentationHide(kObject16);
		break;
	}
}

// FAUST.EXE 0x4a8fb0
void Zone3Faust::onBag(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, DragControl *dragControl, byte type) {
	switch (id) {
	default:
		break;

	case kObject12012:
	case kObject12018: {
		// Scrubbing: the shovel (12018) and the strainer (12012) are rubbed until frame 13
		bool isStrainer = (id == kObject12012);
		Id soundId = isStrainer ? 12110 : 12109;

		switch (type) {
		default:
			break;

		case 1:
			_app->cursorDelete();
			_app->dragControlSetField45(2);
			_app->objectPresentationShow(id, (uint32)_app->varGetWord(12003));
			_app->soundPlay(soundId, kSoundLoop);
			_app->soundSetVolume(soundId, 0);
			break;

		case 2:
			_app->soundStop(soundId, 1024);

			if (_app->varGetWord(12003) < 13)
				break;

			_app->varSetWord(12001, 208);
			_app->varSetWord(12002, 169);
			_app->varSetWord(12003, 1);
			_app->varSetFloat(12001, 0.0f);
			_app->objectPresentationHide(id);
			_app->objectSetAccessibilityOff(id);

			if (isStrainer) {
				_app->bagAdd(kObjectTooth);
				_app->objectPresentationHide(kObject16);
				_app->playMovie("a01s02_e01m05b");
				_app->timerStart(kTimer2, 3000);
			}

			_app->bagAdd(kObjectStrainer);
			_app->bagAdd(kObjectAshShovel);
			_app->bagRemove(kObjectShovelWithAshes);
			break;

		case 3:
			if (!_app->dragControlXLower() && !_app->dragControlXHigher() && !_app->dragControlYLower() && !_app->dragControlYHigher())
				break;

			if (_app->varGetWord(12003) < 14) {
				// The original uses the unrounded distance
				float dx = (float)dragControl->getOffsetX();
				float dy = (float)dragControl->getOffsetY();
				_app->varSetFloat(12001, sqrt(dx * dx + dy * dy) * 0.05f);

				_app->objectPresentationHide(id, (uint32)_app->varGetWord(12003));
				_app->varSetWord(12003, (int16)((float)_app->varGetWord(12003) + _app->varGetFloat(12001)));
				if (_app->varGetWord(12003) > 13)
					_app->varSetWord(12003, 13);
				_app->objectPresentationShow(id, (uint32)_app->varGetWord(12003));

				_app->varSetFloat(12007, (float)(_app->varGetFloat(12001) * 10.0 + 70.0 - _app->varGetWord(12003)));
				_app->soundSetVolume(soundId, (uint32)(int32)_app->varGetFloat(12007));
			}

			// The original checks both axes for the strainer but either one for the shovel
			bool still = isStrainer ? (_app->dragControlYEqual() && _app->dragControlXEqual())
			                        : (_app->dragControlYEqual() || _app->dragControlXEqual());
			if (still) {
				_app->varSetFloat(12007, 0.0f);
				_app->soundSetVolume(soundId, (uint32)(int32)_app->varGetFloat(12007));
			}

			if (_app->dragControlXLower())
				_app->varSetWord(12001, _app->varGetWord(12001) - (int16)_app->dragControlGetOffsetX());
			if (_app->dragControlXHigher())
				_app->varSetWord(12001, _app->varGetWord(12001) + (int16)_app->dragControlGetOffsetX());
			if (_app->dragControlYLower())
				_app->varSetWord(12002, _app->varGetWord(12002) - (int16)_app->dragControlGetOffsetY());
			if (_app->dragControlYHigher())
				_app->varSetWord(12002, _app->varGetWord(12002) + (int16)_app->dragControlGetOffsetY());

			_app->objectPresentationSetImageCoordinatesOnPuzzle(id, (uint32)_app->varGetWord(12003), Common::Point(_app->varGetWord(12001), _app->varGetWord(12002)));
			break;
		}
		break;
	}

	case kObject12027: {
		// Two sliders (target 0 and 1) driving presentations 12025 and 12026
		if (target != 0 && target != 1)
			break;

		Id varId = (target == 0) ? 12002 : 12003;
		ObjectId presentationId = (target == 0) ? kObject12025 : kObject12026;

		switch (type) {
		default:
			break;

		case 1:
			_app->cursorDelete();
			_app->dragControlSetField45(2);
			_app->soundPlay(12113, kSoundLoop);
			_app->soundSetVolume(12113, 0);
			_app->soundSetPan(12113, (target == 0) ? -5 : 5);
			break;

		case 2:
			_app->soundStop(12113, 1024);
			break;

		case 3: {
			// Dragging left raises the first slider but lowers the second one
			double delta = _app->dragControlGetOffsetX() * 0.07518796992481203;
			if (target == 1)
				delta = -delta;

			if (_app->dragControlXLower())
				_app->varSetFloat(varId, (float)(_app->varGetFloat(varId) + delta));
			if (_app->dragControlXHigher())
				_app->varSetFloat(varId, (float)(_app->varGetFloat(varId) - delta));

			if (_app->varGetFloat(varId) < 0.0f)
				_app->varSetFloat(varId, 0.0f);
			if (_app->varGetFloat(varId) > 15.0f)
				_app->varSetFloat(varId, 14.0f);

			_app->objectPresentationHide(presentationId);
			_app->objectPresentationShow(presentationId, (uint32)(int32)_app->varGetFloat(varId));

			if (target == 0) {
				if (_app->varGetFloat(varId) > 10.0f)
					_app->objectSetAccessibilityOn(kObject12009, 1, 1);
				else
					_app->objectSetAccessibilityOff(kObject12009, 1, 1);
			}

			if (_app->dragControlYEqual() || _app->dragControlXEqual())
				_app->soundSetVolume(12113, 0);
			else
				_app->soundSetVolume(12113, (uint32)((int32)_app->dragControlGetOffsetX() / 2 + 70));
			break;
		}
		}
		break;
	}

	case kObject12028:
		// Combination dial: 10 digits, 4 frames apart
		switch (type) {
		default:
			break;

		case 1:
			_app->dragControlSetHotspot(Common::Rect(207, 132, 442, 349));
			_app->dragControlSetCoords1(Common::Point(317, 233));
			break;

		case 2: {
			float position = _app->varGetFloat(12004);
			int32 frame = (int32)floor(position);
			if (frame < 0 || frame > 36 || (frame % 4) != 0)
				break;

			// Digit for exact positions only, 0 otherwise
			int32 digit = 0;
			if (position == (float)frame)
				digit = frame / 4;

			_app->soundPlay(12115);

			// Shift the digit in from the right
			Common::String code = _app->varGetString(12001);
			code = Common::String(code.c_str() + MIN<uint32>(1, code.size())).substr(0, 2) + Common::String::format("%d", digit);
			_app->varSetString(12001, code);

			if (code == "512") {
				_app->objectSetAccessibilityOff(kObject12028, 0, 0);
				_app->soundPlay(12121);
				_app->timerStart(kTimer0, 50);
			}
			break;
		}

		case 3: {
			int32 frame = ApplicationFaust::getDragAngle(dragControl) * 39 / 360;
			_app->objectPresentationHide(kObject12028);
			_app->objectPresentationShow(kObject12028, (uint32)frame);
			_app->soundSetVolume(12114, 91 + rnd(10));

			if (!_app->dragControlYEqual() && !_app->dragControlXEqual())
				_app->soundPlay(12114);

			_app->varSetFloat(12004, (float)frame);
			break;
		}
		}
		break;
	}
}

void Zone3Faust::onUpdateBag(const Common::Point &point) {
	_app->soundStop(_app->varGetDword(12001), 1024);
	_app->varSetDword(12001, 0);
}

void Zone3Faust::onBagClickedObject(ObjectId id) {
	if (id == kObjectStrainer) {
		if (_app->hasCurrentPuzzle() && _app->getCurrentPuzzleId() == kPuzzle12001) {
			_app->objectPresentationShow(kObjectStrainer, 1);
			_app->objectSetAccessibilityOn(kObjectStrainer, 1, 1);
			_app->cursorDelete();
		}
	}
}

void Zone3Faust::onUpdateBefore(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, const Common::Point &point) {
	if (movabilityFrom == 12036 && !_app->soundIsPlayingType(kSoundTypeDialog)) {
		switch (movabilityTo) {
		default:
			break;

		case 0:
			_app->soundPlay(12022);
			_app->varSetDword(12001, 12022);
			break;

		case 1:
			_app->soundPlay(12023);
			_app->varSetDword(12001, 12023);
			break;
		}
	}
}

// FAUST.EXE has no zone 3 handler (the dispatcher's default just returns)
void Zone3Faust::onBeforeRide(Id, Id, uint32, Id, MovabilityType) {
}

// FAUST.EXE 0x4aa0d0
// The first argument is the new rotation and the second the one (or puzzle) we came from
void Zone3Faust::onAfterRide(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, MovabilityType movabilityType) {
	Id current = movabilityFrom;
	Id previous = movabilityTo;

	if (movabilityType == kMovabilityRotationToRotation) {
		if (current == 12003) {
			if (previous == 12004) {
				_app->objectPresentationHide(kObject12030);
				_app->objectPresentationHide(kObject12031);
				_app->objectPresentationHide(kObject12032);
				_app->objectPresentationHide(kObjectButcherKnife);
				_app->objectSetAccessibilityOn(kObject12030, 0, 0);
				_app->objectSetAccessibilityOff(kObject12030, 1, 1);
				_app->objectSetAccessibilityOn(kObject12031, 0, 0);
				_app->objectSetAccessibilityOn(kObject12032, 0, 0);
				_app->objectSetAccessibilityOff(kObject12032, 1, 1);
				_app->objectSetAccessibilityOff(kObjectButcherKnife, 0, 0);

				if (_app->varGetByte(12008) == 1) {
					_app->varSetByte(12008, 0);
					_app->soundPlay(12119);
				}

				if (_app->varGetByte(12009) == 1) {
					_app->varSetByte(12009, 0);
					_app->soundPlay(12124);
				}
				return;
			}

			if (previous != 12002)
				return;
		} else if (current == 12001) {
			if (previous != 12002)
				return;
		}

		if (current == 12001 || current == 12003) {
			_app->objectPresentationHide(kObject12010);
			_app->objectSetAccessibilityOff(kObject12010);
			_app->objectSetAccessibilityOn(kObject12010, 0, 0);

			if (_app->varGetByte(12010) == 1) {
				_app->varSetByte(12010, 0);
				_app->soundPlay(12108);
			}
		}

		if (current != 12002 || previous != 12001)
			return;

		_app->objectSetAccessibilityOn(kObject12005, 0, 0);
		_app->objectSetAccessibilityOff(kObject12005, 1, 3);
		_app->objectPresentationHide(kObject12005);
		_app->objectSetAccessibilityOn(kObject12006, 0, 3);
		_app->objectSetAccessibilityOff(kObject12006, 4, 4);
		_app->objectPresentationHide(kObject12006);
		_app->objectPresentationUnpauseAnimation(kObject12005, 0);
		_app->objectPresentationUnpauseAnimation(kObject12006, 0);
		_app->objectPresentationUnpauseAnimation(kObject12006, 1);
		_app->objectPresentationUnpauseAnimation(kObject12006, 2);
		_app->objectPresentationUnpauseAnimation(kObject12006, 3);

		if (_app->varGetByte(12001) == 1) {
			_app->varSetByte(12001, 0);
			_app->soundPlay(12106);
		}

		if (_app->varGetByte(12002) != -1) {
			_app->varSetByte(12002, -1);
			_app->soundPlay(12112);
		}
		return;
	}

	if (movabilityType != kMovabilityPuzzleToRotation)
		return;

	if ((current == 12002 || current == 12003) && previous == kPuzzle12008) {
		_app->objectPresentationHide(kObject12025);
		_app->objectPresentationHide(kObject12026);
		_app->varSetFloat(12002, 0.0f);
		_app->varSetFloat(12003, 0.0f);
		_app->objectPresentationHide(kObject12034, 0);
		_app->bagAdd(kObjectBurnedKey);
		_app->varSetByte(12006, 0);
		_app->objectPresentationHide(kObject12034, 1);
		_app->bagAdd(kObjectBronzeKey);
		_app->varSetByte(12005, 0);
		_app->objectPresentationHide(kObject16);
		_app->playMovie("a01s02n03p01a02");
	}

	if ((current == 12002 || current == 12003) && previous == kPuzzle12009) {
		_app->objectPresentationHide(kObject12025);
		_app->objectPresentationHide(kObject12026);
		_app->varSetFloat(12002, 0.0f);
		_app->varSetFloat(12003, 0.0f);
		_app->objectPresentationHide(kObject12028);
		_app->objectPresentationHide(kObject12009);
		_app->varSetFloat(12004, 0.0f);
		_app->varSetString(12001, "000000");
		_app->objectSetAccessibilityOn(kObject12028, 0, 0);
		_app->objectSetAccessibilityOff(kObject12009, 2, 2);
		_app->objectPresentationHide(kObject12034, 0);
		_app->bagAdd(kObjectBurnedKey);
		_app->varSetByte(12006, 0);
		_app->objectPresentationHide(kObject12034, 1);
		_app->bagAdd(kObjectBronzeKey);
		_app->varSetByte(12005, 0);
		_app->objectPresentationHide(kObject16);
		_app->playMovie("a01s02n03p01a02");
	}

	if ((current == 12002 || current == 12003) && previous == kPuzzle12010) {
		if (_app->varGetByte(12006) == 1) {
			_app->objectPresentationHide(kObject12034, 0);
			_app->bagAdd(kObjectBurnedKey);
			_app->varSetByte(12006, 0);
		}

		if (_app->varGetByte(12005) == 1) {
			_app->objectPresentationHide(kObject12034, 1);
			_app->bagAdd(kObjectBronzeKey);
			_app->varSetByte(12005, 0);
		}
	}

	if (current == 12001 && previous == 12001) {
		_app->objectPresentationShow(kObject12004, 1);
		_app->soundPlay(12104);
		_app->varSetWord(12001, 208);
		_app->varSetWord(12002, 169);
		_app->varSetWord(12003, 1);
		_app->varSetFloat(12001, 0.0f);
		_app->objectPresentationHide(kObject12018);
		_app->objectPresentationHide(kObject12012);
		_app->objectPresentationHide(kObjectStrainer, 1);
		_app->objectSetAccessibilityOff(kObject12018);
		_app->objectSetAccessibilityOff(kObject12012);

		if (_app->varGetByte(12011) == 1)
			_app->bagAdd(kObjectStrainer);
	}
}

} // End of namespace Ring
