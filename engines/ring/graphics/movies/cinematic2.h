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

#ifndef RING_CINEMATIC2_H
#define RING_CINEMATIC2_H

#include "ring/graphics/movies/cinematic.h"

#include "ring/shared.h"

#include "common/array.h"
#include "common/stream.h"

#include "graphics/surface.h"

namespace Ring {

class Cinematic2 : public Cinematic {
public:
	Cinematic2();
	~Cinematic2();

	bool init(Common::String filename, ArchiveType type, ZoneId zone, LoadFrom loadFrom);

	void skipFrame() override;
	bool tControl() override;
	bool sControl(Graphics::Surface *surface, bool useAlpha);

	// Interlacing comes from the file header, so there is no state to reset
	void setState(bool) override {}
	void setInterlaced(bool interlaced) { _interlaced = interlaced; }

private:
	// Chunk 'T': tile set shared by the following frames
	struct TControlHeader {
		uint32 size;
		uint16 tileCount;
		uint16 tileSize;    // in dwords (one dword per pixel)

		TControlHeader() {
			size      = 0;
			tileCount = 0;
			tileSize  = 0;
		}

		bool read(Common::SeekableReadStream *stream) {
			size      = stream->readUint32LE();
			tileCount = stream->readUint16LE();
			tileSize  = stream->readUint16LE();

			return (!stream->eos() && !stream->err());
		}
	};

	// Chunks 'S' and 'U': tile indices, optionally followed by an embedded tile set
	struct FrameHeader {
		uint32 size;
		uint32 tileOffset;  // offset of the embedded tile set (== size when the frame uses the shared tile set)
		uint16 tileCount;
		uint16 tileSize;    // in dwords (one dword per pixel)
		uint32 width;
		uint32 height;
		uint32 field_14;
		uint32 field_18;
		uint32 field_1C;
		uint32 field_20;
		uint32 field_24;
		uint32 field_28;
		uint16 field_2C;
		byte   field_2E;

		FrameHeader() {
			size       = 0;
			tileOffset = 0;
			tileCount  = 0;
			tileSize   = 0;
			width      = 0;
			height     = 0;
			field_14   = 0;
			field_18   = 0;
			field_1C   = 0;
			field_20   = 0;
			field_24   = 0;
			field_28   = 0;
			field_2C   = 0;
			field_2E   = 0;
		}

		bool read(Common::SeekableReadStream *stream) {
			size       = stream->readUint32LE();
			tileOffset = stream->readUint32LE();
			tileCount  = stream->readUint16LE();
			tileSize   = stream->readUint16LE();
			width      = stream->readUint32LE();
			height     = stream->readUint32LE();
			field_14   = stream->readUint32LE();
			field_18   = stream->readUint32LE();
			field_1C   = stream->readUint32LE();
			field_20   = stream->readUint32LE();
			field_24   = stream->readUint32LE();
			field_28   = stream->readUint32LE();
			field_2C   = stream->readUint16LE();
			field_2E   = stream->readByte();

			return (!stream->eos() && !stream->err());
		}
	};

	// Cyclic list of the last 16 tile indices decoded below a given tile index
	struct TileContext {
		uint16 list[16];
		byte   pos;
	};

	bool                        _interlaced;
	Common::Array<byte>         _buffer;
	Common::Array<byte>         _tiles;          // tileCount * tileSize bytes, BGRA
	uint32                      _tileCount;
	uint32                      _tileSize;       // in bytes
	Common::Array<uint16>       _indices;
	Common::Array<TileContext>  _contexts;
	FrameHeader                 _frameHeader;
	TControlHeader              _tControlHeader;

	bool decompressTControl(const byte *data, uint32 dataSize, uint32 tileCount, uint32 tileSize);
	bool decompressSeq(const byte *data, uint32 dataSize, Graphics::Surface *surface, bool skipEmptyTiles, bool useAlpha);
};

} // End of namespace Ring

#endif // RING_CINEMATIC2_H
