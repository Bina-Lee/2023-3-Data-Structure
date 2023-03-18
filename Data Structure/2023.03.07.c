//데이터 구조 1주차 2차시

//Recursion 순환 p46?

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

//반복문 example

#include<stdio.h>
int main() {
	int n = 10;
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result = result * i;
	}
	printf("%d", result);
}

//recursion은 속도가 느림, 공간을 할당받는 시간

//거듭제곱값의 계산 p50

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

//피보나치 수열의 계산 p53

#include<stdio.h>

int pibo(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	int pp = 0; //previous-previous 전에전꺼
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

//==> > recursion에서 반복되는걸 값을 저장하면 자원 및 시간 단축 가능

//n - 1개짜리 배열 답아서 코드 작성
#include<stdio.h>
#include<stdlib.h>
int pibo_r_s(int n) {

}
int main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

}

//하노이타워 p56

void hanoi(int n, int from, int temp, int to) {
	if (n == 1) {
		printf("%d번돌을 #d에서 #d로\n", 1, from, to);
		return;
	}

	hanoi(n - 1, from,to,temp);
	printf("%d번돌을 #d에서 #d로\n", n,from,to);
	hanoi(n - 1, temp,from,to);
	return;
}
int main() {
	hanoi(3, 1, 2, 3);
}

//03. 배열 구조체 포인터 p70

typedef struct {
	int a;
	int b;
} Person;
int main() {
	Person new;
}

//76~88 skip

//포인터 p89

#endif