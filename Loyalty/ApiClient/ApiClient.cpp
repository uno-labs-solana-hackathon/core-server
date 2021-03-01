#include "ApiClient.hpp"

namespace Sol::Loyalty::API::RPC {

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

find_client_rs_data	ApiClient::find_client (const find_client_rq_data& aRq)
{
	return ProcessRQ<find_client_rq,
					 find_client_rs>(aRq, "find_client"_sv);
}

find_client_rs_data	ApiClient::find_client
(
	std::string_view aClientId,
	const bool		aIsCreateIfNotFound)
{
	auto rq = MakeSP<FindClientRqData>
	(
		aClientId,
		aIsCreateIfNotFound
	);

	return find_client(rq);
}

make_buy_tx_rs_data	ApiClient::make_buy_tx (const make_buy_tx_rq_data& aRq)
{
	return ProcessRQ<make_buy_tx_rq,
					 make_buy_tx_rs>(aRq, "make_buy_tx"_sv);
}

make_buy_tx_rs_data	ApiClient::make_buy_tx
(
	std::string_view	aClientId,
	const ItemsT&		aItems,
	const monetary_t	aSpend,
	const GpBytesArray&	aSpendSign,
	const GpBytesArray&	aSpendRawTx,
	const GpBytesArray&	aNewAccountSign,
	const GpBytesArray&	aNewAccountRawTx,
	const bool			aCommit
)
{
	auto rq = MakeSP<MakeBuyTxRqData>
	(
		aClientId,
		aItems,
		aSpend,
		aSpendSign,
		aSpendRawTx,
		aNewAccountSign,
		aNewAccountRawTx,
		aCommit
	);

	return make_buy_tx(rq);
}

void	ApiClient::CheckRsResult
(
	GPlatform::API::RPC::GpApiResultDesc::SP	aRes,
	std::string_view							aMethodName
)
{
	const auto& res = GpTypeManager::S().Cast<const RsResultDesc>(aRes.VC());

	if (res.res != ResultCode::OK)
	{
		THROW_API
		(
			res.res.Value(),
			"API call return error. Method '"_sv + aMethodName + "', code " + res.res.ToString() + ", message: "_sv + res.msg
		);
	}
}

void	ApiClient::OnProcessRQ (GpApiRqIfDesc& /*aRq*/)
{
	//NOP
}

}//namespace Sol::Loyalty::API::RPC
