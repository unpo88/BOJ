#include <iostream>
#include <stdio.h>
using namespace std;

int tc_number;		// �׽�Ʈ���̽��� ����
int map[1001];		// ���� ����

int max(int a, int b);

int main() {
	// �� 10���� �׽�Ʈ ���̽�
	for (int i = 1; i <= 10; i++) {
		int ans = 0;	// ����
		cin >> tc_number; // �׽�Ʈ���̽� ���� �Է�
		for (int j = 0; j < tc_number; j++) {
			cin >> map[j];
		}
		for (int j = 2; j < tc_number - 2; j++) {	// ������ Ȯ��
			int a = map[j - 2];
			int b = map[j - 1];
			int c = map[j + 1];
			int d = map[j + 2];
			int center = map[j];
			int m = max(a, max(b, max(c, d)));
			if (center > m) {
				ans = ans + (center - m);
			}
		}
		cout << "#" << i << " " << ans << endl;
	}
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
	return a;
}