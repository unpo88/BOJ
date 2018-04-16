#include <cstdio>
#include <set>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	set<int> s;

	while (N--) {
		int num;
		scanf("%d", &num);
		s.insert(num);
	}

	for (auto x : s) {
		printf("%d ", x);
	}
	return 0;
}