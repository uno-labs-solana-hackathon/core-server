#include "Exception.hpp"

namespace Sol::Loyalty::API::RPC {

Exception::Exception (Exception&& aException) noexcept:
GpException(std::move(aException)),
iCode(std::move(aException.iCode))
{
}

Exception::Exception
(
	CodeTE					aCode,
	std::string_view		aMsg,
	const SourceLocationT&	aSourceLocation
) noexcept:
GpException(aMsg, aSourceLocation),
iCode(aCode)
{
}

Exception::~Exception (void) noexcept
{
}

}//namespace Sol::Loyalty::API::RPC
