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

#include "AbstractServer.hpp"
#include "ConfigFile.hpp"
#include "Configuration.hpp"
#include "Ip.hpp"
#include "LoginServerConnection.hpp"
#include "Types.hpp"
#include "WorldServerAcceptConnection.hpp"
#include <string>

class PacketCreator;

class WorldServer final : public AbstractServer {
	SINGLETON_CUSTOM_CONSTRUCTOR(WorldServer);
public:
	auto shutdown() -> void override;
	auto establishedLoginConnection(int8_t worldId, port_t port, const WorldConfig &conf) -> void;
	auto rehashConfig(const WorldConfig &config) -> void;
	auto setScrollingHeader(const string_t &message) -> void;
	auto setRates(const Rates &rates) -> void;
	auto resetRates() -> void;
	auto isConnected() const -> bool;
	auto getWorldId() const -> int8_t;
	auto makeChannelPort(uint16_t channelId) const -> port_t; 
	auto getConfig() -> const WorldConfig &;
	auto sendPacketToLogin(const PacketCreator &packet) -> void;
protected:
	auto listen() -> void override;
	auto loadData() -> void override;
	auto makeLogIdentifier() const -> opt_string_t override;
	auto getLogPrefix() const -> string_t override;
private:
	int8_t m_worldId = -1;
	port_t m_port = 0;
	WorldConfig m_config;
	Rates m_defaultRates;
	LoginServerConnection *m_loginConnection = nullptr;
};