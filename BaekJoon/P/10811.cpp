#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> v1(N);
	for (int i = 0; i < v1.size(); i++) {
		v1[i] = (i+1);
	}

	while (M--) {
		int i, j;
		cin >> i >> j;
		reverse(v1.begin() + (i - 1), v1.begin() + j);
	}

	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << ' ';
	}
	return 0;
}