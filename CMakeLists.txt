cmake_minimum_required(VERSION 3.1)

# this line has to appear before 'PROJECT' in order to be able to disable incremental linking
set(MSVC_INCREMENTAL_DEFAULT ON)

# begin project
project(CPP_PERFORMANCE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CPP_PERFORMANCE_SOURCE_DIR}/Bin CACHE PATH "Single output directory for building executables.")

# debug/release
if (NOT CMAKE_BUILD_TYPE)
	# set(CMAKE_BUILD_TYPE "Debug")
	set(CMAKE_BUILD_TYPE "Release")
endif()

message(STATUS "- System: ${CMAKE_SYSTEM_NAME} - BuildType: ${CMAKE_BUILD_TYPE}")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")
endif()

set(CMAKE_CXX_STANDARD 17)

subdirs (Source)