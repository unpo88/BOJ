#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;

int N, M;

int num;

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N; i++){
        scanf("%d", &num);
        a.push_back(num);
    }

    for(int i = 0; i < M; i++){
        scanf("%d", &num);
        a.push_back(num);
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < a.size(); i++){
        printf("%d ", a[i]);
    }
    return 0;
}