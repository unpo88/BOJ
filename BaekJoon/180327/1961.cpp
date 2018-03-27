#include <cstdio>

int input_data[8][8];
int output_data_90[8][8];
int output_data_180[8][8];
int output_data_270[8][8];

void spin(int N){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            output_data_90[j][N-i+1] = input_data[i][j];
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            output_data_180[j][N-i+1] = output_data_90[i][j];
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            output_data_270[j][N-i+1] = output_data_180[i][j];
        }
    }

    
}

void testCase(){
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            scanf("%d", &input_data[i][j]);
        }
    }
    
    spin(N);

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            printf("%d", output_data_90[i][j]);
        }
        printf(" ");

        for(int j = 1; j <= N; j++){
            printf("%d", output_data_180[i][j]);
        }
        printf(" ");

        for(int j = 1; j <= N; j++){
            printf("%d", output_data_270[i][j]);
        }
    }
    
    
}

int main(){
    int T;
    scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++){
        printf("#%d\n",tc);
        testCase();
    }
}