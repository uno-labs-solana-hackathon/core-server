TEMPLATE        = lib
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 0
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=f72c5c60-b186-4379-8205-552f65ca403d
QMAKE_CXXFLAGS += -DGP_TYPE_SYSTEM_STATIC_ADD_TO_MANAGER
DEFINES		   += SOL_LOYALTY_DATA_MODEL_ENTITIES_LIBRARY
PACKET_NAME     = SolLoyaltyDataModelEntities
DIR_LEVEL       = ./../../../

include(../../../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
	GP_CORE_LIB_V = 2
}

os_linux{
}

LIBS += -lGpCore2$$TARGET_POSTFIX$$GP_CORE_LIB_V
#------------------------------ LIBS END ---------------------------------

SOURCES += \
	BalanceDesc.cpp \
	BalanceTxDesc.cpp \
	BuyTxDesc.cpp \
	BuyTxItemDesc.cpp \
	ClientDesc.cpp


HEADERS += \
	BalanceDesc.hpp \
	BalanceTxDesc.hpp \
	BuyTxDesc.hpp \
	BuyTxItemDesc.hpp \
	ClientDesc.hpp \
	Entities_global.hpp \
	Entities.hpp
