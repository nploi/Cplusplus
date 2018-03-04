//http://codeforces.com/problemset/problem/520/A
/*
@author
 - loinp
@date
 - 1/03/2018
*/

#include <bits/stdc++.h>

using namespace std;

void change(char & c) {
    if (c < 97) {
        c += 32;
    }
}

int main() {
    vector<bool> latin(25, 0);
    int n;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        change(c);
        latin[c-97] = true;
    }

    bool check = 1;
    for (int i = 0; i < 24; ++i) {
        if(latin[i]!=true){
            check = 0;
            break;
        }
    }

    cout << ((check) ? "YES" : "NO" );
    return 0;
}
