#include "ApiRqBaseDesc.hpp"

namespace Sol::Core::API::RPC {

TYPE_STRUCT_IMPLEMENT(ApiRqBaseDesc, GP_MODULE_UUID)

ApiRqBaseDesc::ApiRqBaseDesc (void) noexcept
{
}

ApiRqBaseDesc::~ApiRqBaseDesc (void) noexcept
{
}

std::string_view	ApiRqBaseDesc::Method (void) const
{
	return method;
}

void	ApiRqBaseDesc::SetMethod (std::string_view aMethod)
{
	method = aMethod;
}

void	ApiRqBaseDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
	PROP(jsonrpc);
	PROP(id);
	PROP(method);
}

}//namespace Sol::Core::API::RPC
