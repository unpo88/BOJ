#include <cstdio>
using namespace std;

int N;

char relations[50][50];
int map[50][50];
int salary[50];
int answer;

int main(){
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        int cnt = 0;
        for(int j = 0; j < N; j++){
            scanf("%1s", &relations[i][j]);
            if(relations[i][j] == 'Y'){
                map[i][j] = 1;
            }else if(relations[i][j] == 'N'){
                cnt = cnt + 1;
            }
        }
        if(cnt == N){
            salary[i] = 1;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 1){
                salary[i] = salary[i] + salary[j];
            }
        }
    }

    for(int i = 0; i < N; i++){
        answer += salary[i];
    }

    printf("%d", answer);
    
    return 0;
}