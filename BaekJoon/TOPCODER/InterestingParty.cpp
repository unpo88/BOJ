#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	
	map<string, int> dic;

	vector<string> first;
	vector<string> second;

	int N;
	cin >> N;

	string subject;
	for (int i = 0; i < N; i++) {
		cin >> subject;
		first.push_back(subject);
	}
	
	for (int i = 0; i < N; i++) {
		cin >> subject; 
		second.push_back(subject);
	}

	int answer;

	/*
	for (int i = 0; i < first.size(); i++) {
		int first_answer = 0;
		int second_answer = 0;
		for (int j = 0; j < first.size(); j++) {
			if (first[i] == first[j]) {
				first_answer++;
			}
			if (first[i] == second[j]) {
				first_answer++;
			}
			if (second[i] == first[j]) {
				second_answer++;
			}
			if (second[i] == second[j]) {
				second_answer++;
			}
			answer = max(first_answer, second_answer);
		}
	}
	*/

	for (int i = 0; i < first.size(); i++) {
		dic[first[i]] = 0;
		dic[second[i]] = 0;
	}

	for (int i = 0; i < first.size(); i++) {
		dic[first[i]]++;
		dic[second[i]]++;
	}

	map<string, int>::iterator it;

	for (it = dic.begin(); it != dic.end(); it++) {
		answer = max(answer, it->second);
	}
	cout << answer;

	return 0;
}