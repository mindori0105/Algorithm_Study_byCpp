#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

int N, e, w, s, n;//N과 동서남북.
int x[4] = { 1,-1,0,0 };//동서남북.
int y[4] = { 0,0,-1,1 };
double prob[4];
double sum;
bool map[29][29];//로봇이 움직이는 맵(시작은 항상 중간에서.
vector<pair<int, int>> location;

void moving(int a, int b, double nProb, int depth) {
	if (depth == N) {
		sum += nProb;
		return;
	}
	map[a][b] = true;
	for (int i = 0; i < 4; i++) {
		if (!map[a + x[i]][b + y[i]]) {
			moving((a + x[i]), (b + y[i]), (prob[i] * nProb), depth + 1);
			map[a + x[i]][b + y[i]] = false;
		}
	}
	return;
}

int main() {
	scanf("%d%d%d%d%d", &N, &e, &w, &s, &n);
	prob[0] = e / 100.; prob[1] = w / 100.; prob[2] = s / 100.; prob[3] = n / 100.;
	moving(15, 15, 1., 0);

	printf("%.9lf", sum);
	return 0;
}
