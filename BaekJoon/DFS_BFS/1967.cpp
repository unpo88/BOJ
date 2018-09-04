#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10001

vector<pair<int, int> > tree[MAX];
vector<int> leaf;
bool visit[MAX];

int N;
int u, v, w;

int total;
int result;

void DFS(int last, int cost){
    visit[last] = true;
    for(int i = 0; i < tree[last].size(); i++){
        if(!visit[tree[last][i].first]){
            total = max(total, cost + tree[last][i].second);
            DFS(tree[last][i].first, cost + tree[last][i].second);
        }
    }
}

int main(){
    scanf("%d", &N);

    for(int i = 0; i < N - 1; i++){
        scanf("%d %d %d", &u, &v, &w);
        tree[u].push_back(make_pair(v, w));
        tree[v].push_back(make_pair(u, w));
    }

    for(int i = 1; i <= N; i++){
        if(tree[i].size() == 1){
            leaf.push_back(i);
        }
    }

    for(int i = 0; i < leaf.size(); i++){
        total = 0;
        memset(visit, false, sizeof(visit));
        DFS(leaf[i], total);
        result = max(result, total);
    }

    printf("%d", result);

    return 0;
}