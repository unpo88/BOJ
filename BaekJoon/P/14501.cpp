#include <iostream>
#include <algorithm>
using namespace std;

int N;
int input[2][16];
int result;
int dp[16];

int DFS(int index) {
	if (index + input[0][index] >= N + 2) {
		return 0;
	}

	int rt = input[1][index];
	int MAX = 0;
	for (int i = index + input[0][index]; i <= N; i++) {
		MAX = max(MAX, DFS(i));
	}

	return MAX + rt;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> input[j][i];
		}
	}

	int maxx = 0;
	for (int i = 1; i <= N; i++) {
		maxx = max(maxx, DFS(i));
	}

	cout << maxx << endl;

	return 0;
}