#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int w, h;

int map[51][51];

// πÊ«‚
const int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = { 1, -1, 0, 0 , -1, 1, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (scanf("%d %d", &w, &h) && w != 0 && h != 0) {
		memset(map, 0, sizeof(map));

		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) {
				cin >> map[i][j];
			}
		}
	}
	return 0;
}