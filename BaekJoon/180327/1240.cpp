#include <cstdio>

// 0~9 정해진 암호 코드
char code[10][8] = {"0001101",		// 0
                   "0011001",		// 1
                   "0010011",		// 2
                   "0111101",		// 3
                   "0100011",		// 4
                   "0110001",		// 5
                   "0101111",		// 6
                   "0111011",		// 7
                   "0110111",		// 8
                   "0001011"};		// 9
			

void testCase(){
	int N, M;	// 직사각형 배열의 세로, 가로 크기
	scanf("%d %d", &N, &M);

	int flag = true;
	int check_zero = 0;			// 1이 있는 놈 체크
	
	char input_code[101] = "";	// 입력하는 배열
	char check_code[101] = "";	// 본격적으로 검사할 배열

	for(int i = 0; i < N; i++){
		scanf("%s", input_code);
		for(int j = 0; j < M; j++){
			if(input_code[j] == '1'){	// 1이 있는 열을 체크
				check_zero = 1;
				break;
			}
		}
		if(flag && check_zero){			// 딱 한 번 만 넣고 나머지 무시
			flag = false;
			for(int j = 0; j < M; j++){	// check_code에 입력된 줄을 넣음
				check_code[j] = input_code[j];
			}
		}
	}

	int flag2 = false;
	int arr[8] = {NULL, };		// 8자리의 십진수 수를 저장하는 배열

	for(int i = 0; i < M - 56; i++){	// 딱 맞는 범위까지 구해주기 위해 점화식
		int flag3 = false;
		for(int j = 0; j < 8; j++){	// 7자리까지 비교하기 위해
			int num = -1;

			for(int k = 0; k < 10; k++){	// code[k][l] 비교를 위해
			int cnt = 0;					// 7개 비교시마다 다시 초기화
				for(int l = 0; l < 7; l++){
					if(check_code[i + (j * 7) + l] == code[k][l]){			// 코드 비교하자
						cnt++;	// 비교되면 +1
					}else{
						break;
					}
				}
				if(cnt == 7){	// 7이 되면 code와 일치!
					num = k;	// 0~9 숫자 중 일치된 배열의 숫자 배정
				}
			}
			if(num == -1){		// 일치하는게 없음	잘 집어넣다가 하나라도 일치하는게 없으면
				flag3 = true;
				break;
			}else{				// 일치한다면 숫자를 배열에 차곡차곡 집어넣기
				arr[j] = num;
			}
		}
		if(flag3){				// 일치하는게 없음
			continue;
		}else{
			flag2 = true;		// 있으면 멈춰
			break;
		}
	}

	int cnt = 0;
	if(flag2){					// 있으면 멈췄으니까
		int sum = 0;

		for(int i = 0; i < 8; i++){
			if(i % 2 == 0){			// 홀수 자리의 합
				sum += arr[i] * 3;
			}else{					// 짝수 자리의 합(마지막 검증 코드도 결국 8자리이기 때문에 짝수자리)
				sum += arr[i];
			}
		}

		if(sum % 10 == 0){			// 10의 배수
			for(int i = 0; i < 8; i++){
				cnt += arr[i];		// 정상적 암호 코드들의 숫자의 합
			}
		}
	}
	printf("%d\n", cnt);
}

// testCase 돌림 
int main(){
	int T;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++){
		printf("#%d ", tc);
		testCase();
	}
	return 0;
}