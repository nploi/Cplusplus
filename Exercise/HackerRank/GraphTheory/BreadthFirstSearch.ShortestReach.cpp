//https://www.hackerrank.com/challenges/bfsshortreach/problem

#include <bits/stdc++.h>
#include <vector>

using namespace std;


vector <int> bfs(int n, int m, vector < vector<int> > edges, int s) {
    vector<vector<int> > matrix;
    vector<int> result, dist;
    queue<int> Queue;
    dist.resize(n + 1, -1);
    matrix.resize(n + 1);

    for (int i = 0; i < edges.size(); ++i) {
        matrix[edges[i][0]].push_back(edges[i][1]);
        matrix[edges[i][1]].push_back(edges[i][0]);
    }

    Queue.push(s);
    dist[s] = 0;

    while (!Queue.empty()) {
        int pos = Queue.front();
        Queue.pop();

        for (int i = 0; i < matrix[pos].size(); ++i) {
            if (dist[matrix[pos][i]] == -1) {
                dist[matrix[pos][i]] = dist[pos] + 1;
                Queue.push(matrix[pos][i]);

            }
        }
    }

    for (int j = 1; j <= n; ++j) {
        if (j != s) {
            if (dist[j] != -1) {
                result.push_back(dist[j] * 6);
            } else {
                result.push_back(-1);
            }
        }
    }
    return result;
}

int main() {
    int q;
    cin >> q;
    for (int a0 = 0; a0 < q; a0++) {
        int n;
        int m;
        cin >> n >> m;
        vector<vector<int> > edges(m, vector<int>(2));
        for (int edges_i = 0; edges_i < m; edges_i++) {
            for (int edges_j = 0; edges_j < 2; edges_j++) {
                cin >> edges[edges_i][edges_j];
            }
        }
        int s;
        cin >> s;
        vector<int> result = bfs(n, m, edges, s);
        for (ssize_t i = 0; i < result.size(); i++) {
            cout << result[i] << (i != result.size() - 1 ? " " : "");
        }
        cout << endl;
    }
    return 0;
}
