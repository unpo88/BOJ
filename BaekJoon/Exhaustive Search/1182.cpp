#include <cstdio>

int num[20];

int N;
int S;

int ans;

void cal(int index, int sum){
    sum += num[index];

    if(index >= N){
        return ;
    }

    if(sum == S){
        ans++;
    }

    cal(index + 1, sum - num[index]);
    cal(index + 1, sum);
}

int main(){
    scanf("%d %d", &N, &S);

    for(int i = 0; i < N; i++){
        scanf("%d", &num[i]);
    }

    cal(0, 0);

    printf("%d\n", ans);
    return 0;
}