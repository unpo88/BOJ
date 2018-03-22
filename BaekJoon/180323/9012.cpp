#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

char s[1000];

void testCase() {
	scanf("%s", s);

	stack<char> stk;

	int len = strlen(s);
	int flag = 1;

	for (int i = 0; i < len; i++) {
		char c = s[i];
		if (c == '(') {
			stk.push(c);
		}
		else {
			if (stk.empty() || stk.top() != '(') {
				flag = 0;
				break;
			}
			else {
				stk.pop();
			}
		}
	}

	if (!stk.empty()) {
		flag = 0;
	}

	if (flag == 1) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		testCase();
	}
	return 0;
}
