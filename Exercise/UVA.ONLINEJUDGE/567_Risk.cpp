
/*
@author
 - loinp
@date
 - 10/03/2018
*/

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=508

#include <bits/stdc++.h>

#define Matrix vector<vector<int> >
#define INF 1e9

using namespace std;

void floyWarshall(Matrix &dist) {

    for (int k = 1; k < 21; ++k) {
        for (int i = 1; i < 21; ++i) {
            for (int j = 0; j < 21; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {

    int check = 1, num = 1;
    while (check) {

        Matrix graph(21, vector<int>(21, INF));
        Matrix dist(21, vector<int>(21));
        Matrix path(21, vector<int>(21));

        for (int i = 1; i <= 19; ++i) {
            int k;

            if ((cin >> k)) {
                while (k--) {
                    int j;
                    cin >> j;
                    graph[i][j] = 1;
                    graph[j][i] = 1;
                }
            } else {
                check = 0;
                break;
            }
        }

        if (check == 0)
            break;

        for (int i = 1; i <= 20; ++i) {
            for (int j = 1; j <= 20; ++j) {
                dist[i][j] = graph[i][j];
                if (graph[i][j] != INF && i != j) {
                    path[i][j] = i;
                } else {
                    path[i][j] = -1;
                }
            }
        }


        floyWarshall(dist);

        cout << "Test Set #" << num << endl;
        int test;
        cin >> test;
        for (int i = 0; i < test; ++i) {
            int s, e;
            cin >> s >> e;
            if (s < 10) {
                cout << " " << s;
            } else {
                cout << s;
            }
            cout << " to ";
            if (e < 10) {
                cout << " " << e;
            } else {
                cout << e;
            }
            cout << ": " << dist[s][e] << endl;
        }

        cout << endl;
        num++;
    }
    return 0;
}
