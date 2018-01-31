//http://codeforces.com/problemset/problem/90/B 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string aficanCrossword(const vector<string> &table, int n, int m){
    string result;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int flag = 1;
            for(int k = 0; k < n; k++){
                if(table[i][j] == table[k][j] && k != i){
                    flag = 0;
                }
            }
            if(flag == 0){
                continue;
            }
            for(int k = 0; k < m; k++){
                if(table[i][j] == table[i][k] && k != j){
                    flag = 0;
                }
            }
            if(flag == 1){
                result.push_back(table[i][j]);
            }
        }
    }

    return result;
}

int main(){
    vector<string> table;
    unsigned int n, m;
    cin >> n >> m;

    table.resize(n);

    for (int i = 0; i < n; i++){
        cin >>table[i];
    }

    cout << aficanCrossword(table, n, m);

    return 0;
}
