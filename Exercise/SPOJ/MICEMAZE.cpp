//http://www.spoj.com/problems/MICEMAZE/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define GRAPH vector<vector<pair<int, int> > >

using namespace std;

int dijkstra(const GRAPH &graph, int exit, int start){
    vector<int> distance(graph.size(), INT16_MAX);
    priority_queue<pair<int, int> > pq;

    pq.push(pair<int, int> (0, start));
    distance[start] = 0;

    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();

        int node = top.second;
        int dist = top.first;

        for (int i = 0; i < graph[node].size(); ++i) {
            pair<int, int> temp = graph[node][i];
            if(dist + temp.second < distance[temp.first]){
                distance[temp.first] = dist + temp.second;
                pq.push(pair<int, int>((distance[temp.first]), temp.first));
            }
        }

    }
    return distance[exit];
}

int main(){
    GRAPH graph;
    int n, e, t, m;
    cin >> n >> e >> t >> m;
    graph.resize(n+1);

    while(m--){
        int a, b, time;
        cin >> a >> b >> time;
        pair<int, int> p(b, time);
        graph[a].push_back(p);
    }

    int count = 0;
    for (int i = 1; i <= n; ++i) {
        int result = dijkstra(graph, e, i);
        if(result<=t){
            count++;
        }
    }

    cout << count;

    return 0;
}
