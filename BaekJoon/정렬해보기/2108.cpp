/*
	수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 단, N은 홀수라고 가정하자.
	
	1. 산술평균 : N개의 수들의 합을 N으로 나눈 값
	2. 중 앙 값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
	3. 최 빈 값 : N개의 수들 중 가장 많이 나타나는 값
	4. 범    위 : N개의 수들 중 최대값과 최소값의 차이
	
N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.

	첫째 줄에 수의 개수 N(1≤N≤500,000)이 주어진다. 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절대값은 4,000을 넘지 않는다.
	
	첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
	둘째 줄에는 중앙값을 출력한다.
	셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
	넷째 줄에는 범위를 출력한다.
*/

#include <stdio.h>
#define MAX 500000
#define MAX2 8001

int arr[MAX];		// 배열
int check[MAX2];	// 최빈값 배열
int N;				// 주어진 수

int main(){
	scanf("%d" ,&N);
	double S_Average;	// 산술평균
	int S_Sum = 0;		// 합계
	int S_Mid;			// 중앙값
	int S_Max = -4000;	// Range 구하기 위한 MAX
	int S_Min = 4000;	// Range 구하기 위한 MIN
	int Range;			// Range
	int count;
	
	// 배열에 입력
	for(int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		check[arr[i]+4000]++;	// 최빈값 배열
		S_Sum += arr[i];
		if(S_Max < arr[i])	S_Max = arr[i];
		if(S_Min > arr[i])	S_Min = arr[i];
	}
	
	S_Average = S_Sum/N;	// 산술평균
	Range = S_Max - S_Min;	// 범위
	printf("%.0f",S_Average);
	
	// 중앙 값 위해 정렬
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	S_Mid = arr[N/2];
	printf("%d", S_Mid);
	
	S_Max = 0;
	bool two = False;
	
	for(int i = 0; i < MAX2; i++){
		if(S_Max < arr[i]){
			S_Max = arr[i];
			count = i-4000;
			two = True;
		}else if(S_Max == arr[i] && two){
			if(count < (i-4000) && i < 4000){
				count = i-4000;
			}else if(count > (i-4000) && i>= 4000){
				
			}
			two = False;
		}
	}
	
	printf("%d", Range);
	return 0;
}
