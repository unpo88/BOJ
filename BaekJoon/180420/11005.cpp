#include <iostream>
using namespace std;

int arr[1000000];
int main() {
	long long N;
	int B;

	cin >> N >> B;

	int cnt = 0;
	while (N) {
		if (N / B == 0) {
			arr[cnt] = N;
			break;
		}
		else {
			arr[cnt] = N % B;
			cnt = cnt + 1;
			N = N / B;
		}
	}
	
	for (int i = cnt; i >= 0; i--) {
		if (arr[i] >= 10) {
			char a = 55;
			a = a + arr[i];
			cout << a;
		}
		else {
			cout << arr[i];
		}
	}


	return 0;
}