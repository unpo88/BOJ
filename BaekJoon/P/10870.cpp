#include <functional>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	
	function<int(int)> f = [&](int n) {
		if (n <= 1) return n;
		else return f(n - 1) + f(n - 2);
	};

	cout << f(n) << '\n';
	
	return 0;
}