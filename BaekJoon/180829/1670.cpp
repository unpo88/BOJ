#include <cstdio>

unsigned long long C[100001];

int main(){
    int N;
    scanf("%d", &N);

    C[1] = 1;
    for(int i = 2; i <= N/2; i++){
        C[i] = C[i-1] * 2;
        for(int j = 1; j <= i-2; j++){
            C[i] += (C[j] * C[i-j-1]);
            C[i] = C[i] % 987654321;
        }
    }

    if(N % 2 == 0){
        N /= 2;
        printf("%lld", C[N]);
    }else{
        printf("0");
        return 0;
    }
    return 0;
}