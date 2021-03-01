#pragma once

#include "../Api_global.hpp"

namespace Sol::Loyalty::API::RPC {

//----------------------------- RQ -----------------------------
class SOL_LOYALTY_DATA_MODEL_API_API MakeBuyTxRqData final: public GpTypeStructBase
{
public:
	CLASS_DECLARE_DEFAULTS(MakeBuyTxRqData)
	TYPE_STRUCT_DECLARE("bc89b9c6-fd59-47f3-8933-13319a45eaa0"_sv)

	using ItemsT = Sol::Loyalty::DataModel::BuyTxItemDesc::C::Vec::SP;

public:
						MakeBuyTxRqData		(void) noexcept;
						MakeBuyTxRqData		(std::string_view		aClientId,
											 const ItemsT&			aItems,
											 const monetary_t		aSpend,
											 const GpBytesArray&	aSpendSign,
											 const GpBytesArray&	aSpendRawTx,
											 const GpBytesArray&	aNewAccountSign,
											 const GpBytesArray&	aNewAccountRawTx,
											 const bool				aCommit);
	virtual				~MakeBuyTxRqData	(void) noexcept override final;

public:
	std::string			client_id;
	ItemsT				items;
	monetary_t			spend	= 0_monetary;
	GpBytesArray		spend_sign;
	GpBytesArray		spend_raw_tx;
	GpBytesArray		new_account_sign;
	GpBytesArray		new_account_raw_tx;
	bool				commit	= false;
};

using make_buy_tx_rq_data = MakeBuyTxRqData::SP;

RQ(SOL_LOYALTY_DATA_MODEL_API_API, make_buy_tx, "1e9963b0-2c36-403a-8e94-d40d4a501969"_sv)

//----------------------------- RS -----------------------------
using make_buy_tx_rs_data = Sol::Loyalty::DataModel::BuyTxDesc::SP;

RS(SOL_LOYALTY_DATA_MODEL_API_API, make_buy_tx, "0c0ef560-3650-42d6-9ae3-c97af0bd419d"_sv)

}//namespace Sol::Loyalty::API::RPC
