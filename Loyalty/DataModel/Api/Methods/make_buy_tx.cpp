#include "make_buy_tx.hpp"

namespace Sol::Loyalty::API::RPC {

//----------------------------- RQ -----------------------------
TYPE_STRUCT_IMPLEMENT(MakeBuyTxRqData, GP_MODULE_UUID)

MakeBuyTxRqData::MakeBuyTxRqData (void) noexcept
{
}

MakeBuyTxRqData::MakeBuyTxRqData
(
	std::string_view	aClientId,
	const ItemsT&		aItems,
	const monetary_t	aSpend,
	const GpBytesArray&	aSpendSign,
	const GpBytesArray&	aSpendRawTx,
	const GpBytesArray&	aNewAccountSign,
	const GpBytesArray&	aNewAccountRawTx,
	const bool			aCommit
):
client_id(aClientId),
items(aItems),
spend(aSpend),
spend_sign(aSpendSign),
spend_raw_tx(aSpendRawTx),
new_account_sign(aNewAccountSign),
new_account_raw_tx(aNewAccountRawTx),
commit(aCommit)
{
}

MakeBuyTxRqData::~MakeBuyTxRqData (void) noexcept
{
}

void	MakeBuyTxRqData::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
	PROP(client_id);
	PROP(items);
	PROP(spend);
	PROP(spend_sign);
	PROP(spend_raw_tx);
	PROP(new_account_sign);
	PROP(new_account_raw_tx);
	PROP(commit);	
}

RQ_IMPL(make_buy_tx)

//----------------------------- RS -----------------------------
RS_IMPL(make_buy_tx)

}//namespace Sol::Loyalty::API::RPC
