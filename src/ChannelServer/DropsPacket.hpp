/*
Copyright (C) 2008-2014 Vana Development Team

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#pragma once

#include "Types.hpp"

class Player;
class Drop;
class Pet;
struct Pos;

namespace DropsPacket {
	namespace DropTypes {
		enum DropTypes : int8_t {
			ShowDrop = 0,
			DropAnimation = 1,
			ShowExisting = 2,
			DisappearDuringDrop = 3
		};
	}
	auto showDrop(Player *player, Drop *drop, int8_t type, bool newDrop, const Pos &origin) -> void;
	auto takeDrop(Player *player, Drop *drop, int8_t petIndex = -1) -> void;
	auto dontTake(Player *player) -> void;
	auto removeDrop(Drop *drop) -> void;
	auto explodeDrop(Drop *drop) -> void;
	auto dropNotAvailableForPickup(Player *player) -> void;
	auto cantGetAnymoreItems(Player *player) -> void;
	auto pickupDrop(Player *player, int32_t id, int32_t amount, bool isMesos = false, int16_t cafeBonus = 0) -> void;
	auto pickupDropSpecial(Player *player, int32_t id) -> void;
}