#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vec(9);
vector<bool> check(9);
vector<int> temp;
int N, M;

void solution(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", vec[i]);
		}printf("\n");
		return;
	}
	int prev = 0;
	for (int i = 0; i < (int)temp.size(); i++) {
		if (!check[i] && prev != temp[i]) {
			check[i] = true;
			vec[cnt] = temp[i];
			prev = temp[i];
			solution(cnt + 1);
			check[i] = false;
		}
	}
}
int main() {
	int tmp;
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		temp.push_back(tmp);
	}
	sort(temp.begin(), temp.end());
	solution(0);
	return 0;
}
