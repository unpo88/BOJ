#include <iostream>
#include <cstdio>
using namespace std;

int N, testCase;
int v1, v2;

int map[1001][1001];
int visit[1001];

int start = 1;
int answer;

void DFS(int v);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> testCase;
    
    for(int i = 0; i < testCase; i++){
        cin >> v1 >> v2;
        map[v1][v2] = map[v2][v1] = 1;
    }

    for(int i = 1; i <= N; i++){
        if(visit[i] == 0){
            DFS(i);
            answer++;
        }
    }

    cout << answer;
    return 0;
}

void DFS(int v){
    visit[v] = 1;

    for(int i = 1; i <= N; i++){
        if(map[v][i] == 1 && visit[i] == 0){
            DFS(i);
        }
    }
}