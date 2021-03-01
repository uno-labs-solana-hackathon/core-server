#pragma once

#include "Api_global.hpp"

namespace Sol::Core::API::RPC {

class SOL_CORE_DATA_MODEL_API_API ApiRqBaseDesc: public GpApiRqIfDesc
{
public:
	CLASS_DECLARE_DEFAULTS(ApiRqBaseDesc)
	TYPE_STRUCT_DECLARE("dd45200b-b8bf-4146-9110-a73d18fcf1d3"_sv)

public:
								ApiRqBaseDesc		(void) noexcept;
	virtual						~ApiRqBaseDesc		(void) noexcept override;

	virtual std::string_view	Method				(void) const override final;
	virtual void				SetMethod			(std::string_view aMethod) override final;

public:
	std::string					jsonrpc	= std::string("2.0"_sv);
	s_int_64					id		= 1;
	std::string					method;
};

#define SOL_API_RQ(PREFIX, NAME, UUID) \
class PREFIX NAME##_rq final: public ApiRqBaseDesc \
{ \
public: \
	CLASS_DECLARE_DEFAULTS(NAME##_rq) \
	TYPE_STRUCT_DECLARE(UUID) \
 \
public: \
 \
	using DataT		= NAME##_rq_data; \
	using DataTRef	= std::reference_wrapper<DataT>; \
	using DataTRefC	= std::reference_wrapper<const DataT>; \
 \
public: \
						NAME##_rq	(void) noexcept; \
						NAME##_rq	(DataT&& aData) noexcept; \
	virtual				~NAME##_rq	(void) noexcept; \
 \
	virtual std::any	Payload		(void) const override final; \
	virtual std::any	Payload		(void) override final; \
	virtual void		SetPayload	(std::any aAny) override final; \
 \
public: \
	DataT				params; \
};

#define SOL_API_RQ_IMPL(NAME) \
TYPE_STRUCT_IMPLEMENT(NAME##_rq, GP_MODULE_UUID) \
 \
NAME##_rq::NAME##_rq (void) noexcept \
{ \
} \
 \
NAME##_rq::NAME##_rq (DataT&& aData) noexcept: \
params(std::move(aData)) \
{ \
} \
 \
NAME##_rq::~NAME##_rq (void) noexcept \
{ \
} \
 \
std::any	NAME##_rq::Payload (void) const \
{ \
   return std::make_any<DataTRefC>(params); \
} \
 \
std::any	NAME##_rq::Payload (void) \
{ \
   return std::make_any<DataTRef>(params); \
} \
 \
void	NAME##_rq::SetPayload (std::any aAny) \
{ \
   const auto& typeInfoAny = aAny.type(); \
\
   if (typeInfoAny == typeid(DataTRef)) \
   { \
	   params = std::any_cast<DataTRef>(aAny); \
   } else if (typeInfoAny == typeid(DataTRefC)) \
   { \
	   params = std::any_cast<DataTRefC>(aAny); \
   } else \
   { \
	   throw std::bad_any_cast(); \
   } \
} \
 \
void	NAME##_rq::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut) \
{ \
	PROP(params); \
}

}//Sol::Core::API::RPC
