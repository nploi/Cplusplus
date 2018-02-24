//http://www.spoj.com/problems/CAM5/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


void DFS(const vector<vector<int> >& graph, vector<bool> &visit, int start) {
    stack<int> Stack;

    Stack.push(start);
    visit[start] = true;

    while(!Stack.empty()){

        int val = Stack.top();
        Stack.pop();

        for (int i = 0; i < graph[val].size(); ++i) {
            int x = graph[val][i];
            if(!visit[x]){
                visit[x] = true;
                Stack.push(x);
            }
        }
    }
}

int main() {
//    ios::sync_with_stdio(false);
    int t, n, e;

    cin >> t;

    while (t--) {

        vector<vector<int> > graph;
        vector<bool> visit;
        cin >> n >> e;

        graph.resize(n);
        visit.resize(n, 0);
        for (int i = 0; i < e; ++i) {
            int V, E;
            cin >> V >> E;
            graph[V].push_back(E);
            graph[E].push_back(V);

        }

        if (e == 0) {
            cout << n << endl;
            continue;
        }

        int count = 0;

        for (int i = 0; i < n; ++i) {
            if(visit[i]==0){
                count++;
                DFS(graph, visit, i);
            }
        }

        cout << count << endl;
    }

    return 0;
}
