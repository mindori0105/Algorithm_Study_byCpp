#include <iostream>
#include <math.h>
using namespace std;

int N, r, c;
int cnt;
int flag = 0;
int base;
int xmid, ymid;

void z(int len, int xmid, int ymid, int x, int y) {
	
	//wid 기준 몇 번째 분면인가?
	//xmid,ymid 변수를 써보자.
	if (cnt > 1 && len > 2) {
		//if (x < (xwid - len / 2) && y < (ywid - len / 2)) {//1사분면
		if (x < (xmid) && y < (ymid)) {//1사분면
			cnt--;
			len = len / 2;
			//xwid = xwid / 2;
			//ywid = ywid / 2;
			xmid = xmid - len/2;
			ymid = ymid - len/2;
			z(len, xmid, ymid, x, y);
		}
		else if (x >= (xmid) && y < (ymid)) {//2사분면
			cnt--;
			base = base + pow(2, cnt)*pow(2, cnt);
			len = len / 2;
			//ywid = ywid / 2;
			xmid = xmid + len/2;
			ymid = ymid - len/2;
			z(len, xmid, ymid, x, y);				
		}
		else if (x < (xmid) && y >= (ymid)) {//3사분면
			cnt--;
			base = base + pow(2, cnt)*pow(2, cnt+1);
			len = len / 2;
			//xwid = xwid / 2;
			xmid = xmid - len/2;
			ymid = ymid + len/2;
			z(len, xmid, ymid, x, y);			
		}
		else if (x >= (xmid) && y >= (ymid)) {//4사분면
			cnt--;
			base = base + pow(2, cnt + 1)*pow(2, cnt) + pow(2, cnt)*pow(2, cnt);
			len = len / 2;
			xmid = xmid + len/2;
			ymid = ymid + len/2;
			z(len, xmid, ymid, x, y);			
		}
	}
	else
		flag = 1;
	
	if (flag == 1) {//완료되었는지 검사
		if (x % 2 == 0 && y % 2 == 0) {//왼쪽 위
			cout << base;
			flag = 0;
		}
		else if (x % 2 == 0 && y % 2 == 1) {//왼쪽 밑
			cout << base + 2;
			flag = 0;
		}
		else if (x % 2 == 1 && y % 2 == 0) {//오른쪽 위
			cout << base + 1;
			flag = 0;
		}
		else if (x % 2 == 1 && y % 2 == 1) {//오른쪽 밑
			cout << base + 3;
			flag = 0;
		}
	}
}
int main() {
	cin >> N >> r >> c;
	cnt = N;
	base = 0;
	int len = 1 << N;
	//int xwid = 1 << N;
	//int ywid = xwid;
	//int len = xwid;
	xmid = len/2;
	ymid = len/2;
	if (r < len&&c < len)
		//z(len, xwid, ywid, c, r);
		z(len, xmid, ymid, c, r);
	return 0;
}