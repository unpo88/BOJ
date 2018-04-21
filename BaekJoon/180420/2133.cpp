#include <iostream>
using namespace std;

int dp[31];
int result[31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	dp[0] = 1;
	dp[2] = 3;
	result[0] = 1;

	for (int i = 4; i <= 30; i += 2) {
		dp[i] = 2;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= i; j += 2) {
			result[i] += dp[j] * result[i - j];
		}
	}

	cout << result[N];
	return 0;
}