#include <cstdio>
using namespace std;


int main() {
	int T;		// 테스트케이스의 길이
	scanf("%d", &T);	// 테스트케이스 입력

	for (int tc = 0; tc < T; tc++) {
		int sudoku[10][10] = { 0, };		// 가로 길이(가독성을 위해 배열의 크기는 10)

		// 스도쿠 입력
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				scanf("%d", &sudoku[i][j]);
			}
		}


	}
	return 0;
}