cmake_minimum_required(VERSION 3.9)
project(Cplusplus)

set(CMAKE_CXX_STANDARD 11)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
        "${CMAKE_BINARY_DIR}/googletest-build")

# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if(CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
endif()

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate

include_directories(cmake-build-debug/googletest-src/googlemock/include)
include_directories(cmake-build-debug/googletest-src/googletest/include)
set(SOURCE_FILES main.cpp )

set(SOURCE_FILES
        "Data Structures and Algorithms/Data structures/Binary Search/BinarySearch_TEST.cpp"
        "Data Structures and Algorithms/Data structures/AVL/AVL_TEST.cpp"
        "Data Structures and Algorithms/Data structures/Disjoint-set-union/DSU_TEST.cpp"
        "Data Structures and Algorithms/Data structures/Trie/Trie_TEST.cpp"
        "Data Structures and Algorithms/Data structures/List/List_TEST.cpp"
        "Data Structures and Algorithms/Data structures/Search/Search_TEST.cpp"
        "Data Structures and Algorithms/Data structures/Sorts/Sort_TEST.cpp"
        "Data Structures and Algorithms/Data structures/Stack & Queue/Stack_TEST.cpp"
        "Data Structures and Algorithms/Data structures/Stack & Queue/Queue_TEST.cpp"
        "Data Structures and Algorithms/Data structures/Heap/Heap_TEST.cpp")

add_executable(Cplusplus_test ${SOURCE_FILES})
target_link_libraries(Cplusplus_test gtest gtest_main)