//
// Created by loinp on 04/04/2018.
//https://www.hackerrank.com/challenges/strong-password/problem

#include <iostream>
#include <queue>

using namespace std;

bool isSpecialChar(char c){
    string special_characters = "!@#$%^&*()-+";
    for (int i = 0; i < special_characters.size(); ++i) {
        if(c==special_characters[i]){
            return true;
        }
    }
    return false;
}

bool isNumber(char c){
    return (c >= '0' && c <= '9');
}

int main() {

    string passWord;
    int n;
    cin >> n;
    cin >> passWord;

    int length, digit, lowercase, uppercase, special, result;

    length = digit = lowercase = uppercase = special = result = 0;

    for (int i = 0; i < n; ++i) {
        digit += isNumber(passWord[i]);
        lowercase += islower(passWord[i]);
        uppercase += isupper(passWord[i]);
        special += isSpecialChar(passWord[i]);
    }

    if (digit == 0) {
        result++;
    }
    if (lowercase == 0) {
        result++;
    }
    if (uppercase == 0) {
        result++;
    }
    if (special == 0) {
        result++;
    }

    result = max(result, 6 - n);

    cout << result;

    return 0;
}