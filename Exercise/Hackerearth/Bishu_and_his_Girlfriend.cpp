//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/

#include<iostream>
#include<vector>
#include <stack>
using namespace std;


vector<int> DFS(int N, const vector<vector<int> > &graph, const vector<int> &QGirls){
    vector<int> result;
    vector<int> dist(N + 1, -1);
    stack<int> Stack;
    Stack.push(1);
    dist[1] = 0;

    while (!Stack.empty()) {
        int pos = Stack.top();
        Stack.pop();

        for (int i = 0; i < graph[pos].size(); ++i) {
            if (dist[graph[pos][i]] == -1) {
                dist[graph[pos][i]] = dist[pos] + 1;
                Stack.push(graph[pos][i]);

            }
        }
    }

    int min =  INT8_MAX;
    for(int i = 0; i < QGirls.size(); i++){
        if(QGirls[i] != 1 && dist[QGirls[i]] != -1 &&dist[QGirls[i]] < min){
            min = dist[QGirls[i]];
        }
    }

    for (int j = 0; j < QGirls.size(); ++j) {
        if (QGirls[j] != 1) {
            if (dist[QGirls[j]] != -1 && dist[QGirls[j]] == min) {
                result.push_back(QGirls[j]);
            }
        }
    }

    return result;

}

int accepted(int N, const vector<vector<int> > &graph, const vector<int> &QGirls){
    vector<int> Ids;
    Ids = DFS(N, graph, QGirls);

    int index = 0;
    for (int i = 1; i < Ids.size(); ++i) {
        if(Ids[i] < Ids[index]){
            index = i;
        }
    }
    return Ids[index];
}

int main(){
    vector<vector<int> > graph;
    vector<int> QGirls;
    int n, m;
    cin >> n;
    graph.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cin >> m;
    QGirls.resize(m);
    for (int j = 0; j < m; j++) {
        cin >> QGirls[j];
    }

    cout << accepted(n, graph, QGirls);

    return 0;
}
