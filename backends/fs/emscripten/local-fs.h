/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef LOCAL_FILESYSTEM_H
#define LOCAL_FILESYSTEM_H

#include "backends/fs/abstract-fs.h"

#define LOCAL_FS_PATH "/game"

/**
 * Read-only view of a folder the player picked in the browser (Faust's
 * dists/emscripten/faust/folder-picker.js), mounted at LOCAL_FS_PATH.
 * Names are matched without regard to case, like on the original's Windows.
 */
class LocalFilesystemNode : public AbstractFSNode {
protected:
	Common::String _path;
	Common::String _displayName;
	int _kind; // 0 missing, 1 file, 2 directory

public:
	LocalFilesystemNode(const Common::String &path);

	static bool isMounted();

	bool exists() const override { return _kind != 0; }
	Common::U32String getDisplayName() const override { return _displayName; }
	Common::String getName() const override { return _displayName; }
	Common::String getPath() const override { return _path; }
	bool isDirectory() const override { return _kind == 2; }
	bool isReadable() const override { return exists(); }
	bool isWritable() const override { return false; }

	AbstractFSNode *getChild(const Common::String &n) const override;
	bool getChildren(AbstractFSList &list, ListMode mode, bool hidden) const override;
	AbstractFSNode *getParent() const override;

	Common::SeekableReadStream *createReadStream() override;
	Common::SeekableWriteStream *createWriteStream(bool atomic) override { return nullptr; }
	bool createDirectory() override { return false; }
};

#endif
