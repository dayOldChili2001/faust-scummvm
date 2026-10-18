/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 6
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 06110-1301, USA.
 */

#include "ring/game/faust/faust_zone6.h"

#include "ring/base/saveload.h"

#include "ring/game/faust/faust_application.h"
#include "ring/game/faust/faust_shared.h"

#include "ring/debug.h"
#include "ring/ring.h"
#include "ring/helpers.h"

using namespace FaustGame;

namespace Ring {

Zone6Faust::Zone6Faust(ApplicationFaust *application) : _app(application) {
}

Zone6Faust::~Zone6Faust() {
	// Zero-out passed pointers
	_app = nullptr;
}

void Zone6Faust::onInit() {
	_app->setCurrentZone(kZone6);

	_app->puzzleAdd(kPuzzle31001);
	_app->puzzleAddBackgroundImage(kPuzzle31001, "a03s01n03p02.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle31002);
	_app->puzzleAddBackgroundImage(kPuzzle31002, "a03s01n03p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle31003);
	_app->puzzleAddBackgroundImage(kPuzzle31003, "a03s01n02p01.bmp", Common::Point(0, 16), true);
	_app->rotationAdd(31011, "A03S01N01R01", 0, 0);
	_app->rotationAdd(31012, "A03S01N02R01", 0, 0);
	_app->rotationAdd(31013, "A03S01N03R01", 0, 10);
	_app->rotationSetCompressionBufferLength(31013, 2500000);
	_app->rotationAddMovabilityToRotation(31011, 31012, "", Common::Rect(283, -167, 653, 388), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(31011, 0, 0.0f, -13.0f, 87.0f, 0.0f, 2, 0.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(31012, 31011, "", Common::Rect(2130, 231, 2441, 544), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(31012, 0, 180.0f, 26.0f, 87.0f, 0.0f, 2, 180.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(31012, 31013, "", Common::Rect(295, 68, 669, 444), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(31012, 1, 0.0f, 0.0f, 87.0f, 0.0f, 2, 157.5f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(31012, kPuzzle31003, "", Common::Rect(3447, -592, 3600, -285), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(31012, 2, 180.0f, 26.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(31012, kPuzzle31003, "", Common::Rect(0, -592, 798, -285), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(31012, 3, 180.0f, 26.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(31013, 31012, "", Common::Rect(2058, -20, 2453, 259), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(31013, 0, 180.0f, 5.0f, 87.0f, 0.0f, 2, 180.0f, 26.0f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(31013, kPuzzle31001, "", Common::Rect(2227, 497, 2269, 523), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(31013, 1, 180.0f, 26.0f, 87.0f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(31013, kPuzzle31002, "", Common::Rect(1105, -144, 1149, -94), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(31013, 2, 180.0f, 26.0f, 87.0f, 0.0f, 2);
	_app->puzzleAddMovabilityToRotation(kPuzzle31001, 31013, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle31001, 0, 180.0f, 26.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle31002, 31013, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle31002, 0, 71.0f, -5.0f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle31003, 31012, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle31003, 0, 0.0f, -41.0f, 87.0f);

	_app->objectAdd(kObject31001, "", "", 1);

	for (uint32 i = 0; i < 9; i++) {
		_app->objectAddPresentation(kObject31001);
		_app->objectPresentationAddImageToRotation(kObject31001, i, 31013, i);
	}

	_app->objectAdd(kObject31002, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject31002, kPuzzle31001, Common::Rect(263, 205, 370, 286), true, kCursorAction, 0);
	_app->objectAddPresentation(kObject31002);
	_app->objectPresentationAddImageToPuzzle(kObject31002, 0, kPuzzle31001, "a03s01n03p02l01.bmp", Common::Point(261, 205), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject31002);
	_app->objectPresentationAddAnimationToPuzzle(kObject31002, 1, kPuzzle31001, "a03s01n03p02s01", kImageTypeBMP, Common::Point(261, 205), kDrawTypeNormal, 1000, 10, 15.0f, 6);
	_app->objectPresentationSetAnimationOnPuzzle(kObject31002, 1, 0, 31000);
	_app->objectAdd(kObject31003, "", "", 1);
	_app->objectAdd(kObjectRolodex, "Rolodex", "A01_Dummy", 1);
	_app->objectSetActiveCursor(kObjectRolodex, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectRolodex, Common::Point(11, 11), 0, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObject31003, kPuzzle31002, Common::Rect(241, 109, 423, 367), true, kCursorAction, 0);
	_app->objectAddPuzzleAccessibility(kObject31003, kPuzzle31002, Common::Rect(355, 253, 418, 365), true, kCursorTake, 1);
	_app->objectAddPresentation(kObject31003);
	_app->objectPresentationAddImageToPuzzle(kObject31003, 0, kPuzzle31002, "a03s01n03p01l01.bmp", Common::Point(73, 73), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject31003);
	_app->objectPresentationAddImageToPuzzle(kObject31003, 1, kPuzzle31002, "a03s01n03p01l02.bmp", Common::Point(67, 69), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObject31003);
	_app->objectPresentationAddImageToRotation(31003, 2, 31013, 9);
	_app->soundAdd(31003, kSoundTypeBackgroundMusic, "A03_BGR_MUS.wac", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(31003, 90);
	_app->soundAdd(31001, kSoundTypeEffect, "klopca.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(31002, kSoundTypeEffect, "vratca.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetPan(31002, -8);
	_app->soundAdd(31004, kSoundTypeEffect, "03_rotating_on_stone_01.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(31005, kSoundTypeEffect, "03_rotating_on_stone_02.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(31006, kSoundTypeEffect, "03_rotating_on_stone_03.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(31007, kSoundTypeEffect, "03_rotating_on_stone_04.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(31008, kSoundTypeEffect, "03_rotating_on_stone_05.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(31009, kSoundTypeEffect, "03_rotating_on_stone_06.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(31010, kSoundTypeEffect, "03_plaketa_open.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(31011, kSoundTypeEffect, "03_take_book.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(31012, kSoundTypeEffect, "03_ZAPELJE_CEZ_LUKNO.wav", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(31101, kSoundTypeDialog, "E01_16_plate.wav", _app->getConfiguration().dialog.loadFrom, 1, _app->getConfiguration().dialog.soundChunck);
	_app->varDefineByte(31001, 0);
	_app->varDefineByte(31002, 0);
	_app->varDefineByte(31003, 0);
	_app->varDefineFloat(31001, 4.0f);
	_app->objectPresentationShow(kObject31001, (uint32)_app->varGetFloat(31001));
	_app->varDefineFloat(31003, 4.0f);
	_app->varDefineFloat(31002, 0.0f);
	_app->varDefineDword(31000, 0);
}

void Zone6Faust::onSetup(SetupType type) {
	switch (type) {
	default:
		break;

	case kSetupType1:
		_app->timerStopAll();
		_app->bagRemoveAll();
		_app->setSpace(kZone5);
		_app->playMovie("A01S01_E05M01");
		_app->fadeOut(15, Color(0, 0, 0), 0);
		_app->setSpace(kZone2);
		_app->bagAdd(13899);
		_app->bagAdd(13129);
		_app->bagAdd(97001);
		_app->rotationSetAlp(11005, 270.0f);
		_app->rotationSetBet(11005, 0.0f);
		_app->rotationSetRan(11005, 87.0f);
		_app->displayFade("a01_black.bmp", "a01s01n05p01.bmp", 15, 0, kLoadFromCd, kArchiveArt);
		_app->rotationSetActive(11005);
		_app->timerStart(kTimer0, 1000);
		_app->objectSetAccessibilityOff(kObject11001);
		_app->objectSetAccessibilityOff(kObject11002);
		_app->objectSetAccessibilityOff(kObject11003);
		_app->objectSetAccessibilityOn(kObject11007);
		_app->objectSetAccessibilityOff(kObject11004);
		_app->objectSetAccessibilityOff(kObject11005);
		_app->objectPresentationShow(kObject25, 6);
		break;

	case kSetupType2:
		_app->setSpace(kZone9);
		_app->soundStopAll(1024);
		_app->soundPlay(61306, kSoundLoop);
		_app->rotationSetAlp(61200, 0.0f);
		_app->rotationSetBet(61200, 0.0f);
		_app->rotationSetRan(61200, 87.0f);
		_app->rotationSetActive(61200);
		break;

	case kSetupType3:
		_app->setSpace(kZone17);

		// FAUST.EXE 0x46b157 sets the progress animation frame (0x4dc040), it doesn't save
		if (_app->getSaveManager()->getData()->progressState == kProgressState5)
			_app->getSaveManager()->getData()->progress = 41;

		_app->rotationSetAlp(141101, 270.0f);
		_app->rotationSetBet(141101, 0.0f);
		_app->rotationSetRan(141101, 87.0f);
		_app->rotationSetActive(141101);
		break;

	case kSetupType11:
		_app->setSpace(kZone5);
		_app->timerStopAll();
		_app->timerStart(kTimer7, 1000);
		_app->rotationSetAlp(17001, 270.0f);
		_app->rotationSetBet(17001, 0.0f);
		_app->rotationSetRan(17001, 87.0f);
		_app->rotationSetActive(17001);
		_app->soundPlay(17062);
		_app->soundPlay(17019, kSoundLoop);
		break;

	case kSetupType12:
		_app->timerStopAll();
		_app->soundPlay(17062);
		_app->soundStop(17019, 1024);
		_app->setSpace(kZone2);
		_app->rotationSetAlp(11006, 90.0f);
		_app->rotationSetBet(11006, 0.0f);
		_app->rotationSetRan(11006, 87.0f);
		_app->rotationSetActive(11006);
		_app->timerStart(kTimer0, 1000);
		_app->objectSetAccessibilityOff(kObject11002);
		_app->objectSetAccessibilityOff(kObject11003);
		_app->objectSetAccessibilityOn(kObject11007);
		_app->objectSetAccessibilityOff(kObject11004);
		_app->objectSetAccessibilityOff(kObject11005);
		break;

	case kSetupType99:
		_app->timerStopAll();
		_app->bagRemoveAll();
		_app->bagAdd(13899);
		_app->bagAdd(13129);
		_app->bagAdd(97001);
		_app->setSpace(kZone9);
		_app->bagAdd(kObjectKey);
		_app->bagAdd(kObjectWhip);
		_app->rotationSetMovabilityOn(61001, 1, 1);
		_app->rotationSetMovabilityOn(61207, 2, 2);
		_app->objectPresentationShow(kObject61304, 2);
		_app->rotationSetAlp(61001, 300.0f);
		_app->rotationSetRan(61001, 85.7f);
		_app->rotationSetActive(61001);
		_app->varSetByte(17042, 1);
		_app->varSetByte(17027, 1);
		break;

	case kSetupType30000:
		switch (_app->getChapterIndex()) {
		default:
			break;

		case 18:
			_app->setCurrentZone(kZone5);
			_app->playMovie("A01S01_E05M01");
			break;

		case 19:
			_app->setCurrentZone(kZone5);
			_app->playMovie("A01S07_E05M04");
			break;

		case 20:
			_app->setCurrentZone(kZone9);
			_app->playMovie("A06S03_E05M06");
			break;
		}

		_app->setCurrentZone(kZoneSY);
		_app->soundPlay(90001, kSoundLoop);
		_app->puzzleSetActive(kPuzzleGeneralMenu);
		break;
	}
}

void Zone6Faust::onTimer(TimerId id) {
	error("[Zone6Faust::onTimer] Not implemented");
}

void Zone6Faust::onButtonUp(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, const Common::Point &point) {
	error("[Zone6Faust::onButtonUp] Not implemented");
}

void Zone6Faust::onAnimationNextFrame(Id animationId, const Common::String &name, uint32 frame, uint32 frameCount) {
	if (animationId == 31000 && frame == 10) {
		_app->objectPresentationShow(kObject31002, 0);
		_app->varSetByte(31001, 1);
	}
}

void Zone6Faust::onUpdateBag(const Common::Point &point) {
	_app->soundStop(_app->varGetDword(31000), 1024);
	_app->varSetDword(31000, 0);
}

void Zone6Faust::onUpdateBefore(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, const Common::Point &point) {
	if (movabilityFrom == 31003 && !_app->soundIsPlayingType(kSoundTypeDialog) && movabilityTo == 0) {
		_app->soundPlay(31101);
		_app->varSetDword(31000, 31101);
	}
}

void Zone6Faust::onAfterRide(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, MovabilityType movabilityType) {
	error("[Zone6Faust::onAfterRide] Not implemented");
}

} // End of namespace Ring
