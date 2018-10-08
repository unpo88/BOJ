#include <cstdio>
#include <utility>
#include <cstring>
using namespace std;
#pragma warning(disable: 4996)

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };
        
int map[16][16];
int visit[16][16];
int answer;

void DFS(int start_x, int start_y, int end_x, int end_y){
    visit[start_x][start_y] = 1;

    for(int i = 0; i < 4; i++){
        int nx = start_x + dx[i];
        int ny = start_y + dy[i];

        if(nx < 0 || ny < 0 || nx > 15 || ny > 15)    continue;
        if(visit[nx][ny] && map[nx][ny] == 1)   continue;
        if(!visit[nx][ny] && map[nx][ny] == 3){
            if(nx == end_x && ny == end_y){
                answer = 1;
                return ;
            }
        }else if(!visit[nx][ny] && map[nx][ny] == 0){
            DFS(nx, ny, end_x, end_y);
        }
    }
}

int main(){
    for(int t = 1; t <= 10; t++){
        int testCase;
        scanf("%d", &testCase);
        int start_x, start_y;
        int end_x, end_y;
        answer = 0;
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));

        for(int row = 0; row < 16; row++){
            for(int col = 0; col < 16; col++){
                scanf("%1d", &map[row][col]);
                if(map[row][col] == 2){
                    start_x = row;
                    start_y = col;
                }else if(map[row][col] == 3){
                    end_x = row;
                    end_y = col;
                }
            }
        }

        DFS(start_x, start_y, end_x, end_y);

        printf("#%d %d\n", testCase, answer);

    }
    return 0; 
}