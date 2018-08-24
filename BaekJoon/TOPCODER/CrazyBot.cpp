#include <iostream>
using namespace std;

bool grid[100][100] = {false};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

double prob[4];

double dfs(int x, int y, int n);

int main(){
    ios::sync_with_stdio(false);

    int n;
    int east, west, south, north;

    cin >> n;
    cin >> east;
    cin >> west;
    cin >> south;
    cin >> north;

    prob[0] = east/100.0;
    prob[1] = west/100.0;
    prob[2] = south/100.0;
    prob[3] = north/100.0;

    cout << dfs(50, 50, n);

    return 0;
}

double dfs(int x, int y, int n){
    if(grid[x][y])  return 0;       // true 방문시 확률 0
    if(n == 0)  return 1;           // 횟수가 0이면 무조건 성공(확률 1)
    
    grid[x][y] = true;
    double ret = 0;
    for(int i = 0; i < 4; i ++){
        // east, west, south, north 순으로 로봇을 움직입니다.
        ret += dfs(x + dx[i], y + dy[i], n-1) * prob[i];
    }
    grid[x][y] = false;
    
    return ret;
}