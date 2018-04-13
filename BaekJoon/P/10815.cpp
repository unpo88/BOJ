#include <cstdio>
#include <set>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	set<int> s1;
	while (N--) {
		int num;
		scanf("%d", &num);
		s1.insert(num);
	}

	int M;
	scanf("%d", &M);
	
	while (M--) {
		int num;
		scanf("%d", &num);
		printf("%d ", s1.count(num));
	}

	return 0;
}