#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };

int answer = 0;
int height = 0;

int N, K;

int map[8][8];
bool visit[8][8];


void DFS(int x, int y, int len, int s){
    visit[x][y] = true;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny])  continue;
        if(map[x][y] > map[nx][ny]){
            DFS(nx, ny, len + 1, s);
        }else if(!s && map[x][y] > map[nx][ny] - K){
            int temp = map[nx][ny];
            map[nx][ny] = map[x][y] - 1;
            DFS(nx, ny, len + 1, 1);
            map[nx][ny] = temp;
        }
    }

    visit[x][y] = false;
    answer = max(answer, len);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){
        answer = 0;
        height = 0;

        cin >> N >> K;

        vector<pair<int, int> > v;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> map[i][j];
                if(height < map[i][j])  height = map[i][j];
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(map[i][j] == height){
                    v.push_back(make_pair(i, j));
                }
            }
        }

        for(int i = 0; i < v.size(); i++){
            DFS(v[i].first, v[i].second, 1, 0);
        }

        cout << "#" << tc << " " << answer << '\n';
    }
}