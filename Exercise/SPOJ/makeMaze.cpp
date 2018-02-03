//http://www.spoj.com/problems/MAKEMAZE/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


struct point {
    int x, y;
public:
    point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    point &operator=(point p) {
        this->x = p.x;
        this->y = p.y;
        return *this;
    }

    bool operator==(const point &p) {
        return (x == p.x && y == p.y);
    }
};

point near[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool findDoor(vector<string> map, vector<point> &door) {
    int n = map.size();
    int m = map[0].size();

    for (int i = 0; i < n; i++) {
        if (map[i][0] == '.') {
            door.push_back(point(i, 0));
            map[i][0] = '#';
        }
        if (map[i][m - 1] == '.') {
            door.push_back(point(i, m - 1));
            map[i][m - 1] = '#';
        }
    }

    for (int i = 1; i < m - 1; i++) {
        if (map[0][i] == '.') {
            door.push_back(point(0, i));
            map[0][i] = '#';
        }
        if (map[n - 1][i] == '.') {
            door.push_back(point(n - 1, i));
            map[n -1][i] = '#';
        }
    }

    if (door.size() == 1 || door.size() > 2) {
        return false;
    }

    return true;
}

bool breadthFirstSearch(vector<string> map, const point &start, const point &end) {
    queue<point> Q;
    vector<vector<bool> > mark;
    mark.resize(map.size());

    //mark
    for (int i = 0; i < map.size(); ++i) {
        mark[i].resize(map[i].size());

        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == '#') {
                mark[i][j] = 1;
            } else {
                mark[i][j] = 0;
            }
        }
    }

    Q.push(start);
    mark[start.x][start.y] = 1;

    while (!Q.empty()) {

        point p = Q.front();
        Q.pop();

        if (p == end) {
            return true;
        }

        for (int i = 0; i < 4; ++i) {

            if ((p.x + near[i].x >= 0) && (p.x + near[i].x < map.size())
                && (p.y + near[i].y >= 0) && (p.y + near[i].y < map[0].size())) {

                if (!mark[p.x + near[i].x][p.y + near[i].y]) {
                    Q.push({p.x + near[i].x, p.y + near[i].y});
                    mark[p.x + near[i].x][p.y + near[i].y] = 1;
                }

            }
        }
    }
    return false;
}

bool makeMaze(vector<string> map) {
    vector<point> door;
    if(map.size() == 1 && map[0].size() == 1)
        return false;

    if (findDoor(map, door)) {

        point start = door[0];
        point end = door[1];
        return breadthFirstSearch(map, start, end);
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t != 0) {
        t--;
        vector<string> map;
        int n, m;

        cin >> n >> m;

        map.resize(n);

        for (auto &item : map) {
            cin >> item;
        }

        cout << (makeMaze(map) ? "valid\n" : "invalid\n");
    }
}
