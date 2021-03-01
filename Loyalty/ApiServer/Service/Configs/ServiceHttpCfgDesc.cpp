#include "ServiceHttpCfgDesc.hpp"

namespace Sol::Loyalty::API::RPC {

TYPE_STRUCT_IMPLEMENT(ServiceHttpCfgDesc, GP_MODULE_UUID)

ServiceHttpCfgDesc::ServiceHttpCfgDesc (void) noexcept
{
}

ServiceHttpCfgDesc::~ServiceHttpCfgDesc (void) noexcept
{
}

void	ServiceHttpCfgDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
	PROP(listen_ip);
	PROP(listen_port);
	PROP(cli_init_count);
	PROP(cli_max_count);
}

}//namespace Sol::Loyalty::API::RPC
