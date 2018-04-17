//
// Created by loinp on 11/04/2018.
//

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "QUEUE.h"

TEST(Valid_test_case_Queue, Queue_unit_test){
    QUEUE<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    ASSERT_EQ(1, q.front());
    q.pop();
    ASSERT_EQ(2, q.front());
    q.pop();
    ASSERT_EQ(3, q.front());
    q.pop();
    ASSERT_EQ(4, q.front());
    q.pop();
}