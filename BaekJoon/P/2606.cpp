#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int a[101][101];
int visit[101];
queue<int> q;

int bfs() {
	while (!q.empty()) {
		int z = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (a[z][i] == 1 && visit[i] == 0) {
				q.push(i);
				visit[i] = 1;
				bfs();
			}
		}
	}
	return 0;
}
int main() {
	cin >> N;
	int M;
	cin >> M;
	
	for (int i = 1; i <= M; i++) {
		int x, y;
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}

	q.push(1);
	visit[1] = 1;
	bfs();

	int cnt = 0;
	for (auto x : visit) {
		if (x == 1) {
			cnt++;
		}
	}
	cout << cnt - 1;
	return 0;
}