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
			scanf("%d", &w[i][j]);					// ��� ��� ����
		}
	}

	vector<int> d(n);
	for (int i = 0; i<n; i++) {
		d[i] = i;
	}

	int ans = 2147483647;							// �� �� �ִ� ���� ū ���

	do {
		bool ok = true;
		int sum = 0;
		for (int i = 0; i<n - 1; i++) {
			if (w[d[i]][d[i + 1]] == 0) {			// �� �� ���� ��ζ��
				ok = false;							// false
				break;
			}
			else {
				sum += w[d[i]][d[i + 1]];			// ��� �� ���غ�
			}
		}
		if (ok && w[d[n - 1]][d[0]] != 0) {			// �� �� �ְ�, ������ ��ҿ��� �ٷ� ��
			sum += w[d[n - 1]][d[0]];
			if (ans > sum) ans = sum;				 // �ּ� ��� ����
		}
	} while (next_permutation(d.begin()+1, d.end()));	// ���� ��� ��� üũ

	printf("%d\n", ans);							// �ּ� ��� ���
	return 0;
}