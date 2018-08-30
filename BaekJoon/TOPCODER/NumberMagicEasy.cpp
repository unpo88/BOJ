#include <cstdio>
#include <algorithm>
using namespace std;

int card[4][16] = {
                    { 1, 2, 3, 4, 5, 6, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 1, 2, 3, 4, 0, 0, 0, 0, 9, 10, 11, 12, 0, 0, 0, 0 },
                    { 1, 2, 0, 0, 5, 6, 0, 0, 9, 10, 0, 0, 13, 14, 0, 0 },
                    { 1, 0, 3, 0, 5, 0, 7, 0, 9, 0, 11, 0, 13, 0, 15, 0 }
                 };

int check[17];

char answer[4];
int result;

int main(){
    for(int i = 0; i < 4; i++){
        scanf("%1s", &answer[i]);
    }

    for(int i = 0; i < 4; i++){
        if(answer[i] == 'Y'){
            for(int j = 0; j < 16; j++){
                if(card[i][j] != 0){
                    check[card[i][j]]++;
                }
            }
        }else if(answer[i] == 'N'){
            for(int j = 0; j < 16; j++){
                if(card[i][j] == 0){
                    check[j+1]++;
                }
            }
        }
    }

    for(int i = 1; i <= 16; i++){
        result = max(result, check[i]);
    }

    for(int j = 1; j <= 16; j++){
        if(check[j] == result){
            printf("%d", j);
            return 0;
        }
    }
    return 0;
}