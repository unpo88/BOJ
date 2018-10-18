#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <limits.h>
using namespace std;

#define MAX 100000

int N, K;

queue<pair<int, int> > q;

int visit[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    q.push(make_pair(0, N));

    int ret = INT_MAX;
    int cnt = 0;
    
    if(N == K)  cout << "0";
    else{
        while(!q.empty()){
            int x = q.front().second;
            int cnt = q.front().first;

            q.pop();
            visit[x] = 1;

            if(x == K)  ret = min(ret, cnt);

            if(x * 2 <= MAX && visit[x * 2] == 0 && x * 2 >= 0)    
                q.push(make_pair(cnt, x * 2));
            if(x + 1 <= MAX && visit[x + 1] == 0 && x + 1 >= 0)
                q.push(make_pair(cnt + 1, x + 1));
            if(x - 1 <= MAX && x - 1 >= 0 && visit[x-1] == 0)
                q.push(make_pair(cnt + 1, x - 1));
        }
        cout << ret << '\n';
    }
    return 0;
}