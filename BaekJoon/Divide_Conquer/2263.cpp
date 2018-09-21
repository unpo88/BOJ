#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int in_order[100000];
int post_order[100000];
int position[100001];

int N;

void solve(int in_start, int in_end, int post_start, int post_end){
    if (in_start > in_end || post_start > post_end) return;

    int root = post_order[post_end];

    printf("%d ",root);

    int p = position[root];
    
    // inorder:   in_start in_end
    // postorder: post_start post_end
    // left: p-in_start
    // right: in_end-p
    int left = p - in_start;
    solve(in_start, p - 1, post_start, post_start + left - 1);
    solve(p + 1, in_end, post_start + left, post_end - 1);
}

int main(){
    scanf("%d", &N);

    for(int i = 0; i < N; i++)  scanf("%d", &in_order[i]);

    for(int i = 0; i < N; i++)  scanf("%d", &post_order[i]);

    for(int i = 0; i < N; i++)  position[in_order[i]] = i;

    solve(0, N - 1, 0, N - 1);

    return 0;
}