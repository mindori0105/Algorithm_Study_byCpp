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
	//i가 1부터 시작해서 필요없다.

	while (i<str.size()) {
		
		if (str.at(i) == ' ')
			ans++;
		
		if (str.at(i) == str.at(i-1) && str.at(i) == ' ')
			ans--;
		
		i++;
	}
	if (str.at(i - 1) != ' ')
		ans++;
	//마지막 공백이 없었을 때 카운트 올려줘야한다.
	//공백이 있다면 단어 카운트 돼서 관계X
	cout << ans;

	return 0;
}