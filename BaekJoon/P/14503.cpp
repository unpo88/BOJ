#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 }; //�� �� �� �� ������ ���ư�

int N, M;

int map[51][51];
int result;

void DFS(int x, int y, int d) { //d�� ����
	if (!map[x][y]) {
		result++;
		map[x][y] = 2; //2�� �� ������ �湮�ߴٴ� �ǹ�
	}

	for (int i = d + 1; i<d + 5; i++)
	{
		int nextX = x + dx[i % 4];
		int nextY = y + dy[i % 4];
		if (nextX >= 0 && nextX<N && nextY >= 0 && nextY<M) {
			if (!map[nextX][nextY])
				DFS(nextX, nextY, i % 4);
		}
	}

	//�� ���� ��ο� 0�� ���� ��� -> �κ��� �����¿츦 ��� û���߰ų� ������ �����ִ°��
	int xx = x + dx[(d + 2) % 4];
	int yy = y + dy[(d + 2) % 4];
	if (map[xx][yy] == 2)
		DFS(xx, yy, d % 4);
	else if (map[xx][yy] == 1) {
		cout << result << endl;
		exit(0);
	}
}

int main() {
	cin >> N >> M;

	int r, c, d;
	cin >> r >> c >> d;

	if (d == 3) {
		d = 1;
	}

	else if (d == 1) {
		d = 3;
	}


	for (int i = 0; i<N; i++)
		for (int j = 0; j<M; j++)
			cin >> map[i][j];

	DFS(r, c, d);

	cout << result << endl;
	
	return 0;

}
