#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	
	vector<string> v1(N);

	for(int i = 0; i < N; i++){
		cin >> v1[i];
	}

	sort(v1.begin(), v1.end(), [](string u, string v) {
		if (u.size() == v.size()) {
			return u < v;
		}
		else {
			return u.size() < v.size();
		}
	});

	v1.erase(unique(v1.begin(), v1.end()), v1.end());
	for (auto x : v1) {
		cout << x << '\n';
	}
	return 0;
}