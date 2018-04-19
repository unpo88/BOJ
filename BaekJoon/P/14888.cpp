#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n;
int input[101];
int op[4];
long long MAX, MIN;

void DFS(long long num, int* op, int cnt) { //num�� ������ cnt�� DFS�� ����
	if (cnt == n - 1) { // �������� ������ ���ں��� 1�� ���� �׶� �ִ�,�ּҸ� ���ؾ���.
		if (num >= MAX)
			MAX = num;
		if (num <= MIN)
			MIN = num;
		return;
	}

	long long temp = input[cnt + 1];
	int* tempop;
	for (int i = 0; i<4; i++) {

		tempop = new int[4];
		for (int i = 0; i<4; i++)
			tempop[i] = op[i];

		if (tempop[i] != 0) {
			switch (i) {
			case 0:
				tempop[0]--;
				DFS(num + temp, tempop, cnt + 1);
				break;
			case 1:
				tempop[1]--;
				DFS(num - temp, tempop, cnt + 1);
				break;
			case 2:
				tempop[2]--;
				DFS(num*temp, tempop, cnt + 1);
				break;
			case 3:
				tempop[3]--;
				DFS(num / temp, tempop, cnt + 1);
				break;
			}

		}
	}
	delete[] tempop;

}

int main() {
	cin >> n;

	for (int i = 0; i<n; i++)
		cin >> input[i];
	for (int i = 0; i<4; i++)
		cin >> op[i];


	MAX = -1000000000;
	MIN = 1000000000;

	DFS(input[0], op, 0);
	cout << MAX << endl << MIN << endl;

	return 0;
}


