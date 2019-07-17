#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

typedef struct _bottles {
	int a;
	int b;
	int c;
}bot;
set<int> result;
bool visit[201][201][201];
queue<bot> q;
int A, B, C;//A는 1, B는 2, C는 3 으로 큐에 삽입.

void solution() {
	q.push({ 0,0,C });
	while (!q.empty()) {
		int nowa = q.front().a;
		int nowb = q.front().b;
		int nowc = q.front().c;
		q.pop();
		if (visit[nowa][nowb][nowc])
			continue;
		visit[nowa][nowb][nowc] = true;

		if (nowa == 0)
			result.insert(nowc);

		if (nowb+nowa>B) {//A->B
			q.push({ nowa - (B - nowb), B, nowc });
		}
		else {
			q.push({ 0, nowa + nowb, nowc });
		}

		if (nowc + nowa > C) {//A->c
			q.push({ nowa - (C - nowc), nowb, C });
		}
		else {
			q.push({ 0, nowb, nowa + nowc });
		}

		if (nowb + nowa > A) {//B->A
			q.push({ A, nowb-(A-nowa), nowc });
		}
		else {
			q.push({ nowa+nowb, 0, nowc });
		}

		if (nowb + nowc > C) {//B->C
			q.push({nowa, nowb-(C-nowc), C });
		}
		else {
			q.push({ nowa, 0, nowb + nowc });
		}

		if (nowb + nowc > B) {//C->B
			q.push({ nowa, B, nowc-(B-nowb) });
		}
		else {
			q.push({ nowa, nowb + nowc, 0});
		}
		
		if (nowa + nowc > A) {//C->A
			q.push({ A, nowb ,nowc-(A-nowa) });
		}
		else {
			q.push({ nowa + nowc, nowb, 0 });
		}
		
	}
}

void print() {
	set<int>::iterator iter;
	for (iter = result.begin(); iter != result.end(); iter++) {
		printf("%d ", *iter);
	}
}
int main() {
	scanf("%d%d%d", &A, &B, &C);
	solution();
	print();

	return 0;
}