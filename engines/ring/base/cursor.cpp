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

#include "ring/base/cursor.h"

#include "ring/base/application.h"

#include "ring/graphics/image.h"

#include "ring/helpers.h"
#include "ring/ring.h"

#include "graphics/cursorman.h"

namespace Ring {

#pragma region CursorBase

// Hand an image to the cursor manager. The offset is the hotspot inside the image (the arrow's tip, the
// centre of the busy cursor). 24/32bpp cursor images (TGA, with alpha) are converted to the screen format,
// since the cursor manager is told the buffer is in that format.
static void replaceCursor(ImageSurface *image, const Common::Point &hotspot) {
	switch (image->getBPP()) {
	default:
		error("[replaceCursor] Invalid bit depth (%d)", image->getBPP());

	case 16:
		CursorMan.replaceCursor((byte *)image->getSurface()->getPixels(), image->getWidth(), image->getHeight(), hotspot.x, hotspot.y, 0, &image->getSurface()->format);
		break;

	case 24:
	case 32: {
		Graphics::PixelFormat formatScreen = g_system->getScreenFormat();
		Graphics::PixelFormat formatCursor = image->getSurface()->format;

		// Prepare buffer to hold new cursor data
		uint32 size = image->getWidth() * image->getHeight() * formatScreen.bytesPerPixel;
		byte *buf = (byte *)malloc(size);
		if (!buf)
			error("[replaceCursor] Cannot allocate cursor buffer (size: %d)", size);

		memset(buf, 0, size);

		if (!ImageSurface::crossBlit(buf,
		                 (byte *)image->getSurface()->getBasePtr(0, 0),
		                 image->getWidth() * formatScreen.bytesPerPixel,
		                 image->getSurface()->pitch,
		                 image->getWidth(),
		                 image->getHeight(),
		                 0,
		                 formatScreen,
		                 formatCursor,
		                 true))
			error("[replaceCursor] Cannot convert cursor image to proper screen format");

		CursorMan.replaceCursor((byte *)buf, image->getWidth(), image->getHeight(), hotspot.x, hotspot.y, 0, &formatScreen);
		free(buf);
		}
		break;
	}

	CursorMan.disableCursorPalette(true);
	CursorMan.showMouse(true);
}

CursorBase::CursorBase() : BaseObject(kCursorInvalid) {
	_type = kCursorTypeInvalid;
	_frameCount = 0;
}

CursorBase::~CursorBase() {
}

void CursorBase::init(CursorId id, Common::String name, CursorType cursorType, byte frameCount) {
	_id	 = id;
	_name = name;
	_type  = cursorType;
	_frameCount = frameCount;
}

#pragma endregion

#pragma region CursorImage

CursorImage::CursorImage() {
	_archiveType = kArchiveInvalid;
	_image = nullptr;
}

CursorImage::~CursorImage() {
	SAFE_DELETE(_image);
}

void CursorImage::init(CursorId id, Common::String name, CursorType cursorType, byte imageCount, ArchiveType archiveType) {
	CursorBase::init(id, name, cursorType, imageCount);

	_archiveType = archiveType;
	_image = new ImageSurface();

	if (imageCount == 1)
		alloc();
}

void CursorImage::alloc() {
	if (!_image)
		return;

	if (!_image->load(getName(), _archiveType, getZoneSY(), kLoadFromDisk, kDrawTypeAlpha))
		error("[CursorImage::alloc] Cannot load image (%s)", getName().c_str());

	if (_image->getBPP() != 32) {
		dealloc();
		warning("[CursorImage::alloc] Only 32bpp TGA are supported as cursors images");
	}
}

void CursorImage::dealloc() {
	if (!_image)
		return;

	if (_image->isInitialized())
		_image->destroy();
}

void CursorImage::draw() {
	// TODO Check and do not replace cursor every frame if the data did not change
	if (!_image)
		return;

	if (!_image->isInitialized())
		alloc();

	replaceCursor(_image, _offset);
}

#pragma endregion

#pragma region CursorAnimation

CursorAnimation::CursorAnimation() {
}

CursorAnimation::~CursorAnimation() {
}

void CursorAnimation::init(CursorId id, Common::String name, CursorType cursorType, byte imageCount, uint32 frameCount, float frameRate, byte a7, LoadFrom loadFrom, ArchiveType archiveType) {
	CursorBase::init(id, name, cursorType, imageCount);
	AnimationImage::init(name, kImageTypeTGA, Common::Point(0, 0), 0, kDrawTypeAlpha, frameCount, frameRate, 1, a7, imageCount, 0, loadFrom, archiveType);
	setTicks(g_system->getMillis());
}

void CursorAnimation::alloc() {
	AnimationImage::alloc();
}

void CursorAnimation::dealloc() {
	AnimationImage::dealloc();
}

void CursorAnimation::draw() {
	// Compute current frame, but do not draw on screen
	playFrame(false);

	// Replace cursor
	if (getCurrentImage())
		replaceCursor(getCurrentImage(), _offset);
}

#pragma endregion

#pragma region CursorHandler

CursorHandler::CursorHandler() {
	_index = 0;
}

CursorHandler::~CursorHandler() {
	CLEAR_ARRAY(CursorBase, _cursors);
}

void CursorHandler::add(CursorId id, Common::String name, CursorType cursorType, byte imageCount, uint32 frameCount, float frameRate, byte a6, LoadFrom loadFrom, ArchiveType archiveType) {
	if (_cursors.has(id))
		error("[CursorHandler::add] ID already exists (%d)", id);

	CursorBase *cursor = nullptr;
	switch (cursorType) {
	default:
		error("[CursorHandler::add] Invalid cursor type (%d)", cursorType);
		break;

	case kCursorTypeNormal:
	case kCursorType2:
		cursor = new CursorBase();
		cursor->init(id, name, cursorType, imageCount);
		break;

	case kCursorTypeImage: {
		cursor = new CursorImage();

		// Check archive type
		if (archiveType != kArchiveFile && archiveType != kArchiveArt)
			error("[CursorHandler::add] Invalid archive type (archiveType: %d)", archiveType);

		Common::String path;
		switch (loadFrom) {
		default:
			error("[CursorHandler::add] Cannot load image cursor (loadFrom: %d)", loadFrom);
			break;

		case kLoadFromCursor:
			path = Common::String::format("%sCURSOR/%s.tga", archiveType == kArchiveFile ? "" : "/", name.c_str());
			break;

		case kLoadFromListIcon:
			path = Common::String::format("%sLSTICON/%s.tga", archiveType == kArchiveFile ? "" : "/", name.c_str());
			break;
		}


		((CursorImage *)cursor)->init(id, path, cursorType, imageCount, archiveType);
		}
		break;

	case kCursorTypeAnimated:
		cursor = new CursorAnimation();
		((CursorAnimation *)cursor)->init(id, name, cursorType, imageCount, frameCount, frameRate, a6, loadFrom, archiveType);
		break;
	}

	_cursors.push_back(cursor);
}

void CursorHandler::removeByFrameCount(int framecount) {
	for (uint i = 0; i < _cursors.size();) {
		if (_cursors[i]->getFrameCount() == framecount) {
			SAFE_DELETE(_cursors[i]);
			_cursors.remove_at(i);
		} else {
			++i;
		}
	}

	select(kCursorIdle);
}

void CursorHandler::draw() {
	if (_cursors.empty())
		error("[CursorHandler::draw] No cursor present");

	_cursors[_index]->draw();
}

void CursorHandler::hide() const {
	CursorMan.showMouse(false);
}

void CursorHandler::select(CursorId id) {
	// FAUST.EXE 0x407db0 only logs this and keeps the current cursor. Faust relies on it:
	// object 6 on the race strip uses cursor 52, which the game never adds.
	if (!_cursors.has(id)) {
		debugC(kRingDebugLogic, "[CursorHandler::select] ID doesn't exist (%d)", id);
		return;
	}

	_index = _cursors.getIndex(id);
}

void CursorHandler::setOffset(CursorId id, const Common::Point &offset) {
	if (!_cursors.has(id))
		error("[CursorHandler::setOffset] ID doesn't exist (%d)", id);

	_cursors.get(id)->setOffset(offset);
}

CursorType CursorHandler::getType() {
	if (_cursors.empty())
		error("[CursorHandler::getType] No cursor present");

	return _cursors[_index]->getType();
}

#pragma endregion

} // End of namespace Ring
