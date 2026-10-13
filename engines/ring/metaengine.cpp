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

#include "common/config-manager.h"
#include "common/savefile.h"
#include "common/system.h"

#include "engines/advancedDetector.h"

#include "graphics/surface.h"

#include "ring/ring.h"
#include "ring/base/saveload.h"

namespace Ring {

// Saves are named after the game id ("faust.s01"), not the target
static Common::String gameIdFromTarget(const char *target) {
	const Common::ConfigManager::Domain *domain = ConfMan.getDomain(target);
	if (domain && domain->contains("gameid"))
		return domain->getVal("gameid");

	return target;
}

} // End of namespace Ring

class RingMetaEngine : public AdvancedMetaEngine<Ring::RingGameDescription> {
public:
	const char *getName() const override {
		return "ring";
	}

	bool hasFeature(MetaEngineFeature f) const override {
		return (f == kSupportsListSaves) ||
		       (f == kSupportsDeleteSave) ||
		       (f == kSavesSupportMetaInfo) ||
		       (f == kSavesSupportThumbnail) ||
		       (f == kSavesSupportCreationDate) ||
		       (f == kSavesSupportPlayTime);
	}

	int getMaximumSaveSlot() const override { return 99; }

	Common::Error createInstance(OSystem *syst, Engine **engine, const Ring::RingGameDescription *desc) const override {
		*engine = new Ring::RingEngine(syst, desc);
		return Common::kNoError;
	}

	SaveStateList listSaves(const char *target) const override;
	bool removeSaveState(const char *target, int slot) const override;
	SaveStateDescriptor querySaveMetaInfos(const char *target, int slot) const override;
};

SaveStateList RingMetaEngine::listSaves(const char *target) const {
	Common::String gameId = Ring::gameIdFromTarget(target);

	Common::SaveFileManager *saveFileMan = g_system->getSavefileManager();
	Common::StringArray filenames = saveFileMan->listSavefiles(gameId + ".s##");

	SaveStateList saveList;
	for (Common::StringArray::const_iterator file = filenames.begin(); file != filenames.end(); ++file) {
		// The last 2 digits of the filename are the save slot
		int slotNum = atoi(file->c_str() + file->size() - 2);

		if (slotNum < 0 || slotNum > 99)
			continue;

		Common::InSaveFile *in = saveFileMan->openForLoading(*file);
		if (!in)
			continue;

		Ring::SaveManager::SavegameHeader header;
		if (Ring::SaveManager::readSavegameHeader(in, header)) {
			saveList.push_back(SaveStateDescriptor(this, slotNum, header.name));
			if (header.thumbnail) {
				header.thumbnail->free();
				delete header.thumbnail;
			}
		}
		delete in;
	}

	Common::sort(saveList.begin(), saveList.end(), SaveStateDescriptorSlotComparator());
	return saveList;
}

bool RingMetaEngine::removeSaveState(const char *target, int slot) const {
	Common::String gameId = Ring::gameIdFromTarget(target);
	return g_system->getSavefileManager()->removeSavefile(Ring::SaveManager::getSavegameFile(gameId.c_str(), slot));
}

SaveStateDescriptor RingMetaEngine::querySaveMetaInfos(const char *target, int slot) const {
	Common::String gameId = Ring::gameIdFromTarget(target);

	Common::InSaveFile *f = g_system->getSavefileManager()->openForLoading(Ring::SaveManager::getSavegameFile(gameId.c_str(), slot));
	if (!f)
		return SaveStateDescriptor();

	Ring::SaveManager::SavegameHeader header;
	bool valid = Ring::SaveManager::readSavegameHeader(f, header);
	delete f;

	if (!valid)
		return SaveStateDescriptor();

	SaveStateDescriptor desc(this, slot, header.name);
	desc.setDeletableFlag(true);
	desc.setWriteProtectedFlag(false);
	desc.setThumbnail(header.thumbnail);

	int day = (header.date >> 24) & 0xFF;
	int month = (header.date >> 16) & 0xFF;
	int year = header.date & 0xFFFF;
	desc.setSaveDate(year, month, day);

	int hour = (header.time >> 8) & 0xFF;
	int minutes = header.time & 0xFF;
	desc.setSaveTime(hour, minutes);

	desc.setPlayTime(header.playtime * 1000);

	return desc;
}

#if PLUGIN_ENABLED_DYNAMIC(RING)
	REGISTER_PLUGIN_DYNAMIC(RING, PLUGIN_TYPE_ENGINE, RingMetaEngine);
#else
	REGISTER_PLUGIN_STATIC(RING, PLUGIN_TYPE_ENGINE, RingMetaEngine);
#endif
