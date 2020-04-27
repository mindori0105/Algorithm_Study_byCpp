#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

char input[6];
vector<int> stack;
int N, tmp;
void func(char* input) {
	if (input[0] == 'T' || input[0] == 't') {
		if (stack.size() > 0) cout << stack.back() << endl;
		else cout << -1 << endl;
	}

	else if (input[0] == 'E' || input[0] == 'e') {
		if (stack.size() == 0) cout << 1 << endl;
		else cout << 0 << endl;
	}
	else if (input[0] == 'S' || input[0] == 's') cout << stack.size() << endl;
	else if (input[0] == 'P' && input[1] == 'U' || input[0] == 'p' && input[1] == 'u' || input[0] == 'P' && input[1] == 'u' || input[0] == 'p' && input[1] == 'U') {
		cin >> tmp;
		stack.push_back(tmp);
	}

	else {
		if (stack.size() == 0) cout << "-1" << endl;
		else {
			cout << stack.back() << endl;
			stack.pop_back();
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	//cin.get();
	for (int i = 0; i < N; i++) {
		cin >> input;
		func(input);
	}

	return 0;
}
