/*
	N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	ù° �ٿ� ���� ���� N(1<=N<=1,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���ڰ� �־�����. �� ���� ���밪�� 1,000,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.

	ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.
*/

#include <stdio.h>

#define MAX 1000000

void QuickSort(int arr[], int low, int high);	// QuickSort	https://www.geeksforgeeks.org/quick-sort/
void Swap(int *a, int *b);						// Swap
int Partition(int arr[], int low, int high);	// Partition

int arr[MAX];			// ������ �迭
int N;					// �־��� N���� ��

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