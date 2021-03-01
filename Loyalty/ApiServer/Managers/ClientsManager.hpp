#pragma once

#include "../ApiServer_global.hpp"

namespace Sol::Loyalty::API::RPC {

class ClientsManager
{
	CLASS_REMOVE_CTRS(ClientsManager);

	using ClientDescT = Sol::Loyalty::DataModel::ClientDesc;

public:
	static ClientDescT::SP				SCreateClient			(std::string_view	aClientId);
	static void							SCheckClientId			(std::string_view	aClientId);

	static ClientDescT::SP				SFindClient				(std::string_view	aClientId);
	static ClientDescT::SP				SCreateAndInsertClient	(std::string_view	aClientId);
};

}//namespace Sol::Loyalty::API::RPC
