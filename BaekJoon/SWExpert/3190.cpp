#include <iostream>
#include <cstring>
using namespace std;

// 오른쪽, 아래, 왼쪽, 위
const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

// 사과 위치
bool apple[100][100] = { false, };

// 지도
int map[100][100];

// 크기
int N;

// 사과 개수
int K;

// 명령어 개수
int L;

// 명령어 형태
// 초, (왼, 오)
int M;
char ch;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> K;
    while(K--){
        int x, y;
        cin >> x >> y;
        apple[x-1][y-1] = true;
    }

    memset(map, -1, sizeof(map));

    int x = 0;
    int y = 0;
    int dir = 0;
    int len = 1;
    map[x][y] = 0;
    cin >> L;
    int now = 0;
    
    for(int k = 0; k <= L; k++){
        M = N * N + 1;
        ch = 'L';
        if(k < L){
            cin >> M >> ch;
        }
        while(now < M){
            now += 1;
            x += dx[dir];
            y += dy[dir];
            if(x < 0 || x >= N || y < 0 || y >= N){
                cout << now << '\n';
                return 0;
            }
            if(apple[x][y]){
                apple[x][y] = false;
                len += 1;
            }
            if(map[x][y] != -1 && now - map[x][y] <= len){
                cout << now << '\n';
                return 0;
            }
            map[x][y] = now;
        }
        if(ch == 'L'){
            dir = (dir + 3) % 4;
        }else{
            dir = (dir + 1) % 4;
        }
    }
    return 0;
}