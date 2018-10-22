#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int start, end;
    node(int s, int e):
        start(s), end(e)    {}
};

int N;

vector<node> v;

bool cmp(const node &a, const node &b){
    if(a.end == b.end){
        return a.start < b.start;
    }else{
        return a.end < b.end;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        int start, end;
        cin >> start >> end;
        v.push_back(node(start, end));
    }

    sort(v.begin(), v.end(), cmp);

    int answer = 0;
    int now = 0;
    for(int i = 0; i < N; i++){
        if(now <= v[i].start){
            now = v[i].end;
            answer++;
        }
    }

    cout << answer << '\n';
    return 0;
}