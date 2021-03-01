#include "HttpRequestHandlerFactory.hpp"

namespace Sol::Loyalty::API::RPC {

HttpRequestHandlerFactory::HttpRequestHandlerFactory
(
	GpApiMethodsManager::SP			aApiManager,
	GpTypeMapperFactory::SP			aTypeMapperFactory,
	GpApiTypeDetectorFactory::SP	aTypeDetectorFactory
) noexcept:
iApiManager(std::move(aApiManager)),
iTypeMapperFactory(std::move(aTypeMapperFactory)),
iTypeDetectorFactory(std::move(aTypeDetectorFactory))
{
}

HttpRequestHandlerFactory::~HttpRequestHandlerFactory (void) noexcept
{
}

GpHttpRequestHandler::SP	HttpRequestHandlerFactory::NewInstance (void) const
{
	return MakeSP<HttpRequestHandler>
	(
		iApiManager,
		iTypeMapperFactory,
		iTypeDetectorFactory
	);
}

}//namespace Sol::Loyalty::API::RPC
