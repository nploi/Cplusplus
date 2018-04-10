//
// Created by loinp on 04/04/2018.
//

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "DSU.h"

TEST(Valid_test_case_DSU, DSU_unit_test){
    DSU dsu;
    dsu.unionSet(1, 2);
    dsu.unionSet(3, 4);
    dsu.unionSet(5, 6);
    dsu.unionSet(1, 4);

    ASSERT_TRUE(dsu.find(4) == dsu.find(1));
}