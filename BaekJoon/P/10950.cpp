#include <cstdio>

int main() {
	int A, B;
	int N;
	scanf("%d", &N);
	while (N--) {
		scanf("%d %d", &A, &B);
		printf("%d\n", A + B);
	}
	return 0;
}