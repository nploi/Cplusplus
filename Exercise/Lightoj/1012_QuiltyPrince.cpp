//http://lightoj.com/volume_showproblem.php?problem=1012
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;
 
#define Matrix vector<vector<char> >
 
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
 
point near[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
 
int DFS(Matrix &map, const point &prince) {
    int count = 0;
    stack<point> Stack;
 
    Stack.push(prince);
    map[prince.x][prince.y] = '#';
    count++;
 
    while (!Stack.empty()) {
 
        point p = Stack.top();
        Stack.pop();
 
        for (int i = 0; i < 4; ++i) {
            int x = p.x + near[i].x;
            int y = p.y + near[i].y;
 
            if ((x >= 0) && (x < map.size()) && (y >= 0) && (y < map[0].size())) {
                if (map[x][y] != '#') {
                    Stack.push({x, y});
                    map[x][y] = '#';
                    count++;
                }
            }
        }
    }
 
    return count;
}
 
int main(){
 
    int T;
    cin >> T;
    int number = 1;
    while (T--){
        int W, H;
        Matrix map;
        point prince;
        cin >> W >> H;
 
        map.resize(H);
 
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                char val;
                cin >> val;
                map[i].push_back(val);
                if(val=='@') {
                    prince = {i, j};
                }
            }
        }
 
        cout <<"Case " << number++ << ": " << DFS(map, prince) << endl;
    }
    return 0;
}
