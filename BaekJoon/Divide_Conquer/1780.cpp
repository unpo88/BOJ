#include <cstdio>

int N, input[2187][2187];

int a[3] = { 0, };

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
        if(cur == -1){
            a[0]++;
        }else if(cur == 0){
            a[1]++;
        }else if(cur == 1){
            a[2]++;
        }
    }else if(size == 1 && !flag){
        for(int i = y; (i < y + size) && flag; i++){
            for(int j = y; (j < y + size) && flag; j++){
                if(cur == -1){
                    a[0]++;
                }else if(cur == 0){
                    a[1]++;
                }else if(cur == 1){
                    a[2]++;
                }
            }
        }
    }else{
        solve(x, y, size/3);
        solve(x + size/3, y, size/3);
        solve(x + size/3*2, y, size/3);
        solve(x, y + size/3, size/3);
        solve(x + size/3, y + size/3, size/3);
        solve(x + size/3*2, y + size/3, size/3);
        solve(x, y + size/3*2, size/3);
        solve(x + size/3, y + size/3*2, size/3);
        solve(x + size/3*2, y + size/3*2, size/3);
    }
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &input[i][j]);
        }
    }

    solve(0, 0, N);

    for(int i = 0; i < 3; i++){
        printf("%d\n", a[i]);
    }

    return 0;
}