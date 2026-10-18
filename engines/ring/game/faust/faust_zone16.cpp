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

#include "ring/game/faust/faust_zone16.h"

#include "ring/game/faust/faust_application.h"
#include "ring/game/faust/faust_shared.h"

#include "ring/base/saveload.h"

#include "ring/debug.h"
#include "ring/ring.h"
#include "ring/helpers.h"

using namespace FaustGame;

namespace Ring {

Zone16Faust::Zone16Faust(ApplicationFaust *application) : _app(application) {
}

Zone16Faust::~Zone16Faust() {
	// Zero-out passed pointers
	_app = nullptr;
}

void Zone16Faust::onInit() {
	_app->setCurrentZone(kZone16);

	_app->puzzleAdd(kPuzzle310001);
	_app->puzzleAddBackgroundImage(kPuzzle310001, "a13s02n05p01.bmp", Common::Point(0, 16), true);
	_app->rotationAdd(311111, "A13S01N01R01", 0, 0);
	_app->rotationAdd(311211, "A13S02N01R01", 0, 1);
	_app->rotationAdd(311221, "A13S02N02R01", 0, 1);
	_app->rotationAdd(311231, "A13S02N03R01", 0, 1);
	_app->rotationAdd(311241, "A13S02N04R01", 0, 1);
	_app->rotationAdd(311251, "A13S02N05R01", 0, 1);
	_app->rotationAdd(311261, "A13S02N06R01", 0, 1);
	_app->rotationAddMovabilityToRotation(311211, 311221, "", Common::Rect(1193, -109, 1515, 256), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(311211, 0, 90.0f, -7.0f, 87.0f, 0.0f, 2, 90.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(311221, 311211, "", Common::Rect(2979, 177, 3385, 514), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(311221, 0, 270.0f, 26.0f, 87.0f, 0.0f, 2, 270.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(311221, 311231, "", Common::Rect(330, -94, 609, 273), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(311221, 1, 0.0f, 0.0f, 87.0f, 0.0f, 2, 0.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(311221, 311251, "", Common::Rect(2072, -101, 2364, 306), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(311221, 2, 180.0f, 0.0f, 87.0f, 0.0f, 2, 180.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(311231, 311221, "", Common::Rect(2068, -59, 2411, 395), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(311231, 0, 180.0f, 0.0f, 87.0f, 0.0f, 2, 180.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(311231, 311241, "", Common::Rect(3051, -73, 3325, 329), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(311231, 1, 270.0f, 0.0f, 87.0f, 0.0f, 2, 270.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(311241, 311231, "", Common::Rect(1177, -102, 1457, 287), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(311241, 0, 90.0f, 0.0f, 87.0f, 0.0f, 2, 90.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(311251, 311221, "", Common::Rect(293, -75, 625, 289), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(311251, 0, 0.0f, 0.0f, 87.0f, 0.0f, 2, 0.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(311251, 311261, "", Common::Rect(2926, -118, 3218, 306), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(311251, 1, 270.0f, 0.0f, 87.0f, 0.0f, 2, 270.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(311251, kPuzzle310001, "", Common::Rect(2394, -568, 2647, -52), true, kCursorAction, 0);
	_app->rotationSetMovabilityToPuzzle(311251, 2, 263.0f, 26.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(311261, 311251, "", Common::Rect(1241, -88, 1495, 293), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(311261, 0, 90.0f, 0.0f, 87.0f, 0.0f, 2, 90.0f, 0.0f, 87.0f);
	_app->objectAdd(kObject310001, "", "", 1);
	_app->objectAdd(kObject310002, "", "", 1);
	_app->objectAdd(kObject310015, "", "", 1);
	_app->objectAdd(kObjectIHaveADreamMartinLutherKing, "I Have a Dream Martin Luther King", "A13_book", 1);
	_app->objectSetActiveCursor(kObjectIHaveADreamMartinLutherKing, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectIHaveADreamMartinLutherKing, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectTheodoreRooseveltTheNewDeal, "Theodore Roosevelt The New Deal", "A13_book", 1);
	_app->objectSetActiveCursor(kObjectTheodoreRooseveltTheNewDeal, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectTheodoreRooseveltTheNewDeal, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectLostParadisesMilton, "Lost Paradises Milton", "A13_book", 1);
	_app->objectSetActiveCursor(kObjectLostParadisesMilton, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectLostParadisesMilton, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectHopeAndGloryBrittain1900_1980, "Hope & Glory Brittain 1900-1980", "A13_book", 1);
	_app->objectSetActiveCursor(kObjectHopeAndGloryBrittain1900_1980, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectHopeAndGloryBrittain1900_1980, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectInMemoriaVirgile, "In Memoria Virgile", "A13_book", 1);
	_app->objectSetActiveCursor(kObjectInMemoriaVirgile, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectInMemoriaVirgile, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObject1917TheYearAmericaWentToWar, "1917: The Year America Went To War", "A13_book", 1);
	_app->objectSetActiveCursor(kObject1917TheYearAmericaWentToWar, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObject1917TheYearAmericaWentToWar, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectAndTheAngelsSang, "And The Angels Sang", "A13_book", 1);
	_app->objectSetActiveCursor(kObjectAndTheAngelsSang, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectAndTheAngelsSang, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectSignedWithTheirHonour, "Signed With Their Honour", "A13_book", 1);
	_app->objectSetActiveCursor(kObjectSignedWithTheirHonour, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectSignedWithTheirHonour, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectAMidSummerNightDream, "A mid summer night dream by William Shakespeare", "A13_book", 1);
	_app->objectSetActiveCursor(kObjectAMidSummerNightDream, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectAMidSummerNightDream, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectContractAndRelatedObligation, "Contract And Related Obligation", "A13_book", 1);
	_app->objectSetActiveCursor(kObjectContractAndRelatedObligation, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectContractAndRelatedObligation, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectWithWilliamBurroughs, "With William Burroughs", "A13_book", 1);
	_app->objectSetActiveCursor(kObjectWithWilliamBurroughs, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectWithWilliamBurroughs, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAdd(kObjectMephistoKlausMann, "Mephisto Klaus Mann", "A13_book", 1);
	_app->objectSetActiveCursor(kObjectMephistoKlausMann, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectMephistoKlausMann, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObject310001, kPuzzle310001, Common::Rect(127, 172, 147, 300), true, kCursorAction, 0);
	_app->objectAddPuzzleAccessibility(kObject310001, kPuzzle310001, Common::Rect(161, 172, 181, 300), true, kCursorAction, 1);
	_app->objectAddPuzzleAccessibility(kObject310001, kPuzzle310001, Common::Rect(196, 172, 216, 300), true, kCursorAction, 2);
	_app->objectAddPuzzleAccessibility(kObject310001, kPuzzle310001, Common::Rect(230, 172, 250, 300), true, kCursorAction, 3);
	_app->objectAddPuzzleAccessibility(kObject310001, kPuzzle310001, Common::Rect(264, 172, 284, 300), true, kCursorAction, 4);
	_app->objectAddPuzzleAccessibility(kObject310001, kPuzzle310001, Common::Rect(298, 172, 318, 300), true, kCursorAction, 5);
	_app->objectAddPuzzleAccessibility(kObject310001, kPuzzle310001, Common::Rect(333, 172, 353, 300), true, kCursorAction, 6);
	_app->objectAddPuzzleAccessibility(kObject310001, kPuzzle310001, Common::Rect(367, 172, 387, 300), true, kCursorAction, 7);
	_app->objectAddPuzzleAccessibility(kObject310001, kPuzzle310001, Common::Rect(401, 172, 421, 300), true, kCursorAction, 8);
	_app->objectAddPuzzleAccessibility(kObject310001, kPuzzle310001, Common::Rect(435, 172, 455, 300), true, kCursorAction, 9);
	_app->objectAddPuzzleAccessibility(kObject310001, kPuzzle310001, Common::Rect(470, 172, 490, 300), true, kCursorAction, 10);
	_app->objectAddPuzzleAccessibility(kObject310001, kPuzzle310001, Common::Rect(504, 172, 524, 300), true, kCursorAction, 11);
	_app->objectAddPuzzleAccessibility(kObject310015, kPuzzle310001, Common::Rect(  0, 420, 640, 464), false, kCursorBack, 0);
	_app->objectAddPresentation(kObject310001);
	_app->objectPresentationAddImageToPuzzle(kObject310001, 0, kPuzzle310001, "a13s02n05p01l01.tga", Common::Point(125, 177), true, kDrawTypeAlpha, 1001);
	_app->objectAddPresentation(kObject310001);
	_app->objectPresentationAddImageToPuzzle(kObject310001, 1, kPuzzle310001, "a13s02n05p01l02.tga", Common::Point(159, 177), true, kDrawTypeAlpha, 1002);
	_app->objectAddPresentation(kObject310001);
	_app->objectPresentationAddImageToPuzzle(kObject310001, 2, kPuzzle310001, "a13s02n05p01l03.tga", Common::Point(193, 177), true, kDrawTypeAlpha, 1003);
	_app->objectAddPresentation(kObject310001);
	_app->objectPresentationAddImageToPuzzle(kObject310001, 3, kPuzzle310001, "a13s02n05p01l04.tga", Common::Point(226, 178), true, kDrawTypeAlpha, 1004);
	_app->objectAddPresentation(kObject310001);
	_app->objectPresentationAddImageToPuzzle(kObject310001, 4, kPuzzle310001, "a13s02n05p01l05.tga", Common::Point(258, 177), true, kDrawTypeAlpha, 1005);
	_app->objectAddPresentation(kObject310001);
	_app->objectPresentationAddImageToPuzzle(kObject310001, 5, kPuzzle310001, "a13s02n05p01l06.tga", Common::Point(291, 179), true, kDrawTypeAlpha, 1006);
	_app->objectAddPresentation(kObject310001);
	_app->objectPresentationAddImageToPuzzle(kObject310001, 6, kPuzzle310001, "a13s02n05p01l07.tga", Common::Point(325, 179), true, kDrawTypeAlpha, 1006);
	_app->objectAddPresentation(kObject310001);
	_app->objectPresentationAddImageToPuzzle(kObject310001, 7, kPuzzle310001, "a13s02n05p01l08.tga", Common::Point(355, 178), true, kDrawTypeAlpha, 1005);
	_app->objectAddPresentation(kObject310001);
	_app->objectPresentationAddImageToPuzzle(kObject310001, 8, kPuzzle310001, "a13s02n05p01l09.tga", Common::Point(386, 178), true, kDrawTypeAlpha, 1004);
	_app->objectAddPresentation(kObject310001);
	_app->objectPresentationAddImageToPuzzle(kObject310001, 9, kPuzzle310001, "a13s02n05p01l10.tga", Common::Point(415, 178), true, kDrawTypeAlpha, 1003);
	_app->objectAddPresentation(kObject310001);
	_app->objectPresentationAddImageToPuzzle(kObject310001, 10, kPuzzle310001, "a13s02n05p01l11.tga", Common::Point(444, 178), true, kDrawTypeAlpha, 1002);
	_app->objectAddPresentation(kObject310001);
	_app->objectPresentationAddImageToPuzzle(kObject310001, 11, kPuzzle310001, "a13s02n05p01l12.tga", Common::Point(475, 178), true, kDrawTypeAlpha, 1001);

	_app->setArchiveType(kArchiveFile);

	_app->objectAddPresentation(kObject310002);
	_app->objectPresentationAddImageToPuzzle(kObject310002, 0, kPuzzle310001, "a13s02n05p01n01.tga", Common::Point(0, 0), true, kDrawTypeAlpha, 1011);
	_app->objectAddPresentation(kObject310002);
	_app->objectPresentationAddImageToPuzzle(kObject310002, 1, kPuzzle310001, "a13s02n05p01n02.tga", Common::Point(0, 0), true, kDrawTypeAlpha, 1012);
	_app->objectAddPresentation(kObject310002);
	_app->objectPresentationAddImageToPuzzle(kObject310002, 2, kPuzzle310001, "a13s02n05p01n03.tga", Common::Point(0, 0), true, kDrawTypeAlpha, 1013);
	_app->objectAddPresentation(kObject310002);
	_app->objectPresentationAddImageToPuzzle(kObject310002, 3, kPuzzle310001, "a13s02n05p01n04.tga", Common::Point(0, 0), true, kDrawTypeAlpha, 1014);
	_app->objectAddPresentation(kObject310002);
	_app->objectPresentationAddImageToPuzzle(kObject310002, 4, kPuzzle310001, "a13s02n05p01n05.tga", Common::Point(0, 0), true, kDrawTypeAlpha, 1015);
	_app->objectAddPresentation(kObject310002);
	_app->objectPresentationAddImageToPuzzle(kObject310002, 5, kPuzzle310001, "a13s02n05p01n06.tga", Common::Point(0, 0), true, kDrawTypeAlpha, 1016);
	_app->objectAddPresentation(kObject310002);
	_app->objectPresentationAddImageToPuzzle(kObject310002, 6, kPuzzle310001, "a13s02n05p01n07.tga", Common::Point(0, 0), true, kDrawTypeAlpha, 1016);
	_app->objectAddPresentation(kObject310002);
	_app->objectPresentationAddImageToPuzzle(kObject310002, 7, kPuzzle310001, "a13s02n05p01n08.tga", Common::Point(0, 0), true, kDrawTypeAlpha, 1015);
	_app->objectAddPresentation(kObject310002);
	_app->objectPresentationAddImageToPuzzle(kObject310002, 8, kPuzzle310001, "a13s02n05p01n09.tga", Common::Point(0, 0), true, kDrawTypeAlpha, 1014);
	_app->objectAddPresentation(kObject310002);
	_app->objectPresentationAddImageToPuzzle(kObject310002, 9, kPuzzle310001, "a13s02n05p01n10.tga", Common::Point(0, 0), true, kDrawTypeAlpha, 1013);
	_app->objectAddPresentation(kObject310002);
	_app->objectPresentationAddImageToPuzzle(kObject310002, 10, kPuzzle310001, "a13s02n05p01n11.tga", Common::Point(0, 0), true, kDrawTypeAlpha, 1012);
	_app->objectAddPresentation(kObject310002);
	_app->objectPresentationAddImageToPuzzle(kObject310002, 11, kPuzzle310001, "a13s02n05p01n12.tga", Common::Point(0, 0), true, kDrawTypeAlpha, 1011);

	if (_app->getZoneArchiveType(kZone16) == kArchiveArt)
		_app->setArchiveType(kArchiveArt);

	_app->objectPresentationShow(kObject310001);
	_app->objectPresentationShow(kObject310002);
	_app->objectSetAccessibilityOff(kObject310001);
	_app->objectAddPresentation(kObject310015);
	_app->objectPresentationAddImageToPuzzle(kObject310015, 0, kPuzzle310001, "a13s02n05p02.bmp", Common::Point(120, 174), true, kDrawTypeNormal, 2000);
	_app->objectPresentationShow(kObject310015);
	_app->objectAdd(kObject310016, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject310016, kPuzzle310001, Common::Rect(137, 150, 517, 160), true, kCursorIdle, 0);
	_app->objectAdd(kObject310017, "", "", 1);
	_app->objectAddRotationAccessibility(kObject310017, 311111, Common::Rect(3070, -66, 3229, 183), true, kCursorMove, 0);
	_app->objectAddRotationAccessibility(kObject310017, 311211, Common::Rect(3048, -80, 3208, 188), true, kCursorMove, 1);
	_app->objectAdd(kObject310018, "", "", 1);
	_app->objectAddPresentation(kObject310018);
	_app->objectPresentationAddImageToRotation(kObject310018, 0, 311211, 0);
	_app->objectAddPresentation(kObject310018);
	_app->objectPresentationAddImageToRotation(kObject310018, 1, 311221, 0);
	_app->objectAddPresentation(kObject310018);
	_app->objectPresentationAddImageToRotation(kObject310018, 2, 311231, 0);
	_app->objectAddPresentation(kObject310018);
	_app->objectPresentationAddImageToRotation(kObject310018, 3, 311241, 0);
	_app->objectAddPresentation(kObject310018);
	_app->objectPresentationAddImageToRotation(kObject310018, 4, 311251, 0);
	_app->objectAddPresentation(kObject310018);
	_app->objectPresentationAddImageToRotation(kObject310018, 5, 311261, 0);
	_app->soundAdd(310105, kSoundTypeBackgroundMusic, "13_BGR_MUS.wac", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(310105, 100);
	_app->soundAdd(310101, kSoundTypeEffect, "13_book_take.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(310102, kSoundTypeEffect, "13_book_put.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(310103, kSoundTypeEffect, "13_door_slide_start.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(310104, kSoundTypeEffect, "13_door_slide_end.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(310106, kSoundTypeAmbientEffect, "13_lift.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(310001, kSoundTypeDialog, "E04_38_1Bok.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(310002, kSoundTypeDialog, "E04_38_2Bok.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(310003, kSoundTypeDialog, "E04_38_3Bok.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(310004, kSoundTypeDialog, "E04_38_4Bok.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(310005, kSoundTypeDialog, "E04_38_5Bok.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(310006, kSoundTypeDialog, "E04_38_6Bok.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(310007, kSoundTypeDialog, "E04_38_7Bok.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(310008, kSoundTypeDialog, "E04_38_8Bok.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(310009, kSoundTypeDialog, "E04_38_9Bok.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(310010, kSoundTypeDialog, "E04_38_10Bok.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(310011, kSoundTypeDialog, "E04_38_11Bok.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(310012, kSoundTypeDialog, "E04_38_12Bok.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(310013, kSoundTypeDialog, "E04_38_engraved.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->varDefineByte(311001, 1);
	_app->varDefineByte(311002, 1);
	_app->varDefineByte(311003, 1);
	_app->varDefineByte(311004, 1);
	_app->varDefineByte(311005, 1);
	_app->varDefineByte(311006, 1);
	_app->varDefineByte(311007, 1);
	_app->varDefineByte(311008, 1);
	_app->varDefineByte(311009, 1);
	_app->varDefineByte(311010, 1);
	_app->varDefineByte(311011, 1);
	_app->varDefineByte(311012, 1);
	_app->varDefineWord(311024, 0);
	_app->varDefineWord(311012, 7);
	_app->varDefineWord(311013, 1);
	_app->varDefineWord(311014, 8);
	_app->varDefineWord(311015, 9);
	_app->varDefineWord(311016, 4);
	_app->varDefineWord(311017, 11);
	_app->varDefineWord(311018, 6);
	_app->varDefineWord(311019, 0);
	_app->varDefineWord(311020, 2);
	_app->varDefineWord(311021, 3);
	_app->varDefineWord(311022, 10);
	_app->varDefineWord(311023, 5);
	_app->varDefineWord(311000, 136);
	_app->objectPresentationSetImageCoordinatesOnPuzzle(310002, (uint16)_app->varGetWord(311012), Common::Point(_app->varGetWord(311000), 182));
	_app->varDefineWord(311001, 170);
	_app->objectPresentationSetImageCoordinatesOnPuzzle(310002, (uint16)_app->varGetWord(311013), Common::Point(_app->varGetWord(311001), 182));
	_app->varDefineWord(311002, 204);
	_app->objectPresentationSetImageCoordinatesOnPuzzle(310002, (uint16)_app->varGetWord(311014), Common::Point(_app->varGetWord(311002), 182));
	_app->varDefineWord(311003, 238);
	_app->objectPresentationSetImageCoordinatesOnPuzzle(310002, (uint16)_app->varGetWord(311015), Common::Point(_app->varGetWord(311003), 182));
	_app->varDefineWord(311004, 272);
	_app->objectPresentationSetImageCoordinatesOnPuzzle(310002, (uint16)_app->varGetWord(311016), Common::Point(_app->varGetWord(311004), 182));
	_app->varDefineWord(311005, 306);
	_app->objectPresentationSetImageCoordinatesOnPuzzle(310002, (uint16)_app->varGetWord(311017), Common::Point(_app->varGetWord(311005), 182));
	_app->varDefineWord(311006, 340);
	_app->objectPresentationSetImageCoordinatesOnPuzzle(310002, (uint16)_app->varGetWord(311018), Common::Point(_app->varGetWord(311006), 182));
	_app->varDefineWord(311007, 374);
	_app->objectPresentationSetImageCoordinatesOnPuzzle(310002, (uint16)_app->varGetWord(311019), Common::Point(_app->varGetWord(311007), 182));
	_app->varDefineWord(311008, 408);
	_app->objectPresentationSetImageCoordinatesOnPuzzle(310002, (uint16)_app->varGetWord(311020), Common::Point(_app->varGetWord(311008), 182));
	_app->varDefineWord(311009, 442);
	_app->objectPresentationSetImageCoordinatesOnPuzzle(310002, (uint16)_app->varGetWord(311021), Common::Point(_app->varGetWord(311009), 182));
	_app->varDefineWord(311010, 476);
	_app->objectPresentationSetImageCoordinatesOnPuzzle(310002, (uint16)_app->varGetWord(311022), Common::Point(_app->varGetWord(311010), 182));
	_app->varDefineWord(311011, 510);
	_app->objectPresentationSetImageCoordinatesOnPuzzle(310002, (uint16)_app->varGetWord(311023), Common::Point(_app->varGetWord(311011), 182));
	_app->varDefineDword(311001, 0);
}

void Zone16Faust::onTimer(TimerId id) {
	switch (id) {
	default:
		break;

	case kTimer0:
		_app->varSetWord(311024, _app->varGetWord(311024) + 5);

		if (_app->varGetWord(311024) < 155) {
			_app->objectPresentationSetImageCoordinatesOnPuzzle(kObject310015, 0, Common::Point(120, 174 - _app->varGetWord(311024)));
		} else {
			_app->objectSetAccessibilityOn(kObject310015, 0, 0);
			_app->objectSetAccessibilityOn(kObject310001);
			_app->soundStop(310103, 1024);
			_app->soundPlay(310104);
			_app->timerStop(kTimer0);
		}
		break;

	case kTimer1:
		_app->varSetWord(311024, _app->varGetWord(311024) - 5);

		if (_app->varGetWord(311024) > -10) {
			_app->objectPresentationSetImageCoordinatesOnPuzzle(kObject310015, 0, Common::Point(120, 174 - _app->varGetWord(311024)));
		} else {
			_app->objectPresentationSetImageCoordinatesOnPuzzle(kObject310015, 0, Common::Point(120, 174));
			_app->soundStop(310103, 1024);
			_app->timerStop(kTimer1);
			_app->rotationSetAlp(311251, 206.0f);
			_app->rotationSetBet(311251, -26.0f);
			_app->rotationSetRan(311251, 87.0f);
			_app->rotationSetActive(311251);
			_app->soundPlay(310104);
		}
		break;

	case kTimer2:
		_app->timerStop(kTimer2);
		_app->timerStart(kTimer2, rnd(200));

		if (rnd(2))
			_app->objectPresentationHide(kObject310018);
		else
			_app->objectPresentationShow(kObject310018);
		break;
	}
}

void Zone16Faust::onButtonUp(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, const Common::Point &point) {
	switch (id) {
	default:
		break;

	case kObject310001:
		if (_app->bagHasClickedObject()) {
			// Put a book back on the shelf (slot = target, the word var keeps book - 310003)
			int32 book = _app->bagGetClickedObject();
			if (book < kObjectIHaveADreamMartinLutherKing || book > kObjectMephistoKlausMann || _app->varGetByte(311001 + target) != 0) {
				_app->cursorDelete();
				break;
			}

			_app->objectPresentationShow(kObject310001, target);
			_app->objectPresentationShow(kObject310002, book - 310003);
			_app->objectPresentationSetImageCoordinatesOnPuzzle(kObject310002, book - 310003, Common::Point(_app->varGetWord(311000 + target), 182));
			_app->varSetWord(311012 + target, book - 310003);
			_app->varSetByte(311001 + target, 1);
			_app->soundPlay(310102);
			_app->bagRemove(book);

			for (uint32 i = 0; i < 12; i++) {
				if (_app->varGetWord(311012 + i) != (int16)i) {
					_app->cursorDelete();
					return;
				}
			}

			for (uint32 i = 0; i < 12; i++) {
				if (_app->varGetByte(311001 + i) != 1) {
					_app->cursorDelete();
					return;
				}
			}

			// All twelve books in order: end of episode Four
			_app->soundStopAll(1024);
			_app->playMovie("a13s02n05p01a01");
			_app->playMovie("A13S02_E04M11");
			_app->playMovie("A13S02_E04M12");

			// Sets the progress animation frame (0x4dc040), it doesn't save
			if (_app->getSaveManager()->getData()->progressState == kProgressState4)
				_app->getSaveManager()->getData()->progress = 0x24;

			_app->exitToMenu(kMenuAction0);
		} else {
			// Take a book
			int16 book = _app->varGetWord(311012 + target);
			_app->objectPresentationHide(kObject310001, target);
			_app->objectPresentationHide(kObject310002, book);
			_app->bagAdd(book + 310003);
			_app->varSetByte(311001 + target, 0);
			_app->soundPlay(310101);
		}
		break;

	case kObject310015:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		// Close the bookcase door
		_app->objectSetAccessibilityOff(kObject310015, 0, 0);
		_app->objectSetAccessibilityOff(kObject310001);
		_app->soundPlay(310103, kSoundLoop);
		_app->timerStart(kTimer1, 30);
		break;

	case kObject310017:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		// Lift
		if (target == 0) {
			_app->rotationSetRolTo(311111, 270.0f, 0.0f, 87.0f);
			_app->soundPlay(310106);
			_app->displayFade("A13S01N01R01_0.bmp", "a13_black.bmp", 15, 0, kLoadFromCd, kArchiveArt);
			_app->displayFade("a13_black.bmp", "A13S02N01R01_0.bmp", 15, 0, kLoadFromCd, kArchiveArt);
			_app->rotationSetAlp(311211, 90.0f);
			_app->rotationSetBet(311211, 0.0f);
			_app->rotationSetRan(311211, 87.0f);
			_app->rotationSetActive(311211);
			_app->timerStart(kTimer2, 1000);
		} else if (target == 1) {
			_app->rotationSetRolTo(311211, 270.0f, 0.0f, 87.0f);
			_app->soundPlay(310106);
			_app->displayFade("A13S02N01R01_1.bmp", "a13_black.bmp", 15, 0, kLoadFromCd, kArchiveArt);
			_app->displayFade("a13_black.bmp", "A13S01N01R01_1.bmp", 15, 0, kLoadFromCd, kArchiveArt);
			_app->rotationSetAlp(311111, 90.0f);
			_app->rotationSetBet(311111, 0.0f);
			_app->rotationSetRan(311111, 87.0f);
			_app->rotationSetActive(311111);
		}
		break;
	}
}

void Zone16Faust::onUpdateBag(const Common::Point &point) {
	_app->soundStop(_app->varGetDword(311001), 1024);
	_app->varSetDword(311001, 0);
}

void Zone16Faust::onUpdateBefore(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, const Common::Point &point) {
	if (_app->soundIsPlayingType(kSoundTypeDialog))
		return;

	switch (movabilityFrom) {
	default:
		break;

	case 310001: {
		// Read out the title of the book in slot movabilityTo (the target)
		if (_app->varGetByte(311001 + movabilityTo) != 1)
			break;

		Id soundId = 310001 + _app->varGetWord(311012 + movabilityTo);
		_app->soundPlay(soundId);
		_app->varSetDword(311001, soundId);
		}
		break;

	case 310016:
		_app->soundPlay(310013);
		_app->varSetDword(311001, 310013);
		break;
	}
}

void Zone16Faust::onAfterRide(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, MovabilityType movabilityType) {
	if (movabilityType == kMovabilityRotationToPuzzle && movabilityFrom == 310001 && movabilityTo == 311251) {
		_app->soundPlay(310103, kSoundLoop);
		_app->timerStart(kTimer0, 30);
	}
}

} // End of namespace Ring
