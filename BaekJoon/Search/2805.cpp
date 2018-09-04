#include <cstdio>
#include <climits>

long long N, M;
long long tree[1000001];

long long max = 0;

int main(){
    scanf("%lld %lld", &N, &M);
    
    for(int i = 0; i < N; i++){
        scanf("%lld", &tree[i]);
        if(max < tree[i]){
            max = tree[i];
        }
    }

    long long left = 0;
    long long right = max;
    long long result = 0;

    while(left <= right){
        long long mid = (left + right) / 2;
        long long total = 0;
        for(int i = 0; i < N; i++){
            if(tree[i] > mid){
                total += tree[i] - mid;
            }
        }

        if(total >= M){
            if(result < mid){
                result = mid;
            }
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    printf("%lld", result);
    
    return 0;
}