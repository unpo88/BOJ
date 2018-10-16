#include <iostream>
using namespace std;

// up, right, down, left
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

// 로봇 바라보는 방향
// 0 : 북, 1 : 동, 2 : 남, 3 : 서
int d;

// 지도
int map[50][50];

// 행, 렬
int N, M;

// 로봇 청소기 칸의 좌표
int r, c;

int ans = 0;

int cnt = 0; 

int DFS(int x, int y, int dir){
    if(cnt == 4){
        dir = (dir + 2) % 4;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        cnt = 0;
        if(nx >= 0 || ny >= 0 || nx < N || ny < M){
            if(map[nx][ny] == 0){
                DFS(nx, ny, dir);
            }else{
                return ans;
            }
        }
    }

    if(map[x][y] == 0){
        map[x][y] = 2;
        cout << x << " " << y << endl;
        ans = ans + 1;
    }


    dir = (dir + 3) % 4;
    
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(nx >= 0 || ny >= 0 || nx < N || ny < M){
        if(map[nx][ny] == 0){
            DFS(nx, ny, dir);
        }else{
            cnt = cnt + 1;
            DFS(x, y, dir);
        }
    }
    
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> r >> c >> d;
    
    // 빈 칸은 0, 벽은 1로 주어진다. 장소의 모든 외곽은 벽이다.
    // 로봇 청소기가 있는 칸의 상태는 항상 빈 칸이다.
    // 로봇 청소기가 청소하는 칸의 개수를 출력한다.
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    int count = 0;

    while(true){
        if(map[r][c] == 0){
            map[r][c] = 2;
        }
        if(map[r+1][c] != 0 && map[r-1][c] != 0 && map[r][c-1] != 0 && map[r][c+1] != 0){
            if(map[r-dx[d]][c-dy[d]] == 1 ){
                break;
            }else{
                r -= dx[d];
                c -= dy[d];
            }
        }else{
            d = (d + 3) % 4;
            if(map[r+dx[d]][c+dy[d]] == 0){
                r += dx[d];
                c += dy[d];
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 2){
                count += 1;
            }
        }
    }

    cout << count << '\n';

    //cout << DFS(r, c, d) << '\n';

    return 0;
}