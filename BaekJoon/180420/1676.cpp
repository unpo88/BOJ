#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int result = 0;

	while (N /= 5) {
		result += N;
	}

	cout << result;

	return 0;
}