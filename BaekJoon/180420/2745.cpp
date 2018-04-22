#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int N;
char arr[100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> arr;
	cin >> N;

	long long sum = 0;
	for (int i = strlen(arr) - 1; i >= 0; i--) {
		if (arr[i] >= '0' && arr[i] <= '9') {
			sum += pow(N, strlen(arr) - 1 - i)*(int)(arr[i] - '0');
		}
		else {
			sum += pow(N, strlen(arr) - 1 - i)*(int)(arr[i] - 'A' + 10);
		}
	}

	cout << sum;
	
	return 0;
}