#include <cstdio>
#include <algorithm>
using namespace std;

struct time_table{
    int start_time;
    int end_time;
};

int N;

time_table arr[100000];

int answer;
int now;

bool cmp(const time_table &a, const time_table &b){
    if(a.end_time == b.end_time){
        return a.start_time < b.start_time;
    }else{
        return a.end_time < b.end_time;
    }
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &arr[i].start_time, &arr[i].end_time);
    }

    // 오름차순 정렬, 만약 끝나는 시간이 같으면 시작 시간이 작은 순으로
    sort(arr, arr + N, cmp);

    for(int i = 0; i < N; i++){
        if(now <= arr[i].start_time){
            now = arr[i].end_time;
            answer++;
        }
    }

    printf("%d\n", answer);

    return 0;   
}