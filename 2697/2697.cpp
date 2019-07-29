#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 81
using namespace std;

int T;//test case�� ��
vector<char> number;//sort���� ����
char input[MAX];//�Է¹��� �迭

void sorting(int k, int length) {//�ٲ� �� ���� �ڸ� �������� ����.
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

void start(int k,int length) {//�� ��° ���� �ٲ���ϴ��� ã��
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

void print(int length) {//����Լ�
	for (int i = 0; i < length; i++) {
		printf("%c",input[i]);
	}printf("\n");
	return;
}
void solution(int length) {//�ٲ� �ڸ� ã�� �Լ�
	for (int i = length - 1; i > 0; i--) {
		if (input[i]-'0' > input[i - 1]-'0') {
			start(i,length);
			print(length);
			return;
		}
	}
	printf("BIGGEST\n");//�ٲ� �ڸ��� ���ٸ� ���.
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
		number.clear();//���� �ʱ�ȭ
		input[0] = '\0';//�迭 �ʱ�ȭ
	}
	
	return 0;
}