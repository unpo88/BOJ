#include <cstdio>

int N;
long long K;
int A[10];

int answer;

int main(){
    scanf("%d", &N);
    scanf("%lld", &K);
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    for(int i = N - 1; i >= 0; i--){
        if(A[i] <= K){
            answer += K / A[i];
            K = K % A[i];
        }
    }

    printf("%d\n", answer);


    return 0;
}