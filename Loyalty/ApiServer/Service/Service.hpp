#pragma once

#include "../ApiServer_global.hpp"

namespace Sol::Loyalty::API::RPC {

class Service final: public GpService
{
public:
	CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(Service)
	CLASS_DECLARE_DEFAULTS(Service)

public:
										Service					(void);
	virtual								~Service				(void) noexcept override final;

protected:
	virtual GpArgBaseDesc::SP			CreateCmdLineArgsDesc	(void) override final;
	virtual GpServiceCfgBaseDesc::SP	CreateServiceCfgDesc	(void) override final;
	virtual GpServiceMainTask::SP		CreateMainTask			(const GpArgBaseDesc&		aCmdLineArgsDesc,
																 GpServiceCfgBaseDesc::CSP	aServiceCfgDesc) override final;
};

}//namespace Sol::Loyalty::API::RPC
