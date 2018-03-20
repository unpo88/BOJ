#include <cstdio>
using namespace std;

int main() {
	int T;								// Test Case
	scanf("%d", &T);

	for (int tc = 0; tc < T; tc++) {
		int sudoku[10][10] = { 0, };	// ¿¿¿ ¿¿
		bool check_row = true;			// ¿¿¿ ¿¿ ¿¿
		bool check_col = true;			// ¿¿¿ ¿¿ ¿¿
		bool check_square = true;		// 3*3¿¿ ¿¿ ¿¿
		
		// row check
		for (int i = 1; i < 10; i++) {
			int check_row_count[10] = { 0, };	// 1~9¿¿ ¿¿¿ ¿¿¿¿ ¿¿
			for (int j = 1; j < 10; j++) {
				scanf("%d", &sudoku[i][j]);		// ¿¿¿¿ ¿¿¿¿¿¿ ¿¿¿ ¿¿¿ ¿¿¿¿¿. ¿¿¿ ¿¿¿ ¿¿¿¿¿ ¿¿¿¿
				check_row_count[sudoku[i][j]]++;// 1~9¿¿ ¿¿¿ ¿¿
			}
			for(int j = 1; j < 10; j++){
				if(check_row_count[j] != 1){	// ¿¿¿¿ 0¿ ¿¿¿ 1~9¿¿ ¿¿ ¿
					check_row = false;			// ¿¿¿¿ ¿¿¿ ¿¿¿¿ ¿¿ ¿¿ ¿¿¿ false
				}
			}
		}
		
		// col check
		for(int i = 1; i < 10; i++){
			int check_col_count[10] = { 0, };	// 1~9¿¿ ¿¿¿ ¿¿¿¿ ¿¿
			for(int j = 1; j < 10; j++){
				check_col_count[sudoku[j][i]]++;// 1~9¿¿ ¿¿¿ ¿¿
			}
			for(int j = 1; j < 10; j ++){
				if(check_col_count[j] != 1){	// ¿¿¿¿ 0¿ ¿¿¿ 1~9¿¿ ¿¿¿
					check_col = false;			// ¿¿¿¿ ¿¿¿ ¿¿¿¿ ¿¿ ¿¿ ¿¿¿ false
				}
			}
		}
		
		// 3*3 ¿¿¿¿
		int start = 1;
		int end = 3;
		for(int k = 1; k <= 3; k++){
			int check_square_count[10] = {0, };
			for(int i = 1; i < 10; i++){
				if(i % 3 == 1){
					check_square_count[10] = {0, }; 
				}
				
				for(int j = start; j <= end; j++){
					check_square_count[sudoku[i][j]]++;
				}
				
				if(i % 3 == 0){
					for(int j = 1; j < 10; j++){
						if(check_square_count[j] != 1){
							check_square = false;
						}
					}
				}
				
				if(check_square == false){
					break;
				}
			}
			
			if(check_square == false){
				break;
			}
			
			start += 3;
			end += 3;

		}
		
		if(check_row == true && check_col == true && check_square == true){
			printf("1");
		}else{
			printf("0");
		}
	}
	return 0;
}
