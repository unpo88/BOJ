#include <cstdio>
#include <cstring>
using namespace std;

char c[111];
int main() {
	int N;
	int s = 0;
	int n = 20;
	int num;
	scanf("%d", &N);
	while (N--) {
		scanf("%s", c);
		if (!strcmp(c,"add")) {
			scanf("%d", &num);
			num--;
			s = (s | (1 << num));
		}
		else if (!strcmp(c,"remove")) {
			scanf("%d", &num);
			num--;
			s = (s & ~(1 << num));
		}
		else if (!strcmp(c,"check")) {
			scanf("%d", &num);
			num--;
			int res = (s & (1 << num));
			if (res) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (!strcmp(c,"toggle")) {
			scanf("%d", &num);
			num--;
			s = (s ^ (1 << num));
		}
		else if (!strcmp(c,"all")) {
			s = (1 << n) - 1;
		}
		else if (!strcmp(c,"empty")) {
			s = 0;
		}
	}
	return 0;
}

