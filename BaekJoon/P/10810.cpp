#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> v1(N,0);

	while (M--) {
		int i, j, k;
		cin >> i >> j >> k;
		fill(v1.begin()+(i-1), v1.begin()+j, k);
	}

	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << ' ';
	}
	return 0;
}