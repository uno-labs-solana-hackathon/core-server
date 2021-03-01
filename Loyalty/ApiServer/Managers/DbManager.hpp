#pragma once

#include "../Exception/Exception.hpp"
#include "DbTables.hpp"

namespace Sol::Loyalty::API::RPC {

class DbManager
{
	CLASS_REMOVE_CTRS(DbManager);

public:
	[[noreturn]] static void SThrowOnNoResult (void)
	{
		THROW_SOL_EX(ResultCode::DB_ENTITY_NOT_FOUND, ""_sv);
	}
};

}//namespace Sol::Loyalty::API::RPC
