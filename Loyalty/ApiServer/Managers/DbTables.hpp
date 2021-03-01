#pragma once

#include "../ApiServer_global.hpp"

namespace Sol::Loyalty::API::RPC {

namespace DbTables
{
	namespace sol
	{
		constexpr static std::string_view	clients					(void) noexcept {return "sol.clients"_sv;}
		constexpr static std::string_view	buy_txs					(void) noexcept {return "sol.buy_txs"_sv;}
	}
};

}//namespace Sol::Loyalty::API::RPC
