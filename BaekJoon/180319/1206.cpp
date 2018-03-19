#include <iostream>
#include <stdio.h>
using namespace std;

int tc_number;		// 테스트케이스의 길이
int map[1001];		// 가로 길이

int max(int a, int b);

int main() {
	// 총 10개의 테스트 케이스
	for (int i = 1; i <= 10; i++) {
		int ans = 0;	// 정답
		cin >> tc_number; // 테스트케이스 길이 입력
		for (int j = 0; j < tc_number; j++) {
			cin >> map[j];
		}
		for (int j = 2; j < tc_number - 2; j++) {	// 조망권 확보
			int a = map[j - 2];
			int b = map[j - 1];
			int c = map[j + 1];
			int d = map[j + 2];
			int center = map[j];
			int m = max(a, max(b, max(c, d)));
			if (center > m) {
				ans = ans + (center - m);
			}
		}
		cout << "#" << i << " " << ans << endl;
	}
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
	return a;
}