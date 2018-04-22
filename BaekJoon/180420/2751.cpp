#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
int N;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr + 1, arr + N + 1);

	for (int i = 1; i <= N; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}