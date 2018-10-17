#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;

int R, C;
char map[101][101];
int c[101][101];
int N;

const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };

vector<pair<int, int> > group;

void dfs(int x, int y){
    if(map[x][y] == '.')    return ;
    if(c[x][y]) return ;
    c[x][y] = true;
    group.push_back(make_pair(x, y));

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < R && 0 <= ny && ny < C) {
            dfs(nx,ny);
        }
    }
}

void simulate(){
    memset(c, false, sizeof(c));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(map[i][j] == '.')    continue;
            if(c[i][j]) continue;
            group.clear();
            dfs(i, j);
            vector<int> low(C, -1);
            
            int count = 0;
            for(auto &p : group){
                low[p.second] = max(low[p.second], p.first);
                map[p.first][p.second] = '.';
            }
            int lowest = R;
            for (int i, j=0; j<C; j++) {
                if (low[j] == -1) continue;
                for (i=low[j]; i<R && map[i][j]=='.'; i++);
                lowest = min(lowest, i-low[j]-1);
            }
            for(auto &p : group){
                p.first += lowest;
                map[p.first][p.second] = 'x';
                c[p.first][p.second] = true;
            }
        }
    }
}

int main(){
    cin >> R >> C;

    for (int i=0; i<R; i++) {
        cin >> map[i];
    }

    cin >> N;

    for(int i = 0; i < N; i++){
        int height;
        cin >> height;
        height = R - height;

        if(i % 2 == 0){
            for(int j = 0; j < C; j++){
                if(map[height][j] == 'x'){
                    map[height][j] = '.';
                    break;
                }
            }
        }else{
            for(int j = C - 1; j >= 0; j--){
                if(map[height][j] == 'x'){
                    map[height][j] = '.';
                    break;
                }
            }
        }
    }
    simulate();

    for(int i = 0; i < R; i++){
        cout << map[i] << '\n';
    }

    return 0;
}