#include <cstdio>

int N;

void solve(int n, int x, int y){
    if(n == 0){
        return;
    }

    solve(n-1, x, 6-x-y);
    printf("%d %d\n", x, y);
    solve(n-1, 6-x-y, y);
}

int main(){
    scanf("%d", &N);
    printf("%d\n", (1 << N) - 1);
    solve(N, 1, 3);

    return 0;
}