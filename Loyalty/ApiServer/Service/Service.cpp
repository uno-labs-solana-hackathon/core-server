#include "Service.hpp"
#include "ServiceMainTask.hpp"
#include "CmdArgsDesc.hpp"
#include "Configs/ServiceCfgDesc.hpp"

namespace Sol::Loyalty::API::RPC {

Service::Service (void):
GpService("Solana loyalty API server"_sv)
{
}

Service::~Service (void) noexcept
{
}

GpArgBaseDesc::SP	Service::CreateCmdLineArgsDesc (void)
{
	return MakeSP<CmdArgsDesc>();
}

GpServiceCfgBaseDesc::SP	Service::CreateServiceCfgDesc (void)
{
	return MakeSP<ServiceCfgDesc>();
}

GpServiceMainTask::SP	Service::CreateMainTask
(
	const GpArgBaseDesc&		aCmdLineArgsDesc,
	GpServiceCfgBaseDesc::CSP	aServiceCfgDesc
)
{
	return MakeSP<ServiceMainTask>(aCmdLineArgsDesc, aServiceCfgDesc);
}

}//namespace Sol::Loyalty::API::RPC
