# HELLO
# HAPPY CODING
### Install library googletest
```
git clone git@github.com:google/googletest.git
cd googletest
cmake . && sudo make install
```
### How to test
```
mkdir cmake-build-debug
cd cmake-build-debug/
cmake ..
make -j4 && ./GTest
```
### After run unit-test

```
Running main() from gtest_main.cc
[==========] Running 3 tests from 3 test cases.
[----------] Global test environment set-up.
[----------] 1 test from BINARY_SEARCH_TEST
[ RUN      ] BINARY_SEARCH_TEST.BINARY_SEARCH
[       OK ] BINARY_SEARCH_TEST.BINARY_SEARCH (0 ms)
[----------] 1 test from BINARY_SEARCH_TEST (0 ms total)

[----------] 1 test from AVL_TEST
[ RUN      ] AVL_TEST.AVL
[       OK ] AVL_TEST.AVL (0 ms)
[----------] 1 test from AVL_TEST (0 ms total)

[----------] 1 test from DSU_TEST_UNIT
[ RUN      ] DSU_TEST_UNIT.DSU_TEST
[       OK ] DSU_TEST_UNIT.DSU_TEST (0 ms)
[----------] 1 test from DSU_TEST_UNIT (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 3 test cases ran. (0 ms total)
[  PASSED  ] 3 tests.

``` 