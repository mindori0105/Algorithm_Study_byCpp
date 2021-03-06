#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector<int> vec(9);
vector<bool> check(9);
int cnt;

void solution(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", vec[i]);
		}printf("\n");
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			vec[cnt] = i + 1;
			for (int j = 0; j < i; j++) {
				check[j] = true;
			}
			solution(cnt + 1);
			for (int j = 0; j < i; j++) {
				check[j] = false;
			}
		}
	}
}
int main() {
	scanf("%d%d", &N, &M);
	solution(0);

	return 0;
}