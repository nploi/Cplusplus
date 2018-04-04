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
make -j4 && ./Cplusplus_test
```
### After run unit-test

```
[==========] Running 4 tests from 4 test cases.
[----------] Global test environment set-up.
[----------] 1 test from BINARY_SEARCH_UNIT_TEST
[ RUN      ] BINARY_SEARCH_UNIT_TEST.BINARY_SEARCH_TEST
[       OK ] BINARY_SEARCH_UNIT_TEST.BINARY_SEARCH_TEST (0 ms)
[----------] 1 test from BINARY_SEARCH_UNIT_TEST (0 ms total)

[----------] 1 test from AVL_TEST
[ RUN      ] AVL_TEST.AVL
[       OK ] AVL_TEST.AVL (0 ms)
[----------] 1 test from AVL_TEST (0 ms total)

[----------] 1 test from DSU_UNIT_TEST
[ RUN      ] DSU_UNIT_TEST.DSU_TEST
[       OK ] DSU_UNIT_TEST.DSU_TEST (0 ms)
[----------] 1 test from DSU_UNIT_TEST (0 ms total)

[----------] 1 test from Trie_UNIT_TEST
[ RUN      ] Trie_UNIT_TEST.Trie_TEST
[       OK ] Trie_UNIT_TEST.Trie_TEST (0 ms)
[----------] 1 test from Trie_UNIT_TEST (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 4 test cases ran. (0 ms total)
[  PASSED  ] 4 tests.

``` 