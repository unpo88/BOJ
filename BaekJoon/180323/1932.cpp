#include <cstdio>
#define MAX(X, Y) ( (X) > (Y) ? (X) : (Y))		// MAX
int Triangle[501][501];							// 삼각형 모양 배열

int main(){
	int N;			// 자연수
	scanf("%d" ,&N);

	for(int i = 0; i < N; i++){
		for(int j = 0; j <= i; j++){
			scanf("%d", &Triangle[i][j]);		// 삼각형 모양
		}
	}
	
	// Triangle[i][j] = 최대 합만을 저장
	
	for(int i = 1; i < N; i++){					// 첫번째 줄은 제외
		for(int j = 0; j <= i; j++){
			if(j == 0){
				Triangle[i][j] += Triangle[i-1][j];
			}else if(j == i){
				Triangle[i][j] += Triangle[i-1][j-1];
			}else{
				Triangle[i][j] = MAX(Triangle[i][j] + Triangle[i-1][j-1], Triangle[i][j] + Triangle[i-1][j]);
			}
		}
	}
	
	int max = 0;
	// 최대값 찾기
	for(int i = 0; i < N; i ++){
		if(max < Triangle[N-1][i]){
			max = Triangle[N-1][i];
		}
	}
	
	printf("%d", max);
	
	return 0;
}