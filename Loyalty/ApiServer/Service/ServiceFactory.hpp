#pragma once

#include "../ApiServer_global.hpp"

namespace Sol::Loyalty::API::RPC {

class SOL_LOYALTY_API_SERVER_API ServiceFactory final: public GpServiceFactory
{
public:
	CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(ServiceFactory)
	CLASS_DECLARE_DEFAULTS(ServiceFactory)

public:
							ServiceFactory	(void) noexcept;
	virtual					~ServiceFactory	(void) noexcept override final;

	virtual GpService::SP	NewInstance		(void) const override final;
};

}//namespace Sol::Loyalty::API::RPC
