//http://www.spoj.com/problems/TRVCOST/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

#define MAX 501
const int INF = 1e9;

using namespace std;

void dijkstra(const vector<vector<pair<int, int> > > &graph, vector<int> &distance, int from) {
    priority_queue<pair<int, int> > pq;
    pq.push(pair<int, int>(0, from));
    distance[from] = 0;

    while (!pq.empty()) {

        pair<int, int> top = pq.top();
        pq.pop();

        int node = top.second;
        int distTop = top.first;

        for (int i = 0; i < graph[node].size(); ++i) {
            pair<int, int> neigh = graph[node][i];
            if ((distTop + neigh.second) < distance[neigh.first]) {
                distance[neigh.first] = distTop + neigh.second;
                pq.push(pair<int, int>((distance[neigh.first]), neigh.first));
            }
        }
    }
}

int main() {
    int n, a, b, w, u, q, v;

    vector<vector<pair<int, int> > > graph;
    vector<int> distance(503, INF);

    cin >> n;
    graph.resize(503);
    while (n--) {
        cin >> a >> b >> w;
        pair<int, int> p(b, w);
        pair<int, int> p1(, w);
        graph[a].push_back(p);
        graph[b].push_back(p1);
    }

    cin >> u; //start

    cin >> q; //number of queries

    dijkstra(graph, distance, u);

    while (q--) {
        cin >> v;
        int result = distance[v];
        if (result != INF) {
            cout << distance[v] << endl;
        } else {
            cout << "NO PATH" << endl;
        }
    }

    return 0;
}
