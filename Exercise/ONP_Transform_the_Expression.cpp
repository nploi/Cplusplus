//
// Created by nguyenphucloi on 1/18/18.
//http://www.spoj.com/problems/ONP/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
using namespace std;

int isOperators(char c) {
    if (c == '(' || c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return 1;
    }
    if (c >= 'a' && c <= 'z') {
        return 2;
    }
}



string toPostfix(string infix) {
    string result;
    int i = 0;
    stack<char> operators;
    while (i < infix.size()) {
        if (isOperators(infix[i]) == 1) {

            operators.push(infix[i]);

        } else {

            if (isOperators(infix[i]) == 2) {

                result.push_back(infix[i]);

            } else {

                while (!operators.empty()) {
                    if (operators.top() == '(') {
                        operators.pop();
                        break;
                    }
                    result.push_back(operators.top());
                    operators.pop();

                }

            }

        }

        i++;
    }
    while(!operators.empty()){
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

        arrayPostfix[i] = toPostfix(infix);

    }

    for (int j = 0; j < n; j++) {
        cout << arrayPostfix[j] <<"\n";
    }

    return 0;
}


