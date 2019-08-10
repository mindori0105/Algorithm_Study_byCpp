#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int totalday;
queue<pair<int, int>> q;
queue<pair<int, int>> nq;
vector<vector<pair<int,int>>> room;
vector<vector<bool>> check;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (room[i][j].first == 1 && room[i][j].second == totalday) {
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
				if (room[ny][nx].first == 0) {//다음칸으로 갈 수 있을 때만,
						room[ny][nx].first = 1;
						room[ny][nx].second = room[y][x].second + 1;
						totalday = room[y][x].second + 1;
						nq.push({ ny,nx });
				}
			}
		}
		if (q.empty()) q.swap(nq);		
	}
	return;
}
bool count() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!check[i][j]) return false;
		}
	}
	return true;
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
			if (input == 1) {
				room[i].push_back({ input , 0 });
				q.push({ i,j });
			}
			else if(input == 0) room[i].push_back({ input , 0 });
			else {
				room[i].push_back({ input , 0 });
				check[i][j] = true;
			}
		}
	}
	bfs();
	if (!count()) printf("-1\n");
	else printf("%d\n", totalday);
	return 0;
}