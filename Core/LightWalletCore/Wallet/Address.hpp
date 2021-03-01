#pragma once

#include "../LightWalletCore_global.hpp"

namespace Sol::Core::LightWallet {

class SOL_CORE_LIGHT_WALLET_CORE_API Address
{
public:
	CLASS_DECLARE_DEFAULTS(Address)

	using KeyPairT	= GpCryptoKeyPair_Ed25519;

public:
							Address			(void);
							Address			(const Address& aAddress);
							Address			(Address&& aAddress);
							Address			(const KeyPairT& aKeyPair);
							Address			(KeyPairT&& aKeyPair);
	virtual					~Address		(void) noexcept;

	Address&				operator=		(const Address& aAddress);
	Address&				operator=		(Address&& aAddress);

	const KeyPairT&			KeyPair			(void) const noexcept {return iKeyPair;}
	std::string_view		Name			(void) const noexcept {return iName;}
	GpBytesArray			SignData		(GpRawPtrByteR aData) const;

private:
	void					RecalcAddress	(void);

private:
	KeyPairT				iKeyPair;
	std::string				iName;
};

}//namespace Sol::Core::LightWallet
