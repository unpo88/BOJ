#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	cout << gcd(N, M) << '\n';
	cout << (N*M) / gcd(N, M);
	return 0;
}