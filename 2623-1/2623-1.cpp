#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> vec;
vector<int> degree;
queue<int>q;
vector<int> result;
int N, M, T;

void sorting() {
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		for (int i = 0; i < (int)vec[q.front()].size(); i++) {
			degree[vec[q.front()][i]]--;
			if (degree[vec[q.front()][i]] == 0) {
				q.push(vec[q.front()][i]);
			}					
		}
		result.push_back(q.front());
		q.pop();
	}
}

void print() {
	if ((int)result.size() == N) {
		for (int i = 0; i < N; i++) {
			printf("%d\n", result[i]);
		}
	}
	else {
		printf("0\n");
	}
}

void resize() {
	vector<int> tmp;
	for (int i = 0; i <= N; i++) {
		vec.push_back(tmp);
		degree.push_back(0);
	}
}

int main() {
	int t, before, next;

	scanf("%d%d", &N, &M);
	resize();
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &t, &before);
		for (int j = 1; j < t; j++) {
			scanf("%d", &next);
			vec[before].push_back(next);
			degree[next]++;
			before = next;
		}
	}
	sorting();
	print();

	return 0;
}
