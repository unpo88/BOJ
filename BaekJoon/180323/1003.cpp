#include <cstdio>

int N;	// Number
int T;	// TestCase

int dp_zero[41];	// ��Ģ�� ���� �迭
int dp_one[41];		// ��Ģ�� ���� �迭

int main() {
	scanf("%d", &T);		// TestCase

	// �ʱⰪ
	dp_zero[0] = 1;
	dp_zero[1] = 0;

	dp_one[0] = 0;
	dp_one[1] = 1;

	for (int i = 2; i < 41; i++) {	// ������ 40���� �۰ų� ���� �ڿ��� �Ǵ� 0
		dp_zero[i] = dp_zero[i - 1] + dp_zero[i - 2];
		dp_one[i] = dp_one[i - 1] + dp_one[i - 2];
	}

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		printf("%d %d\n", dp_zero[N], dp_one[N]);
	}
	return 0;
}