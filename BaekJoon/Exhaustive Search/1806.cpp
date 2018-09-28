#include <cstdio>
#include <vector>
using namespace std;

int N, S;

int sum;
int ans;

int L, R;

int main(){
    scanf("%d %d", &N, &S);
    vector<int> v(N);

    for(int i = 0; i < N; i++){
        scanf("%d", &v[i]);
    }

    sum = v[0];
    ans = N + 1;

    while(L <= R && R < N){
        if(sum < S){
            R++;
            sum += v[R];
        }else if(sum == S){
            if(ans > R - L + 1){
                ans = min(ans, R - L + 1);
            }
            R++;
            sum += v[R];
        }else if(sum > S){
            if(ans > R - L + 1){
                ans = min(ans, R - L + 1);
            }
            sum -= v[L];
            L++;
        }
    }

    if(ans > N){
        printf("0\n");
    }else{
        printf("%d\n", ans);
    }
    return 0;
}