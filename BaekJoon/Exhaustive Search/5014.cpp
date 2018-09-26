#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

long long F,S,G,U,D;

queue<pair<int, int> > q;

int answer = - 1
long long visit[1000001];

int main(){
    scanf("%lld %lld %lld %lld %lld", &F, &S, &G, &U, &D);
    
    q.push(make_pair(S,0));
    visit[S] = 1;

    while(!q.empty()){
        int stair = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(stair == G){
            answer = cnt;
            break;
        }

        if(stair + U <= F && !visit[stair+U]){
            q.push(make_pair(stair+U, cnt+1));
            visit[stair+U] = 1;
        }

        if(stair - D > 0 && !visit[stair-D]){
            q.push(make_pair(stair-D, cnt+1));
            visit[stair-D] = 1;
        }
    }

    if(answer == -1){
        printf("use the stairs\n");
    }else{
        printf("%d\n", answer);
    }
    return 0;
}