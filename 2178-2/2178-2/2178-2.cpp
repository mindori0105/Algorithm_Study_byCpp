#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>
#include <vector>

#define MAX 100
using namespace std;

int N, M;
queue<pair<int, int>> q;
queue<int> q2;
vector<vector<int>> miro;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int res = 100001;

void bfs(int row, int col) {
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		int cnt = q2.front();
		q.pop();
		q2.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
				if (miro[nr][nc] == 1) {
					if ((nr == N - 1) && (nc == M - 1)) {
						if(cnt < res)
							res = cnt + 1;
						return;
					}
					q.push(make_pair(nr, nc));
					q2.push( cnt + 1);
					miro[nr][nc] = cnt + 1;
				}
			}
		}
	}
}


int main() {
	char input[MAX];
	vector<int> tmp;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", &input);
		for (int j = 0; j < M; j++) {
			tmp.push_back((int)input[j] - 48);
		}
		miro.push_back(tmp);
		tmp.clear();
		input[0] = '\0';
	}
	q.push(make_pair(0, 0));
	q2.push(1);
	bfs(q.front().first, q.front().second);

	printf("%d\n", res);


	return 0;
}
