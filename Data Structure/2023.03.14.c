//정수 저장 stack

#if 0

#include<stdio.h>

#define STACK_SZ 10

int stack[STACK_SZ];
int top = -1; //현재 스택의 맨 꼭대기 위치 index

int isFull(void) {
	//full이면 1 반환
	//아니면 0
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
		return -999; //에러라고 가정
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
	printf("%d", pop()); //6 반환
}

#endif

//===============

//p135

#if 0

//미로찾기

//2차원 배열에서 1은 벽, 0은 공간
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

//미로 출력
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
		return err_loc;	//스택 빔
	}

	LOC result = stack[top];
	top--;
	return result;
}

int main() {

	LOC cur = { 1,0 };

	while (1) {
		//x에 도착하면 끝
		if (maze[cur.r][cur.c] == 'x') {
			printf("길 찾음, 끝\n");
			return 0;
		}

		maze[cur.r][cur.c] = '.';//왔던 곳 표시

		printMaze();

		//갈수있는 위치 전부 스택에 집어넣음
		push(cur.r - 1, cur.c);
		push(cur.r + 1, cur.c);
		push(cur.r, cur.c - 1);
		push(cur.r, cur.c + 1);

		cur = pop();

		if ((cur.r == -1) || (cur.c == -1)) {
			printf("길 없음");
			return -1;
		}
	}

	printMaze();
}

#endif

#if 1
//p128

//중위표기식을 후위표기수식으로 변환

//1+2 : infix expression : 연산자가 가운데 있음
//후위표기식 : postfix expression : 1 2 +
//연산자가 나오면 가장 가까이 있는 두개 숫자 연산



#endif