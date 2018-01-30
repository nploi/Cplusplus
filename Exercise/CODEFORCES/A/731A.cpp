#include <iostream>
#include <string>

using namespace std;


int rotateRight(string &str, char stop){
    char temp;
    int count = 0;
    for(int i = str.size() - 1; i >= 0 && str[0] != stop; i--){
        temp = str[str.size() - 1];
        for(int j = str.size() - 1; j > 0; j--){
            str[j] = str[j - 1];
        }
        str[0] = temp;

        count++;
    }
    return count;
}

int rotateLeft(string &str, char stop){

    char temp;
    int count = 0;
    for(int i = 0; i < str.size()  && str[0] != stop; i++){
        temp = str[0];
        for(int j = 0; j < str.size() - 1; j++){
            str[j] = str[j + 1];
        }
        str[str.size() - 1] = temp;

        count++;
    }
    return count;
}

int nightAtTheMuseum(string str){
    string AZ("abcdefghijklmnopqrstuvwxyz");
    //121
    int size = str.size();
    int sum = 0;
    for(int i = 0; i < size; i++){
        int pos = AZ.find(str[i]);
        if(pos > 13){
           sum += rotateRight(AZ, str[i]);
        }else{
            sum += rotateLeft(AZ, str[i]);
        }
    }
    return sum;
}


int main(){
    string str;
    cin >> str;
    cout << nightAtTheMuseum(str);
    return 0;
}
