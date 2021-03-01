#pragma once

#include "Api_global.hpp"

namespace Sol::Core::API::RPC {

class SOL_CORE_DATA_MODEL_API_API RsErrorDesc final: public GpApiResultDesc
{
public:
	CLASS_DECLARE_DEFAULTS(RsErrorDesc)
	TYPE_STRUCT_DECLARE("1be528ce-e69d-4f21-90e8-f9d4dbab8a3d"_sv)

public:
						RsErrorDesc		(void) noexcept;
	virtual				~RsErrorDesc	(void) noexcept override final;

public:
	s_int_64			code	= 0;
	std::string			message;
};

}//namespace Sol::Core::API::RPC
