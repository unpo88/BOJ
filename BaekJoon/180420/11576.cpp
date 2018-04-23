#include <iostream>
#include <cmath>
using namespace std;

int arr[100];
int main() {
	int A, B;
	cin >> A >> B;

	int N;
	cin >> N;

	int num;
	int sum = 0;
	while (N) {
		cin >> num;
		N = N-1;
		sum = sum + num * pow(A,N);
	}

	int cnt = 0;

	while(sum >= B){
		arr[cnt] = sum % B;
		cnt = cnt+1;
		sum = sum / B;
	}
	
	arr[cnt] = sum;
	
	for(int i = cnt; i >= 0; i--){
		cout << arr[i] << " ";
	}

	return 0;
}