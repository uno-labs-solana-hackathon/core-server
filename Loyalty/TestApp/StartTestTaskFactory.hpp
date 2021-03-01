#pragma once

#include "TestApp_global.hpp"

namespace Sol::Loyalty::Test {

class StartTestTaskFactory final: public GpTaskFactory
{
public:
	CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(StartTestTaskFactory)
	CLASS_DECLARE_DEFAULTS(StartTestTaskFactory)

public:
								StartTestTaskFactory	(void) noexcept;
	virtual						~StartTestTaskFactory	(void) noexcept override final;

	virtual GpTask::SP			NewInstance				(void) const override final;
};


}//namespace Sol::Loyalty::Test
