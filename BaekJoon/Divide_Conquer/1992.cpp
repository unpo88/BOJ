#include <cstdio>

int N, input[64][64];

void solve(int x, int y, int size){
    int cur = input[y][x];
    bool flag = true;
    for(int i = y; (i < y + size) && flag; i++){
        for(int j = x; (j < x + size) && flag; j++){
            if(cur != input[i][j]){
                flag = false;
            }
        }
    }

    if(flag){
        printf("%d", cur);
    }else{
        printf("(");
        solve(x, y, size/2);
        solve(x + size/2, y, size/2);
        solve(x, y + size/2, size/2);
        solve(x + size/2, y + size/2, size/2);
        printf(")");
    }

    return ;
}

int main(){
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%1d", &input[i][j]);
        }
    }

    solve(0, 0, N);
    return 0;
}