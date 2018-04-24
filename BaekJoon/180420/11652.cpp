#include <iostream>
#include <map>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    long long X;

    map<long long, int> m;
    while(N--){
        cin >> X;
        m[X]++;
    }

    int maxnum = -1;
    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second > maxnum){
            maxnum = it->second;
            X = it->first;
        }
    }

    cout << X;

    return 0;
}