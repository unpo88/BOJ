#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Person {
	string name;
	int age;
	int join;
};

bool cmp(const Person &u, const Person &v) {
	if (u.age < v.age) {
		return true;
	}
	else if (u.age == v.age) {
		if (u.join < v.join) {
			return true;
		}
	}
	return false;
}

int main() {
	int N;
	scanf("%d", &N);

	vector<Person> v1(N);

	for (int i = 0; i < N; i++) {
		cin >> v1[i].age >> v1[i].name;
		v1[i].join = ++i;
	}

	sort(v1.begin(), v1.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << v1[i].age << ' ' << v1[i].name << '\n';
	}

	return 0;
}