#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#define MAX 201
using namespace std;

int check[MAX];
bool td[MAX][MAX];
int N, M;
int total=0;

void solution(int idx) {
	if (idx == N) {
		printf("%d\n", total);
		return;
	}
	for (int i = idx+1; i < N; i++) {
		if (td[idx][i] != true) {
			for (int j = i + 1; j < N; j++) {
				if (!td[idx][j] && !td[i][j])
					total++;
			}
		}			
	}
	solution(idx+1);
}

int main(void) {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		td[a-1][b-1] = true;
		td[b-1][a-1] = true;
	}
	solution(0);

	return 0;
}
