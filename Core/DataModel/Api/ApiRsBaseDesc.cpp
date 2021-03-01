#include "ApiRsBaseDesc.hpp"

namespace Sol::Core::API::RPC {

TYPE_STRUCT_IMPLEMENT(ApiRsBaseDesc, GP_MODULE_UUID)

ApiRsBaseDesc::ApiRsBaseDesc (void) noexcept
{
}

ApiRsBaseDesc::~ApiRsBaseDesc (void) noexcept
{
}

GpApiResultDesc::SP	ApiRsBaseDesc::Result (void)
{
	return error;
}

void	ApiRsBaseDesc::SetResult (GpApiResultDesc::SP aResult)
{
	error = std::move(aResult);
}

void	ApiRsBaseDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
	PROP(jsonrpc);
	PROP(id);
	PROP(error);
}

}//namespace Sol::Core::API::RPC
