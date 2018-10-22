#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int a[1000];

int main(){
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }

    sort(a, a + N);

    int answer = 0;
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += a[i];
        answer += sum;
    }

    printf("%d\n", answer);
    return 0;
}