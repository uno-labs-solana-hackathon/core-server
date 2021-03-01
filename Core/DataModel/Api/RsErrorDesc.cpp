#include "RsErrorDesc.hpp"

namespace Sol::Core::API::RPC {

TYPE_STRUCT_IMPLEMENT(RsErrorDesc, GP_MODULE_UUID)

RsErrorDesc::RsErrorDesc (void) noexcept
{
}

RsErrorDesc::~RsErrorDesc (void) noexcept
{
}

void	RsErrorDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
	PROP(code);
	PROP(message);
}

}//namespace Sol::Core::API::RPC
