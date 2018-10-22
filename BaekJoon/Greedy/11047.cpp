#include <iostream>
#include <vector>
using namespace std;

int N, K;

int sum;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    for(int i = v.size() - 1; i >= 0; i--){
        if(v[i] > K)    continue;
        if(v[i] <= K){
            int n = 0;
            n += K / v[i];
            K -= n * v[i];
            sum += n;
        }
    }

    cout << sum << '\n';

    return 0;
}