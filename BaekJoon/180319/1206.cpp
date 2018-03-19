#include <iostream>
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
		for (int j = 2; j < tc_number - 2; j++) {	// 맨 왼쪽과 오른쪽 두 칸에는 건물이 지어지지 않는다.
													// 체크해야하는 건물	(조망권 체크)(양쪽으로 거리 2 이상의 공간이 확보)
			int m_left2 = map[j - 2];
			int m_left1 = map[j - 1];
			int m_right1 = map[j + 1];
			int m_right2 = map[j + 2];
			int center = map[j];	// 중심 건물 center
			int m = max(m_left2, max(m_left1, max(m_right1, m_right2)));	// 가장 높은 건물
			if (center > m) {
				ans = ans + (center - m);	// 조망권 빌딩
			}
		}
		cout << "#" << i << " " << ans << endl;
	}
}

// MAX 함수
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
	return a;
}