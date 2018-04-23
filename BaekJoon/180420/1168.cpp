#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		v[i] = i + 1;
	}

	int pos = 0;

	cout << "<";
	while (v.size() != 1) {
		pos += M - 1;

		if (pos >= v.size()) {
			pos %= v.size();
		}

		cout << v[pos] << ", ";
		v.erase(v.begin() + pos);
	}

	cout << v[0];
	cout << ">";

	return 0;
}