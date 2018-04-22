#include <iostream>
#define mod 1000000000
using namespace std;

long long dp[201][201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		dp[1][i] = 1;
	}

	for (int i = 0; i <= N; i++) {
		dp[2][i] = i + 1;
	}

	for (int i = 3; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
			}
		}
	}
	cout << dp[K][N] % mod;
	
	return 0;
}