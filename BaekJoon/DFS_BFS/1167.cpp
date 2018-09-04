#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 100001;

vector<pair<int, int> > tree[MAX];
bool check[MAX];

int V;

int u, v, w;

int diameter;
int farthestNode;

void DFS(int start, int total){
    if(check[start]){
        return ;
    }
    check[start] = true;

    if(diameter < total){
        diameter = total;
        farthestNode = start;
    }

    for(int i = 0; i < tree[start].size();i++){
        DFS(tree[start][i].first, total + tree[start][i].second);
    }
}

int main(){
    scanf("%d", &V);

    for(int i = 0; i < V; i++){
        int cnt = 1;

        while(scanf("%d", &u)){
            if(u == -1){
                break;
            }
            if(cnt == 1){
                v = u;
                cnt = cnt + 1;
            }else{
                scanf("%d", &w);
                tree[v].push_back(make_pair(u, w));
            }
        }
    }

    memset(check, false, sizeof(check));
    DFS(1, 0);
    memset(check, false, sizeof(check));
    diameter = 0;
    DFS(farthestNode, 0);

    printf("%d", diameter);

    return 0;
}