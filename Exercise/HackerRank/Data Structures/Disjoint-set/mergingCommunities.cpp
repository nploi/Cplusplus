//https://www.hackerrank.com/challenges/merging-communities/problem

#include <iostream>
#include <vector>

#define MAX 100000
using namespace std;

int a[MAX], size[MAX];

void init(int n){
    for (int i = 1; i <= n; ++i) {
        a[i] = i;
        size[i] = 1;
    }
}

int findRoot(int i){
    // compress path
    if(i != a[i]){
        a[i] = findRoot(a[i]);
    }
    return a[i];
}

void merge(int i, int j){
    int x = findRoot(i), y = findRoot(j);
    if(x == y)
        return;
    a[x] = y;
    size[y] += size[x];
    size[x] = 0;
}


int main(){
    int n;
    cin >> n;
    init(n);
    cin >> n;

    while(n--){
        char c;
        int a, b;
        cin >> c ;
        if(c == 'Q'){
            cin >> a;
            cout << size[findRoot(a)] << endl;
        }else{
            cin >> a >> b;
            merge(a, b);
        }
    }
    return 0;
}
