#include<cstdio>

int stack[100001];			// stack
int N;						// 정수
int top;					// top
char instruction[6];		// 명령어
int number;					// Push 일 때 입력받장

int main() {
	scanf("%d", &N);	// 명령어 개수 입력
	
	for (int i = 1; i <= N; i++) {
		scanf("%s", instruction);
		if (instruction[0] == 'p' && instruction[1] == 'u') {		// Push
			scanf("%d", &number);
			stack[top++] = number;
		}
		else if (instruction[0] == 'p') {							// Pop
			printf("%d\n", top ? stack[--top] : -1);
		}
		else if (instruction[0] == 's') {							// Size
			printf("%d\n", top);
		}
		else if (instruction[0] == 'e') {							// Empty
			printf("%d\n", !top);
		}
		else {														// Top
			printf("%d\n", top ? stack[top - 1] : -1);
		}
	}
	return 0;
}