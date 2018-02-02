//http://codeforces.com/problemset/problem/112/A
#include <iostream>
#include <string>

using namespace std;

void standard(string &str) {
    for (auto &c : str) {
        if (c >= 'A' && c <= 'Z') {
            c += ('a' - 'A');
        }
    }
}

int main() {
    string str1;
    string str2;
    cin >> str1;
    cin >> str2;
    standard(str1);
    standard(str2);
    if(str1 < str2){
        cout << -1;
    }else{
        if(str1 > str2){
            cout << 1;
        }else{
            cout << 0;
        }
    }
    return 0;
}
