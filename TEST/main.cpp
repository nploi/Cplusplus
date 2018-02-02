#include <gtest/gtest.h>
#include <gmock/gmock.h>

//int main(int argc, char *argv[]){
//    testing::InitGoogleTest(&argc, argv);
//    RUN_ALL_TESTS();
//    return 0;
//}

using namespace std;

string hardWork(const vector<string> &arrStr, const vector<string> &arrStr2){
    return "";
}

bool isAlphabet(char c) {
    return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}

string standard(string str){
    string result;
    while(str[0]==';' ||str[0]=='_' ){
        str.erase(0, 1);
    }
    while(str[str.size() - 1]==';' ||str[str.size() - 1]=='_' ){
        str.erase(str.size() - 1, 1);
    }
    for(int i = 0; i < str.size(); i++){
        if(isAlphabet(str[i])){
            result.push_back(str[i]);
        }
    }
    return result;
}

bool check(string str,const vector<string> &arrStr){
    int index = -1;
    for(int i =0 ;i < 3; i++){
        if(str[0] == arrStr[i][0]){
            index = i;
        }
    }


    int i = 0;

    while(true){
        if(index == -1 || str.empty())
            break;
        int j = i, k = 0;
        while(str[0] == (arrStr[index][k] + 32) || str[0] == (arrStr[index][k] - 32)){
            str.erase(0, 1);
            k++;
        }
        index = -1;
        for(j = 0 ; j < 3; j++){
            if(str[i] == arrStr[j][i]){
                index = i;
            }
        }
        i++;
    }
    if(str.empty())
        return true;
    return false;
}

int main(){

    vector<string> arrStr;
    int n;
    arrStr.resize(3);
    for (int i = 0; i < 3; i++) {
        string str;
        cin >> str;
        arrStr[i] = standard(str);
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        str = standard(str);
        cout << ((check(str, arrStr)) ?"ACC":"WA") << "\n";
    }
    return 0;
}