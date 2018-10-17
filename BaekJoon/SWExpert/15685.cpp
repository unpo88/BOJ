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