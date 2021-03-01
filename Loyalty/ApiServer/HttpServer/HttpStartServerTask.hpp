#pragma once

#include "../ApiServer_global.hpp"

namespace Sol::Loyalty::API::RPC {

class HttpStartServerTask final: public GpTaskFiberBase
{
public:
	CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(HttpStartServerTask)
	CLASS_DECLARE_DEFAULTS(HttpStartServerTask)

public:
							HttpStartServerTask		(void) noexcept;
	virtual					~HttpStartServerTask	(void) noexcept override final;

protected:
	virtual void			OnStart					(void) override final;
	virtual GpTask::ResT	OnStep					(EventOptRefT aEvent) override final;
	virtual void			OnStop					(void) noexcept override final;
};

}//namespace Sol::Loyalty::API::RPC
