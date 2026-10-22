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

#include "ring/graphics/codecs/imageloader_bmp.h"

#include "ring/base/stream.h"

#include "ring/graphics/image.h"
#include "ring/ring.h"

#include "common/archive.h"
#include "common/savefile.h"
#include "common/system.h"

#include "image/bmp.h"

namespace Ring {

bool ImageLoaderBMP::load(ImageSurface *image, ArchiveType, ZoneId, LoadFrom, DrawType) {
	if (!image)
		error("[ImageLoaderBMP::load] Invalid image pointer!");

	// Get image stream
	Common::SeekableReadStream *stream = SearchMan.createReadStreamForMember(Common::Path(image->getName(), '/'));

	// The save thumbnails the original writes to disk are savefiles here ("<gameid>-<user folder>-<file>.bmp",
	// and "<gameid>-osc.bmp" for the save screen's preview)
	if (!stream)
		stream = g_system->getSavefileManager()->openForLoading(image->getName());

	if (!stream)
		stream = g_system->getSavefileManager()->openForLoading(Common::String::format("%s-%s", ((RingEngine *)g_engine)->getGameDescription()->desc.gameId, image->getName().c_str()));

	if (!stream) {
		warning("[ImageLoaderBMP::load] Cannot load image (%s)", image->getName().c_str());
		return false;
	}

	// Get image surface
	Image::BitmapDecoder *bmp = new Image::BitmapDecoder();
	bool loaded = bmp->loadStream(*stream);
	if (!loaded) {
		warning("[ImageLoaderBMP::load] Cannot decode image (%s)", image->getName().c_str());
		delete bmp;
		delete stream;
		return false;
	}

	// Our blitter can't downsample 24bpp (the save thumbnails, written with Image::writeBMP)
	Graphics::Surface *surface;
	if (bmp->getSurface()->format.bytesPerPixel == 3) {
		surface = bmp->getSurface()->convertTo(g_system->getScreenFormat());
	} else {
		surface = new Graphics::Surface();
		surface->copyFrom(*bmp->getSurface());
	}

	image->setSurface(surface);

	delete stream;
	delete bmp;

	return true;
}

} // End of namespace Ring
