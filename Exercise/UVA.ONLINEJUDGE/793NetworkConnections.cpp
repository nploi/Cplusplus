//https://uva.onlinejudge.org/index.php?Itemid=8&option=com_onlinejudge&page=show_problem&problem=734


#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class DSU{

public:
    DSU(){
        /*
         * can more 10000
         */
        par.resize(1005, 0);
    }

    DSU(int n){
        par.resize( n + 1, 0);
    }

    void reSize(int n){
        par.resize(n + 1, 0);
    }

    /*
     * Find root of leaf
     */
    int getRoot(int i){
        return (par[i] <= 0) ? i : par[i] = getRoot(par[i]);
    }

    /*
     * merge
     */
    void merge(int i, int j){
        int x = getRoot(i), y = getRoot(j);
        if(x == y){
            return;
        }
        if(par[i] < par[j]){
            swap(i, j);
        }
        par[i] += par[j];
        par[j] = i;
    }

    ~DSU(){
        par.clear();
    }
private:
    vector<int> par;
};

int main() {
    int t;

    cin >> t;

    while (t--) {

        int n, fail = 0, success = 0;
        char operatorr;
        string str;
        DSU d;

        cin >> n;
        cin.ignore();
        while (getline(cin, str)) {
            int i, j;
            if (str.empty()) {
                break;
            }

            istringstream in(str);
            in >> operatorr >> i >> j;

            if (operatorr == 'c') {
                d.merge(i, j);
            } else {

                if (d.getRoot(i) == d.getRoot(j)) {
                    success++;
                } else {
                    fail++;
                }
            }
        }
        cout << success << "," << fail;
        if (t > 0)
            cout << endl << endl;
        else
            cout << endl;
    }
    return 0;
}
