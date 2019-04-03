#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int N;
vector<pair<int, int>> vc;

int main() {
	cin >> N;

	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		vc.push_back(make_pair(a, b));
	}

	sort(vc.begin(), vc.end());

	for (int i = 0; i < N; i++) {
		// endl 시간 초과
		cout << vc[i].first << ' ' << vc[i].second << '\n';
	}

	return 0;
}