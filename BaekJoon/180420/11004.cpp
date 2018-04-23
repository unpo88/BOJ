#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> v1(N);

    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }
    sort(v1.begin(),v1.end());
    cout << v1[K-1] << '\n';
    return 0;
}