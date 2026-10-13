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

#ifndef RING_IMAGE_HEADER_ENTRY_H
#define RING_IMAGE_HEADER_ENTRY_H

#include "ring/shared.h"

namespace Graphics {
struct Surface;
}

namespace Ring {

// An aquator image: a vector-quantized panorama (or a rectangle of one).
//
// Every uint16 code selects 4 horizontal pixels from a codebook of 16200
// RGB565 quads. The node entry owns the codebook, the decoded 32bpp panorama
// and the projection grid used to render the view (the exe keeps the latter
// in a global at 0x4cf968). Channel entries (animated layers) only hold the
// codes of their rectangle and are decoded into the node's panorama.
class ImageHeaderEntry {
public:
	struct Header {
		int32 width;          // Panorama width in pixels (always 2048)
		int32 height;         // Panorama height in pixels
		int32 bytesPerPixel;  // Of the original image (2)
		float hMin;           // Horizontal range (degrees)
		float hMax;
		float vMin;           // Vertical range (degrees)
		float vMax;
		int32 left;           // Rectangle covered by this entry
		int32 right;
		int32 top;
		int32 bottom;
		int32 size;           // pitch * (bottom - top), in bytes of the original image
		int32 pitch;

		Header();
		void load(Common::SeekableReadStream *stream);
		void computeSize();
	};

	struct Vector {
		float x;
		float y;
		float z;

		Vector() : x(0), y(0), z(0) {}
		Vector(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
	};

	ImageHeaderEntry();
	~ImageHeaderEntry();

	void reset();

	// Loading
	void init(Common::SeekableReadStream *stream, bool isNode);
	void init(ImageHeaderEntry *entry);
	void copyCodes(ImageHeaderEntry *entry) const;
	void decode(const ImageHeaderEntry *entry);
	void decodeAll();

	// Rendering
	void setCorners(const Vector *corners);
	void process();
	void offsetGrid(uint32 row, uint32 col, int32 u, int32 v);
	void clampGrid();
	void drawBuffer(Graphics::Surface *surface, int32 offsetY);
	void computeCoordinates(Common::Point *point);
	void adjustCoordinates(Common::Point *point);

	bool isInitialized() { return _codes != nullptr || _pixels != nullptr; }
	const Header &getHeader() { return _header; }

	static const uint32 kViewWidth  = 640;
	static const uint32 kViewHeight = 448;
	static const uint32 kGridCols   = 40;
	static const uint32 kGridRows   = 28;

private:
	Header  _header;
	uint16 *_codes;
	uint32 *_codebook;
	uint32 *_pixels;

	// Projection grid (16.16 panorama coordinates of every 16x16 block corner)
	int32   _gridU[64 * 64];
	int32   _gridV[64 * 64];
	Vector  _corners[4];

	uint32 getCodeCount() const;
	void drawBlock(const int32 *u, const int32 *v, byte *dst, int32 pitch, const Graphics::PixelFormat &format) const;
};

} // End of namespace Ring

#endif // RING_IMAGE_HEADER_ENTRY_H
