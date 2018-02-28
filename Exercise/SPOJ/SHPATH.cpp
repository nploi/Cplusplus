//http://www.spoj.com/problems/SHPATH/en/
/*
@author
 - loinp
@date
 - 28/02/2018
*/

#include <bits/stdc++.h>

using namespace std;

#define GRAPH vector<vector<pair<int, int> > >

int dijkstra(const GRAPH &graph, int from, int to) {

    vector<int> dist(graph.size(), INT8_MAX);

    /*
     * first: distance
     * second: city
    */
    priority_queue<pair<int, int> > pq;

    pq.push(pair<int, int>(0, from));
    dist[from] = 0;

    while (!pq.empty()) {

        pair<int, int> top = pq.top();
        pq.pop();

        int node = top.second;
        int d = top.first;

        for (int i = 0; i < graph[node].size(); ++i) {

            pair<int, int> neig = graph[node][i];

            if (d + neig.second < dist[neig.first]) {

                dist[neig.first] = d + neig.second;
                pq.push(pair<int, int>((dist[neig.first]), neig.first));
            }
        }
    }
    return dist[to];
}


int main() {


    int s;
    cin >> s;

    while (s--) {
        GRAPH graph;
        int n, p, nr, r;
        cin >> n;
        graph.resize(n + 1);

        /*
         * first: name of city
         * second: number of city
        */
        map<string, int> cities;
        for (int i = 1; i <= n; ++i) {

            string str;
            cin >> str;
            cities.insert(pair<string, int>(str, i));
            cin >> p;

            while (p--) {

                int neig, distance;
                cin >> neig >> distance;
                graph[i].push_back(pair<int, int>(neig, distance));

            }
        }

        cin >> nr;

        while (nr--) {

            int start, end;
            string cty1, cty2;
            cin >> cty1 >> cty2;

            /*
             * get number of cities
             */
            start = cities.find(cty1)->second;
            end = cities.find(cty2)->second;

            cout << dijkstra(graph, start, end) << endl;
        }

    }
    return 0;
}

