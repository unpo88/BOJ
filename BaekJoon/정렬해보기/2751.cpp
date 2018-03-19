/*
	N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

	첫째 줄에 수의 개수 N(1<=N<=1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 절대값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

	첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
*/

#include <stdio.h>

#define MAX 1000000

void QuickSort(int arr[], int low, int high);	// QuickSort	https://www.geeksforgeeks.org/quick-sort/
void Swap(int *a, int *b);						// Swap
int Partition(int arr[], int low, int high);	// Partition

int arr[MAX];			// 정렬할 배열
int N;					// 주어진 N개의 수

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	QuickSort(arr, 0, N-1);

	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}

void QuickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = Partition(arr, low, high);

		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}

int Partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			Swap(&arr[i], &arr[j]);
		}
	}
	Swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void Swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}