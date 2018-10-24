#include <iostream>
#include <cstring>
using namespace std;

int C, N, M;

bool map[10][10];
bool taken[10];

int countPair(){
    int idx = -1;
    for(int i = 0; i < N; i++){
        if(!taken[i]){
            idx = i;
            break;
        }
    }

    if(idx == -1)   return 1;

    int ret = 0;
    for(int i = idx + 1; i < N; i++){
        if(!taken[i] && map[idx][i]){
            taken[i] = taken[idx] = true;
            ret += countPair();
            taken[i] = taken[idx] = false;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> C;

    while(C--){
        memset(map, false, sizeof(map));
        memset(taken, false, sizeof(taken));

        cin >> N >> M;

        for(int i = 0; i < M; i++){
            int a, b;
            cin >> a >> b;
            map[a][b] = map[b][a] = true;
        }

        cout << countPair() << '\n';
    }
    
    return 0;
}