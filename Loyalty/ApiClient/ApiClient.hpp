#pragma once

#include "ApiClient_global.hpp"

namespace Sol::Loyalty::API::RPC {

class SOL_LOYALTY_API_CLIENT_API ApiClient final: public GPlatform::API::RPC::GpApiCli
{
public:
	CLASS_REMOVE_CTRS(ApiClient)
	CLASS_DECLARE_DEFAULTS(ApiClient)

	using ItemsT = Sol::Loyalty::DataModel::BuyTxItemDesc::C::Vec::SP;

public:
										ApiClient				(std::string_view aUrl);
	virtual								~ApiClient				(void) noexcept override final;

	//find_client
	find_client_rs_data					find_client				(const find_client_rq_data& aRq);
	find_client_rs_data					find_client				(std::string_view	aClientId,
																 const bool			aIsCreateIfNotFound);

	//make_buy_tx
	make_buy_tx_rs_data					make_buy_tx				(const make_buy_tx_rq_data& aRq);
	make_buy_tx_rs_data					make_buy_tx				(std::string_view		aClientId,
																 const ItemsT&			aItems,
																 const monetary_t		aSpend,
																 const GpBytesArray&	aSpendSign,
																 const GpBytesArray&	aSpendRawTx,
																 const GpBytesArray&	aNewAccountSign,
																 const GpBytesArray&	aNewAccountRawTx,
																 const bool				aCommit);

protected:
	virtual void						CheckRsResult			(GPlatform::API::RPC::GpApiResultDesc::SP	aRes,
																 std::string_view							aMethodName) override final;
	virtual void						OnProcessRQ				(GpApiRqIfDesc& aRq) override final;
};

}//namespace Sol::Loyalty::API::RPC
