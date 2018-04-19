/*

   *
  * *
 *   *
*******

*/

#include <iostream>
using namespace std;
int main(){
    int N;
    scanf("%d", &N);

    bool flag;

    for(int i = 1; i <= N; i++){
        if(i == N){
                for(int k = 1; k <= i*2-1; k++){
                    printf("*");
                }
             break;
        }
        flag = true;
        for(int j = N-i; j > 0 ; j--){
            printf(" ");
        }
        for(int j = 1; j <= 1; j++){
            printf("*");
            for(int k = (i - 1) * 2 - 1; k > 0 && flag == true; k--){
                printf(" ");
            }
            if(i != 1){
                printf("*");
            }
            flag = false;
        }
        printf("\n");
    }
    return 0;
}