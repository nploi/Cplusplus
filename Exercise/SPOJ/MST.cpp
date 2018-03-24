//http://www.spoj.com/problems/MST/

/*
+@author
+ - loinp
+@date
+ - 24/03/2018
+*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define GRAPH vector<vector<pair<int, int> > >
#define INF 1e9
using namespace std;

long long Cost(const vector<long> &dist, const vector<int> &path){
    long long result = 0;
    for (int i = 0; i < dist.size(); ++i) {
        if(path[i] == -1){
            continue;
        }
        result += dist[i];
    }
    return result;
}

long long prims(const GRAPH &graph, int s){
    vector<long> dist(graph.size(), INT64_MAX);
    vector<bool> visit(graph.size(), 0);
    vector<int> path(graph.size(), -1);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    dist[s] = 0;
    pq.push(make_pair(0, s));

    while (!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        visit[top.second] = true;

        for (int i = 0; i < graph[top.second].size(); ++i) {
            int v = graph[top.second][i].first;
            int w = graph[top.second][i].second;

            if(!visit[v] && w < dist[v]){
                dist[v] = w;
                pq.push(make_pair(w, v));
                path[v] = top.second;
            }

        }

    }

    return Cost(dist, path);
}

int main(){

    long t, x;
    cin >> t;
    while(t--) {
        GRAPH graph;
        int n, m;

        cin >> x >>  n >> m;

        graph.resize(n + 1);

        while (m--) {
            long i, j, k;
            cin >> i >> j >> k;
            graph[i].push_back(pair<int, int>(j, k));
            graph[j].push_back(pair<int, int>(i, k));   
        }

        int s = 1;
        cout << (long long)(prims(graph, s) * x);
    }
    return 0;
}
