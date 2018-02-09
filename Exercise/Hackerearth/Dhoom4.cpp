//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/dhoom-4/description/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long BFS(long start, long end, vector<long> listKey) {
    queue<long> Queue;
    vector<long> dist(100001, -1);

    Queue.push(start);

    dist[start] = 0;
    while (!Queue.empty()) {
        long q = Queue.front();
        Queue.pop();

        for (int i = 0; i < listKey.size(); ++i) {
            long x = ((q * listKey[i]) % 100000);
            if (dist[x] == -1) {
                dist[x] = dist[q] + 1;
                Queue.push(x);
            }
        }

        if(q == end){
            break;
        }

    }

    return dist[end];
}

int main(){
    int keyStart, keyEnd, n;
    vector<long> listKey;
    cin >> keyStart >> keyEnd;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        listKey.push_back(val);
    }
    cout << BFS(keyStart, keyEnd, listKey);
    return 0;
}
