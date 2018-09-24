#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int N;

vector<pair<int, int> > v;

int map[2001][2001];

const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };

int ans;

void draw(int x1, int y1, int x2, int y2){
    for(int i = x1; i <= x2; i++){
        map[i][y1] = map[i][y2] = 1;
    }
    for(int i = y1; i <= y2; i++){
        map[x1][i] = map[x2][i] = 1;
    }
}

void BFS(int sx, int sy){
    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));
    map[sx][sy] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= 2000 || ny >= 2000)  continue;
            if(map[nx][ny] == 1){
                map[nx][ny] = 0;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main(){
    scanf("%d", &N);
    int x1, y1, x2, y2;
    
    for(int i = 0; i < N; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1 = x1 * 2 + 1000;
        x2 = x2 * 2 + 1000;
        y1 = y1 * 2 + 1000;
        y2 = y2 * 2 + 1000;

        draw(x1, y1, x2, y2);
        v.push_back(make_pair(x1, y1));
    }

    BFS(1000, 1000);

    for(int i = 0; i < v.size(); i++){
        int x = v[i].first;
        int y = v[i].second;
        if(!map[x][y])  continue;
        ans++;
        BFS(x,y);
    }
    printf("%d\n", ans);
    return 0;
}