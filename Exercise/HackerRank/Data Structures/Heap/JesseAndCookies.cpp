//https://www.hackerrank.com/challenges/jesse-and-cookies/problem

#include<iostream>
#include <queue>
#include <vector>

using namespace std;

#define ll long long

int main() {
    
    priority_queue<ll, vector<ll>, greater<ll> > pq;

    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        ll val;
        cin >> val;
        pq.push(val);
    }

    ll sweetness = 0, count = 0, top1, top2;

    while(pq.size() >= 2 && pq.top() < k) {
        top1 = pq.top();
        pq.pop();
        top2 = pq.top();
        pq.pop();
        sweetness = top1 + 2 * top2;
        count++;
        pq.push(sweetness);
    };

    if(pq.top() < k){
        cout << "-1";
    }else {
        cout << count;
    }
    return 0;
}
