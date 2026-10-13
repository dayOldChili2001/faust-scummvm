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

#include "base/plugins.h"

#include "common/debug-channels.h"

#include "engines/advancedDetector.h"

#include "ring/debug.h"
#include "ring/detection.h"
#include "ring/detection_tables.h"

namespace Ring {

static const char *const directoryGlobs[] = {
	"DATA",
	nullptr
};

static const DebugChannelDef debugFlagList[] = {
	{kRingDebugAll, "Everything", "Debug everything"},
	{kRingDebugGraphics, "Graphics", "Debug graphics & video playback"},
	{kRingDebugResource, "Resource", "Debug resource management"},
	{kRingDebugSound, "Sound", "Debug sound playback"},
	{kRingDebugSavegame, "Savegame", "Debug savegame"},
	{kRingDebugLogic, "Logic", "Debug logic"},
	{kRingDebugMovie, "Movie", "Movie decoding"},
	{kRingDebugUnknown, "Unknown", "Debug unknown data"},
	DEBUG_CHANNEL_END
};

} // End of namespace Ring

class RingMetaEngineDetection : public AdvancedMetaEngineDetection<Ring::RingGameDescription> {
public:
	RingMetaEngineDetection() : AdvancedMetaEngineDetection(Ring::gameDescriptions, Ring::ringGames) {
		_guiOptions = GUIO1(GUIO_NOSFX);
		_maxScanDepth = 2;
		_directoryGlobs = Ring::directoryGlobs;
	}

	const char *getName() const override {
		return "ring";
	}

	const char *getEngineName() const override {
		return "Ring";
	}

	const char *getOriginalCopyright() const override {
		return "Ring Engine (C) 1999 Arxel Tribe";
	}

	const DebugChannelDef *getDebugChannels() const override {
		return Ring::debugFlagList;
	}
};

REGISTER_PLUGIN_STATIC(RING_DETECTION, PLUGIN_TYPE_ENGINE_DETECTION, RingMetaEngineDetection);
