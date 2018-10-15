#include <iostream>
using namespace std;

int map[20][20];
int dice[7];

// 동, 서, 남, 북(right, left, down, up)
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int N, M, K;
int x, y;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> x >> y >> K;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    while(K--){
        int k;
        cin >> k;
        k -= 1;
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(nx < 0 || nx >= N || ny < 0 || ny >= M)  continue;
        if(k == 0){ // right
            int temp = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = temp;
        }else if(k == 1){   // left
            int temp = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = temp;
        }else if(k == 2){   // down
            int temp = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = temp;
        }else{  // up
            int temp = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = temp;
        }
        x = nx;
        y = ny;
        if(map[x][y] == 0){
            // 주사위 굴렸을 때, 이동한 칸에 써 있는 수가 0이면, 주사위의 바닥면에 써 있는 수가 칸에 복사됌
            map[x][y] = dice[6];
        }else{
            // 0이 아닌 경우에는 칸에 써 있는 수가 주사위 바닥면으로 복사되고, 칸은 0이 됌
            dice[6] = map[x][y];
            map[x][y] = 0;
        }

        cout << dice[1] << '\n';
    }
    return 0;
}