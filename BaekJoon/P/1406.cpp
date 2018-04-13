#include <cstdio>
#include <string>
#include <iostream>
#include <list>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	list<char> editor(s.begin(), s.end());

	auto cursor = editor.end();

	int n;
	scanf("%d", &n);
	while (n--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'P') {
			char plus;
			cin >> plus;
			editor.insert(cursor, plus);
		}
		else if (cmd == 'L') {
			if (cursor != editor.begin()) {
				cursor--;
			}
		}
		else if (cmd == 'D') {
			if (cursor != editor.end()) {
				cursor++;
			}
		}
		else if (cmd == 'B') {
			if (cursor != editor.begin()) {
				auto temp = cursor;
				--cursor;
				editor.erase(cursor);
				cursor = temp;
			}
		}
	}

	for (char c : editor) {
		printf("%c", c);
	}
	return 0;
}