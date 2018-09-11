#include <cstdio>

int N;
int arr[50001];
int sorted[50001];

void merge(int a[], int m, int middle, int n){
    int i = m;
    int j = middle + 1;
    int k = m;

    while(i <= middle && j <= n){
        if(a[i] <= a[j]){
            sorted[k] = a[i];
            i++;
        }else{
            sorted[k] = a[j];
            j++;
        }
        k++;
    }

    if(i > middle){
        for(int t = j ; t <= n; t++){
            sorted[k] = a[t];
            k++;
        }
    }else{
        for(int t = i; t <= middle; t++){
            sorted[k] = a[t];
            k++;
        }
    }

    for(int t = m ; t <= n; t++){
        a[t] = sorted[t];
    }
}

void MergeSort(int a[], int L, int R){
    if(L < R){
        int middle = (L + R) / 2;
        MergeSort(a, L, middle);
        MergeSort(a, middle + 1, R);
        merge(a, m, middle, R);
    }
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);        
    }

    MergeSort(arr, 0, N - 1);

    for(int i = 0; i < N; i++){
        printf("%d", arr[i]);
    }

    return 0;
}