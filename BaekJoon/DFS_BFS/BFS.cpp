#include <iostream>
#include <cstdio>
using namespace std;

int n;
int map[30][30];
int queue[30];
int visit[30];
int front, rear;
int start;

int BFS(int visit);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> start;

    while(1){
        int v1, v2;
        cin >> v1 >> v2;
        if(v1 == -1 && v2 == -1){
            break;
        }
        map[v1][v2] = map[v2][v1] = 1;
    }

    BFS(start);

    return 0;
}

int BFS(int v){
    visit[v] = 1;
    queue[rear++] = v;
    while(front < rear){
        v = queue[front++];
        for(int i = 1; i <= n; i++){
            if(map[v][i] == 1 && !visit[i]){
                visit[i] = 1;
                cout << v << "에서 " << i << "로 이동" << endl;
                queue[rear++] = i;
            }
        }
    }
}