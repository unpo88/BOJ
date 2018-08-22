#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    
    string s;
    cin >> s;

    for(int i = s.size(); ; i++){
        bool flag = true;
        for(int j = 0; j < s.size(); j++){
            if((i-j-1) < s.size() && s[j] != s[i-j-1]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << i;
            break;
        }
    }
    return 0;
}