#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	set<int> s1;
	
	while (N--) {
		int num;
		scanf("%d", &num);
		if (num == 0) {
			if (s1.size() == 0) {
				printf("0\n");
			}
			else {
				auto it = s1.begin();
				cout << *it << '\n';
				s1.erase(it);
			}
		}
		else {
			s1.insert(num);
		}
	}
	return 0;
}