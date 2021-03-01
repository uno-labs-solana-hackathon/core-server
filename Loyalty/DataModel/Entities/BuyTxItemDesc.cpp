#include "BuyTxItemDesc.hpp"

namespace Sol::Loyalty::DataModel  {

TYPE_STRUCT_IMPLEMENT(BuyTxItemDesc, GP_MODULE_UUID)

BuyTxItemDesc::BuyTxItemDesc (void) noexcept
{
}

BuyTxItemDesc::BuyTxItemDesc
(
	const SInt64		aId,
	std::string_view	aArticle,
	std::string_view	aName,
	const monetary_t	aPrice,
	const count_t		aQty
):
id(aId),
article(aArticle),
name(aName),
price(aPrice),
qty(aQty)
{
}

BuyTxItemDesc::~BuyTxItemDesc (void) noexcept
{
}

void	BuyTxItemDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
	PROP(id);
	PROP(article);
	PROP(name);
	PROP(price);
	PROP(qty);
}

}//namespace Sol::Loyalty::DataModel
