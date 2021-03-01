#include "find_client.hpp"
#include "../../Managers/ClientsManagerApi.hpp"

namespace Sol::Loyalty::API::RPC {

API_METHOD_IMPL(find_client)

find_client::RsT::DataT	find_client::Process (RqT& aRq)
{
	//RQ
	const FindClientRqData& rqData = aRq.data.VC();

	//RS
	find_client_rs_data rsData = ClientsManagerApi::SFindClient(rqData.client_id, rqData.is_create_if_not_found);
	return rsData;
}

}//namespace Sol::Loyalty::API::RPC
