/*
	자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 최소값을 찾는 프로그램을 작성하시오.
	예를 들어 M=60, N=100인 경우 60이상 100이하의 자연수 중 소수는 61, 67, 71, 73, 79, 83, 89, 97 총 8개가 있으므로, 이들 소수의 합은 620이고, 최소값은 61이 된다.

	입력의 첫째 줄에 M이, 둘째 줄에 N이 주어진다.
	M과 N은 10,000이하의 자연수이며, M은 N보다 같거나 작다.
	
	M이상 N이하의 자연수 중 소수인 것을 모두 찾아 첫째 줄에 그 합을, 둘째 줄에 그 중 최소값을 출력한다. 
	단, M이상 N이하의 자연수 중 소수가 없을 경우는 첫째 줄에 -1을 출력한다.
*/

#include <stdio.h>

int IsPrimeNumber(int n);

int main(){
	int M, N;			// M이상 N이하 자연수
	int sum = 0;		// 합계
	int Min = 10000;	// 최소값 구하기
	bool check = false;	// 체크
	scanf("%d %d", &M, &N);
	
	// 소수 판별
	for(int i = M; i <= N; i++){
		if(IsPrimeNumber(i)){
			check = true;
			sum += i;
			if(Min > i)	Min = i;
		}
	}
	
	if(check == false){
		printf("-1");
	}else{
		printf("%d\n", sum);
		printf("%d", Min);
	}
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
