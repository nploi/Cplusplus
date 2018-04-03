//
// Test AVL
//

#include "AVL.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace std;

TEST(AVL_TEST, AVL){
    int ss;
    AVL<int> avl;
    avl.insert(1);
    avl.insert(2);
    avl.insert(3);

    ASSERT_TRUE(avl.search(1,ss));
    ASSERT_TRUE(avl.search(2,ss));
    ASSERT_TRUE(avl.search(3,ss));
}