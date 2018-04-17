//
// Created by loinp on 11/04/2018.
//

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Search.cpp"
//#include "Search.h"


TEST(Valid_test_case_search, Search_unit_test){
    int *a = new int[11];
    for (int i = 0; i <= 10; ++i) {
        a[i] = i;
    }
    int result;
    /*
     * find x in arr
     * return index
     */
    result = BinarySearch(a, 10, 5);
    ASSERT_EQ(5, a[result]);
    result = LinearSearch(a, 10, 6);
    ASSERT_EQ(6, a[result]);

    /*
     * find Min 4th in arr
     * return value
     */
    result = SearchForMinimum(a, 10, 4);
    ASSERT_EQ(4, result);

    /*
     * find min
     * return value
     */
    result = SearchForMinimum(a, 10);
    ASSERT_EQ(0, result);

    delete [] a;
}