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
		
		if (!changed[i][j]) {//�̹��� ���� ��ź�̸�, �ش��ϴ� �κи� ������ ���������� �ȵȴ�.
			for (int k = 0; k < 4; k++) {//�����¿�
				if ((i + x[k] >= 0) && (i + x[k] < R) && (j + y[k] >= 0) && (j + y[k] < C)) {//���� üũ
					if ((bomboard[i + x[k]][j + y[k]].first == 'O') && (bomboard[i + x[k]][j + y[k]].second == 0)) {//������ ��������� ��ź�ΰ�?
						explode(i + x[k], j + y[k]);
					}
					else {//�ƴϸ� ����
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
	if (i % 2 == 1) {//���� ������.
		if (i == 1) {//ó�� 1��.->�ƹ��͵� ����.(�� ī��Ʈ�� ������)->�׷��� ���ʿ� �ʱ� ��ġ�Ǵ� ��ź���� �ð��� 1��..
			return;
		}
		else {//���� ����.
			for (int j = 0; j < C; j++) {
				for (int i = 0; i < R; i++) {
					if (!check[i][j]) {//�湮 ��������,
						if (bomboard[i][j].first == 'O') {//��ź�̸�,
							if (bomboard[i][j].second != 0) {//��ź ������ ��.
								bomboard[i][j].second--;
								check[i][j] = true;
								changed[i][j] = true;
							}
							else {//����.
								explode(i, j);
							}
						}
					}
				}
			}
		}	
	}
	else {//��ġ ������.
		for (int j = 0; j < C; j++) {
			for (int i = 0; i < R; i++) {
				if (!check[i][j]) {//�湮 ��������,
					if (bomboard[i][j].first == '.') {//'.'�̸�
						bomboard[i][j].first = 'O';
						bomboard[i][j].second = 2;
						check[i][j] = true;
					}
					else {//'O'�̸�
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
	for (int i = 0; i < R; i++) {//x,y������ ä�� �����. ����.
		for (int j = 0; j < C; j++) {
			scanf(" %c", &t);
			bomboard[i].push_back(make_pair(t, 1));
		}
	}

	for (int i = 1; i <= N; i++) {//ó�� 1�� ������ �ִ°� ó�����ֱ�.
		nextSec(i);
	}
	print();//�ٽ� ������� ����� ���.	

	return 0;
}