#include "BuyTxManagerApi.hpp"
#include "BuyTxManager.hpp"
#include "BuyTxManagerDB.hpp"
#include "ClientsManagerApi.hpp"
#include "../Exception/Exception.hpp"

namespace Sol::Loyalty::API::RPC {

BuyTxManagerApi::BuyTxDescT::SP	BuyTxManagerApi::SMakeBuyTx
(
	std::string_view			aBuyerAddrBase58,
	const BuyTxDescT::ItemsT&	aItems,
	const monetary_t			aSpend,
	const GpBytesArray&			aSpendSign,
	const GpBytesArray&			aSpendRawTx,
	const GpBytesArray&			aNewAccountSign,
	const GpBytesArray&			aNewAccountRawTx,
	const bool					aIsCommit
)
{
	if (aBuyerAddrBase58.length() > 0)
	{
		ClientsManagerApi::SFindClient(aBuyerAddrBase58, true);
	}

	BuyTxDescT::SP buyTxDescSP = BuyTxManager::SCreateBuyTx
	(
		aBuyerAddrBase58,
		aItems,
		BuyTxManager::SCalcEarns(aSpend, aBuyerAddrBase58, aItems),
		aSpend,
		aSpendSign,
		aSpendRawTx,
		aNewAccountSign,
		aNewAccountRawTx,
		aIsCommit
	);

	if (aIsCommit)
	{
		GpDbConnectionGuard	dbConnGuard;
		GpDbConnection&		dbConn = dbConnGuard.Connection();

		BuyTxManagerDB::SInsert(buyTxDescSP.Vn(), dbConn);
	}

	return buyTxDescSP;
}

}//namespace Sol::Loyalty::API::RPC
