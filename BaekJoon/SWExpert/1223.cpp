#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int tc = 1; tc <= 10; tc++){
        int N;
        string s;

        cin >> N;
        cin >> s;

        int answer = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*'){
                int mul = 1;
                mul *= s[i-1] - '0';
                //cout << s[i-1] << endl;
                int j = i+1;
                while(s[j] != '+' && j < s.size()){
                    if(s[j] == '*'){
                        j++;
                    }else{
                        mul *= s[j] - '0';
                        //cout << s[j] << endl;
                        j++;
                    }
                }
                i = j;
                answer += mul;
            }else if(s[i] == '+'){
                answer += s[i-1] - '0';
            }

            if(i == s.size() - 1){
                answer += s[i] - '0';
            }
        }        

        cout << "#" << tc << " " << answer << endl;
    }
    return 0;
}