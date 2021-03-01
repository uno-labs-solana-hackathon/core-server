#include "HttpStartServerTask.hpp"
#include "HttpRequestHandlerFactory.hpp"
#include "../Service/Configs/ServiceCfgDesc.hpp"
#include "../Api/ApiManager.hpp"

namespace Sol::Loyalty::API::RPC {

HttpStartServerTask::HttpStartServerTask (void) noexcept
{
}

HttpStartServerTask::~HttpStartServerTask (void) noexcept
{
}

void	HttpStartServerTask::OnStart (void)
{
	//Configure and start http server
	const ServiceCfgDesc&		cfg		= ServiceCfgDesc::SGetServiceGlobal();
	const ServiceHttpCfgDesc&	cfgHttp	= cfg.Http();

	GpHttpClientPoolCatalog::S().SetPoolDefaultFactory
	(
		MakeSP<GpHttpClientCurlFactory>(),
		cfgHttp.cli_init_count,
		cfgHttp.cli_max_count
	);

	GpSocketAddr addr;
	addr.Init(GpSocketIPv::IPv4, cfgHttp.listen_ip, cfgHttp.listen_port);

	//API manager
	ApiManager::SP apiManager = MakeSP<ApiManager>();
	apiManager->Init();

	//
	GpHttpServerFactory::SP httpServerFactory = MakeSP<GpHttpServerNodeFactory>
	(
		addr,
		MakeSP<GpIOEventPollerEpollFactory>(100.0_si_ms, 128_cnt),
		MakeSP<HttpRequestHandlerFactory>
		(
			apiManager,
			MakeSP<GpTypeMapperJsonFactory>(GpJsonMapperFlags{GpJsonMapperFlag::WRITE_STRUCT_UID}),
			MakeSP<GpApiTypeDetectorJsonFactory>()
		)
	);

	GpHttpServer::SP httpServer = httpServerFactory->NewInstance();
	GpTaskScheduler::SCurrentScheduler().value()->AddTaskToReady(httpServer);
}

GpTask::ResT	HttpStartServerTask::OnStep (EventOptRefT /*aEvent*/)
{
	return GpTask::ResT::DONE;
}

void	HttpStartServerTask::OnStop (void) noexcept
{
	//NOP
}

}//namespace Sol::Loyalty::API::RPC
