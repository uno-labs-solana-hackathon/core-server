#include "HttpRequestHandler.hpp"
#include "../Managers/Managers.hpp"

#include <iostream>

namespace Sol::Loyalty::API::RPC {

HttpRequestHandler::HttpRequestHandler
(
	GpApiMethodsManager::SP			aApiManager,
	GpTypeMapperFactory::SP			aTypeMapperFactory,
	GpApiTypeDetectorFactory::SP	aTypeDetectorFactory
) noexcept:
GpApiSrvRequestHandlerHttp
(
	aApiManager,
	aTypeMapperFactory,
	aTypeDetectorFactory
)
{
}

HttpRequestHandler::~HttpRequestHandler	(void) noexcept
{
}

GpApiResultDesc::SP	HttpRequestHandler::GenResultOK (void) const
{
	return MakeSP<RsResultDesc>
	(
		ResultCode::OK,
		""_sv
	);
}

GpApiResultDesc::SP	HttpRequestHandler::GenResultEx (const std::exception& e) const
{
	return MakeSP<RsResultDesc>
	(
		ResultCode::FAILED,
		e.what()
	);
}

GpApiResultDesc::SP	HttpRequestHandler::GenResultExUnknown (void) const
{
	return MakeSP<RsResultDesc>
	(
		ResultCode::FAILED,
		"Unknown exception"_sv
	);
}

GpApiResultDesc::SP	HttpRequestHandler::CallAndCatch (std::function<void()> aFn) const
{
	try
	{
		aFn();
	} catch (const Exception& e)
	{
		return MakeSP<RsResultDesc>
		(
			e.Code(),
			e.what()
		);
	}

	return GenResultOK();
}

}//namespace Sol::Loyalty::API::RPC
