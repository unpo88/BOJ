#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    vector<string> v(s.size());

    for(int i = 0; i < s.size(); i++){
        v[i] = s.substr(i);
    }

    sort(v.begin(), v.end());

    for(auto x : v){
        cout << x << '\n';
    }

    return 0;
}