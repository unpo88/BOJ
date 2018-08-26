#include <iostream>
#include <cstring>

using namespace std;

int testCase;
int N;
int answer;

int vertex[100001];
bool isVisited[100001];
bool isFinished[100001];

void DFS(int v) {
	isVisited[v] = true;
	int next_v = vertex[v];
	if (!isVisited[next_v]) {
		DFS(next_v);
	}
	else {
		if (!isFinished[next_v]) {
			for (int i = next_v; i != v; i = vertex[i]) {
				answer++;
			}
			answer++;
		}
	}
	isFinished[v] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> testCase;

	while (testCase--) {
		cin >> N;
		answer = 0;

		memset(vertex, 0, sizeof(vertex));
		memset(isVisited, 0, sizeof(isVisited));
		memset(isFinished, 0, sizeof(isFinished));

		for (int i = 1; i <= N; i++) {
			cin >> vertex[i];
		}

		for (int i = 1; i <= N; i++) {
			if (!isVisited[i]) {
				DFS(i);
			}
		}
		cout << N - answer << "\n";
	}
	return 0;
}