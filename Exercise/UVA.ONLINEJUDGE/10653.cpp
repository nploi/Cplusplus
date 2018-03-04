//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1594
/*
@author
 - loinp
@date
 - 1/03/2018
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e7;

vector<pair<int, int> > near = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int BFS(vector<vector<int> > &graph, pair<int, int> start, pair<int, int> end){
    int total = 0;

    queue<pair<int, int> > q;

    q.push(start);

    while(!q.empty()){

        pair<int, int>  val = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int x = near[i].first + val.first;
            int y = near[i].second + val.second;
            if(x >= 0 && x < graph.size() && y >= 0 && y < graph[0].size()){
                if(graph[x][y]==0){
                    graph[x][y] = graph[val.first][val.second] + 1;
                    q.push({x,y});
                }
            }
        }
    }
    return graph[end.first][end.second];

}


int main() {


    int R, C, row, c, rows;
    while(true) {

        vector<vector<int> > graph;
        cin >> R >> C;

        if(R == 0 && C ==0 )
            break;

        graph.resize(R);

        for (int i = 0; i < R; ++i) {
            graph[i].resize(C, 0);
        }

        cin >> rows;

        for (int i = 0; i < rows; ++i) {
            cin >> row;
            int n;
            cin >> n;
            while (n--) {
                int j;
                cin >> j;
                graph[row][j] = 1;
            }
        }

        pair<int, int> start, end;
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;

        cout << BFS(graph, start, end) << endl;

    }
    return 0;
}
