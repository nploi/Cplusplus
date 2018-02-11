//http://codeforces.com/problemset/problem/723/D

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct point {
public:
    int x, y;

    point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    point();

    point &operator=(const point &p) {
        this->x = p.x;
        this->y = p.y;
        return *this;
    }

    bool operator==(const point &p) {
        return (x == p.x && y == p.y);
    }
};

point near[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool MARK[50][50];

bool BFSCheck(const vector<string> &map, const point &cell) {

    queue<point> Queue;
    if (cell.x == 0 || cell.x == map.size() - 1 || cell.y == 0 || cell.y == map[0].size() - 1) {
        return false;
    }
    Queue.push(cell);
    MARK[cell.x][cell.y] = true;


    while (!Queue.empty()) {
        point p = Queue.front();
        Queue.pop();

        for (int i = 0; i < 4; ++i) {

            int x = p.x + near[i].x;
            int y = p.y + near[i].y;

            if ((x >= 0) && (x < map.size()) && (y >= 0) && (y < map[0].size())) {

                if (MARK[x][y] != 1 && map[x][y] == '.') {
                    if (x == 0 || x == map.size() - 1 || y == 0 || y == map[0].size() - 1) {
                        return false;
                    } else {
                        Queue.push({x, y});
                        MARK[x][y] = 1;
                    }

                }

            }
        }

    }

    return true;
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
                        Queue.push({x, y});
                        map[x][y] = '*';
                }

            }
        }

    }

}

int DFS(vector<string> &map, int k) {
    int count = 0;

    stack<point> Stack;
    Stack.push({0, 0});
    MARK[0][0] = 1;

    while (!Stack.empty()) {
        point p = Stack.top();
        Stack.pop();
        for (int i = 0; i < 4; ++i) {

            int x = p.x + near[i].x;
            int y = p.y + near[i].y;

            if ((x >= 0) && (x < map.size()) && (y >= 0) && (y < map[0].size())) {

                if (MARK[x][y] != 1) {

                    if (map[x][y] == '*') {
                        Stack.push({x, y});
                        MARK[x][y] = 1;
                    } else {
                        bool l = BFSCheck(map, {x, y});
                        if(l) {
                            if (k != 0) {
                                k -= l;
                            } else {
                                count++;
                                BFSFill(map, {x, y});
                            }
                        }
                    }
                }

            }
        }
    }

    return count;
}

int main() {

    long n, m, k;

    vector<string> map;

    cin >> n >> m >> k;

    map.resize(n);

    for (int i = 0; i < n ; ++i) {
        cin >> map[i];
    }

    cout << DFS(map, k) << endl;
    for (int i = 0; i < n ; ++i) {
        cout << map[i] << endl;
    }

    return 0;
}
