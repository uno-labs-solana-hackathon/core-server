#include "ServiceMainTask.hpp"
#include "Configs/ServiceConfigs.hpp"
#include "../../../../GPlatform/GpPostgreSql/GpPostgreSql.hpp"

#include <iostream>

namespace Sol::Loyalty::API::RPC {

ServiceMainTask::ServiceMainTask
(
	const GpArgBaseDesc&		aCmdLineArgsDesc,
	GpServiceCfgBaseDesc::CSP	aServiceCfgDesc
) noexcept:
GpServiceMainTask(aCmdLineArgsDesc, aServiceCfgDesc)
{
}

ServiceMainTask::~ServiceMainTask (void) noexcept
{
}

void	ServiceMainTask::OnStart (void)
{	
	std::cout << "[ServiceMainTask::OnStart]: starting server..."_sv << std::endl;

	ServiceCfgDesc::SRegisterServiceGlobal(ServiceCfgCSP());

	const ServiceCfgDesc& serviceCfgDesc = static_cast<const ServiceCfgDesc&>(ServiceCfg());

	std::cout << "[ServiceMainTask::OnStart]: starting db manager..."_sv << std::endl;

	//DB
	{
		GpDbManagerCatalog& dbManager = GpDbManagerCatalog::S();
		dbManager.AddDriverFactory(MakeSP<GpDbDriverFactoryPgSql>());
		dbManager.InitFromConfig(serviceCfgDesc.Db(), GpDbConnectionMode::SYNC);
	}

	std::cout << "[ServiceMainTask::OnStart]: server started..."_sv << std::endl;
}

GpTask::ResT	ServiceMainTask::OnStep (EventOptRefT /*aEvent*/)
{
	return GpTask::ResT::WAITING;
}

void	ServiceMainTask::OnStop (void) noexcept
{
}

}//namespace Sol::Loyalty::API::RPC
