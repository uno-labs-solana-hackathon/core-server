#pragma once

#include "Configs/ServiceConfigs.hpp"

namespace Sol::Loyalty::API::RPC {

class ServiceMainTask final: public GpServiceMainTask
{
public:
	CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(ServiceMainTask)
	CLASS_DECLARE_DEFAULTS(ServiceMainTask)

public:
							ServiceMainTask		(const GpArgBaseDesc&		aCmdLineArgsDesc,
												 GpServiceCfgBaseDesc::CSP	aServiceCfgDesc) noexcept;
	virtual					~ServiceMainTask	(void) noexcept override final;

protected:
	virtual void			OnStart				(void) override final;
	virtual ResT			OnStep				(EventOptRefT aEvent) override final;
	virtual void			OnStop				(void) noexcept override final;

private:
};

}//namespace Sol::Loyalty::API::RPC
