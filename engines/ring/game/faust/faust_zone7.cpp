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

#include "ring/game/faust/faust_zone7.h"

#include "ring/game/faust/faust_application.h"
#include "ring/game/faust/faust_shared.h"

#include "ring/debug.h"
#include "ring/ring.h"
#include "ring/helpers.h"

using namespace FaustGame;

namespace Ring {

Zone7Faust::Zone7Faust(ApplicationFaust *application) : _app(application) {
}

Zone7Faust::~Zone7Faust() {
	// Zero-out passed pointers
	_app = nullptr;
}

void Zone7Faust::onInit() {
	_app->setCurrentZone(kZone7);
	_app->puzzleAdd(kPuzzle49000);
	_app->puzzleAddBackgroundImage(kPuzzle49000, "a04s01n02p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle49001);
	_app->puzzleAddBackgroundImage(kPuzzle49001, "a04s02n01p02.bmp", Common::Point(0, 16), true);
	_app->rotationAdd(41000, "A04S01N01R01", 0, 2);
	_app->rotationAdd(41001, "A04S01N02R01", 0, 2);
	_app->rotationAdd(41002, "A04S02N01R01", 0, 1);
	_app->rotationAddMovabilityToRotation(41000, 41001, "", Common::Rect(3533, -150, 3600, 52), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(41000, 0, 330.0f, 0.3f, 87.0f, 0.0f, 2, 0.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(41000, 41001, "", Common::Rect(0, -150, 138, 52), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(41000, 1, 330.0f, 0.3f, 87.0f, 0.0f, 2, 0.0f, 0.3f, 87.0f);
	_app->objectAdd(kObject49000, "", "", 1);
	_app->objectAddRotationAccessibility(kObject49000, 41001, Common::Rect(316, 5, 611, 318), true, kCursorAction, 0);
	_app->objectAddPresentation(kObject49000);
	_app->objectPresentationAddAnimationToPuzzle(kObject49000, 0, kPuzzle49000, "a04s01n02a01", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1000, 100, 12.5f, 6);
	_app->objectAddPresentation(kObject49000);
	_app->objectPresentationAddAnimationToPuzzle(kObject49000, 1, kPuzzle49000, "a04s02n01p01s01", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1000, 70, 12.5f, 6);
	_app->objectAddPresentation(kObject49000);
	_app->objectPresentationAddAnimationToPuzzle(kObject49000, 2, kPuzzle49000, "a04s02n01p01s02", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1000, 23, 15.0f, 6);
	_app->objectAddPresentation(kObject49000);
	_app->objectPresentationAddAnimationToPuzzle(kObject49000, 3, kPuzzle49000, "a04s02n01p01s03", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1000, 17, 12.5f, 6);
	_app->objectAddPresentation(kObject49000);
	_app->objectPresentationAddAnimationToPuzzle(kObject49000, 4, kPuzzle49000, "a04s02n01p01s04", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1000, 15, 12.5f, 6);
	_app->objectAddPresentation(kObject49000);
	_app->objectPresentationAddAnimationToPuzzle(kObject49000, 5, kPuzzle49000, "a04s02n01p01s05", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1000, 63, 12.5f, 6);
	_app->objectAddPresentation(kObject49000);
	_app->objectPresentationAddAnimationToPuzzle(kObject49000, 6, kPuzzle49000, "a04s02n01p01s06", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1000, 58, 12.5f, 6);
	_app->objectAddPresentation(kObject49000);
	_app->objectPresentationAddAnimationToPuzzle(kObject49000, 7, kPuzzle49000, "a04s02n01p01s07", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1000, 70, 12.5f, 6);
	_app->objectAddPresentation(kObject49000);
	_app->objectPresentationAddAnimationToPuzzle(kObject49000, 8, kPuzzle49000, "a04s02n01p01s08", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1000, 60, 12.5f, 6);
	_app->objectAddPresentation(kObject49000);
	_app->objectPresentationAddAnimationToPuzzle(kObject49000, 9, kPuzzle49000, "a04s02n01p01s09", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1000, 70, 12.5f, 6);
	_app->objectAddPresentation(kObject49000);
	_app->objectPresentationAddAnimationToPuzzle(kObject49000, 10, kPuzzle49000, "a04s02n01p01s10", kImageTypeBMP, Common::Point(0, 16), kDrawTypeNormal, 1000, 60, 12.5f, 6);
	_app->objectAdd(kObject49003, "", "", 1);
	_app->objectAddRotationAccessibility(kObject49003, 41002, Common::Rect(704, 187, 847, 317), true, kCursorZoom, 0);
	_app->objectAddPuzzleAccessibility(kObject49003, kPuzzle49001, Common::Rect(278, 280, 396, 330), true, kCursorZoom, 1);
	_app->objectAddPuzzleAccessibility(kObject49003, kPuzzle49001, Common::Rect(0,   420, 640, 464), true, kCursorBack, 9);
	_app->objectAddPresentation(kObject49003);
	_app->objectPresentationAddImageToPuzzle(kObject49003, 0, kPuzzle49001, "a04s02n01p02l01.tga", Common::Point(0, 16), true, kDrawTypeAlpha, 1000);
	_app->objectPresentationAddImageToRotation(49003, 0, 41002, 0);
	_app->objectAdd(kObject49002, "", "", 1);
	_app->objectAddPresentation(kObject49002);
	_app->objectPresentationAddAnimationToRotation(kObject49002, 0, 41000, 0, 40, 12.5f, 5);
	_app->objectPresentationAddAnimationToRotation(kObject49002, 0, 41000, 1, 40, 12.5f, 5);
	_app->objectPresentationAddAnimationToRotation(kObject49002, 0, 41001, 0, 40, 12.5f, 5);
	_app->objectPresentationAddAnimationToRotation(kObject49002, 0, 41001, 1, 40, 12.5f, 5);
	_app->objectPresentationShow(kObject49002);
	_app->objectAdd(kObject19, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject19, kPuzzle49000, Common::Rect(0, 0, 640, 480), false, kCursorMenuIdle, 1);
	_app->objectAddPuzzleAccessibility(kObject19, kPuzzleMenu,  Common::Rect(0, 0, 640, 480), false, kCursorMenuIdle, 1);
	_app->varDefineByte(49000, 0);
	_app->varDefineByte(49001, 0);
	_app->varDefineByte(49002, 0);
	_app->varDefineByte(49003, 0);
	_app->varDefineByte(49004, 0);
	_app->soundAdd(41001, kSoundTypeBackgroundMusic, "a04_BgrMus.wac", _app->getConfiguration().backgroundMusic.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(41001, 90);
	_app->soundAdd(41002, kSoundTypeAmbientMusic, "04_crickets.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(41003, kSoundTypeAmbientMusic, "04_Horror1.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(41004, kSoundTypeAmbientMusic, "04_Horror2.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(41005, kSoundTypeAmbientMusic, "04_Horror3.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(41006, kSoundTypeAmbientMusic, "04_Horror4.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(41007, kSoundTypeAmbientMusic, "04_Horror5.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(41008, kSoundTypeAmbientMusic, "04_Laugh1.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(41009, kSoundTypeAmbientMusic, "04_Laugh2.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(41011, kSoundTypeAmbientMusic, "04_OUTIN_loop.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(41012, kSoundTypeAmbientMusic, "04_OUTIN_start.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(41013, kSoundTypeAmbientMusic, "04_IN_stop.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(41000, kSoundTypeDialog, "e01_15_pact.wac", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
}

// FAUST.EXE 0x4ab800. setupZone() dispatches on the episode, so this is episode 7
// ("Six"): it starts in zone 2 and zone 4, not in this class's A04 rotations.
void Zone7Faust::onSetup(SetupType type) {
	switch ((uint32)type) {
	default:
		break;

	case kSetupType1:
		_app->timerStopAll();
		_app->bagRemoveAll();
		_app->setSpace(kZone2);
		_app->playMovie("A01S01_E06M01");
		_app->fadeOut(15, Color(0, 0, 0), 0);
		_app->rotationSetAlp(11003, 270.0f);
		_app->rotationSetBet(11003, 0.0f);
		_app->rotationSetRan(11003, 87.0f);
		_app->rotationSetActive(11003);
		_app->timerStart(kTimer0, 1000);
		_app->objectSetAccessibilityOff(kObject11001);
		_app->objectSetAccessibilityOff(kObject11003);
		_app->bagAdd(13899);
		_app->bagAdd(13129);
		_app->bagAdd(97001);
		_app->objectPresentationShow(kObject25, 7);
		break;

	case kSetupType3:
		_app->setSpace(kZone4);
		_app->playMovie("a05s02_e06m12");
		_app->sub_4A7790(1);
		break;

	case kSetupType99:
		_app->setSpace(kZone4);
		_app->bagAdd(13899);
		_app->puzzleSetActive(kPuzzle13901);
		_app->sub_4A7790(2);
		break;

	case 20000:
		// The first chapter in the extras: the intro movies
		_app->setCurrentZone(kZoneSY);
		_app->playMovie("e00m01");
		_app->fadeOut(15, Color(0, 0, 0), 0);
		_app->playMovie("e00m03");
		_app->fadeOut(15, Color(0, 0, 0), 0);
		returnToMenu();
		break;

	case kSetupType30000:
	case 30001: {
		static const struct {
			ZoneId zone;
			const char *movie;
		} movies[] = {
			{ kZone2, "A01S01_E06M01" },
			{ kZone2, "A01S01_E06M02" },
			{ kZone2, "A01S01_E06M03" },
			{ kZone2, "A01S01_E06M04" },
			{ kZone4, "A01S04_E06M07" },
			{ kZone4, "A05S02_E06M12" }
		};

		// Chapters 21-26 (30001 plays the last one)
		int32 index = (type == 30001) ? 5 : _app->getChapterIndex() - 21;
		if (index >= 0 && index < (int32)ARRAYSIZE(movies)) {
			_app->setCurrentZone(movies[index].zone);
			_app->playMovie(movies[index].movie);
		}

		returnToMenu();
		}
		break;

	case 30002:
		_app->sub_4A7790(2);
		break;
	}
}

// 0x4aba41
void Zone7Faust::returnToMenu() {
	_app->setCurrentZone(kZoneSY);
	_app->soundPlay(90001, kSoundLoop);
	_app->puzzleSetActive(kPuzzleGeneralMenu);
}

// FAUST.EXE 0x4a06c0
void Zone7Faust::onButtonUp(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, const Common::Point &point) {
	switch (id) {
	default:
		break;

	case kObject19:
		// Clicking during the pact animation
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->varSetByte(49000, 1);
		_app->varSetByte(49003, 1);
		break;

	case kObject49000:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->puzzleSetActive(kPuzzle49000);
			_app->puzzleSetMod(kPuzzleMenu, 2, 19);
			_app->playMovie("A04S01N02A01");
			_app->soundStopAll(1024);
			_app->soundPlay(41011, kSoundLoop);
			pactLoop();
		}
		break;

	case kObject49003:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		switch (target) {
		default:
			break;

		case 0:
			_app->puzzleSetActive(kPuzzle49001);
			break;

		case 1:
			_app->objectSetAccessibilityOff(kObject49003, 0, 1);
			_app->objectPresentationShow(kObject49003);
			_app->varSetByte(49004, 1);
			_app->_vm->update();
			_app->soundPlay(41000, kSoundOnce);
			break;

		case 9:
			_app->rotationSetAlp(41002, 33.0f);
			_app->rotationSetBet(41002, 22.0f);
			_app->rotationSetRan(41002, 87.0f);
			_app->rotationSetActive(41002);

			if (_app->varGetByte(49004) == 1) {
				_app->displayFade("a04s02n01p03.bmp", "a04_black.bmp", 15, 0, kLoadFromCd, kArchiveArt);
				_app->soundStop(41001, 1024);
				_app->exitToMenu(kMenuAction0);
			}
			break;
		}
		break;
	}
}

// FAUST.EXE 0x4a08a0
void Zone7Faust::onAnimationNextFrame(Id animationId, const Common::String &name, uint32 frame, uint32 frameCount) {
	switch (animationId) {
	default:
		break;

	case 49000:
		// Faust and Mephisto talking: a click (object 19) during it picks the answer
		if (frame > 0)
			_app->objectSetAccessibilityOn(kObject19);

		if (frame != frameCount)
			break;

		_app->objectSetAccessibilityOff(kObject19);

		if (_app->varGetByte(49000) == 0) {
			_app->playMovie("A04S02N01P01S03");
			_app->varSetByte(49001, 1);
		} else {
			_app->playMovie("A04S02N01P01S04");
			_app->varSetByte(49001, 2);
		}

		_app->varSetByte(49000, 0);
		pactLoop();
		break;

	case 49005: {
		if (frame != frameCount)
			break;

		if (_app->soundIsPlaying(41001)) {
			_app->soundStop(41001, 1024);
			_app->soundStop(41002, 1024);
			_app->soundPlay(41003 + rnd(7), kSoundOnce);
		}

		_app->varSetByte(49002, _app->varGetByte(49002) + 1);

		uint32 index = rnd(7) + 4;
		if (index >= 7) {
			showPresentation(index, 49005);
		} else if (_app->varGetByte(49002) >= 15 && _app->varGetByte(49003)) {
			showPresentation(1, 49006);
		} else if (_app->varGetByte(49001) == 0) {
			showPresentation(2, 49000);
		} else if (_app->varGetByte(49001) == 1) {
			showPresentation(5, 49005);
			_app->varSetByte(49001, 0);
		} else if (_app->varGetByte(49001) == 2) {
			showPresentation(6, 49005);
			_app->varSetByte(49001, 0);
		}
		}
		break;

	case 49006:
		if (frame == frameCount) {
			if (_app->varGetByte(98014) == 0) {
				_app->soundPlay(41001, kSoundLoop);
				_app->rotationSetActive(41002);
			} else {
				returnToMenu();
			}
		} else if (frame == 30) {
			_app->soundStopAll(1024);
			_app->soundPlay(41013, kSoundOnce);
		}
		break;
	}
}

void Zone7Faust::showPresentation(uint32 index, Id animationId) {
	_app->objectPresentationShow(kObject49000, index);
	_app->objectPresentationSetAnimationOnPuzzle(kObject49000, index, 0, animationId);
}

// FAUST.EXE 0x4a0470: the pact scene in puzzle 49000. Plays random reaction movies
// until one of the talking animations is picked (they wait for a click on object 19)
// or the scene has run long enough, then signs the pact.
void Zone7Faust::pactLoop() {
	uint32 previous = 55;
	int32 count = _app->varGetByte(49002);

	while (count < 30) {
		++count;

		if (_app->varGetByte(49003) && count > 15)
			break;

		_app->soundPlay(41003 + rnd(7), kSoundOnce);

		uint32 index;
		do {
			index = rnd(7) + 4;
		} while (index == previous);
		previous = index;

		if (index > 6) {
			_app->playMovie(Common::String::format("A04S02N01P01S%02d", index));
		} else if (_app->varGetByte(49001) == 0) {
			showPresentation(2, 49000);
			_app->varSetByte(49002, count);
			return;
		} else if (_app->varGetByte(49001) == 1) {
			_app->playMovie("A04S02N01P01S05");
			_app->varSetByte(49001, 0);
		} else if (_app->varGetByte(49001) == 2) {
			_app->playMovie("A04S02N01P01S06");
			_app->varSetByte(49001, 0);
		}
	}

	_app->soundStopAll(1024);
	_app->puzzleSetMod(kPuzzleMenu, 1, 0);
	_app->playMovie("A04S02N01P01S01");

	if (_app->varGetByte(98014) == 0) {
		_app->soundPlay(41001, kSoundLoop);
		_app->rotationSetActive(41002);
	} else {
		returnToMenu();
	}
}

} // End of namespace Ring
