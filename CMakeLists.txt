cmake_minimum_required(VERSION 3.5.2)
project(CODING)


find_package(UnitTest++ REQUIRED)

include_directories(${UTPP_INCLUDE_DIRS})

add_subdirectory(lib/googletest)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES main.cpp TESTING/Testing.cpp TESTING/Testing.h)


add_executable(CODING ${SOURCE_FILES})


target_link_libraries(CODING gtest gtest_main)
