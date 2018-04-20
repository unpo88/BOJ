#include <iostream>
using namespace std;

long DP[1001][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int sum = 0;

	cin >> N;

	for (int i = 0; i < 10; i++) {
		DP[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				DP[i][j] = (DP[i][j] + DP[i - 1][k]) % 10007;
			}
		}
	}
	
	for (int i = 0; i < 10; i++) {
		sum = (sum + DP[N][i]) % 10007;
	}

	cout << sum;

	return 0;
}