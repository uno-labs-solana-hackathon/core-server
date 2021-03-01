#include "ClientsManagerDB.hpp"
#include "DbManager.hpp"

namespace Sol::Loyalty::API::RPC {

ClientsManagerDB::SelectResT	ClientsManagerDB::SSelectById
(
	std::string_view	aClientId,
	GpDbConnection&		aDbConn
)
{
	constexpr const auto cacheUID = GpUUID::CE_FromString("5084f578-3e53-40f2-af1d-041325f6885f"_sv);

	return GpDbQueryMapper::SSelectByKeysAsJsonbCTNR<ClientDescT, DbManager, std::string_view&>
	(
		GpDbQueryCacheUID(cacheUID),
		DbTables::sol::clients(),
		aDbConn,
		{"id"_sv},
		aClientId
	);
}

void	ClientsManagerDB::SInsert
(
	const ClientDescT&	aClientDesc,
	GpDbConnection&		aDbConn
)
{
	constexpr const auto cacheUID = GpUUID::CE_FromString("e6695efd-4160-4068-942a-5e93c239b5e1"_sv);

	GpDbQueryMapper::SInsertAsJsonb
	(
		GpDbQueryCacheUID(cacheUID),
		aClientDesc,
		DbTables::sol::clients(),
		aDbConn,
		GpJsonMapperFlags()
	);
}

void	ClientsManagerDB::SUpdate
(
	const ClientDescT&	aClientDesc,
	const SInt64		aVersion,
	GpDbConnection&		aDbConn
)
{
	constexpr const auto cacheUID = GpUUID::CE_FromString("f005d6ce-f520-4cef-b2c3-416a987b6ec9"_sv);

	GpDbQueryMapper::SUpdateByKeysAsJsonbCTNR<DbManager, std::string_view>
	(
		GpDbQueryCacheUID(cacheUID),
		aClientDesc,
		aVersion,
		DbTables::sol::clients(),
		aDbConn,
		GpJsonMapperFlags(),
		{"id"_sv},
		aClientDesc.id
	);
}

}//namespace Sol::Loyalty::API::RPC
