#pragma once

#include "../ApiServer_global.hpp"

namespace Sol::Loyalty::API::RPC {

class Exception final: public GpException
{
public:
	using CodeT		= ResultCode;
	using CodeTE	= CodeT::EnumT;

private:
						Exception		(void) noexcept = delete;
						Exception		(const Exception& aException) noexcept = delete;

	Exception&			operator=		(const Exception& aException) noexcept = delete;
	Exception&			operator=		(Exception&& aException) noexcept = delete;

public:
						Exception		(Exception&& aException) noexcept;
						Exception		(CodeTE					aCode,
										 std::string_view		aMsg,
										 const SourceLocationT&	aSourceLocation = SourceLocationT::current()) noexcept;
	virtual 			~Exception		(void) noexcept override final;

	CodeTE				Code			(void) const noexcept {return iCode;}

private:
	const CodeTE		iCode;
};

#define THROW_SOL_EX(CODE, MSG)						throw Exception((CODE), (MSG))
#define THROW_SOL_EX_COND_CHECK(COND, CODE)			if (!(COND)) throw Exception((CODE), ("Condition not met: "#COND))
#define THROW_SOL_EX_COND_CHECK_M(COND, CODE, MSG)	if (!(COND)) throw Exception((CODE), (MSG))

}//namespace Sol::Loyalty::API::RPC
