#include <cstdio>

int num[10][10];								// 배열
int dr[4] = { 0, +1, 0, -1 };	 // row 움직임
int dc[4] = { +1, 0, -1, 0 };	 // column 움직임

void testCase(){
	int n;							// Input N
	scanf("%d", &n);

  int cr = 0;
  int cc = 0;
  int cdir = 0;

  for(int r = 0; r < n; r++){	//	초기화
		for(int c = 0; c < n; c++){
			num[r][c] = 0;
		}
  }
	
  for(int i = 0; i < n * n; i++){
		int nr = cr + dr[cdir];	// 움직임
		int nc = cc + dc[cdir];
		num[cr][cc] = (i+1);
		if( nr < 0 || nr >= n || nc < 0 || nc >= n || num[nr][nc] != 0 ){     
			cdir = (cdir + 1) % 4;
		}

		cr = cr + dr[cdir];
		cc = cc + dc[cdir];
	}

	for(int r = 0; r < n; r++){
		for(int c = 0; c < n; c++){
			if( c > 0 )
				printf(" ");
			printf("%d", num[r][c]);
		}
		printf("\n");
	}
}

int main(){
	int tc;
	scanf("%d",&tc);		// testCase
	for(int t = 1; t <= tc; t++){
		printf("#%d\n",t);
		testCase();
	}
	return 0;
}