#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	string s1;
	string line;
	while (cin >> line) {
		s1 += line;
	}

	istringstream sin(s1);

	string number;
	int sum = 0;

	while (getline(sin, number, ',')) {
		sum += stoi(number);
	}

	cout << sum;
	return 0;
}