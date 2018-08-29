#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int C, H;

int M;  // move

char maze[51][51];
int visit[51][51];

int moveRow[51];
int moveCol[51];

int startRow;
int startCol;

int answer;

queue<pair<int, int> > q;

void input(){
    scanf("%d %d", &H, &C);

    for(int i = 0; i < H; i++){
        for(int j = 0; j < C; j++){
            scanf("%1s", &maze[i][j]);
            if(maze[i][j] == 'X'){
                visit[i][j] = -1;
            }
        }
    }

    printf("StartRow : ");
    scanf("%d", &startRow);
    printf("StartCol : ");
    scanf("%d", &startCol);

    printf("Move Number : ");
    scanf("%d", &M);

    printf("moveRow : ");
    for(int i = 0; i < M; i++){
        scanf("%d", &moveRow[i]);
    }

    printf("moveCol : ");
    for(int i = 0; i < M; i++){
        scanf("%d", &moveCol[i]);
    }
    
    visit[startRow][startCol] = 1;
    q.push(make_pair(startRow, startCol));
}

void BFS(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < M; i++){
            int nx = x + moveRow[i];
            int ny = y + moveCol[i];
            if(nx >= 0 && ny >= 0 && nx < H && ny < C){
                if(maze[nx][ny] != 'X' && visit[nx][ny] == 0){
                    visit[nx][ny] = visit[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int isCheck(){

    for(int i = 0; i < H; i++){
        for(int j = 0; j < C; j++){
            if(visit[i][j] == 0){
                return -1;
            }else{
                answer = max(answer, visit[i][j]);
            }
        }
    }
    return answer - 1;
}

int main(){
    input();

    BFS();

    printf("%d\n", isCheck());

    return 0;
}