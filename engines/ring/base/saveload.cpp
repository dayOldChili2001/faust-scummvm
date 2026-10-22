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

#include "ring/base/saveload.h"

#include "common/config-manager.h"
#include "common/random.h"

#include "ring/base/application.h"
#include "ring/base/bag.h"
#include "ring/base/timer.h"

#include "ring/graphics/image.h"

#include "ring/sound/sound_manager.h"

#include "ring/debug.h"
#include "ring/helpers.h"
#include "ring/ring.h"

#include "graphics/thumbnail.h"

#include "image/bmp.h"

namespace Ring {

#define RING_SAVEGAME_VERSION 2
static const char *ringSavegameIdentification = "ArxSav";

SaveManager::SaveManager(Application *application) : _app(application) {
	_setupType = kSetupTypeNone;
	_type = kLoadSaveInvalid;

	_currentTicks = 0;
	_slot = 0;

	_ser = nullptr;
	_load = nullptr;
	_save = nullptr;
}

SaveManager::~SaveManager() {
	SAFE_DELETE(_ser);
	SAFE_DELETE(_load);
	SAFE_DELETE(_save);

	clearList(_users);
	clearList(_savegames);

	// Zero-out passed pointers
	_app = nullptr;
}

// Header
bool SaveManager::readSavegameHeader(Common::InSaveFile *in, SavegameHeader &header) {
	char saveIdent[7];
	header.thumbnail = nullptr;

	// Validate the header Id
	in->read(saveIdent, 6);
	saveIdent[6] = '\0';
	if (strcmp(saveIdent, ringSavegameIdentification) != 0)
		return false;

	header.version = in->readByte();
	if (header.version != RING_SAVEGAME_VERSION)
		return false;

	// Read in name and description
	header.name.clear();
	char ch;
	while ((ch = (char)in->readByte()) != '\0') header.name += ch;

	header.description.clear();
	while ((ch = (char)in->readByte()) != '\0') header.description += ch;

	header.date = in->readUint32LE();
	header.time = in->readUint16LE();
	header.playtime = in->readUint32LE();

	// Get the thumbnail
    return Graphics::loadThumbnail(*in, header.thumbnail);
}

void SaveManager::writeSavegameHeader(Common::OutSaveFile *out, const SavegameHeader &header) {
	// Write out a savegame header
	out->write(ringSavegameIdentification, 6);
	out->writeByte(RING_SAVEGAME_VERSION);

	// Write savegame name and description
	out->write(header.name.c_str(), header.name.size() + 1);
	out->write(header.description.c_str(), header.description.size() + 1);

	out->writeUint32LE(header.date);
	out->writeUint16LE(header.time);
	out->writeUint32LE(header.playtime);

	// Create a thumbnail and save it
	Graphics::saveThumbnail(*out, *header.thumbnail);
}

bool SaveManager::open(Common::String path, LoadSaveType type) {
	// Check save file
	if (type == kLoadSaveRead && !has(path))
		return false;

	// Open save file
	switch (type) {
	default:
		error("[SaveManager::loadSaveTimer] Invalid type (%d)", type);

	case kLoadSaveRead:
		_load = g_system->getSavefileManager()->openForLoading(path);
		if (!_load)
			return false;

		_ser = new Common::Serializer(_load, nullptr);
		break;

	case kLoadSaveWrite:
		_save = g_system->getSavefileManager()->openForSaving(path);
		if (!_save)
			return false;

		_ser = new Common::Serializer(nullptr, _save);
		break;
	}

	// Setup global variables
	_currentTicks = g_system->getMillis();
	_type = type;

	return true;
}

void SaveManager::close() {
	SAFE_DELETE(_ser);
	SAFE_DELETE(_load);
	SAFE_DELETE(_save);
}

// FAUST.EXE 0x473990 (aApplication::LoadSave): Data/Save/<user>/<name>.ars
// The original writes no header. We write a short identification so that a
// file from another engine version is rejected instead of misread.
bool SaveManager::loadSave(const Common::String &name, LoadSaveType type) {
	Common::String path = getUserFile(name + ".ars");
	if (path.empty())
		return false;

	debugC(kRingDebugSavegame, "[SaveManager::loadSave] %s %s", type == kLoadSaveRead ? "Loading" : "Saving", path.c_str());

	if (!open(path, type))
		return false;

	switch (type) {
	default:
		error("[SaveManager::loadSave] Invalid type (%d)", type);

	case kLoadSaveRead: {
		char ident[7];
		_load->read(ident, 6);
		ident[6] = '\0';

		if (strcmp(ident, ringSavegameIdentification) != 0 || _load->readByte() != RING_SAVEGAME_VERSION) {
			warning("[SaveManager::loadSave] Invalid savegame: %s", path.c_str());
			close();
			return false;
		}
		break;
	}

	case kLoadSaveWrite:
		_save->write(ringSavegameIdentification, 6);
		_save->writeByte(RING_SAVEGAME_VERSION);
		break;
	}

	loadSaveData(type);

	return true;
}

bool SaveManager::loadSave(uint32 slot, LoadSaveType type) {
	if (!open(getSavegameFile(slot), type))
		return false;

	// Set slot (will be used to load timers)
	_slot = slot;

	// Handle header
	switch (type) {
	default:
		error("[SaveManager::loadSave] Invalid type (%d)", type);

	case kLoadSaveRead:
		// Read savegame header
		readSavegameHeader(_load, _header);
		break;

	case kLoadSaveWrite:
		writeSavegameHeader(_save, _header);
		break;
	}

	loadSaveData(type);

	return true;
}

void SaveManager::loadSaveData(LoadSaveType type) {
	// Save/load array data
	_app->saveLoadWithSerializer(*_ser);

	// Initialize save data
	initialize();

	// Application data
	_ser->syncAsUint32LE(_data.state);
	_ser->syncAsByte(_data.field_6A);
	_ser->syncAsUint32LE(_data.zone);
	_ser->syncAsUint32LE(_data.episode);
	_ser->syncAsByte(_data.hasCurrentPuzzle);
	_ser->syncAsUint32LE(_data.puzzleId);
	_ser->syncAsByte(_data.hasCurrentRotation);
	_ser->syncAsUint32LE(_data.rotationId);
	_ser->syncAsByte(_data.rotationFre);
	_ser->syncAsUint32LE(_data.loadFrom);
	_ser->syncAsByte(_data.isRotationCompressed);
	_ser->syncAsUint32LE(_data.archiveType);

	if (_ser->isLoading()) {
		_app->setState(_data.state);
		_app->setField6A(_data.field_6A);
		// The original saves the space and the episode, and sets up the episode (0x473e9e).
		// The space is restored in Application::setZone.
		_app->setupZone(_data.episode, kSetupTypeLoading);

		// We do not close the savegame yet, as it will be closed in loadSaveSounds()
		// (called from setZone, so _ser is no longer valid here)
		return;
	}

	if (_ser->isSaving()) {
		_app->getSoundManager()->saveLoadWithSerializer(*_ser);

		close();
	}
}

bool SaveManager::loadSaveTimer(Common::String zone, LoadSaveType type) {
	if (!open(getTimerFile(zone, _slot), type))
		return false;

	// Load/Save data
	_app->getTimerHandler()->saveLoadWithSerializer(*_ser);
	_app->getBag()->saveLoadWithSerializer(*_ser);
	_app->getSoundManager()->saveLoadWithSerializer(*_ser);

	close();

	return true;
}

void SaveManager::initialize() {
	_data.state = _app->getState();
	_data.field_6A = _app->getField6A();
	_data.zone = _app->getCurrentZone();
	_data.episode = _app->getCurrentEpisode();

	_data.hasCurrentPuzzle = _app->hasCurrentPuzzle();
	_data.puzzleId = _data.hasCurrentPuzzle ? _app->getCurrentPuzzleId() : kPuzzleInvalid;

	_data.hasCurrentRotation = _app->hasCurrentRotation();
	_data.rotationId = _data.hasCurrentRotation ? _app->getCurrentRotationId() : 0;

	_data.rotationFre = _app->getBag()->getRotationFre();

	_data.loadFrom = _app->getLoadFrom();
	_data.isRotationCompressed = _app->isRotationCompressed();
	_data.archiveType = _app->getArchiveType();
}

bool SaveManager::hasTimer(Common::String zone) {
	return has(getTimerFile(zone, _slot));
}

// FAUST.EXE 0x45acc0: Data/Save/<user>/SaveGame_<98001>.ars exists
bool SaveManager::hasZoneSavegame() {
	Common::String path = getUserFile(Common::String::format("SaveGame_%d.ars", (int8)_app->varGetByte(98001)));

	return !path.empty() && has(path);
}

bool SaveManager::hasSavegame(uint32 userId) {
	error("[SaveManager::hasSavegame] not implemented");
}

void SaveManager::deleteSavegame(uint32 userId) {
	error("[SaveManager::deleteSavegame] Not implemented");
}

// FAUST.EXE 0x45a800: delete <file>.ars and <file>.bmp and remove the entry from save.aba
bool SaveManager::deleteSavegame(Common::String name) {
	Common::String listFile = getUserFile("save.aba");
	if (listFile.empty())
		return false;

	Common::Array<SaveEntry *> list;
	readList(listFile, list);

	int32 index = findInList(list, name);
	if (index == -1) {
		clearList(list);
		return false;
	}

	Common::SaveFileManager *saveFileMan = g_system->getSavefileManager();
	saveFileMan->removeSavefile(getUserFile(list[index]->filename + ".ars"));
	saveFileMan->removeSavefile(getUserFile(list[index]->filename + ".bmp"));

	delete list[index];
	list.remove_at(index);

	bool written = writeList(listFile, list);
	clearList(list);

	return written;
}

bool SaveManager::has(Common::String filename) const {
	if (g_system->getSavefileManager()->listSavefiles(filename).size() == 0)
		return false;

	return true;
}

bool SaveManager::isSaving() const {
	return (_type == kLoadSaveWrite);
}

void SaveManager::loadSaveSounds() {
	if (_type == kLoadSaveInvalid || _ser == nullptr)
		error("[SaveManager::loadSaveSounds] Savegame not initialized");

	_app->getSoundManager()->saveLoadWithSerializer(*_ser);

	close();
}

// GenPro.con (FAUST.EXE 0x45a510 / 0x45a660) is 100 random printable characters,
// with the progress state at offset 26 and the progress animation frame at
// offset 32, both stored + 0x37.
static const uint32 kProgressFileSize   = 100;
static const uint32 kProgressStateIndex = 26;
static const uint32 kProgressIndex      = 32;

void SaveManager::loadProgress() {
	_data.progressState = kProgressStateNone;

	Common::String path = getUserFile("GenPro.con");
	if (path.empty() || !has(path)) {
		warning("[SaveManager::loadProgress] Cannot open file: %s", path.c_str());
		return;
	}

	Common::InSaveFile *file = g_system->getSavefileManager()->openForLoading(path);
	if (!file) {
		warning("[SaveManager::loadProgress] Cannot open file: %s", path.c_str());
		return;
	}

	byte buffer[kProgressFileSize];
	uint32 size = file->read(buffer, kProgressFileSize);
	delete file;

	if (size != kProgressFileSize) {
		warning("[SaveManager::loadProgress] Wrong file format (length %d)", size);
		return;
	}

	_data.progress      = (byte)(buffer[kProgressIndex] - 0x37);
	_data.progressState = (ProgressState)(int8)(buffer[kProgressStateIndex] - 0x37);
}

void SaveManager::saveProgress(ProgressState progress) {
	Common::String path = getUserFile("GenPro.con");
	if (path.empty()) {
		warning("[SaveManager::saveProgress] No current user");
		return;
	}

	Common::OutSaveFile *file = g_system->getSavefileManager()->openForSaving(path, false);
	if (!file) {
		warning("[SaveManager::saveProgress] Cannot open file: %s", path.c_str());
		return;
	}

	// Filler, as in the original
	Common::RandomSource randomSource("faustProgress");
	byte buffer[kProgressFileSize];
	for (uint32 i = 0; i < kProgressFileSize; i++)
		buffer[i] = (byte)(0x21 + randomSource.getRandomNumber(59));

	buffer[kProgressIndex]      = (byte)(_data.progress + 0x37);
	buffer[kProgressStateIndex] = (byte)(progress + 0x37);

	file->write(buffer, kProgressFileSize);
	file->finalize();
	delete file;
}

// FAUST.EXE 0x474230 (aApplication::StartLogin) reads the users from Data/Save/user.aba
Common::Array<SaveManager::SaveEntry *> *SaveManager::loadUsers() {
	readList(getUsersFile(), _users);

	return &_users;
}

// FAUST.EXE 0x45e8de: create Data/Save/userN/, add it to user.aba, then copy zero.aba
// (an empty save list) and aPre.ini into it
bool SaveManager::createUser(const Common::String &name) {
	readList(getUsersFile(), _users);

	if (findInList(_users, name) != -1)
		return true;

	// Find a free folder name
	Common::String folder;
	for (uint32 i = 1; ; i++) {
		folder = Common::String::format("user%d", i);
		if (findInList(_users, folder) == -1)
			break;
	}

	SaveEntry *entry = new SaveEntry();
	entry->description = name;
	entry->filename = folder;
	_users.push_back(entry);

	if (!writeList(getUsersFile(), _users)) {
		warning("[SaveManager::createUser] Cannot add to file list: user.aba");
		return false;
	}

	// The preferences (aPre.ini) are not per user yet
	Common::Array<SaveEntry *> empty;
	return writeList(getUserFile(folder, "save.aba"), empty);
}

// FAUST.EXE 0x45a920: delete the user's savegames and files, then remove the user from user.aba
bool SaveManager::deleteUser(const Common::String &name) {
	readList(getUsersFile(), _users);

	int32 index = findInList(_users, name);
	if (index == -1)
		return false;

	Common::SaveFileManager *saveFileMan = g_system->getSavefileManager();
	Common::StringArray files = saveFileMan->listSavefiles(getUserFile(_users[index]->filename, "*"));
	for (Common::StringArray::const_iterator it = files.begin(); it != files.end(); it++)
		saveFileMan->removeSavefile(*it);

	delete _users[index];
	_users.remove_at(index);

	return writeList(getUsersFile(), _users);
}

// FAUST.EXE 0x45b140 reads the current user's save.aba
Common::Array<SaveManager::SaveEntry *> *SaveManager::loadSavegames() {
	clearList(_savegames);

	Common::String path = getUserFile("save.aba");
	if (!path.empty())
		readList(path, _savegames);

	return &_savegames;
}

// FAUST.EXE 0x45de81: copy SaveGame_<98001>.ars (written by startMenu) and the
// thumbnail to "<98001>_ArSa<n>", and add or replace the name in save.aba
bool SaveManager::saveAs(const Common::String &name) {
	Common::String listFile = getUserFile("save.aba");
	if (listFile.empty() || name.empty())
		return false;

	byte chapter = _app->varGetByte(98001);

	Common::Array<SaveEntry *> list;
	readList(listFile, list);

	Common::String filename;
	int32 index = findInList(list, name);
	if (index != -1) {
		filename = list[index]->filename;
	} else {
		// FindTempFileName
		for (uint32 i = 0; ; i++) {
			filename = Common::String::format("%d_ArSa%d", chapter, i);
			if (findInList(list, filename) == -1 && !has(getUserFile(filename + ".ars")))
				break;
		}

		SaveEntry *entry = new SaveEntry();
		entry->description = name;
		entry->filename = filename;
		list.push_back(entry);
	}

	bool saved = copyFile(getUserFile(Common::String::format("SaveGame_%d.ars", chapter)), getUserFile(filename + ".ars"));
	if (!saved) {
		warning("[SaveManager::saveAs] Cannot copy file: SaveGame_%d.ars", chapter);
	} else {
		// The original copies data/SY/Image/osc.bmp
		if (_header.thumbnail) {
			Common::OutSaveFile *file = g_system->getSavefileManager()->openForSaving(getUserFile(filename + ".bmp"), false);
			if (file) {
				Image::writeBMP(*file, *_header.thumbnail);
				file->finalize();
				delete file;
			}
		}

		saved = writeList(listFile, list);
	}

	clearList(list);

	return saved;
}

// The original also writes the thumbnail to data/SY/Image/osc.bmp, the save screen's preview
void SaveManager::setThumbnail(ImageSurface *image) {
	_header.setThumbnail(image->getSurface());

	Common::OutSaveFile *file = g_system->getSavefileManager()->openForSaving(getPreviewFile(), false);
	if (!file) {
		warning("[SaveManager::setThumbnail] Cannot write the preview image");
		return;
	}

	Image::writeBMP(*file, *_header.thumbnail);
	file->finalize();
	delete file;
}

Common::String SaveManager::getPreviewFile() const {
	return Common::String::format("%s-osc.bmp", ((RingEngine *)g_engine)->getGameDescription()->desc.gameId);
}

// Data/Save/<user>/ in the original, where saveAs puts the thumbnails
Common::String SaveManager::getIconDirectory() {
	return getUserFile("");
}

#pragma region File lists

// The original's .aba files are aFileList records (name and file name). Ours are
// plain text: one "name<TAB>file name" line per entry.
void SaveManager::clearList(Common::Array<SaveEntry *> &list) {
	for (uint32 i = 0; i < list.size(); i++)
		delete list[i];

	list.clear();
}

bool SaveManager::readList(const Common::String &filename, Common::Array<SaveEntry *> &list) {
	clearList(list);

	Common::InSaveFile *file = g_system->getSavefileManager()->openForLoading(filename);
	if (!file)
		return false;

	while (!file->eos() && !file->err()) {
		Common::String line = file->readLine();
		if (line.empty())
			continue;

		size_t separator = line.findFirstOf('\t');
		if (separator == Common::String::npos)
			continue;

		SaveEntry *entry = new SaveEntry();
		entry->description = Common::String(line.c_str(), separator);
		entry->filename = Common::String(line.c_str() + separator + 1);
		list.push_back(entry);
	}

	delete file;

	return true;
}

bool SaveManager::writeList(const Common::String &filename, const Common::Array<SaveEntry *> &list) {
	Common::OutSaveFile *file = g_system->getSavefileManager()->openForSaving(filename, false);
	if (!file)
		return false;

	for (uint32 i = 0; i < list.size(); i++)
		file->writeString(list[i]->description + "\t" + list[i]->filename + "\n");

	file->finalize();
	bool success = !file->err();
	delete file;

	return success;
}

// Entries are looked up by name or by file name
int32 SaveManager::findInList(const Common::Array<SaveEntry *> &list, const Common::String &name) {
	for (uint32 i = 0; i < list.size(); i++)
		if (list[i]->description == name || list[i]->filename == name)
			return (int32)i;

	return -1;
}

#pragma endregion

#pragma region User files

// The original keeps everything in Data/Save/. Here the files are ScummVM
// savefiles named "<gameid>-<file>" and "<gameid>-<user folder>-<file>".
Common::String SaveManager::getUsersFile() const {
	return Common::String::format("%s-user.aba", ((RingEngine *)g_engine)->getGameDescription()->desc.gameId);
}

Common::String SaveManager::getUserFile(const Common::String &filename) {
	readList(getUsersFile(), _users);

	int32 index = findInList(_users, _app->getUser());
	if (index == -1)
		return "";

	return getUserFile(_users[index]->filename, filename);
}

Common::String SaveManager::getUserFile(const Common::String &folder, const Common::String &filename) {
	return Common::String::format("%s-%s-%s", ((RingEngine *)g_engine)->getGameDescription()->desc.gameId, folder.c_str(), filename.c_str());
}

bool SaveManager::copyFile(const Common::String &from, const Common::String &to) const {
	Common::InSaveFile *in = g_system->getSavefileManager()->openForLoading(from);
	if (!in)
		return false;

	Common::OutSaveFile *out = g_system->getSavefileManager()->openForSaving(to);
	if (!out) {
		delete in;
		return false;
	}

	byte buffer[4096];
	while (!in->eos() && !in->err()) {
		uint32 size = in->read(buffer, sizeof(buffer));
		out->write(buffer, size);
	}

	out->finalize();
	bool success = !in->err() && !out->err();

	delete in;
	delete out;

	return success;
}

#pragma endregion

void SaveManager::setDescription(const Common::String &description) {
	_header.description = description;

	// Update current date/time and total playtime
	TimeDate curTime;
	g_system->getTimeAndDate(curTime);
	_header.date = (((uint)curTime.tm_mday & 0xFF) << 24) | ((((uint)curTime.tm_mon + 1) & 0xFF) << 16) | (((uint)curTime.tm_year + 1900) & 0xFFFF);
	_header.time = (((uint)curTime.tm_hour & 0xFF) << 8) | ((curTime.tm_min) & 0xFF);
	_header.playtime = g_engine->getTotalPlayTime() / 1000;
}

bool SaveManager::remove(uint32 slot) const {
	return g_system->getSavefileManager()->removeSavefile(getSavegameFile(slot));
}

const char *SaveManager::getSavegameFile(int slot) {
	return getSavegameFile(((RingEngine *)g_engine)->getGameDescription()->desc.gameId, slot);
}

const char *SaveManager::getSavegameFile(const char *gameid, int slot) {
	static char buffer[54];
	assert(strlen(gameid) < 50);

	Common::sprintf_s(buffer, "%s.s%02d", gameid, slot);
	return buffer;
}

Common::String SaveManager::getTimerFile(Common::String zone, uint32 slot) {
	return Common::String::format("%s_%s.s%02d", ((RingEngine *)g_engine)->getGameDescription()->desc.gameId, zone.c_str(), slot);
}

uint32 SaveManager::getNextSlot() const {
	RingEngine *engine = (RingEngine *)g_engine;

	return engine->getMetaEngine()->listSaves(ConfMan.getActiveDomainName().c_str()).size() - 1;
}

} // End of namespace Ring
