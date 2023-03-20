// postfit 계산
// stack, LIFO (last in first out)

//우리가 사용하는 수식 : infix : operator 위치 기준

//컴퓨터가 계산할 때는 postfix형태를 사용함
// 2 3 +
//괄호를 사용하지 않고도 우선순위 표기가 표기가 가능
// 2 3 5 * +
// 2 3 + 5 *

//왼쪽에서 오른쪽으로 읽어나가면서
//연산자를 만나면 앞의 2개 숫자로 계산, 결과값으로 치환
//끝날때까지 무한반복

//컴퓨터는 infix를 postfix로 전환해서 연산

//사칙연산 한자리 정수형 계산만 할 예정
//수식에 공백없이 입력

//숫자면 push
//연산자면 stack에서 2개를 pop하고 연산, 후에 push
//연산 끝날때 까지
//에러나는 수식은 없다고 가정하자

#if 0

#include<stdio.h>

#define SIZE 20

int stack[SIZE];
int top=-1;

int isFull(void){
    return (top==(SIZE-1));
}

int isEmpty(void){
    return (top==-1);
}

void push(int _v){
    if(isFull){
        printf("Error, Stack is full\n");
        return;
    }
    top++;
    stack[top]=_v;
    return;
}

int pop(void){
    if(isEmpty){
        printf("Error, Stack is empty\n");
        return -999;//error code
    }
    int result=stack[top];
    top--;
    return result;
}

int calc_expr(char op,int v1,int v2){
    switch(op){
        case '+':
            return v2+v1;
        case '-':
            return v2-v1;
        case '*':
            return v2*v1;
        case '/':
            return v2/v1;
        default:
            break;
    }

}

int main(){
    char postfix[]="234*+"; //postfix expression
    int idx=0;//expression에서 현재 읽는 위치

    while(postfix[idx]!=0){

        char c=postfix[idx];
        if(c>='0'&&c<='9'){
            push((int)(c-'0'));
        }
        else{   //error는 없다고 가정하기 때문에 else로 함
            int v1=pop();
            int v2=pop();
            int res=calc_expr(c,v1,v2);
            push(res);
        }

        idx++;
    }

    printf("연산 결과는 %d\n",pop());
}

#endif

//infix=>postfix

//숫자 순서는 안바뀜
//왼쪽부터 숫자몇 출력
//연산자면 기본적으로 push
//연산순위가 낮은 다른 연산자가 있으면 
//  연사눈위가 높은 것을 pop 하고 push

//여는 괄호는 무조건 push
//여는 괄호의 우선순위는 최하위로 취급  //괄호 자체도 연산자임 괄호 자체를 최하위
//닫는 괄호가 나오면 여는 괄호 최초나올 때까지 pop하면서 연산자 출력


#if 1

#include<stdio.h>

#define SIZE 20

char stack[SIZE];
int top=-1;

int isFull(void){
    return (top==(SIZE-1));
}

int isEmpty(void){
    return (top==-1);
}

void push(char _v){
    if(isFull){
        printf("Error, Stack is full\n");
        return;
    }
    top++;
    stack[top]=_v;
    return;
}

char pop(void){
    if(isEmpty){
        printf("Error, Stack is empty\n");
        return 0;//error code
    }
    char result=stack[top];
    top--;
    return result;
}

intIHgher(char _c){
    if(stack[top]=='('){
        return 1;
    }
    else if(_c=='*'||_c=='/'){
        if(stack[top]=='+'||_c=='-'){
            return 1;
        }
    }
    return 0;
}

int main(void){

    char infix_expr[]="1*(2+3)";

    int idx=0;

    while(infix_expr[idx]!=0){

        char _c=infix_expr[idx];

        if(_c>='0'&&_c<='9'){
            printf("%c",_c);
        }
        else{
            if(_c=='('){
                push(_c);
            }
            else if(_c==')'){
                while(1){
                    char _d=pop();
                    if(_d=='('){
                        break;
                    }
                    printf("%c",_d);
                }
            }
            else{
                if(isEmpty())push(_c);
                else{
                    //amIHigher(_c)
                    //우선순위에 따라 동작
                    //높으면 1, 아니면 0 반환 시키면 됨
                    while(1){
                        if(!amIHigher(_c))push(_c);
                        else break;
                    }
                    push(_c);
                }
            }

        }

        idx++;
    }

    while(isEmpty()!=1){
        printf("%c",pop());
    }
    printf("\n");

    return 0;
}

#endif

