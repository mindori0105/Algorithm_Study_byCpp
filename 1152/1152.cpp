#include<iostream>
#include<string>
using namespace std;

int main(void) {

	string str;
	getline(cin, str);

	int i=1;
	int ans=0;

	//if (str.at(0) == ' ')
		//ans--;
	//i�� 1���� �����ؼ� �ʿ����.

	while (i<str.size()) {
		
		if (str.at(i) == ' ')
			ans++;
		
		if (str.at(i) == str.at(i-1) && str.at(i) == ' ')
			ans--;
		
		i++;
	}
	if (str.at(i - 1) != ' ')
		ans++;
	//������ ������ ������ �� ī��Ʈ �÷�����Ѵ�.
	//������ �ִٸ� �ܾ� ī��Ʈ �ż� ����X
	cout << ans;

	return 0;
}