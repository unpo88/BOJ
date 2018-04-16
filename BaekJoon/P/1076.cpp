#include <map>
#include <iostream>
#include <string>
using namespace std;

int main() {
	map<string, int> d = {
		{"black", 0}, {"brown", 1}, {"red", 2},
		{"orange", 3}, {"yellow", 4}, {"green", 5},
		{"blue", 6}, {"violet", 7}, {"grey", 8},
		{"white", 9}
	};

	string a, b, c;
	cin >> a >> b >> c;

	long long ans = (long long)(d[a] * 10 + d[b]);
	for (int k = 0; k < d[c]; k++) {
		ans *= 10;
	}
	
	cout << ans;
	return 0;
}