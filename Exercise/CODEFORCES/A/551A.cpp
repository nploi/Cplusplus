//
// Created by nguyenphucloi on 1/18/18.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return (a > b);
}
int main(){
    vector<int> a, rates, _sort;
    int n;
    cin >> n;
    a.resize(n);
    rates.resize(2001, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        _sort.push_back(a[i]);
    }

    sort(_sort.begin(), _sort.end(), cmp);

    rates[_sort[0]] = 1;

    for (int i = 1; i < n; ++i) {
        if(_sort[i] != _sort[i - 1]){
            rates[_sort[i]] = i + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << rates[a[i]] <<" ";
    }

    return 0;
}