#include "ApiClient.hpp"

namespace Sol::Core::API::RPC {

ApiClient::ApiClient (std::string_view aUrl):
GpApiCli
(
	MakeSP<GPlatform::API::RPC::GpApiCliTransportHttpFactory>
	(
		aUrl,
		MakeSP<GpTypeMapperJsonFactory>(),
		MakeSP<GpApiCliTransportHttpCtxFactory>()
	)->NewInstance()
)
{
}

ApiClient::~ApiClient (void) noexcept
{
}

getRecentBlockhash_rs_data	ApiClient::getRecentBlockhash (const getRecentBlockhash_rq_data& aRq)
{
	return ProcessRQ<getRecentBlockhash_rq,
					 getRecentBlockhash_rs>(aRq, "getRecentBlockhash"_sv);
}

getRecentBlockhash_rs_data	ApiClient::getRecentBlockhash (void)
{
	auto rq = {MakeSP<GetRecentBlockhashRqData>()};
	return getRecentBlockhash(rq);
}

sendTransaction_rs_data	ApiClient::sendTransaction (std::string_view aTxBase58)
{
	return ProcessRQ<sendTransaction_rq,
					 sendTransaction_rs>({std::string(aTxBase58)}, "sendTransaction"_sv);
}

void	ApiClient::CheckRsResult
(
	GPlatform::API::RPC::GpApiResultDesc::SP	aRes,
	std::string_view							aMethodName
)
{
	if (aRes.IsNULL())
	{
		return;
	}

	const RsErrorDesc& error = static_cast<const RsErrorDesc&>(aRes.VCn());

	THROW_GPE_COND
	(
		error.code == 0,
		"Solana API call return error. Method '"_sv + aMethodName + "', code " + error.code + ", message: "_sv + error.message
	);
}

void	ApiClient::OnProcessRQ (GpApiRqIfDesc& /*aRq*/)
{
	//NOP
}

}//namespace Sol::Core::API::RPC
