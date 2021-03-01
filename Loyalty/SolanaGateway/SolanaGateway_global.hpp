#pragma once

#include "../../../GPlatform/GpCore2/GpCore.hpp"
#include "../../../GPlatform/GpCryptoCore/GpCryptoCore.hpp"

#include "../DataModel/Entities/Entities.hpp"

#include "../../Core/DataModel/Entities/Entities.hpp"
#include "../../Core/DataModel/Api/Api.hpp"
#include "../../Core/ApiClient/ApiClient.hpp"
#include "../../Core/LightWalletCore/LightWalletCore.hpp"

#if defined(SOL_LOYALTY_SOLANA_GATEWAY_LIBRARY)
	#define SOL_LOYALTY_SOLANA_GATEWAY_API GP_DECL_EXPORT
#else
	#define SOL_LOYALTY_SOLANA_GATEWAY_API GP_DECL_IMPORT
#endif

using namespace GPlatform;
