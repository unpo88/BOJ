#include <iostream>
#include <algorithm>
using namespace std;

int N;
int input[2][16];
int answer;

int BFS(int idx) {
	if (idx + input[0][idx] > N + 1)	return 0;

	int result = input[1][idx];
	int sum = 0;
	for (int i = idx + input[0][idx]; i <= N; i++) {
		sum = max(sum, BFS(i));
	}

	return result + sum;
}
int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> input[0][i] >> input[1][i];
	}

	for (int i = 1; i <= N; i++) {
		answer = max(answer, BFS(i));
	}

	cout << answer << endl;

	return 0;
}