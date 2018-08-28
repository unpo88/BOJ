#include <cstdio>
#include <cstring>
using namespace std;

int w, h;

int map[53][53];
int check[53][53];

int answer;

const int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = { 1, -1, 0, 0 , -1, 1, 1, -1};

void DFS(int x, int y){
	check[x][y] = 1;

	for(int i = 0; i < 8; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx <= 0 || nx > h || ny <= 0 || ny > w){
			continue;
		}
		if(!check[nx][ny] && map[nx][ny] == 1){
			DFS(nx, ny);
		}
	}
	return ;
}

int main() {
	while (scanf("%d %d", &w, &h) && w != 0 && h != 0) {
		memset(check, 0, sizeof(check));
		answer = 0;

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= w; j++){
				if(map[i][j] == 1 && !check[i][j]){
					DFS(i,j);
					answer++;
				}
			}
		}
		
		printf("%d\n", answer);
	}
	return 0;
}