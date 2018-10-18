#include <iostream>
using namespace std;

int N;

int A[1000001];
int B, C;

int answer;

int main(){
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    cin >> B >> C;

    answer = answer + N;

    for(int i = 1; i <= N; i++){
        A[i] -= B;

        if(A[i] > 0){
            if(A[i] % C == 0){
                answer += (A[i] / C);
            }else{
                answer += (A[i] / C) + 1;
            }
        }
    }
    cout << answer << endl;

    return 0;
}