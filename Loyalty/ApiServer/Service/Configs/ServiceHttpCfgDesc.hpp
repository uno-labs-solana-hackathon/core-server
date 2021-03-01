#pragma once

#include "../../ApiServer_global.hpp"

namespace Sol::Loyalty::API::RPC {

class ServiceHttpCfgDesc final: public GpServiceCfgBaseDesc
{
public:
	CLASS_DECLARE_DEFAULTS(ServiceHttpCfgDesc)
	TYPE_STRUCT_DECLARE("0860d877-3be7-48bf-92fb-3038fb53f87f"_sv)

public:
						ServiceHttpCfgDesc		(void) noexcept;
	virtual				~ServiceHttpCfgDesc		(void) noexcept override final;

public:
	std::string			listen_ip		= "127.0.0.1";
	u_int_16			listen_port		= 8080;
	count_t				cli_init_count;
	count_t				cli_max_count;
};

}//namespace Sol::Loyalty::API::RPC
