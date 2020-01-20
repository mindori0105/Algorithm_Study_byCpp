#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

vector<pair<bool, int>> vec;
int N, K, index = 1;

void solution(int K) {
	for (int i = 2; i < N + 2; i++) {
		if (vec[i].second == K) {
			printf("%d\n", i);
			break;
		}
	}
}

void setPrime() {
	int now = 2;
	int next;
	while (1) {
		for (int i = 1; i < N / 2 + 1; i++) {
			next = now * i;
			if (next < N + 1 && vec[next].first) {
				vec[next].first = false;
				vec[next].second = index++;
			}
			else continue;
		}
		if (now == N) break;
		now++;
	}
}

int main() {
	scanf("%d %d", &N, &K);
	vec.resize(N + 2, make_pair(true,0));
	setPrime();
	solution(K);
	return 0;
}