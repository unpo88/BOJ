#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int w[10][10];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			scanf("%d", &w[i][j]);					// 경로 비용 저장
		}
	}

	vector<int> d(n);
	for (int i = 0; i<n; i++) {
		d[i] = i;
	}

	int ans = 2147483647;							// 들어갈 수 있는 가장 큰 비용

	do {
		bool ok = true;
		int sum = 0;
		for (int i = 0; i<n - 1; i++) {
			if (w[d[i]][d[i + 1]] == 0) {			// 갈 수 없는 경로라면
				ok = false;							// false
				break;
			}
			else {
				sum += w[d[i]][d[i + 1]];			// 비용 다 더해봐
			}
		}
		if (ok && w[d[n - 1]][d[0]] != 0) {			// 갈 수 있고, 마지막 장소에서 바로 옴
			sum += w[d[n - 1]][d[0]];
			if (ans > sum) ans = sum;				 // 최소 비용 저장
		}
	} while (next_permutation(d.begin()+1, d.end()));	// 길의 모든 경로 체크

	printf("%d\n", ans);							// 최소 비용 출력
	return 0;
}