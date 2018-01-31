//
// Created by nguyenphucloi on 1/18/18.
//http://www.spoj.com/problems/ONP/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
using namespace std;

int isNumber(char c) {
    return (c >= 'a' && c <= 'z');
}

string toPostfix(string infix) {
    string result;
    int i = 0;
    stack<char> operators;
    while (i < infix.size()) {
        if (infix[i] == '(') {
            operators.push(infix[i]);

        } else {

            if (isNumber(infix[i])) {

                result.push_back(infix[i]);

            } else {
                if(infix[i]==')') {
                    while (!operators.empty()) {
                        if (operators.top() == '(') {
                            operators.pop();
                            break;
                        }
                        result.push_back(operators.top());
                        operators.pop();
                    }
                }else{
                    operators.push(infix[i]);
                }
            }
        }

        i++;
    }
    while (!operators.empty()) {
        if (operators.top() == '(') {
            operators.pop();
            break;
        }
        result.push_back(operators.top());
        operators.pop();
    }

    return result;
}

int main() {

    vector<string> arrayPostfix;
    int n;
    cin >> n;
    arrayPostfix.resize(n);
    for (int i = 0; i < n; i++) {

        string infix;

        cin >> infix;

        cout << toPostfix(infix) << "\n";
    }

    return 0;
}
