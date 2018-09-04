#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001

int N;

int u, v;

vector<int> tree[MAX];

int parent[MAX];

bool check[MAX];

queue<int> q;

int main(){
    scanf("%d", &N);

    for(int i = 0; i < N - 1; i++){
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    parent[1] = 0;
    check[1] = true;
    q.push(1);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto y : tree[x]){
            if(!check[y]){
                check[y] = true;
                parent[y] = x;
                q.push(y);
            }
        }
    }

    for(int i = 2; i <= N; i++){
        printf("%d\n", parent[i]);
    }

    return 0;
}