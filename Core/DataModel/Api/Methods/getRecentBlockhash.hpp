#pragma once

#include "../ApiRqBaseDesc.hpp"
#include "../ApiRsBaseDesc.hpp"

namespace Sol::Core::API::RPC {

using namespace Sol::Core::DataModel;

//----------------------------- RQ -----------------------------
class SOL_CORE_DATA_MODEL_API_API GetRecentBlockhashRqData final: public GpTypeStructBase
{
public:
	CLASS_DECLARE_DEFAULTS(GetRecentBlockhashRqData)
	TYPE_STRUCT_DECLARE("dcb5b08c-b40f-40ef-9c2e-d129579ef43a"_sv)

public:
						GetRecentBlockhashRqData		(void) noexcept;
						GetRecentBlockhashRqData		(std::string_view aCommitment);
	virtual				~GetRecentBlockhashRqData		(void) noexcept override final;

public:
	std::string			commitment	= std::string("finalized"_sv);
};

using getRecentBlockhash_rq_data = GetRecentBlockhashRqData::C::Vec::SP;

SOL_API_RQ(SOL_CORE_DATA_MODEL_API_API, getRecentBlockhash, "cc5f1128-4228-4501-a406-337ddda8c219"_sv)

//----------------------------- RS -----------------------------
namespace GetRecentBlockhashRqRs
{
	class SOL_CORE_DATA_MODEL_API_API Context final: public GpTypeStructBase
	{
	public:
		CLASS_DECLARE_DEFAULTS(Context)
		TYPE_STRUCT_DECLARE("d81a3da4-40fd-4d7f-a798-32ea77b30427"_sv)

		public:
								Context		(void) noexcept;
			virtual				~Context	(void) noexcept override final;

		public:
			s_int_64			slot = 0;
	};

	class SOL_CORE_DATA_MODEL_API_API FeeCalculator final: public GpTypeStructBase
	{
	public:
		CLASS_DECLARE_DEFAULTS(FeeCalculator)
		TYPE_STRUCT_DECLARE("54febadb-fe01-42a4-8abe-6aa61b609f78"_sv)

		public:
							FeeCalculator	(void) noexcept;
			virtual			~FeeCalculator	(void) noexcept override final;

		public:
			lamport_t		lamportsPerSignature = 0_lamport;
	};

	class SOL_CORE_DATA_MODEL_API_API Value final: public GpTypeStructBase
	{
	public:
		CLASS_DECLARE_DEFAULTS(Value)
		TYPE_STRUCT_DECLARE("9808a911-c7a8-41b6-9255-bd779b536ade"_sv)

		public:
								Value		(void) noexcept;
			virtual				~Value		(void) noexcept override final;

		public:
			std::string			blockhash;
			FeeCalculator		feeCalculator;
	};
}//namespace GetRecentBlockhashRqRs

class SOL_CORE_DATA_MODEL_API_API GetRecentBlockhashRsData final: public GpTypeStructBase
{
public:
	CLASS_DECLARE_DEFAULTS(GetRecentBlockhashRsData)
	TYPE_STRUCT_DECLARE("6f522c98-642e-415c-b689-df3aba84fb70"_sv)

public:
						GetRecentBlockhashRsData		(void) noexcept;
	virtual				~GetRecentBlockhashRsData		(void) noexcept override final;

public:
	GetRecentBlockhashRqRs::Context	context;
	GetRecentBlockhashRqRs::Value	value;
};

using getRecentBlockhash_rs_data = GetRecentBlockhashRsData::SP;

SOL_API_RS(SOL_CORE_DATA_MODEL_API_API, getRecentBlockhash, "759ab18f-a8a0-4329-9436-ecbf2491aeff"_sv)

}//namespace Sol::Core::API::RPC
