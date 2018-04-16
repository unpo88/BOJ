#include <cstdio>
#include <list>
using namespace std;

int main() {
	list<pair<int, int>> a;

	int N;
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		a.push_back({ x,i });
	}

	auto it = a.begin();

	for (int i = 0; i < N - 1; i++) {
		printf("%d ", it->second);
		int step = it->first;
		if (step > 0) {
			auto temp = it;
			++temp;
			if (temp == a.end()) {
				temp = a.begin();
			}
			a.erase(it);
			it = temp;
			for (int i = 1; i < step; i++) {
				++it;
				if (it == a.end()) {
					it = a.begin();
				}
			}
		}
		else {
			step = -step;
			auto temp = it;
			if (temp == a.begin()) {
				temp = a.end();
			}
			--temp;
			a.erase(it);
			it = temp;
			for (int i = 1; i < step; i++) {
				if (it == a.begin()) {
					it = a.end();
				}
				--it;
			}
		}
	}

	printf("%d ", a.front().second);

	return 0;
}