#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1;
	cin >> s1;

	for (char i = 'a'; i <= 'z'; i++) {
		cout << count(s1.begin(), s1.end(), i) << ' ';
	}

	return 0;
}