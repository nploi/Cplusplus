//http://codeforces.com/problemset/problem/918/A

#include <iostream>
#include <string>

using namespace std;

int main() {

    unsigned int n;

    cin >> n;

    string Eleven(n, 'o');

    int previous = 1, current = 1;
    int i = 0;

    while (i < n) {

        if (current <= n) {
            Eleven[current - 1] = 'O';
        }

        int newFib = previous + current;
        previous = current;
        current = newFib;

        i++;

    }

    if (current <= n) {
        Eleven[current - 1] = 'O';
    }

    cout << Eleven;

    return 0;
}
