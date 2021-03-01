#pragma once

#include "HttpRequestHandler.hpp"

namespace Sol::Loyalty::API::RPC {

class HttpRequestHandlerFactory final: public GpHttpRequestHandlerFactory
{
public:
	CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(HttpRequestHandlerFactory)
	CLASS_DECLARE_DEFAULTS(HttpRequestHandlerFactory)

public:
										HttpRequestHandlerFactory	(GpApiMethodsManager::SP		aApiManager,
																	 GpTypeMapperFactory::SP		aTypeMapperFactory,
																	 GpApiTypeDetectorFactory::SP	aTypeDetectorFactory) noexcept;
	virtual								~HttpRequestHandlerFactory	(void) noexcept override final;

	virtual GpHttpRequestHandler::SP	NewInstance					(void) const override final;

private:
	GpApiMethodsManager::SP				iApiManager;
	GpTypeMapperFactory::SP				iTypeMapperFactory;
	GpApiTypeDetectorFactory::SP		iTypeDetectorFactory;
};

}//namespace Sol::Loyalty::API::RPC
