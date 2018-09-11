#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

long long N;
long long K;
vector<long long> v;

int answer;
int cnt;

int main(){
    scanf("%lld %lld", &N, &K);

    for(int i = 0; i < N; i++){
        long long num;
        scanf("%lld", &num);
        v.push_back(num);
    }

    reverse(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        if(v[i] > K){
            continue;
        }else{
            answer = (K / v[i]);
            cnt += answer;
            K = K - (v[i] * answer);
        }
    }

    printf("%d", cnt);

    return 0;
}