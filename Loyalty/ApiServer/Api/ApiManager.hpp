#pragma once

#include "../ApiServer_global.hpp"

namespace Sol::Loyalty::API::RPC {

class ApiManager final: public GpApiMethodsManager
{
public:
	CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(ApiManager)
	CLASS_DECLARE_DEFAULTS(ApiManager)

public:
								ApiManager			(void) noexcept;
	virtual						~ApiManager			(void) noexcept override final;

	virtual GpApiRsIfDesc::SP	NewDefaultRs		(void) const override final;

protected:
	virtual void				OnInit				(void) override final;
	[[noreturn]] virtual void	OnMethodNotFoundEx	(std::string_view aName) const override final;
};

}//namespace Sol::Loyalty::API::RPC
