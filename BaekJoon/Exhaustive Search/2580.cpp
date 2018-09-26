#include <cstdio>
#include <cstdlib>
using namespace std;

int map[10][10];

bool visit_1[10][10];
bool visit_2[10][10];
bool visit_3[10][10];

int square(int x, int y){
    return (x/3)*3 + (y/3);
}

bool go(int z){
    if (z == 81) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
				printf("%d ", map[i][j]);
            }
            printf("\n");
        }
        return true;
    }
    int x = z/9;
    int y = z%9;
    if (map[x][y] != 0) {
        return go(z+1);
    } else {
        for (int i=1; i<=9; i++) {
            if (visit_1[x][i] == 0 && visit_2[y][i] == 0 && visit_3[square(x,y)][i]==0) {
                visit_1[x][i] = visit_2[y][i] = visit_3[square(x,y)][i] = true;
                map[x][y] = i;
                if(go(z+1)){
                    return true;
                }
                map[x][y] = 0;
                visit_1[x][i] = visit_2[y][i] = visit_3[square(x,y)][i] = false;
            }
        }
    }
    return false;
}

int main(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] != 0){
                visit_1[i][map[i][j]] = true;
                visit_2[j][map[i][j]] = true;
                visit_3[square(i,j)][map[i][j]] = true;
            }
        }
    }

    go(0);
    return 0;
}