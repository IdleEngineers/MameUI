set(PACKAGE_NAME MUI)

set(
	Sources
	
	Main.cpp
	MainWindow.cpp
	SettingsWindow.cpp
)

set(
	Forms
	
	MainWindow.ui
	SettingsWindow.ui
)


# for ui headers
include_directories(${CMAKE_CURRENT_BINARY_DIR})

qt4_wrap_ui(Sources ${Forms})

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

add_executable("${PACKAGE_NAME}" ${Sources})

target_link_libraries(
	"${PACKAGE_NAME}"
	
	${QT_LIBRARIES}
	mameInterface
)
