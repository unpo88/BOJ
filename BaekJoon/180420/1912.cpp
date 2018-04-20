#include <iostream>
using namespace std;

int dp[100001];
int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	int max2 = -99999;
	for (int i = 1; i <= N; i++) {
		if (dp[i - 1] + arr[i] > arr[i]) {
			dp[i] = dp[i - 1] + arr[i];
		}
		else {
			dp[i] = arr[i];
		}
		if (max2 < dp[i]) {
			max2 = dp[i];
		}
	}

	/*int max = dp[1];

	for (int i = 2; i <= N; i++) {
		if (max < dp[i]) {
			max = dp[i];
		}
	}*/
	cout << max2;
	return 0;
}