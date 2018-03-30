#include <cstdio>

int dp[101];
int price[10001];

int main() {
	int n, k;
	

	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &dp[i]);
	}

	price[0] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= dp[i]) {
				price[j] += price[j - dp[i]];
			}
		}
	}

	printf("%d\n", price[k]);

	return 0;
}