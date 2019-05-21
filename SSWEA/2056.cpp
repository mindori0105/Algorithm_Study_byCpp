#include <iostream>
#include <string>
using namespace std;

//string itostr(int y, int m, int d);

int main(void) {
	int T;
	cin >> T;

	int date;
	int year;
	int month;
	int day;
	for (int i = 1; i < T+1; i++) {
		string result = "OK";
		cin >> date;

		//년도 뽑기.
		year = date / 10000;
		month = (date - (year * 10000)) / 100;
		day = (date - ((year * 10000) + month * 100));
		//error check
		if (month > 12 || month < 1 || day > 31 || day < 1) {
			result = "-1";
		}
		else {
			if (month == 2) {//2월
				if (day > 28)
					result = "-1";
			}
			else if (month % 2 == 0 && month != 8) {//8월을 제외한 나머지 달
				if (day > 30)
					result = "-1";
			}
		}
		if (result.compare("OK") == 0) {
			cout << "#" << i << " ";
			cout.width(4);
			cout.fill('0');
			cout << year;
			cout << "/";
			cout.width(2);
			cout.fill('0');
			cout << month;
			cout << "/";
			cout.width(2);
			cout.fill('0'); 
			cout << day << endl;
		//	result = itostr(year, month, day);
		}
		else
			cout << "#" << i << " " << result << endl;
	}
	
}
/*
string itostr(int y, int m, int d) {
	char *res;
	char buf[256];
		
	sprintf(buf, "%d/%d/%d", y, m, d);

	res = buf;
	return res;
}
*/