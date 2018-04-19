/*
*********
 *******
  *****
   ***
    *
   ***
  *****
 *******
*********
*/

#include <iostream>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j < i; j++){
            printf(" ");
        }
        for(int j = 2 * N - (i * 2 -1); j > 0; j--){
            printf("*");
        }
        printf("\n");
    }

    for(int i = N -1; i > 0; i--){
        for(int j = 1; j < i; j++){
            printf(" ");
        }
        for(int j = 2 * N - (i * 2 - 1); j > 0; j--){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}