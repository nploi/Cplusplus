//http://www.spoj.com/problems/PQUEUE/

/*
@author
 - loinp
@date
 - 1/03/2018
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

class mycomparison {
    bool reverse;
public:
    mycomparison(const bool &revparam = false) { reverse = revparam; }

    bool operator()(const int &lhs, const int &rhs) const {
        if (reverse) return (abs(lhs) > abs(rhs));
        else return (abs(lhs) < abs(rhs));
    }
};

int main() {

    int t;
    cin >> t;

    while (t--) {
        priority_queue<int, vector<int>, mycomparison> pq;
        queue<int> q;
        int m, n, i = 0;
        cin >> n >> m;
        while (n--) {

            int val;
            cin >> val;
            if (m == i) {
                val = -val;
            }
            pq.push(val);
            q.push(val);
            i++;
        }
        int count = 0;
        while (!q.empty()) {
            while (abs(pq.top()) > abs(q.front())) {
                q.push(q.front());
                q.pop();
            }
            count++;

            if (q.front() < 0) {
                cout << count << endl;
                break;
            } else {
                pq.pop();
                q.pop();
            }
        }
    }
}
