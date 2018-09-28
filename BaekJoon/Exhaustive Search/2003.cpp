#include <cstdio>

int num[10000];
long long M;
int N;
int ans;

void cal(int index, int sum){
    sum += num[index];
    
    if(index >= N){
        return ;
    }

    if(sum == M){
        ans++;
    }

    cal(index + 1, sum);
}


int main(){
    scanf("%d %lld", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d", &num[i]);
    }
    for(int i = 0; i < N; i++){
        cal(i, 0);
    }

    printf("%d\n", ans);

    return 0;
}