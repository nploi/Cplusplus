#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> ar;
    int n, h, w;
    cin >> n >> h;

    for(int i = 0 ; i < n ; i++){
        int val;
        cin >> val;
        ar.push_back(val);
    }
    w = 0;
    for(int i = 0; i < n ; i++){
        if(ar[i] > h) {
          w +=2;
        }else{
            w+=1;
        }
    }
    cout<< w;
    return 0;
}
