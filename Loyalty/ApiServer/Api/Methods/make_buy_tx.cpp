#include "make_buy_tx.hpp"
#include "../../Managers/BuyTxManagerApi.hpp"

namespace Sol::Loyalty::API::RPC {

API_METHOD_IMPL(make_buy_tx)

make_buy_tx::RsT::DataT	make_buy_tx::Process (RqT& aRq)
{
	//RQ
	const MakeBuyTxRqData& rqData = aRq.data.VC();

	//RS
	make_buy_tx_rs_data rsData = BuyTxManagerApi::SMakeBuyTx
	(
		rqData.client_id,
		rqData.items,
		rqData.spend,
		rqData.spend_sign,
		rqData.spend_raw_tx,
		rqData.new_account_sign,
		rqData.new_account_raw_tx,
		rqData.commit
	);

	return rsData;
}

}//namespace Sol::Loyalty::API::RPC
