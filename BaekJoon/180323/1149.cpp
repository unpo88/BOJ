#include <cstdio>
#define MIN(X,Y) ( (X) < (Y) ? (X) : (Y) )	// MIN 함수

int house[1001][3];
int charge[1001][3];

int main() {
	int N;				// Number 입력
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {		// 배열에 저장
		for (int j = 0; j <= 2; j++) {
			scanf("%d", &charge[i][j]);
		}
	}

	house[0][0] = house[0][1] = house[0][2] = charge[0][0] = charge[0][1] = charge[0][2] = 0;

	// 최소값 찾는 식(칠 순서와 가격에 따라 최소 금액이 달라짐)
	for (int i = 1; i <= N; i++) {
		house[i][0] = MIN(house[i - 1][1], house[i - 1][2]) + charge[i][0];
		house[i][1] = MIN(house[i - 1][0], house[i - 1][2]) + charge[i][1];
		house[i][2] = MIN(house[i - 1][0], house[i - 1][1]) + charge[i][2];
	}
	printf("%d", MIN(MIN(house[N][0], house[N][1]), house[N][2]));
	return 0;
}