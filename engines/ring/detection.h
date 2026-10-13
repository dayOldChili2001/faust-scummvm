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

#ifndef RING_DETECTION_H
#define RING_DETECTION_H

#include "engines/advancedDetector.h"

namespace Ring {

struct RingGameDescription {
	AD_GAME_DESCRIPTION_HELPERS(desc);

	ADGameDescription desc;

	int gameType;
	uint32 features;
};

enum RingGameType {
	GameTypePilgrim,
	GameTypeRing,
	GameTypeFaust,
	GameTypePompeii,
	GameTypePilgrim2,
	GameTypePilgrim3,
	GameTypeJerusalem
};

// Available languages
enum {
	LANG_ENG = 1 << 0,
	LANG_FRA = 1 << 1,
	LANG_GER = 1 << 2,
	LANG_GRE = 1 << 3,
	LANG_HEB = 1 << 4,
	LANG_HOL = 1 << 5,
	LANG_ITA = 1 << 6,
	LANG_SLO = 1 << 7,
	LANG_SPA = 1 << 8,
	LANG_SWE = 1 << 9
};

} // End of namespace Ring

#endif // RING_DETECTION_H
