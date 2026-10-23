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

#include "ring/base/timer.h"

#include "ring/base/application.h"
#include "ring/base/saveload.h"

#include "ring/ring.h"
#include "ring/helpers.h"


namespace Ring {

#pragma region Timer

Timer::Timer(TimerId timerId, uint32 elapseTime): BaseObject(timerId), _elapseTime(elapseTime) {
	_fired = 0;
	_tickStart = g_system->getMillis();

	start();
}

Timer::~Timer() {
}

void Timer::start() {
	_lastFire = g_system->getMillis();
}

// Serializable
void Timer::saveLoadWithSerializer(Common::Serializer &s) {
	s.syncAsUint32LE(_id);
	s.syncAsUint32LE(_tickStart);
	s.syncAsUint32LE(_fired);
	s.syncAsUint32LE(_elapseTime);
}

#pragma endregion

#pragma region TimerHandler

TimerHandler::TimerHandler() {
}

TimerHandler::~TimerHandler() {
	CLEAR_ARRAY(Timer, _timers);
}

void TimerHandler::start(TimerId id, uint32 elapseTime) {
	// The original (FAUST.EXE 0x48dc70) logs this and keeps the running timer
	if (_timers.has(id)) {
		warning("[TimerHandler::start] Timer with that id already exists (%d)", id);
		return;
	}

	_timers.push_back(new Timer(id, elapseTime));
}

void TimerHandler::stop(TimerId id) {
	// The original (FAUST.EXE 0x48de20) silently ignores unknown timers
	if (!_timers.has(id))
		return;

	_timers.remove(id);
}

void TimerHandler::addTicks(uint32 ticks) {
	for (uint32 i = 0; i < _timers.size(); i++)
		_timers[i]->addTicks(ticks);
}

void TimerHandler::stopAll() {
	CLEAR_ARRAY(Timer, _timers);
}

bool TimerHandler::has(TimerId id) {
	return _timers.has(id);
}

void TimerHandler::incrementFiredCount(TimerId id) {
	if (!_timers.has(id))
		return;

	_timers.get(id)->incrementFiredCount();
}

void TimerHandler::collectDue(uint32 now, Common::Array<TimerId> &due) {
	// Like WM_TIMER, a late timer fires once rather than catching up
	for (uint32 i = 0; i < _timers.size(); i++) {
		if (_timers[i]->isDue(now)) {
			_timers[i]->markFired(now);
			due.push_back((TimerId)_timers[i]->getId());
		}
	}
}

#pragma region Serializable

void TimerHandler::saveLoadWithSerializer(Common::Serializer &s) {
	// FIXME: Original checks if the timer should be started (but seems to always call with the value set to true)
	uint32 count = _timers.size();
	s.syncAsUint32LE(count);

	for (uint32 i = 0; i < count; i++) {
		if (s.isSaving()) {
			_timers[i]->saveLoadWithSerializer(s);
		}

		if (s.isLoading()) {
			Timer *timer = new Timer();
			timer->saveLoadWithSerializer(s);

			// Update start ticks
			timer->setTickStart(getApp()->getSaveManager()->getTicks() - timer->getTickStart());
			timer->start();

			_timers.push_back(timer);
		}
	}
}

#pragma endregion

#pragma endregion

} // End of namespace Ring
