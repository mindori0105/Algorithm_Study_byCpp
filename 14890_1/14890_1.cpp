#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#define MAX 100
using namespace std;


int N, L;
int top;//조건검사 줄이기 위해 가장 높은 높이 저장.
int cnt;//최종 출력값
vector<vector<double>> map;

void findRoad() {
	int count;
	for (int i = 0; i < N; i++) {//행우선
		count = 1;
		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] == map[i][j + 1]) count++;
			else if (map[i][j] + 1 == map[i][j + 1] && count >= L) count = 1;
			else if (map[i][j] - 1 == map[i][j + 1] && count >= 0) count = - L + 1;
			else break;
			if (j == N - 2 && count >= 0) cnt++;
		}
	}
	for (int j = 0; j < N; j++) {//열우선
		count = 1;
		for (int i = 0; i < N - 1; i++) {
			if (map[i][j] == map[i + 1][j]) count++;
			else if (map[i][j] + 1 == map[i + 1][j] && count >= L) count = 1;
			else if (map[i][j] - 1 == map[i + 1][j] && count >= 0) count = - L + 1;
			else break;
			if (i == N - 2 && count >= 0) cnt++;
		}
	}
}
int main() {
	scanf("%d%d", &N, &L);
	int tmp;
	vector<double> temp;
	for (int i = 0; i < N; i++) {//x,y가 바뀌지 않도록 입력하기위해서.
		for (int j = 0; j < N; j++) {
			scanf("%d", &tmp);
			if (tmp > top)
				top = tmp;
			if (j == 0) {
				temp.push_back(tmp);
				map.push_back(temp);
				temp.pop_back();
			}
			else {
				map[i].push_back(tmp);
			}
		}
	}
	findRoad();
	printf("%d\n", cnt);
	return 0;

}
