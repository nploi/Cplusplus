//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1895

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

    int n;

    priority_queue<long, vector<long>, greater<long> > pq;

    do {

        cin >> n;

        for (int i = 0; i < n; ++i) {

            int val;
            cin >> val;
            pq.push(val);
        }

        long total = 0;

        while (pq.size() >= 2) {

            long top1, top2;

            top1 = pq.top();
            pq.pop();

            top2 = pq.top();
            pq.pop();

            total += top1 + top2;

            pq.push(top1 + top2);

        }

        if (n == 0) {
            break;
        }

        cout << total << endl;
        pq.pop();

        while (!pq.empty()) {
            pq.pop();
        }

    } while (n != 0);
    
    return 0;
}
