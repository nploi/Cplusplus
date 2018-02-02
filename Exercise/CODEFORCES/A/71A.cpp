//http://codeforces.com/problemset/problem/71/A
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string str;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> str;
        string strTemp;
        if (str.size() <= n && str.size() < 10) {
            cout << str << "\n";
        } else {
            if (str.size() > 10) {
                cout << str[0] << (str.size() - 2) << str[str.size() - 1] << "\n";
            } else {
                cout << str << "\n";
            }
        }

    }
    return 0;
}
