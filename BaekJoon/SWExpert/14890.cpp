#include <iostream>
#include <vector>
using namespace std;

bool go(vector<int> &a, int l){
    int n = a.size();
    vector<bool> c(n, false);
    for(int i = 1; i < n; i++){
        if(a[i-1] != a[i]){
            int diff = a[i] - a[i-1];
            if(diff < 0)    diff *= -1;
            if(diff != 1)   return false;
            if(a[i-1] < a[i]){
                for(int j = 1; j <= l; j++){
                    if(i - j < 0)   return false;
                    if(a[i-1] != a[i-j])    return false;
                    if(c[i-j])  return false;
                    c[i-j] = true;
                }
            }else{
                for(int j = 0; j < l; j++){
                    if(i+j >= n)    return false;
                    if(a[i] != a[i+j])  return false;
                    if(c[i+j])  return false;
                    c[i+j] = true;
                }
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    vector<vector<int> > a(N, vector<int>(N));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }

    int ans = 0;

    for(int i = 0; i < N; i++){
        vector<int> d;
        for(int j = 0; j < N; j++){
            d.push_back(a[i][j]);
        }
        if(go(d, L))    ans += 1;
    }

    for(int j = 0; j < N; j++){
        vector<int> d;
        for(int i = 0; i < N; i++){
            d.push_back(a[i][j]);
        }
        if(go(d, L))    ans += 1;
    }

    cout << ans << '\n';

    return 0;
}