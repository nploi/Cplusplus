//
// Created by loinp on 04/04/2018.
//

#include "BST.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(BINARY_SEARCH_TEST, BINARY_SEARCH){
    BST<int> bst;
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    ASSERT_EQ(6, bst.sum());
}