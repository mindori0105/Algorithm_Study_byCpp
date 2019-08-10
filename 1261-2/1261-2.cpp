#define	_CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <memory.h>
#define INF 0x3f3f3f3f
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> dist;
typedef pair<int, pair<int, int>> T;
priority_queue<T,vector<T>,greater<T>> q;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

void diijkstra(int y,int x){
	dist[0][0] = 0;
	q.push({ dist[0][0],{ 0,0 } });

	while (!q.empty()) {
		int y = q.top().second.first;
		int x = q.top().second.second;
		int d = q.top().first;
		if (map[y][x] == 1) map[y][x] = 0;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (nx >= 0 && ny >= 0 && nx <= M && ny <= N) {
				if (dist[ny][nx] > d + map[ny][nx]) {//갈려고 하는 칸의 거리가 현재 칸 까지의 거리 + 다음 칸의 벽 수 보다 클 때
					dist[ny][nx] = d + map[ny][nx];
					q.push({ dist[ny][nx],{ ny,nx } });
				}
			}
		}

	}
	return;
}

int main() {
	int col, row;
	char input[101];
	scanf("%d%d", &col,&row);
	M = col - 1;
	N = row - 1;
	map.resize(row);
	dist.resize(row);
	//memset(dist., 0x3f, sizeof(int)*row*col);
	for (int i = 0; i < row; i++) {
		scanf("%s", input);
		for (int j = 0; j < col; j++) {
		//	scanf("%s", input);
			map[i].push_back(input[j]-48);
			dist[i].push_back(INF);
		}
		input[0] = '\0';
	}
	diijkstra(0, 0);
	printf("%d\n", dist[N][M]);

	return 0;

}
