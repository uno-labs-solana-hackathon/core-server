#include "RsResultDesc.hpp"

namespace Sol::Loyalty::API::RPC {

TYPE_STRUCT_IMPLEMENT(RsResultDesc, GP_MODULE_UUID)

RsResultDesc::RsResultDesc (void) noexcept
{
}

RsResultDesc::RsResultDesc
(
	const ResultCode::EnumT	aRes,
	std::string_view		aMsg
):
res(aRes),
msg(aMsg)
{
}

RsResultDesc::~RsResultDesc (void) noexcept
{
}

void	RsResultDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
	PROP(res);
	PROP(msg);
}

}//namespace Sol::Loyalty::API::RPC
