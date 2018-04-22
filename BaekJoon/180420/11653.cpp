#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int i = 2;
	while (N) {
		if (N == 1) {
			break;
		}
		if (N % i == 0) {
			N = N / i;
			cout << i << '\n';
		}
		else {
			i++;
		}
	}
	return 0;
}