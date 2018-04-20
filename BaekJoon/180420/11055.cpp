#include <iostream>
using namespace std;

int arr[1001];
int sum[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	int max = 0;
	for (int i = 1; i <= N; i++) {
		sum[i] = arr[i];
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j] && sum[i] < sum[j] + arr[i]) {
				sum[i] = sum[j] + arr[i];
			}
		}
		if (max < sum[i]) {
			max = sum[i];
		}
	}

	cout << max;

	return 0;
}