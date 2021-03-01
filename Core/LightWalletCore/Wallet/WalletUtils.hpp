#pragma once

#include "Address.hpp"
#include "Wallet.hpp"
#include "Transaction.hpp"

namespace Sol::Core::LightWallet {

class SOL_CORE_LIGHT_WALLET_CORE_API WalletUtils
{
public:
	CLASS_REMOVE_CTRS(WalletUtils)

	static constexpr s_int_8		WALLET_FORMAT_VERSION			(void) noexcept {return 1;}

public:
	static GpSecureStorage			SNewMnemonic					(void);
	static bool						SValidateMnemonic				(GpRawPtrCharR aMnemonic);
	static GpSecureStorage			SSeedFromMnemonic				(GpRawPtrCharR aMnemonic,
																	 GpRawPtrCharR aPassword);
	static GpCryptoHDKeyStorage		SGenerateBip44					(GpRawPtrByteR aSeed);
	static GpCryptoKeyFactory::SP	SNewHDKeyFactory				(const GpCryptoHDKeyStorage& aBip44RootHD);
	static GpCryptoKeyFactory::SP	SNewHDKeyFactoryMnemonic		(GpRawPtrCharR aMnemonic, GpRawPtrCharR aPassword);
	static GpCryptoKeyFactory::SP	SNewRndKeyFactory				(void);
	static Address::SP				SNewAddrFromFactory				(GpCryptoKeyFactory& aFactory);
	static Address::SP				SNewAddrFromPrivateKey			(GpRawPtrByteR aPrivateKey);
	static Address::SP				SNewAddrFromPrivateKeyStrHex	(GpRawPtrCharR aPrivateKeyStrHex);

private:
	static const GpMnemonicCodeGen::WordListT	sWordListEN;
};

}//Sol::Core::LightWallet
