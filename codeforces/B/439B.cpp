//
// http://codeforces.com/problemset/problem/439/b
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long


int main() {
    vector<ll> c;
    ll n, x;
    cin >> n >> x;
    c.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    sort(c.begin(), c.end());

    ll time = c[0] * x;

    for (int i = 1; i < n; ++i) {
        if (x != 1) {
            x--;
        }
        time += x * c[i];
    }

    cout << time;
    return 0;
}