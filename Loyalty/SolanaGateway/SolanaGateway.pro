TEMPLATE        = lib
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 0
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=c284fe58-6559-4277-9e6c-ee6a0fad79c0
QMAKE_CXXFLAGS += -DGP_TYPE_SYSTEM_STATIC_ADD_TO_MANAGER
DEFINES		   += SOL_LOYALTY_SOLANA_GATEWAY_LIBRARY
PACKET_NAME     = SolLoyaltySolanaGateway
DIR_LEVEL       = ./../../

include(../../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
	GP_CORE_LIB_V							= 2
	GP_CRYPTO_CORE_LIB_V					= 0

	SOL_LOYALTY_DATA_MODEL_ENTITIES_LIB_V	= 0	

	SOL_CORE_DATA_MODEL_ENTITIES_LIB_V		= 0
	SOL_CORE_DATA_MODEL_API_LIB_V			= 0
	SOL_CORE_API_CLIENT_LIB_V				= 0
	SOL_CORE_LIGHT_WALLET_CORE_LIB_V		= 0
}

os_linux{
	LIBS += -lpthread
	LIBS += -lboost_context
	LIBS += -lboost_program_options
	LIBS += -lsodium
}

LIBS += -lGpCore2$$TARGET_POSTFIX$$GP_CORE_LIB_V
LIBS += -lGpCryptoCore$$TARGET_POSTFIX$$GP_CRYPTO_CORE_LIB_V

LIBS += -lSolLoyaltyDataModelEntities$$TARGET_POSTFIX$$SOL_LOYALTY_DATA_MODEL_ENTITIES_LIB_V

LIBS += -lSolCoreDataModelEntities$$TARGET_POSTFIX$$SOL_CORE_DATA_MODEL_ENTITIES_LIB_V
LIBS += -lSolCoreDataModelApi$$TARGET_POSTFIX$$SOL_CORE_DATA_MODEL_API_LIB_V
LIBS += -lSolCoreApiClient$$TARGET_POSTFIX$$SOL_CORE_DATA_MODEL_API_LIB_V
LIBS += -lSolCoreLightWalletCore$$TARGET_POSTFIX$$SOL_CORE_LIGHT_WALLET_CORE_LIB_V
#------------------------------ LIBS END ---------------------------------

HEADERS += \
	Loyalty2Solana.hpp \
	SolanaGateway.hpp \
	SolanaGateway_global.hpp

SOURCES += \
	Loyalty2Solana.cpp
