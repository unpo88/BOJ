#include <cstdio>
using namespace std;


int main() {
	int T;		// �׽�Ʈ���̽��� ����
	scanf("%d", &T);	// �׽�Ʈ���̽� �Է�

	for (int tc = 0; tc < T; tc++) {
		int sudoku[10][10] = { 0, };		// ���� ����(�������� ���� �迭�� ũ��� 10)

		// ������ �Է�
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				scanf("%d", &sudoku[i][j]);
			}
		}


	}
	return 0;
}