#include "HttpStartServerTaskFactory.hpp"
#include "HttpStartServerTask.hpp"

namespace Sol::Loyalty::API::RPC {

HttpStartServerTaskFactory::HttpStartServerTaskFactory (void) noexcept
{
}

HttpStartServerTaskFactory::~HttpStartServerTaskFactory (void) noexcept
{
}

GpTask::SP	HttpStartServerTaskFactory::NewInstance (void) const
{
	return MakeSP<HttpStartServerTask>();
}

}//namespace Sol::Loyalty::API::RPC
