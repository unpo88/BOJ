/*
	주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

	첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

	주어진 수들 중 소수의 개수를 출력한다.
*/

#include <stdio.h>
#define MAX 100

int arr[MAX];

int IsPrimeNumber(int n);

int main(){
	int N;
	int count = 0;
	scanf("%d", &N);
	
	for(int i = 0 ; i < N; i++){
		scanf("%d", &arr[i]);
	}
	
	for(int i = 0; i < N; i++){
		if(IsPrimeNumber(arr[i])){
			count++;
		}
	}
	
	printf("%d", count);
	return 0;
}

// 소수 구하기
int IsPrimeNumber(int n){
	if(n <= 1){
		return 0;
	}
	for(int i = 2; i < n; i++){
		if(n % i == 0){
			return 0;
			break;
		}
	}
	return 1;
}
