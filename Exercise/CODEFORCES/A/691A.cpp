#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, flag = 1, c[2] = {0, 0}, temp;

    cin >> n;
    flag = n;
    if(n==1){
        cin >> temp;
        if(temp == 0){
            flag = 0;
        }
    }else {
        for (int i = 0; i < n; i++) {
            cin >> temp;
            c[temp]++;

            if(c[0] > 1){
                flag = 0;
            }
            if (c[0] == 1 && c[1] == n - 2) {
                flag = 1;
            }
        }
        if(c[1] == n ){
            flag = 0;
        }
    }


    cout<<((flag)?"YES":"NO");
    return 0;
}
