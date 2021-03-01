#pragma once

#include "../Managers/DbManager.hpp"

namespace Sol::Loyalty::API::RPC {

class HttpRequestHandler final: public GpApiSrvRequestHandlerHttp
{
public:
	CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(HttpRequestHandler)
	CLASS_DECLARE_DEFAULTS(HttpRequestHandler)

public:
								HttpRequestHandler		(GpApiMethodsManager::SP		aApiManager,
														 GpTypeMapperFactory::SP		aTypeMapperFactory,
														 GpApiTypeDetectorFactory::SP	aTypeDetectorFactory) noexcept;
	virtual						~HttpRequestHandler		(void) noexcept override final;

protected:
	virtual GpApiResultDesc::SP	GenResultOK				(void) const override final;
	virtual GpApiResultDesc::SP	GenResultEx				(const std::exception& e) const override final;
	virtual GpApiResultDesc::SP	GenResultExUnknown		(void) const override final;
	virtual GpApiResultDesc::SP	CallAndCatch			(std::function<void()> aFn) const override final;
};

}//namespace Sol::Loyalty::API::RPC
