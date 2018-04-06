//https://www.hackerrank.com/challenges/balanced-brackets/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

map<char, char> m;

bool checkBalanced( string &str){
    stack<char> s;

    for (int i = 0; i < str.size(); ++i) {
        if(m.find(str[i]) != m.end()) {
            if(!s.empty() && s.top() == m[str[i]]) {
                s.pop();
            }else{
                return false;
            }
        }else{
            s.push(str[i]);
        }
    }
    return s.empty();
}

int main() {

    m.insert(make_pair(')', '('));
    m.insert(make_pair('}', '{'));
    m.insert(make_pair(']', '['));

    stack<char> s;
    int n;
    cin >> n;

    while(n--){
        string str;
        cin >> str;
        cout << (checkBalanced(str)?"YES":"NO") << endl;
    }
    
    return 0;
}
