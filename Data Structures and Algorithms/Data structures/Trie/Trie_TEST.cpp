//
// Created by loinp on 04/04/2018.
//
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Trie.h"

TEST(Valid_test_case_Trie, Trie_unit_test){
    Trie t;
    t.add("nguyen");
    t.add("phuc");
    t.add("loi");

    ASSERT_TRUE(t.find("nguyen"));
    ASSERT_TRUE(t.find("phuc"));
    ASSERT_TRUE(t.find("loi"));
}