//https://www.hackerrank.com/challenges/dynamic-array/problem

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int> > seq(n);
    int lastAnswer = 0;
    while (q--) {
        int c, x, y;
        cin >> c >> x >> y;
        int i = (x ^ lastAnswer) % n;

        if (c == 1) {
            seq[i].push_back(y);
        } else {
            lastAnswer = seq[i][y % seq[i].size()];
            cout << lastAnswer << endl;
        }
    }
    return 0;
}
