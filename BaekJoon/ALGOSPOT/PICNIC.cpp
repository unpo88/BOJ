#include <iostream>
#include <cstring>
using namespace std;

int N, M;

bool map[11][11];

int countPair(bool taken[10]){
    int idx = -1;
    for(int i = 0; i < N; i++){
        if(!taken[i]){
            idx = i;
            break;
        }
    }

    if(idx == -1)  return true;

    int ret = 0;

    for(int i = idx + 1; i < N; i++){
        if(!taken[i] && map[idx][i]){
            taken[idx] = taken[i] = true;
            ret += countPair(taken);
            taken[idx] = taken[i] = false;
        }
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int C;
    cin >> C;

    while(C--){
        memset(map, false, sizeof(map));

        cin >> N >> M;

        for(int i = 0; i < M; i++){
            int a, b;
            cin >> a >> b;
            map[a][b] = map[b][a] = true;
        }

        bool taken[11];
        memset(taken, false, sizeof(taken));
        cout << countPair(taken) << '\n';
    }

    return 0;
}