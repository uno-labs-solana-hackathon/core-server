#include "BuyTxDesc.hpp"

namespace Sol::Loyalty::DataModel  {

TYPE_STRUCT_IMPLEMENT(BuyTxDesc, GP_MODULE_UUID)

BuyTxDesc::BuyTxDesc (void) noexcept
{
}

BuyTxDesc::~BuyTxDesc (void) noexcept
{
}

void	BuyTxDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
	PROP(id);
	PROP(items);
	PROP(create_ts);
	PROP(client_id);
	PROP(total);
	PROP(earned);
	PROP(spend);
	PROP(spend_sign);
	PROP(spend_raw_tx);
	PROP(new_account_sign);
	PROP(new_account_raw_tx);
}

}//namespace Sol::Loyalty::DataModel
