#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vec;

int main() {
	scanf("%d", &N); 
	for (int i = 0; i < N; i++) vec.push_back(i + 1);
	for (int i = 0; i < N; i++) printf("%d ", vec[i]);
	printf("\n");
	while (next_permutation(vec.begin(), vec.end())) {
		for (int i = 0; i < N; i++) printf("%d ", vec[i]);
		printf("\n");
	}
	return 0;
}