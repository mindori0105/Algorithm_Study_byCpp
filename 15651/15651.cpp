#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector<int> vec(8);
vector<bool> check(8);
int cnt;

void solution(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", vec[i]);
		}printf("\n");
		return;
	}
	for (int i = 0; i < N; i++) {
		vec[cnt] = i + 1;
		solution(cnt + 1);
	}
}
int main() {
	scanf("%d%d", &N, &M);
	solution(0);

	return 0;
}