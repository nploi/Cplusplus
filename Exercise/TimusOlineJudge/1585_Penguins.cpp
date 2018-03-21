//http://acm.timus.ru/problem.aspx?num=1585

/*
+@author
+ - loinp
+@date
+ - 19/03/2018
+*/

#include <map>
#include <string>
#include <iostream>

using namespace std;


int main() {


    int n;
    cin >> n;
    std::map<string, int> Map;
    cin.ignore();
    while(n--){
        string str;
        getline(cin, str);
        map<string, int>::iterator i = Map.find(str);
        if(i != Map.end()){
            Map[str] +=1;
        }else{
            pair<string, int> p = pair<string, int>(str, 1);
            Map.insert(p);
        }
    }


    int max = -1;
    string result;
    map<string, int>::iterator j;
    for ( j = Map.begin(); j != Map.end(); j++){
        if(j->second > max){
            max = j->second;
            result = j->first;
        }
    }

    cout << result << endl;

    return 0;
}
