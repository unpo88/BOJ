#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	if (s == "0" && s.length() == 1) {
		cout << 0;
		return 0;
	}

	else if (s[0] == '1') {
		printf("1");
	}
	else if (s[0] == '2') {
		printf("10");
	}
	else if (s[0] == '3') {
		printf("11");
	}
	else if (s[0] == '4') {
		printf("100");
	}
	else if (s[0] == '5') {
		printf("101");
	}
	else if (s[0] == '6') {
		printf("110");
	}
	else if (s[0] == '7') {
		printf("111");
	}

	for (int i = 1; i < s.length(); i++) {
		if (s[i] == '0') {
			printf("000");
		}
		else if (s[i] == '1') {
			printf("001");
		}
		else if (s[i] == '2') {
			printf("010");
		}
		else if (s[i] == '3') {
			printf("011");
		}
		else if (s[i] == '4') {
			printf("100");
		}
		else if (s[i] == '5') {
			printf("101");
		}
		else if (s[i] == '6') {
			printf("110");
		}
		else if (s[i] == '7') {
			printf("111");
		}
	}
	
	return 0;
}