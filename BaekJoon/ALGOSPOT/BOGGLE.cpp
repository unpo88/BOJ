#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct point{
    int x, y;
    string s;
    string status;
};

char map[6][6];
bool check = false;

const int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void board_Init(){
    for(int i = 0; i < 5; i++){
        cin >> map[i];
    }
}

void print_All(){
    cout << endl << endl;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
}

void DFS(int x, int y, int k, int idx, vector<point> &v){
    if(idx == v[k].s.size()){
        check = 1;
        v[k].status = "YES";
        return ;
    }

    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5)  continue;
        if(map[nx][ny] != v[k].s[idx])  continue;
        if(!check){
            DFS(nx, ny, k, idx + 1, v);
        }else{
            return ;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int C;
    cin >> C;

    while(C--){
        board_Init();
        //print_All();
        int N;
        cin >> N;

        vector<point> v(N);
        for(int i = 0; i < N; i++){
            cin >> v[i].s;
            v[i].status = "NO";
        }

        for(int k = 0; k < v.size(); k++){
            check = false;
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    if(v[k].s[0] == map[i][j]){
                        DFS(i, j, k, 1, v);
                    }
                }
            }
        }

        for(int i = 0; i < v.size(); i++){
            cout << v[i].s << " " << v[i].status << "\n";
        }
    }
    return 0;
}