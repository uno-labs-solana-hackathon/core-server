#pragma once

#include "../../../GPlatform/GpCore2/GpCore.hpp"
#include "../../../GPlatform/GpService/GpService.hpp"
#include "../../../GPlatform/GpJson/GpJson.hpp"
#include "../../../GPlatform/GpDbClient/GpDbClient.hpp"
#include "../../../GPlatform/GpPostgreSql/GpPostgreSql.hpp"
#include "../../../GPlatform/GpNetwork/GpNetwork.hpp"
#include "../../../GPlatform/GpApi/GpApi.hpp"
#include "../DataModel/Entities/Entities.hpp"
#include "../DataModel/Api/Api.hpp"
#include "../ApiClient/ApiClient.hpp"
#include "../SolanaGateway/SolanaGateway.hpp"

#if defined(SOL_LOYALTY_API_SERVER_LIBRARY)
	#define SOL_LOYALTY_API_SERVER_API GP_DECL_EXPORT
#else
	#define SOL_LOYALTY_API_SERVER_API GP_DECL_IMPORT
#endif

using namespace GPlatform;
