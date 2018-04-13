#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1;
	cin >> s1;

	for (char i = 'a'; i <= 'z'; i++) {
		auto it = find(s1.begin(), s1.end(), i);
		if (it == s1.end()) {
			cout << "-1" << ' ';
		}
		else {
			cout << it - s1.begin() << ' ';
		}
	}

	return 0;
}