#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#define MAX 1000000001
#define MIN -1000000001	

using namespace std;

int N;
int P, M, T, D;
int A_arr[11];
vector<char> oper;
vector<char> opertmp;
vector<int> chk(4);
vector<int> res;
int cnt = 0;
int result;
int minres = 1000000001;
int maxres = -1000000001;
/*
void makeOperator(int P, int M, int T, int D) {
	for (int i = 0; i < P; i++)
		oper.push_back('+');
	for (int i = 0; i < M; i++)
		oper.push_back('-');
	for (int i = 0; i < T; i++)
		oper.push_back('*');
	for (int i = 0; i < D; i++)
		oper.push_back('/');
 }*/

void saveResult() {
	result = A_arr[0];
	for (int i = 0; i < (int)opertmp.size(); ++i) {
		if (opertmp[i] == '+')
			result += A_arr[i + 1];
		else if (opertmp[i] == '-')
			result -= A_arr[i + 1];
		else if (opertmp[i] == '*')
			result *= A_arr[i + 1];
		else if (opertmp[i] == '/')
			result /= A_arr[i + 1];
	}
	res.push_back(result);
}
char getOper(int i) {
	if (i == 0) {
		return '+';
	}
	else if (i == 1) {
		return '-';
	}
	else if (i == 2) {
		return '*';
	}
	else if (i == 3) {
		return '/';
	}
}

void swapOperator(int cnt) {
	/*
	char tmp;
	for (int i = 0; i < N - 1; i++) {
		//for (int j = 0; j < N - 1; j++) {
		//		tmp = oper[cnt];
		//		oper[cnt] = oper[i];
		//		oper[i] = tmp;

				saveResult();
				swapOperator(cnt++);
	}*/
	if (cnt == 0) {
		saveResult();
	}
	for (int i = 0; i < 4; i++) {
		if (chk[i]>0) {
			chk[i]--;
			opertmp.push_back(getOper(i));
			swapOperator(cnt - 1);
			chk[i]++;
			opertmp.pop_back();
		}
	}
}

void findMaxMin() {
	maxres = *max_element(res.begin(), res.end());
	minres = *min_element(res.begin(), res.end());
	if (maxres < MAX && minres > MIN)
		printf("%d\n%d", maxres, minres);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A_arr[i]);

	scanf("%d %d %d %d", &chk[0], &chk[1], &chk[2], &chk[3]);
	//scanf("%d %d %d %d", &P, &M, &T, &D);
	
	//chk.push_back(P); chk.push_back(M);chk.push_back(T); chk.push_back(D);
	cnt = accumulate(chk.begin(), chk.end(), 0);
	if (cnt == N - 1) {
		//makeOperator(P, M, T, D);
		swapOperator(cnt);
		findMaxMin();
	}
	
	return 0;
}