#include <iostream>
using namespace std;

char map[20][20];
int alpha[26];

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

int R, C;
int ans = 0;

void solve(int x, int y, int step){
    alpha[map[x][y] - 'A'] = 1;
    if(step > ans){
        ans = step;
    }

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= R || ny >= C){
            continue;
        }
        if(alpha[map[nx][ny] - 'A'] == 1){
            continue;
        }
        solve(nx, ny, step + 1);
        alpha[map[nx][ny] - 'A'] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
        }
    }

    solve(0, 0, 1);

    printf("%d\n", ans);

    return 0;
}