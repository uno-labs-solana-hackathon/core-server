#include "BuyTxManager.hpp"
#include "ClientsManagerApi.hpp"
#include "ClientsManagerDB.hpp"

namespace Sol::Loyalty::API::RPC {

//TODO: move to secure storage
static const GpArray<u_int_8, 32>	sPrivateKeyStore	= {12,105,194,80,78,228,241,238,31,105,219,69,228,23,193,143,87,80,30,179,60,99,54,88,5,126,134,185,180,165,176,247};
static const GpArray<u_int_8, 32>	sPrivateKeyProgram	= {25,250,30,109,229,24,183,141,170,235,127,24,242,14,143,231,231,70,122,228,4,64,94,14,125,134,199,140,182,215,89,59};

BuyTxManager::BuyTxDescT::SP	BuyTxManager::SCreateBuyTx
(
	std::string_view			aBuyerAddrBase58,
	const BuyTxDescT::ItemsT&	aItems,
	const monetary_t			aEarned,
	const monetary_t			aSpend,
	const GpBytesArray&			aSpendSign,
	const GpBytesArray&			aSpendRawTx,
	const GpBytesArray&			aNewAccountSign,
	const GpBytesArray&			aNewAccountRawTx,
	const bool					aIsCommit
)
{
	BuyTxDescT::SP buyTxDescSP = MakeSP<BuyTxDescT>();

	{
		BuyTxDescT& buyTxDesc = buyTxDescSP.V();

		buyTxDesc.id					= GpUUID::SGenRandom();
		buyTxDesc.items					= aItems;
		buyTxDesc.create_ts				= GpDateTimeOps::SUnixTS_s();
		buyTxDesc.client_id				= aBuyerAddrBase58;
		buyTxDesc.total					= 0_monetary;
		buyTxDesc.earned				= aEarned;
		buyTxDesc.spend					= aSpend;
		buyTxDesc.spend_sign			= aSpendSign;
		buyTxDesc.spend_raw_tx			= SCalcSpendRawTx(aSpendRawTx, aBuyerAddrBase58, buyTxDesc.spend, aIsCommit);
		buyTxDesc.new_account_sign		= aNewAccountSign;
		buyTxDesc.new_account_raw_tx	= SCalcSNewAccountRawTx(aNewAccountRawTx, aBuyerAddrBase58, aIsCommit, aNewAccountSign.size() > 0);

		//
		buyTxDesc.total	= SCalcTotal(buyTxDesc);

		SNewAccountMakeTx(aBuyerAddrBase58, aNewAccountRawTx, aIsCommit, aNewAccountSign);
		SApplyBalanceChange(buyTxDesc, aIsCommit);
	}

	return buyTxDescSP;
}

monetary_t	BuyTxManager::SCalcEarns
(
	const monetary_t			aSpend,
	std::string_view			aBuyerAddrBase58,
	const BuyTxDescT::ItemsT&	aItems
)
{
	monetary_t earns = 0_monetary;

	if (   (aBuyerAddrBase58.length() == 0)
		|| (aSpend > 0_monetary))
	{
		return earns;
	}

	for (const auto& itemSP: aItems)
	{
		const auto& item	= itemSP.VC();
		const auto	price	= item.price;
		const auto	qty		= item.qty.As<monetary_t>();

		earns += (price * qty) / 20_monetary;
	}

	return earns;
}

monetary_t	BuyTxManager::SCalcTotal (const BuyTxDescT& aBuyTxDesc)
{
	monetary_t total = 0_monetary;

	for (const auto& itemSP: aBuyTxDesc.items)
	{
		const auto& item	= itemSP.VC();
		const auto	price	= item.price;
		const auto	qty		= item.qty.As<monetary_t>();

		total += price * qty;
	}

	return total;
}

GpBytesArray	BuyTxManager::SCalcSNewAccountRawTx
(
	const GpBytesArray&	aNewAccountRawTx,
	std::string_view	aBuyerAddrBase58,
	const bool			aIsCommit,
	const bool			aIsSignReady
)
{
	if (aNewAccountRawTx.size() > 0)
	{
		return aNewAccountRawTx;
	}

	if (   (aIsCommit == false)
		&& (aIsSignReady == false))
	{
		Sol::Loyalty::DataModel::ClientDesc::SP clientDescSP = ClientsManagerApi::SFindClient(aBuyerAddrBase58, true);

		if (clientDescSP->is_on_chain == false)
		{
			Sol::Loyalty::SolanaGateway::Loyalty2Solana loyalty2Solana("https://testnet.solana.com"_sv);

			Sol::Core::LightWallet::Address::SP	addressStore	= Sol::Core::LightWallet::WalletUtils::SNewAddrFromPrivateKey(sPrivateKeyStore);
			Sol::Core::LightWallet::Address::SP	addressProgram	= Sol::Core::LightWallet::WalletUtils::SNewAddrFromPrivateKey(sPrivateKeyProgram);
			const GpBytesArray					buyerAddess		= GpBase58::SDecodeToByteArray(aBuyerAddrBase58, GpBase58Alphabet::NAKAMOTO);

			return loyalty2Solana.NewAccountPrepareTx
			(
				addressStore->KeyPair().PublicBytes(),
				buyerAddess,
				addressProgram->KeyPair().PublicBytes()
			);
		}
	}

	return GpBytesArray();
}

void	BuyTxManager::SNewAccountMakeTx
(
	std::string_view	aBuyerAddrBase58,
	const GpBytesArray&	aNewAccountRawTx,
	const bool			aIsCommit,
	const GpBytesArray&	aNewAccountSign
)
{
	if (aNewAccountRawTx.size() == 0)
	{
		return;
	}

	if (   (aIsCommit == true)
		&& (aNewAccountSign.size() > 0))
	{
		Sol::Loyalty::DataModel::ClientDesc::SP clientDescSP = ClientsManagerApi::SFindClient(aBuyerAddrBase58, true);

		if (clientDescSP->is_on_chain == false)
		{
			Sol::Loyalty::SolanaGateway::Loyalty2Solana loyalty2Solana("https://testnet.solana.com"_sv);

			Sol::Core::LightWallet::Address::SP	addressStore = Sol::Core::LightWallet::WalletUtils::SNewAddrFromPrivateKey(sPrivateKeyStore);

			loyalty2Solana.NewAccountMakeTx
			(
				aNewAccountRawTx,
				addressStore.VC(),
				aNewAccountSign
			);

			//
			ClientsManagerApi::SSetOnChain(aBuyerAddrBase58);
		}
	}
}

GpBytesArray	BuyTxManager::SCalcSpendRawTx
(
	const GpBytesArray&	aSpendRawTx,
	std::string_view	aBuyerAddrBase58,
	const monetary_t	aSpend,
	const bool			aIsCommit
)
{
	if (aSpendRawTx.size() > 0)
	{
		return aSpendRawTx;
	}

	if (   (aIsCommit == false)
		&& (aSpend > 0_monetary))
	{
		Sol::Loyalty::DataModel::ClientDesc::SP clientDescSP = ClientsManagerApi::SFindClient(aBuyerAddrBase58, true);

		if (clientDescSP->is_on_chain == false)
		{
			return GpBytesArray();
		}

		Sol::Loyalty::SolanaGateway::Loyalty2Solana loyalty2Solana("https://testnet.solana.com"_sv);

		Sol::Core::LightWallet::Address::SP	addressStore	= Sol::Core::LightWallet::WalletUtils::SNewAddrFromPrivateKey(sPrivateKeyStore);
		Sol::Core::LightWallet::Address::SP	addressProgram	= Sol::Core::LightWallet::WalletUtils::SNewAddrFromPrivateKey(sPrivateKeyProgram);
		const GpBytesArray					buyerAddess		= GpBase58::SDecodeToByteArray(aBuyerAddrBase58, GpBase58Alphabet::NAKAMOTO);

		return loyalty2Solana.SpendPrepareTx
		(
			addressStore->KeyPair().PublicBytes(),
			buyerAddess,
			addressProgram->KeyPair().PublicBytes(),
			aSpend
		);
	}

	return GpBytesArray();
}

void	BuyTxManager::SMakeSpendTx
(
	std::string_view	aBuyerAddrBase58,
	const GpBytesArray&	aSpendRawTx,
	const bool			aIsCommit,
	const GpBytesArray&	aSpendSign
)
{
	if (aSpendRawTx.size() == 0)
	{
		return;
	}

	if (   (aIsCommit == true)
		&& (aSpendSign.size() > 0))
	{
		Sol::Loyalty::DataModel::ClientDesc::SP clientDescSP = ClientsManagerApi::SFindClient(aBuyerAddrBase58, true);

		if (clientDescSP->is_on_chain == false)
		{
			return;
		}

		Sol::Loyalty::SolanaGateway::Loyalty2Solana loyalty2Solana("https://testnet.solana.com"_sv);

		Sol::Core::LightWallet::Address::SP	addressStore = Sol::Core::LightWallet::WalletUtils::SNewAddrFromPrivateKey(sPrivateKeyStore);

		loyalty2Solana.SpendMakeTx
		(
			aSpendRawTx,
			addressStore.VC(),
			aSpendSign
		);
	}
}

void	BuyTxManager::SApplyBalanceChange
(
	const BuyTxDescT	aBuyTxDesc,
	const bool			aIsCommit
)
{
	if (   (aIsCommit == false)
		|| (aBuyTxDesc.client_id.length() == 0))
	{
		return;
	}

	GpDbConnectionGuard	dbConnGuard;
	GpDbConnection&		dbConn = dbConnGuard.Connection();

	auto[client, version] = ClientsManagerDB::SSelectById(aBuyTxDesc.client_id, dbConn);

	client->balance.total += aBuyTxDesc.earned;
	client->balance.total -= aBuyTxDesc.spend;

	if (client->balance.total < 0_monetary)
	{
		THROW_GPE("Balance is out of range"_sv);
	}

	ClientsManagerDB::SUpdate(client.VC(), version, dbConn);

	if (aBuyTxDesc.new_account_sign.size() == 0)
	{
		if (aBuyTxDesc.earned > 0_monetary)
		{
			Sol::Loyalty::SolanaGateway::Loyalty2Solana loyalty2Solana("https://testnet.solana.com"_sv);

			Sol::Core::LightWallet::Address::SP	addressStore	= Sol::Core::LightWallet::WalletUtils::SNewAddrFromPrivateKey(sPrivateKeyStore);
			Sol::Core::LightWallet::Address::SP	addressProgram	= Sol::Core::LightWallet::WalletUtils::SNewAddrFromPrivateKey(sPrivateKeyProgram);
			const GpBytesArray					buyerAddess		= GpBase58::SDecodeToByteArray(aBuyTxDesc.client_id, GpBase58Alphabet::NAKAMOTO);

			loyalty2Solana.EmitMakeTx
			(
				addressStore.VC(),
				buyerAddess,
				addressProgram->KeyPair().PublicBytes(),
				aBuyTxDesc.earned
			);
		} else if (aBuyTxDesc.spend > 0_monetary)
		{
			SMakeSpendTx
			(
				aBuyTxDesc.client_id,
				aBuyTxDesc.spend_raw_tx,
				aIsCommit,
				aBuyTxDesc.spend_sign
			);
		}
	}
}

}//namespace Sol::Loyalty::API::RPC
