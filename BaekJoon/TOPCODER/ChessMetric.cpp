#include <cstdio>
#include <queue>
using namespace std;

int N;

long long map[100][100][51];

int start_x, start_y;

int end_x, end_y;

int numMoves;

int answer;

queue<pair<int, int> > q;

const int dx[] = { 1, 1, 1, 0, -1, -1, -1, 0, 2, 1, -1, -2, -2, -1, 1, 2 };
const int dy[] = { 1, 0, -1, -1, -1, 0, 1, 1, -1, -2, -2, -1, 1, 2, 2, 1 };

int main(){
    scanf("%d", &N);

    scanf("%d %d", &start_x, &start_y);

    scanf("%d %d", &end_x, &end_y);

    scanf("%d", &numMoves);
    
    map[start_x][start_y][0] = 1;

    for(int i = 1; i <= numMoves; i++){
        for(int x = 0; x < N; x++){
            for(int y = 0; y < N; y++){
                 for(int j = 0; j < 16; j++){
                     int next_x = x + dx[j];
                     int next_y = y + dy[j];
                     if( next_x < 0 || next_y < 0 || next_x >= N || next_y >= N){
                         continue;
                     }
                     map[next_x][next_y][i] += map[x][y][i-1];
                 }
            }
        }
    }

    printf("%lld", map[end_x][end_y][numMoves]);

    return 0;
}