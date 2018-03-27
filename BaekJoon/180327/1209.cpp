/*[제약 사항]

총 10개의 테스트 케이스가 주어진다.

배열의 크기는 100X100으로 동일하다.

각 행의 합은 integer 범위를 넘어가지 않는다.

동일한 최댓값이 있을 경우, 하나의 값만 출력한다.
 
[입력]

각 테스트 케이스의 첫 줄에는 테스트 케이스 번호가 주어지고 그 다음 줄부터는 2차원 배열의 각 행 값이 주어진다.

[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 테스트 케이스의 답을 출력한다.*/

#include <cstdio>

#define MAX 100
int main(){
    for(int t = 1; t <= 10; t++){
        int tc;

        int max = 0;
        int r_sum = 0;
        int c_sum = 0;
        int p_sum = 0;
        int q_sum = 0;

        int data[MAX][MAX];
        scanf("%d", &tc);

        for(int i = 0; i < MAX; i++){
            r_sum = 0;
            for(int j = 0; j < MAX; j++){
                scanf("%d",&data[i][j]);
                r_sum += data[i][j];
            }
            if( max < r_sum )
                max = r_sum;
        }

        for(int i = 0; i < MAX; i++){
            c_sum = 0;
            for(int j = 0; j < MAX; j++){
                c_sum += data[j][i];
            }
            if( max < c_sum )
                max = c_sum;
        }

        for(int i = 0; i < MAX; i++){
            p_sum += data[i][i];
        }
        if( max < p_sum )
            max = p_sum;

        int MAX_VAR = MAX;
        for(int i = 0; i < MAX; i++){
            q_sum += data[i][MAX_VAR-1];
            MAX_VAR--;
        }

        if( max < q_sum )
            max = q_sum;


        printf("#%d %d\n", tc, max);
    }
    return 0;
}