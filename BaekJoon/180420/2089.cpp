#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long N;
	cin >> N;

	int arr[100];

	if (N == 0) {
		cout << "0";
	}
	else {
		int cnt = 0;
		while (N != 1) {
			arr[cnt] = abs(N % (-2));
			N = (int)ceil((double)N / (-2));
			cnt = cnt + 1;
		}
		arr[cnt] = N;

		for(int i = cnt; i >= 0; i--){
			cout << arr[i];
		}
	}
	return 0;
}