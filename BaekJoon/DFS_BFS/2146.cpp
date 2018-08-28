#include <cstdio>
#include <queue>
using namespace std;

#define LI  100000

int N;

int map[102][102];
int visit[102][102];

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };

queue<pair<int, int> > q;

void input(){
    scanf("%d", &N);

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            scanf("%d", &map[i][j]);
        }
    }
}


void dfs(int x, int y, int count){
    visit[x][y] = count;
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx > 0 && ny > 0 && nx <= N && ny <= N){
            if(!visit[nx][ny]){
                if(map[nx][ny]){
                    dfs(nx, ny, count);
                }else{
                    visit[nx][ny] = count + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

void island(){
    for (int i = 1, cnt = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] && !visit[i][j]) {
                dfs(i, j, cnt * LI);
                cnt++;
            }
        }
    }
}

int linkbridge(){
    int temp;
    int min  = N * N;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
                
            if(nx > 0 && ny > 0 && nx <= N && ny <= N){
                if(visit[nx][ny]){
                    if(visit[nx][ny] / LI != visit[x][y] / LI){
                        temp = visit[nx][ny] % LI + visit[x][y] % LI;
                        
                        if(temp < min){
                            min = temp;
                        }
                    }
                }else{
                    visit[nx][ny] = visit[x][y] + 1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    return min;
}

int main(){
    input();

    island();
    
    printf("%d\n", linkbridge());

    return 0;
}