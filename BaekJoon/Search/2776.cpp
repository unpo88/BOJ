#include <cstdio>
#include <algorithm>
using namespace std;

int testCase, N, M;

int a[100001];

int num;

int main(){
    scanf("%d", &testCase);

    while(testCase--){
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            scanf("%d", &a[i]);
        }
        sort(a, a + N);

        scanf("%d", &M);
        while(M--){
            scanf("%d", &num);
            int left = 0;
            int right = N - 1;
            int answer = 0;
            while(left <= right){
                int mid = (left + right) / 2;
                if(a[mid] == num){
                    answer = 1;
                    break;
                }else if(a[mid] > num){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            printf("%d\n", answer);
        }
    }

    return 0;
}