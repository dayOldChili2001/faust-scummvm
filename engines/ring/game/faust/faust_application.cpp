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

#include "ring/game/faust/faust_application.h"

#include "ring/base/accessibility.h"
#include "ring/base/art.h"
#include "ring/base/bag.h"
#include "ring/base/cursor.h"
#include "ring/base/dialog.h"
#include "ring/base/movability.h"
#include "ring/base/object.h"
#include "ring/base/preferences.h"
#include "ring/base/puzzle.h"
#include "ring/base/rotation.h"
#include "ring/base/saveload.h"
#include "ring/base/timer.h"

#include "ring/game/faust/faust_shared.h"
#include "ring/game/faust/faust_zonesystem.h"
#include "ring/game/faust/faust_zone2.h"
#include "ring/game/faust/faust_zone3.h"
#include "ring/game/faust/faust_zone4.h"
#include "ring/game/faust/faust_zone5.h"
#include "ring/game/faust/faust_zone6.h"
#include "ring/game/faust/faust_zone7.h"
#include "ring/game/faust/faust_zone8.h"
#include "ring/game/faust/faust_zone9.h"
#include "ring/game/faust/faust_zone10.h"
#include "ring/game/faust/faust_zone11.h"
#include "ring/game/faust/faust_zone12.h"
#include "ring/game/faust/faust_zone13.h"
#include "ring/game/faust/faust_zone14.h"
#include "ring/game/faust/faust_zone15.h"
#include "ring/game/faust/faust_zone16.h"
#include "ring/game/faust/faust_zone17.h"

#include "ring/graphics/drag_control.h"
#include "ring/graphics/hotspot.h"
#include "ring/graphics/image.h"
#include "ring/graphics/screen.h"

#include "ring/sound/sound_handler.h"

#include "ring/debug.h"
#include "ring/helpers.h"
#include "ring/ring.h"

using namespace FaustGame;

