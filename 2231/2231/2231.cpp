#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int N;

int main() {
	scanf("%d", &N);

	for (int i = 1; i < N; i++) {
		int sum = i;
		int pos = i;
		while (pos > 10) {
			sum += pos % 10;
			pos /= 10;
		}
		sum += (pos % 10);
		if (sum == N) {
			printf("%d\n", i);
			return 0;
		}
	}

	printf("0\n");

	return 0;
}
