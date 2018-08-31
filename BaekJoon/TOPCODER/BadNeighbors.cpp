#include <cstdio>
#include <algorithm>
using namespace std;

int donations[41];
int check[41];
int check2[41];

int N;

int answer;

int main(){
    scanf("%d", &N);

    for(int i = 1; i <= N; i++){
        scanf("%d", &donations[i]);
        check[i] = check2[i] = donations[i];
    }

    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= N; j++){
            if(i == 1){
                if(j == N){
                    check[j] = 0;
                    continue;
                }else{
                    if(j == 1 || j == 2){
                        answer = max(answer, check[j]);
                        continue;
                    }else{
                        check[j] = max((check[j] + check[j-3]), (check[j] + check[j-2]));
                        answer = max(answer, check[j]);
                    }
                }
            }else if(i == 2){
                if(j == 1){
                    check2[j] = 0;
                    continue;
                }else{
                    if(j == 2 || j == 3){
                        answer = max(answer, check2[j]);
                        continue;
                    }else{
                        check2[j] = max((check2[j] + check2[j-3]), (check2[j] + check2[j-2]));
                        answer = max(answer,check2[j]);
                    }
                }
            }
        }
    }

    printf("%d\n", answer);

    return 0;
}