#include <iostream>
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
		for (int j = 2; j < tc_number - 2; j++) {	// �� ���ʰ� ������ �� ĭ���� �ǹ��� �������� �ʴ´�.
													// üũ�ؾ��ϴ� �ǹ�	(������ üũ)(�������� �Ÿ� 2 �̻��� ������ Ȯ��)
			int m_left2 = map[j - 2];
			int m_left1 = map[j - 1];
			int m_right1 = map[j + 1];
			int m_right2 = map[j + 2];
			int center = map[j];	// �߽� �ǹ� center
			int m = max(m_left2, max(m_left1, max(m_right1, m_right2)));	// ���� ���� �ǹ�
			if (center > m) {
				ans = ans + (center - m);	// ������ ����
			}
		}
		cout << "#" << i << " " << ans << endl;
	}
}

// MAX �Լ�
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
	return a;
}