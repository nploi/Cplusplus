//http://codeforces.com/problemset/problem/279/B

#include <iostream>
#include <vector>

using namespace std;

int main1() {
    vector<long> arr;
    long n, t, sum = 0, start, end, r, l, count = 0;
    cin >> n >> t;
    start = 0;
    end = n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long countTemp = 0;
    for (start = l = 0; l < end; l++) {
        sum += arr[l];
        countTemp++;
        while(start < end && sum > t){
            sum -= arr[start];
            start++;
            countTemp--;
        }
        if (sum <= t) {
            count = ((count > countTemp) ? count : countTemp);
        }
    }

    cout << count;
    return 0;
}