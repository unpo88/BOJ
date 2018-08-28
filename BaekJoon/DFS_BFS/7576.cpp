#include <cstdio>
#include <queue>
using namespace std;

int M, N;
int map[1002][1002];
int visit[1002][1002];

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };

queue<pair<int,int> > q;

int main(){
    scanf("%d %d", &M, &N);
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            scanf("%d", &map[i][j]);
            visit[i][j] = -1;
            if(map[i][j] == 1){
                visit[i][j] = 0;
                q.push(make_pair(i,j));
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
            if(!map[nx][ny] && visit[nx][ny] == -1){
                if(nx > 0 && ny > 0 && nx <= N && ny <= M){
                    visit[nx][ny] = visit[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    int maxVal = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j<= M; j++){
            if(maxVal < visit[i][j]){
                maxVal = visit[i][j];
            }
            if(!map[i][j] && visit[i][j] == -1){
                printf("-1\n");
                return 0;
            }
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(!map[i][j] && visit[i][j] == -1){
                maxVal = -1;
            }
        }
    }

    printf("%d\n", maxVal);

    return 0;
}