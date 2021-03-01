TEMPLATE        = lib
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 0
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=294f0faa-0df1-4601-a0cd-c3fe9049e843
QMAKE_CXXFLAGS += -DGP_TYPE_SYSTEM_STATIC_ADD_TO_MANAGER
DEFINES		   += SOL_LOYALTY_DATA_MODEL_API_LIBRARY
PACKET_NAME     = SolLoyaltyDataModelApi
DIR_LEVEL       = ./../../../

include(../../../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
	GP_CORE_LIB_V							= 2
	GP_NETWORK_LIB_V						= 0
	GP_JSON_LIB_V							= 0
	GP_API_LIB_V							= 0

	SOL_LOYALTY_DATA_MODEL_ENTITIES_LIB_V	= 0
}

os_linux{
}

LIBS += -lGpCore2$$TARGET_POSTFIX$$GP_CORE_LIB_V
LIBS += -lGpNetwork$$TARGET_POSTFIX$$GP_NETWORK_LIB_V
LIBS += -lGpJson$$TARGET_POSTFIX$$GP_JSON_LIB_V
LIBS += -lGpApi$$TARGET_POSTFIX$$GP_API_LIB_V

LIBS += -lSolLoyaltyDataModelEntities$$TARGET_POSTFIX$$SOL_LOYALTY_DATA_MODEL_ENTITIES_LIB_V
#------------------------------ LIBS END ---------------------------------

SOURCES += \
	ApiException.cpp \
	Methods/find_client.cpp \
	Methods/make_buy_tx.cpp \
	ResultCode.cpp \
	RsResultDesc.cpp

HEADERS += \
	ApiException.hpp \
    Api_global.hpp \
	Api.hpp \
	Methods/Methods.hpp \
	Methods/find_client.hpp \
	Methods/make_buy_tx.hpp \
	ResultCode.hpp \
	RsResultDesc.hpp
