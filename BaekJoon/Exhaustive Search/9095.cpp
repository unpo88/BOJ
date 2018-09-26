#include <cstdio>

int go(int sum, int goal){
    if(sum > goal){
        return 0;
    }
    if(sum == goal){
        return 1;
    }
    int now = 0;
    for(int i = 1; i <= 3; i++){
        now += go(sum+i, goal);
    }
    return now;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int num;
        scanf("%d", &num);
        printf("%d\n", go(0, num));
    }
    return 0;
}