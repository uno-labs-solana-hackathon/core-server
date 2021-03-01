#pragma once

#include "BuyTxItemDesc.hpp"

namespace Sol::Loyalty::DataModel  {

class SOL_LOYALTY_DATA_MODEL_ENTITIES_API BuyTxDesc final: public GpTypeStructBase
{
public:
	CLASS_DECLARE_DEFAULTS(BuyTxDesc)
	TYPE_STRUCT_DECLARE("8572b0d0-a63e-459c-b308-c879298a454e"_sv)

public:
	using ItemsT = BuyTxItemDesc::C::Vec::SP;

public:
							BuyTxDesc	(void) noexcept;
	virtual					~BuyTxDesc	(void) noexcept override final;

public:
	GpUUID					id;
	ItemsT					items;
	unix_ts_s_t				create_ts;
	std::string				client_id;
	monetary_t				total	= 0_monetary;
	monetary_t				earned	= 0_monetary;
	monetary_t				spend	= 0_monetary;
	GpBytesArray			spend_sign;
	GpBytesArray			spend_raw_tx;
	GpBytesArray			new_account_sign;
	GpBytesArray			new_account_raw_tx;
};

}//namespace Sol::Loyalty::DataModel
