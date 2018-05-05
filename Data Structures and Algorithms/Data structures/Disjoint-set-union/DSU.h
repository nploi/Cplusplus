/*
@author
    nploi1998@gmail.com
@date
    04/04/2018.
*/

#ifndef GTEST_DSU_H
#define GTEST_DSU_H

#define MAX 1000

#include <iostream>
#include <vector>

class DSU{
public:
    DSU(){
        par.resize(MAX + 1);
        for (int i = 1; i <= MAX; ++i) {
            par[i] = i;
        }
    }

    /*
     * find root
     */
    int find(int x) {
        if (x <= MAX) {
            while (x != par[x]) {
                x = par[x];
            }
            return x;
        }
        return -1;
    }

    /*
     * merge
     */
    void unionSet(int i, int j){
        int x = find(i), y = find(j);
        if(x == -1 || y == -1)
            return;
        par[y] = x;
    }

    ~DSU(){
        par.clear();
    }
private:
    std::vector<int> par;
};

#endif //GTEST_DSU_H
