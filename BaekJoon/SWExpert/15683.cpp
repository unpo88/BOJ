#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
	int x, y, n;
	point(int x, int y, int n) :
		x(x), y(y), n(n)	{}
};

int N, M;

int map[8][8];
int visit[8][8];

int answer = 987654321;

vector<point> v;

void check(int x, int y, int dir, int flag) {
	if (dir == 0) {
		--x;
		while (x >= 0) {
			if (map[x][y] == 6)	return;
			if (flag)	visit[x][y]++;
			else visit[x][y]--;
			x--;
		}
	}
	else if (dir == 1) {
		++y;
		while (y < M) {
			if (map[x][y] == 6)	return;
			if (flag)	visit[x][y]++;
			else visit[x][y]--;
			y++;
		}
	}
	else if (dir == 2) {
		++x;
		while (x < N) {
			if (map[x][y] == 6)	return;
			if (flag)	visit[x][y]++;
			else visit[x][y]--;
			x++;
		}
	}
	else if (dir == 3) {
		--y;
		while (y >= 0) {
			if (map[x][y] == 6)	return;
			if (flag)	visit[x][y]++;
			else visit[x][y]--;
			y--;
		}
	}
}

int get_result() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && visit[i][j] == 0) {
				sum++;
			}
		}
	}
	return sum;
}


void DFS(int idx) {
	if (idx == v.size()) {
		answer = min(answer, get_result());
		return;
	}

	int x = v[idx].x;
	int y = v[idx].y;
	int num = v[idx].n;

	if (num == 1) {
		for (int i = 0; i < 4; i++) {
			check(x, y, i, 0);
			DFS(idx + 1);
			check(x, y, i, 1);
		}
	}
	else if (num == 2) {
		for (int i = 0; i < 2; i++) {
			check(x, y, i, 0);
			check(x, y, i + 2, 0);
			DFS(idx + 1);
			check(x, y, i, 1);
			check(x, y, i + 2, 1);
		}
	}
	else if (num == 3) {
		for (int i = 0; i < 4; i++) {
			check(x, y, i, 0);
			check(x, y, (i + 1) % 4, 0);
			DFS(idx + 1);
			check(x, y, i, 1);
			check(x, y, (i + 1) % 4, 1);
		}
	}
	else if (num == 4) {
		for (int i = 0; i < 4; i++) {
			check(x, y, i, 0);
			check(x, y, (i + 1) % 4, 0);
			check(x, y, (i + 3) % 4, 0);
			DFS(idx + 1);
			check(x, y, i, 1);
			check(x, y, (i + 1) % 4, 1);
			check(x, y, (i + 3) % 4, 1);
		}
	}
	else if (num == 5) {
		for (int i = 0; i < 4; i++) {
			check(x, y, i, 0);
		}
		DFS(idx + 1);
		for (int i = 0; i < 4; i++) {
			check(x, y, i, 1);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0 || map[i][j] == 6)	continue;
			v.push_back(point(i, j, map[i][j]));
		}
	}
	
	DFS(0);

	cout << answer << '\n';
	return 0;
}
