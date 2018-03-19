#include <cstdio>


int main() {
	// 주어진 TestCase와 실제 Input Test Case가 달라서 임의로 일단 이렇게 설정
	for (int j = 0; j < 10; j++) {
		int tc;				// testCase 입력
		scanf("%d", &tc);

		int data[101] = { 0, };	// 숫자 분포 배열 

		int max_count = 0;		// 최빈값 check 변수

		for (int i = 0; i < 1000; i++) {	// 학생 수 1000명 반복
			int tmp;
			scanf("%d", &tmp);
			data[tmp]++;						// 점수를 입력받자마자 점수분포 배열에 증가
		}

		// 최빈 값 구하기
		for (int i = 0; i < 100; i++) {		// 최빈수 구함
			if (max_count <= data[i])
			max_count = data[i];
		}

		for (int i = 100; i >= 0; i--) {	// 최빈값, 조건은 동일할 시 가장 큰 값이므로 큰수부터 배열 탐색 
			if (max_count == data[i]) {
				printf("#%d %d\n", tc, i);
				break;
			}
		}
	}
	return 0;
}