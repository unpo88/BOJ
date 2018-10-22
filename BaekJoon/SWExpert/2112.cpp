#include <iostream>
using namespace std;

int answer;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    
    for(int tc = 1; tc <= T; tc++){


        cout << "#" << tc << " " << answer;
    }
}