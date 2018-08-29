#include<cstdio>
#include<algorithm>
using namespace std;
pair<int, int> p[500000];
int bit[500001], n, r;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &p[i].first), p[i].second = i + 1;
    sort(p, p + n);
    for (int i = n - 1; i >= 0; i--) {
        int s = 0;
        for (int j = p[i].second; j; j -= j&-j) s += bit[j];
        r = max(r, s);
        for (int j = p[i].second; j <= n; j += j&-j) bit[j]++;
    }
    printf("%d", r + 1);
    return 0;
}