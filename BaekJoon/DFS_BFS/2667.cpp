#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int check[26][26];
char map[26][26];
int cnt = 1;
vector<int> answer;

// 아래, 위, 왼쪽, 오른쪽
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

void DFS(int x, int y){
    check[x][y] = 1;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx <= 0 || nx > n || ny <= 0 || ny > n){
            continue;
        } 
        if(!check[nx][ny] && map[nx][ny] == '1'){
            cnt++;
            DFS(nx, ny);
        }else if(!check[nx][ny] && map[nx][ny] == '0'){
            check[nx][ny] = 1;
        }
    }
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!check[i][j] && map[i][j] == '1'){
                DFS(i, j);
                answer.push_back(cnt);
                cnt = 1;
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << "\n";
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << "\n";
    }
    return 0;
}