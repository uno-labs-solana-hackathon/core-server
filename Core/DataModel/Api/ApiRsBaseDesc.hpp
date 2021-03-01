#pragma once

#include "RsErrorDesc.hpp"

namespace Sol::Core::API::RPC {

class SOL_CORE_DATA_MODEL_API_API ApiRsBaseDesc: public GpApiRsIfDesc
{
public:
	CLASS_DECLARE_DEFAULTS(ApiRsBaseDesc)
	TYPE_STRUCT_DECLARE("f76d1837-fa68-4b52-a916-2e63a0505f5e"_sv)

public:
										ApiRsBaseDesc	(void) noexcept;
	virtual								~ApiRsBaseDesc	(void) noexcept override;

	virtual GpApiResultDesc::SP			Result			(void) override final;
	virtual void						SetResult		(GpApiResultDesc::SP aResult) override final;

public:
	std::string							jsonrpc	= std::string("2.0"_sv);
	s_int_64							id		= 1;
	GpApiResultDesc::SP					error;
};

#define SOL_API_RS(PREFIX, NAME, UUID) \
class PREFIX NAME##_rs final: public ApiRsBaseDesc \
{ \
public: \
	CLASS_DECLARE_DEFAULTS(NAME##_rs) \
	TYPE_STRUCT_DECLARE(UUID) \
 \
public: \
 \
	using DataT		= NAME##_rs_data; \
	using DataTRef	= std::reference_wrapper<DataT>; \
	using DataTRefC	= std::reference_wrapper<const DataT>; \
 \
public: \
						NAME##_rs	(void) noexcept; \
	virtual				~NAME##_rs	(void) noexcept; \
 \
	virtual std::any	Payload		(void) const override final; \
	virtual std::any	Payload		(void) override final; \
	virtual void		SetPayload	(std::any aAny) override final; \
 \
public: \
	DataT				result; \
};

#define SOL_API_RS_IMPL(NAME) \
TYPE_STRUCT_IMPLEMENT(NAME##_rs, GP_MODULE_UUID) \
 \
NAME##_rs::NAME##_rs (void) noexcept \
{ \
} \
 \
NAME##_rs::~NAME##_rs (void) noexcept \
{ \
} \
 \
std::any	NAME##_rs::Payload (void) const \
{ \
	return std::make_any<DataTRefC>(result); \
} \
 \
std::any	NAME##_rs::Payload (void) \
{ \
	return std::make_any<DataTRef>(result); \
} \
 \
void	NAME##_rs::SetPayload (std::any aAny) \
{ \
	const auto& typeInfoAny = aAny.type(); \
 \
	if (typeInfoAny == typeid(DataTRef)) \
	{ \
		result = std::any_cast<DataTRef>(aAny); \
	} else if (typeInfoAny == typeid(DataTRefC)) \
	{ \
		result = std::any_cast<DataTRefC>(aAny); \
	} else \
	{ \
		throw std::bad_any_cast(); \
	} \
} \
 \
void	NAME##_rs::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut) \
{ \
	PROP(result); \
}

}//namespace Sol::Core::API::RPC
