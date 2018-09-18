#include <cstdio>

int N, M;

int A[50][50];
int B[50][50];

int answer;

int main(){
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d", &A[i][j]);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d", &B[i][j]);
        }
    }
    
    for(int i = 0; i <= N - 3; i++){
        for(int j = 0; j <= M - 3; j++){
            if(A[i][j] != B[i][j]){
                for(int k = i; k < i + 3; k++){
                    for(int k2 = j; k2 < j + 3; k2++){
                        if(A[k][k2] == 0){
                            A[k][k2] = 1;
                        }else{
                            A[k][k2] = 0;
                        }
                    }
                }
                answer++;
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(A[i][j] != B[i][j]){
                printf("-1\n");
                return 0;
            }
        }
    }
    
    printf("%d\n", answer);

    return 0;
}