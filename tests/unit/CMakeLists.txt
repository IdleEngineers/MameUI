
set(PACKAGE_NAME mameInterfaceTests)

set(
	Sources

	GameListTests.cpp
)

set(
	Headers

	GameListTests.h
)

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

add_executable(
	${PACKAGE_NAME}

	${Sources}
)

target_link_libraries(
	${PACKAGE_NAME}

	${QT_LIBRARIES}
	mameInterface
	gtest
	gtest_main
)


file(COPY "sample_game_list.txt" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
