cmake_minimum_required(VERSION 3.9)
project(Cplusplus)

set(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY (lib/googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


# Now simply link your own targets against gtest, gmock,
# etc. as appropriate

include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

set(SOURCE_FILES main.cpp )

set(SOURCE_FILES
        "Data Structures and Algorithms/Data structures/Binary Search/BinarySearch_TEST.cpp"
        "Data Structures and Algorithms/Data structures/AVL/AVL_TEST.cpp"
        "Data Structures and Algorithms/Data structures/Disjoint-set-union/DSU_TEST.cpp"
        "Data Structures and Algorithms/Data structures/Trie/Trie_TEST.cpp"
        "Data Structures and Algorithms/Data structures/List/List_TEST.cpp"
        "Data Structures and Algorithms/Algorithms/Search/Search_TEST.cpp"
        "Data Structures and Algorithms/Algorithms/Sorts/Sort_TEST.cpp"
        "Data Structures and Algorithms/Data structures/Stack & Queue/Stack_TEST.cpp"
        "Data Structures and Algorithms/Data structures/Stack & Queue/Queue_TEST.cpp"
        "Data Structures and Algorithms/Data structures/Heap/Heap_TEST.cpp")

add_executable(Cplusplus_test ${SOURCE_FILES})
# Make leak
add_custom_target(
        leak
        COMMAND make -j4
        COMMAND valgrind --track-origins=yes --error-exitcode=2 --leak-check=full --verbose ./Cplusplus_test
#        COMMAND valgrind --leak-check=full -v ./Cplusplus_test
)
target_link_libraries(Cplusplus_test gtest gtest_main)
