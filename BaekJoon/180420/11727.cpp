#include <iostream>
using namespace std;

long long DP[1001];

int main(){
    int N;
    scanf("%d", &N);

    DP[0] = 1;
    DP[1] = 1;

    for(int i = 2; i <= 1000; i++){
        DP[i] = (DP[i-2] * 2 + DP[i-1]) % 10007;
    }

   printf("%lld", DP[N]);

    return 0;
}