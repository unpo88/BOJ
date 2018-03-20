#include <cstdio>
using namespace std;

int main() {
	int T;								// Test Case
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		int sudoku[10][10] = { 0, };	// 스도쿠 배열
		bool check_row = true;			// 가로줄 체크 변수
		bool check_col = true;			// 세로줄 체크 변수
		bool check_square = true;		// 3*3배열 체크 변수
		
		// row check
		for (int i = 1; i < 10; i++) {
			int check_row_count[10] = { 0, };	// 1~9까지 있는지 확인해줄 변수
			for (int j = 1; j < 10; j++) {
				scanf("%d", &sudoku[i][j]);		// 스도쿠를 입력받으면서 동시에 가로를 체크해준다. 왜냐면 입력을 가로순으로 받으니깐
				check_row_count[sudoku[i][j]]++;// 1~9까지 있으면 증가
			}
			for(int j = 1; j < 10; j++){
				if(check_row_count[j] != 1){	// 하나라도 0이 있으면 1~9까지 없는 것
					check_row = false;			// 하나라도 조건을 만족하지 않는 것이 있다면 false
				}
			}
		}
		
		// col check
		for(int i = 1; i < 10; i++){
			int check_col_count[10] = { 0, };	// 1~9까지 있는지 확인해줄 변수
			for(int j = 1; j < 10; j++){
				check_col_count[sudoku[j][i]]++;// 1~9까지 있으면 증가
			}
			for(int j = 1; j < 10; j ++){
				if(check_col_count[j] != 1){	// 하나라도 0이 있으면 1~9까지 없는것
					check_col = false;			// 하나라도 조건을 만족하지 않는 것이 있다면 false
				}
			}
		}
		
		// 3*3 확인하기
		int start = 1;	// 3*3을 크게 범위를 나누어줄 기특한 변수
		int end = 3;	// 3*3을 크게 범위를 나누어줄 기특한 변수
		// 가로줄을 총 크게 3번으로 잘라서 나눌거임! 어차피 for가 많아도 반복범위의 수는 굉장히 조그만함 9*9 스도쿠라면
		for(int k = 1; k <= 3; k++){
			int check_square_count[10] = {0, };		// 3*3 배열을 한번씩 체크할 때 마다 다시 초기화
			for(int i = 1; i < 10; i++){
				if(i % 3 == 1){						// 총 9개의 3*3 스도쿠를 체크해줘야하기 때문에 1~9까지 있는지 계속 초기화
					check_square_count[10] = {0, }; 
				}
				
				for(int j = start; j <= end; j++){	// 3*3 스도쿠 범위 나누기
					check_square_count[sudoku[i][j]]++;
				}
				
				if(i % 3 == 0){						// 3*3 스도쿠 한번 읽었으면 그 스도쿠에 1~9 있는지 체크
					for(int j = 1; j < 10; j++){
						if(check_square_count[j] == 0){
							check_square = false;	// 없다고? 그러면 넌 false!
						}
					}
				}
				
				if(check_square == false){			// false가 있다면 더 이상 반복문을 돌 이유가 없지 가자!
					break;
				}
			}
			
			if(check_square == false){				// 너 역시 마찮가지지 가즈아!!!!
				break;
			}
			
			// 크게 3번 잘라서 나눈 것중 하나를 돌았다고? 그럼 이제 범위를 바꿔주자
			start += 3;
			end += 3;
			
		}
	
		// 셋 모두 true여야지 스도쿠의 검증이 끝난것이여
		if(check_row == true && check_col == true && check_square == true){
			printf("#%d 1\n", tc);
		}else{
			printf("#%d 0\n", tc);
		}
	}
	return 0;
}