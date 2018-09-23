#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;

bool possible(vector<int> &a, int c, int x){
    int cnt = 1;
    int last = a[0];

    for(int i = 1; i < a.size(); i++){
        int house = a[i];
        if(house - last >= x){
            cnt += 1;
            last = house;
        }
    }

    return cnt >= c;
}

int main(){
    scanf("%d %d", &N, &C);
    vector<int> a(N);
    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }

    sort(a.begin(), a.end());

    int l = 1;
    int r = a[N-1] - a[0];
    int ans = l;

    while(l <= r){
        int mid = (l + r) / 2;
        if(possible(a, C, mid)){
            if(ans < mid){
                ans = mid;
            }
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}