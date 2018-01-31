//http://codeforces.com/problemset/problem/118/A

#include <string>
#include <iostream>

using namespace std;

string stringTask(string str){
    string vowels = "AOYEUIaoyeui";
    string result = ".";

    for(int i = 0; i < str.size(); i++){
        int flag = 1;
        for(int j = 0; j < vowels.size(); j++){
            if(str[i] == vowels[j]){
                flag = 0;
                break;
            }
        }
        if(flag){

            if(isupper(str[i])) {
                result.push_back((char)(str[i] + 32));
            }else {
                result.push_back(str[i]);
            }
            result.push_back('.');
        }
    }
    if(result.size()!=1) {
        result.erase(result.size() - 1, 1);
    }
    return result;
}

int main(){
  string str;  
  cin >> str;
  cout << stringTask(str);
  return 0;
}
