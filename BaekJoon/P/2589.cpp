#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int L, W;

int map[51][51];
bool visit[51][51];
int depth[51][51];

queue<int> qx;
queue<int> qy;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int max_value = 0;

void bfs(int x, int y) {
	visit[x][y] = true;
	qx.push(x);
	qy.push(y);

	while (!qx.empty() && !qy.empty()) {
		int temp_x = qx.front();
		qx.pop();
		int temp_y = qy.front();
		qy.pop();
		for (int i = 0; i < 4; i++) {
			int nx = temp_x + dx[i];
			int ny = temp_y + dy[i];
			if (map[nx][ny] == 1 && !visit[nx][ny]) {
				visit[nx][ny] = true;
				qx.push(nx);
				qy.push(ny);
		
				depth[nx][ny] = depth[temp_x][temp_y] + 1;
				if (max_value < depth[nx][ny]) {
					max_value = depth[nx][ny];
				}
			}
		}
	}
}
int main() {
	scanf("%d %d", &L, &W);
	
	char input;
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> input;
			if (input == 'W') {
				map[i][j] = 0;
			}
			else {
				map[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= W; j++) {
			if (map[i][j] == 1) {
				bfs(i, j);
				memset(visit, 0, sizeof(visit));
				memset(depth, 0, sizeof(depth));
			}
		}
	}

	cout << max_value;

	return 0;
}