#include <iostream>
#include <algorithm>
using namespace std;

int arr[301];
int dp[301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= 3 && i <= N; i++) {
		if (i != 3) {
			dp[i] = dp[i - 1] + arr[i];
		}
		dp[i] = max(arr[i] + dp[i - 2], arr[i] + arr[i - 1]);
	}

	for (int i = 4; i <= N; i++) {
		dp[i] = max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);
	}

	cout << dp[N];
	return 0;
}