#pragma once

#include "Entities_global.hpp"

namespace Sol::Loyalty::DataModel  {

class SOL_LOYALTY_DATA_MODEL_ENTITIES_API BalanceDesc final: public GpTypeStructBase
{
public:
	CLASS_DECLARE_DEFAULTS(BalanceDesc)
	TYPE_STRUCT_DECLARE("db877116-caef-42e2-a1f3-81123b72cf2e"_sv)

public:
							BalanceDesc		(void) noexcept;
	virtual					~BalanceDesc	(void) noexcept override final;

public:
	monetary_t				total		= 0_monetary;
	monetary_t				unlocked	= 0_monetary;
	monetary_t				locked		= 0_monetary;
};

}//namespace Sol::Loyalty::DataModel
