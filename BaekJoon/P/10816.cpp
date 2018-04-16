#include <cstdio>
#include <set>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	multiset<int> s1;
	for(int i = 0; i < N; i++){
		int num;
		scanf("%d", &num);
		s1.insert(num);
	}

	int M;
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);
		printf("%d ", s1.count(num));
	}
	return 0;
}