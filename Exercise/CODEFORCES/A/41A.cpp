//http://codeforces.com/problemset/problem/41/A

#include <iostream>
#include <string>

using namespace std;

void reverse(string &str) {

    int start = 0;
    int end = str.size() - 1;
    while (start < end){
        swap(str[start], str[end]);
        start++;
        end--;
    }

}

int main() {
    string str1;
    string str2;

    cin >> str1;
    reverse(str1);
    cin >> str2;

    cout << ((str2 == str1) ? "YES" : "NO");
    return 0;
}
