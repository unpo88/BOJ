#include <iostream>
#include <algorithm>
using namespace std;

int a[21][21];
bool c[21];
int n;
int ans = 987654321;

void go(int num, int now){
    if(num > n / 2) return ;
    
    if(num == n/2){
        int ans1 = 0;
        int ans2 = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(c[i] && c[j]){
                    ans1 += a[i][j];
                }
                else if(!c[i] && !c[j]){
                    ans2 += a[i][j];
                }
            }
        }
        ans = min(ans, abs(ans1 - ans2));
        return ;
    }

    for(int i = now + 1; i <= n; i++){
        if(!c[i]){
            c[i] = true;
            go(num + 1, i);
            c[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    go(0, 0);
    cout << ans << endl;

    return 0;
}