#include "ClientsManagerApi.hpp"
#include "ClientsManager.hpp"
#include "ClientsManagerDB.hpp"
#include "../Exception/Exception.hpp"

namespace Sol::Loyalty::API::RPC {

ClientsManagerApi::ClientDescT::SP	ClientsManagerApi::SFindClient
(
	std::string_view	aClientId,
	const bool			aIsCreateIfNotFound
)
{
	ClientsManagerApi::ClientDescT::SP client;

	try
	{
		client = ClientsManager::SFindClient(aClientId);
	} catch (const Exception& ex)
	{
		if (   (aIsCreateIfNotFound == true)
			&& (ex.Code() == ResultCode::DB_ENTITY_NOT_FOUND))
		{
			client = ClientsManager::SCreateAndInsertClient(aClientId);
		}
	}

	return client;
}

ClientsManagerApi::ClientDescT::SP	ClientsManagerApi::SSetOnChain (std::string_view aClientId)
{
	GpDbConnectionGuard	dbConnGuard;
	GpDbConnection&		dbConn = dbConnGuard.Connection();

	auto[client, version] = ClientsManagerDB::SSelectById(aClientId, dbConn);

	client->is_on_chain = true;

	ClientsManagerDB::SUpdate(client.VC(), version, dbConn);

	return client;
}

}//namespace Sol::Loyalty::API::RPC
