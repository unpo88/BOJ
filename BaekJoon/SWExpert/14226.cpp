#include <iostream>
#include <queue>
using namespace std;

int S;

bool check[1003][2003];
int dist[1003][2003];

int main(){
    cin >> S;
    queue<pair<int, int> > q;

    // 원본, 복사
    q.push(make_pair(1, 0));
    check[1][0] = true;
    dist[1][0] = 0;

    int cnt = 0;
    bool flag = false;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == S){
            cout << dist[x][y] << endl;
            flag = true;
            return 0;
        }
        if(check[x][x] == false){
            q.push(make_pair(x, x));
            check[x][x] = true;
            dist[x][x] = dist[x][y] + 1;
        }
        if(y != 0 && (x + y <= S) && check[x + y][y] == false){
            q.push(make_pair(x + y, y));
            check[x + y][y] = true;
            dist[x + y][y] = dist[x][y] + 1;
        }
        if(x >= 1 && check[x-1][y] == false){
            q.push(make_pair(x - 1, y));
            check[x - 1][y] = true;
            dist[x - 1][y] = dist[x][y] + 1;
        }
    }
    return 0;
}