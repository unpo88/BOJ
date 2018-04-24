#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
    string s;
    getline(cin,s);

    for(int i = 0; i < s.size(); i++){
        if(isalpha(s[i])){
            if(s[i] < 78){
                cout << char(s[i] + 13);
            }else if(s[i] >= 79 && s[i] <= 90){
                cout << char(s[i] - 13);
            }else if(s[i] >= 97 && s[i] < 110){
                cout << char(s[i] + 13);
            }else{
                cout << char(s[i] - 13);
            }
        }else{
            cout << char(s[i]);
        }
    }
    
    return 0;
}