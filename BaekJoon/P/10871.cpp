#include <cstdio>

int main() {
	int N, X;
	int num;
	scanf("%d %d", &N, &X);
	while (N--) {
		scanf("%d ", &num);
		if (num < X) {
			printf("%d ", num);
		}
	}
	return 0;
}