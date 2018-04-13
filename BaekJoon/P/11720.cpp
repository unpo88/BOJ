#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);
	int N2;
	int sum = 0;
	while (N--) {
		scanf("%1d", &N2);
		sum += N2;
	}
	printf("%d", sum);
	return 0;
}