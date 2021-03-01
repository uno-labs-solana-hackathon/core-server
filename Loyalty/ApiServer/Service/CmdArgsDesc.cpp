#include "CmdArgsDesc.hpp"

namespace Sol::Loyalty::API::RPC {

TYPE_STRUCT_IMPLEMENT(CmdArgsDesc, GP_MODULE_UUID)

CmdArgsDesc::CmdArgsDesc (void) noexcept
{
}

CmdArgsDesc::~CmdArgsDesc (void) noexcept
{
}

void	CmdArgsDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& /*aPropsOut*/)
{
}

}//namespace Sol::Loyalty::API::RPC
