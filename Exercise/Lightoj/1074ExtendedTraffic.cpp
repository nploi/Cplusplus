//http://www.lightoj.com/volume_showproblem.php?problem=1074

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
    int earn;
};


bool bellmanFord(int n, int m, const vector<triad> &graph, vector<int> &dist) {
    dist[1] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            triad t;
            t.cource = graph[j].cource;
            t.target = graph[j].target;
            t.earn = graph[j].earn;

            if (dist[t.cource] != INF && (dist[t.cource] + t.earn < dist[t.target])) {
                dist[t.target] = dist[t.cource] + t.earn;
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        triad t;
        t.cource = graph[j].cource;
        t.target = graph[j].target;
        t.earn = graph[j].earn;

        if (dist[t.cource] != INF && (dist[t.cource] + t.earn) < dist[t.target]) {
            return false;
        }
    }

    return true;
}


int main() {

    int t, num = 1;
    cin >> t;

    while (t--) {

        vector<int> busyness;
        vector<triad> graph;
        vector<int> dist;

        unsigned int n, m, mt;

        cin >> n;
        busyness.resize(n + 1);
        dist.resize(n + 1, INF);

        for (int i = 1; i <= n; ++i) {
            cin >> busyness[i];
        }

        cin >> m;
        mt = m;

        while (mt--) {
            triad value;
            cin >> value.cource;
            cin >> value.target;

            value.earn = pow(busyness[value.target] - busyness[value.cource], 3);

            graph.push_back(value);
        }

        int q;
        cin >> q;
        bellmanFord(n, m, graph, dist);
        cout << "Case " << num++ << ":\n";
        while (q--) {
            int dest;
            cin >> dest;

            int total = dist[dest];
            if (total < 3 || total == INF) {
                cout << "?\n";
            } else {
                cout << total << endl;
            }
        }

    }
    return 0;
}
