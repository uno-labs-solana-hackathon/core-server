#include "BuyTxManagerDB.hpp"
#include "DbManager.hpp"

namespace Sol::Loyalty::API::RPC {

BuyTxManagerDB::SelectResT	BuyTxManagerDB::SSelectById
(
	const GpUUID&	aBuyTxId,
	GpDbConnection&	aDbConn
)
{
	constexpr const auto cacheUID = GpUUID::CE_FromString("8bed787e-74dc-483c-958e-e70e5f473a1c"_sv);

	return GpDbQueryMapper::SSelectByKeysAsJsonbCTNR<BuyTxDescT, DbManager, const GpUUID&>
	(
		GpDbQueryCacheUID(cacheUID),
		DbTables::sol::buy_txs(),
		aDbConn,
		{"id"_sv},
		aBuyTxId
	);
}

void	BuyTxManagerDB::SInsert
(
	const BuyTxDescT&	aBuyTxDesc,
	GpDbConnection&		aDbConn
)
{
	constexpr const auto cacheUID = GpUUID::CE_FromString("ffa6bee2-33f0-4580-abf8-3cb02c63c445"_sv);

	GpDbQueryMapper::SInsertAsJsonb
	(
		GpDbQueryCacheUID(cacheUID),
		aBuyTxDesc,
		DbTables::sol::buy_txs(),
		aDbConn,
		GpJsonMapperFlags()
	);
}

}//namespace Sol::Loyalty::API::RPC
