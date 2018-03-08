//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499

/*
@author
 - loinp
@date
 - 8/03/2018
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct triad{
    int cource;
    int target;
    int time;
};


bool bellmanFord(int n, int m, const vector<triad> &graph, vector<int> &dist) {
    dist[0] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            triad t;
            t.cource = graph[j].cource;
            t.target = graph[j].target;
            t.time = graph[j].time;

            if (dist[t.cource] != INF && (dist[t.cource] + t.time < dist[t.target])) {
                dist[t.target] = dist[t.cource] + t.time;
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        triad t;
        t.cource = graph[j].cource;
        t.target = graph[j].target;
        t.time = graph[j].time;

        if (dist[t.cource] != INF && (dist[t.cource] + t.time) < dist[t.target]) {
            return true;
        }
    }

    return false;
}


int main() {

    int c;
    cin >> c;

    while (c--) {
        vector<triad> graph;
        vector<int> dist;
        int n, m;
        cin >> n >> m;

        dist.resize(n, INF);
        int mt = m;
        while (m--) {
            triad t;
            cin >> t.cource;
            cin >> t.target;
            cin >> t.time;
            graph.push_back(t);
        }

        if (bellmanFord(n, mt, graph, dist)) {
            cout << "possible\n";
        } else {
            cout << "not possible\n";
        }

    }
    return 0;
}
