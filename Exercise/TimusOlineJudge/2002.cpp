//http://acm.timus.ru/problem.aspx?space=1&num=2002

/*
+@author
+ - loinp
+@date
+ - 22/03/2018
+*/

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

#define  INF 1e9

using namespace std;

int main() {
    map<string, pair<string, pair<int, int> > > hashTable;

    int n;
    cin >> n;
    while (n--) {
        string func, user, pwd, message;
        cin >> func >> user;

        if (func == "register") {
            cin >> pwd;
            if (hashTable.find(user) != hashTable.end()) {
                message = "fail: user already exists";
                continue;
            }
            message = "success: new user added";
            hashTable[user] = pair<string, pair<int, int> >(pwd, {0, 0});
        } else {
            if (func == "login") {
                cin >> pwd;
                if (hashTable.find(user) == hashTable.end()) {
                    message = "fail: no such user";
                } else {s
                    if (hashTable[user].first != pwd) {
                        message = "fail: incorrect password";
                    } else {
                        if (hashTable[user].second.first == true) {
                            message = "fail: already logged in";
                        } else {
                            hashTable[user].second.first = true;
                            message = "success: user logged in";
                        }
                    }
                }
            } else {
                if (hashTable.find(user) == hashTable.end()) {
                    message = "fail: no such user";
                } else {
                    if (hashTable[user].second.second == true) {
                        message = "fail: already logged out";
                    } else {
                        hashTable[user].second.second = true;
                        message = "success: user logged out";
                    }
                }
            }
        }
        cout << message << endl;
    }

    return 0;
}
