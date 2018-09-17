#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;

int main(){
    scanf("%d %d %d", &N, &M, &K);

    vector<int> a(N);

    // 반드시 돌아가야하는 조건
    if(M + K - 1 <= N && N <= M * K){
        for(int i = 0; i < N; i++){
            a[i] = i + 1;
        }
        vector<int> g;  // 그룹의 경계
        g.push_back(0);
        g.push_back(K); // 적어도 한 그룹은 K개가 되어야함
        N -= K;
        M -= 1;

        int gs = M == 0 ? 1 : N / M;
        int r = M == 0 ? 0 : N % M;
        
        // 그룹의 크기를 각각 결정해준다. 랜덤으로 정해주는 것이 아니라
        // 두 가지 종류가 있는 것임
        // 그룹의 크기를 K의 배수이지만 일부는 K-1
        // 그룹의 크기는 N/M
        // 각 그룹의 수를 뒤집어준다
        // 출력하면 된다.
        for(int i = 0; i < M; i++){
            g.push_back(g.back() + gs + (r > 0 ? 1 : 0));
            if(r > 0){
                r -= 1;
            }
        }

        for(int i = 0; i < g.size() - 1; i++){
            reverse(a.begin() + g[i], a.begin() + g[i+1]);
        }

        for(int i = 0; i < a.size(); i++){
            printf("%d ", a[i]);
        }
        printf("\n");
    }else{
        printf("-1\n");
    }

    return 0;
}