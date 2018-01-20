//
// Created by nguyenphucloi on 1/18/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define ll long long

int main() {

    vector<double> a;
    double n, w;
    double result;
    cin >> n >> w;
    a.resize(n * 2);

    for (int i = 0; i < n * 2; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    if(w > a[n]) {
        double mof = a[n] / 2, m;
        if (mof <= a[n - 1]) {
            m = a[n];
        } else {
            m = a[n - 1];
        }

        result = m * n + (m / 2) * n;

        while (result > w) {
            m = m - 0.1;
            result = m * n + (m / 2) * n;
        }
    }else{
        if(w < a[n] && w < a[n-1]) {
            double m = (double)w/(double)2;
            result = m * n + (m / 2) * n;
            while(result > w){
                m = m - 0.1;
                result = m * n + (m / 2) * n;
            }
            result = round(result);
        }
    }
    cout << result;

    return 0;
}
