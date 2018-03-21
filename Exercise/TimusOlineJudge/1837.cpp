//http://acm.timus.ru/problem.aspx?space=1&num=1837

/*
+@author
+ - loinp
+@date
+ - 19/03/2018
+*/

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

#define  INF 1e9

using namespace std;

int dijkstra(const vector<vector<int> > &graph,vector<int> &dist,  int source) {
    priority_queue<pair<int, int> > pq;

    dist[source] = 0;
    pq.push(pair<int, int>(1, source));

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        for (int i = 0; i < graph[top.second].size(); ++i) {
            pair<int, int> temp = pair<int, int>(graph[top.second][i], 1);

            if (top.first + temp.second < dist[temp.first]) {
                dist[temp.first] = top.first + temp.second;
                pq.push(pair<int, int>(dist[temp.first], temp.first));
            }
        }
    }
}


int main() {

    int n, k = 1;
    cin >> n;
    map<string, int> m;
    vector<vector<int> > graph;
    graph.resize(5000);
    vector<string> ListStr;
    ListStr.resize(3);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> ListStr[j];
            if (m.find(ListStr[j]) == m.end()) {

                if (ListStr[j] == "Isenbaev") {
                    m.insert(pair<string, int>(ListStr[j], 0));
                } else {
                    m[ListStr[j]] = k++;
                }
            }
        }

        int i1 = m[ListStr[0]], i2 = m[ListStr[1]], i3 = m[ListStr[2]];

        graph[i1].push_back(i2);
        graph[i1].push_back(i3);
        graph[i2].push_back(i1);
        graph[i2].push_back(i3);
        graph[i3].push_back(i1);
        graph[i3].push_back(i2);


    }
    vector<int> dist(graph.size(), INF);
    map<string, int>::iterator i;

    dijkstra(graph, dist, 0);

    for (i = m.begin(); i != m.end(); i++) {
        int d = dist[i->second];
        cout << i->first;
        if (d >= 0 && d != INF) {
            if (d == 0) {
                cout << " " << 0 << endl;
            } else {
                cout << " " << d - 1 << endl;
            }
        } else {
            cout << " undefined" << endl;
        }
    }

    return 0;
}
