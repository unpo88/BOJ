#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);

	vector<int> v(N);

	for (int i = 0; i < v.size(); i++) {
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.end());

	cout << v[0] << ' ' << v[N - 1];
	return 0;
}