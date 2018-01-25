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
    if (c >= 'a' && c <= 'z') {
        return 2;
    }
}

int preference(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    if(c == '(' || c == ')')
        return -1;
    return 0;
}


string toPostfix(string infix) {
    string result;
    int i = 0;
    stack<char> operators;
    while (i < infix.size()) {
        if (infix[i] == '(') {
            operators.push(infix[i]);

        } else {

            if (isNumber(infix[i]) == 2) {

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
                    if(preference(infix[i]) >= 1 && preference(infix[i]) <= 3){
                        while(!operators.empty() &&
                              preference(operators.top()) >= preference(infix[i]) &&
                              operators.top()!= ')'){

                            result.push_back(operators.top());
                            operators.pop();

                        }
                        operators.push(infix[i]);
                    }
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


