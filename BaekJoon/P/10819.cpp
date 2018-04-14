#include <iostream>
#include <algorithm>
using namespace std;

int N;
int v[8];
int maxi, tot;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	sort(v, v+N);

	do {
		tot = 0;
		for (int i = 0; i < N - 1; i++) {
			tot += abs(v[i] - v[i + 1]);
		}
		maxi = max(maxi, tot);
	} while (next_permutation(v, v + N));

	cout << maxi;
	return 0;
}