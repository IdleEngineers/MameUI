
set(PACKAGE_NAME mameInterfaceTests)

set(
	Sources

	GameListTests.cpp
)

set(
	Headers

	GameListTests.h
)

add_executable(
	mameInterfaceTests

	${Sources}
)

target_link_libraries(mameInterfaceTests mameInterface gtest gtest_main)
