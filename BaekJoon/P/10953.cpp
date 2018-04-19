#include <iostream>
#include <string>
using namespace std;

int main(){
    int T;
    int A, B;
    char C;
    scanf("%d" , &T);
    while(T--){
        scanf("%d%c%d",&A,&C,&B);
		printf("%d",A+B);
    }
    return 0;
}