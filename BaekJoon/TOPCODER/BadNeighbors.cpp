#include <cstdio>
#include <algorithm>
using namespace std;

int donations[41];
int dp[41];

int N;

int answer;

int main(){
    scanf("%d", &N);

    for(int i = 1; i <= N; i++){
        scanf("%d", &donations[i]);
    }

    for(int i = 1; i <= N - 1; i++){
        dp[i] = donations[i];
        if(i > 1){
            dp[i] = max(dp[i], dp[i-1]);
        }
        if(i > 2){
            dp[i] = max(dp[i], dp[i-2] + donations[i]);
        }
        answer = max(answer, dp[i]);
    }

    for(int i = 1; i <= N - 1; i++){
        dp[i] = donations[i+1];
        if(i > 1){
            dp[i] = max(dp[i], dp[i-1]);
        }
        if(i > 2){
            dp[i] = max(dp[i], dp[i-2] + donations[i+1]);
        }
        answer = max(answer, dp[i]);
    }

    printf("%d\n", answer);

    return 0;
}