#include <iostream>
using namespace std;

int isNotPrime[100003];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 2; i * i < 100003; i++){
        if(!isNotPrime[i]){
            for(int j = i*i; j < 100003; j += i){
                isNotPrime[j] = 1;
            }
        }
        isNotPrime[1] = 1;
    }

    while(1){
        int N;
        cin >> N;

        if(N == 0){
            break;
        }

        bool check = false;
        for(int i = 3; i <= N; i+=2){
            if(!isNotPrime[i] && !isNotPrime[N-i]){
                cout << N << " = " << i << " + " << N-i << '\n';
                check = true;
                break;
            }
        }
        if(!check){
            cout << "Goldbach's conjecture is wrong.\n";
            }
    }
    return 0;
}