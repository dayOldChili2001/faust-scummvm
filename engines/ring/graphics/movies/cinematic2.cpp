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

#include "ring/graphics/movies/cinematic2.h"

#include "ring/base/application.h"
#include "ring/base/art.h"

#include "ring/ring.h"
#include "ring/helpers.h"

namespace Ring {

#pragma region BitReader

namespace {

// CI2 bitstreams are read LSB first. Reading past the end returns zeroes.
class BitReader {
public:
	BitReader(const byte *data, uint32 size) : _data(data), _size(size), _pos(0) {}

	uint32 getBits(uint32 count) {
		uint32 value = 0;

		for (uint32 i = 0; i < count; i++) {
			uint32 bytePos = _pos >> 3;
			if (bytePos < _size)
				value |= (uint32)((_data[bytePos] >> (_pos & 7)) & 1) << i;

			++_pos;
		}

		return value;
	}

	bool getBit() { return getBits(1) != 0; }

	bool isOverrun() const { return (_pos >> 3) > _size; }

private:
	const byte *_data;
	uint32      _size;
	uint32      _pos;
};

} // End of anonymous namespace

#pragma endregion

#pragma region Cinematic2

Cinematic2::Cinematic2() {
	_stream = nullptr;
	_interlaced = false;
	_tileCount = 0;
	_tileSize = 0;
}

Cinematic2::~Cinematic2() {
	SAFE_DELETE(_stream);
}

bool Cinematic2::init(Common::String filename, ArchiveType type, ZoneId zone, LoadFrom loadFrom) {
	// Initialize stream
	switch (type) {
	default:
		warning("[Cinematic2::init] Invalid archive type (%d)!", type);
		return false;

	case kArchiveFile:
		_stream = SearchMan.createReadStreamForMember(Common::Path(filename, '/'));
		break;

	case kArchiveArt:
		_stream = getApp()->getArtHandler()->get(filename, zone, loadFrom);
		break;
	}

	if (_stream == nullptr)
		return false;

	_interlaced = false;
	_tileCount = 0;
	_tileSize = 0;

	return true;
}

void Cinematic2::skipFrame() {
	// Read frame header
	if (!_frameHeader.read(_stream))
		error("[Cinematic2::skipFrame] Cannot read frame header");

	debugC(kRingDebugMovie, "    Skipping frame data (size: %d)", _frameHeader.size);

	// Skip frame
	seek(_frameHeader.size, SEEK_CUR);
}

bool Cinematic2::tControl() {
	if (!_stream)
		error("[Cinematic2::tControl] Stream not initialized");

	// Read tControl header
	if (!_tControlHeader.read(_stream)) {
		error("[Cinematic2::tControl] Cannot read tControl header");
	}

	debugC(kRingDebugMovie, "    Reading T control header (size: %d, tileCount: %d, tileSize: %d)",
		_tControlHeader.size, _tControlHeader.tileCount, _tControlHeader.tileSize);

	// Read tile data
	_buffer.resize(_tControlHeader.size);
	if (_tControlHeader.size && _stream->read(_buffer.data(), _tControlHeader.size) != _tControlHeader.size) {
		warning("[Cinematic2::tControl] Cannot read tControl data");
		return false;
	}

	return decompressTControl(_buffer.data(), _tControlHeader.size, _tControlHeader.tileCount, 4 * _tControlHeader.tileSize);
}

bool Cinematic2::sControl(Graphics::Surface *surface, bool useAlpha) {
	if (!_stream)
		error("[Cinematic2::sControl] Stream not initialized");

	// Read frame header
	if (!_frameHeader.read(_stream)) {
		warning("[Cinematic2::sControl] Cannot read frame header");
		return false;
	}

	debugC(kRingDebugMovie, "    Reading Frame header (size: %d, tileOffset: %d, tileCount: %d, tileSize: %d, width: %d, height: %d)",
	       _frameHeader.size, _frameHeader.tileOffset, _frameHeader.tileCount, _frameHeader.tileSize, _frameHeader.width, _frameHeader.height);

	// Read frame data
	_buffer.resize(_frameHeader.size);
	if (_frameHeader.size && _stream->read(_buffer.data(), _frameHeader.size) != _frameHeader.size) {
		warning("[Cinematic2::sControl] Cannot read frame data");
		return false;
	}

	// Empty frame: nothing changes
	if (_frameHeader.width == 0 && _frameHeader.height == 0)
		return true;

	if (_frameHeader.width != (uint32)surface->w || _frameHeader.height != (uint32)surface->h) {
		warning("[Cinematic2::sControl] Frame size mismatch (frame: %dx%d, surface: %dx%d)", _frameHeader.width, _frameHeader.height, surface->w, surface->h);
		return false;
	}

	// Still images embed their own tile set after the tile indices. Movie frames
	// use the tile set from the last T chunk, and tile 0 marks an unchanged area.
	uint32 indicesSize = _frameHeader.size;
	bool embeddedTiles = (_frameHeader.tileOffset < _frameHeader.size);
	if (embeddedTiles) {
		if (!decompressTControl(_buffer.data() + _frameHeader.tileOffset, _frameHeader.size - _frameHeader.tileOffset, _frameHeader.tileCount, 4 * _frameHeader.tileSize))
			return false;

		indicesSize = _frameHeader.tileOffset;
	} else if (_frameHeader.tileCount != _tileCount || 4u * _frameHeader.tileSize != _tileSize) {
		warning("[Cinematic2::sControl] Frame does not match the current tile set (tiles: %d/%d, size: %d/%d)", _frameHeader.tileCount, _tileCount, 4 * _frameHeader.tileSize, _tileSize);
		return false;
	}

	return decompressSeq(_buffer.data(), indicesSize, surface, !embeddedTiles, useAlpha);
}

bool Cinematic2::decompressTControl(const byte *data, uint32 dataSize, uint32 tileCount, uint32 tileSize) {
	if (tileCount == 0 || tileSize == 0 || (tileSize % 4) || dataSize < tileSize) {
		warning("[Cinematic2::decompressTControl] Invalid tile data (count: %d, size: %d, data size: %d)", tileCount, tileSize, dataSize);
		return false;
	}

	_tileCount = tileCount;
	_tileSize = tileSize;
	_tiles.resize(tileCount * tileSize);

	// The first tile is stored raw
	memcpy(_tiles.data(), data, tileSize);

	// Each following tile is coded as a delta from the previous one,
	// one component (B, G, R, A) at a time
	BitReader bits(data + tileSize, dataSize - tileSize);
	for (uint32 tile = 1; tile < tileCount; tile++) {
		byte *current = &_tiles[tile * tileSize];
		memcpy(current, current - tileSize, tileSize);

		for (uint32 component = 0; component < 4; component++) {
			uint32 deltaBits = bits.getBits(3);
			if (deltaBits == 0)
				continue;

			for (uint32 i = component; i < tileSize; i += 4) {
				if (deltaBits == 7) {
					current[i] = (byte)bits.getBits(8);
					continue;
				}

				byte delta = (byte)bits.getBits(deltaBits);
				if (delta && bits.getBit())
					current[i] -= delta;
				else
					current[i] += delta;
			}
		}
	}

	if (bits.isOverrun()) {
		warning("[Cinematic2::decompressTControl] Tile data is truncated");
		return false;
	}

	return true;
}

bool Cinematic2::decompressSeq(const byte *data, uint32 dataSize, Graphics::Surface *surface, bool skipEmptyTiles, bool useAlpha) {
	uint32 tilePixels = _tileSize / 4;
	if ((uint32)surface->w % tilePixels) {
		warning("[Cinematic2::decompressSeq] Width %d is not a multiple of the tile width %d", surface->w, tilePixels);
		return false;
	}

	uint32 tilesPerRow = surface->w / tilePixels;
	uint32 rows = _interlaced ? surface->h / 2 : surface->h;
	uint32 total = tilesPerRow * rows;

	uint32 indexBits = 0;
	while ((_tileCount >> indexBits) > 0)
		++indexBits;

	_indices.resize(total);
	_contexts.resize(_tileCount);
	memset(_contexts.data(), 0, _contexts.size() * sizeof(TileContext));

	// Tile indices are coded in groups of eight. Groups run on across rows,
	// so a group can start on one row and end on the next.
	BitReader bits(data, dataSize);
	for (uint32 group = 0; group < total; group += 8) {
		uint32 groupEnd = MIN<uint32>(group + 8, total);

		// Copy the whole group from the row above
		if (bits.getBit()) {
			for (uint32 i = group; i < groupEnd; i++)
				_indices[i] = (i >= tilesPerRow) ? _indices[i - tilesPerRow] : 0;

			continue;
		}

		for (uint32 i = group; i < groupEnd; i++) {
			uint32 x = i % tilesPerRow;
			uint32 y = i / tilesPerRow;
			uint16 top = (y > 0) ? _indices[i - tilesPerRow] : 0;
			uint32 index;
			bool updateContext = true;

			if (bits.getBit()) {
				// Same as above
				index = top;
				updateContext = false;
			} else {
				switch (bits.getBits(2)) {
				default:
				case 0:
					// New index
					index = bits.getBits(indexBits);
					break;

				case 1: {
					// Pick one of the neighbours that differ from the tile above
					uint16 list[4];
					uint32 count = 0;
					int32 candidates[4] = {
						(x > 0)                            ? (int32)i - 1                   : -1,
						(x > 0 && y > 0)                   ? (int32)(i - tilesPerRow - 1)   : -1,
						(x + 1 < tilesPerRow && y > 0)     ? (int32)(i - tilesPerRow + 1)   : -1,
						(y > 1)                            ? (int32)(i - 2 * tilesPerRow)   : -1
					};

					for (uint32 c = 0; c < 4; c++) {
						if (candidates[c] < 0)
							continue;

						uint16 value = _indices[candidates[c]];
						if (y > 0 && value == top)
							continue;

						bool found = false;
						for (uint32 j = 0; j < count; j++)
							found |= (list[j] == value);

						if (!found)
							list[count++] = value;
					}

					if (count == 0) {
						warning("[Cinematic2::decompressSeq] No neighbour to pick from at tile %d", i);
						return false;
					}

					uint32 pick = 0;
					if (count == 2)
						pick = bits.getBits(1);
					else if (count > 2)
						pick = bits.getBits(2);

					if (pick >= count) {
						warning("[Cinematic2::decompressSeq] Invalid neighbour %d (count: %d) at tile %d", pick, count, i);
						return false;
					}

					index = list[pick];
					}
					break;

				case 2: {
					// Small delta from the tile above
					uint32 delta = bits.getBits(4) + 1;
					if (bits.getBit())
						index = (top >= delta) ? top - delta : _tileCount;
					else
						index = top + delta;
					}
					break;

				case 3:
					// Recently seen below the tile above
					index = _contexts[top].list[bits.getBits(4)];
					updateContext = false;
					break;
				}
			}

			if (index >= _tileCount) {
				warning("[Cinematic2::decompressSeq] Invalid tile index %d (count: %d)", index, _tileCount);
				return false;
			}

			_indices[i] = (uint16)index;

			if (updateContext && y > 0) {
				TileContext &context = _contexts[top];
				context.list[context.pos] = (uint16)index;
				context.pos = (context.pos + 1) & 15;
			}
		}
	}

	if (bits.isOverrun()) {
		warning("[Cinematic2::decompressSeq] Frame data is truncated");
		return false;
	}

	// Draw tiles. Frames are stored bottom-up, and interlaced frames only code every other line.
	const Graphics::PixelFormat &format = surface->format;
	for (uint32 row = 0; row < rows; row++) {
		uint32 line = rows - 1 - row;
		if (_interlaced)
			line *= 2;

		uint32 *dst = (uint32 *)surface->getBasePtr(0, line);
		for (uint32 x = 0; x < tilesPerRow; x++, dst += tilePixels) {
			uint16 index = _indices[row * tilesPerRow + x];
			if (skipEmptyTiles && index == 0)
				continue;

			const byte *tile = &_tiles[index * _tileSize];
			for (uint32 p = 0; p < tilePixels; p++, tile += 4)
				dst[p] = format.ARGBToColor(useAlpha ? tile[3] : 0xFF, tile[2], tile[1], tile[0]);
		}

		if (_interlaced)
			memcpy(surface->getBasePtr(0, line + 1), surface->getBasePtr(0, line), surface->w * format.bytesPerPixel);
	}

	return true;
}

#pragma endregion

} // End of namespace Ring
