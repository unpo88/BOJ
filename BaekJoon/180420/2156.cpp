#include <iostream>
#include <algorithm>
using namespace std;

int DP[10001];
int wine[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++){
		cin >> wine[i];
	}

	DP[1] = wine[1];
	DP[2] = wine[2] + wine[1];

	for (int i = 3; i <= N; i++) {
		int result = 0;
		result = max(wine[i] + DP[i - 2], DP[i - 1]);
		result = max(result, wine[i] + wine[i - 1] + DP[i - 3]);
		DP[i] = result;
	}

	cout << DP[N];
	return 0;
}