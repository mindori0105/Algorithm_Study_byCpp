#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <cstdio>
#include <math.h>
using namespace std;

int N,cnt;
vector<int> board;
bool visited[15];
void dfs(int depth) {
	if (depth == N) {
		cnt++;
		return;
	}
	bool changed = false;
	bool check = true;
	for (int i = depth; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[j]) {
				for (int k = 0; k < depth; k++) {
					if (abs(i - k) == abs(j - board[k])) {
						check = false;
						k = depth;
					}
				}
				if (check) {
					board.push_back(j);
					visited[j] = true;
					changed = true;
					dfs(depth + 1);
					visited[j] = false;
					changed = false;
					board.pop_back();
				}
				check = true;
			}
		}if (!changed) return;
	}
}

int main() {
	scanf("%d", &N);

	dfs(0);
	printf("%d\n", cnt);
	return 0;
}
