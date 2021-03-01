#pragma once

#include "../ApiServer_global.hpp"

namespace Sol::Loyalty::API::RPC {

class ClientsManagerDB
{
	CLASS_REMOVE_CTRS(ClientsManagerDB);

	using ClientDescT	= Sol::Loyalty::DataModel::ClientDesc;
	using SelectResT	= std::tuple<ClientDescT::SP, SInt64/*version*/>;

public:
	static SelectResT				SSelectById			(std::string_view	aClientId,
														 GpDbConnection&	aDbConn);
	static void						SInsert				(const ClientDescT&	aClientDesc,
														 GpDbConnection&	aDbConn);
	static void						SUpdate				(const ClientDescT&	aClientDesc,
														 const SInt64		aVersion,
														 GpDbConnection&	aDbConn);
};

}//namespace Sol::Loyalty::API::RPC
