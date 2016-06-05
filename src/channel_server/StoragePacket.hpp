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
	namespace channel_server {
		class player;

		namespace packets {
			namespace storage {
				PACKET(show_storage, ref_ptr<player> player, game_npc_id npc_id);
				PACKET(add_item, ref_ptr<player> player, game_inventory inv);
				PACKET(take_item, ref_ptr<player> player, game_inventory inv);
				PACKET(change_mesos, game_storage_slot slot_count, game_mesos mesos);
				PACKET(storage_full);
				PACKET(no_mesos);
			}
		}
	}
}