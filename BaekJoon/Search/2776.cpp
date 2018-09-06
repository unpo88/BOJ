#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int T, N, M;

int a[1000001];

int K;

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            scanf("%d", &a[i]);
        }
        sort(a, a + N);

        scanf("%d", &M);
        while(M--){
            scanf("%d", &K);
            int left = 0;
            int right = N - 1;
            int search = 0;
            while(left <= right){
                int mid = (left + right) / 2;
                if(a[mid] == K){
                    search = 1;
                    break;
                }else if(a[mid] > K){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            printf("%d\n", search);
        }
    }

    return 0;
}