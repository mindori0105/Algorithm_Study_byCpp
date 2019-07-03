#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> vec(9);
vector<int> temp;
vector<bool> check(9);

void solution(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", vec[i]);
		}printf("\n");
		return;
	}
	int prev = 0;
	for (int i = 0; i < (int)temp.size(); i++) {
		if (!check[i]&&prev!=temp[i]) {
			for(int j=0;j<i;j++)
				check[j] = true;
			check[i] = true;
			vec[cnt] = temp[i];
			prev = temp[i];
			solution(cnt + 1);
			for (int j = 0; j < i; j++)
				check[j] = false;
			check[i] = false;
		}
	}
}

int main(void) {
	int a;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		temp.push_back(a);
	}
	sort(temp.begin(), temp.end());
	solution(0);
	
	return 0;
}

