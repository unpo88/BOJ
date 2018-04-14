#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int k;
	while (scanf("%d", &k) == 1) {
		if (k == 0) {
			break;
		}

		vector<int> v(k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &v[i]);
		}

		vector<int> v2;
		for (int i = 0; i < k-6; i++) {
			v2.push_back(0);
		}
		for (int i = 0; i < 6; i++) {
			v2.push_back(1);
		}
		
		vector<vector<int>> ans;

		do {
			vector<int> current;
			for (int i = 0; i < k; i++) {
				if (v2[i] == 1) {
					current.push_back(v[i]);
				}
			}
			ans.push_back(current);
		} while (next_permutation(v2.begin(), v2.end()));
		sort(ans.begin(), ans.end());
		for (auto &v : ans) {
			for (int i = 0; i < v.size(); i++) {
				printf("%d ", v[i]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

