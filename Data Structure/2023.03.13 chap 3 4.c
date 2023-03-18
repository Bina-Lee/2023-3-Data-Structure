#define _CRT_SECURE_NO_WARNINGS
//포인터 p91

#if 0
#include<stdio.h>
int main() {
	int a = 10;
	int* pa = &a;
	//short : 2byte
	//포인터 자체의 사이즈는 4byte

	//null pointer p91
	//아무것도 가리키지 않는 포인터
	int* NP1 = null;
	int* NP2 = 0;

	//p90
	//포인터 연산자

	//1. 주소 연산자
	int a1 = 10;
	
	//2. 간접참조연산자 '*'
	int a2 = 20;
	int* pa1 = &a2;
	printf("%d", *pa);
	//주의!!! 포인터 변수에 대해서만 적용가능

}
#endif


#if 0
#include<stdio.h>
void temp(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
	return;
}

int main() {
	//call by value
	//call by reference
	int a = 10;
	int b = 20;
	temp(&a, &b);	//call by reference
	printf("%d %d", a, b);
}
#endif

#if 0
#include<stdio.h>
int main() {
	//p92 배열과 포인터
	//뭐 대충 cp2에서 했던 내용
	//배열 이름은 주소 그자체 어쩌구
	int a[10];
	//a+1==&a[1]


}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
int main() {
	//p94 동적 메모리
	//malloc : memory allocation
	//free

	//정적mem : 컴파일 할 때 사용하는 메모리양 모두 결정
	//동적mem : 수행하면서 메모리 할당, 속도가 느림,
	//	운영체제가 대빵, 원하는만큼 정확하게
	//	free 안하면 메모리 낭비

	char* p = (char*)malloc(100);
	if (p == 0) {
		printf("메모리없음");
		return -100;
	}
	//free(p);
	// 
	//할당 받은 주소에 또 할당을 받으면
	//원래 할당 받아져 있던 곳은 엑세스 불가
	//unreferenced space problem

	//dangling pointer problem
	char* q = p;
	free(q);
	*p = 20;
	//writing하면 안되는 메모리에 writing해버림


}
#endif

#if 0
//구조체 포인터
#include<stdio.h>
#include<stdlib.h>

struct A{
	int a;
	char b;
};

int main() {
	struct A a;
	a.a = 10;
	a.b = 'a';

	struct A *pa = &a;
	pa->a = 40;
	pa->b = 'c';

	pa = (struct A*)malloc(sizeof(struct A));
}
#endif

//=========================================

//chap4 Stack

//LIFO : Last In First Out

//call stack 함수가 불린 순서

//구현?
//입력되는 정수를 저장하는 stack을 구현

//입력 : push <== stack에 값을 저장하는 operation
//출력 : pop  <== stack에서 값을 꺼내는 operation

#if 0
#include<stdio.h>

void push(int n) {

}
int pop(void) {

}

int main() {
	push(4);
	push(5);
	push(1);

	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
}
#endif
//114