#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
int N, M;
int totalday;
queue<pair<int, int>> q;
queue<pair<int, int>> nq;
vector<vector<int>> room;
vector<vector<bool>> check;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (room[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		check[y][x] = true;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (nx > -1 && ny > -1 && nx < M&&ny < N) {
				if (room[ny][nx] == 0) {//다음칸으로 갈 수 있을 때만,
					room[ny][nx] = room[y][x]+1;
					q.push({ ny,nx });
				}
			}
		}
	}
	return;
}

void print() {
	int day=-INF;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!check[i][j]) {
				printf("-1\n");
				return;
			}
			else {
				if (day < room[i][j])
					day = room[i][j];
			}
		}
	}
	printf("%d\n", day-1);
	return;
}

int main() {
	int input;
	scanf("%d%d", &M, &N);
	room.resize(N);
	check.resize(N);
	for (int i = 0; i < N; i++) {
		check[i].resize(M);
		for (int j = 0; j < M; j++) {
			scanf("%d", &input);
			if (input == -1) {
				room[i].push_back(input);
				check[i][j] = true;
			}
			else {
				room[i].push_back(input);
			}
		}
	}
	bfs();
	print();

	return 0;
}