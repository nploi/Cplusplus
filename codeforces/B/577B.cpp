//
// Created by nguyenphucloi on 1/18/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


int main() {

    vector<double> a;
    int n, w;
    double m;
    double result;
    cin >> n >> w;
    a.resize(n * 2);

    for (int i = 0; i < n * 2; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    result = 3*n*min(a[0], a[n]/2);

    if(result > w){
        result = w;
    }

    cout << result;

    return 0;
}
