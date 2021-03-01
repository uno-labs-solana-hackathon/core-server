#pragma once

#include "Api_global.hpp"

namespace Sol::Loyalty::API::RPC {

GP_ENUM(SOL_LOYALTY_DATA_MODEL_API_API, ResultCode,
	OK						= 0,
	FAILED					= 1,
	UNKNOWN_METHOD			= 2,
	INVALID_SID				= 3,
	DB_ENTITY_NOT_FOUND		= 4
);

}//namespace Sol::Loyalty::API::RPC
