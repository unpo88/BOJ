#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int x;
	int y;
	int num;
	int dir;
};

int t, n, m, k;
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };
vector<int> map[100][100];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m >> k;

		vector<Node> v(k);
		for (int i = 0; i < k; i++) {
			cin >> v[i].x >> v[i].y >> v[i].num >> v[i].dir;
			v[i].dir;
			map[v[i].x][v[i].y].push_back(i);
		}

		while (m--) {

			// ���� ����
			for (int i = 0; i < k; i++) {
				if (v[i].num == 0) continue;
				map[v[i].x][v[i].y].clear();
			}

			// ���� �̵�
			for (int i = 0; i < k; i++) {
				if (v[i].num == 0) continue;
				v[i].x += dx[v[i].dir];
				v[i].y += dy[v[i].dir];
				map[v[i].x][v[i].y].push_back(i);
			}

			for (int i = 0; i < k; i++) {
				if (v[i].num == 0) continue;

				//�����ڸ��� ���� ���
				if (v[i].x == 0 || v[i].y == 0 || v[i].x == n - 1 || v[i].y == n - 1) {
					v[i].num = v[i].num / 2; //�̻��� 1/2����
											 //������ȯ
					if (v[i].dir == 1) v[i].dir = 2;
					else if (v[i].dir == 2) v[i].dir = 1;
					else if (v[i].dir == 3)v[i].dir = 4;
					else v[i].dir = 3;
				}
				//���� ������ ��ģ ���
				else if (map[v[i].x][v[i].y].size() > 1) {
					int x = v[i].x;
					int y = v[i].y;
					int max_num = 0;
					int max_cnt = 0;
					int max_dir = 0;
					int sum = 0;
					for (int i = 0; i < map[x][y].size(); i++) {
						sum += v[map[x][y][i]].num; // �̻��� �� ��
													// �ִ� �̻����� ���� ���� ã��
						if (max_num < v[map[x][y][i]].num) {
							max_num = v[map[x][y][i]].num;
							max_dir = v[map[x][y][i]].dir;
							max_cnt = map[x][y][i];
						}
						v[map[x][y][i]].num = 0;
					}
					v[max_cnt].num = sum;
					v[max_cnt].dir = max_dir;
				}
			}
		}

		//���� �̻��� ���
		int res = 0;
		for (int i = 0; i < k; i++) {
			res += v[i].num;
		}

		//���ʱ�ȭ
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j].clear();
			}
		}

		cout << "#" << tc << " " << res << "\n";
	}
}

