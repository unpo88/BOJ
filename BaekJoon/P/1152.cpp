#include <string>
#include <iostream>
using namespace std;

int main() {
	int count = 0;
	string s;

	while (cin >> s) {
		count++;
	}

	cout << count;
	return 0;
}