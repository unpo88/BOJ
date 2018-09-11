#include <cstdio>

int N;
int a[500002];
int temp[500002];

long long int answer;

void merge(int start, int end){
    int middle = (start + end) / 2;

    int i = start;
    int j = middle + 1;
    int k = start;

    while(i <= middle && j <= end){
        if(a[i] > a[j]){
            answer += (long long)(middle - i + 1);
            temp[k++] = a[j++];
        }else{
            temp[k++] = a[i++];
        }
    }

    while(i <= middle){
        temp[k++] = a[i++];
    }

    while(j <= end){
        temp[k++] = a[j++];
    }

    for(int t = start; t <= end; t++){
        a[t] = temp[t];
    }
}

void divide(int start, int end){
    if(start != end){
        int middle = (start + end) / 2;
        divide(start, middle);
        divide(middle+1, end);
        merge(start, end);
    }
}

int main(){
    scanf("%d", &N);
    
    for(int i = 1; i <= N; i++){
        scanf("%d", &a[i]);
    }

    divide(1, N);
    
    printf("%lld", answer);
    return 0;
}