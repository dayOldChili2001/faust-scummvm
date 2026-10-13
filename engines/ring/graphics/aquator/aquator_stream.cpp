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

#include "ring/graphics/aquator/aquator_stream.h"

#include "ring/graphics/aquator/aquator_image_header.h"
#include "ring/graphics/aquator/image_header.h"

#include "ring/base/stream.h"

#include "ring/helpers.h"
#include "ring/ring.h"

#include "common/archive.h"
#include "graphics/surface.h"

namespace Ring {

AquatorStream::AquatorStream(uint32 count, Common::String path) {
	_entry = new ImageHeaderEntry();

	_path = path;

	for (uint32 i = 0; i < count; i++)
		_headers.push_back(new AquatorImageHeader());
}

AquatorStream::~AquatorStream() {
	CLEAR_ARRAY(AquatorImageHeader, _headers);
	SAFE_DELETE(_entry);
}

void AquatorStream::alloc(bool isCompressed, uint32 size) {
	if (isCompressed) {
		Common::String filename = Common::String::format("%s.aqc", _path.c_str());

		// Decompress node
		CompressedStream *stream = new CompressedStream();
		if (!stream->init(filename, 2, size))
			error("[AquatorStream::alloc] Cannot init compressed stream for aquator file (%s)", filename.c_str());

		initNode(stream->decompressNode());

		// Decompress each channel
		for (uint32 i = 0; i < _headers.size(); i++)
			initChannel(stream->decompressChannel(), i);

		delete stream;
	} else {
		// Open a stream to the uncompressed aquator file
		Common::String filename = Common::String::format("%s.aqi", _path.c_str());
		Common::SeekableReadStream *archive = SearchMan.createReadStreamForMember(Common::Path(filename, '/'));
		if (!archive)
			error("[AquatorStream::alloc] Error opening uncompressed aquator (%s)", filename.c_str());

		initNode(archive);

		// Init channels
		for (uint32 i = 0; i < _headers.size(); i++)
			initStream(i);
	}

	// Channels keep a copy of the node codes they cover, so decode the node last
	_entry->decodeAll();
}

// 0x4042c0
void AquatorStream::dealloc() {
	for (uint32 i = 0; i < _headers.size(); i++)
		_headers[i]->getHeader()->reset();

	_entry->reset();
}

void AquatorStream::initNode(Common::SeekableReadStream *stream) {
	if (!stream)
		error("[AquatorStream::initNode] Invalid node stream");

	_entry->init(stream, true);

	delete stream;
}

void AquatorStream::initStream(uint32 index) {
	Common::String filename = Common::String::format("%s_%03i.aqc", _path.c_str(), index);
	Common::SeekableReadStream *archive = SearchMan.createReadStreamForMember(Common::Path(filename, '/'));
	if (!archive)
		error("[AquatorStream::initStream] Error opening aquator channel (%s)", filename.c_str());

	initChannel(archive, index);
}

void AquatorStream::initChannel(Common::SeekableReadStream *stream, uint32 index) {
	AquatorImageHeader *aquatorHeader = _headers[index];
	ImageHeader *imageHeader = aquatorHeader->getHeader();

	if (!stream)
		error("[AquatorStream::initChannel] Invalid channel stream (%d)", index);

	imageHeader->init(stream);
	delete stream;

	imageHeader->update(_entry);

	if (imageHeader->getField4() == 0)
		aquatorHeader->setField0(false);
	else
		aquatorHeader->setField0(true);

	aquatorHeader->shouldUpdateEntries(aquatorHeader->getChannel());
}

uint32 AquatorStream::getField0ByIndex(uint32 index) {
	return _headers[index]->getField0();
}

// 0x404310
void AquatorStream::updateEntries(float) {
	// Restore the node under disabled channels
	for (Common::Array<AquatorImageHeader *>::iterator it = _headers.begin(); it != _headers.end(); it++) {
		AquatorImageHeader *header = (*it);

		if (!header->getHeader()->hasEntries() || !header->shouldUpdateEntries() || header->getChannel())
			continue;

		_entry->decode(header->getHeader()->getCurrent());
		header->shouldUpdateEntries(0);
	}

	// Draw the current frame of enabled channels
	for (Common::Array<AquatorImageHeader *>::iterator it = _headers.begin(); it != _headers.end(); it++) {
		AquatorImageHeader *header = (*it);

		if (!header->getHeader()->hasEntries() || !header->shouldUpdateEntries() || !header->getChannel())
			continue;

		_entry->decode(header->getHeader()->get(header->getField8()));
		header->shouldUpdateEntries(0);
	}
}

void AquatorStream::sub_411530(uint32 index, uint32 a2) {
	if (_headers[index]->getField8() != a2) {
		_headers[index]->setField8(a2);
		_headers[index]->shouldUpdateEntries(_headers[index]->getChannel());
	}
}

void AquatorStream::setChannel(uint32 index, uint32 channel) {
	_headers[index]->setChannel(channel);
}

uint32 AquatorStream::getChannel(uint32 index) {
	return _headers[index]->getChannel();
}

} // End of namespace Ring
