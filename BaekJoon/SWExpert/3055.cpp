#include <iostream>
#include <queue>
#include <utility>
#include <cstdio>
using namespace std;

char map[51][51];

int visit_water[51][51];
int visit_go[51][51];

int R, C;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { 1, -1, 0, 0 };

queue<pair<int, int> > water;
queue<pair<int, int> > g;

int flag = false;

void BFS(){
    while(!water.empty()){
        flag = true;
        int wx = water.front().first;
        int wy = water.front().second;
        water.pop();
        for(int i = 0; i < 4; i++){
            int nx = wx + dx[i];
            int ny = wy + dy[i];
            if(nx <= 0 || ny <= 0 || nx > R || ny > C)  continue;
            if(map[nx][ny] != 'D' && map[nx][ny] != 'X' && visit_water[nx][ny] == 987654321){
                visit_water[nx][ny] = visit_water[wx][wy] + 1;
                water.push(make_pair(nx, ny));
            }
        }
    }

    while(!g.empty()){
        int gx = g.front().first;
        int gy = g.front().second;
        g.pop();
        for(int i = 0; i < 4; i++){
            int nx = gx + dx[i];
            int ny = gy + dy[i];
            
            if(nx <= 0 || ny <= 0 || nx > R || ny > C)  continue;

            if(!flag){
                if(map[nx][ny] == '.' && visit_go[nx][ny] == 0){
                    visit_go[nx][ny] = visit_go[gx][gy] + 1;
                    g.push(make_pair(nx, ny));
                }
            }else if(map[nx][ny] == '.' && visit_go[nx][ny] == 0 && (visit_go[gx][gy] + 1) < visit_water[nx][ny]){
                visit_go[nx][ny] = visit_go[gx][gy] + 1;
                g.push(make_pair(nx, ny));
            }

            if(map[nx][ny] == 'D' && visit_go[nx][ny] == -1){
                cout << visit_go[gx][gy] << endl;
                return ;
            }
        }
    }
    cout << "KAKTUS" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            visit_water[i][j] = 987654321;
        }
    }

    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> map[i][j];
            if(map[i][j] == '*'){
                visit_water[i][j] = 1;         
                visit_go[i][j] = -3;
                water.push(make_pair(i, j));   
            }else if(map[i][j] == 'S'){
                visit_go[i][j] = 1;
                g.push(make_pair(i, j));
            }else if(map[i][j] == 'D'){
                visit_go[i][j] = -1;
                visit_water[i][j] = -1;
            }else if(map[i][j] == 'X'){
                visit_go[i][j] = -2;
                visit_water[i][j] = -2;
            }
        }
    }

    BFS();
    
    return 0;
}