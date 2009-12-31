/*
Copyright (C) 2008-2010 Vana Development Team

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
#include "WorldServerConnectPacket.h"
#include "InterHeader.h"
#include "SendHeader.h"
#include "MapleSession.h"
#include "PacketCreator.h"
#include "Player.h"
#include "WorldServerConnection.h"

void WorldServerConnectPacket::groupChat(WorldServerConnection *player, int8_t type, int32_t playerid, const vector<int32_t> &receivers, const string &chat) {
	PacketCreator packet;
	packet.add<int16_t>(IMSG_GROUP_CHAT);
	packet.add<int32_t>(playerid);
	packet.add<int8_t>(type);
	packet.addString(chat);
	packet.add<int8_t>(receivers.size());
	for (size_t i = 0; i < receivers.size(); i++) {
		packet.add<int32_t>(receivers[i]);
	}

	player->getSession()->send(packet);
}

void WorldServerConnectPacket::findPlayer(WorldServerConnection *player, int32_t playerid, const string &findee_name) {
	PacketCreator packet;
	packet.add<int16_t>(IMSG_FIND);
	packet.add<int32_t>(playerid);
	packet.addString(findee_name);
	player->getSession()->send(packet);
}

void WorldServerConnectPacket::whisperPlayer(WorldServerConnection *player, int32_t playerid, const string &whisperee, const string &message) {
	PacketCreator packet;
	packet.add<int16_t>(IMSG_WHISPER);
	packet.add<int32_t>(playerid);
	packet.addString(whisperee);
	packet.addString(message);
	player->getSession()->send(packet);
}

void WorldServerConnectPacket::scrollingHeader(WorldServerConnection *player, const string &message) {
	PacketCreator packet;
	packet.add<int16_t>(IMSG_SCROLLING_HEADER);
	packet.addString(message);
	player->getSession()->send(packet);
}

void WorldServerConnectPacket::rankingCalculation(WorldServerConnection *player) {
	PacketCreator packet;
	packet.add<int16_t>(IMSG_TO_LOGIN);
	packet.add<int16_t>(IMSG_CALCULATE_RANKING);
	player->getSession()->send(packet);
}

void WorldServerConnectPacket::toChannels(WorldServerConnection *player, PacketCreator &packet) {
	PacketCreator pack;
	pack.add<int16_t>(IMSG_TO_CHANNELS);
	pack.addBuffer(packet);
	player->getSession()->send(pack);
}

void WorldServerConnectPacket::toWorlds(WorldServerConnection *player, PacketCreator &packet) {
	PacketCreator pack;
	pack.add<int16_t>(IMSG_TO_WORLDS);
	pack.addBuffer(packet);
	player->getSession()->send(pack);
}

void WorldServerConnectPacket::worldMessage(WorldServerConnection *player, const string &message, int8_t type) {
	PacketCreator packet;
	packet.add<int16_t>(IMSG_TO_CHANNELS);
	packet.add<int16_t>(IMSG_TO_PLAYERS);
	packet.add<int16_t>(SMSG_MESSAGE); 
	packet.add<int8_t>(type);
	packet.addString(message);
	if (type == 6)
		packet.add<int32_t>(0);
	player->getSession()->send(packet);
}

void WorldServerConnectPacket::globalMessage(WorldServerConnection *player, const string &message, int8_t type) {
	PacketCreator packet;
	packet.add<int16_t>(IMSG_TO_LOGIN);
	packet.add<int16_t>(IMSG_TO_WORLDS);
	packet.add<int16_t>(IMSG_TO_CHANNELS);
	packet.add<int16_t>(IMSG_TO_PLAYERS);
	packet.add<int16_t>(SMSG_MESSAGE); 
	packet.add<int8_t>(type);
	packet.addString(message);
	if (type == 6)
		packet.add<int32_t>(0);
	
	player->getSession()->send(packet);
}

void WorldServerConnectPacket::reloadMcdb(WorldServerConnection *player, const string &type) {
	PacketCreator packet;
	packet.add<int16_t>(IMSG_REFRESH_DATA);
	packet.addString(type);
	toChannels(player, packet);
}