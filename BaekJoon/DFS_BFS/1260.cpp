#include <iostream>
#include <cstdio>
using namespace std;

int N;      // 정점의 개수
int M;      // 간선의 개수
int start;  // 시작점의 위치

int v1, v2;

int DFS_visit[1001];
int BFS_visit[1001];

int map[1001][1001];

int queue[1001];
int rear, front;

void DFS(int v);
void BFS(int v);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> start;
    
    for(int i = 0; i < M; i++){
        cin >> v1 >> v2;
        map[v1][v2] = map[v2][v1] = 1;
    }
    DFS(start);
    cout << endl;
    BFS(start);

    return 0;
}

void DFS(int v){
    DFS_visit[v] = 1;

    if(v == start){
        cout << v << " ";
    }

    for(int i = 1; i <= N; i++){
        if(DFS_visit[i] == 0 && map[v][i] == 1){
            cout << i << " ";
            DFS(i);
        }
    }
}

void BFS(int v){
    cout << v << " ";
    BFS_visit[v] = 1;
    queue[rear++] = v;
    while(front < rear){
        v = queue[front++];
        for(int i = 1; i <= N; i++){
            if(map[v][i] == 1 && BFS_visit[i] == 0){
                BFS_visit[i] = 1;
                cout << i << " ";
                queue[rear++] = i;
            }
        }
    }
}