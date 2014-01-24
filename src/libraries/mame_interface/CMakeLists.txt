
set(PACKAGE_NAME mameInterface)

set(
	Sources

	GameList.cpp
)

set(
	Headers

	GameList.h
)

add_library(
	mameInterface
	SHARED

	${Sources}
)
