#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

char map[20][20];
bool check[26];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int result;
int R, C;

void bTracking(int r, int c, int count) {
	for (int k = 0; k < 4; k++) {
		if ((r + dy[k] > -1) && (r + dy[k] < R) && (c + dx[k] > -1) && (c + dx[k] < C)) {
			if (check[map[r + dy[k]][c + dx[k]] - 65])	
				continue;
			
			check[map[r + dy[k]][c + dx[k]] - 65] = true;
			bTracking(r + dy[k], c + dx[k], count + 1);
			check[map[r + dy[k]][c + dx[k]] - 65] = false;		
		}
	}//if (result < count) result = count;
	result = (result < count) ? count : result;
}

int main() {
	scanf("%d %d", &R, &C);
	char tmp[21];
	for (int i = 0; i < R; i++) {
		scanf("%s", tmp);
		for (int j = 0; j < C; j++) {
			map[i][j] = tmp[j];
		}
		tmp[0] = '\0';
	}
	check[map[0][0] - 65] = true;
	bTracking(0, 0, 1);
	printf("%d\n", result);

	return 0;
}
