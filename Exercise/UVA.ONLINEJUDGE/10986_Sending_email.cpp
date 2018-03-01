//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927

/*
@author
 - loinp
@date
 - 28/02/2018
*/

#include <bits/stdc++.h>
using namespace std;

#define GRAPH vector<vector<pair<int, int> > >

const int INF = 1e7;

int dijkstra(const GRAPH &graph, int from, int to){

    vector<int> dist(graph.size(), INF);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    pq.push(pair<int, int>(0, from));
    dist[from] = 0;

    while (!pq.empty()){

        pair<int, int> top = pq.top();
        pq.pop();

        int node = top.second;
        int d = top.first;

        for (int i = 0; i < graph[node].size(); ++i) {
            pair<int, int> neighbour = graph[node][i];
            if(d + neighbour.second < dist[neighbour.first]){
                dist[neighbour.first] = d + neighbour.second;
                pq.push(pair<int, int>(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist[to];
}

int main() {
    int N, Case = 1;
    cin >> N;

    while (N--) {

        GRAPH graph;
        int n, m, s, t;
        cin >> n >> m >> s >> t;

        graph.resize(n);

        while (m--){
            int comPuter1, comPuter2, time;
            cin >> comPuter1 >> comPuter2 >> time;
            graph[comPuter1].push_back(pair<int, int>(comPuter2, time));
            graph[comPuter2].push_back(pair<int, int>(comPuter1, time));
        }

        int result = dijkstra(graph, s, t);
        if(result != INF) {
            cout << "Case #" << Case << ": " << result << endl;
        }else{
            cout << "Case #" << Case << ": unreachable" << endl;
        }
        Case++;
    }

    return 0;
}

