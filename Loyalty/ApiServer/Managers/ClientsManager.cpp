#include "ClientsManager.hpp"
#include "ClientsManagerDB.hpp"

namespace Sol::Loyalty::API::RPC {

ClientsManager::ClientDescT::SP	ClientsManager::SCreateClient (std::string_view aClientId)
{
	SCheckClientId(aClientId);

	Sol::Loyalty::DataModel::ClientDesc::SP clientDescSP = MakeSP<Sol::Loyalty::DataModel::ClientDesc>();

	{
		Sol::Loyalty::DataModel::ClientDesc& clientDesc = clientDescSP.V();

		clientDesc.id = aClientId;
	}

	return clientDescSP;
}

void	ClientsManager::SCheckClientId (std::string_view aClientId)
{
	const size_t length = aClientId.length();

	THROW_GPE_COND
	(
		(length == 44),
		"Wrong client id length"_sv
	);
}

ClientsManager::ClientDescT::SP	ClientsManager::SFindClient (std::string_view aClientId)
{
	GpDbConnectionGuard	dbConnGuard;
	GpDbConnection&		dbConn = dbConnGuard.Connection();

	return std::get<0>(ClientsManagerDB::SSelectById(aClientId, dbConn));
}

ClientsManager::ClientDescT::SP	ClientsManager::SCreateAndInsertClient (std::string_view aClientId)
{
	ClientDescT::SP clientDescSP = ClientsManager::SCreateClient(aClientId);

	{
		GpDbConnectionGuard	dbConnGuard;
		GpDbConnection&		dbConn = dbConnGuard.Connection();
		ClientsManagerDB::SInsert(clientDescSP.VC(), dbConn);
	}

	return clientDescSP;
}

}//namespace Sol::Loyalty::API::RPC
