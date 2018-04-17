//
// Created by loinp on 11/04/2018.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Heap.h"

TEST(Valid_test_case_Heap, Heap_unit_test) {
    //max heap
    Heap<int> heap(greater);
    heap.push(1);
    heap.push(2);
    heap.push(5);
    heap.push(6);
    heap.push(9);
    heap.push(0);

    ASSERT_EQ(9, heap.top());

    //Min heap
    Heap<int> heap1(less);
    heap1.push(1);
    heap1.push(2);
    heap1.push(5);
    heap1.push(6);
    heap1.push(9);
    heap1.push(0);

    ASSERT_EQ(0, heap1.top());
}