#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <vector>
#include <cstdio>
#include <algorithm>
#define MAX 200
using namespace std;

int R, C, N;
pair<char, int> p;
vector<vector<pair<char, int>>> bomboard(MAX);
bool check[MAX][MAX];
bool changed[MAX][MAX];
int x[4] = {0, 0, 1, -1};
int y[4] = { 1,-1,0,0 };

void explode(int i, int j) {
		bomboard[i][j].first = '.';
		bomboard[i][j].second = 0;
		check[i][j] = true;
		
		if (!changed[i][j]) {//이번에 생긴 폭탄이면, 해당하는 부분만 터지고 번져나가면 안된다.
			for (int k = 0; k < 4; k++) {//상하좌우
				if ((i + x[k] >= 0) && (i + x[k] < R) && (j + y[k] >= 0) && (j + y[k] < C)) {//범위 체크
					if ((bomboard[i + x[k]][j + y[k]].first == 'O') && (bomboard[i + x[k]][j + y[k]].second == 0)) {//원래도 터졌어야할 폭탄인가?
						explode(i + x[k], j + y[k]);
					}
					else {//아니면 ㄱㄱ
						bomboard[i + x[k]][j + y[k]].first = '.';
						bomboard[i + x[k]][j + y[k]].second = 0;
						check[i + x[k]][j + y[k]] = true;
					}
				}
			}
		}
	return;
}

void nextSec(int i) {
	memset(check, false, sizeof(check));
	memset(changed, false, sizeof(changed));
	if (i % 2 == 1) {//폭파 시퀀스.
		if (i == 1) {//처음 1초.->아무것도 안함.(초 카운트만 내려감)->그래서 애초에 초기 설치되는 폭탄에는 시간초 1로..
			return;
		}
		else {//ㄹㅇ 폭파.
			for (int j = 0; j < C; j++) {
				for (int i = 0; i < R; i++) {
					if (!check[i][j]) {//방문 안했으면,
						if (bomboard[i][j].first == 'O') {//폭탄이면,
							if (bomboard[i][j].second != 0) {//폭탄 터지기 전.
								bomboard[i][j].second--;
								check[i][j] = true;
								changed[i][j] = true;
							}
							else {//터짐.
								explode(i, j);
							}
						}
					}
				}
			}
		}	
	}
	else {//설치 시퀀스.
		for (int j = 0; j < C; j++) {
			for (int i = 0; i < R; i++) {
				if (!check[i][j]) {//방문 안했으면,
					if (bomboard[i][j].first == '.') {//'.'이면
						bomboard[i][j].first = 'O';
						bomboard[i][j].second = 2;
						check[i][j] = true;
					}
					else {//'O'이면
						bomboard[i][j].second--;
						check[i][j] = true;
					}
				}
			}
		}
	}
}

void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%c", bomboard[i][j].first);
		}printf("\n");
	}
}

int main() {
	scanf("%d%d%d", &R, &C, &N);
	char t;
	for (int i = 0; i < R; i++) {//x,y뒤집힌 채로 저장됨. 주의.
		for (int j = 0; j < C; j++) {
			scanf(" %c", &t);
			bomboard[i].push_back(make_pair(t, 1));
		}
	}

	for (int i = 1; i <= N; i++) {//처음 1초 가만히 있는거 처리해주기.
		nextSec(i);
	}
	print();//다시 원래대로 뒤집어서 출력.	

	return 0;
}