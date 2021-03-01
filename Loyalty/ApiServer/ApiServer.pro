TEMPLATE        = lib
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 0
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=2db6b1cd-8965-4c61-bf8b-dfa4fde74781
QMAKE_CXXFLAGS += -DGP_TYPE_SYSTEM_STATIC_ADD_TO_MANAGER
DEFINES		   += SOL_LOYALTY_API_SERVER_LIBRARY
PACKET_NAME     = SolLoyaltyApiServer
DIR_LEVEL       = ./../../

include(../../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
	GP_CORE_LIB_V							= 2
	GP_JSON_LIB_V							= 0
	GP_NETWORK_LIB_V						= 0
	GP_API_LIB_V							= 0
	GP_SERVICE_LIB_V						= 0
	GP_DB_CLIENT_LIB_V						= 0
	GP_POSTGRESQL_LIB_V						= 0
	GP_CRYPTO_CORE_LIB_V					= 0

	UTF8_PROC_LIB_V							= 0

	SOL_CORE_DATA_MODEL_ENTITIES_LIB_V		= 0
	SOL_CORE_DATA_MODEL_API_LIB_V			= 0
	SOL_CORE_API_CLIENT_LIB_V				= 0
	SOL_CORE_LIGHT_WALLET_CORE_LIB_V		= 0

	SOL_LOYALTY_DATA_MODEL_ENTITIES_LIB_V	= 0
	SOL_LOYALTY_DATA_MODEL_API_LIB_V		= 0
	SOL_LOYALTY_SOLANA_GATEWAY_LIB_V	    = 0
	SOL_LOYALTY_API_CLIENT_LIB_V		    = 0
	SOL_LOYALTY_API_SERVER_LIB_V		    = 0
}

os_linux{
	LIBS += -lpthread
	LIBS += -lboost_context
	LIBS += -lboost_program_options
	LIBS += -lsodium
}

LIBS += -lGpCore2$$TARGET_POSTFIX$$GP_CORE_LIB_V
LIBS += -lGpJson$$TARGET_POSTFIX$$GP_JSON_LIB_V
LIBS += -lGpNetwork$$TARGET_POSTFIX$$GP_NETWORK_LIB_V
LIBS += -lGpApi$$TARGET_POSTFIX$$GP_API_LIB_V
LIBS += -lGpService$$TARGET_POSTFIX$$GP_SERVICE_LIB_V
LIBS += -lGpDbClient$$TARGET_POSTFIX$$GP_DB_CLIENT_LIB_V
LIBS += -lGpPostgreSql$$TARGET_POSTFIX$$GP_POSTGRESQL_LIB_V
LIBS += -lGpCryptoCore$$TARGET_POSTFIX$$GP_CRYPTO_CORE_LIB_V
LIBS += -lutf8proc$$TARGET_POSTFIX$$UTF8_PROC_LIB_V

LIBS += -lSolCoreDataModelEntities$$TARGET_POSTFIX$$SOL_CORE_DATA_MODEL_ENTITIES_LIB_V
LIBS += -lSolCoreDataModelApi$$TARGET_POSTFIX$$SOL_CORE_DATA_MODEL_API_LIB_V
LIBS += -lSolLoyaltySolanaGateway$$TARGET_POSTFIX$$SOL_LOYALTY_SOLANA_GATEWAY_LIB_V
LIBS += -lSolCoreApiClient$$TARGET_POSTFIX$$SOL_CORE_DATA_MODEL_API_LIB_V
LIBS += -lSolCoreLightWalletCore$$TARGET_POSTFIX$$SOL_CORE_LIGHT_WALLET_CORE_LIB_V

LIBS += -lSolLoyaltyDataModelEntities$$TARGET_POSTFIX$$SOL_LOYALTY_DATA_MODEL_ENTITIES_LIB_V
LIBS += -lSolLoyaltyDataModelApi$$TARGET_POSTFIX$$SOL_LOYALTY_DATA_MODEL_API_LIB_V
LIBS += -lSolLoyaltyApiClient$$TARGET_POSTFIX$$SOL_LOYALTY_API_CLIENT_LIB_V
LIBS += -lSolLoyaltyApiServer$$TARGET_POSTFIX$$SOL_LOYALTY_API_SERVER_LIB_V
#------------------------------ LIBS END ---------------------------------

HEADERS += \
	Api/Api.hpp \
	Api/ApiManager.hpp \
	Api/Methods/Methods.hpp \
	Api/Methods/find_client.hpp \
	Api/Methods/make_buy_tx.hpp \
	ApiServer.hpp \
	ApiServer_global.hpp \
	Exception/Exception.hpp \
	HttpServer/HttpRequestHandler.hpp \
	HttpServer/HttpRequestHandlerFactory.hpp \
	HttpServer/HttpStartServerTask.hpp \
	HttpServer/HttpStartServerTaskFactory.hpp \
	Managers/BuyTxManager.hpp \
	Managers/BuyTxManagerApi.hpp \
	Managers/BuyTxManagerDB.hpp \
	Managers/ClientsManager.hpp \
	Managers/ClientsManagerApi.hpp \
	Managers/ClientsManagerDB.hpp \
	Managers/DbManager.hpp \
	Managers/DbTables.hpp \
	Managers/Managers.hpp \
	Service/CmdArgsDesc.hpp \
	Service/Configs/ServiceCfgDesc.hpp \
	Service/Configs/ServiceConfigs.hpp \
	Service/Configs/ServiceHttpCfgDesc.hpp \
	Service/Service.hpp \
	Service/ServiceFactory.hpp \
	Service/ServiceMainTask.hpp

SOURCES += \
	Api/ApiManager.cpp \
	Api/Methods/find_client.cpp \
	Api/Methods/make_buy_tx.cpp \
	Exception/Exception.cpp \
	HttpServer/HttpRequestHandler.cpp \
	HttpServer/HttpRequestHandlerFactory.cpp \
	HttpServer/HttpStartServerTask.cpp \
	HttpServer/HttpStartServerTaskFactory.cpp \
	Managers/BuyTxManager.cpp \
	Managers/BuyTxManagerApi.cpp \
	Managers/BuyTxManagerDB.cpp \
	Managers/ClientsManager.cpp \
	Managers/ClientsManagerApi.cpp \
	Managers/ClientsManagerDB.cpp \
	Managers/DbManager.cpp \
	Service/CmdArgsDesc.cpp \
	Service/Configs/ServiceCfgDesc.cpp \
	Service/Configs/ServiceHttpCfgDesc.cpp \
	Service/Service.cpp \
	Service/ServiceFactory.cpp \
	Service/ServiceMainTask.cpp
