#include <cstdio>

int N;
int M;

int number;

int visit[20000001];

int main(){
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &number);
        if(number == 0){
            visit[number]++;
        }else if(number > 0){
            number = number + 10000000;
            visit[number]++;
        }else{
            number = number * -1;
            visit[number]++;
        }
    }

    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d", &number);
        if(number > 0){
            number = number + 10000000;
        }else if(number < 0){
            number = number * -1;
        }
        printf("%d", visit[number]);
        if(i != M - 1){
            printf(" ");
        }
    }
    return 0;
}