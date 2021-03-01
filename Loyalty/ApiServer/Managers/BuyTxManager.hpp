#pragma once

#include "../ApiServer_global.hpp"

namespace Sol::Loyalty::API::RPC {

class BuyTxManager
{
public:
	CLASS_REMOVE_CTRS(BuyTxManager);

	using BuyTxDescT = Sol::Loyalty::DataModel::BuyTxDesc;

public:
	static BuyTxDescT::SP				SCreateBuyTx			(std::string_view			aBuyerAddrBase58,
																 const BuyTxDescT::ItemsT&	aItems,
																 const monetary_t			aEarned,
																 const monetary_t			aSpend,
																 const GpBytesArray&		aSpendSign,
																 const GpBytesArray&		aSpendRawTx,
																 const GpBytesArray&		aNewAccountSign,
																 const GpBytesArray&		aNewAccountRawTx,
																 const bool					aIsCommit);

	static monetary_t					SCalcEarns				(const monetary_t			aSpend,
																 std::string_view			aBuyerAddrBase58,
																 const BuyTxDescT::ItemsT&	aItems);

	static monetary_t					SCalcTotal				(const BuyTxDescT& aBuyTxDesc);

	static GpBytesArray					SCalcSNewAccountRawTx	(const GpBytesArray&	aNewAccountRawTx,
																 std::string_view		aBuyerAddrBase58,
																 const bool				aIsCommit,
																 const bool				aIsSignReady);

	static void							SNewAccountMakeTx		(std::string_view		aBuyerAddrBase58,
																 const GpBytesArray&	aNewAccountRawTx,
																 const bool				aIsCommit,
																 const GpBytesArray&	aNewAccountSign);

	static GpBytesArray					SCalcSpendRawTx			(const GpBytesArray&	aSpendRawTx,
																 std::string_view		aBuyerAddrBase58,
																 const monetary_t		aSpend,
																 const bool				aIsCommit);
	static void							SMakeSpendTx			(std::string_view		aBuyerAddrBase58,
																 const GpBytesArray&	aSpendRawTx,
																 const bool				aIsCommit,
																 const GpBytesArray&	aSpendSign);

	static void							SApplyBalanceChange		(const BuyTxDescT	aBuyTxDesc,
																 const bool			aIsCommit);

};

}//namespace Sol::Loyalty::API::RPC
