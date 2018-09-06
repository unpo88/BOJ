#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int N;

string arr[100];

string solve(int n, int y, int x, int jump){
    if(n == 1){
        string res = "";
        res += arr[y][x];
        return res;
    }
    
    string first = "";
    first += arr[y][x];
    string lu = solve(n / 2, y, x, jump / 2);
    string ru = solve(n / 2, y, x + jump, jump / 2);
    string ld = solve(n / 2, y + jump, x, jump / 2);
    string rd = solve(n / 2, y + jump, x + jump, jump / 2);

    if(lu == first && ru == first && ld == first && rd == first){
        return first;
    }

    return '(' + lu + ru + ld + rd + ')';
}

int main(){
    scanf("%d", &N);

    getchar();
    for(int i = 0; i < N; i++){
        getline(cin, arr[i]);
    }
    
    cout << solve(N, 0, 0, N / 2);
    return 0;
}