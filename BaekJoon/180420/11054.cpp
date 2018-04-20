#include <iostream>
using namespace std;

int DP[1001];
int ans[1001];
int ans2[1001];
int sum[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> DP[i];
	}

	for (int i = 1; i <= N; i++) {
		int min = 0;
		for (int j = 0; j < i; j++) {
			if (DP[i] > DP[j]) {
				if (min < ans[j]) {
					min = ans[j];
				}
			}
		}
		ans[i] = min + 1;
	}

	for (int i = N; i > 0; i--) {
		int min = 0;
		for (int j = N; j > i; j--) {
			if (DP[i] > DP[j]) {
				if (min < ans2[j]) {
					min = ans2[j];
				}
			}
		}
		ans2[i] = min + 1;
	}

	int max = 0;
	for (int i = 1; i <= N; i++) {
		sum[i] = ans[i] + ans2[i] - 1;
		if (max < sum[i]) {
			max = sum[i];
		}
	}

	cout << max;
	return 0;
}