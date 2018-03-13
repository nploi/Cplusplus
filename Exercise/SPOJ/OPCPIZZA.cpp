//http://www.spoj.com/problems/OPCPIZZA/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findPair(const vector<int> &a, int x) {
    int left = 0, right = a.size() - 1, count = 0;

    while (left < right) {
        if (x == a[left] + a[right]) {
            count++;
            left++;
            right--;
            continue;
        }
        if (x - a[left] > a[right]) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        vector<int> f;
        cin >> n >> m;

        for (int i = 0; i < n; ++i) {
            int val;
            cin >> val;
            f.push_back(val);
        }
        sort(f.begin(), f.end());

        cout << findPair(f, m) << endl;
    }

    return 0;
}
