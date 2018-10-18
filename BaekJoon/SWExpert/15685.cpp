#include <iostream>
#include <vector>
using namespace std;

bool map[102][102];

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> v;

    while(N--){
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        v.clear();

        map[y][x] = true;
        
        int nx = x + dx[d];
        int ny = y + dy[d];

        map[ny][nx] = true;

        v.push_back(d);
        
        for(int i = 0; i < g; i++){
            int size = (int)v.size();

            for(int i = size - 1; i >= 0; i--){
                int dir = (v[i] + 1) % 4;
                nx = nx + dx[dir];
                ny = ny + dy[dir];
                map[ny][nx] = true;
                v.push_back(dir);
            }
        }
    }

    int result = 0;
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            if(map[i][j] && map[i][j+1] && map[i+1][j+1] && map[i+1][j]){
                result++;
            }
        }
    }

    cout << result << '\n';
    
    
    return 0;
}

/*

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int map[105][105];

int N;

// 동, 북, 서, 남
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int cnt = 0;

void curve(int x, int y, int d, int g){
    map[y][x] = 1;

    vector<int> dir;

    dir.push_back(d);

    while(g--){
        cnt = 0;
        vector<int> dir2;
        for(int i = 0; i < dir.size(); i++){
            dir2.push_back(((dir[cnt++]+1)%4));
        }

        for(int i = dir2.size() - 1; i >= 0; i--){
            dir.push_back(dir2[i]);
        }
    }

    int nx = x;
    int ny = y;

    for(int i = 0; i < dir.size(); i++){
        if(nx < 0 || ny < 0 || nx > 100 || ny > 100)    continue;
        nx = nx + dx[dir[i]];
        ny = ny + dy[dir[i]];
        map[ny][nx] = 1;
    }
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        curve(x, y, d, g);
    }

    int answer = 0;

    for(int i = 0; i <= 99; i++){
        for(int j = 0; j <= 99; j++){
            if(map[i][j] == 1 && map[i+1][j+1] == 1 && map[i+1][j] == 1 && map[i][j+1]){
                answer++;
            }
        }
    }
    cout << answer << endl;
    return 0;
}

*/