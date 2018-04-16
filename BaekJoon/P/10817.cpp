#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	printf("%d", A + B + C - max(max(A, B), C) - min(min(A, B), C));
	return 0;
}