#define	_CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
using namespace std;

int R, C, T;
vector<vector<int>> befRoom;
vector<vector<int>> nextRoom;
vector<vector<int>> emptyRoom;
int sec[50][50];
int result;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector <pair<int,int>> air;

int spreading(int y, int x, int dust) {
	int cnt=0;
	for (int k = 0; k < 4; k++) {
		if ((y + dy[k] > -1) && (x + dx[k] > -1) && (y + dy[k] < R) && (x + dx[k] < C) && (sec[y + dy[k]][x + dx[k]] > -1)) {
			//북남서동 가능, 공기청정기 아닌 곳으로만 확산.
			nextRoom[y + dy[k]][x + dx[k]] += dust;
			cnt++;
		}
	}
	return cnt;
}

void spread(int now) {
	int next;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if ((befRoom[i][j] > 0) && (sec[i][j] == now)) {
				next = befRoom[i][j] / 5;
				nextRoom[i][j] = nextRoom[i][j] + befRoom[i][j] - (next * spreading(i, j, next));
			}
			if(sec[i][j]>-1) sec[i][j] = now + 1;//청정기 아닐 때만,
		}
	}
	nextRoom[air[0].first][air[0].second] = -1;
	nextRoom[air[1].first][air[1].second] = -1;
}

void clean() {
	int i, j;
	//위쪽 청정기
	for (i = air[0].first-1; i > 0; i--) {//아래방향으로 청소
		nextRoom[i][0] = nextRoom[i - 1][0];
	}
	for (i = 0; i < C-1; i++) {
		nextRoom[0][i] = nextRoom[0][i + 1];
	}
	for (i = 0; i < air[0].first; i++) {
		nextRoom[i][C - 1] = nextRoom[i + 1][C - 1];
	}
	for (i = C - 1; i > 1; i--) {
		nextRoom[air[0].first][i] = nextRoom[air[0].first][i - 1];
	}
	nextRoom[air[0].first][1] = 0;
	//아랫쪽 청정기
	for (j = air[1].first + 1; j < R - 1; j++) {
		nextRoom[j][0] = nextRoom[j + 1][0];
	}
	for (j = 0; j < C - 1; j++) {
		nextRoom[R-1][j] = nextRoom[R-1][j+1];
	}
	for (j = R - 1; j > air[1].first; j--) {
		nextRoom[j][C - 1] = nextRoom[j - 1][C - 1];
	}
	for (j = C - 1; j > 1; j--) {
		nextRoom[air[1].first][j] = nextRoom[air[1].first][j - 1];
	}
	nextRoom[air[1].first][1] = 0;
}

void getTotal() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			result += befRoom[i][j];
		}
	}
	result += 2;//공기청정기 설치부분 제외.
	printf("%d\n", result);
}

void vecClear() {
	nextRoom.resize((int)emptyRoom.size());
	copy(emptyRoom.begin(), emptyRoom.end(), nextRoom.begin());
}

int main() {
	scanf("%d%d%d", &R, &C, &T);
	int tmp;
	vector<int> t;
	vector<int> emp(1);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &tmp);
			if (j == 0) {
				t.push_back(tmp);
				befRoom.push_back(t);
				emptyRoom.push_back(emp);
				t.pop_back();
			}
			else {
				befRoom[i].push_back(tmp);
				emptyRoom[i].push_back(0);
			}
			if (tmp == -1) {
				sec[i][j] = -1;
				air.push_back(make_pair(i, j));
			}
			else if (tmp > 0) sec[i][j] = 1;
		}
	}
	
	for (int k = 1; k <= T; k++) {
		vecClear();
		spread(k);
		clean();
		befRoom.swap(nextRoom);
	}
	getTotal();
	
	return 0;
}
