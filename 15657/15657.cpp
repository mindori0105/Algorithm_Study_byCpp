#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> check(9);
vector<int> vec(9);
vector<int> tmp;

int N, M;
int a;

void solution(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", vec[i]);
		}printf("\n");
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			for (int j = 0; j < i; j++) {
				check[j] = true;
			}
			vec[cnt] = tmp[i];
			solution(cnt + 1);
			for (int j = 0; j < i; j++) {
				check[j] = false;
			}
		}
	}

}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		tmp.push_back(a);
	}sort(tmp.begin(), tmp.end());

	solution(0);

	return 0;
}
