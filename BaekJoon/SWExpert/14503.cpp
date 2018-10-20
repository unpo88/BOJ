#include <iostream>
using namespace std;

int N, M;
int R, C, D;

int map[51][51];

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> R >> C >> D;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    while(true){
        map[R][C] = 2;

        if(map[R-1][C] != 0 && map[R][C+1] != 0 && map[R+1][C] != 0 && map[R][C-1] != 0){
            if(map[R-dx[D]][C-dy[D]] == 1){
                break;
            }else{
                R -= dx[D];
                C -= dy[D];
            }
        }else{
            D = (D + 3) % 4;
            if(map[R+dx[D]][C+dy[D]] == 0){
                R += dx[D];
                C += dy[D];
            }
        }
    }

    int count = 0;
    for(int i = 0; i< N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 2){
                count += 1;
            }
        }
    }

    cout << count << '\n';

    return 0;
}