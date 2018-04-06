//https://www.hackerrank.com/challenges/maximum-element/problem


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    stack<int> s;
    int n, max = -1;
    cin >> n;
    while (n--) {
        int value, check;
        cin >> check;
        if (check == 1) {
            cin >> value;
            if (value > max) {
                max = value;
            }
            s.push(value);
        } else {
            if (check == 2) {
                if (s.top() == max) {
                    max = -1;
                    s.pop();
                    stack<int> st;
                    st.push(max);
                    while (!s.empty()) {
                        if (s.top() > max) {
                            max = s.top();
                        }
                        st.push(s.top());
                        s.pop();
                    }
                    while (!st.empty()) {
                        s.push(st.top());
                        st.pop();
                    }
                }
                s.pop();
            } else {
                cout << max << endl;
            }
        }
    }
    return 0;
}
