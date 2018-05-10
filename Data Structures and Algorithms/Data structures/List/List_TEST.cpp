//
// Created by loinp on 11/04/2018.
//

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "List.h"

TEST(Valid_test_case_List ,List_unit_test) {
    List<int> list;
//
    list.addHead(1);
    list.addHead(2);
    list.addHead(3);
    list.addHead(4);

    ASSERT_EQ(4, list.getHead());
    list.RemoveHead();
    ASSERT_EQ(3, list.getHead());
    list.RemoveHead();
    ASSERT_EQ(2, list.getHead());
    list.RemoveHead();
    ASSERT_EQ(1, list.getHead());
    list.RemoveHead();
//
    list.addTail(1);
    list.addTail(2);
    list.addTail(3);
    list.addTail(4);
//
    ASSERT_EQ(4, list.getTail());
    list.RemoveTail();
    ASSERT_EQ(3, list.getTail());
    list.RemoveTail();
    ASSERT_EQ(2, list.getTail());
    list.RemoveTail();
    ASSERT_EQ(1, list.getTail());
    list.RemoveTail();

}