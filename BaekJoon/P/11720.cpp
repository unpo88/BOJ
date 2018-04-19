
#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A;
    int Sum = 0;
    while(N--){
        while(scanf("%d",&A)==1){
            Sum+=A;
        }
        printf("%d",Sum);
    }
    return 0;
}