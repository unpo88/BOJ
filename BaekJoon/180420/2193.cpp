#include <iostream>
using namespace std;

long long DP[91];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	
	DP[1] = 1;
	DP[2] = 1;

	for (int i = 3; i <= N; i++) {
		for (int j = 1; j <= i - 2; j++) {
			DP[i] += DP[j];
		}
		DP[i] += 1;
	}

	cout << DP[N];
	return 0;
}