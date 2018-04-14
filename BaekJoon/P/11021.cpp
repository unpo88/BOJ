#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	int A, B;

	for(int tc = 1; tc <= T; tc++) {
		cin >> A >> B;
		cout << "Case #" << tc << ": " << A + B << '\n';
	}

	return 0;
}