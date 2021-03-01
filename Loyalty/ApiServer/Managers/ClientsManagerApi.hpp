#pragma once

#include "../ApiServer_global.hpp"

namespace Sol::Loyalty::API::RPC {

class ClientsManagerApi
{
	CLASS_REMOVE_CTRS(ClientsManagerApi);

	using ClientDescT = Sol::Loyalty::DataModel::ClientDesc;

public:
	static ClientDescT::SP				SFindClient		(std::string_view	aClientId,
														 const bool			aIsCreateIfNotFound);

	static ClientDescT::SP				SSetOnChain		(std::string_view	aClientId);
};

}//namespace Sol::Loyalty::API::RPC
