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

    for(int i = 0; i < arrStr.size(); i++){

        if(str == arrStr[i]){
            return true;
        }

    }
    return false;
}

int main() {

    vector<string> arrStr, arrStr2;
    int n;
    arrStr.resize(3);
    for (int i = 0; i < 3; i++) {
        string str;
        cin >> str;
        arrStr[i] = standard(str);
    }

    arrStr2.resize(6);

    arrStr2[0] = arrStr[0] +  arrStr[1] +  arrStr[2];
    arrStr2[1] = arrStr[0] +  arrStr[2] +  arrStr[1];
    arrStr2[2] = arrStr[1] +  arrStr[0] +  arrStr[2];
    arrStr2[3] = arrStr[1] +  arrStr[2] +  arrStr[0];
    arrStr2[4] = arrStr[2] +  arrStr[0] +  arrStr[1];
    arrStr2[5] = arrStr[2] +  arrStr[1] +  arrStr[0];  
        
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        str = standard(str);
        cout << ((check(str, arrStr2)) ? "ACC" : "WA") << "\n";
    }
    return 0;
}
