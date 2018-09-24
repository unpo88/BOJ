#include <cstdio>

int map[101][101];
long long s[101][101];

int N, M;

long long ans;

long long sum(int x1, int y1, int x2, int y2){
    return s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1];
}
int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + (long long)map[i][j];
        }
    }
    // 1번 경우
    for(int i = 1; i <= M - 2; i++){
        for(int j = i + 1; j <= M - 1; j++){
            long long r1 = sum(1, 1, N, i);
            long long r2 = sum(1, i+1, N, j);
            long long r3 = sum(1, j+1, N, M);
            if(ans < r1 * r2 * r3){
                ans = r1 * r2 * r3;
            }
        }
    }

    // 2번 경우
    for(int i = 1; i <= N - 2; i++){
        for(int j = i + 1; j <= N - 1; j++){
            long long r1 = sum(1, 1, i, M);
            long long r2 = sum(i+1, 1, j, M);
            long long r3 = sum(j+1, 1, N, M);
            if(ans < r1 * r2 * r3){
                ans = r1 * r2 * r3;
            }     
        }
    }

    // 3번 경우
    for(int i = 1; i <= N - 1; i++){
        for(int j = 1; j <= M - 1; j++){
            long long r1 = sum(1, 1, N, j);
            long long r2 = sum(1, j+1, i, M);
            long long r3 = sum(i+1, j+1, N, M);
            if(ans < r1 * r2 * r3){
                ans = r1 * r2 * r3;
            }            
        }
    }

    // 4번 경우
    for(int i = 1; i <= N - 1; i++){
        for(int j = 1; j <= M - 1; j++){
            long long r1 = sum(1, 1, i, j);
            long long r2 = sum(i+1, 1, N, j);
            long long r3 = sum(1, j+1, N, M);
            if(ans < r1 * r2 * r3){
                ans = r1 * r2 * r3;
            }
        }
    }

    // 5번 경우
    for(int i = 1; i <= N - 1; i++){
        for(int j = 1; j <= M - 1; j++){
            long long r1 = sum(1, 1, i, M);
            long long r2 = sum(i+1, 1, N, j);
            long long r3 = sum(i+1, j+1, N, M);
            if(ans < r1 * r2 * r3){
                ans = r1 * r2 * r3;
            }
        }
    }

    // 6번 경우
    for(int i = 1; i <= N - 1; i++){
        for(int j = 1; j <= M - 1; j++){
            long long r1 = sum(1, 1, i, j);
            long long r2 = sum(1, j+1, i, M);
            long long r3 = sum(i+1, 1, N, M);
            if(ans < r1 * r2 * r3){
                ans = r1 * r2 * r3;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}