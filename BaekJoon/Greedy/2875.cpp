#include <cstdio>

int N, M, K;

int female;

int answer;

int main(){
    scanf("%d %d %d", &N, &M, &K);

    while(K){
        female = N / 2;

        if(female >= M){
            N--;
        }else{
            M--;
        }
        K--;
    }

    for(int i = 1; i <= M; i++){
        if(N >= 2){
            N -= 2;
            answer++;
        }
    }

    printf("%d", answer);
    return 0;
}