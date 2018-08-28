#include <cstdio>
#include <queue>
using namespace std;

int N, M;
int map[102][102];
int visit[102][102];

queue<pair<int, int> > q;

const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { -1, 1, 0, 0 };

int main(){
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            scanf("%1d", &map[i][j]);
            if(i == 1 && j == 1){
                visit[i][j] = 1;
            }else if(map[i][j] == 0){
                visit[i][j] = -1;
            }
        }
    }

    q.push(make_pair(1,1));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(map[nx][ny] == 1 && visit[nx][ny] == 0){
                if(nx > 0 && ny > 0 && nx <= N && ny <= M){
                    visit[nx][ny] = visit[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    printf("%d\n", visit[N][M]);

    return 0;
}
