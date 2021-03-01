#include "ClientDesc.hpp"

namespace Sol::Loyalty::DataModel  {

TYPE_STRUCT_IMPLEMENT(ClientDesc, GP_MODULE_UUID)

ClientDesc::ClientDesc (void) noexcept
{
}

ClientDesc::~ClientDesc (void) noexcept
{
}

void	ClientDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
	PROP(id);
	PROP(create_ts);
	PROP(name);
	PROP(balance);
	PROP(is_on_chain);
}

}//namespace Sol::Loyalty::DataModel
