#include <iostream>
using namespace std;

int price[1001];
int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> price[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i <= j) {
				if (dp[j] <= dp[j - i] + price[i]) {
					dp[j] = dp[j - i] + price[i];
				}
			}
			cout << dp[j] << " ";
		}
		cout << endl;
	}


	cout << dp[N];
	

	return 0;

}