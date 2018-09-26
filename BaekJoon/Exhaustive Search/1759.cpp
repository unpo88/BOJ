#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int L, C;

bool check(string &password){
    int ja = 0;
    int mo = 0;
    for(int i = 0; i < password.size(); i++){
        if(password[i] == 'a' || password[i] == 'e' || password[i] == 'o' || password[i] == 'i' || password[i] == 'u'){
            mo += 1;
        }else{
            ja += 1;
        }
    }
    return ja >= 2 && mo >= 1;
}
void go(int n, vector<char> &alpha, string password, int i){
    if(n == password.size()){
        if(check(password)){
            cout << password << endl;
        }
        return ;
    }

    if(i >= alpha.size()){
        return ;
    }
    go(n, alpha, password+alpha[i], i + 1);
    go(n, alpha, password, i+1);

}

int main(){
    cin >> L >> C;
    vector<char> c(C);
    for(int i = 0; i < C; i++){
        cin >> c[i];
    }

    sort(c.begin(), c.end());

    go(L, c, "", 0);

    return 0;
}