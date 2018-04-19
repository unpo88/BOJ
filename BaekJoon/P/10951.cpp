#include <iostream>
using namespace std;

int main(){
    int A, B;
    while(scanf("%d %d", &A, &B) == 2){
        if(A==0 && B==0){
            return 0;
        }
        printf("%d" A+B);
    }
    return 0;
}