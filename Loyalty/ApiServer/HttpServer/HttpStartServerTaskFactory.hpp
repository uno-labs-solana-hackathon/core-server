#pragma once

#include "../ApiServer_global.hpp"

namespace Sol::Loyalty::API::RPC {

class SOL_LOYALTY_API_SERVER_API HttpStartServerTaskFactory final: public GpTaskFactory
{
public:
	CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(HttpStartServerTaskFactory)
	CLASS_DECLARE_DEFAULTS(HttpStartServerTaskFactory)

public:
								HttpStartServerTaskFactory	(void) noexcept;
	virtual						~HttpStartServerTaskFactory	(void) noexcept override final;

	virtual GpTask::SP			NewInstance					(void) const override final;
};

}//namespace Sol::Loyalty::API::RPC
