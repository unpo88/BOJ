#include <iostream>
using namespace std;

int DP[1001];

int main(){
    int N;
    scanf("%d", &N);

    DP[1] = 1;
    DP[2] = 2;

    for(int i = 3; i <= 1000; i++){
        DP[i] = DP[i-2] + DP[i-1] % 10007;
    }

    printf("%d", DP[N]);

    return 0;
}