#pragma once

#include "SolanaGateway_global.hpp"

namespace Sol::Loyalty::SolanaGateway {

class SOL_LOYALTY_SOLANA_GATEWAY_API Loyalty2Solana
{
	CLASS_REMOVE_CTRS(Loyalty2Solana);

public:
								Loyalty2Solana				(std::string_view aSolanaRpcEndpoint);
	virtual						~Loyalty2Solana				(void) noexcept;

	GpBytesArray				NewAccountPrepareTx			(GpRawPtrByteR aStorePublicKey,
															 GpRawPtrByteR aBuyerPublicKey,
															 GpRawPtrByteR aProgramPublicKey);
	std::string					NewAccountMakeTx			(GpRawPtrByteR							aSerializedTransaction,
															 const Sol::Core::LightWallet::Address&	aStoreAddress,
															 GpRawPtrByteR							aBuyerSign);

	std::string					EmitMakeTx					(const Sol::Core::LightWallet::Address&	aStoreAddress,
															 GpRawPtrByteR							aBuyerPublicKey,
															 GpRawPtrByteR							aProgramPublicKey,
															 const monetary_t						aAmountEarn);

	GpBytesArray				SpendPrepareTx				(GpRawPtrByteR		aStorePublicKey,
															 GpRawPtrByteR		aBuyerPublicKey,
															 GpRawPtrByteR		aProgramPublicKey,
															 const monetary_t	aAmountSpend);

	std::string					SpendMakeTx					(GpRawPtrByteR							aSerializedTransaction,
															 const Sol::Core::LightWallet::Address&	aStoreAddress,
															 GpRawPtrByteR							aBuyerSign);

private:
	GpBytesArray				SerializeTxNoSig			(const Sol::Core::LightWallet::Transaction&	aTx);
	GpBytesArray				SerializeTx					(const Sol::Core::LightWallet::Transaction&	aTx);

	std::string					SendTx						(const GpBytesArray& aSerializedTransactionData);

	GpBytesArray				RecentBlockhash				(void);

private:
	const std::string			iSolanaRpcEndpoint;
};

}//namespace Sol::Loyalty::SolanaGateway
