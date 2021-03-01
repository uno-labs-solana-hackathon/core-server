#pragma once

#include "../ApiServer_global.hpp"

namespace Sol::Loyalty::API::RPC {

class CmdArgsDesc final: public GpArgBaseDesc
{
public:
	CLASS_DECLARE_DEFAULTS(CmdArgsDesc)
	TYPE_STRUCT_DECLARE("d54e66f4-16f4-4f87-86a7-a0622924b4c2"_sv)

public:
							CmdArgsDesc		(void) noexcept;
	virtual					~CmdArgsDesc	(void) noexcept override final;

private:	
};

}//namespace Sol::Loyalty::API::RPC
