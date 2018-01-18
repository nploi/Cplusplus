#include<iostream>
#include<stack>
#include<fstream>
#include<stack>

using namespace std;

#define MAX 10
#define INPUT "INPUT.txt"
struct point {
	int x, y;
};

int map[MAX][MAX];
int mask[MAX][MAX];
int n;
point start, End;

point near[4] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };

void loadFile()
{
	std::ifstream in(INPUT);
	in >> n;
	in >> start.x >> start.y;
	in >> End.x >> End.y;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			in >> map[i][j];
			mask[i][j] = 0;
		}
	}

}


bool FindFromAToB(point x) {

	if ((x.x == End.x&&x.y == End.y)) {
		return true;
	}
	stack<point> S;
	S.push(x);
	mask[x.x][x.y] = 1;
	point t;
	while (!S.empty()) {
		t = S.top();	
		S.pop();

		if (t.x == End.x&&t.y == End.y) {
			return true;
		}

		for (int i = 0; i < 4; i++) {
			if (t.x + near[i].x >= 0 && t.x + near[i].x < n&&t.y + near[i].y >= 0 && t.y + near[i].y < n) {
				if (mask[t.x + near[i].x][t.y + near[i].y] == 0 && map[t.x + near[i].x][t.y + near[i].y] == 1) {
					mask[t.x + near[i].x][t.y + near[i].y] = 1;
					S.push({ t.x + near[i].x, t.y + near[i].y });
				}
			}
		}
	}
	return false;
}

int main() {
	loadFile();
	bool t = FindFromAToB(start);
	cout << t;
	return 0;
}