namespace Ring {

#pragma region Screen lists

// List of credits screens
static const struct {
	Common::String filename;
	uint32 ticksWait;
	LoadFrom loadFrom;
	ArchiveType archiveType;
} creditsScreens[7] = {
	{"cre1.bmp",    0, kLoadFromDisk, kArchiveArt},
	{"cre2.bmp",    0, kLoadFromDisk, kArchiveArt},
	{"cre3.bmp",    0, kLoadFromDisk, kArchiveArt},
	{"cre4.bmp",    0, kLoadFromDisk, kArchiveArt},
	{"cre5.bmp",    0, kLoadFromDisk, kArchiveArt},
	{"cre6.bmp",    0, kLoadFromDisk, kArchiveArt},
	{"cre7.bmp", 5000, kLoadFromDisk, kArchiveArt},
};

#pragma endregion

ApplicationFaust::ApplicationFaust(RingEngine *engine) : Application(engine) {
	_slot = -1;
	_zone = kZoneNone;
	_controlNotPressed = true;

	// Event handlers
	_zoneSystem = new ZoneSystemFaust(this);
	_zone2      = new Zone2Faust(this);
	_zone3      = new Zone3Faust(this);
	_zone4      = new Zone4Faust(this);
	_zone5      = new Zone5Faust(this);
	_zone6      = new Zone6Faust(this);
	_zone7      = new Zone7Faust(this);
	_zone8      = new Zone8Faust(this);
	_zone9      = new Zone9Faust(this);
	_zone10     = new Zone10Faust(this);
	_zone11     = new Zone11Faust(this);
	_zone12     = new Zone12Faust(this);
	_zone13     = new Zone13Faust(this);
	_zone14     = new Zone14Faust(this);
	_zone15     = new Zone15Faust(this);
	_zone16     = new Zone16Faust(this);
	_zone17     = new Zone17Faust(this);
}

ApplicationFaust::~ApplicationFaust() {
	SAFE_DELETE(_zoneSystem);
	SAFE_DELETE(_zone2);
	SAFE_DELETE(_zone3);
	SAFE_DELETE(_zone4);
	SAFE_DELETE(_zone5);
	SAFE_DELETE(_zone6);
	SAFE_DELETE(_zone7);
	SAFE_DELETE(_zone8);
	SAFE_DELETE(_zone9);
	SAFE_DELETE(_zone10);
	SAFE_DELETE(_zone11);
	SAFE_DELETE(_zone12);
	SAFE_DELETE(_zone13);
	SAFE_DELETE(_zone14);
	SAFE_DELETE(_zone15);
	SAFE_DELETE(_zone16);
	SAFE_DELETE(_zone17);
}

#pragma region Game setup

void ApplicationFaust::initLanguages() {
	languageAdd(kLanguageEnglish, "ENG", "ENG", 1);
	languageAdd(kLanguageFrench,  "FRA", "FRA", 2);
	languageAdd(kLanguageGerman,  "GER", "GER", 3);
	languageAdd(kLanguageItalian, "ITA", "ITA", 1);
	languageAdd(kLanguageSpanish, "SPA", "SPA", 2);
	languageAdd(kLanguageDutch,   "HOL", "HOL", 3);
	languageAdd(kLanguageSwedish, "SWE", "SWE", 4);
}

void ApplicationFaust::initFont() {
	// Original asks for size 12, but the font only contains size 9
	fontAdd(kFontDefault, "arxrin3.fon", "HelveticaLight", 9, true, false, false, false, getCurrentLanguage());
}

void ApplicationFaust::setup() {
	// Add the list of episodes
	addEpisode(kZone2, "One",   2);
	addEpisode(kZone3, "Two",   2);
	addEpisode(kZone4, "Three", 4);
	addEpisode(kZone5, "Four",  3);
	addEpisode(kZone6, "Five",  3);
	addEpisode(kZone7, "Six",   1);
	addEpisode(kZone8, "Seven", 4);
	addEpisode(kZone9, "Eight", 5);

	// Add the list of zones
	addZone(kZone2,  "A01S01", "a01s01", kArchiveArt, kLoadFromCd);
	addZone(kZone3,  "A01S02", "a01s02", kArchiveArt, kLoadFromCd);
	addZone(kZone4,  "A01S03", "a01s03", kArchiveArt, kLoadFromCd);
	addZone(kZone5,  "A01S07", "a01s07", kArchiveArt, kLoadFromCd);
	addZone(kZone6,  "A03S01", "a03s01", kArchiveArt, kLoadFromCd);
	addZone(kZone7,  "A04S01", "a04s01", kArchiveArt, kLoadFromCd);
	addZone(kZone8,  "A05S03", "a05s03", kArchiveArt, kLoadFromCd);
	addZone(kZone9,  "A06S01", "a06s01", kArchiveArt, kLoadFromCd);
	addZone(kZone10, "A07S01", "a07s01", kArchiveArt, kLoadFromCd);
	addZone(kZone11, "A07S02", "a07s02", kArchiveArt, kLoadFromDisk);
	addZone(kZone12, "A08S01", "a08s01", kArchiveArt, kLoadFromCd);
	addZone(kZone13, "A09S01", "a09s01", kArchiveArt, kLoadFromCd);
	addZone(kZone14, "A11S01", "a11s01", kArchiveArt, kLoadFromCd);
	addZone(kZone15, "A12S01", "a12s01", kArchiveArt, kLoadFromCd);
	addZone(kZone16, "A13S01", "a13s01", kArchiveArt, kLoadFromCd);
	addZone(kZone17, "A14S01", "a14s01", kArchiveArt, kLoadFromCd);

	// Setup system zone
	setupZone(kZoneSY, kSetupTypeNone);
	setSpace(kZoneSY);

	// Setup cursors
	ArchiveType archiveType = (_configuration.artCURSOR ? kArchiveArt : kArchiveFile);

	cursorAdd(kCursorDefault,       "",                 kCursorTypeNormal,   1, kLoadFromCursor, archiveType);
	cursorAdd(kCursorBusy,          "cur_busy",         kCursorTypeImage,    1, kLoadFromCursor, archiveType);
	cursorAdd(kCursorIdle,          "cur_menuidle",     kCursorTypeImage,    1, kLoadFromCursor, archiveType);
	cursorAdd(kCursorMove,          "cur_muv",          kCursorTypeAnimated, 1, 18, 15.0f, 4, kLoadFromCursor, archiveType);
	cursorAdd(kCursorBack,          "cur_back",         kCursorTypeAnimated, 1, 15, 12.5f, 4, kLoadFromCursor, archiveType);
	cursorAdd(kCursorMenuIdle,      "sy_right",         kCursorTypeImage,    1, kLoadFromCursor, archiveType);
	cursorAdd(kCursorMenuActive,    "cur_menuactive",   kCursorTypeImage,    1, kLoadFromCursor, archiveType);
	cursorAdd(kCursorShoot,         "cur_shoot",        kCursorTypeImage,    1, kLoadFromCursor, archiveType);
	cursorAdd(kCursorZoom,          "cur_zoom",         kCursorTypeAnimated, 1, 15, 12.5f, 4, kLoadFromCursor, archiveType);
	cursorAdd(kCursorTake,          "cur_take",         kCursorTypeAnimated, 1, 20, 15.0f, 4, kLoadFromCursor, archiveType);
	cursorAdd(kCursorAction,        "cur_action",       kCursorTypeImage,    1, kLoadFromCursor, archiveType);
	cursorAdd(kCursorActionObject,  "cur_actionobject", kCursorTypeImage,    1, kLoadFromCursor, archiveType);
	cursorAdd(kCursorDragDrop,      "cur_drag_dp",      kCursorTypeImage,    1, kLoadFromCursor, archiveType);

	// Adjust offsets
	cursorSetOffset(kCursorBusy,         Common::Point(15, 15));
	cursorSetOffset(kCursorIdle,         Common::Point(5, 3));
	cursorSetOffset(kCursorMove,         Common::Point(20, 20));
	cursorSetOffset(kCursorBack,         Common::Point(10, 20));
	cursorSetOffset(kCursorMenuIdle,     Common::Point(5, 3));
	cursorSetOffset(kCursorMenuActive,   Common::Point(5, 3));
	cursorSetOffset(kCursorZoom,         Common::Point(20, 20));
	cursorSetOffset(kCursorTake,         Common::Point(14, 14));
	cursorSetOffset(kCursorAction,       Common::Point(14, 14));
	cursorSetOffset(kCursorActionObject, Common::Point(14, 14));
	cursorSetOffset(kCursorDragDrop,     Common::Point(14, 14));

	// Setup subtitles
	subtitleSetColor(Color(255, 255, 255));
	subtitleSetBackgroundColor(Color(50, 50, 50));
}

void ApplicationFaust::initBag() {
	_bag->setOrigin(Common::Point(0, 0));
	_bag->sub_417D40(15, 26, 40, 61);
	_bag->setBackgroundOffset(Common::Point(0, 0));
	_bag->sub_417DD0(10);
	_bag->sub_417D80(0, 0, 30, 448);
	_bag->sub_417DA0(610, 0, 30, 448);
	_bag->sub_4192A0(6, 12);
	_bag->sub_4192C0(622, 12);
	_bag->sub_417DE0(99, 0);
	_bag->sub_419280(500);
	_bag->loadBackground("bagbgr.tga", "", "", "", "", "", "", "bag_hl.bmp", _archiveType);
	_bag->initHotspots();
}

#pragma endregion

#pragma region Startup

void ApplicationFaust::showStartupScreen() {
	setCurrentZone(kZoneSY);

	playMovie("logo");
	fadeOut(15, Color(0, 0, 0), 0);

	playMovie("e00m01");
	fadeOut(15, Color(0, 0, 0), 0);

	playMovie("e00m03");
	fadeOut(15, Color(0, 0, 0), 0);
}

void ApplicationFaust::startMenu(bool savegame) {
	initMenuSave(savegame);
	initMenu2();
	initMenu3();

	if (_currentGameZone)
		return;

	if (savegame) {
		cursorSelect(kCursorBusy);
		_vm->setFlag(false);
		_bag->reset();

		// The in-game menu saves to SaveGame_<chapter>, which saveAs copies when the player saves
		Common::String filename = Common::String::format("SaveGame_%d", (int8)varGetByte(98001));
		if (!_saveManager->loadSave(filename, kLoadSaveWrite))
			error("[ApplicationFaust::startMenu] Cannot save game: %s", filename.c_str());

		// Save a copy of the screen surface for savegame
		SAFE_DELETE(_thumbnail);

		_thumbnail = new ImageSurface();
		_thumbnail->create(24, 2, 640, 480);

		// Save a copy of the screen to our image
		_screenManager->copySurface(_thumbnail);
	}

	_currentGameZone = getCurrentEpisode();

	soundStopAll(4);
	timerStopAll();
	setupZone(kZoneSY, kSetupTypeNone);
	setSpace(kZoneSY);
	puzzleSetActive(kPuzzleGeneralMenu, true, true);
	puzzleSetMod(kPuzzleMenu, 1, 0);

	for (uint32 i = 1; i <= 25; i++) {
		objectSetAccessibilityOff(i);
		objectPresentationHideAndRemove(i);
	}

	Bag *bag = getBag();
	if (bag && bag->isInitialized())
		bag->reset();

	cursorDelete();
}

void ApplicationFaust::showMenu(ZoneId zone, MenuAction menuAction) {
	if (zone != kZoneSY) {
		exitZone();
		initZones();
	}

	switch (zone) {
	default:
		break;

	case kZoneSY:
		switch (menuAction) {
		default:
			break;

		case kMenuAction0:
			loadAndStartLogin();
			break;

		case kMenuAction1:
			loadAndInitZone();
			break;

		case kMenuAction3:
			initZone();
			break;

		case kMenuAction10:
			exitZone();
			initZones();
			startLogin(kPuzzlePreferences);
			break;
		}
		break;

	case kZone2:
		if (menuAction == kMenuAction1) {
			setCurrentZone(kZoneSY);
			_slot = -1;
			startMenu(false);
		}
		break;

	case kZone3:
		if (menuAction == kMenuAction0)
			setupZone(kZone2, kSetupType2);
		break;

	case kZone4:
		if (menuAction == kMenuAction0)
			setProgressAndShowMenu(kProgressState7);
		break;

	case kZone6:
		if (menuAction == kMenuAction0)
			setProgressAndShowMenu(kProgressState2);
		break;

	case kZone7:
		if (menuAction == kMenuAction0)
			setupZone(kZone2, kSetupType3);
		break;

	case kZone8:
		switch (menuAction) {
		default:
			break;

		case kMenuAction0:
			setCurrentZone(kZoneSY);
			varSetByte(98001, kProgressState8);
			setCurrentZone(kZoneSY);
			_slot = -1;
			startMenu(false);
			break;

		case kMenuAction2:
			setupZone(kZone8, kSetupType2);
			break;

		case kMenuAction3:
			varSetByte(98001, kProgressState8);
			setCurrentZone(kZoneSY);
			_slot = -1;
			startMenu(false);
			break;
		}
		break;

	case kZone9:
		if (menuAction == kMenuAction0)
			setupZone(kZone6, kSetupType3);
		break;

	case kZone10:
		switch (menuAction) {
		default:
			break;

		case kMenuAction2:
			setupZone(kZone6, kSetupType2);
			break;

		case kMenuAction4:
			setSpace(kZone14);
			playMovie("1001");
			fadeOut(15, Color(0, 0, 0), 0);

			setProgressAndShowMenu(kProgressState3);
			break;
		}
		break;

	case kZone11:
		switch (menuAction) {
		default:
			break;

		case kMenuAction1:
			_saveManager->loadSave("Rabbit", kLoadSaveRead);
			puzzleSetMod(kPuzzleMenu, 1, 0);
			break;

		case kMenuAction4:
			setProgressAndShowMenu(kProgressState4);
			break;
		}
		break;

	case kZone12:
		if (menuAction == kMenuAction0)
			setupZone(kZone4, kSetupType3);
		break;

	case kZone13:
		if (menuAction == kMenuAction0)
			setProgressAndShowMenu(kProgressState4);
		break;

	case kZone14:
		switch (menuAction) {
		default:
			break;

		case kMenuAction0:
			setupZone(kZone3, kSetupType3);
			break;

		case kMenuAction1:
		case kMenuAction2:
			playMovie("Surogat");
			break;
		}
		break;

	case kZone15:
		if (menuAction == kMenuAction0)
			setupZone(kZone5, kSetupType2);
		break;

	case kZone16:
		if (menuAction == kMenuAction0)
			setProgressAndShowMenu(kProgressState5);
		break;

	case kZone17:
		if (menuAction == kMenuAction0)
			setProgressAndShowMenu(kProgressState6);
		break;
	}
}

void ApplicationFaust::setProgressAndShowMenu(ProgressState progress) {
	if (getSaveManager()->getData()->progressState < progress) {
		getSaveManager()->getData()->progressState = progress;
		getSaveManager()->saveProgress(progress);
	}

	varSetByte(98001, progress);
	setCurrentZone(kZoneSY);
	_slot = -1;
	startMenu(false);
}

void ApplicationFaust::loadAndStartLogin() {
	// Get clicked object
	ObjectId objectId = visualListGetObjectIdClicked(4, kPuzzleGeneralMenu);
	if (!objectId)
		error("[ApplicationFaust::loadAndStartLogin] No object clicked");

	// Get icon name
	Common::String iconName = getObject(objectId)->getName();
	if (iconName.empty())
		error("[ApplicationFaust::loadAndStartLogin] Object does not have an icon name (%d)", objectId.id());

	exitZone();
	initZones();

	if (getSaveManager()->loadSave(iconName, kLoadSaveRead)) {
		varSetByte(98003, 0);
	} else {
		// Reload autosave
		Common::String filename = Common::String::format("Savegame_%d", varGetByte(98001));

		// Try reloading autosave
		if (!getSaveManager()->loadSave(filename, kLoadSaveRead)) {
			warning("[ApplicationFaust::loadAndStartLogin] Cannot reload autosave after failed load (%s)", filename.c_str());

			exitZone();
			initZones();
			startLogin(kPuzzlePreferences);
		}

		messageFormat("CanNotLoadGame", filename);
		messageShowWarning(0);
	}
}

void ApplicationFaust::loadAndInitZone() {
	// Set current zone
	ZoneId zone = (ZoneId)varGetByte(98001);
	getSaveManager()->getData()->zone = zone;

	if (getSaveManager()->hasZoneSavegame()) {
		exitZone();
		initZones();

		Common::String filename = Common::String::format("Savegame_%d", zone);
		if (!getSaveManager()->loadSave(filename, kLoadSaveRead)) {
			warning("[ApplicationFaust::loadAndInitZone] Can not load game (%s)", filename.c_str());

			exitZone();
			initZones();
			startLogin(kPuzzlePreferences);

			messageFormat("CanNotLoadGame", filename);
			messageShowWarning(0);

			return;
		}

		varSetByte(99000, -1);
		varSetByte(98001, zone);

		return;
	}

	// No savegame, setup the zone
	switch (zone) {
	default:
		break;

	case kZoneSY:
		exitZone();
		initZones();
		setupZone(kZone2, kSetupType1);
		break;

	case kZone2:
		exitZone();
		initZones();
		setupZone(kZone3, kSetupType1);
		break;

	case kZone3:
		exitZone();
		initZones();
		setupZone(kZone4, kSetupType1);
		break;

	case kZone4:
		exitZone();
		initZones();
		setupZone(kZone5, kSetupType1);
		break;

	case kZone5:
		exitZone();
		initZones();
		setupZone(kZone6, kSetupType1);
		break;

	case kZone6:
		exitZone();
		initZones();
		setupZone(kZone7, kSetupType1);
		break;

	case kZone7:
		exitZone();
		initZones();
		setupZone(kZone8, kSetupType1);
		break;
	}

	// Save zone
	varSetByte(99000, -1);
	varSetByte(98001, zone);
}

void ApplicationFaust::initZone() {
	bool resetZones = true;

	switch (varGetByte(98001)) {
	default:
		resetZones = false;
		break;

	case kZoneSY:
		setupZone(kZone2, kSetupType1);
		break;

	case kZone2:
		setupZone(kZone3, kSetupType1);
		break;

	case kZone3:
		setupZone(kZone4, kSetupType1);
		break;

	case kZone4:
		setupZone(kZone5, kSetupType1);
		break;

	case kZone5:
		setupZone(kZone6, kSetupType1);
		break;

	case kZone6:
		setupZone(kZone7, kSetupType1);
		break;

	case kZone7:
		setupZone(kZone8, kSetupType1);
		break;
	}

	if (resetZones) {
		exitZone();
		initZones();
	}

	varSetByte(98003, 0);
	varSetByte(98002, 1);
	varSetByte(98001, _zone);
}

void ApplicationFaust::initMenuSave(bool savegame) {
	int8 slot = varGetByte(98001);

	varSetByte(99000, 0);
	varSetByte(99001, 1);
	varSetByte(99002, 1);
	varSetByte(99003, 0);
	varSetByte(99004, 0);
	varSetByte(99005, 0);
	varSetByte(99006, 0);
	varSetByte(99007, 0);
	varSetByte(99008, 0);
	varSetByte(99009, 0);

	if (slot <= 0) {
		if (slot == 0) {
			varSetByte(99005, 1);
			varSetByte(99006, 1);
			varSetByte(99007, 1);
			varSetByte(99008, 1);
			varSetByte(99009, 1);
		}
	} else {
		varSetByte(99005, 0);

		if (slot == getSaveManager()->getData()->progressState) {
			varSetByte(99001, 0);
		} else if (slot < getSaveManager()->getData()->progressState) {
			varSetByte(99000, 1);
			varSetByte(99001, 0);
		} else {
			varSetByte(99000, 1);
		}
	}

	if (savegame) {
		_slot = slot;
		varSetByte(98089, 0);
	}

	if (_slot == slot) {
		varSetByte(99000, 0);
		varSetByte(99002, 0);
	} else {
		varSetByte(99002, 1);
	}

	for (uint32 i = 1; i < (uint32)getSaveManager()->getData()->progressState; i++) {
		if (i < 9)
			objectPresentationShow(99600, i - 1);
	}

	if (varGetByte(98012) == getSaveManager()->getData()->progressState)
		if (varGetByte(98012) > 0)
			objectPresentationShow(99600, getSaveManager()->getData()->progressState - 1);

	if (getSaveManager()->getData()->progressState > 1 && getSaveManager()->getData()->progressState >= slot) {
		objectPresentationShow(99600, 7);
		objectSetAccessibilityOn(14, 2, 2);

		switch (slot) {
		default:
			break;

		case 1:
		case 3:
		case 5:
		case 7:
			if (getSaveManager()->getData()->progressState > slot)
				objectSetAccessibilityOn(99100);
			break;
		}
	}

	puzzleSetMod(kPuzzleMenu, 1, 0);
	objectSetAccessibilityOff(kObjectPipe);
	objectSetAccessibilityOff(kObject22);
	objectSetAccessibilityOff(kObject20);
	objectSetAccessibilityOff(kObject114503);
}

void ApplicationFaust::initMenu2()  {
	int8 slot = varGetByte(98001);

	objectPresentationShow(99012, 0);
	objectPresentationHide(99011);

	if (slot >= 8)
		objectPresentationShow(99011, 7);
	else
		objectPresentationShow(99011, (byte)slot);

	for (uint32 i = 99000; i < 99010; i++) {
		objectPresentationHide(i, 0);
		objectPresentationHide(i, 1);

		if (varGetByte(i) > 0)
			objectPresentationShow(i, 1);
	}

	objectPresentationShow(99010, 0);
	objectPresentationShow(99010, 1);
	objectPresentationShow(99010, 3);
}

void ApplicationFaust::initMenu3() {
	for (uint32 i = 99000; i < 99010; i++) {
		objectSetAccessibilityOn(i);

		if (varGetByte(i) > 0)
			objectSetAccessibilityOff(i);
	}
}

void ApplicationFaust::showCredits() {
	soundStopAll(1024);
	setCurrentZone(kZoneSY);
	soundSetVolume(52000, 100);
	soundPlay(52000, kSoundLoop);

	// Scroll credits
	for (uint i = 0; i < ARRAYSIZE(creditsScreens); i++) {
		if (scrollImage(creditsScreens[i].filename, creditsScreens[i].ticksWait, creditsScreens[i].loadFrom, creditsScreens[i].archiveType))
			break;
	}

	fadeOut(15, Color(0, 0, 0), 0);
	soundStop(52000, 1024);
}

// Only used to skip the menu (RING_DEBUG_SKIPMENU). It starts a new game the way
// PLAY does once a user has logged in (exitToMenu(1) with no savegame).
void ApplicationFaust::startGame() {
	if (!_preferenceHandler)
		error("[ApplicationFaust::startGame] Preference handler not initialized properly");

	_preferenceHandler->load();

	varSetByte(98001, 1);
	setupZone(kZone2, kSetupType1);
}

#pragma endregion

#pragma region Drawing

void ApplicationFaust::draw() {
	// Update our screen
	_screenManager->updateScreen();

	// FAUST.EXE 0x402420: start each frame from the screen position, which drawing a
	// rotation then converts to panorama coordinates
	_rotationPoint = _vm->getCoordinates();

	// Update engine state
	switch (_state){
	default:
		break;

	case kStateNone:
		return;

	case kStateUpdateRotation:
		if (!_rotation)
			error("[ApplicationRing::draw] No active rotation!");

		if (!checkEscape()) {
			if (_rotation->getState() != 0) {
				if (_rotation->getState() == 3) {
					_rotation->destroyImage();
					_rotation->setState(0);
				}
			} else {
				if (_rotation->hasImage())
					_rotation->setState(3);
			}
		}

		if (_rotation->getState() != 0) {
			if (_rotation->getState() == 3) {
				_rotation->loadImage();
				_rotation->drawImage();
				_rotation->drawText();
			}
		} else {
			_rotation->alloc();
			_rotation->update();

			// An animation callback can switch to a puzzle and deallocate the rotation
			if (_state != kStateUpdateRotation || !_rotation)
				break;

			_rotationPoint = _vm->getCoordinates();
			_rotation->setCoordinates(&_rotationPoint, Common::KEYCODE_INVALID);
			_rotation->draw();
			_rotation->drawText();
		}

		break;

	case kStateUpdatePuzzle:
		_puzzle->alloc();
		_puzzle->update();
		break;

	case kStateDrawBag:
		getBag()->draw();
		break;

	case kStateShowMenu:
		showMenu(getCurrentZone(), _menuAction);
		return;
	}

	// Update menu puzzle
	if (_puzzles.has(kPuzzleMenu)) {
		Puzzle *puzzleMenu = _puzzles.get(kPuzzleMenu);

		puzzleMenu->alloc();
		puzzleMenu->update();
	}

	// Draw bag
	Bag *bag = getBag();
	if (bag && bag->isInitialized())
		bag->draw();

	// Open bag
	if (_vm->isMouseButtonPressed())
		updateBag(_vm->getCoordinates());

	// Update bag, puzzle & rotation
	if (_vm->getFlag())
		update(_vm->getCoordinates());
	else
		_vm->setFlag(true);

	// Play dialogs
	if (_dialogHandler)
		_dialogHandler->play();

	// Update animated cursors
	if (_cursorHandler->getType() == kCursorTypeImage || _cursorHandler->getType() == kCursorTypeAnimated)
		_cursorHandler->draw();
}

#pragma endregion

#pragma region Message

void ApplicationFaust::messageInsertCd(ZoneId zone) {
	setupZone(kZoneSY, kSetupTypeNone);
	setSpace(kZoneSY);

	for (uint32 i = 0; i <= 25; i++) {
		objectSetAccessibilityOff(i);
		objectPresentationHideAndRemove(i);
	}

	objectPresentationSetTextToPuzzle(kObject55, 1, 0, _messageType);
	objectPresentationSetTextCoordinatesToPuzzle(kObject55, 1, 0, Common::Point(225, 193));
	objectPresentationSetTextToPuzzle(kObject55, 1, 1, _message);
	objectPresentationSetTextCoordinatesToPuzzle(kObject55, 1, 1, Common::Point(225, 213));
	objectPresentationShow(kObject55, 0);
	objectSetAccessibilityOff(kObject55);
	objectSetAccessibilityOn(kObject55, zone, zone);
	objectSetAccessibilityOn(kObject55, 10, 10);
	puzzleSetActive(kPuzzleInsertCd);
}

#pragma endregion

#pragma region Zone setup

void ApplicationFaust::initZones() {
	debugC(kRingDebugLogic, "Init zone data");

	_loadFrom = kLoadFromDisk;

	drawZoneName(kZoneSY);
	_archiveType = getZoneArchiveType(kZoneSY);
	_zoneSystem->onInit();

	_loadFrom = kLoadFromCd;

	drawZoneName(kZone2);
	_archiveType = getZoneArchiveType(kZone2);
	_zone2->onInit();

	drawZoneName(kZone2);
	_archiveType = getZoneArchiveType(kZone3);
	_zone3->onInit();

	drawZoneName(kZone4);
	_archiveType = getZoneArchiveType(kZone4);
	_zone4->onInit();

	drawZoneName(kZone5);
	_archiveType = getZoneArchiveType(kZone5);
	_zone5->onInit();

	drawZoneName(kZone6);
	_archiveType = getZoneArchiveType(kZone6);
	_zone6->onInit();

	drawZoneName(kZone7);
	_archiveType = getZoneArchiveType(kZone7);
	_zone7->onInit();

	drawZoneName(kZone8);
	_archiveType = getZoneArchiveType(kZone8);
	_zone8->onInit();

	drawZoneName(kZone9);
	_archiveType = getZoneArchiveType(kZone9);
	_zone9->onInit();

	drawZoneName(kZone10);
	_archiveType = getZoneArchiveType(kZone10);
	_zone10->onInit();

	_loadFrom = kLoadFromDisk;

	drawZoneName(kZone11);
	_archiveType = getZoneArchiveType(kZone11);
	_zone11->onInit();

	_loadFrom = kLoadFromCd;

	drawZoneName(kZone12);
	_archiveType = getZoneArchiveType(kZone12);
	_zone12->onInit();

	drawZoneName(kZone13);
	_archiveType = getZoneArchiveType(kZone13);
	_zone13->onInit();

	drawZoneName(kZone14);
	_archiveType = getZoneArchiveType(kZone14);
	_zone14->onInit();

	drawZoneName(kZone15);
	_archiveType = getZoneArchiveType(kZone15);
	_zone15->onInit();

	drawZoneName(kZone16);
	_archiveType = getZoneArchiveType(kZone16);
	_zone16->onInit();

	drawZoneName(kZone17);
	_archiveType = getZoneArchiveType(kZone17);
	_zone17->onInit();

	_archiveType = getZoneArchiveType(getCurrentZone());

	setState(kStateNone);

	// Clear screen
	_screenManager->clear();
	g_system->updateScreen();
}

void ApplicationFaust::setupZone(ZoneId zone, SetupType type) {
	debugC(kRingDebugLogic, "Setting up zone %s", getZoneName(zone).c_str());

	// The original asks for the zone's CD here. loadConfiguration() only accepts
	// a full DVD copy, so every zone's data is present (and Faust has no
	// language packs: there is no pack.ini in FAUST.EXE).
	bool hasLanguage = true;
	bool hasData = true;

	reset();
	soundStopAll(8);

	if (_soundHandler)
		_soundHandler->reset();

	if (zone != kZoneSY)
		_artHandler->reset();

	if (hasData && hasLanguage) {
		setCurrentEpisode(zone);
		setZone(zone, type);
	} else {
		_saveManager->setSetupType(type);

		if (hasData)
			messageGet("TurnDVD");
		else {
			messageFormat("InsertCD", getEpisodeCd(zone));
		}

		messageInsertCd(zone);
	}
}

#pragma endregion

#pragma region Event handling

// Input handling follows FAUST.EXE: the window procedure (0x401ac0) forwards
// WM_LBUTTONUP to 0x472060/0x472090 (plain/CTRL click, both ending in 0x470f20),
// WM_LBUTTONDOWN to 0x470810, WM_RBUTTONUP to 0x4720c0 and WM_CHAR plus
// VK_DELETE to 0x472150. These are engine routines shared with Ring, so the logic
// mirrors ApplicationRing, plus the checks Faust's executable adds.

void ApplicationFaust::onMouseLeftButtonUp(const Common::Event &evt, bool isControlPressed) {
	_controlNotPressed = !isControlPressed;

	handleMouseLeftButtonUp(evt.mouse);
}

void ApplicationFaust::handleMouseLeftButtonUp(const Common::Point &point) {
	// Handle clicks on bag
	Bag *bag = getBag();
	if (bag->isInitialized()) {
		if (bag->checkHotspotClick(point) == 1) {
			onBagClickedObject(bag->getClickedObject());

			if (getState() == kStateShowMenu)
				return;

			if (getField77()) {
				bag->reset();
				setFreOffCurrentRotation();

				if (getField78()) {
					initObjectCursors(bag->getClickedObject());
				} else {
					setField78(true);
					cursorDelete();
				}

				// Center cursor on screen
				g_system->warpMouse(320, 240);
			} else {
				setField77(true);
				cursorDelete();
			}
		}

		return;
	}

	// Handle clicks on drag control
	DragControl *dragControl = getDragControl();
	if (dragControl->getField20()) {
		bool stopProcessing = (dragControl->getField45() == 2);

		onBag(dragControl->getObjectId(), dragControl->getTarget(), dragControl->getPuzzleRotationId(), dragControl->getField39(), dragControl, 2);

		if (getState() == kStateShowMenu)
			return;

		dragControl->reset();

		if (stopProcessing)
			return;
	}

	// Handle clicks on menu
	Puzzle *puzzleMenu = getPuzzle(kPuzzleMenu);
	if (puzzleMenu) {
		if (puzzleMenu->visualHandleLeftButtonUp(point)) {
			update(point);
			return;
		}

		if (handleLeftButtonUp(getPuzzleAccessibility(puzzleMenu, point), puzzleMenu->getId(), point))
			return;

		if (puzzleMenu->getField24() == 1) {
			Movability *movability = puzzleMenu->getMovability(point);
			if (handleLeftButtonUp(movability, (uint32)puzzleMenu->getMovabilityIndex(point), puzzleMenu->getId()))
				return;
		}

		if (puzzleMenu->getField24() == 2)
			return;
	}

	// Handle current puzzle
	Puzzle *currentPuzzle = getCurrentPuzzle();
	if (currentPuzzle) {
		if (currentPuzzle->visualHandleLeftButtonUp(point)) {
			update(point);
			return;
		}

		if (handleLeftButtonUp(getPuzzleAccessibility(currentPuzzle, point), currentPuzzle->getId(), point))
			return;

		Movability *movability = currentPuzzle->getMovability(point);
		if (handleLeftButtonUp(movability, (uint32)currentPuzzle->getMovabilityIndex(point), currentPuzzle->getId()))
			return;
	}

	// Handle current rotation
	Rotation *currentRotation = getCurrentRotation();
	if (currentRotation) {
		// FAUST.EXE 0x4717f2 returns while the rotation is loading or showing an image (state != 0)
		if (currentRotation->getState())
			return;

		Accessibility *accessibility = currentRotation->getAccessibility(_rotationPoint);
		if (handleLeftButtonUp(accessibility, currentRotation->getId(), point))
			return;

		Movability *movability = currentRotation->getMovability(_rotationPoint);
		if (handleLeftButtonUp(movability, (uint32)currentRotation->getMovabilityIndex(_rotationPoint), currentRotation->getId(), true))
			return;

		if (getField75())
			cursorDelete();

		setField75(true);
	}
}

Accessibility *ApplicationFaust::getPuzzleAccessibility(Puzzle *puzzle, const Common::Point &point) {
	Accessibility *accessibility = puzzle->getAccessibility(point);

	// While a puzzle is modal (mod 2, e.g. a message box), only the selected object reacts to clicks
	if (accessibility && puzzle->getField24() == 2 && accessibility->getObject()->getId() != puzzle->getSelectedId())
		return nullptr;

	return accessibility;
}

bool ApplicationFaust::handleLeftButtonUp(Accessibility *accessibility, Id id, const Common::Point &point) {
	if (!accessibility)
		return false;

	Object *object = accessibility->getObject();
	Hotspot *hotspot = accessibility->getHotspot();

	if (object->getFieldC() & 1) {
		onButtonUp(object->getId(), hotspot->getTarget(), id, 1, point);

		if (getState() == kStateShowMenu)
			return true;
	}

	if (!(object->getFieldC() & 8)) {
		update(point);
		return true;
	}

	// The zone dispatcher for this event (0x47a9e0) only reaches empty handlers in Faust

	if (getField74()) {
		cursorDelete();
		getBag()->setClickedObject(object->getId());
		initObjectCursors(object->getId());
	}

	setField74(true);

	update(point);

	return true;
}

bool ApplicationFaust::handleLeftButtonUp(Movability *movability, uint32 index, Id id, bool isRotation) {
	if (!movability)
		return false;

	Hotspot *hotspot = movability->getHotspot();

	//////////////////////////////////////////////////////////////////////////
	// Before Ride
	//////////////////////////////////////////////////////////////////////////
	onBeforeRide(id, movability->getTo(), index, hotspot->getTarget(), movability->getType());

	if (getState() == kStateShowMenu)
		return true;

	bool showRide = _controlNotPressed;

	if (isRotation) {
		int updateType = 2;
		if (_controlNotPressed)
			updateType = movability->getUpdateType();
		else
			showRide = false;

		switch (updateType) {
		default:
			break;

		case 0:
			showRide = getCurrentRotation()->setRolTo(movability->getAlpBefore(), movability->getBetBefore(), movability->getRanBefore());
			break;

		case 1:
			getCurrentRotation()->updateAndDraw(movability->getAlpBefore(), movability->getBetBefore(), movability->getRanBefore());
			break;
		}
	}

	reset();

	switch (movability->getType()) {
	default:
		break;

	case kMovabilityRotationToRotation:
	case kMovabilityPuzzleToRotation:
		if (isRotation)
			break;

		if (getRotation(movability->getTo())) {
			Rotation *rotation = getRotation(movability->getTo());

			float alp = movability->getAlpAfter() - 135.0f;
			if (alp < 0.0f)
				alp += 360.0f;

			rotation->setAlp(alp);

			rotation->updateAmbientSoundPan(false);

			getSoundHandler()->setSounds2(rotation->getSoundItems());
			getSoundHandler()->setField0(true);

			if (!getSoundHandler()->processSounds()) {
				getSoundHandler()->setField0(false);
				getSoundHandler()->turnOffSounds1(true);
			}
		}
		break;

	case kMovabilityRotationToPuzzle:
	case kMovabilityPuzzleToPuzzle:
		if (getPuzzle(movability->getTo().id())) {
			Puzzle *puzzle = getPuzzle(movability->getTo().id());

			getSoundHandler()->setSounds2(puzzle->getSoundItems());
			getSoundHandler()->setField0(true);

			if (!getSoundHandler()->processSounds()) {
				getSoundHandler()->setField0(false);
				getSoundHandler()->turnOffSounds1(true);
			}
		}
		break;
	}

	//////////////////////////////////////////////////////////////////////////
	// Ride
	//////////////////////////////////////////////////////////////////////////
	if (showRide)
		playMovie(movability->getRideName());

	//////////////////////////////////////////////////////////////////////////
	// After ride
	//////////////////////////////////////////////////////////////////////////
	if (getSoundHandler()->getField0()) {
		getSoundHandler()->turnOffItems1();

		if (!getSoundHandler()->updateItems(2)) {
			getSoundHandler()->turnOffSounds1(true);
			getSoundHandler()->setField0(false);
		}
	}

	if (getSoundHandler()->getField0()) {
		getSoundHandler()->updateItems2(3);
		getSoundHandler()->updateItems3(3);
	}

	switch (movability->getType()) {
	default:
		break;

	case kMovabilityRotationToRotation:
	case kMovabilityPuzzleToRotation:
		rotationSetActive(movability->getTo());
		getCurrentRotation()->updateAndDraw(movability->getAlpAfter(), movability->getBetAfter(), movability->getRanAfter());

		onAfterRide(getCurrentRotationId(), id, index, hotspot->getTarget(), movability->getType());

		if (getState() == kStateShowMenu)
			return true;
		break;

	case kMovabilityRotationToPuzzle:
	case kMovabilityPuzzleToPuzzle:
		puzzleSetActive(movability->getTo().id());

		onAfterRide(getCurrentRotationId(), id, index, hotspot->getTarget(), movability->getType());

		if (getState() == kStateShowMenu)
			return true;
		break;
	}

	if (getField75())
		cursorDelete();

	setField75(true);

	return true;
}

void ApplicationFaust::onMouseLeftButtonDown(const Common::Event &evt) {
	if (getBag()->isInitialized())
		return;

	// Handle menu
	Puzzle *puzzleMenu = getPuzzle(kPuzzleMenu);
	if (puzzleMenu) {
		if (puzzleMenu->visualHandleLeftButtonDown(evt.mouse)) {
			update(evt.mouse);
			return;
		}

		Accessibility *accessibility = getPuzzleAccessibility(puzzleMenu, evt.mouse);
		if (handleLeftButtonDown(accessibility, (uint32)puzzleMenu->getAccessibilityIndex(evt.mouse), puzzleMenu->getId(), evt.mouse))
			return;

		if (puzzleMenu->getField24() == 2)
			return;
	}

	// Handle current puzzle
	Puzzle *currentPuzzle = getCurrentPuzzle();
	if (currentPuzzle) {
		if (currentPuzzle->visualHandleLeftButtonDown(evt.mouse)) {
			update(evt.mouse);
			return;
		}

		Accessibility *accessibility = getPuzzleAccessibility(currentPuzzle, evt.mouse);
		if (handleLeftButtonDown(accessibility, (uint32)currentPuzzle->getAccessibilityIndex(evt.mouse), currentPuzzle->getId(), evt.mouse))
			return;
	}

	// Handle current rotation
	Rotation *currentRotation = getCurrentRotation();
	if (currentRotation) {
		Accessibility *accessibility = currentRotation->getAccessibility(_rotationPoint);
		if (handleLeftButtonDown(accessibility, (uint32)currentRotation->getAccessibilityIndex(_rotationPoint), currentRotation->getId(), evt.mouse))
			return;
	}
}

bool ApplicationFaust::handleLeftButtonDown(Accessibility *accessibility, uint32 index, Id id, const Common::Point &point) {
	if (!accessibility)
		return false;

	Object *object = accessibility->getObject();
	Hotspot *hotspot = accessibility->getHotspot();

	if (object->getFieldC() & 2) {
		onButtonDown(object->getId(), hotspot->getTarget(), id, 1, point);

		if (getState() == kStateShowMenu)
			return true;
	}

	if (!(object->getFieldC() & 4)) {
		update(point);
		return true;
	}

	getDragControl()->init(point, object->getId(), index, hotspot, hotspot->getTarget(), id, 1);
	onBag(object->getId(), hotspot->getTarget(), id, 1, getDragControl(), 1);

	if (getState() != kStateShowMenu) {
		if (!getField76())
			getDragControl()->reset();

		setField76(true);
		update(point);
	}

	return true;
}

void ApplicationFaust::onMouseRightButtonUp(const Common::Event &evt) {
	debugC(kRingDebugLogic, "onMouseRightButtonUp");

	if (getDragControl()->getField20() || getCurrentGameZone())
		return;

	Puzzle *puzzleMenu = getPuzzle(kPuzzleMenu);
	if (puzzleMenu && puzzleMenu->getField24() == 2)
		return;

	Bag *bag = getBag();
	if (bag->isInitialized()) {
		bag->reset();
		setFreOffCurrentRotation();
		return;
	}

	cursorDelete();
	sub_45FF30();

	bag->initialize();

	if (getCurrentRotation())
		bag->setRotationFre(getCurrentRotation()->getFre());

	setupCurrentRotation();
}

void ApplicationFaust::onKeyDown(Common::Event &evt) {
	debugC(kRingDebugLogic, "onKeyDown");

	// Function keys arrive through WM_KEYDOWN in the original, with auto-repeat ignored
	switch (evt.kbd.keycode) {
	default:
		break;

	case Common::KEYCODE_F3:
		if (!evt.kbdRepeat && getCurrentRotation())
			getCurrentRotation()->setFreOnOff(!getCurrentRotation()->getFre());
		return;

	case Common::KEYCODE_F12:
		if (!evt.kbdRepeat)
			startMenu(true);
		return;
	}

	// Stop dialogs if needed
	if (evt.kbd.keycode == Common::KEYCODE_ESCAPE)
		soundStopType(kSoundTypeDialog, 4098);

	// Check menu and simulate button click
	Puzzle *puzzleMenu = getPuzzle(kPuzzleMenu);
	if (puzzleMenu) {
		if (puzzleMenu->visualHandleKey(evt.kbd.keycode))
			return;

		if (puzzleMenu->getField24() == 2) {
			Accessibility *accessibility = puzzleMenu->getAccessibility(evt.kbd.keycode);
			if (!accessibility)
				return;

			// Center rotation
			evt.mouse = accessibility->getHotspot()->getCenter();
			if (hasCurrentRotation())
				getCurrentRotation()->setCoordinates(&evt.mouse, evt.kbd.keycode);

			simulateClick(evt, (evt.kbd.flags & Common::KBD_CTRL) != 0, true);
			return;
		}
	}

	// Handle events on zone (only the system zone has a key handler in Faust)
	_zoneSystem->onKeyDown(evt.kbd);

	if (getState() == kStateShowMenu)
		return;

	// Check current puzzle and simulate button click
	if (hasCurrentPuzzle()) {
		Puzzle *currentPuzzle = getCurrentPuzzle();

		if (currentPuzzle->visualHandleKey(evt.kbd.keycode))
			return;

		Accessibility *accessibility = currentPuzzle->getAccessibility(evt.kbd.keycode);
		if (!accessibility)
			return;

		evt.mouse = accessibility->getHotspot()->getCenter();

		simulateClick(evt, (evt.kbd.flags & Common::KBD_CTRL) != 0, false);
		return;
	}

	// Check current rotation and simulate button click
	Rotation *currentRotation = getCurrentRotation();
	if (currentRotation) {
		Accessibility *accessibility = currentRotation->getAccessibility(evt.kbd.keycode);
		if (!accessibility)
			return;

		evt.mouse = accessibility->getHotspot()->getCenter();

		// Center rotation
		currentRotation->setCoordinates(&evt.mouse, evt.kbd.keycode);

		simulateClick(evt, (evt.kbd.flags & Common::KBD_CTRL) != 0, false);
	}
}

void ApplicationFaust::simulateClick(Common::Event &evt, bool isControlPressed, bool clickTwiceWithBag) {
	if (getBag()->isInitialized()) {
		onMouseLeftButtonUp(evt, isControlPressed);

		// For the menu puzzle, a plain click with the bag open is sent twice (the first one closes the bag)
		if (!clickTwiceWithBag || isControlPressed || getState() == kStateShowMenu)
			return;
	}

	onMouseLeftButtonUp(evt, isControlPressed);

	// When the click lands on the top bar, the original then calls 0x470f00,
	// which only fetches the menu puzzle and has no side effects
}

void ApplicationFaust::onButtonDown(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, const Common::Point &point) {
	debugC(kRingDebugLogic, "onButtonDown (ObjectId: %d, coords: (%d, %d))", id.id(), point.x, point.y);

	if (puzzleRotationId == 1 && a4 == 1) {
		_zoneSystem->onButtonDown(id, target, puzzleRotationId, a4, point);
		return;
	}

	switch (getCurrentZone()) {
	default:
		break;

	case kZoneSY:
		_zoneSystem->onButtonDown(id, target, puzzleRotationId, a4, point);
		break;

	case kZone5:
		_zone5->onButtonDown(id, target, puzzleRotationId, a4, point);
		break;
	}
}

void ApplicationFaust::onButtonUp(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, const Common::Point &point) {
	debugC(kRingDebugLogic, "onButtonUp (ObjectId: %d, target: %d, coords: (%d, %d))", id.id(), target, point.x, point.y);

	if (puzzleRotationId == 1 && a4 == 1) {
		_zoneSystem->onButtonUp(id, target, puzzleRotationId, a4, point);
		return;
	}

	switch (getCurrentZone()) {
	default:
		break;

	case kZoneSY:
		_zoneSystem->onButtonUp(id, target, puzzleRotationId, a4, point);
		break;

	case kZone2:
		_zone2->onButtonUp(id, target, puzzleRotationId, a4, point);
		break;

	case kZone3:
		_zone3->onButtonUp(id, target, puzzleRotationId, a4, point);
		break;

	case kZone4:
		_zone4->onButtonUp(id, target, puzzleRotationId, a4, point);
		break;

	case kZone5:
		_zone5->onButtonUp(id, target, puzzleRotationId, a4, point);
		break;

	case kZone6:
		_zone6->onButtonUp(id, target, puzzleRotationId, a4, point);
		break;

	case kZone7:
		_zone7->onButtonUp(id, target, puzzleRotationId, a4, point);
		break;

	case kZone8:
		_zone8->onButtonUp(id, target, puzzleRotationId, a4, point);
		break;

	case kZone9:
		_zone9->onButtonUp(id, target, puzzleRotationId, a4, point);
		break;

	case kZone10:
		_zone10->onButtonUp(id, target, puzzleRotationId, a4, point);
		break;

	case kZone11:
		_zone11->onButtonUp(id, target, puzzleRotationId, a4, point);
		break;

	case kZone12:
		_zone12->onButtonUp(id, target, puzzleRotationId, a4, point);
		break;

	case kZone13:
		_zone13->onButtonUp(id, target, puzzleRotationId, a4, point);
		break;

	case kZone14:
		_zone14->onButtonUp(id, target, puzzleRotationId, a4, point);
		break;

	case kZone15:
		_zone15->onButtonUp(id, target, puzzleRotationId, a4, point);
		break;

	case kZone16:
		_zone16->onButtonUp(id, target, puzzleRotationId, a4, point);
		break;

	case kZone17:
		_zone17->onButtonUp(id, target, puzzleRotationId, a4, point);
		break;
	}
}

void ApplicationFaust::onSetup(ZoneId zone, SetupType type) {
	switch (zone) {
	default:
		break;

	case kZone2:
		_zone2->onSetup(type);
		break;

	case kZone3:
		_zone3->onSetup(type);
		break;

	case kZone4:
		_zone4->onSetup(type);
		break;

	case kZone5:
		_zone5->onSetup(type);
		break;

	case kZone6:
		_zone6->onSetup(type);
		break;

	case kZone7:
		_zone7->onSetup(type);
		break;

	case kZone8:
		_zone8->onSetup(type);
		break;
	}
}

void ApplicationFaust::onUpdateBefore(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, const Common::Point &point) {
	if (movabilityIndex == 1 && target == 1) {
		_zoneSystem->onUpdateBefore(movabilityFrom, movabilityTo, movabilityIndex, target, point);
		return;
	}

	switch (getCurrentZone()) {
	default:
		break;

	case kZoneSY:
		_zoneSystem->onUpdateBefore(movabilityFrom, movabilityTo, movabilityIndex, target, point);
		break;

	case kZone3:
		_zone3->onUpdateBefore(movabilityFrom, movabilityTo, movabilityIndex, target, point);
		break;

	case kZone4:
		_zone4->onUpdateBefore(movabilityFrom, movabilityTo, movabilityIndex, target, point);
		break;

	case kZone6:
		_zone6->onUpdateBefore(movabilityFrom, movabilityTo, movabilityIndex, target, point);
		break;

	case kZone8:
		_zone8->onUpdateBefore(movabilityFrom, movabilityTo, movabilityIndex, target, point);
		break;

	case kZone12:
		_zone12->onUpdateBefore(movabilityFrom, movabilityTo, movabilityIndex, target, point);
		break;

	case kZone14:
		_zone14->onUpdateBefore(movabilityFrom, movabilityTo, movabilityIndex, target, point);
		break;

	case kZone15:
		_zone15->onUpdateBefore(movabilityFrom, movabilityTo, movabilityIndex, target, point);
		break;

	case kZone16:
		_zone16->onUpdateBefore(movabilityFrom, movabilityTo, movabilityIndex, target, point);
		break;
	}
}

void ApplicationFaust::onTimer(TimerId timerId) {
	debugC(kRingDebugLogic, "[ApplicationFaust::onTimer] Timer id: %d", timerId);

	switch (getCurrentZone()) {
	default:
		break;

	case kZoneSY:
		_zoneSystem->onTimer(timerId);
		break;

	case kZone2:
		_zone2->onTimer(timerId);
		break;

	case kZone3:
		_zone3->onTimer(timerId);
		break;

	case kZone4:
		_zone4->onTimer(timerId);
		break;

	case kZone5:
		_zone5->onTimer(timerId);
		break;

	case kZone6:
		_zone6->onTimer(timerId);
		break;

	case kZone8:
		_zone8->onTimer(timerId);
		break;

	case kZone9:
		_zone9->onTimer(timerId);
		break;

	case kZone10:
		_zone10->onTimer(timerId);
		break;

	case kZone11:
		_zone11->onTimer(timerId);
		break;

	case kZone12:
		_zone12->onTimer(timerId);
		break;

	case kZone13:
		_zone13->onTimer(timerId);
		break;

	case kZone14:
		_zone14->onTimer(timerId);
		break;

	case kZone15:
		_zone15->onTimer(timerId);
		break;

	case kZone16:
		_zone16->onTimer(timerId);
		break;
	}

	if (getState() != kStateShowMenu)
		getTimerHandler()->incrementFiredCount(timerId);
}

void ApplicationFaust::onBag(ObjectId id, Id target, Id puzzleRotationId, uint32 a4, DragControl *dragControl, byte type) {
	debugC(kRingDebugLogic, "onBag (object: %d)", id.id());

	if (puzzleRotationId == 1 && a4 == 1) {
		_zoneSystem->onBag(id, target, 1, 1, dragControl, type);
		return;
	}

	switch (getCurrentZone()) {
	default:
		break;

	case kZoneSY:
		_zoneSystem->onBag(id, target, puzzleRotationId, a4, dragControl, type);
		break;

	case kZone3:
		_zone3->onBag(id, target, puzzleRotationId, a4, dragControl, type);
		break;

	case kZone4:
		_zone4->onBag(id, target, puzzleRotationId, a4, dragControl, type);
		break;

	case kZone5:
		_zone5->onBag(id, target, puzzleRotationId, a4, dragControl, type);
		break;

	case kZone8:
		_zone8->onBag(id, target, puzzleRotationId, a4, dragControl, type);
		break;

	case kZone12:
		_zone12->onBag(id, target, puzzleRotationId, a4, dragControl, type);
		break;

	case kZone13:
		_zone13->onBag(id, target, puzzleRotationId, a4, dragControl, type);
		break;

	case kZone14:
		_zone14->onBag(id, target, puzzleRotationId, a4, dragControl, type);
		break;
	}
}

void ApplicationFaust::onUpdateBag(const Common::Point &point) {
	switch (getCurrentZone()) {
	default:
		break;

	case kZoneSY:
		_zoneSystem->onUpdateBag(point);
		break;

	case kZone3:
		_zone3->onUpdateBag(point);
		break;

	case kZone4:
		_zone4->onUpdateBag(point);
		break;

	case kZone6:
		_zone6->onUpdateBag(point);
		break;

	case kZone12:
		_zone12->onUpdateBag(point);
		break;

	case kZone14:
		_zone14->onUpdateBag(point);
		break;

	case kZone15:
		_zone15->onUpdateBag(point);
		break;

	case kZone16:
		_zone16->onUpdateBag(point);
		break;
	}
}

void ApplicationFaust::onBagClickedObject(ObjectId id) {
	switch (getCurrentZone()) {
	default:
		break;

	case kZone2:
		_zone2->onBagClickedObject(id);
		break;

	case kZone3:
		_zone3->onBagClickedObject(id);
		break;

	case kZone4:
		_zone4->onBagClickedObject(id);
		break;

	case kZone8:
		_zone8->onBagClickedObject(id);
		break;

	case kZone14:
		_zone14->onBagClickedObject(id);
		break;

	case kZone15:
		_zone15->onBagClickedObject(id);
		break;
	}
}

void ApplicationFaust::onBeforeRide(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, MovabilityType movabilityType) {
	if (movabilityFrom == 1)
		return;

	switch (getCurrentZone()) {
	default:
	case kZoneSY:
		break;

	case kZone2:
		_zone2->onBeforeRide(movabilityFrom, movabilityTo, movabilityIndex, target, movabilityType);
		break;

	case kZone4:
		_zone4->onBeforeRide(movabilityFrom, movabilityTo, movabilityIndex, target, movabilityType);
		break;

	case kZone5:
		_zone5->onBeforeRide(movabilityFrom, movabilityTo, movabilityIndex, target, movabilityType);
		break;

	case kZone8:
		_zone8->onBeforeRide(movabilityFrom, movabilityTo, movabilityIndex, target, movabilityType);
		break;

	case kZone14:
		_zone14->onBeforeRide(movabilityFrom, movabilityTo, movabilityIndex, target, movabilityType);
		break;

	case kZone15:
		_zone15->onBeforeRide(movabilityFrom, movabilityTo, movabilityIndex, target, movabilityType);
		break;
	}
}

void ApplicationFaust::onAfterRide(Id movabilityFrom, Id movabilityTo, uint32 movabilityIndex, Id target, MovabilityType movabilityType) {
	if (movabilityTo == 1)
		return;

	switch (getCurrentZone()) {
	default:
	case kZoneSY:
		break;

	case kZone2:
		_zone2->onAfterRide(movabilityFrom, movabilityTo, movabilityIndex, target, movabilityType);
		break;

	case kZone3:
		_zone3->onAfterRide(movabilityFrom, movabilityTo, movabilityIndex, target, movabilityType);
		break;

	case kZone4:
		_zone4->onAfterRide(movabilityFrom, movabilityTo, movabilityIndex, target, movabilityType);
		break;

	case kZone6:
		_zone6->onAfterRide(movabilityFrom, movabilityTo, movabilityIndex, target, movabilityType);
		break;

	case kZone8:
		_zone8->onAfterRide(movabilityFrom, movabilityTo, movabilityIndex, target, movabilityType);
		break;

	case kZone10:
		_zone10->onAfterRide(movabilityFrom, movabilityTo, movabilityIndex, target, movabilityType);
		break;

	case kZone12:
		_zone12->onAfterRide(movabilityFrom, movabilityTo, movabilityIndex, target, movabilityType);
		break;

	case kZone13:
		_zone13->onAfterRide(movabilityFrom, movabilityTo, movabilityIndex, target, movabilityType);
		break;

	case kZone14:
		_zone14->onAfterRide(movabilityFrom, movabilityTo, movabilityIndex, target, movabilityType);
		break;

	case kZone15:
		_zone15->onAfterRide(movabilityFrom, movabilityTo, movabilityIndex, target, movabilityType);
		break;

	case kZone16:
		_zone16->onAfterRide(movabilityFrom, movabilityTo, movabilityIndex, target, movabilityType);
		break;

	case kZone17:
		_zone17->onAfterRide(movabilityFrom, movabilityTo, movabilityIndex, target, movabilityType);
		break;
	}
}

void ApplicationFaust::onSound(Id id, SoundType type, uint32 a3) {
	debugC(kRingDebugLogic, "onSound (id: %d, type: %d)", id, type);

	bool process = (a3 & 0x1000) != 0;
	a3 &= 239;

	switch (getCurrentZone()) {
	default:
		break;

	case kZoneSY:
		_zoneSystem->onSound(id, type, a3, process);
		break;

	case kZone3:
		_zone3->onSound(id, type, a3, process);
		break;

	case kZone4:
		_zone4->onSound(id, type, a3, process);
		break;

	case kZone5:
		_zone5->onSound(id, type, a3, process);
		break;

	case kZone8:
		_zone8->onSound(id, type, a3, process);
		break;

	case kZone12:
		_zone12->onSound(id, type, a3, process);
		break;

	case kZone14:
		_zone14->onSound(id, type, a3, process);
		break;

	case kZone15:
		_zone15->onSound(id, type, a3, process);
		break;

	case kZone17:
		_zone17->onSound(id, type, a3, process);
		break;
	}
}

void ApplicationFaust::onAnimationNextFrame(Id animationId, const Common::String &name, uint32 frame, uint32 frameCount) {
	switch (getCurrentZone()) {
	default:
		break;

	case kZoneSY:
		_zoneSystem->onAnimationNextFrame(animationId, name, frame, frameCount);
		break;

	case kZone3:
		_zone3->onAnimationNextFrame(animationId, name, frame, frameCount);
		break;

	case kZone4:
		_zone4->onAnimationNextFrame(animationId, name, frame, frameCount);
		break;

	case kZone5:
		_zone5->onAnimationNextFrame(animationId, name, frame, frameCount);
		break;

	case kZone6:
		_zone6->onAnimationNextFrame(animationId, name, frame, frameCount);
		break;

	case kZone7:
		_zone7->onAnimationNextFrame(animationId, name, frame, frameCount);
		break;

	case kZone8:
		_zone8->onAnimationNextFrame(animationId, name, frame, frameCount);
		break;

	case kZone9:
		_zone9->onAnimationNextFrame(animationId, name, frame, frameCount);
		break;

	case kZone10:
		_zone10->onAnimationNextFrame(animationId, name, frame, frameCount);
		break;

	case kZone11:
		_zone11->onAnimationNextFrame(animationId, name, frame, frameCount);
		break;

	case kZone12:
		_zone12->onAnimationNextFrame(animationId, name, frame, frameCount);
		break;

	case kZone13:
		_zone13->onAnimationNextFrame(animationId, name, frame, frameCount);
		break;

	case kZone14:
		_zone14->onAnimationNextFrame(animationId, name, frame, frameCount);
		break;

	case kZone15:
		_zone15->onAnimationNextFrame(animationId, name, frame, frameCount);
		break;
	}
}

void ApplicationFaust::onVisualList(Id id, uint32 type, const Common::Point &point) {
	if (getCurrentZone() == kZoneSY)
		_zoneSystem->onVisualList(id, type, point);
}

#pragma endregion

#pragma region Helpers

void ApplicationFaust::setupRotation(uint32 type) {
	switch (type) {
	default:
		break;

	case 2:
		soundStop(17019, 1024);
		setSpace(kZone10);
		rotationSetAlp(71009, 64.0f);
		rotationSetBet(71009, 0);
		rotationSetRan(71009, 87.0f);
		rotationSetActive(71009);
		break;

	case 3:
		setSpace(kZone9);
		soundPlay(61306, kSoundLoop);
		rotationSetAlp(61200, 0.0f);
		rotationSetBet(61200, 0);
		rotationSetRan(61200, 87.0f);
		rotationSetActive(61200);
		break;

	case 4:
		setSpace(kZone10);
		soundStop(61306, 1024);
		rotationSetAlp(71010, 270.0f);
		rotationSetBet(71010, 0);
		rotationSetRan(71010, 87.0f);
		rotationSetActive(71010);
		objectPresentationHide(kObject5);
		break;
	}
}

void ApplicationFaust::sub_45FF30() {
	if (soundIsPlaying(112016)) {
		objectPresentationHide(kObject12, 1);
		objectSetAccessibilityOff(kObject22);
		soundStop(112016, 1024);
		varSetByte(114100, 0);
	}
}

void ApplicationFaust::sub_460280() {
	error("[ApplicationFaust::sub_460280] Not implemented");
}

// FAUST.EXE 0x4687f0: zone 14 radio puzzle (object 22 / sound 112016) outcomes
void ApplicationFaust::sub_468290(uint32 a1) {
	switch (a1) {
	default:
		break;

	case 1:
		sub_45FF30();
		objectPresentationHide(kObject12);

		if (varGetByte(114100) != 1) {
			playMovie("a11s04n01a09b");
			fadeOut(15, Color(0, 0, 0), 0);
			soundStop(111079, 1024);
			soundStop(111080, 1024);
			objectSetAccessibilityOn(kObject1);
			objectPresentationShow(kObject15);
			soundPlay(111042);
			break;
		}

		playMovie("a11s04n01a09a");
		objectSetAccessibilityOn(kObject114006, 8, 8);
		// Fallback to case 3
		sub_468290(3);
		break;

	case 2:
		fadeOut(15, Color(0, 0, 0), 0);
		soundStop(111079, 1024);
		soundStop(111080, 1024);
		objectSetAccessibilityOn(kObject1);
		objectPresentationShow(kObject15);
		soundPlay(111076);
		break;

	case 3:
		soundPlay(varGetByte(111000) == 1 ? 111080 : 111079, kSoundLoop);
		sub_45FF30();
		objectPresentationHide(kObject12);
		objectSetAccessibilityOff(kObject22);
		varSetByte(114100, 0);
		objectSetAccessibilityOff(kObject114027, 1, 1);
		objectSetAccessibilityOn(kObject114027, 0, 0);
		break;
	}
}

// FAUST.EXE 0x45b140: fill a visual list with the current user's savegames for this chapter
// (save.aba entries whose file name starts with "<98001>_")
void ApplicationFaust::loadSaveList(Id visualId, PuzzleId puzzleId) {
	Common::String prefix = Common::String::format("%d_", (int8)varGetByte(98001));
	Common::Array<SaveManager::SaveEntry *> *savegames = _saveManager->loadSavegames();

	for (uint32 i = 0; i < savegames->size(); i++) {
		if (!(*savegames)[i]->filename.hasPrefix(prefix))
			continue;

		ObjectId objectId = i + 2000000;
		objectAdd(objectId, (*savegames)[i]->description, (*savegames)[i]->filename, 1);
		visualListAdd(visualId, puzzleId, objectId);
	}
}

// The chapter selected in the extras (exe global 0x4dbf0c), used by the episodes' 30000 setups
int8 ApplicationFaust::getChapterIndex() const {
	return _zoneSystem->getChapterIndex();
}

// FAUST.EXE 0x460150: resume play in zones 11/12/13. This is also episode 4's onSetup
// in the exe's setup dispatcher (0x47d090). The original takes the zone as its first
// argument, but doesn't use it.
void ApplicationFaust::sub_460150(uint32 type) {
	switch (type) {
	default:
		error("[ApplicationFaust::sub_460150] Not implemented (type %d)", type);

	case 1:
		timerStopAll();
		bagRemoveAll();
		setSpace(kZone12);
		playMovie("a08s01_e03m01");
		fadeOut(15, Color(0, 0, 0), 0);
		soundPlay(81107, kSoundLoop);
		displayFade("a08_black.bmp", "a08_start_episode.bmp", 12, 0, kLoadFromCd, kArchiveArt);
		rotationSetAlp(81011, 4.0f);
		rotationSetBet(81011, 0.0f);
		rotationSetRan(81011, 87.0f);
		rotationSetActive(81011);
		timerStart(kTimer7, 1000);
		timerStart(kTimer8, 500);
		bagAdd(13899);
		bagAdd(kObjectMatches);
		bagAdd(kObjectHomunculus);
		objectPresentationShow(kObject25, 3);
		break;

	case 2:
		timerStopAll();
		setSpace(kZone11);
		rotationSetAlp(72014, 90.0f);
		rotationSetBet(72014, 0.0f);
		rotationSetRan(72014, 87.0f);
		rotationSetActive(72014);
		timerStart(kTimer0, 1);
		timerStart(kTimer3, 400);
		timerStart(kTimer5, 1);
		objectPresentationShow(kObject8, 0);
		objectPresentationShow(kObject9);
		objectPresentationShow(kObject10);
		break;

	case 3:
		timerStopAll();
		bagAdd(13899);
		bagAdd(kObjectMatches);
		bagAdd(kObjectHomunculus);
		setSpace(kZone13);
		playMovie("A08S03_E03M06");
		if (_saveManager->getData()->progressState == kProgressState3)
			_saveManager->getData()->progress = 28;
		fadeOut(15, Color(0, 0, 0), 0);
		rotationSetAlp(91002, 90.0f);
		rotationSetBet(91002, 0.0f);
		rotationSetRan(91002, 87.0f);
		rotationSetActive(91002);
		soundPlay(91920, kSoundLoop);
		displayFade("a09_black.bmp", "a09_start.bmp", 12, 0, kLoadFromCd, kArchiveArt);
		timerStart(kTimer1, 15000);
		break;
	}
}

// FAUST.EXE 0x4aba90: episode 1, travel between A01S01 (zone 2) and A01S03 (zone 4)
void ApplicationFaust::sub_4ABA90(uint32 type) {
	switch (type) {
	default:
		break;

	case 5:
		timerStopAll();
		setSpace(kZone2);
		rotationSetAlp(11003, 270.0f);
		rotationSetBet(11003, 0.0f);
		rotationSetRan(11003, 87.0f);
		rotationSetActive(11003);
		timerStart(kTimer0, 1000);
		objectSetAccessibilityOff(kObject11001);
		objectSetAccessibilityOff(kObject11003);
		break;

	case 6:
		timerStopAll();
		setSpace(kZone4);
		rotationSetAlp(13311, 90.0f);
		rotationSetBet(13311, 0.0f);
		rotationSetRan(13311, 87.0f);
		rotationSetActive(13311);
		soundPlay(13054);
		break;
	}
}

// FAUST.EXE 0x4ac4e0: episode 1, travel between A01S01 (zone 2), A01S02 (zone 3) and A03 (zone 6)
void ApplicationFaust::sub_4AC4E0(uint32 type) {
	switch (type) {
	default:
		break;

	case 1:
		setSpace(kZone2);
		rotationSetAlp(11001, 180.0f);
		rotationSetBet(11001, 0.0f);
		rotationSetRan(11001, 87.0f);
		rotationSetActive(11001);
		timerStart(kTimer0, 1000);
		objectSetAccessibilityOff(kObject11002);
		objectSetAccessibilityOff(kObject11003);
		objectSetAccessibilityOff(kObject11004);
		objectSetAccessibilityOff(kObject11005);
		soundPlay(11105);
		soundStop(12201, 1024);
		break;

	case 3:
		timerStopAll();
		setSpace(kZone6);
		rotationSetAlp(31011, 0.0f);
		rotationSetBet(31011, 0.0f);
		rotationSetRan(31011, 87.0f);
		rotationSetActive(31011);
		break;

	case 5:
		timerStopAll();
		setSpace(kZone3);
		rotationSetAlp(12001, 0.0f);
		rotationSetBet(12001, 0.0f);
		rotationSetRan(12001, 87.0f);
		rotationSetActive(12001);
		timerStart(kTimer8, 10);
		soundPlay(12127);
		soundPlay(12201, kSoundLoop);
		break;
	}
}

void ApplicationFaust::sub_4A08E0() {
	error("[ApplicationFaust::sub_4A08E0] Not implemented");
}

void ApplicationFaust::sub_4A2CF0() {
	error("[ApplicationFaust::sub_4A2CF0] Not implemented");
}

#pragma endregion

// FAUST.EXE 0x460d40: angle of the drag around its start point, clockwise from up (0..359)
int32 ApplicationFaust::getDragAngle(DragControl *dragControl) {
	// The original uses 180 / 3.14
	const double radToDeg = 57.324840764331206;

	int32 dx = dragControl->getCurrentCoords().x - dragControl->getCoords1().x;
	int32 dy = dragControl->getCoords1().y - dragControl->getCurrentCoords().y;
	double angle = dy ? atan((double)dx / dy) : 0.0;

	if (dx == 0) {
		if (dy > 0)
			return 0;

		return dy < 0 ? 180 : 0;
	}

	if (dx > 0) {
		if (dy > 0)
			return (int32)(angle * radToDeg);

		if (dy == 0)
			return 90;

		return 180 - (int32)(angle * -radToDeg);
	}

	if (dy > 0)
		return 360 - (int32)(angle * -radToDeg);

	if (dy == 0)
		return 270;

	return 180 - (int32)(angle * -radToDeg);
}

} // End of namespace Ring
