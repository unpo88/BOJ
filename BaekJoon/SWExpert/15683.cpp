#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
struct Node {
    int x;
    int y;
    int num;
    Node(int x,int y,int n):x(x),y(y),num(n){}
};
 
int n, m, res;
int map[8][8];
int visited[8][8];
vector<Node> v;
 
 
//dir 0북 1동 2남 3서
void check(int x,int y, int dir,int flag) {
    if (dir == 0) {
        --x;
        while (x >= 0) {
            if (map[x][y] == 6)return;
            if (flag == 0) visited[x][y]++;
            else visited[x][y]--;
            x--;
        }
    }
    else if (dir == 1) {
        ++y;
        while (y < m) {
            if (map[x][y] == 6)return;
            if (flag == 0) visited[x][y]++;
            else visited[x][y]--;
            y++;
        }
    }
    else if (dir == 2) {
        ++x;
        while (x < n) {
            if (map[x][y] == 6)return;
            if (flag == 0) visited[x][y]++;
            else visited[x][y]--;
            x++;
        }
    }
    else {
        --y;
        while (y >= 0) {
            if (map[x][y] == 6)return;
            if (flag == 0) visited[x][y]++;
            else visited[x][y]--;
            y--;
        }
    }
}
 
int get_result() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j]==0 && visited[i][j]==0) ans++;
        }
    }
    return ans;
}
 
void printAll() {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]) cout << "# ";
            else cout <<map[i][j]<<" ";
        }
        cout << endl;
    }
}
 
void dfs(int idx) {
    if (idx == v.size()) {
        res = min(res, get_result());
        //printAll();
        return;
    }
 
    int x = v[idx].x;
    int y = v[idx].y;
    int num = v[idx].num;
 
    if (num == 1) {
        //4방향
        for (int i = 0; i < 4; i++) {
            check(x, y, i, 0);
            dfs(idx + 1);
            check(x, y, i, 1);
        }
    }
    else if (num == 2) {
        for (int i = 0; i < 2; i++) {
            check(x, y, i, 0);
            check(x, y, i + 2, 0);
            dfs(idx + 1);
            check(x, y, i, 1);
            check(x, y, i + 2, 1);
        }
    }
    else if (num == 3) {
        for (int i = 0; i < 4; i++) {
            check(x, y, i, 0);
            check(x, y, (i + 1 == 4) ? 0 : i + 1, 0);
            dfs(idx + 1);
            check(x, y, i, 1);
            check(x, y, (i + 1 == 4) ? 0 : i + 1, 1);
        }
    }
    else if (num == 4) {
        for (int i = 0; i < 4; i++) {
            check(x, y, i, 0);
            check(x, y, (i + 1 >= 4) ? i + 1 - 4 : i + 1, 0);
            check(x, y, (i + 2 >= 4) ? i + 2 - 4 : i + 2, 0);
            dfs(idx + 1);
            check(x, y, i, 1);
            check(x, y, (i + 1 >= 4) ? i + 1 - 4 : i + 1, 1);
            check(x, y, (i + 2 >= 4) ? i + 2 - 4 : i + 2, 1);
        }
    }
    else if (num == 5) {
        for (int i = 0; i < 4; i++)check(x, y, i, 0);
        dfs(idx + 1);
        for (int i = 0; i < 4; i++)check(x, y, i, 1);
    }
 
 
}
 
int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0 || map[i][j] == 6)continue;
            v.push_back(Node(i, j, map[i][j]));
        }
    }
 
    res = 987654321;
    dfs(0);
 
    cout << res << endl;
}
