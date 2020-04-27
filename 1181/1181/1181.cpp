#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
vector<string> words;

bool compare(string a, string b) {
	if (a.length() == b.length())
		return a < b;
	else 
		return a.length() < b.length();
}

int main() {
	ios::sync_with_stdio(false);
	string tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		words.push_back(tmp);
	}
	sort(words.begin(), words.end(),compare);
	//words.erase(unique(words.begin(), words.end()), words.end());
	
	cout << words[0] << endl;
	for (int i = 1; i < (int)words.size(); i++) {
		if(words[i]!=words[i-1])
			cout << words[i] << endl;
	}
	
	
	return 0;
}
