#include <iostream>
using namespace std;
bool broken[10]; // ��ư�� ������ ������ true, �ƴϸ� false
int possible(int c) {
	if (c == 0) {
		if (broken[0]) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int len = 0;
	while (c > 0) {
		if (broken[c % 10]) {
			return 0;
		}
		len += 1;
		c /= 10;
	}
	return len;
}
int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		broken[x] = true;
	}
	int ans = n - 100; // n >= 100
	if (ans < 0) {
		ans = -ans; // n < 100
	}
	for (int i = 0; i <= 1000000; i++) { // ���� ��ư���� �̵��ϴ� ä��
		int c = i;
		int len = possible(c); // ���̸� ���.
		if (len > 0) {
			int press = c - n; // +�� -�� �� �� ������ �ϴ��� ���
			if (press < 0) {
				press = -press; // +�� ������ ���
			}
			if (ans > len + press) {
				ans = len + press;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}