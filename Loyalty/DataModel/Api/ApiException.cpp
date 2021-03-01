#include "ApiException.hpp"

namespace Sol::Loyalty::API::RPC {

ApiException::ApiException (ApiException&& aException) noexcept:
GpException(std::move(aException)),
iCode(std::move(aException.iCode))
{
}

ApiException::ApiException
(
	CodeTE					aCode,
	std::string_view		aMsg,
	const SourceLocationT&	aSourceLocation
) noexcept:
GpException(aMsg, aSourceLocation),
iCode(aCode)
{
}

ApiException::~ApiException (void) noexcept
{
}

}//namespace Sol::Loyalty::API::RPC
