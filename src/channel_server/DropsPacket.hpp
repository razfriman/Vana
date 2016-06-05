/*
Copyright (C) 2008-2016 Vana Development Team

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

#include "common/packet_builder.hpp"
#include "common/types_temp.hpp"

namespace vana {
	struct point;

	namespace channel_server {
		class drop;
		class pet;
		class player;

		namespace packets {
			namespace drops {
				namespace drop_types {
					enum drop_types : int8_t {
						show_drop = 0,
						drop_animation = 1,
						show_existing = 2,
						disappear_during_drop = 3
					};
				}

				PACKET(show_drop, drop *drop, int8_t type, const point &origin);
				PACKET(take_drop, game_player_id player_id, game_map_object drop_id, int8_t pet_index = -1);
				PACKET(dont_take);
				PACKET(remove_drop, game_map_object drop_id);
				PACKET(explode_drop, game_map_object drop_id);
				PACKET(drop_not_available_for_pickup);
				PACKET(cant_get_anymore_items);
				PACKET(pickup_drop, game_map_object id, int32_t amount, bool is_mesos = false, int16_t cafe_bonus = 0);
				PACKET(pickup_drop_special, game_map_object id);
			}
		}
	}
}