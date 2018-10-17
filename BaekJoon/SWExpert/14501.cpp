#include <iostream>
#include <algorithm>
using namespace std;

int N;

int input[2][16];

int dfs(int index){
    if(index + input[0][index] >= N + 2){
        return 0;
    }

    int result = input[1][index];
    int MAX = 0;
    for(int i = index + input[0][index]; i <= N; i++){
        MAX = max(MAX, dfs(i));
    }

    return result + MAX;
}

int main(){
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> input[0][i] >> input[1][i];
    }

    int answer = 0;
    for(int i = 1; i <= N; i++){
        answer = max(answer, dfs(i));
    }

    cout << answer << '\n';
    return 0;
}