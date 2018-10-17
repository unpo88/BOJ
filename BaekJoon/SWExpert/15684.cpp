#include <iostream>
using namespace std;

int N, M, H;
int map[31][31] = { 0, };
int result = -1;

void BackTracking(int m, int cnt){
    if(m == cnt){
        for(int col = 1; col <= N; col++){
            int start = col;
            for(int row = 1; row <= H; row++){
                if(map[row][start] == 0)    continue;
                if(map[row][start] > 0){
                    if(map[row][start] == 1){
                        ++start;
                        continue;
                    }else if(map[row][start] == 2){
                        --start;
                        continue;
                    }
                }
            }
            if(col != start)    return;
        }
        result = cnt;
        return ;
    }

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= N-1; j++){
            if(map[i][j] == 0 && map[i][j+1] == 0){
                map[i][j] = 1;
                map[i][j + 1] = 2;

                BackTracking(m, cnt + 1);

                map[i][j] = 0;
                map[i][j + 1] = 0;
            }
        }
    }
}
 
int main(){
    int row, col;
    cin >> N >> M >> H;

    for(int i = 0; i < M; i++){
        cin >> row >> col;
        
        map[row][col] = 1;
        map[row][col + 1] = 2;
    }

    for(int i = 0; i < 4; i++){
        BackTracking(i, 0);
        if(result != -1)    break;
    }

    cout << result << '\n';
    return 0;
}