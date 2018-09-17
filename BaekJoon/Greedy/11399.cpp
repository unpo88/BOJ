#include <cstdio>
#include <algorithm>
using namespace std;

struct ATM{
    int number;
    int time;

};

bool cmp(const ATM &a, const ATM &b){
    if(a.time == b.time){
        return a.number < b.number;
    }else{
        return a.time < b.time;
    }
}

ATM arr[1000];
int N;

int sum;
int answer;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        arr[i].number = i + 1;
        scanf("%d", &arr[i].time);
    }

    sort(arr, arr + N, cmp);

    for(int i = 0; i < N; i++){
        printf("%d %d\n", arr[i].number, arr[i].time);
        sum += arr[i].time;
        answer += sum;
    }

    printf("%d\n", answer);
    return 0;
}