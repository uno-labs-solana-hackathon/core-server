#include "find_client.hpp"

namespace Sol::Loyalty::API::RPC {

//----------------------------- RQ -----------------------------
TYPE_STRUCT_IMPLEMENT(FindClientRqData, GP_MODULE_UUID)

FindClientRqData::FindClientRqData (void) noexcept
{
}

FindClientRqData::FindClientRqData
(
	std::string_view	aClientId,
	const bool			aIsCreateIfNotFound
):
client_id(aClientId),
is_create_if_not_found(aIsCreateIfNotFound)
{
}

FindClientRqData::~FindClientRqData (void) noexcept
{
}

void	FindClientRqData::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
	PROP(client_id);
	PROP(is_create_if_not_found);
}

RQ_IMPL(find_client)

//----------------------------- RS -----------------------------
RS_IMPL(find_client)

}//namespace Sol::Loyalty::API::RPC
