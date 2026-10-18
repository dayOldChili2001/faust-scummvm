/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 17
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 017110-1301, USA.
 */

#include "ring/game/faust/faust_zone17.h"

#include "ring/game/faust/faust_application.h"
#include "ring/game/faust/faust_shared.h"

#include "ring/base/saveload.h"

#include "ring/debug.h"
#include "ring/ring.h"
#include "ring/helpers.h"

using namespace FaustGame;

namespace Ring {

Zone17Faust::Zone17Faust(ApplicationFaust *application) : _app(application) {
}

Zone17Faust::~Zone17Faust() {
	// Zero-out passed pointers
	_app = nullptr;
}

void Zone17Faust::onInit() {
	_app->setCurrentZone(kZone17);

	_app->rotationAdd(141101, "A14S01N01R01", 0, 0);
	_app->rotationAdd(141102, "A14S01N02R01", 0, 1);
	_app->rotationAdd(141201, "A14S02N01R01", 0, 0);
	_app->rotationAdd(141202, "A14S02N02R01", 0, 2);
	_app->rotationAddMovabilityToRotation(141101, 141102, "", Common::Rect(3127, -68, 3396, 143), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(141101, 0, 280.0f, 0.0f, 87.0f, 0.0f, 2, 270.0f, 6.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(141102, 141201, "", Common::Rect(2626, -75, 2868, 368), false, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(141102, 0, 230.0f, 0.0f, 87.0f, 0.0f, 2, 250.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(141102, 141101, "", Common::Rect(1335, -101, 1687, 233), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(141102, 1, 100.0f, 0.0f, 87.0f, 0.0f, 2, 100.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(141201, 141202, "", Common::Rect(2831, -233, 3074, 301), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(141201, 0, 250.0f, 0.0f, 87.0f, 0.0f, 2, 250.0f, 0.0f, 87.0f);
	_app->rotationAddMovabilityToRotation(141201, 141102, "", Common::Rect(1030, -143, 1877, 550), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(141201, 1, 100.0f, 0.0f, 87.0f, 0.0f, 2, 100.0f, 0.0f, 87.0f);
	_app->objectAdd(kObject142003, "", "", 1);
	_app->objectAddRotationAccessibility(kObject142003, 141202, Common::Rect(1204, -186, 1771, 550), true, kCursorMove, 0);
	_app->objectAdd(kObject141001, "", "", 1);
	_app->objectAddRotationAccessibility(kObject141001, 141102, Common::Rect(3091, -34, 3418, 380), true, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject141001, 141102, Common::Rect(2997, 357, 3127, 438), true, kCursorTake, 1);
	_app->objectAddPresentation(kObject141001);
	_app->objectPresentationAddImageToRotation(141001, 0, 141102, 0);
	_app->objectAdd(kObject142002, "", "", 1);
	_app->objectAddRotationAccessibility(kObject142002, 141202, Common::Rect(3561, 22, 3600, 291), false, kCursorAction, 0);
	_app->objectAddRotationAccessibility(kObject142002, 141202, Common::Rect(0, 22, 277, 291), false, kCursorAction, 0);
	_app->objectAdd(kObjectMovieReel, "Movie reel", "a06_Reel", 9);
	_app->objectSetActiveCursor(kObjectMovieReel, Common::Point(20, 20), 0, kCursorTypeImage, 0, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectMovieReel, Common::Point(20, 20), 0, kCursorTypeImage, 0, 0, kLoadFromCursor);
	_app->objectAddRotationAccessibility(kObjectMovieReel, 141202, Common::Rect(548, 115, 710, 173), true, kCursorTake, 0);
	_app->objectAddRotationAccessibility(kObjectMovieReel, 141202, Common::Rect(3561, 22, 3600, 291), true, kCursorActionObject, 1);
	_app->objectAddRotationAccessibility(kObjectMovieReel, 141202, Common::Rect(0, 22, 277, 291), true, kCursorActionObject, 1);
	_app->objectAddPresentation(kObjectMovieReel);
	_app->objectPresentationAddImageToRotation(142001, 0, 141202, 0);
	_app->objectAddPresentation(kObjectMovieReel);
	_app->objectPresentationAddImageToRotation(142001, 1, 141202, 1);
	_app->objectPresentationShow(kObjectMovieReel, 0);
	_app->soundAdd(142005, kSoundTypeAmbientEffect, "14_Projector.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().ambientEffect.soundChunck);
	_app->soundAdd(141001, kSoundTypeAmbientMusic, "11_ZUN_ambience_crickets.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->rotationAddAmbientSound(141101, 141001, 90, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(141102, 141001, 90, 0, 1, 1, 10);
	_app->soundAdd(142002, kSoundTypeAmbientEffect, "11_TPM_recorder_insert_reel.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(142003, kSoundTypeAmbientEffect, "11_TPM_recorder_take_reel.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(142004, kSoundTypeAmbientEffect, "11_Door_close.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(143001, kSoundTypeDialog, "e05_18_1mef.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(143002, kSoundTypeDialog, "e05_18_2mef.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
	_app->soundAdd(143003, kSoundTypeDialog, "e05_18_3mef.wav", _app->getConfiguration().dialog.loadFrom, 2, _app->getConfiguration().dialog.soundChunck);
}

void Zone17Faust::onButtonUp(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, const Common::Point &point) {
	switch (id) {
	default:
		break;

	case kObject141001:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->playMovie("A14S01_E05M08");
			_app->objectPresentationShow(kObject141001, 0);
			_app->objectSetAccessibilityOff(kObject141001);
			_app->objectSetAccessibilityOn(kObject141001, 1, 1);
		} else {
			_app->objectPresentationHide(kObject141001);
			_app->rotationSetMovabilityOn(141102, 0, 0);
		}
		break;

	case kObjectMovieReel:
		if (_app->bagHasClickedObject()) {
			if (target == 1 && _app->bagGetClickedObject() == kObjectMovieReel) {
				// Reel on the projector
				_app->soundPlay(142002);
				_app->bagRemove(kObjectMovieReel);
				_app->objectPresentationHide(kObjectMovieReel, 0);
				_app->objectSetAccessibilityOn(kObject142002);
				_app->objectSetAccessibilityOff(kObjectMovieReel, 0, 0);
				_app->rotationSetRolTo(141202, 310.0f, 17.0f, 87.0f);
				_app->rotationSetRolTo(141202, 310.0f, 17.0f, 55.0f);
				_app->soundPlay(142005, kSoundLoop);
				_app->playMovie("INSERTS");
				_app->soundStop(142005, 1024);
				_app->rotationSetRan(141202, 87.0f);
				_app->objectSetAccessibilityOff(kObject142002);
				_app->objectSetAccessibilityOff(kObjectMovieReel);
			}

			_app->setField74(false);
			_app->cursorDelete();
			break;
		}

		if (target == 0) {
			_app->soundPlay(142003);
			_app->objectPresentationShow(kObjectMovieReel, 1);
			_app->bagAdd(kObjectMovieReel);
			_app->objectSetAccessibilityOff(kObjectMovieReel, 0, 0);
		} else {
			_app->setField74(false);
		}
		break;

	case kObject142003:
		if (_app->bagHasClickedObject())
			_app->cursorDelete();

		_app->rotationSetMovabilityOff(141201);
		_app->rotationSetAlp(141201, 180.0f);
		_app->rotationSetActive(141201);

		// Sets the progress animation frame (0x4dc040), it doesn't save
		if (_app->getSaveManager()->getData()->progressState == kProgressState5)
			_app->getSaveManager()->getData()->progress = 0x2a;

		_app->soundPlay(143001);
		break;
	}
}

void Zone17Faust::onSound(Id id, SoundType type, uint32 a3, bool process) {
	if (!process)
		return;

	switch (id) {
	default:
		break;

	case 143001:
		_app->soundPlay(143002);
		break;

	case 143002:
		_app->playMovie("a00s00_e05m10");
		_app->soundPlay(143003);
		break;

	case 143003:
		_app->playMovie("a14s02_e05m09");
		_app->fadeOut(15, Color(0, 0, 0), 0);
		_app->exitToMenu(kMenuAction0);
		break;
	}
}

void Zone17Faust::onAfterRide(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, MovabilityType movabilityType) {
	if (movabilityType == kMovabilityRotationToRotation) {
		switch (movabilityFrom) {
		default:
			break;

		case 141102:
			if (movabilityTo == 141201)
				_app->soundPlay(142004);
			break;

		case 141201:
		case 141202:
			_app->soundPlay(142004);
			break;
		}
	}
}

} // End of namespace Ring
