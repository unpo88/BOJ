#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s1;
	int sum = 0;
	while (getline(cin, s1, ',')) {
		sum += stoi(s1);
	}

	cout << sum;
	return 0;
}