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



bool findDoor(vector<string> map, vector<point> &door) {

    int n = map.size();
    int m = map[0].size();

    for (int i = 0; i < map.size(); i++) {
        if (map[i][0] == '.') {
            point p = point(i, 0);
            door.push_back(p);
            map[i][0] = '#';
        }
        if (map[i][m - 1] == '.') {
            point p = point(i, m - 1);
            door.push_back(p);
            map[i][m - 1] = '#';
        }
    }

    for (int i = 1; i < m - 1; i++) {
        if (map[0][i] == '.') {
            point p = point(0, i);
            door.push_back(p);
            map[0][i] = '#';
        }
        if (map[n - 1][i] == '.') {
            point p = point(n - 1, i);
            door.push_back(p);
            map[n -1][i] = '#';
        }
        if( door.size() > 2){
            return false;
        }
    }

    if(door.size() == 2){
        return true;
    }

    return false;

}

bool breadthFirstSearch(vector<string> map, const point &start, const point &end) {
    vector<point> near = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    queue<point> Q;

    Q.push(start);
    map[start.x][start.y] = '#';

    while (!Q.empty()) {

        point p = Q.front();
        Q.pop();

        if (p == end) {
            return true;
        }

        for (int i = 0; i < 4; ++i) {

            if ((p.x + near[i].x >= 0) && (p.x + near[i].x < map.size())
                && (p.y + near[i].y >= 0) && (p.y + near[i].y < map[0].size())) {

                if (map[p.x + near[i].x][p.y + near[i].y] != '#') {
                    Q.push({p.x + near[i].x, p.y + near[i].y});
                    map[p.x + near[i].x][p.y + near[i].y] = '#';
                }

            }
        }
    }
    return false;
}

bool makeMaze(vector<string> map) {
    vector<point> door;
    bool success;
    if(map.size() == 1 && map[0].size() == 1)
        return false;

    if (findDoor(map, door)) {

        point start = door[0];
        point end = door[1];
        success = breadthFirstSearch(map, start, end);
        return success;
    }

    return false;
}

int main() {
    int t;
    cin >> t;
    vector<string> map;
    while (t != 0) {
        t--;

        int n, m;

        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            map.push_back(str);
        }

        cout << (makeMaze(map) ? "valid\n" : "invalid\n");
        map.clear();
    }
}
