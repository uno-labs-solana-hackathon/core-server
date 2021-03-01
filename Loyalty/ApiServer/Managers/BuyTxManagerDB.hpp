#pragma once

#include "../ApiServer_global.hpp"

namespace Sol::Loyalty::API::RPC {

class BuyTxManagerDB
{
public:
	CLASS_REMOVE_CTRS(BuyTxManagerDB);

	using BuyTxDescT	= Sol::Loyalty::DataModel::BuyTxDesc;
	using SelectResT	= std::tuple<BuyTxDescT::SP, SInt64/*version*/>;

public:
	static SelectResT				SSelectById			(const GpUUID&		aBuyTxId,
														 GpDbConnection&	aDbConn);
	static void						SInsert				(const BuyTxDescT&	aBuyTxDesc,
														 GpDbConnection&	aDbConn);
};

}//namespace Sol::Loyalty::API::RPC
