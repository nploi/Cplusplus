//http://www.spoj.com/problems/STPAR/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;

    do {
        stack<int> stack;
        vector<int> arr;
        cin >> n;
        int val, i = 0, flag = 1;
        int j = 0;
        if (n == 0) {
            break;
        }
        arr.clear();
        while (!stack.empty()) {
            stack.pop();
        }
        while (i < n) {
            cin >> val;
            if (val == j + 1) {
                arr.push_back(val);
                j++;
            } else {
                while (!stack.empty()) {
                    if (stack.top() == j + 1) {
                        arr.push_back(stack.top());
                        stack.pop();
                        j++;
                    } else {
                        break;
                    }

                }
                stack.push(val);
            }
            i++;
        }
        while (!stack.empty()) {
            if (stack.top() == j + 1) {
                arr.push_back(stack.top());
                stack.pop();
                j++;
            } else {
                flag = 0;
                break;
            }

        }
        cout << ((flag) ? "yes\n" : "no\n");
    } while (n != 0);

    return 0;
}
