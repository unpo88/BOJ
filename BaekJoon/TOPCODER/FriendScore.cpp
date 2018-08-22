#include <iostream>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    int data[51][51] = {0, };

    int N;
    cin >> N;

    char s;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> s;
            if(s == 'N')
                data[i][j] = 0;
            else if(s == 'Y')
                data[i][j] = 1;
        }
    }

    int answer = 0;

    int direct_friend[51] = {0, };
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(data[i][j] == 1){
                direct_friend[i]++;
            }else if(i != j){
                for(int k = 1; k <= N; k++){
                    if(data[j][k] == 1 && data[j][k] == data[i][k]){
                        direct_friend[i]++;
                    }
                }
            }
        }
        answer = max(answer, direct_friend[i]);
    }

    cout << answer;
    return 0;
}