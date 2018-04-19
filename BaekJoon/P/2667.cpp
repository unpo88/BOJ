#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[25][25];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n;

int bfs(int x, int y, int& cnt) {
	a[x][y] = 2;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (a[nx][ny] == 1)
				bfs(nx, ny, ++cnt);
		}
	}
	return 0;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &a[i][j]);

	int cnt = 1;
	vector<int> ans;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) {
				bfs(i, j, cnt);
				ans.push_back(cnt);
				cnt = 1;
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;
	for (auto x : ans)
		cout << x << endl;

	return 0;
}
