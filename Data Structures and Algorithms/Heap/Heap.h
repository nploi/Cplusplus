/*
@author
    nploi1998@gmail.com
@date
    11/04/2018
*/

#ifndef GTEST_HEAP_H
#define GTEST_HEAP_H

#include <iostream>
#include <vector>
#include <stack>


template <class T>
void Swap(T &a, T &b){
    T t = a;
    a = b;
    b = t;
}

template <class T>
bool greater(T a, T b);

template <class T>
bool less(T a, T b);

template <class T>
class Heap {
public:
    Heap() {
        this->compare = less;
        build();
    }

    Heap(bool(compare)(T, T)) {
        this->compare = compare;
        build();
    }

    ~Heap() {

    }

    bool push(T x) {
        arr.push_back(x);
        int i = arr.size() - 1;

        while (i > 0 && compare(arr[i], arr[(i - 1) / 2])) {
            Swap(arr[(i - 1) / 2], arr[i]);
            i = (i - 1) / 2;
        }
    }

    bool pop() {

    }

    T top() {
        return arr[0];
    }

private:
    void heapify(int i) {
        std::stack<int> s;
        s.push(i);

        while (!s.empty()) {
            int index = s.top();

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < arr.size() / 2 && compare(arr[left], arr[index])) {
                index = left;
            }

            if (right < arr.size() / 2 && compare(arr[right], arr[index])) {
                index = right;
            }

            if (index != s.top()) {
                Swap(arr[s.top()], arr[index]);
                s.pop();

                s.push(index);
            }
        }
    }

    void build() {
        for (int i = arr.size() / 2 - 1; i >= 0; --i) {
            heapify(i);
        }
    }

private:
    std::vector<T> arr;

    bool (*compare)(T, T);
};

template <class T>
inline bool greater(T a, T b){
    return a > b;
}

template <class T>
inline bool less(T a, T b){
    return !greater(a, b);
}

#endif //GTEST_HEAP_H
