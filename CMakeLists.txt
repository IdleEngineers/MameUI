 # Treat link_directories as relative
cmake_policy(SET CMP0015 NEW)
cmake_minimum_required(VERSION 2.8)


project(mui)


set(PROJECT_FRIENDLY_NAME "MameUI")
set(PROJECT_COPYRIGHT_YEAR "2013")

if(NOT CMAKE_BUILD_TYPE MATCHES "^[Dd][Ee][Bb][Uu][Gg]")
	add_definitions(-DQT_NO_DEBUG_OUTPUT)
	set(CMAKE_BUILD_RELEASE TRUE)
else()
	set(CMAKE_BUILD_RELEASE FALSE)
	message(WARNING	"Only run ${PROJECT_FRIENDLY_NAME} in Debug mode if you are doing development!")
endif()

set(QT_USE_QTMAIN TRUE)

find_package(Qt4 REQUIRED)
set(CMAKE_AUTOMOC true)

enable_testing()

#====================================================================================================
# Must add subdirectories after installer so that the install directories are defined
#====================================================================================================
add_subdirectory("src")
add_subdirectory("tests")
