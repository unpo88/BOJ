#include <bitset>
#include <iostream>
using namespace std;

int main() {
	bitset<100000> b1;
	bitset<100000> b2;

	cin >> b1 >> b2;

	cout << (b1 & b2) << '\n';
	cout << (b1 | b2) << '\n';
	cout << (b1 ^ b2) << '\n';
	cout << (~b1) << '\n';
	cout << (~b2) << '\n';

	return 0;
}