//http://codeforces.com/problemset/problem/169/A

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> arr;
    int n, a, b;
    cin >> n >> a >> b;
    arr.resize(n);

    for(int i =0 ;i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cout <<(arr[b] - arr[b-1]);

    return 0;
}