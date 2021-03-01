#pragma once

#include "ResultCode.hpp"

namespace Sol::Loyalty::API::RPC {

class SOL_LOYALTY_DATA_MODEL_API_API RsResultDesc: public GpApiResultDesc
{
public:
	CLASS_DECLARE_DEFAULTS(RsResultDesc)
	TYPE_STRUCT_DECLARE("636f424a-4af6-48df-a0fe-1ea09a7b94e0"_sv)

public:
						RsResultDesc	(void) noexcept;
						RsResultDesc	(const ResultCode::EnumT	aRes,
										 std::string_view			aMsg);
	virtual				~RsResultDesc	(void) noexcept override;

public:
	ResultCode			res;
	std::string			msg;
};

}//namespace Sol::Loyalty::API::RPC
