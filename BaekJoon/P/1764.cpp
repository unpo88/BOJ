#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	set<string> v1;
	while (N--) {
		string s1;
		cin >> s1;
		v1.insert(s1);
	}

	set<string> v2;
	int count = 0;
	while (M--) {
		string s2;
		cin >> s2;
		if (v1.count(s2)) {
			v2.insert(s2);
			count++;
		}
	}
	
	cout << count << '\n';

	for (auto x : v2) {
		cout << x << '\n';
	}

	return 0;
}