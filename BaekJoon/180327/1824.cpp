#include <cstdio>

char scanner[51][102];
char check[10][8] = { "0001101",
					"0011001",
					"0010011",
					"0111101",
					"0110001",
					"0101111",
					"0111011",
					"0110111",
					"0001011" };
char compare[9][9];

void testCase() {
	int N, M;
	scanf("%d %d", &N, &M);
	
	bool flag = false;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M+1; j++) {
			scanf("%c", &scanner[i][j]);
		}
	}
	
	for (int i = 1; i <= N; i++) {

	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		printf("#%d\n", tc);
		testCase();
	}
	return 0;
}