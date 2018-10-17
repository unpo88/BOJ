#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M;

int map[9][9];
int check[9][9];

queue<pair<int, int> > q;

const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };

int ans = 0;

int bfs(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            check[i][j] = map[i][j];
            if(map[i][j] == 2){
                q.push(make_pair(i, j));
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <= 0 || ny <= 0 || nx > N || ny > M)  continue;
            if(check[nx][ny] == 0){
                check[nx][ny] = 2;
                q.push(make_pair(nx, ny));
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(check[i][j] == 0){
                cnt += 1;
            }
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> map[i][j];
        }
    }

    for(int x1 = 1; x1 <= N; x1++){
        for(int y1 = 1; y1 <= M; y1++){
            if(map[x1][y1] != 0)  continue;
            for(int x2 = 1; x2 <= N; x2++){
                for(int y2 = 1; y2 <= M; y2++){
                    if(map[x2][y2] != 0)    continue;
                    for(int x3 = 1; x3 <= N; x3++){
                        for(int y3 = 1; y3 <= M; y3++){
                            if(map[x3][y3] != 0)    continue;
                            if(x1 == x2 && y1 == y2)    continue;
                            if(x2 == x3 && y2 == y3)    continue;
                            if(x3 == x1 && y3 == y1)    continue;
                            map[x1][y1] = 1;
                            map[x2][y2] = 1;
                            map[x3][y3] = 1;
                            int cur = bfs();
                            if(ans < cur)   ans = cur;
                            map[x1][y1] = 0;
                            map[x2][y2] = 0;
                            map[x3][y3] = 0;
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}