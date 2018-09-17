#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

string s;

int cur;
int answer;
bool check = false;

vector<int> number;
vector<int> sign;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s;
    
    sign.push_back(1);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+' || s[i] == '-'){
            if(s[i] == '-'){
                sign.push_back(-1);
            }else if(s[i] == '+'){
                sign.push_back(1);
            }
            number.push_back(cur);
            cur = 0;
        }else{
            cur = cur * 10 + (s[i] - '0');
        }
    }
    number.push_back(cur);

    for(int i = 0; i < number.size(); i++){
        if(sign[i] == -1){
            check = true;
        }
        if(check){
            answer -= number[i];
        }else{
            answer += number[i];
        }
    }

    cout << answer << endl;
    return 0;
}