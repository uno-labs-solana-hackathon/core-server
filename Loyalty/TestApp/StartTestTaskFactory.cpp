#include "StartTestTaskFactory.hpp"
#include "TestTask.hpp"

namespace Sol::Loyalty::Test {

StartTestTaskFactory::StartTestTaskFactory (void) noexcept
{
}

StartTestTaskFactory::~StartTestTaskFactory (void) noexcept
{
}

GpTask::SP	StartTestTaskFactory::NewInstance (void) const
{
	return MakeSP<TestTask>();
}

}//namespace Sol::Loyalty::Test
