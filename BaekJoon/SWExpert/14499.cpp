#include <iostream>
using namespace std;

int N, M;
int x, y;
int K;

int map[20][20];

int dice[7];

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { 1, -1, 0, 0 };

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
        int D;
        cin >> D;
        D -= 1;

        int nx = x + dx[D];
        int ny = y + dy[D];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M)  continue;

        if(D == 0){
            int temp = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = temp;
        }else if(D == 1){
            int temp = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = temp;
        }else if(D == 2){
            int temp = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = temp;
        }else if(D == 3){
            int temp = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = temp;
        }

        if(map[nx][ny] == 0){
            map[nx][ny] = dice[6];
        }else{
            dice[6] = map[nx][ny];
            map[nx][ny] = 0;
        }

        cout << dice[1] << '\n';
        x = nx;
        y = ny;
    }

    return 0;
}