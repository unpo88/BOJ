#include <iostream>
#include <algorithm>
using namespace std;

int DP[2][100001];
int ans[2][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		for (int i = 0; i <= 1; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> DP[i][j];
			}
		}

		int result;
		for (int i = 2; i <= N; i++) {
			DP[0][i] = max(DP[1][i - 1] + DP[0][i], DP[1][i - 2] + DP[0][i]);
			DP[1][i] = max(DP[0][i - 1] + DP[1][i], DP[0][i - 2] + DP[1][i]);
			result = max(DP[0][i], DP[1][i]);
		}

		cout << result << endl;
	}
	return 0;
}