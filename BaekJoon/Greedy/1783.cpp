#include <cstdio>
#include <algorithm>
using namespace std;
int N, M;

int main(){
    scanf("%d %d", &N, &M);

    if(N == 1){
        printf("%d\n", 1);
    }else if(N == 2){
        printf("%d\n", min(4, (M+1)/2));
    }else if(N >= 3){
        if(M >= 7){
            printf("%d\n", M-2);
        }else{
            printf("%d\n", min(4, M));
        }
    }
    return 0;
}