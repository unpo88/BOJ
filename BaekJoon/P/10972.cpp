#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	if (next_permutation(v.begin(), v.end())) {
		for (int i = 0; i < N; i++) {
			cout << v[i] << ' ';
		}
	}
	else {
		cout << "-1";
	}
}
