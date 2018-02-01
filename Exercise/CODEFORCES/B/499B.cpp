//http://codeforces.com/problemset/problem/499/B

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define matrix vector < vector <string> >

vector<string> Lecture(unsigned int n, unsigned int m, const vector < vector <string> > &table, const vector<string> &arrStr) {
    vector<string> result;

    result.resize(n);

    for (int i = 0; i < n; i++) {
        int index = -1, j;
        for (j = 0; j < m; j++) {
            if (arrStr[i] == table[j][0]) {
                index = 0;
                break;
            }
            if (arrStr[i] == table[j][1]){
                index = 1;
                break;
            }
        }
        if (index != -1) {

            int pos ;
            if(index == 0 && (table[j][0].size()) <= table[j][1].size()){
                pos = 0;
            }else {
                pos = 1;
            }
            result[i] =  table[j][pos];
        }

    }

    return result;
}

int main() {
    vector < vector <string> > table;
    vector<string> arrStr, temp;
    unsigned int n = 4, m = 3;
    cin >> n >> m;
    table.resize(m);
    for(int i = 0; i < m; i++){
        string str;
        cin >> str;
        table[i].push_back(str);
        cin >> str;
        table[i].push_back(str);
    }
    for (int j = 0; j < n; ++j) {
        string str;
        cin >> str;
        arrStr.push_back(str);
    }

    vector<string> actual = Lecture(n, m, table, arrStr);

    for (int i = 0; i < n; ++i) {
        cout << actual[i] << " ";
    }
    return 0;
}
