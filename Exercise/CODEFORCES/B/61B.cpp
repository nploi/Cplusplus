//http://codeforces.com/problemset/problem/61/B
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
            if(str[i] <= 'Z' && str[i] >= 'A')
                str[i] += ('a' - 'A');
            result.push_back(str[i]);
        }
    }

    return result;
}

bool check(string str,const vector<string> &arrStr){
    int sumSize = 0, count = 0;

    for(int i = 0; i < 3; i++){

        if(str.find(arrStr[i]) != -1){
            count++;
            sumSize+=arrStr[i].size();
        }

    }

    if(sumSize == str.size()){
        return true;
    }

    if(sumSize == str.size()){
        return true;
    }
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