#pragma once

#include "../Api_global.hpp"

namespace Sol::Loyalty::API::RPC {

//----------------------------- RQ -----------------------------
class SOL_LOYALTY_DATA_MODEL_API_API FindClientRqData final: public GpTypeStructBase
{
public:
	CLASS_DECLARE_DEFAULTS(FindClientRqData)
	TYPE_STRUCT_DECLARE("8555ed00-3e4e-4049-b629-dfe9d97f632e"_sv)

public:
						FindClientRqData		(void) noexcept;
						FindClientRqData		(std::string_view	aClientId,
												 const bool			aIsCreateIfNotFound);
	virtual				~FindClientRqData		(void) noexcept override final;

public:
	std::string			client_id;
	bool				is_create_if_not_found = false;
};

using find_client_rq_data = FindClientRqData::SP;

RQ(SOL_LOYALTY_DATA_MODEL_API_API, find_client, "6893469e-7f57-4a42-8522-1dfcf4e86b22"_sv)

//----------------------------- RS -----------------------------
using find_client_rs_data = Sol::Loyalty::DataModel::ClientDesc::SP;

RS(SOL_LOYALTY_DATA_MODEL_API_API, find_client, "57bcfaee-bc78-49bc-b19e-9be9610c78ab"_sv)

}//namespace Sol::Loyalty::API::RPC
