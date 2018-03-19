/*
	M¿¿ N¿¿¿ ¿¿¿ ¿¿ ¿¿¿¿ ¿¿¿¿¿ ¿¿¿¿¿.

	¿¿ ¿¿ ¿¿¿ M¿ N¿ ¿ ¿¿ ¿¿¿ ¿¿ ¿¿¿¿. (1¿M¿N¿1,000,000)
	
	¿ ¿¿ ¿¿¿, ¿¿¿¿ ¿¿¿¿ ¿¿¿ ¿¿¿¿.
*/

#include <stdio.h>

#define MAX 1000001

bool Arr_Prime[MAX];		// Prime Check Array

int main(){
	int M, N;
	scanf("%d %d", &M, &N);
	
	Arr_Prime[0] = Arr_Prime[1] = false;	// 0, 1 is not prime
	
	for(int i = 2; i <= N; i++){			// default true
		Arr_Prime[i] = true;
	}
	
	for(int i = 2; i * i <= N; i++){		// Arr_Prime ¿¿¿¿¿¿¿
		int mult = 2;
		if(Arr_Prime[i]){
			for(int j = i * mult; j <= N; j = i * mult){
				Arr_Prime[j] = false;
				mult++;
			}	
		}
	}
	
	for(int i= M; i <= N; i++){
		if(Arr_Prime[i]){					// Prime Check
			printf("%d\n", i);
		}
	}
	
	return 0;
}
