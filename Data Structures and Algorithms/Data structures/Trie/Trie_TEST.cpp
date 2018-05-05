//
// Created by loinp on 04/04/2018.
//
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Trie.h"

TEST(Valid_test_case_Trie, Trie_unit_test){
    Trie t;
    t.add("Nguyen");
    t.add("Phuc");
    t.add("Loi");

    ASSERT_TRUE(t.find("Nguyen"));
    ASSERT_TRUE(t.find("Phuc"));
    ASSERT_TRUE(t.find("Loi"));
    t.deleteAll();
}