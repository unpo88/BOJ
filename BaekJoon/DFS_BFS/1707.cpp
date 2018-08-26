#include <iostream>
#include <vector>
using namespace std;

int testCase;
int V, E;
int v1, v2;

vector<int> map[20001];
int color[20001];

void DFS(int v, int c){
    color[v] = c;
    for(int i = 0; i < map[v].size(); i++){
        int next = map[v][i];
        if(color[next] == 0){
            DFS(next, 3-c);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> testCase;
    while(testCase--){
        cin >> V >> E;
        for(int i = 1; i <= V; i++){
            map[i].clear();
            color[i] = 0;
        }

        for(int i = 0; i < E; i++){
            cin >> v1 >> v2;
            map[v1].push_back(v2);
            map[v2].push_back(v1);
        }

        for(int i = 1; i <= V; i++){
            if(color[i] == 0){
                DFS(i, 1);
            }
        }
        bool ok = true;
        for(int i = 1; i <= V; i++){
            for(int j = 0; j < map[i].size(); j++){
                int k = map[i][j];
                if(color[k] == color[i]){
                    ok = false;
                }
            }
        }
        if(ok){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}