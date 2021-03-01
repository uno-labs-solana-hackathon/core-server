#pragma once

#include "BalanceDesc.hpp"

namespace Sol::Loyalty::DataModel  {

class SOL_LOYALTY_DATA_MODEL_ENTITIES_API ClientDesc final: public GpTypeStructBase
{
public:
	CLASS_DECLARE_DEFAULTS(ClientDesc)
	TYPE_STRUCT_DECLARE("6ae53969-df92-47c5-a0b5-9ca4e85e03b3"_sv)

public:
							ClientDesc	(void) noexcept;
	virtual					~ClientDesc	(void) noexcept override final;

public:
	std::string				id;
	unix_ts_s_t				create_ts;
	std::string				name;
	BalanceDesc				balance;
	bool					is_on_chain = false;
};

}//namespace Sol::Loyalty::DataModel
