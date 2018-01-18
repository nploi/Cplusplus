#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> ar;
    int n, minute = 90;
    cin >> n ;

    for(int i = 0; i < n ; i++){
        int val;
        cin >> val;
        ar.push_back(val);
    }
    if(n >= 1){
        if(ar[0] > 15){
            minute = 15;
        }else {

            for (int i = 0; i < n - 1; i++) {
                if ((ar[i + 1] - ar[i]) > 15) {
                    minute = ar[i] + 15;
                    break;
                }
            }
        }
        if(n==1 && ar[0] < 15){
            minute = ar[0] + 15;
        }
        if(minute == 90) {
            if (ar[n - 1] < 75) {
                minute = ar[n - 1] + 15;
            }
        }
    }



    cout << minute;

    return 0;
}
