/*첫째 줄에는 별 1개, 둘째 줄에는 별 3개, ..., N번째 줄에는 별 2*N-1개를 찍는 문제

별은 가운데를 기준으로 대칭이어야 한다.

입력
첫째 줄에 N (1<=N<=100)이 주어진다.

출력
첫째 줄부터 N번째 줄 까지 차례대로 별을 출력한다.

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
    scanf("%d" ,&N);
    for(int i = 1; i <= N; i++){
        for(int j = N-i; j > 0; j--){
            printf(" ");
        }
        for(int j = 1; j <= i*2-1; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}