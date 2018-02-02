#include <gtest/gtest.h>
#include <gmock/gmock.h>

//int main(int argc, char *argv[]){
//    testing::InitGoogleTest(&argc, argv);
//    RUN_ALL_TESTS();
//    return 0;
//}

#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool isAlphabet(char c) {
    return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}


string standard(string str){
    string result;
    while(str[0]==';' ||str[0]=='_' || str[0] == '-'){
        str.erase(0, 1);
    }

    while(str[str.size() - 1]==';' ||str[str.size() - 1]=='_' || str[str.size() - 1] == '-'){
        str.erase(str.size() - 1, 1);
    }

    for(int i = 0; i < str.size(); i++){
        if(isAlphabet(str[i])){
            result.push_back(str[i]);
        }
    }

    return result;
}

bool check(string str,const vector<string> &arrStr) {

    int index = -1;
    for (int i = 0; i < 3; i++) {
        if (str[0] == arrStr[i][0] || str[0] == (arrStr[i][0] + 32) ||
            str[0] == (arrStr[i][0] - 32)) {
            index = i;
            break;
        }
    }

    int i = 0;

    while (true) {

        if (index == -1 || str.empty() && i >= str.size())
            break;

        int j = i, k = 0;
        while (k < arrStr[index].size() &&
               str[0] == arrStr[index][k] ||
               str[0] == (arrStr[index][k] + 32) ||
               str[0] == (arrStr[index][k] - 32)) {

            str.erase(0, 1);
            k++;
        }

        if (k < arrStr[index].size() - 1)
            return false;

        index = -1;
        for (j = 0; j < 3; j++) {
            if (str[0] == arrStr[j][0] ||
                str[0] == (arrStr[j][0] + 32) ||
                str[0] == (arrStr[j][0] - 32)) {
                index = j;
                break;
            }
        }
        i++;
    }

    if (str.empty())
        return true;
    return false;
}

int main() {

    vector<string> arrStr;
    int n;
    arrStr.resize(3);
    for (int i = 0; i < 3; i++) {
        string str;
        cin >> str;
        arrStr[i] = standard(str);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        str = standard(str);
        cout << ((check(str, arrStr)) ? "ACC" : "WA") << "\n";
    }
    return 0;
}