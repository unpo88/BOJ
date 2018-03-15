#include <stdio.h>
int main() {
	int num;
	int three, five;
	scanf("%d", &num);
	three = num / 3;
	five = num / 5;
	int sum = 0;

	for (int i = 0; i <= three; i++) {
		for (int j = 0; j <= five; j++) {
			if (3 * i + 5 * j == num) {
				sum = sum + i + j;
				printf("%d", sum);
				return 0;
			}
		}
	}
	printf("-1");

	return 0;
}