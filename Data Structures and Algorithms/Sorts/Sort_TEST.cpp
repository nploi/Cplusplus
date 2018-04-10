//
// Created by loinp on 11/04/2018.
//


#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "sort.h"

TEST(Valid_case_test_Sort, Sort_unit_test){

    int n = 5000;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }

    /*
     * ALL SORT FOLLOW LESS
     */

    SelectionSort(a, n, Less);

    for (int j = 0; j < n; ++j) {
        ASSERT_EQ(j, a[j]);
    }

    /*
     * 1 is h
     * h for shellSort, h can 1, 3, 5
     */
    InsertionSort(a, n, 1, Less);
    for (int j = 0; j < n; ++j) {
        ASSERT_EQ(j, a[j]);
    }

    HeapSort(a, n, Less);
    for (int j = 0; j < n; ++j) {
        ASSERT_EQ(j, a[j]);
    }

    QuickSort(a, n, 0, n - 1, Less);
    for (int j = 0; j < n; ++j) {
        ASSERT_EQ(j, a[j]);
    }

    MergeSort(a, n, Less);
    for (int j = 0; j < n; ++j) {
        ASSERT_EQ(j, a[j]);
    }

    //---------------------------

    /*
     * ALL SORT FOLLOW GREATER
     */

    SelectionSort(a, n, Greater);
    for (int j = n - 1, i = 0; i < n; --j, i++) {
        ASSERT_EQ(j, a[i]);
    }

    /*
     * 1 is h
     * h for shellSort, h can 1, 3, 5
     */
    InsertionSort(a, n, 1, Greater);
    for (int j = n - 1, i = 0; i < n; --j, i++) {
        ASSERT_EQ(j, a[i]);
    }

    HeapSort(a, 11, Greater);
    for (int j = n - 1, i = 0; i < n; --j, i++) {
        ASSERT_EQ(j, a[i]);
    }

    QuickSort(a, 11, 0, 10, Greater);
    for (int j = n - 1, i = 0; i < n; --j, i++) {
        ASSERT_EQ(j, a[i]);
    }

    MergeSort(a, 11, Greater);
    for (int j = n - 1, i = 0; i < n; --j, i++) {
        ASSERT_EQ(j, a[i]);
    }

    delete []a;
}