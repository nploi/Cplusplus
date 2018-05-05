# HELLO
# HAPPY CODING
### Install library googletest
```
git clone git@github.com:google/googletest.git
cd googletest
cmake . && sudo make install
```
### How to test all data structures
```
mkdir cmake-build-debug
cd cmake-build-debug/
cmake ..
make -j4 && ./Cplusplus_test
```
### Test memory leak by valgrind
```
# Step 1: Install valgrind
sudo apt install valgrind
# Step 2:
cd cmake-build-debug/
cmake ..
make leak
```
