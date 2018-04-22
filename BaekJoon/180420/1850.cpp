#include <iostream>
using namespace std;

int gcd(long long a, long long b)
{
	return b ? gcd(b, a%b) : a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long N, M;
	cin >> N >> M;

	for (int i = 1; i <= gcd(N, M); i++) {
		cout << "1";
	}
	
	return 0;
}