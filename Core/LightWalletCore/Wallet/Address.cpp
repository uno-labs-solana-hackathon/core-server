#include "Address.hpp"

namespace Sol::Core::LightWallet {

Address::Address (void)
{
}

Address::Address (const Address& aAddress):
iKeyPair(aAddress.iKeyPair),
iName(aAddress.iName)
{
}

Address::Address (Address&& aAddress):
iKeyPair(std::move(aAddress.iKeyPair)),
iName(std::move(aAddress.iName))
{
}

Address::Address (const KeyPairT& aKeyPair):
iKeyPair(aKeyPair)
{
	RecalcAddress();
}

Address::Address (KeyPairT&& aKeyPair):
iKeyPair(std::move(aKeyPair))
{
	RecalcAddress();
}

Address::~Address (void) noexcept
{
	iKeyPair.Clear();
}

Address&	Address::operator= (const Address& aAddress)
{
	iKeyPair	= aAddress.iKeyPair;
	iName		= aAddress.iName;

	return *this;
}

Address&	Address::operator= (Address&& aAddress)
{
	iKeyPair	= std::move(aAddress.iKeyPair);
	iName		= std::move(aAddress.iName);

	return *this;
}

GpBytesArray	Address::SignData (GpRawPtrByteR aData) const
{
	const GpCryptoKeyPair_Ed25519::ResSignT sign = KeyPair().Sign(aData);
	return GpBytesArrayUtils::SMake(sign);
}

void	Address::RecalcAddress (void)
{
	iName = GpBase58::SEncodeToStr(iKeyPair.PublicBytes(), GpBase58Alphabet::NAKAMOTO);

	if (iName.length() < 44)
	{
		const size_t	paddingSize = 44 - iName.length();
		std::string		padding(paddingSize, '1');
		iName = padding + iName;
	}
}

}//namespace Sol::Core::LightWallet
