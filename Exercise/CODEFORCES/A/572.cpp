//link: http://codeforces.com/problemset/problem/572/A

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define for(i, n) for(int i=0;i<n;i++)

int main(){
    vector<int> arA, arB;

    int nA, nB, k, m;

    bool result = true;


    cin >> nA >> nB >> k >> m;

    for(i, nA){
        int val;
        cin >> val;
        arA.push_back(val);
    }

    for(i, nB){
        int val;
        cin >> val;
        arB.push_back(val);
    }
    int j = 0, c = 0;

    for(i, nB - m + 1){
        if(j + k - 1 < nA){
            if(arA[j + k - 1] >= arB[i]){
                c++;
                if(c==nB-m+1){
                    result = false;
                    break;
                }
                continue;
            }

        }
    }

    cout << ((result) ? "YES" : "NO");
    return 0;
}
