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

// emscripten.h declares FILE
#define FORBIDDEN_SYMBOL_EXCEPTION_FILE

#ifdef EMSCRIPTEN

#include "backends/fs/emscripten/local-fs.h"
#include "backends/fs/fs-factory.h"
#include "common/debug.h"
#include "common/memstream.h"
#include "common/system.h"
#include <emscripten.h>

EM_JS(int, _localFsStat, (const char *path), {
	return globalThis.faustLocalFs ? globalThis.faustLocalFs.stat(UTF8ToString(path)) : 0;
});

// Returns a malloc'd string (or NULL): one child per line, 'D' or 'F' + name
EM_JS(char *, _localFsList, (const char *path), {
	var s = globalThis.faustLocalFs ? globalThis.faustLocalFs.list(UTF8ToString(path)) : null;
	if (s === null) return 0;
	var size = lengthBytesUTF8(s) + 1, ret = Module._malloc(size);
	stringToUTF8Array(s, HEAP8, ret, size);
	return ret;
});

EM_JS(char *, _localFsRealName, (const char *path), {
	var s = globalThis.faustLocalFs ? globalThis.faustLocalFs.realName(UTF8ToString(path)) : null;
	if (s === null) return 0;
	var size = lengthBytesUTF8(s) + 1, ret = Module._malloc(size);
	stringToUTF8Array(s, HEAP8, ret, size);
	return ret;
});

// Reads the whole file into a malloc'd buffer; its size goes to *sizePtr
EM_ASYNC_JS(byte *, _localFsRead, (const char *path, uint32 *sizePtr), {
	try {
		var data = await globalThis.faustLocalFs.read(UTF8ToString(path));
		if (data === null) return 0;
		var ptr = Module._malloc(Math.max(data.length, 1));
		if (!ptr) return 0;
		Module.writeArrayToMemory(data, ptr);
		setValue(sizePtr, data.length, "i32");
		return ptr;
	} catch (e) {
		console.error("LocalFilesystemNode: reading " + UTF8ToString(path) + " failed", e);
		return 0;
	}
});

bool LocalFilesystemNode::isMounted() {
	return _localFsStat(LOCAL_FS_PATH) == 2;
}

LocalFilesystemNode::LocalFilesystemNode(const Common::String &path) {
	_path = Common::normalizePath(path, '/');
	_kind = _localFsStat(_path.c_str());
	char *name = _kind ? _localFsRealName(_path.c_str()) : nullptr;
	if (name) {
		_displayName = name;
		free(name);
	} else {
		_displayName = Common::lastPathComponent(_path, '/');
	}
}

AbstractFSNode *LocalFilesystemNode::getChild(const Common::String &n) const {
	assert(!n.contains('/'));
	return new LocalFilesystemNode(_path + "/" + n);
}

bool LocalFilesystemNode::getChildren(AbstractFSList &list, ListMode mode, bool hidden) const {
	char *s = _kind == 2 ? _localFsList(_path.c_str()) : nullptr;
	if (!s)
		return false;
	Common::String all(s);
	free(s);
	for (uint start = 0; start < all.size();) {
		uint end = start;
		while (end < all.size() && all[end] != '\n')
			end++;
		Common::String line(all.c_str() + start, end - start);
		start = end + 1;
		if (line.size() < 2)
			continue;
		bool isDir = line[0] == 'D';
		Common::String name(line.c_str() + 1);
		if (!hidden && name.hasPrefix("."))
			continue;
		if ((mode == Common::FSNode::kListFilesOnly && isDir) || (mode == Common::FSNode::kListDirectoriesOnly && !isDir))
			continue;
		list.push_back(new LocalFilesystemNode(_path + "/" + name));
	}
	return true;
}

AbstractFSNode *LocalFilesystemNode::getParent() const {
	if (_path == LOCAL_FS_PATH)
		return g_system->getFilesystemFactory()->makeRootFileNode();
	return g_system->getFilesystemFactory()->makeFileNodePath(_path.substr(0, _path.findLastOf('/')));
}

Common::SeekableReadStream *LocalFilesystemNode::createReadStream() {
	if (_kind != 1)
		return nullptr;
	// The whole file is read on open: a read inside a stream could then run
	// from the audio callback, where an async (Asyncify) call isn't allowed.
	uint32 size = 0;
	byte *data = _localFsRead(_path.c_str(), &size);
	if (!data) {
		warning("LocalFilesystemNode: can't read %s", _path.c_str());
		return nullptr;
	}
	debug(5, "LocalFilesystemNode::createReadStream(%s): %u bytes", _path.c_str(), size);
	return new Common::MemoryReadStream(data, size, DisposeAfterUse::YES);
}

#endif // EMSCRIPTEN
