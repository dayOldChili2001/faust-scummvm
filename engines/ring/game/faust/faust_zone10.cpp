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

#include "ring/game/faust/faust_zone10.h"

#include "ring/game/faust/faust_application.h"
#include "ring/game/faust/faust_shared.h"

#include "ring/base/saveload.h"

#include "ring/debug.h"
#include "ring/ring.h"
#include "ring/helpers.h"

using namespace FaustGame;

namespace Ring {

Zone10Faust::Zone10Faust(ApplicationFaust *application) : _app(application) {
}

Zone10Faust::~Zone10Faust() {
	// Zero-out passed pointers
	_app = nullptr;
}

void Zone10Faust::onInit() {
	_app->setCurrentZone(kZone10);

	_app->puzzleAdd(kPuzzle71001);
	_app->puzzleAddBackgroundImage(kPuzzle71001, "a07s01n07p01.bmp", Common::Point(0, 16), true);
	_app->puzzleAdd(kPuzzle71002);
	_app->puzzleAddBackgroundImage(kPuzzle71002, "a07s01n11p01.bmp", Common::Point(0, 16), true);
	_app->rotationAdd(71001, "A07S01N01R01", 0, 0);
	_app->rotationAdd(71002, "A07S01N02R01", 0, 0);
	_app->rotationAdd(71003, "A07S01N03R01", 0, 0);
	_app->rotationAdd(71004, "A07S01N04R01", 0, 0);
	_app->rotationAdd(71005, "A07S01N05R01", 0, 0);
	_app->rotationAdd(71006, "A07S01N06R01", 0, 3);
	_app->rotationAdd(71015, "A07S01N15R01", 0, 2);
	_app->rotationAdd(71007, "A07S01N07R01", 0, 0);
	_app->rotationAdd(71008, "A07S01N08R01", 0, 0);
	_app->rotationAdd(71009, "A07S01N09R01", 0, 0);
	_app->rotationAdd(71010, "A07S01N10R01", 0, 1);
	_app->rotationAdd(71011, "A07S01N11R01", 0, 6);
	_app->rotationAdd(71012, "A07S01N12R01", 0, 0);
	_app->rotationAddMovabilityToRotation(71001, 71002, "", Common::Rect(2844, -75, 3044, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71001, 0, 249.0f, 0.3f, 87.0f, 0.0f, 2, 249.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71001, 71003, "", Common::Rect(2086, -75, 2286, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71001, 1, 174.0f, 0.3f, 87.0f, 0.0f, 2, 174.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71002, 71001, "", Common::Rect(1044, -75, 1244, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71002, 0, 69.0f, 0.3f, 87.0f, 0.0f, 2, 69.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71002, 71003, "", Common::Rect(1586, -75, 1786, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71002, 1, 124.0f, 0.3f, 87.0f, 0.0f, 2, 124.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71003, 71001, "", Common::Rect(286, -75, 486, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71003, 0, 354.0f, 0.3f, 87.0f, 0.0f, 2, 354.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71003, 71002, "", Common::Rect(3386, -75, 3586, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71003, 1, 304.0f, 0.3f, 87.0f, 0.0f, 2, 304.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71003, 71008, "", Common::Rect(2290, -75, 2490, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71003, 2, 194.0f, 0.3f, 87.0f, 0.0f, 2, 194.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71003, 71009, "", Common::Rect(2392, -75, 2592, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71003, 3, 204.0f, 0.3f, 87.0f, 0.0f, 2, 204.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71004, 71005, "", Common::Rect(1515, -75, 1715, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71004, 0, 117.0f, 0.3f, 87.0f, 0.0f, 2, 117.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71004, 71007, "", Common::Rect(2150, -75, 2350, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71004, 1, 180.0f, 0.3f, 87.0f, 0.0f, 2, 180.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71004, 71008, "", Common::Rect(2651, -75, 2851, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71004, 2, 230.0f, 0.3f, 87.0f, 0.0f, 2, 230.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71004, 71012, "", Common::Rect(3137, -75, 3337, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71004, 3, 279.0f, 0.3f, 87.0f, 0.0f, 2, 279.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71005, 71004, "", Common::Rect(3315, -75, 3515, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71005, 0, 297.0f, 0.3f, 87.0f, 0.0f, 2, 297.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71005, 71007, "", Common::Rect(2651, -75, 2851, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71005, 1, 230.0f, 0.3f, 87.0f, 0.0f, 2, 230.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71007, 71004, "", Common::Rect(350, -75, 550, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71007, 0, 0.0f, 0.3f, 87.0f, 0.0f, 2, 0.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71007, 71005, "", Common::Rect(851, -75, 1051, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71007, 1, 50.0f, 0.3f, 87.0f, 0.0f, 2, 50.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71007, 71008, "", Common::Rect(3300, -75, 3500, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71007, 2, 297.0f, 0.3f, 87.0f, 0.0f, 2, 297.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(71007, kPuzzle71001, "", Common::Rect(3550, -155, 3600, 127), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(71007, 3, 313.0f, 0.3f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToPuzzle(71007, kPuzzle71001, "", Common::Rect(0, -155, 75, 127), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(71007, 3, 313.0f, 0.3f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(71008, 71004, "", Common::Rect(851, -75, 1051, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71008, 0, 50.0f, 0.3f, 87.0f, 0.0f, 2, 50.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71008, 71007, "", Common::Rect(1515, -75, 1715, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71008, 1, 117.0f, 0.3f, 87.0f, 0.0f, 2, 117.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71008, 71009, "", Common::Rect(2791, -106, 3039, 108), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71008, 2, 247.0f, 0.3f, 87.0f, 0.0f, 2, 247.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71008, 71010, "", Common::Rect(984, -75, 1184, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71008, 3, 63.0f, 0.3f, 87.0f, 0.0f, 2, 63.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71008, 71011, "", Common::Rect(3315, -75, 3480, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71008, 4, 297.0f, 0.3f, 87.0f, 0.0f, 2, 297.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71008, 71012, "", Common::Rect(35, -122, 346, 134), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71008, 5, 315.0f, 0.3f, 87.0f, 0.0f, 2, 315.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71009, 71008, "", Common::Rect(956, -73, 1170, 127), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71009, 0, 64.0f, 0.3f, 87.0f, 0.0f, 2, 64.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71010, 71008, "", Common::Rect(2784, -75, 2984, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71010, 0, 243.0f, 0.3f, 87.0f, 0.0f, 2, 243.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71011, 71008, "", Common::Rect(1630, -300, 1980, 600), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71011, 0, 117.0f, 0.3f, 87.0f, 0.0f, 2, 117.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToPuzzle(71011, kPuzzle71002, "", Common::Rect(1086, 294, 1313, 452), true, kCursorZoom, 0);
	_app->rotationSetMovabilityToPuzzle(71011, 1, 77.0f, 39.0f, 85.7f, 0.0f, 2);
	_app->rotationAddMovabilityToRotation(71012, 71003, "", Common::Rect(984, -75, 1184, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71012, 0, 63.0f, 0.3f, 87.0f, 0.0f, 2, 63.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71012, 71004, "", Common::Rect(1337, -75, 1537, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71012, 1, 99.0f, 0.3f, 87.0f, 0.0f, 2, 99.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71012, 71008, "", Common::Rect(1700, -75, 1900, 250), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71012, 2, 135.0f, 0.3f, 87.0f, 0.0f, 2, 135.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71006, 71015, "", Common::Rect(2483, -89, 3018, 208), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71006, 0, 202.0f, 0.3f, 87.0f, 0.0f, 2, 202.0f, 0.3f, 87.0f);
	_app->rotationAddMovabilityToRotation(71015, 71006, "", Common::Rect(745, -227, 1246, 154), true, kCursorMove, 0);
	_app->rotationSetMovabilityToRotation(71015, 0, 70.0f, 0.3f, 87.0f, 0.0f, 2, 70.0f, 0.3f, 87.0f);
	_app->puzzleAddMovabilityToRotation(kPuzzle71001, 71007, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle71001, 0, 313.0f, 0.3f, 85.7f);
	_app->puzzleAddMovabilityToRotation(kPuzzle71002, 71011, "", Common::Rect(0, 420, 640, 464), true, kCursorBack, 0);
	_app->puzzleSetMovabilityToRotation(kPuzzle71002, 0, 77.0f, 39.0f, 85.7f);
	_app->objectAdd(kObjectFuse, "Fuse", "a06_fuse", 9);
	_app->objectSetActiveCursor(kObjectFuse, Common::Point(20, 20), 20, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectFuse, Common::Point(20, 20), 20, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectFuse, kPuzzle71002, Common::Rect(344, 220, 373, 289), true, kCursorTake, 2);
	_app->objectAddPuzzleAccessibility(kObjectFuse, kPuzzle71002, Common::Rect(344, 220, 373, 289), false, kCursorActionObject, 3);
	_app->objectAddPuzzleAccessibility(kObjectFuse, kPuzzle71002, Common::Rect(429, 238, 457, 303), false, kCursorTake, 4);
	_app->objectAddPuzzleAccessibility(kObjectFuse, kPuzzle71002, Common::Rect(429, 238, 457, 303), true, kCursorActionObject, 5);
	_app->objectAdd(kObjectRing2, "Ring", "a06_ring", 9);
	_app->objectSetActiveCursor(kObjectRing2, Common::Point(20, 20), 20, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectSetPassiveCursor(kObjectRing2, Common::Point(20, 20), 20, kCursorTypeImage, 0.0f, 0, kLoadFromCursor);
	_app->objectAddPuzzleAccessibility(kObjectRing2, kPuzzle71001, Common::Rect(435, 280, 479, 327), true, kCursorTake, 0);
	_app->objectAddPuzzleAccessibility(kObjectRing2, kPuzzle71002, Common::Rect(344, 220, 373, 289), false, kCursorTake, 2);
	_app->objectAddPuzzleAccessibility(kObjectRing2, kPuzzle71002, Common::Rect(429, 238, 457, 303), false, kCursorTake, 4);
	_app->objectAddPresentation(kObjectRing2);
	_app->objectPresentationAddImageToPuzzle(kObjectRing2, 0, kPuzzle71001, "a07s01n07p01l01.bmp", Common::Point(432, 276), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObjectRing2);
	_app->objectPresentationAddImageToRotation(kObjectRing2, 1, 71011, 0);
	_app->objectPresentationAddImageToPuzzle(kObjectRing2, 1, kPuzzle71002, "a07s01n11p01l00.bmp", Common::Point(316, 213), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObjectRing2);
	_app->objectPresentationAddImageToRotation(kObjectRing2, 2, 71011, 2);
	_app->objectPresentationAddImageToPuzzle(kObjectRing2, 2, kPuzzle71002, "a07s01n11p01l02.bmp", Common::Point(411, 227), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObjectRing2);
	_app->objectPresentationAddImageToRotation(kObjectRing2, 3, 71011, 3);
	_app->objectPresentationAddImageToPuzzle(kObjectRing2, 3, kPuzzle71002, "a07s01n11p01l03.bmp", Common::Point(321, 212), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObjectRing2);
	_app->objectPresentationAddImageToRotation(kObjectRing2, 4, 71011, 4);
	_app->objectPresentationAddImageToPuzzle(kObjectRing2, 4, kPuzzle71002, "a07s01n11p01l04.bmp", Common::Point(408, 232), true, kDrawTypeNormal, 1000);
	_app->objectAddPresentation(kObjectRing2);
	_app->objectPresentationAddImageToRotation(kObjectRing2, 5, 71011, 5);
	_app->objectPresentationAddImageToPuzzle(kObjectRing2, 5, kPuzzle71002, "a07s01n11p01l05.bmp", Common::Point(397, 365), true, kDrawTypeNormal, 1000);
	_app->objectPresentationShow(kObjectRing2, 5);
	_app->objectAdd(kObject71002, "", "", 1);
	_app->objectAddPuzzleAccessibility(kObject71002, kPuzzle71002, Common::Rect(222, 31, 284, 150), true, kCursorAction, 0);
	_app->objectAddPresentation(kObject71002);
	_app->objectPresentationAddAnimationToPuzzle(kObject71002, 0, kPuzzle71002, "a07s01n11p01s01", kImageTypeBMP, Common::Point(164, 25), kDrawTypeNormal, 1000, 12, 12.5f, 6);
	_app->objectAddPresentation(kObject71002);
	_app->objectPresentationAddAnimationToPuzzle(kObject71002, 1, kPuzzle71002, "a07s01n11p01s01", kImageTypeBMP, Common::Point(164, 25), kDrawTypeNormal, 1000, 12, 12.5f, 10);
	_app->objectAdd(kObject71003, "", "", 1);
	_app->objectAddRotationAccessibility(kObject71003, 71010, Common::Rect(1364, -205, 1531, 230), false, kCursorMove, 0);
	_app->objectAddPresentation(kObject71003);
	_app->objectPresentationAddImageToRotation(kObject71003, 0, 71010, 0);
	_app->objectAdd(kObject71201, "", "", 1);
	_app->objectAddRotationAccessibility(kObject71201, 71006, Common::Rect(965, -536, 1089, -485), true, kCursorActionObject, 0);
	_app->objectAddRotationAccessibility(kObject71201, 71015, Common::Rect(2037, 28, 2202, 183), false, kCursorTake, 1);
	_app->objectAddPresentation(kObject71201);
	_app->objectPresentationAddImageToRotation(kObject71201, 0, 71006, 2);
	_app->objectPresentationAddImageToRotation(kObject71201, 0, 71006, 1);
	_app->objectAddPresentation(kObject71201);
	_app->objectPresentationAddImageToRotation(kObject71201, 1, 71006, 0);
	_app->objectAddPresentation(kObject71201);
	_app->objectPresentationAddImageToRotation(kObject71201, 2, 71015, 1);
	_app->objectAddPresentation(kObject71201);
	_app->objectPresentationAddImageToRotation(kObject71201, 3, 71015, 0);
	_app->objectPresentationShow(kObject71201, 2);
	_app->objectPresentationShow(kObject71201, 3);
	_app->soundAdd(71001, kSoundTypeAmbientEffect, "07_generic_put.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(71002, kSoundTypeAmbientEffect, "07_generic_take.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(71006, kSoundTypeAmbientEffect, "0701_put_rinka.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(71005, kSoundTypeAmbientEffect, "0701_take_rinka.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(71004, kSoundTypeAmbientEffect, "0701_handle_za_carousel.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(71007, kSoundTypeAmbientEffect, "0701_Carusel_Stops.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(71008, kSoundTypeAmbientEffect, "0701_Handle.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundAdd(71009, kSoundTypeAmbientEffect, "0701_step.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(71009, 90);
	_app->soundAdd(71010, kSoundTypeAmbientEffect, "0701_door_close.wav", _app->getConfiguration().ambientEffect.loadFrom, 1, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->soundSetVolume(71010, 85);
	_app->soundAdd(71003, kSoundTypeAmbientMusic, "07_ZUN_ambience_crickets.was", _app->getConfiguration().ambientEffect.loadFrom, 2, _app->getConfiguration().backgroundMusic.soundChunck);
	_app->rotationAddAmbientSound(71006, 71003, 85, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(71015, 71003, 85, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(71001, 71003, 85, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(71002, 71003, 85, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(71003, 71003, 85, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(71004, 71003, 85, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(71005, 71003, 85, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(71007, 71003, 85, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(71008, 71003, 85, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(71009, 71003, 85, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(71010, 71003, 85, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(71011, 71003, 82, 0, 1, 1, 10);
	_app->rotationAddAmbientSound(71012, 71003, 82, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle71001, 71003, 85, 0, 1, 1, 10);
	_app->puzzleAddAmbientSound(kPuzzle71002, 71003, 82, 0, 1, 1, 10);
	_app->varDefineByte(71000, 0);
	_app->varDefineByte(71001, 1);
}

void Zone10Faust::onTimer(TimerId id) {
	if (id == kTimer0) {
		if (rnd(5) == 3) {
			_app->objectPresentationHide(kObject71201, 2);
			_app->objectPresentationShow(kObject71201, 0);

			handleEvents();

			_app->objectPresentationHide(kObject71201, 0);
			_app->objectPresentationShow(kObject71201, 2);
		}
	}
}

// FAUST.EXE 0x499de0
void Zone10Faust::onButtonUp(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, const Common::Point &point) {
	switch (id) {
	default:
		break;

	case kObjectFuse:
		if (_app->bagHasClickedObject()) {
			if (target == 3) {
				if (_app->bagGetClickedObject() == kObjectRing2) {
					_app->soundPlay(71006);
					_app->bagRemove(kObjectRing2);
					_app->varSetByte(71000, 1);
					_app->objectSetAccessibilityOff(kObjectFuse, 1, 1);
					_app->objectSetAccessibilityOn(kObjectRing2, 1, 1);
					_app->objectPresentationHide(kObjectRing2, 1);
					_app->objectPresentationShow(kObjectRing2, 3);
				} else if (_app->bagGetClickedObject() == kObjectFuse) {
					_app->bagRemove(kObjectFuse);
					_app->soundPlay(71001);
					_app->varSetByte(71001, 1);
					_app->objectSetAccessibilityOff(kObjectFuse, 1, 1);
					_app->objectSetAccessibilityOn(kObjectFuse, 0, 0);
					_app->objectPresentationHide(kObjectRing2, 1);
					_app->objectPresentationHide(kObjectRing2, 3);
				}
			} else if (target == 5) {
				if (_app->bagGetClickedObject() == kObjectRing2) {
					_app->bagRemove(kObjectRing2);
					_app->soundPlay(71006);
					_app->varSetByte(71000, 2);
					_app->objectSetAccessibilityOff(kObjectFuse, 3, 3);
					_app->objectSetAccessibilityOn(kObjectRing2, 2, 2);
					_app->objectPresentationHide(kObjectRing2, 4);
					_app->objectPresentationShow(kObjectRing2, 2);
				} else if (_app->bagGetClickedObject() == kObjectFuse) {
					_app->soundPlay(71001);
					_app->bagRemove(kObjectFuse);
					_app->varSetByte(71001, 2);
					_app->objectSetAccessibilityOff(kObjectFuse, 3, 3);
					_app->objectSetAccessibilityOn(kObjectFuse, 2, 2);
					_app->objectPresentationHide(kObjectRing2, 2);
					_app->objectPresentationShow(kObjectRing2, 4);
				}
			}

			if (_app->varGetByte(71000) + _app->varGetByte(71001) > 0)
				_app->objectPresentationShow(kObjectRing2, 5);

			_app->setField74(false);
			_app->cursorDelete();
			break;
		}

		if (target == 2) {
			_app->bagAdd(kObjectFuse);
			_app->soundPlay(71002);
			_app->varSetByte(71001, 0);
			_app->objectSetAccessibilityOff(kObjectFuse, 0, 0);
			_app->objectSetAccessibilityOn(kObjectFuse, 1, 1);
			_app->objectPresentationHide(kObjectRing2, 3);
			_app->objectPresentationShow(kObjectRing2, 1);
		} else if (target == 4) {
			_app->bagAdd(kObjectFuse);
			_app->soundPlay(71002);
			_app->varSetByte(71001, 0);
			_app->objectSetAccessibilityOff(kObjectFuse, 2, 2);
			_app->objectSetAccessibilityOn(kObjectFuse, 3, 3);
			_app->objectPresentationHide(kObjectRing2, 2);
			_app->objectPresentationHide(kObjectRing2, 4);
		} else {
			_app->setField74(false);
		}

		if (_app->varGetByte(71000) + _app->varGetByte(71001) == 0)
			_app->objectPresentationHide(kObjectRing2, 5);
		break;

	case kObjectRing2:
		if (_app->bagHasClickedObject()) {
			_app->setField74(false);
			_app->cursorDelete();
			break;
		}

		if (target == 2) {
			_app->bagAdd(kObjectRing2);
			_app->soundPlay(71005);
			_app->varSetByte(71000, 0);
			_app->objectSetAccessibilityOff(kObjectRing2, 1, 1);
			_app->objectSetAccessibilityOn(kObjectFuse, 1, 1);
			_app->objectPresentationHide(kObjectRing2, 3);
			_app->objectPresentationShow(kObjectRing2, 1);
		} else if (target == 4) {
			_app->bagAdd(kObjectRing2);
			_app->soundPlay(71005);
			_app->varSetByte(71000, 0);
			_app->objectSetAccessibilityOff(kObjectRing2, 2, 2);
			_app->objectSetAccessibilityOn(kObjectFuse, 3, 3);
			_app->objectPresentationHide(kObjectRing2, 4);
			_app->objectPresentationHide(kObjectRing2, 2);
		} else {
			if (target == 0) {
				_app->bagAdd(kObjectRing2);
				_app->soundPlay(71005);
				_app->objectPresentationShow(kObjectRing2, 0);
			}

			_app->setField74(false);
		}

		if (_app->varGetByte(71000) + _app->varGetByte(71001) == 0)
			_app->objectPresentationHide(kObjectRing2, 5);
		break;

	case kObject71002:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->objectPresentationSetAnimationOnPuzzle(kObject71002, 0, 0, 71000);
		_app->objectPresentationShow(kObject71002, 0);
		_app->soundPlay(71008);
		break;

	case kObject71003:
		if (_app->bagHasClickedObject()) {
			_app->cursorDelete();
			break;
		}

		_app->playMovie("A07S01N10A02");
		_app->setupRotation(3);
		break;

	case kObject71201:
		if (_app->bagHasClickedObject()) {
			if (target == 0 && _app->bagGetClickedObject() == kObjectHomunculus) {
				_app->timerStop(kTimer0);
				_app->objectPresentationShow(kObject71201, 0);
				_app->objectPresentationHide(kObject71201, 2);
				_app->soundPlay(71001);
				_app->_vm->update();
				_app->_vm->update();
				_app->_vm->update();
				_app->rotationSetRolTo(71006, 90.0f, 20.0f, 87.0f);
				_app->rotationSetRolTo(71006, 220.0f, 0.0f, 87.0f);
				_app->playMovie("A07S01_E02M05");
				_app->rotationSetAlp(71015, 180.0f);
				_app->rotationSetBet(71015, 0.0f);
				_app->rotationSetRan(71015, 87.0f);
				_app->rotationSetActive(71015);
				_app->objectPresentationShow(kObject71201, 1);
				_app->objectPresentationHide(kObject71201, 3);
				_app->objectSetAccessibilityOff(kObject71201, 0, 0);
				_app->objectSetAccessibilityOn(kObject71201, 1, 1);
			}

			_app->cursorDelete();
			break;
		}

		if (target == 1) {
			_app->objectPresentationHide(kObject71201, 1);
			_app->objectPresentationShow(kObject71201, 3);
			_app->soundPlay(71002);
			_app->_vm->update();
			_app->_vm->update();
			_app->_vm->update();
			_app->objectPresentationShow(kObject14, 16);
			_app->_vm->update();
			_app->_vm->update();
			_app->_vm->update();
			_app->_vm->update();
			_app->_vm->update();
			_app->fadeOut(15, Color(0, 0, 0), 0);

			// FAUST.EXE 0x49a4f3 sets the progress animation frame (0x4dc040), it doesn't save
			if (_app->getSaveManager()->getData()->progressState == kProgressState2)
				_app->getSaveManager()->getData()->progress = 0x13;

			_app->exitToMenu(kMenuAction4);
		}
		break;
	}
}

// FAUST.EXE 0x49a6d0
void Zone10Faust::onAnimationNextFrame(Id animationId, const Common::String &name, uint32 frame, uint32 frameCount) {
	if (animationId != 71000 || frame != frameCount)
		return;

	_app->objectPresentationHide(kObject71002);

	int32 count = _app->varGetByte(71000) + _app->varGetByte(71001);

	if (count == 1) {
		_app->soundPlay(71004);
		_app->playMovie("A07S01N11A01");
	} else if (count == 2) {
		_app->soundPlay(71004);
		_app->playMovie("A07S01N11A02");
		_app->soundPlay(71007);
	} else if (count > 2) {
		// Advances the progress animation frame (0x4dc040), it doesn't save
		if (_app->getSaveManager()->getData()->progressState == kProgressState5)
			_app->getSaveManager()->getData()->progress++;

		_app->soundPlay(71004);
		_app->playMovie("A07S01N11A02");
		_app->playMovie("A07S01N11A02b");
		_app->soundPlay(71007);
		_app->objectSetAccessibilityOn(kObject71003);
		_app->objectPresentationShow(kObject71003);
	}

	_app->objectPresentationShow(kObject71002, 1);
}

// FAUST.EXE 0x49a5f0 (onAfterRide gets the new rotation first, then the previous one)
void Zone10Faust::onAfterRide(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, MovabilityType movabilityType) {
	_app->soundPlay(71009);

	if (movabilityType == kMovabilityRotationToRotation) {
		switch (movabilityFrom) {
		default:
			break;

		case 71011:
			if (movabilityTo == 71008)
				_app->soundPlay(71010);
			break;

		case 71008:
			if (movabilityTo == 71011)
				_app->soundPlay(71010);
			break;
		}
	}
}

} // End of namespace Ring
