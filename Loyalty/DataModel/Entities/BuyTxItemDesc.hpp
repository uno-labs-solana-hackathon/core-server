#pragma once

#include "Entities_global.hpp"

namespace Sol::Loyalty::DataModel  {

class SOL_LOYALTY_DATA_MODEL_ENTITIES_API BuyTxItemDesc final: public GpTypeStructBase
{
public:
	CLASS_DECLARE_DEFAULTS(BuyTxItemDesc)
	TYPE_STRUCT_DECLARE("b616772b-113f-4909-a2f6-7552a36504c1"_sv)

public:
							BuyTxItemDesc	(void) noexcept;
							BuyTxItemDesc	(const SInt64		aId,
											 std::string_view	aArticle,
											 std::string_view	aName,
											 const monetary_t	aPrice,
											 const count_t		aQty);
	virtual					~BuyTxItemDesc	(void) noexcept override final;

public:
	SInt64					id		= 0_s_int_64;
	std::string				article;
	std::string				name;
	monetary_t				price	= 0_monetary;
	count_t					qty		= 0_cnt;
};

}//namespace Sol::Loyalty::DataModel
