#include <iostream>
#include <math.h>
using namespace std;

int N, r, c;
int cnt;
int flag = 0;
int base;
int xmid, ymid;

void z(int len, int xmid, int ymid, int x, int y) {
	
	//wid ���� �� ��° �и��ΰ�?
	//xmid,ymid ������ �Ẹ��.
	if (cnt > 1 && len > 2) {
		//if (x < (xwid - len / 2) && y < (ywid - len / 2)) {//1��и�
		if (x < (xmid) && y < (ymid)) {//1��и�
			cnt--;
			len = len / 2;
			//xwid = xwid / 2;
			//ywid = ywid / 2;
			xmid = xmid - len/2;
			ymid = ymid - len/2;
			z(len, xmid, ymid, x, y);
		}
		else if (x >= (xmid) && y < (ymid)) {//2��и�
			cnt--;
			base = base + pow(2, cnt)*pow(2, cnt);
			len = len / 2;
			//ywid = ywid / 2;
			xmid = xmid + len/2;
			ymid = ymid - len/2;
			z(len, xmid, ymid, x, y);				
		}
		else if (x < (xmid) && y >= (ymid)) {//3��и�
			cnt--;
			base = base + pow(2, cnt)*pow(2, cnt+1);
			len = len / 2;
			//xwid = xwid / 2;
			xmid = xmid - len/2;
			ymid = ymid + len/2;
			z(len, xmid, ymid, x, y);			
		}
		else if (x >= (xmid) && y >= (ymid)) {//4��и�
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
	
	if (flag == 1) {//�Ϸ�Ǿ����� �˻�
		if (x % 2 == 0 && y % 2 == 0) {//���� ��
			cout << base;
			flag = 0;
		}
		else if (x % 2 == 0 && y % 2 == 1) {//���� ��
			cout << base + 2;
			flag = 0;
		}
		else if (x % 2 == 1 && y % 2 == 0) {//������ ��
			cout << base + 1;
			flag = 0;
		}
		else if (x % 2 == 1 && y % 2 == 1) {//������ ��
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