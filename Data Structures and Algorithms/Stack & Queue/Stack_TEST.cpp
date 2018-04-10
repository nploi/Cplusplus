//
// Created by loinp on 11/04/2018.
//

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "STACK.h"

TEST(Valid_test_case_Stack, Stack_unit_test){
    STACK<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    ASSERT_EQ(4, s.top());
    s.pop();
    ASSERT_EQ(3, s.top());
    s.pop();
    ASSERT_EQ(2, s.top());
    s.pop();
    ASSERT_EQ(1, s.top());
    s.pop();
}