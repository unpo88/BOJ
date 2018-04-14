#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	string s1;
	string s2;

	int A, B;
	while (T--) {
		getline(cin, s1, ',');
		A = stoi(s1);
		getline(cin, s2);
		B = stoi(s2);
		printf("%d\n", A+B);
	}

	return 0;
}