#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
typedef struct _dice {
	int top;
	int bottom;
	int left;
	int right;
	int front;
	int back;
}Dice;

int N, M, X, Y, K;
int map[20][20];
int dx[4] = { 1,-1,0,0 };//µ¿¼­ºÏ³²
int dy[4] = { 0,0,-1,1 };
Dice d1;
Dice tmp;
void scan(int y,int x) {
	if (map[y][x] == 0) {
		map[y][x] = d1.bottom;
	}
	else {
		d1.bottom = map[y][x];
		map[y][x] = 0;
	}
}

void roll(int dir) {
	if (dir <= 2) {
		if (dir == 1) {//µ¿
			tmp.left = d1.bottom;
			tmp.bottom = d1.right;
			tmp.right = d1.top;
			tmp.top = d1.left;
			tmp.front = d1.front;
			tmp.back = d1.back;
			d1 = tmp;
		}
		else {//¼­
			tmp.left = d1.top;
			tmp.bottom = d1.left;
			tmp.right = d1.bottom;
			tmp.top = d1.right;
			tmp.front = d1.front;
			tmp.back = d1.back;
			d1 = tmp;
		}
	}
	else {
		if (dir == 3) {//ºÏ
			tmp.left = d1.left;
			tmp.bottom = d1.back;
			tmp.right = d1.right;
			tmp.top = d1.front;
			tmp.front = d1.bottom;
			tmp.back = d1.top;
			d1 = tmp;
		}
		else {//³²
			tmp.left = d1.left;
			tmp.bottom = d1.front;
			tmp.right = d1.right;
			tmp.top = d1.back;
			tmp.front = d1.top;
			tmp.back = d1.bottom;
			d1 = tmp;
		}
	}
}

void move(int dir) {
	if ((X + dy[dir-1] > -1) && (Y + dx[dir-1] > -1) && (X + dy[dir-1] < N) && (Y + dx[dir-1] < M)) {
		X += dy[dir-1];
		Y += dx[dir-1];
		roll(dir);
		scan(X,Y);
		printf("%d\n", d1.top);
	}
}

int main() {
	scanf("%d%d%d%d%d", &N, &M, &X, &Y, &K);//X~N,Y~M;
	int t;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &t);
			map[i][j] = t;
		}
	}
	scan(X,Y);
	for (int i = 0; i < K; i++) {
		scanf("%d", &t);
		move(t);
	}
}