#include <iostream>
#include <string>
using namespace std;

char map[100][100];
int visited[100][100][81];

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

int N, M, K;

int ans;

string str;

int DFS(int x, int y, int pos){
    if(pos == str.length() - 1){
        return 1;
    }

    if(visited[x][y][pos] != -1){
        return visited[x][y][pos];
    }

    visited[x][y][pos] = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= K; j++){
            int nx = x + dx[i] * j;
            int ny = y + dy[i] * j;

            if(nx < 0 || ny < 0 || nx >= N || ny >= M)  continue;
            if(map[nx][ny] == str[pos + 1]){
                visited[x][y][pos] += DFS(nx, ny, pos + 1);
            }
        }
    }
    return visited[x][y][pos];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
			fill(visited[i][j], visited[i][j] + 81, -1);
            cin >> map[i][j];
        }
    }
    
    cin >> str;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == str[0]){
                ans += DFS(i, j, 0);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}