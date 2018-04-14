#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
	string name;
	int ko, eng, math;
};

bool cmp(const Person &u, const Person &v) {
	if (u.ko > v.ko) {
		return true;
	}
	else if (u.ko == v.ko) {
		if (u.eng < v.eng) {
			return true;
		}
		else if (u.eng == v.eng) {
			if (u.math > v.math) {
				return true;
			}
			else if (u.math == v.math) {
				return u.name < v.name;
			}
		}
	}
	return false;
}

int main() {
	int N;
	scanf("%d", &N);

	vector<Person> v1(N);

	for (int i = 0; i < v1.size(); i++){
		cin >> v1[i].name >> v1[i].ko >> v1[i].eng >> v1[i].math;
	}

	sort(v1.begin(), v1.end(), cmp);
	
	for (int i = 0; i < N; i++) {
		cout << v1[i].name << '\n';
	}

	return 0;
}