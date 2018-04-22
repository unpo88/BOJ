#include <iostream>
using namespace std;


int gcd(long long a, long long b)
{
	return b ? gcd(b, a%b) : a;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	
	while (T--) {
		int N;
		long long arr[100] = { 0, };
		long long sum = 0;
		cin >> N;

		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}
		cout << sum << '\n';
	}
	
	return 0;
}