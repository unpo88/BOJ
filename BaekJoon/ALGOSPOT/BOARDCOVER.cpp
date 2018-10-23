#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int C;
int H, W;

int board[20][20];

// 네 가지 방법
const int coverType[4][3][2] = {
    { { 0, 0 }, { 1, 0 }, { 0, 1 } },
    { { 0, 0 }, { 0, 1 }, { 1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 1, -1 } }
};

bool set(int board[][20], int y, int x, int type, int delta){
    bool ok = true;
    for(int i = 0; i < 3; i++){
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        if(ny < 0 || ny >= H || nx < 0 || nx >= W){
            ok = false;
        }else if((board[ny][nx] += delta) > 1){
            ok = false;
        }
    }
    return ok;
}

int cover(int board[][20]){
    int y = - 1;
    int x = -1;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(board[i][j] == 0){
                y = i;
                x = j;
                break;
            }
        }
        if(y != -1) break;
    }

    if(y == -1) return 1;
    int ret = 0;
    for(int type = 0; type < 4; type++){
        if(set(board, y, x, type, 1)){
            ret += cover(board);
        }
        set(board, y, x, type, -1);
    }
    return ret;
}

int main(){
    cin >> C;

    while(C--){
        cin >> H >> W;

        for(int i = 0; i < H; i++){
            string bw;
            cin >> bw;
            for(int j = 0; j < W; j++){
                board[i][j] = (bw[j] == '#') ? 1 : 0;
            }
        }
        
        cout << cover(board) << '\n';
    }
    return 0;
}