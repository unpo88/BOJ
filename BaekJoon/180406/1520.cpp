#include <cstdio>

int map[510][510];
int visit[510][510];
int M, N;

int search(int x, int y){   
 
    // 상하좌우 표시
    int vect_x[5] = { 0, 1, 0, -1, 0 };
    int vect_y[5] = { 0, 0, 1, 0, -1 };
 
    if (x == N && y == M)
        return 1;
    if (visit[y][x]) return visit[y][x];
    for (int i = 1; i <= 4; i++){
        int nextX = x + vect_x[i];
        int nextY = y + vect_y[i];
        if (map[nextY][nextX] < map[y][x] && nextX>0 && nextX <= N && nextY>0 && nextY <= M){
 
            visit[y][x] += search(nextX,nextY);
 
        }
    }
 
    return visit[y][x];
}

int main(){
    scanf("%d %d", &M, &N);
 
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &map[i][j]);        // 입력
    
    printf("%d\n", search(1,1));            // (1,1) 좌표부터 시작
    return 0;
}