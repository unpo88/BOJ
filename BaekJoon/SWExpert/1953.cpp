#include <iostream>
#include <queue>
#include <utility>
using namespace std;

struct point{
    int r, c, l, n;
    point(int _r, int _c, int _l, int _n):
        r(_r), c(_c), l(_l), n(_n) {}
};

int N, M;
int R, C, L;

int map[51][51];
bool visit[51][51];

//  동, 서, 남, 북
const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){
        int answer = 0 ;

        queue<point> q;
        
        cin >> N >> M >> R >> C >> L;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> map[i][j];
            }
        }

        q.push(point(R, C, 1, map[R][C]));
        visit[R][C] = true;
        
        
        while(!q.empty()){
            point temp = q.front();
            q.pop();

            if(temp.l == L){
                continue;
            }

            for(int i = 0; i < 4; i++){
                int nx = temp.r + dx[i];
                int ny = temp.c + dy[i];
                if(nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny])  continue;
                if(map[temp.r][temp.c] == 2){
                    if(i == 0 || i == 1)    continue;
                }else if(map[temp.r][temp.c] == 3){
                    if(i == 2 || i == 3)    continue;
                }else if(map[temp.r][temp.c] == 4){
                    if(i == 1 || i == 2)    continue;
                }else if(map[temp.r][temp.c] == 5){
                    if(i == 1 || i == 3)    continue;
                }else if(map[temp.r][temp.c] == 6){
                    if(i == 0 || i == 3)    continue;
                }else if(map[temp.r][temp.c] == 7){
                    if(i == 0 || i == 2)    continue;
                }

                if(i == 0){
                    if(map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 6 || map[nx][ny] == 7){
                        q.push(point(nx, ny, temp.l + 1, map[nx][ny]));
                        visit[nx][ny] = true;
                    }
                }else if(i == 1){
                    if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 5) {
                        q.push(point(nx, ny, temp.l + 1, map[nx][ny]));
                        visit[nx][ny] = true;
                    }
                }else if(i == 2){
                    if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny]== 4 || map[nx][ny] == 7) {
                        q.push(point(nx, ny, temp.l + 1, map[nx][ny]));
                        visit[nx][ny] = true;
                    }
                }else{
                    if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny]== 5 || map[nx][ny] == 6) {
                        q.push(point(nx, ny, temp.l + 1, map[nx][ny]));
                        visit[nx][ny] = true;
                    }
                }
            }
            /*
            switch(temp.n){
                case 1 :
                    for(int i = 0; i < 4; i++){
                        int nx = temp.r + dx[i];
                        int ny = temp.c + dy[i];
                        if(nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny])  continue;
                        if(map[nx][ny] != 0 && temp.l < L){
                            visit[nx][ny] = true;
                            q.push(point(nx, ny, temp.l + 1, map[nx][ny]));
                        }
                    }
                    break;
                case 2 :
                    for(int i = 2; i < 4; i++){
                        int nx = temp.r + dx[i];
                        int ny = temp.c + dy[i];
                        if(nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny])  continue;
                        if(map[nx][ny] != 0 && temp.l < L && map[nx][ny] != 3 && map[nx][ny] != 4 && map[nx][ny] != 7){
                            visit[nx][ny] = true;
                            q.push(point(nx, ny, temp.l + 1, map[nx][ny]));
                        }
                    }
                    break;
                case 3 :
                    for(int i = 0; i < 2; i++){
                        int nx = temp.r + dx[i];
                        int ny = temp.c + dy[i];
                        if(nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny])  continue;
                        if(map[nx][ny] != 0 && temp.l < L && map[nx][ny] != 2){
                            visit[nx][ny] = true;
                            q.push(point(nx, ny, temp.l + 1, map[nx][ny]));
                        }
                    }
                    break;
                case 4 :
                    for(int i = 0; i < 4; i+=3){
                        int nx = temp.r + dx[i];
                        int ny = temp.c + dy[i];
                        if(nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny])  continue;
                        if(map[nx][ny] != 0 && temp.l < L){
                            visit[nx][ny] = true;
                            q.push(point(nx, ny, temp.l + 1, map[nx][ny]));
                        }
                    }
                    break;
                case 5 :
                    for(int i = 0; i < 4; i+=2){
                        int nx = temp.r + dx[i];
                        int ny = temp.c + dy[i];
                        if(nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny])  continue;
                        if(map[nx][ny] != 0 && temp.l < L){
                            visit[nx][ny] = true;
                            q.push(point(nx, ny, temp.l + 1, map[nx][ny]));
                        }
                    }
                    break;
                case 6 :
                    for(int i = 1; i < 3; i++){
                        int nx = temp.r + dx[i];
                        int ny = temp.c + dy[i];
                        if(nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny])  continue;
                        if(map[nx][ny] != 0 && temp.l < L){
                            visit[nx][ny] = true;
                            q.push(point(nx, ny, temp.l + 1, map[nx][ny]));
                        }
                    }
                    break;
                case 7 :
                    for(int i = 1; i < 4; i+=2){
                        int nx = temp.r + dx[i];
                        int ny = temp.c + dy[i];
                        if(nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny])  continue;
                        if(map[nx][ny] != 0 && temp.l < L){
                            visit[nx][ny] = true;
                            q.push(point(nx, ny, temp.l + 1, map[nx][ny]));
                        }
                    }
                    break;
            }*/
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(visit[i][j]){
                    answer += 1;
                }
                visit[i][j] = false;
            }
        }

        cout << "#" << tc << " " << answer << '\n';
    }
    return 0;
}