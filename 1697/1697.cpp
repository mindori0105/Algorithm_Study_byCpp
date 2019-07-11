#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
queue<int> result;
int visit[100001];

void finding() {
	result.push(N);
	visit[N]=1;
	while (!result.empty()) {
		int now = result.front();
		result.pop();
		if (now == K) {
			printf("%d", visit[now] - 1);
			return;
		}

		if (now - 1 >= 0 && visit[now - 1] == 0) {
			result.push(now - 1);
			visit[now - 1] = visit[now] + 1;
		}
		if (now + 1 < 100001 && visit[now + 1] == 0) {
			result.push(now + 1);
			visit[now + 1] = visit[now] + 1;
		}
		if (now * 2 < 100001 && visit[now * 2] == 0) {
			result.push(now * 2);
			visit[now * 2] = visit[now] + 1;
		}
	}
}


int main() {
	scanf("%d%d", &N, &K);
	finding();

	return 0;
}