#include <deque>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
	deque<int> d;

	int N;
	scanf("%d", &N);

	while (N--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push_front") {
			int num;
			scanf("%d", &num);
			d.push_front(num);
		}
		else if (cmd == "push_back") {
			int num;
			scanf("%d", &num);
			d.push_back(num);
		}
		else if (cmd == "front") {
			if (d.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", d.front());
			}
		}
		else if (cmd == "back") {
			if (d.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", d.back());
			}
		}
		else if (cmd == "size") {
			printf("%d\n", d.size());
		}
		else if (cmd == "empty") {
			if (d.empty()) {
				printf("1\n");
			}         
			else {
				printf("0\n");
			}
		}
		else if (cmd == "pop_front") {
			if (d.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", d.front());
				d.pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (d.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", d.back());
				d.pop_back();
			}
		}
	}
	return 0;
}