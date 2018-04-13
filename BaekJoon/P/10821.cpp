#include <string>
#include <iostream>
using namespace std;

int main() {
	string s1;
	int num = 0;
	while (getline(cin, s1, ',')) {
		num++;
	}
	cout << num;
	return 0;
}