//������ ���� 1���� 2����

//Recursion ��ȯ p46?

//factorial example

#if 0

#include<stdio.h>

int factorial(int n) {
	if (n == 1)return 1;
	return n * factorial(n - 1);
}

int main() {
	int result = factorial(10);
	printf("%d", result);
}

//�ݺ��� example

#include<stdio.h>
int main() {
	int n = 10;
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result = result * i;
	}
	printf("%d", result);
}

//recursion�� �ӵ��� ����, ������ �Ҵ�޴� �ð�

//�ŵ��������� ��� p50

#include<stdio.h>

int pow(int a, int b) {
	if (b == 1)return a;
	return a * pow(a, b - 1);
}

int main() {
	int result = pow(2, 3);
	printf("%d", result);
}

//==> > a ^ n : O(n)

int pow(int a, int b) {
	if (b == 1)return a;
	if (b % 2 == 0) return pow(a * a, b / 2);
	else return a * pow(a * a, (b - 1) / 2);
}

int main() {
	int result = pow(2, 3);
	printf("%d", result);
}

//==> > O(log_2 n)

//�Ǻ���ġ ������ ��� p53

#include<stdio.h>

int pibo(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	int pp = 0; //previous-previous ��������
	int p = 01;
	int result = 0;
	for (int i = 2; i <= n; i++) {
		result = pp + p;
		pp = p;
		p = result;
	}
}

int pibo_r(int n) {
	if (n == 0)return 0;
	if (n == 1)return 1;
	return fibo_r(n - 2) + fibo_r(n - 1);
}

//==> > recursion���� �ݺ��Ǵ°� ���� �����ϸ� �ڿ� �� �ð� ���� ����

//n - 1��¥�� �迭 ��Ƽ� �ڵ� �ۼ�
#include<stdio.h>
#include<stdlib.h>
int pibo_r_s(int n) {

}
int main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

}

//�ϳ���Ÿ�� p56

void hanoi(int n, int from, int temp, int to) {
	if (n == 1) {
		printf("%d������ #d���� #d��\n", 1, from, to);
		return;
	}

	hanoi(n - 1, from,to,temp);
	printf("%d������ #d���� #d��\n", n,from,to);
	hanoi(n - 1, temp,from,to);
	return;
}
int main() {
	hanoi(3, 1, 2, 3);
}

//03. �迭 ����ü ������ p70

typedef struct {
	int a;
	int b;
} Person;
int main() {
	Person new;
}

//76~88 skip

//������ p89

#endif