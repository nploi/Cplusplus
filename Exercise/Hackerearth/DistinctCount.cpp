//https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/distinct-count/description/
/*
+@author
+ - loinp
+@date
+ - 19/03/2018
+*/

#include <bits/stdc++.h>

using namespace std;

template <class T>
struct node {
    node *pLeft;
    node *pRight;
    T data;

    node() {
        pLeft = NULL;
        pRight = NULL;
    }

    node(T x) {
        data = x;
        pLeft = NULL;
        pRight = NULL;
    }
};

template <class T>
class BinaryTree {

public:
    BinaryTree() {
        pRoot = NULL;
        count = 0;
    }

    ~BinaryTree() {
        if (pRoot != NULL) {
            Delete(pRoot);
        }
    }

    void insert(T key) {
        this->count += Insert(this->pRoot, key);
    }

    int getSize() {
        return count;
    }

private:
    void Delete(node<T> *&pRoot) {
        if (pRoot != NULL) {
            Delete(pRoot->pLeft);
            Delete(pRoot->pRight);
            delete pRoot;
        }
    }

    bool Insert(node<T> *&pRoot, T x) {

        if (pRoot == NULL) {
            pRoot = new node<T>(x);
            return true;
        }

        if (x == pRoot->data) {
            return false;
        }

        if (x > pRoot->data) {
            return Insert(pRoot->pRight, x);
        } else {
            return Insert(pRoot->pLeft, x);
        }
    }


private:
    node<T> *pRoot;
    int count;
};



int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, x;
        BinaryTree<int> binaryTree;
        cin >> n >> x;

        for (int i = 0; i < n; ++i) {
            int val;
            cin >> val;
            binaryTree.insert(val);
        }

        if (binaryTree.getSize() > x) {
            cout << "Average\n";
        } else {
            if (binaryTree.getSize() < x) {
                cout << "Bad\n";
            } else {
                cout << "Good\n";
            }
        }

    }

    return 0;
}
