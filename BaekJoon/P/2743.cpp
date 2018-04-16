#include <string>
#include <iostream>
using namespace std;

int main() {
	string s1;
	while (getline(cin, s1)) {
		int cnt = 0;
		for (char x : s1) {
			cnt++;
		}
		cout << cnt;
	}
	return 0;
}