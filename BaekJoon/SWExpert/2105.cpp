#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
int N;

int map[25][25];
int v[101];
int ans, sx, sy;

const int dx[4]={-1,-1,1,1};
const int dy[4]={-1,1,-1,1};
 
void dfs(int x,int y,int l,int d,int c)
{
    if(c >= 5) return;

    v[map[x][y]]=true;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx==sx && ny==sy && l>=4 && c>=3)
        { 
            ans=max(ans,l);
            v[map[x][y]]=false;
            return;
        }

        if(nx < 0 || nx >= N || ny < 0 || ny >= N || v[map[nx][ny]])    continue;
        dfs(nx, ny, l + 1, i, i == d ? c : c + 1);
    }
    
    v[map[x][y]]=false;
}
 
int main()
{
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++)
    {
        ans = -1;
        cin >> N;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> map[i][j];
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                sx = i;
                sy = j;
                dfs(i, j, 1, -1, 0);
            }
        }

        cout << "#" << tc << " " << ans << '\n';
    }
    return 0;
}
