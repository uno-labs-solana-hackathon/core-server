#include "ServiceFactory.hpp"
#include "Service.hpp"

namespace Sol::Loyalty::API::RPC {

ServiceFactory::ServiceFactory (void) noexcept
{
}

ServiceFactory::~ServiceFactory (void) noexcept
{
}

GpService::SP	ServiceFactory::NewInstance (void) const
{
	return MakeSP<Service>();
}

}//namespace Sol::Loyalty::API::RPC
