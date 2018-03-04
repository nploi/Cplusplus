//http://codeforces.com/contest/20/problem/C

/*
@author
 - loinp
@date
 - 1/03/2018
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define GRAPH vector<vector<pair<long, ll> > >

void dijkstra(const GRAPH &graph, vector<long> &path) {

    priority_queue<pair<ll, int >, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
    vector<ll> dist(graph.size(), LLONG_MAX);

    pq.push(pair<ll, int> (0, 1));
    path[1] = 0;
    dist[1] = 0;

    while (!pq.empty()) {

        pair<ll, int> top = pq.top();
        pq.pop();

        int node = top.second;
        ll d = top.first;

        for (int i = 0; i < graph[node].size(); ++i) {
            pair<ll, int> neigbour = graph[node][i];

            if (d + neigbour.second < dist[neigbour.first]) {

                dist[neigbour.first] = d + neigbour.second;
                pq.push(pair<ll, long> (dist[neigbour.first], neigbour.first));
                path[neigbour.first] = node;
            }
        }
    }
}

void printer(const vector<long> &path, long end){

    if(path[end] == -1){
        cout << -1;
        return;
    }

    vector<long> p;

    while (true) {
        p.push_back(end);
        end = path[end];
        if (end == 1) {
            p.push_back(1);
            break;
        }
    }

    for (int i = p.size() - 1; i >= 0 ; --i) {
        cout << p[i] << " ";
    }
}

int main() {

    GRAPH graph;
    vector<long> path;
    long n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    path.resize(n + 1, -1);

    while (m--) {
        long long i, j, w;
        cin >> i >> j >> w;
        graph[i].push_back(pair<int, ll> (j, w));
        graph[j].push_back(pair<int, ll> (i, w));
    }

    dijkstra(graph, path);

    printer(path, n);

    return 0;
}
