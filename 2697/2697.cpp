#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 81
using namespace std;

int T;//test case의 수
vector<char> number;//sort위한 벡터
char input[MAX];//입력받을 배열

void sorting(int k, int length) {//바꾼 후 남은 자리 오름차순 정렬.
	int count=0;
	for (int i = k; i < length; i++) {
		number.push_back(input[i]);
		count++;
	}
	sort(number.begin(), number.end());
	for (int i = 0; i < count; i++) {
		input[k+i] = number[i];
	}
}

void start(int k,int length) {//몇 번째 수랑 바꿔야하는지 찾기
	char tmp;
	for (int i = (input[k - 1] - '0')+1; i < 10; i++) {
		for (int j = k; j < length; j++) {
			if (input[j]-'0' == i) {
				tmp = input[j];
				input[j] = input[k - 1];
				input[k - 1] = tmp;
				sorting(k, length);
				return;
			}
		}
	}
}

void print(int length) {//출력함수
	for (int i = 0; i < length; i++) {
		printf("%c",input[i]);
	}printf("\n");
	return;
}
void solution(int length) {//바꿀 자리 찾는 함수
	for (int i = length - 1; i > 0; i--) {
		if (input[i]-'0' > input[i - 1]-'0') {
			start(i,length);
			print(length);
			return;
		}
	}
	printf("BIGGEST\n");//바꿀 자리가 없다면 출력.
}

int getLength() {
	int cnt = 0;
	for (int i = 0; i < MAX; i++) {
		if (input[i] != NULL)
			cnt++;
		else
			return cnt;
	}
}

int main() {
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%s", input);
		solution(getLength());
		number.clear();//벡터 초기화
		input[0] = '\0';//배열 초기화
	}
	
	return 0;
}