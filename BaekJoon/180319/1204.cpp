#include <cstdio>


int main() {
	// �־��� TestCase�� ���� Input Test Case�� �޶� ���Ƿ� �ϴ� �̷��� ����
	for (int j = 0; j < 10; j++) {
		int tc;				// testCase �Է�
		scanf("%d", &tc);

		int data[101] = { 0, };	// ���� ���� �迭 

		int max_count = 0;		// �ֺ� check ����

		for (int i = 0; i < 1000; i++) {	// �л� �� 1000�� �ݺ�
			int tmp;
			scanf("%d", &tmp);
			data[tmp]++;						// ������ �Է¹��ڸ��� �������� �迭�� ����
		}

		// �ֺ� �� ���ϱ�
		for (int i = 0; i < 100; i++) {		// �ֺ�� ����
			if (max_count <= data[i])
			max_count = data[i];
		}

		for (int i = 100; i >= 0; i--) {	// �ֺ�, ������ ������ �� ���� ū ���̹Ƿ� ū������ �迭 Ž�� 
			if (max_count == data[i]) {
				printf("#%d %d\n", tc, i);
				break;
			}
		}
	}
	return 0;
}