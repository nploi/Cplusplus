//https://www.hackerrank.com/challenges/crush/problem


#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n, m, max = -1, t = 0;
    cin >> n >> m;

    vector<ll> v(n + 1, 0);

    while (m--) {
        ll a, b, k;
        cin >> a >> b >> k;
        v[a] += k;
        if (b + 1 <= n) {
            v[b + 1] -= k;
        }
    }
    for (int i = 1; i <= n; ++i) {
        t += v[i];
        if (t > max) {
            max = t;
        }
    }
    cout << max;

    return 0;
}
