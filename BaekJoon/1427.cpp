/*
	배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.

	첫째 줄에 정렬하고자하는 수 N이 주어진다. N은 1,000,000,000보다 작거나 같은 자연수이다.

	첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.
*/

#include <stdio.h>
#define MAX 10

int main() {
	int arr[MAX];
	int N;
	int check = 0; // 기본으로 0이 들어가있는 배열에서 몇개의 0이 입력되었는지 Check 해주는 변수

	scanf("%d", &N);

	int divide = 1000000000;
	
	// 자릿수 배열에 저장
	for (int i = 0; i < 10; i++) {
		arr[i] = N / divide;
		N -= arr[i] * divide;
		divide /= 10;
	}

	// 숫자에서 0이 들어간 수 체크
	for (int i = 0; i < 10; i++) {
		if(arr[i] != 0){
			break;
		}
		check++;
	}
	
	// 정렬
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (arr[i] < arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	// 정렬된 배열 출력
	for (int i = 0; i < 10-check; i++) {
		printf("%d", arr[i]);
	}

	return 0;
}
