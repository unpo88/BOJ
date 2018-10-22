#include <iostream>
#include <string>
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
            if(s[i] == '+')    continue;
            answer += (s[i] - '0');
        }

        cout << "#" << tc << " " << answer << '\n';
    }

    return 0;
}