#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	vector<int> s1;
	while (N--) {
		int num;
		scanf("%d", &num);
		s1.push_back(num);
	}

	sort(s1.begin(), s1.end());

	for (int i = 0; i < s1.size(); i++) {
		printf("%d\n", s1[i]);
	}
	return 0;
}