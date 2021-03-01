#include "BalanceDesc.hpp"

namespace Sol::Loyalty::DataModel  {

TYPE_STRUCT_IMPLEMENT(BalanceDesc, GP_MODULE_UUID)

BalanceDesc::BalanceDesc (void) noexcept
{
}

BalanceDesc::~BalanceDesc (void) noexcept
{
}

void	BalanceDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
	PROP(total);
	PROP(unlocked);
	PROP(locked);
}

}//namespace Sol::Loyalty::DataModel
