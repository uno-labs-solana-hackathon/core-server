#pragma once

#include "ResultCode.hpp"

namespace Sol::Loyalty::API::RPC {

class SOL_LOYALTY_DATA_MODEL_API_API ApiException final: public GpException
{
public:
	using CodeT		= ResultCode;
	using CodeTE	= CodeT::EnumT;

private:
							ApiException		(void) noexcept = delete;
							ApiException		(const ApiException&	aException) noexcept = delete;

	ApiException&			operator=			(const ApiException& aException) noexcept = delete;
	ApiException&			operator=			(ApiException&& aException) noexcept = delete;

public:
							ApiException		(ApiException&& aException) noexcept;
							ApiException		(CodeTE					aCode,
												 std::string_view		aMsg,
												 const SourceLocationT&	aSourceLocation = SourceLocationT::current()) noexcept;
	virtual 				~ApiException		(void) noexcept override final;

	CodeTE					Code				(void) const noexcept {return iCode;}

private:
	const CodeTE			iCode = ResultCode::OK;
};

#define THROW_API(CODE, MSG)					throw ::Sol::Loyalty::API::RPC::ApiException((CODE), (MSG))
#define THROW_API_COND_CHECK(COND, CODE)		if (!(COND)) throw ::Sol::Loyalty::API::RPC::ApiException((CODE), ("Condition not met: "#COND))
#define THROW_API_COND_CHECK_M(COND, CODE, MSG)	if (!(COND)) throw ::Sol::Loyalty::API::RPC::ApiException((CODE), (MSG))

}//namespace Sol::Loyalty::API::RPC
