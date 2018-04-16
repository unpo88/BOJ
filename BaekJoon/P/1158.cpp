#include <cstdio>
#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	deque<int> d1;
	for (int i = 1; i <= N; i++) {
		d1.push_back(i);
	}

	printf("<");
	for(int k = 1; k <= N; k++){
		for (int j = 0; j < M - 1; j++) {
			d1.push_back(d1.front());
			d1.pop_front();
		}
		cout << d1.front();
		d1.pop_front();
		if (k != N) {
			cout << ", ";
		}
	}
	printf(">");
	
	return 0;
}