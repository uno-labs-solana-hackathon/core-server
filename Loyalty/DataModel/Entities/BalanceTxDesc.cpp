#include "BalanceTxDesc.hpp"

namespace Sol::Loyalty::DataModel  {

TYPE_STRUCT_IMPLEMENT(BalanceTxDesc, GP_MODULE_UUID)

BalanceTxDesc::BalanceTxDesc (void) noexcept
{
}

BalanceTxDesc::~BalanceTxDesc (void) noexcept
{
}

void	BalanceTxDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
	PROP(id);
	PROP(buy_tx_id);
	PROP(balance_id);
	PROP(balance_delta);
	PROP(create_ts);
}

}//namespace Sol::Loyalty::DataModel
