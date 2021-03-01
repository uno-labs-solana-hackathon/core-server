#pragma once

#include "Entities_global.hpp"

namespace Sol::Loyalty::DataModel  {

class SOL_LOYALTY_DATA_MODEL_ENTITIES_API BalanceTxDesc final: public GpTypeStructBase
{
public:
	CLASS_DECLARE_DEFAULTS(BalanceTxDesc)
	TYPE_STRUCT_DECLARE("3b78287d-74e8-495b-9411-a656398c3b89"_sv)

public:
							BalanceTxDesc	(void) noexcept;
	virtual					~BalanceTxDesc	(void) noexcept override final;

public:
	GpUUID					id;
	GpUUID					buy_tx_id;
	GpUUID					balance_id;
	monetary_t				balance_delta	= 0_monetary;
	unix_ts_s_t				create_ts;
};

}//namespace Sol::Loyalty::DataModel
