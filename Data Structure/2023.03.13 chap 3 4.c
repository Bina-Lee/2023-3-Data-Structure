#define _CRT_SECURE_NO_WARNINGS
//������ p91

#if 0
#include<stdio.h>
int main() {
	int a = 10;
	int* pa = &a;
	//short : 2byte
	//������ ��ü�� ������� 4byte

	//null pointer p91
	//�ƹ��͵� ����Ű�� �ʴ� ������
	int* NP1 = null;
	int* NP2 = 0;

	//p90
	//������ ������

	//1. �ּ� ������
	int a1 = 10;
	
	//2. �������������� '*'
	int a2 = 20;
	int* pa1 = &a2;
	printf("%d", *pa);
	//����!!! ������ ������ ���ؼ��� ���밡��

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
	//p92 �迭�� ������
	//�� ���� cp2���� �ߴ� ����
	//�迭 �̸��� �ּ� ����ü ��¼��
	int a[10];
	//a+1==&a[1]


}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
int main() {
	//p94 ���� �޸�
	//malloc : memory allocation
	//free

	//����mem : ������ �� �� ����ϴ� �޸𸮾� ��� ����
	//����mem : �����ϸ鼭 �޸� �Ҵ�, �ӵ��� ����,
	//	�ü���� �뻧, ���ϴ¸�ŭ ��Ȯ�ϰ�
	//	free ���ϸ� �޸� ����

	char* p = (char*)malloc(100);
	if (p == 0) {
		printf("�޸𸮾���");
		return -100;
	}
	//free(p);
	// 
	//�Ҵ� ���� �ּҿ� �� �Ҵ��� ������
	//���� �Ҵ� �޾��� �ִ� ���� ������ �Ұ�
	//unreferenced space problem

	//dangling pointer problem
	char* q = p;
	free(q);
	*p = 20;
	//writing�ϸ� �ȵǴ� �޸𸮿� writing�ع���


}
#endif

#if 0
//����ü ������
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

//call stack �Լ��� �Ҹ� ����

//����?
//�ԷµǴ� ������ �����ϴ� stack�� ����

//�Է� : push <== stack�� ���� �����ϴ� operation
//��� : pop  <== stack���� ���� ������ operation

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