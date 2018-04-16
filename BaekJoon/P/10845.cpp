#include <queue>
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	queue<int> q1;
	while (N--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int num;
			scanf("%d", &num);
			q1.push(num);
		}
		else if (cmd == "front") {
			if (q1.empty()) {
				printf("-1\n");
			}
			else {
				cout << q1.front() << '\n';
			}
		}
		else if (cmd == "back") {
			if (q1.empty()) {
				printf("-1\n");
			}
			else {
				cout << q1.back() << '\n';
			}
		}
		else if (cmd == "size") {
			printf("%d\n", q1.size());
		}
		else if (cmd == "empty") {
			if (q1.empty()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (cmd == "pop") {
			if (q1.empty()) {
				printf("-1\n");
			}
			else {
				cout << q1.front() << '\n';
				q1.pop();
			}
		}
	}
	return 0;
}