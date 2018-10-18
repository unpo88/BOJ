#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

int N, M;

int check[2000];
int flag;

vector<vector<int> > v;

void DFS(int now, int cnt){
    if(cnt == 4){
        flag = 1;
        return ;
    }
    check[now] = 1;
    for(int i = 0; i < v[now].size(); i++){
        int next = v[now][i];
        if(check[next] == 0){
            DFS(next, cnt + 1);
        }
        if(flag == 1)   return ;
    }
    check[now] = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    v.resize(N);

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 0; i < N; i++){
        DFS(i, 0);
        if(flag == 1)   break;
        memset(check, 0, sizeof(check));
    }

    if(flag == 1){
        cout << "1" << '\n';
    }else{
        cout << "0" << '\n';
    }
    return 0;       
}