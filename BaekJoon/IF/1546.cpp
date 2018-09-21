#include <cstdio>
#include <algorithm>
using namespace std;

double a[1000];
double max_number = 0;
double average = 0;

int main(){
    int N;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%lf", &a[i]);
        max_number = max(max_number, a[i]);
    }
    
    for(int i = 0; i < N; i++){
        a[i] = (a[i] / max_number) * 100;
        average += a[i];
    }

    average = average / N;

    printf("%.2f\n", average);

    return 0;
}