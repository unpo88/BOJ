#include <cstdio>
#define MIN(X, Y)( (X) < (Y) ? (X) : (Y) )	// 최소값 함수

int DP[1000001];		// 1보다 크고 10^6보다 작거나 같은 자연수 N의 연산 최소값을 저장할 배열

int main(){
	int N;				// 자연수 N
	scanf("%d" ,&N);
	
	DP[1] = 0;			// 1을 출력하는 것이니 0
	
	for(int i = 2; i <= N; i++){	// 2부터 N까지 돌면서
		DP[i] = DP[i - 1] + 1;		// 
		if(i % 2 == 0){				// 2의 배수
			// 연산 횟수 최소값 비교 후 적은 값 채택
			DP[i] = MIN(DP[i], DP[i/2] + 1);
		}
		if(i % 3 == 0){				// 3의 배수
			// 연산 횟수 최소값 비교 후 적은 값 채택
			DP[i] = MIN(DP[i], DP[i/3] + 1);
		}
	}
	
	// 최소값
	printf("%d\n",DP[N]);
	return 0;
}