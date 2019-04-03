#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(void){
	int TC;
	cin >> TC;

	int x1, y1, r1;
	int x2, y2, r2;
	int ans;

	for (int tc = 0; tc < TC; tc++) {
		cin >> x1 >> y1 >> r1;
		cin >> x2 >> y2 >> r2;

		double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		int minus = abs(r1 - r2);
		int plus = r1 + r2;

		if (dist == 0) {
			if (r1 == r2) {
				ans = -1;
			}
			else
				ans = 0;
		}
		else {
			if (plus > dist && minus < dist) {
				ans = 2;
			}
			else if (plus == dist || minus == dist) {
				ans = 1;
			}
			else
				ans = 0;
		}
		cout <<ans << endl;
	}
}