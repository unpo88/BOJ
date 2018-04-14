#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		v[i] = i+1;
	}

	do {
		for (int i = 0; i < N; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));
	
	return 0;
}
