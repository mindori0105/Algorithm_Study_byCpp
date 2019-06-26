#include <iostream>

using namespace std;

int N, M;
int arr[9];
bool chk[9];

void bTrack(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	for(int i=0;i<N;i++){
		if (!chk[i]) {
			chk[i] = true;
			arr[cnt] = i + 1;
			bTrack(cnt + 1);
			chk[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	bTrack(0);
	return 0;
}