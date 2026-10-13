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

#include "ring/graphics/aquator/image_header_entry.h"

#include "ring/base/stream.h"

#include "ring/ring.h"

#include "graphics/surface.h"

namespace Ring {

// The codebook holds 16200 entries of 4 RGB565 pixels (129600 bytes)
#define CODEBOOK_PIXELS 64800

// Panorama textures are always 2048 pixels wide (the renderer wraps on it)
#define TEXTURE_WIDTH 2048

ImageHeaderEntry::Header::Header() {
	width = 0;
	height = 0;
	bytesPerPixel = 0;
	hMin = 0;
	hMax = 0;
	vMin = 0;
	vMax = 0;
	left = 0;
	right = 0;
	top = 0;
	bottom = 0;
	size = 0;
	pitch = 0;
}

void ImageHeaderEntry::Header::load(Common::SeekableReadStream *stream) {
	width         = stream->readSint32LE();
	height        = stream->readSint32LE();
	bytesPerPixel = stream->readSint32LE();
	hMin          = convertIEEEFloat(stream->readUint32LE());
	hMax          = convertIEEEFloat(stream->readUint32LE());
	vMin          = convertIEEEFloat(stream->readUint32LE());
	vMax          = convertIEEEFloat(stream->readUint32LE());
	left          = stream->readSint32LE();
	right         = stream->readSint32LE();
	top           = stream->readSint32LE();
	bottom        = stream->readSint32LE();
	size          = stream->readSint32LE();
	pitch         = stream->readSint32LE();
}

// 0x4057c0
void ImageHeaderEntry::Header::computeSize() {
	if (!right)
		right = width;

	if (!bottom)
		bottom = height;

	pitch = bytesPerPixel * (right - left);
	size = pitch * (bottom - top);
}

ImageHeaderEntry::ImageHeaderEntry() {
	_codes    = nullptr;
	_codebook = nullptr;
	_pixels   = nullptr;

	memset(_gridU, 0, sizeof(_gridU));
	memset(_gridV, 0, sizeof(_gridV));
}

ImageHeaderEntry::~ImageHeaderEntry() {
	reset();
}

void ImageHeaderEntry::reset() {
	delete[] _codes;
	delete[] _codebook;
	delete[] _pixels;

	_codes    = nullptr;
	_codebook = nullptr;
	_pixels   = nullptr;
}

uint32 ImageHeaderEntry::getCodeCount() const {
	// The exe reads size / 4 bytes of codes
	return (uint32)_header.size / 8;
}

// 0x405940
void ImageHeaderEntry::init(Common::SeekableReadStream *stream, bool isNode) {
	reset();

	_header.load(stream);
	_header.computeSize();

	if (_header.size < 0 || _header.size > 10000000)
		error("[ImageHeaderEntry::init] Invalid image size (%d)", _header.size);

	uint32 count = getCodeCount();
	_codes = new uint16[count];
	for (uint32 i = 0; i < count; i++)
		_codes[i] = stream->readUint16LE();

	if (!isNode)
		return;

	if (_header.width != TEXTURE_WIDTH)
		error("[ImageHeaderEntry::init] Unsupported panorama width (%d)", _header.width);

	// Read the codebook and convert it to 32bpp (0x403dd0)
	_codebook = new uint32[CODEBOOK_PIXELS];
	for (uint32 i = 0; i < CODEBOOK_PIXELS; i++) {
		uint16 color = stream->readUint16LE();

		uint32 r = (color >> 8) & 0xF8;
		uint32 g = (color >> 3) & 0xFC;
		uint32 b = (color << 3) & 0xF8;

		_codebook[i] = (r << 16) | (g << 8) | b;
	}

	_pixels = new uint32[_header.width * _header.height];
	memset(_pixels, 0, _header.width * _header.height * sizeof(uint32));
}

// 0x405900
void ImageHeaderEntry::init(ImageHeaderEntry *entry) {
	reset();

	_header = entry->getHeader();
	_header.computeSize();

	_codes = new uint16[getCodeCount()];
}

// 0x405a80: copy the node codes covered by the entry rectangle into the entry
void ImageHeaderEntry::copyCodes(ImageHeaderEntry *entry) const {
	if (!_codes || !entry->_codes)
		error("[ImageHeaderEntry::copyCodes] Codes not initialized properly");

	const Header &header = entry->getHeader();
	int32 stride = (header.right - header.left) / 4;

	const uint16 *src = _codes + header.top * (_header.width / 4) + header.left / 4;
	uint16 *dst = entry->_codes;

	for (int32 row = header.top; row < header.bottom; row++) {
		memcpy(dst, src, stride * sizeof(uint16));

		src += _header.width / 4;
		dst += stride;
	}
}

// 0x4059b0: decode the entry codes into the node panorama
void ImageHeaderEntry::decode(const ImageHeaderEntry *entry) {
	if (!_pixels || !_codebook || !entry->_codes)
		error("[ImageHeaderEntry::decode] Buffers not initialized properly");

	const Header &header = entry->_header;
	int32 stride = (header.right - header.left) / 4;

	const uint16 *codes = entry->_codes;

	for (int32 row = header.top; row < header.bottom; row++) {
		uint32 *dst = _pixels + row * _header.width + header.left;

		for (int32 i = 0; i < stride; i++) {
			uint16 code = *codes++;
			if (code >= CODEBOOK_PIXELS / 4)
				error("[ImageHeaderEntry::decode] Invalid code (%d)", code);

			memcpy(dst, &_codebook[code * 4], 4 * sizeof(uint32));
			dst += 4;
		}
	}
}

// End of 0x403f80: decode the whole node, the codes are not needed afterwards
void ImageHeaderEntry::decodeAll() {
	decode(this);

	delete[] _codes;
	_codes = nullptr;
}

//////////////////////////////////////////////////////////////////////////
// Rendering
//////////////////////////////////////////////////////////////////////////

// 0x403a40 (called with the corners already rotated to world space)
void ImageHeaderEntry::setCorners(const Vector *corners) {
	for (uint32 i = 0; i < 4; i++)
		_corners[i] = corners[i];
}

// 0x404f80: project every block corner of the view onto the panorama
void ImageHeaderEntry::process() {
	const float pi = (float)M_PI;

	float vRange  = _header.vMax - _header.vMin;
	float vCenter = (_header.vMax + _header.vMin) * 0.5f;
	float hRange  = _header.hMax - _header.hMin;
	float hCenter = (_header.hMax + _header.hMin) * 0.5f;
	float height  = (float)_header.height;

	for (uint32 row = 0; row <= kGridRows; row++) {
		for (uint32 col = 0; col <= kGridCols; col++) {
			// Bilinear interpolation of the corner rays
			float a = (float)(kGridCols - col);
			float b = (float)col;
			float c = (float)(kGridRows - row);
			float d = (float)row;

			float x = ((a * _corners[0].x + b * _corners[1].x) / kGridCols * c + (a * _corners[2].x + b * _corners[3].x) / kGridCols * d) / kGridRows;
			float y = ((a * _corners[0].y + b * _corners[1].y) / kGridCols * c + (a * _corners[2].y + b * _corners[3].y) / kGridCols * d) / kGridRows;
			float z = ((a * _corners[0].z + b * _corners[1].z) / kGridCols * c + (a * _corners[2].z + b * _corners[3].z) / kGridCols * d) / kGridRows;

			double length = sqrt(x * x + y * y + z * z);

			double latitude = CLIP<double>(y / length, -1.0, 1.0);
			latitude = asin(latitude);

			double cosLatitude = cos(latitude);
			double longitude = (cosLatitude == 0.0) ? 0.0 : CLIP<double>(x / length / cosLatitude, -1.0, 1.0);
			longitude = asin(longitude);

			if (z < 0.0f) {
				if (longitude > 0.0)
					longitude = pi - longitude;
				else
					longitude = -pi - longitude;
			}

			double v = (latitude * 180.0 / pi - vCenter) / vRange * height + height * 0.5f;
			double u = (longitude * 180.0 / pi + hCenter) / hRange * (float)TEXTURE_WIDTH;

			_gridU[row * 64 + col] = (int32)(u * 65536.0f);
			_gridV[row * 64 + col] = (int32)(v * 65536.0f);
		}
	}
}

void ImageHeaderEntry::offsetGrid(uint32 row, uint32 col, int32 u, int32 v) {
	_gridU[row * 64 + col] += u;
	_gridV[row * 64 + col] += v;
}

// 0x4054b0
void ImageHeaderEntry::clampGrid() {
	int32 vMax = (_header.height - 2) << 16;

	for (uint32 row = 0; row <= kGridRows; row++)
		for (uint32 col = 0; col <= kGridCols; col++)
			_gridV[row * 64 + col] = CLIP<int32>(_gridV[row * 64 + col], 0, vMax);
}

// 0x405550
void ImageHeaderEntry::drawBuffer(Graphics::Surface *surface, int32 offsetY) {
	if (!_pixels)
		error("[ImageHeaderEntry::drawBuffer] Buffer not initialized properly");

	if (surface->format.bytesPerPixel != 2 && surface->format.bytesPerPixel != 4)
		error("[ImageHeaderEntry::drawBuffer] Unsupported surface format (%d bpp)", surface->format.bytesPerPixel * 8);

	for (uint32 row = 0; row < kGridRows; row++) {
		for (uint32 col = 0; col < kGridCols; col++) {
			uint32 index = row * 64 + col;

			int32 u[4] = { _gridU[index], _gridU[index + 1], _gridU[index + 64], _gridU[index + 65] };
			int32 v[4] = { _gridV[index], _gridV[index + 1], _gridV[index + 64], _gridV[index + 65] };

			byte *dst = (byte *)surface->getBasePtr(col * 16, offsetY + row * 16);

			drawBlock(u, v, dst, surface->pitch, surface->format);
		}
	}
}

// 0x404570 (MMX): bilinear texture mapping of a 16x16 block
void ImageHeaderEntry::drawBlock(const int32 *u, const int32 *v, byte *dst, int32 pitch, const Graphics::PixelFormat &format) const {
	// Fix horizontal wrapping around the panorama seam (0x404780)
	const int32 period = TEXTURE_WIDTH << 16;
	int32 uA = u[0];
	int32 uB = u[1];
	int32 uC = u[2];
	int32 uD = u[3];

	int32 *others[3] = { &uB, &uC, &uD };
	for (uint32 i = 0; i < 3; i++) {
		if (*others[i] - uA > period / 2)
			*others[i] -= period;
		else if (uA - *others[i] > period / 2)
			*others[i] += period;
	}

	int32 uLeft  = uA;
	int32 vLeft  = v[0];
	int32 uRight = uB;
	int32 vRight = v[1];

	int32 uLeftStep  = (uC - uA) >> 4;
	int32 vLeftStep  = (v[2] - v[0]) >> 4;
	int32 uRightStep = (uD - uB) >> 4;
	int32 vRightStep = (v[3] - v[1]) >> 4;

	for (uint32 y = 0; y < 16; y++) {
		int32 uCurrent = uLeft;
		int32 vCurrent = vLeft;
		int32 uStep = (uRight - uLeft) >> 4;
		int32 vStep = (vRight - vLeft) >> 4;

		byte *line = dst;

		for (uint32 x = 0; x < 16; x++) {
			uint32 tx  = (uint32)(uCurrent >> 16) & (TEXTURE_WIDTH - 1);
			uint32 tx1 = (tx + 1) & (TEXTURE_WIDTH - 1);
			uint32 ty  = (uint32)(vCurrent >> 16) & 0x3FF;
			int32 fx = (uCurrent & 0xFFFF) >> 8;
			int32 fy = (vCurrent & 0xFFFF) >> 8;

			const uint32 *texel = _pixels + ty * TEXTURE_WIDTH;
			uint32 p00 = texel[tx];
			uint32 p01 = texel[tx1];
			uint32 p10 = texel[TEXTURE_WIDTH + tx];
			uint32 p11 = texel[TEXTURE_WIDTH + tx1];

			byte rgb[3];
			for (uint32 i = 0; i < 3; i++) {
				uint32 shift = 16 - i * 8;
				int32 c00 = (p00 >> shift) & 0xFF;
				int32 c01 = (p01 >> shift) & 0xFF;
				int32 c10 = (p10 >> shift) & 0xFF;
				int32 c11 = (p11 >> shift) & 0xFF;

				int32 top    = (c00 << 8) + (c01 - c00) * fx;
				int32 bottom = (c10 << 8) + (c11 - c10) * fx;

				rgb[i] = (byte)(((top << 8) + (bottom - top) * fy) >> 16);
			}

			uint32 color = format.RGBToColor(rgb[0], rgb[1], rgb[2]);
			if (format.bytesPerPixel == 2)
				*(uint16 *)line = (uint16)color;
			else
				*(uint32 *)line = color;

			line += format.bytesPerPixel;

			uCurrent += uStep;
			vCurrent += vStep;
		}

		uLeft  += uLeftStep;
		vLeft  += vLeftStep;
		uRight += uRightStep;
		vRight += vRightStep;

		dst += pitch;
	}
}

// 0x404cd0: screen coordinates to panorama pixel
void ImageHeaderEntry::computeCoordinates(Common::Point *point) {
	point->x = CLIP<int16>(point->x, 0, kViewWidth - 1);
	point->y = CLIP<int16>(point->y, 0, kViewHeight - 1);

	int32 col = point->x / 16;
	int32 row = point->y / 16;
	float fx = (float)(point->x % 16);
	float fy = (float)(point->y % 16);

	uint32 index = row * 64 + col;

	float u00 = _gridU[index]      / 65536.0f;
	float u01 = _gridU[index + 1]  / 65536.0f;
	float u10 = _gridU[index + 64] / 65536.0f;
	float u11 = _gridU[index + 65] / 65536.0f;

	// Fix wrapping around the panorama seam
	float *others[3] = { &u01, &u10, &u11 };
	for (uint32 i = 0; i < 3; i++) {
		if (*others[i] - u00 > TEXTURE_WIDTH * 0.5f)
			*others[i] -= TEXTURE_WIDTH;
		else if (u00 - *others[i] > TEXTURE_WIDTH * 0.5f)
			*others[i] += TEXTURE_WIDTH;
	}

	float v00 = _gridV[index]      / 65536.0f;
	float v01 = _gridV[index + 1]  / 65536.0f;
	float v10 = _gridV[index + 64] / 65536.0f;
	float v11 = _gridV[index + 65] / 65536.0f;

	int32 x = (int32)((((16 - fx) * u00 + fx * u01) * (16 - fy) + ((16 - fx) * u10 + fx * u11) * fy) * 0.0625f * 0.0625f);
	int32 y = (int32)((((16 - fx) * v00 + fx * v01) * (16 - fy) + ((16 - fx) * v10 + fx * v11) * fy) * 0.0625f * 0.0625f);

	x %= TEXTURE_WIDTH;
	if (x < 0)
		x += TEXTURE_WIDTH;

	point->x = (int16)x;
	point->y = (int16)(y % _header.height);
}

// 0x405680: panorama pixel to tenths of degrees (the unit of rotation hotspots)
void ImageHeaderEntry::adjustCoordinates(Common::Point *point) {
	float height = (float)_header.height;
	float vRange  = _header.vMax - _header.vMin;
	float vCenter = (_header.vMax + _header.vMin) * 0.5f;
	float hRange  = _header.hMax - _header.hMin;

	point->x = (int16)(point->x / (float)TEXTURE_WIDTH * hRange * 10.0f);
	point->y = (int16)(((point->y - height * 0.5f) / height * vRange + vCenter) * 10.0f);
}

} // End of namespace Ring
