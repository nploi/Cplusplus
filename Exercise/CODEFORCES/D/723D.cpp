//http://codeforces.com/problemset/problem/723/D

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

struct point {
public:
    int x, y;

    point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    point(){}

    point &operator=(const point &p) {
        this->x = p.x;
        this->y = p.y;
        return *this;
    }

    bool operator==(const point &p) {
        return (x == p.x && y == p.y);
    }


};

point near[4] = {point(-1, 0), point(0, 1), point(1, 0), point(0, -1)};
bool MARK[50][50];

struct lake {
    point p;
    long size;
public:
    lake(point p, int size) {this->size = size, this->p = p;}

    lake(const lake &l) { this->size = l.size, this->p = l.p; }

    bool operator>(const lake &l) { return size > l.size; }
    bool operator<(const lake &l) { return size < l.size; }
};



int BFSGetSize(const vector<string> &map, const point &cell) {

    queue<point> Queue;
    int count = 0;

    Queue.push(cell);
    MARK[cell.x][cell.y] = true;
    count++;

    while (!Queue.empty()) {
        point p = Queue.front();
        Queue.pop();

        for (int i = 0; i < 4; ++i) {

            int x = p.x + near[i].x;
            int y = p.y + near[i].y;

            if ((x >= 0) && (x < map.size()) && (y >= 0) && (y < map[0].size())) {

                if (MARK[x][y] != 1 && map[x][y] == '.') {

                    point t = point(x,y);
                    Queue.push(t);
                    MARK[x][y] = 1;
                    count++;
                }

            }
        }

    }

    return count;
}

void BFSFill(vector<string> &map, point cell) {

    queue<point> Queue;

    Queue.push(cell);
    map[cell.x][cell.y] = '*';

    while (!Queue.empty()) {
        point p = Queue.front();
        Queue.pop();

        for (int i = 0; i < 4; ++i) {

            int x = p.x + near[i].x;
            int y = p.y + near[i].y;

            if ((x >= 0) && (x < map.size()) && (y >= 0) && (y < map[0].size())) {

                if (map[x][y] != '*') {
                    point t = point(x,y);
                    Queue.push(t);
                    map[x][y] = '*';
                }

            }
        }

    }

}

void DFSMarkBeach(vector<string> &map, const point &cell){
    stack<point> S;
    S.push(cell);
    map[cell.x][cell.y] = '#';

    while (!S.empty()){
        point p = S.top();
        S.pop();

        for (int i = 0; i < 4; ++i) {

            int x = p.x + near[i].x;
            int y = p.y + near[i].y;

            if ((x >= 0) && (x < map.size()) && (y >= 0) && (y < map[0].size())) {

                if (map[x][y] == '.') {
                    point t = point(x,y);
                    S.push(t);
                    map[x][y] = '#';
                }

            }
        }

    }
}

int main() {

    long n, m, k;

    vector<string> map;
    vector<lake> lakes;

    cin >> n >> m >> k;

    map.resize(n);

    for (int i = 0; i < n ; ++i) {
        cin >> map[i];
    }

    point t;
    for (int i = 0; i < m; ++i) {
        if (map[0][i] == '.') {
            /*
             * mark beach
             */
            t = point(0, i);
            DFSMarkBeach(map, t);
        }
        if (map[n - 1][i] == '.') {
            /*
             * mark beach
             */
            t = point((n - 1), i);
            DFSMarkBeach(map, t);
        }
    }

    for (int i = 1; i < n - 1; ++i) {
        if (map[i][0] == '.') {
            /*
             * mark beach
             */
            t = point(i,0);
            DFSMarkBeach(map, t);
        }
        if (map[i][m - 1] == '.') {
            /*
             * mark beach
             */
            t = point(i, m -1);
            DFSMarkBeach(map, t);
        }
    }

    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            if(map[i][j]=='.' && MARK[i][j] != 1){
                point p(i,j);
                int size = BFSGetSize(map, p);
                lakes.push_back((lake){p, size});
            }
        }
    }

    sort(lakes.begin(), lakes.end());
    int count = 0;
    for (int i = 0; i < lakes.size() - k; ++i){
        BFSFill(map, lakes[i].p);
        count +=lakes[i].size;
    }

    cout << count  << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(map[i][j] !='*') {
                cout << '.';
            }else{
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}

