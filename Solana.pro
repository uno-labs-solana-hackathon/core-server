TEMPLATE = subdirs

os_linux {
	SUBDIRS += \
		./Core \
		./Loyalty
} else:os_android {
	SUBDIRS += \
		./Core \
		./Loyalty
} else:os_ios {
	SUBDIRS += \
		./Core \
		./Loyalty
} else:os_windows {
	SUBDIRS += \
		./Core \
		./Loyalty
} else:os_macx {
	SUBDIRS += \
		./Core \
		./Loyalty
} else:os_browser {
	SUBDIRS += \
		./Core
} else {
	error(Unknown OS. Set CONFIG+=... one of values: os_linux, os_android, os_ios, os_windows, os_macx, os_browser)
}

CONFIG += ordered
