#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

vector<int> vec(9);
vector<bool> check(9);
vector<int> temp;
set<vector<int>> list;
set<vector<int>>::iterator iter;

int N, M;

void solution(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			list.insert(vec);
		}
		return;
	}
	for (int i = 0; i < (int)temp.size(); i++) {
		if (!check[i]) {
			check[i] = true;
			vec[cnt] = temp[i];
			solution(cnt + 1);
			check[i] = false;
		}
	}

}
void printvec() {
	for (iter = list.begin(); iter != list.end(); iter++) {
		for (int i = 0; (int)i < M; i++) {
			printf("%d ", iter->at(i));
		}printf("\n");
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
	printvec();
	return 0;
}