#include <iostream>
using namespace std;

long long dp[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;

	while (T--) {
		int N;
		cin >> N;
		
		for (int i = 6; i <= N; i++) {
			dp[i] = dp[i - 1] + dp[i - 5];
		}
		
		cout << dp[N] << endl;
	}
	return 0;
}