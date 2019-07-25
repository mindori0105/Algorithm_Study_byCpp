#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string.h>

using namespace std;
int H, M;
char time[10];
vector<pair<int,int>> answer;
vector<int> posH;//possible Hour.
vector<int> posM;//possible Minute.

int hour[3];
int minute[3];
int effcnt;
int tmpH, tmpM;

int effort(int a, int b) {//effort �� ���.
	int xa = 0, xb = 0, ya = 0, yb = 0;
	if (a == 1) {
		xa = 0; ya = 0;
	}
	else if (a == 2) {
		xa = 1; ya = 0;
	}
	else if (a == 3) {
		xa = 2; ya = 0;
	}
	else if (a == 4) {
		xa = 0; ya = 1;
	}
	else if (a == 5) {
		xa = 1; ya = 1;
	}
	else if (a == 6) {
		xa = 2; ya = 1;
	}
	else if (a == 7) {
		xa = 0; ya = 2;
	}
	else if (a == 8) {
		xa = 1; ya = 2;
	}
	else if (a == 9) {
		xa = 2; ya = 2;
	}
	else if (a == 0) {
		xa = 1; ya = 3;
	}

	if (b == 1) {
		xb = 0; yb = 0;
	}
	else if (b == 2) {
		xb = 1; yb = 0;
	}
	else if (b == 3) {
		xb = 2; yb = 0;
	}
	else if (b == 4) {
		xb = 0; yb = 1;
	}
	else if (b == 5) {
		xb = 1; yb = 1;
	}
	else if (b == 6) {
		xb = 2; yb = 1;
	}
	else if (b == 7) {
		xb = 0; yb = 2;
	}
	else if (b == 8) {
		xb = 1; yb = 2;
	}
	else if (b == 9) {
		xb = 2; yb = 2;
	}
	else if (b == 0) {
		xb = 1; yb = 3;
	}
	return (abs(xa - xb) + abs(ya - yb));
}

void findHour(int a) {
	while (tmpH < 100) {
		if ((tmpH % 24) == a)
			posH.push_back(tmpH);
		tmpH++;
	}
}

void findMin(int a) {
	while (tmpM < 100) {
		if ((tmpM % 60) == a)
			posM.push_back(tmpM);
		tmpM++;
	}
}

void sepHour(int H) {
	hour[0] = H / 10;//���� �ڸ��� �ʿ��ϹǷ�.
	hour[1] = H - (hour[0] * 10);
}

void sepMin(int M) {
	minute[0] = M / 10;
	minute[1] = M - (minute[0] * 10);
}

void solution() {
	for (int i = 0; i < (int)posH.size(); i++) {
		for (int j = 0; j < (int)posM.size(); j++) {
			sepHour(posH[i]);
			sepMin(posM[j]);
			int effnew = effort(hour[0], hour[1]) + effort(hour[1], minute[0]) + effort(minute[0], minute[1]);
			if (effcnt == effnew) {//������ effort�� ������,
				if (H > posH[i]) {//�ð����ؼ� ������,
					answer.pop_back();
					answer.push_back(make_pair(posH[i], posM[j]));
				}
				else if (H == posH[i]) {//�ð����ؼ� ������->�� ��
					if (M > posM[j]) {
						answer.pop_back();
						answer.push_back(make_pair(posH[i], posM[j]));
					}
				}
			}
			else if (effcnt > effnew) {//������ effort���� ������
				answer.pop_back();
				answer.push_back(make_pair(posH[i], posM[j]));
				effcnt = effnew;
			}
		}
	}
	return;
}

void printAns() {
	sepHour(answer.front().first);
	sepMin(answer.front().second);
	printf("%d%d:%d%d", hour[0], hour[1], minute[0], minute[1]);
}

int main() {
	
	fgets(time,sizeof(time),stdin);
	time[strlen(time) - 1] = 0;//���� ������ ����.
	char *tmp = strtok(time, ":");

	/* //�׳� ���������� �� �� ���� �ð�, �� �� ���� ������ ���� ��.
	scanf("%s", time);
	char tmp[3];
	tmp[0] = time[0];
	tmp[1] = time[1];
	H = atoi(tmp);
	tmp[0] = time[3];
	tmp[1] = time[4];
	M = atoi(tmp);
	*/

	H = atoi(tmp);//���� ������ ����뵵.
	sepHour(H);
	tmp = strtok(NULL, " ");
	M = atoi(tmp);
	sepMin(M);
	
	effcnt = effort(hour[0], hour[1]) + effort(hour[1], minute[0]) + effort(minute[0], minute[1]);
	answer.push_back(make_pair(H, M));
	findHour(H);
	findMin(M);
	solution();
	printAns();

	return 0;
}