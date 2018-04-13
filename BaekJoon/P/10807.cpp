#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	vector<int> v1(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v1[i]);
	}
	
	int find;
	scanf("%d", &find);
	
	printf("%d", count(v1.begin(), v1.end(), find));

	return 0;
}