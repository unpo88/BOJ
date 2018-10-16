#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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