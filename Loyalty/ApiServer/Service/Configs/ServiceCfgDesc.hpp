#pragma once

#include "ServiceHttpCfgDesc.hpp"

namespace Sol::Loyalty::API::RPC {

class ServiceCfgDesc final: public GpServiceCfgBaseDesc
{
public:
	CLASS_DECLARE_DEFAULTS(ServiceCfgDesc)
	TYPE_STRUCT_DECLARE("01026915-2e17-486c-8b36-dec1bab62932"_sv)

public:
												ServiceCfgDesc			(void) noexcept;
	virtual										~ServiceCfgDesc			(void) noexcept override final;

	const GpDbManagerCfgDesc::C::MapStr::SP&	Db						(void) const noexcept {return db;}
	const ServiceHttpCfgDesc&					Http					(void) const noexcept {return http;}

	static const ServiceCfgDesc&				SGetServiceGlobal		(void);
	static void									SRegisterServiceGlobal	(GpServiceCfgBaseDesc::CSP aDesc);

private:
	GpDbManagerCfgDesc::C::MapStr::SP			db;
	ServiceHttpCfgDesc							http;
};

}//namespace Sol::Loyalty::API::RPC
