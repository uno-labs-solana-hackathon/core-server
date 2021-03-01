#include "ServiceCfgDesc.hpp"

namespace Sol::Loyalty::API::RPC {

TYPE_STRUCT_IMPLEMENT(ServiceCfgDesc, GP_MODULE_UUID)

constexpr std::string_view __serviceCfgDesc_reg_name = "/sol/loyalty/api/rpc/service_cfg"_sv;

ServiceCfgDesc::ServiceCfgDesc (void) noexcept
{
}

ServiceCfgDesc::~ServiceCfgDesc (void) noexcept
{
}

void	ServiceCfgDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
	PROP(db);
	PROP(http);
}

const ServiceCfgDesc&	ServiceCfgDesc::SGetServiceGlobal (void)
{
	const ServiceCfgDesc& serviceCfg = GpStaticCatalogC::S().FindAs<ServiceCfgDesc::CSP>(__serviceCfgDesc_reg_name).VC();
	return serviceCfg;
}

void	ServiceCfgDesc::SRegisterServiceGlobal (GpServiceCfgBaseDesc::CSP aDesc)
{
	GpStaticCatalogC::S().Register(__serviceCfgDesc_reg_name, aDesc);
}

}//namespace Sol::Loyalty::API::RPC
