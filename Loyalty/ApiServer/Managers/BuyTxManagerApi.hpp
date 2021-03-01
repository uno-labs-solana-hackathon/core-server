#pragma once

#include "../ApiServer_global.hpp"

namespace Sol::Loyalty::API::RPC {

class BuyTxManagerApi
{
public:
	CLASS_REMOVE_CTRS(BuyTxManagerApi);

	using BuyTxDescT = Sol::Loyalty::DataModel::BuyTxDesc;

public:
	static BuyTxDescT::SP				SMakeBuyTx		(std::string_view			aBuyerAddrBase58,
														 const BuyTxDescT::ItemsT&	aItems,
														 const monetary_t			aSpend,
														 const GpBytesArray&		aSpendSign,
														 const GpBytesArray&		aSpendRawTx,
														 const GpBytesArray&		aNewAccountSign,
														 const GpBytesArray&		aNewAccountRawTx,
														 const bool					aIsCommit);
};

}//namespace Sol::Loyalty::API::RPC
