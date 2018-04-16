#include <stdio.h>
int main() {
	int N;
	int i = 0;
	scanf("%d", &N);
	while(N--){
		printf("%d\n", ++i);
	}
	return 0;
}