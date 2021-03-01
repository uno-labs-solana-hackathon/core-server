#include "ApiManager.hpp"
#include "Methods/Methods.hpp"

namespace Sol::Loyalty::API::RPC {

ApiManager::ApiManager (void) noexcept
{
}

ApiManager::~ApiManager (void) noexcept
{
}

GpApiRsIfDesc::SP	ApiManager::NewDefaultRs (void) const
{
	return MakeSP<GpApiRsBaseDesc>();
}

void	ApiManager::OnInit (void)
{
	Register(find_client::SFactory());
	Register(make_buy_tx::SFactory());
}

[[noreturn]] void	ApiManager::OnMethodNotFoundEx (std::string_view aName) const
{
	THROW_API
	(
		ResultCode::UNKNOWN_METHOD,
		"API method '"_sv + aName + "' was not found"_sv
	);
}

}//namespace Sol::Loyalty::API::RPC
