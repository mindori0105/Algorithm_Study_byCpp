#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Rotating_factors{
	int r;
	int c;
	int s;
	int ty, tx;//위쪽y,x좌표
	int by, bx;//아래쪽y,x좌표
	int cy, cx;//가운데y,x좌표
} Rotate;

#define MAX 5001
int N, M, K;
vector<int> order;
vector<vector<int>> map;
vector<vector<int>> map2;
vector<Rotate> roll;
Rotate r1;
int result=MAX;

void rotating(Rotate rot);
int calc();
//void print();

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < K; i++) order.push_back(i);//to get next_permutation

	for (int i = 0; i < N; i++) {//make the array
		for (int j = 0; j < M; j++) {
			int input;
			vector<int> tmp;
			scanf("%d", &input);
			if (j == 0) {
				tmp.push_back(input);
				map.push_back(tmp);
				
			}
			else {
				map[i].push_back(input);
			}
		}
	}
	map2.assign(map.begin(), map.end());
	for (int i = 0; i < K; i++) {
		int inp1, inp2, inp3;
		scanf("%d%d%d", &inp1, &inp2, &inp3);
		r1.r = inp1-1; 
		r1.c = inp2-1; 
		r1.s = inp3;
		r1.tx = r1.c - r1.s;
		r1.ty = r1.r - r1.s;
		r1.bx = r1.c + r1.s;
		r1.by = r1.r + r1.s;
		r1.cy = r1.ty + ((r1.by - r1.ty)/2);
		r1.cx = r1.tx + ((r1.bx - r1.tx)/2);
		roll.push_back(r1);		
	}

	for (int i = 0; i < (int)roll.size(); i++) {
		rotating(roll[order[i]]);
	}
	int res_t = calc();
	if (result > res_t) result = res_t;
	map2.assign(map.begin(), map.end());
	//printf("first permute\n");
	while (next_permutation(order.begin(), order.end())) {
		for (int i = 0; i < (int)roll.size(); i++) {
			rotating(roll[order[i]]);
		}
		res_t = calc();
		if (result > res_t) result = res_t;
		map2.assign(map.begin(), map.end());
	}
	//print();
	printf("%d\n", result);
	return 0;
}

void rotating(Rotate rot) {
	int sy, sx, ey, ex;//starting y,x // end y,x
	int sv;//starting poing value
	sy = rot.ty;
	sx = rot.tx;
	ey = rot.by;
	ex = rot.bx;

	while (sy != rot.cy && sx != rot.cx) {
		int nowy = sy;
		int nowx = sx;
		sv = map2[sy][sx];
		//printf("시작.\n");
		for (int i = sy; i < ey;i++) {//left to bottom.
			map2[nowy][nowx] = map2[nowy + 1][nowx];
			nowy++;
		}//printf("좌측아래.\n");print();
		for (int i = sx; i < ex;i++) {//bottom to right.
			map2[nowy][nowx] = map2[nowy][nowx + 1];
			nowx++;
		}//printf("아래우측.\n"); print();
		for (int i = sy; i < ey; i++) {//right to top.
			map2[nowy][nowx] = map2[nowy - 1][nowx];
			nowy--;
		}//printf("우측 위.\n"); print();
		for (int i = sx; i < ex-1; i++) {//top to left.
			map2[nowy][nowx] = map2[nowy][nowx - 1];
			nowx--;
		}
		map2[nowy][nowx] = sv;//starting point's value
		//printf("우측좌측.\n"); print();
		//다음 회전을 위해.
		sy += 1;
		sx += 1;
		ey -= 1;
		ex -= 1;
	}
}

int calc() {
	int res = MAX;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < M; j++) {
			sum += map2[i][j];
		}
		if (res > sum) res = sum;
	}
	return res;
}
/*
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}*/