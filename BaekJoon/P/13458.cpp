#include <iostream>
#include <vector>
using namespace std;

int N;
int Ai;
int B, C;
int map[1000001];
int B_cnt = 0;
int C_cnt = 0;

bool flag = true;

int main() {
	cin >> N;
	

	for (int i = 0; i < N; i++) {
		cin >> Ai;
		map[i] = Ai;
	}

	cin >> B >> C;


	for (int i = 0; i < N; i++) {
		map[i] = map[i] - B;
		B_cnt += 1;
	}

	for (int i = 0; i < N; i++) {
			if(map[i] == 0){
				continue;
			}else if (map[i] < C) {
				C_cnt += 1;
			}
			else if(map[i] == C){
				C_cnt += map[i] / C;
			}
			else {
				C_cnt += map[i] / C + 1;
			}
	}

	cout << B_cnt + C_cnt << endl;

	return 0;
}