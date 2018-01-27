//
// http://codeforces.com/problemset/problem/451/B
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr, b;
    int n;
    int x, y;
    cin >> n;
    arr.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        b[i] = arr[i];
    }
    sort(b.begin(), b.end());

    int i = 0, j = n - 1 ,L = -1, R = -1;
    while (i < j) {
        if (arr[i] != b[i] && L==-1) L = i;
        if (arr[j] != b[j] && R==-1) R = j;
        if(L==-1) i++;
        if(R==-1) j--;
        if(L!=-1&&R!=-1)
            break;
    }

    if (R != L) {
        int l = L, r = R;
        x = L;
        y = R;
        while (l < r) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
        int flag = 1;
        for (int k = 0; k < n; k++) {
            if (arr[k] != b[k])
                flag = false;
        }
        if (flag) {
            cout << "yes\n" << L + 1 << " " << R + 1;
        } else {
            cout << "no";
        }
    } else {
        if (L == R) {
            cout << "yes\n1 1";
        }

    }

    return 0;
}