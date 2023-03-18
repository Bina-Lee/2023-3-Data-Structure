//���� ���� stack

#if 0

#include<stdio.h>

#define STACK_SZ 10

int stack[STACK_SZ];
int top = -1; //���� ������ �� ����� ��ġ index

int isFull(void) {
	//full�̸� 1 ��ȯ
	//�ƴϸ� 0
	return (top == (STACK_SZ - 1));
}

int isEmpty(void) {
	return(top == -1);
}

void push(int _v) {

	if (isFull()) {
		printf("Eroor, Stack full\n");
		return;
	}

	top++;
	stack[top] = _v;

	return;
}

int pop(void) {

	if (isEmpty()) {
		printf("Error, Stack empty\n");
		return -999; //������� ����
	}

	int result = stack[top];
	top--;
	return result;
}

int main() {
	push(4);
	push(5);
	push(6);
	push(7);

	pop();
	printf("%d", pop()); //6 ��ȯ
}

#endif

//===============

//p135

#if 0

//�̷�ã��

//2���� �迭���� 1�� ��, 0�� ����
#include<stdio.h>

#define MAZE_SIZE 6
#define STACK_SIZE MAZE_SIZE*MAZE_SIZE

//reo wolumn
typedef struct{
	int r;
	int c;
}LOC;

LOC stack[STACK_SIZE];
int top = -1;

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'}
};

//�̷� ���
void printMaze(void) {
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j=0; j < MAZE_SIZE; j++) {
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int isFull(void) {
	return (top == (STACK_SIZE - 1));
}
int isEmpty(void) {
	return (top == -1);
}

void push(int _r, int _c) {
	if (_r < 0 || _c < 0) return;
	if ((maze[_r][_c] == '1') || (maze[_r][_c] == '.'))return;
	if (_r >= MAZE_SIZE || _c >= MAZE_SIZE) return;

	if (isFull())return;

	LOC temp = {_r, _c};
	top++;
	stack[top] = temp;
	return;
}

LOC pop(void) {
	if (isEmpty()) {
		LOC err_loc = { -1,-1 };
		return err_loc;	//���� ��
	}

	LOC result = stack[top];
	top--;
	return result;
}

int main() {

	LOC cur = { 1,0 };

	while (1) {
		//x�� �����ϸ� ��
		if (maze[cur.r][cur.c] == 'x') {
			printf("�� ã��, ��\n");
			return 0;
		}

		maze[cur.r][cur.c] = '.';//�Դ� �� ǥ��

		printMaze();

		//�����ִ� ��ġ ���� ���ÿ� �������
		push(cur.r - 1, cur.c);
		push(cur.r + 1, cur.c);
		push(cur.r, cur.c - 1);
		push(cur.r, cur.c + 1);

		cur = pop();

		if ((cur.r == -1) || (cur.c == -1)) {
			printf("�� ����");
			return -1;
		}
	}

	printMaze();
}

#endif

#if 1
//p128

//����ǥ����� ����ǥ��������� ��ȯ

//1+2 : infix expression : �����ڰ� ��� ����
//����ǥ��� : postfix expression : 1 2 +
//�����ڰ� ������ ���� ������ �ִ� �ΰ� ���� ����



#endif
