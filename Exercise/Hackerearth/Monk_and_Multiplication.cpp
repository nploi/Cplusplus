//https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-multiplication/
#include<iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){

    priority_queue<int> pq;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        pq.push(val);
        if(i-2 < 0){
            cout << "-1\n";
        }else{
            long long top1 = pq.top();
            pq.pop();
            long long top2 = pq.top();
            pq.pop();

            cout << top1 * top2 * pq.top() << endl;
            pq.push(top1);
            pq.push(top2);
        }
    }
    return 0;
}
