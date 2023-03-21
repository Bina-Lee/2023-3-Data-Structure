//p146 Queue

//FIFO
//rear에서 들어가서 front로 나감
//들어오는 데이터는 뒤, 나가는 데이터는 앞

//stack : push, pop
//queue : enqueue(enter queue), dequeue(depart from queue)

//queue의 구현에도 배열을 사용함

//front : dequeue할 위치
//rear  ; enqueue할 위치

//front==rear : 큐가 비었음

//circular queue : front와 rear가 끝까지 가면 순환함
//일반적으로는 circular보다는 dequeue외면 데이터를 끌어다가 움직임
//front의 인덱스가 변하지 않음

//circular queue 한칸을 비워서 empty와 full을 구분함
//공간은 n-1개

#if 1

#include<stdio.h>

#define Q_SZ 10 //circular qeue : 9개

int que[Q_SZ];
int front=0;
int rear=0;

int isEmpty(void){
    return (front==rear);
}
int isFull(){
    return ((rear+1)%Q_SZ==front);
}

void enqueue(int _v){
    if(isFull()){
        printf("queue is full");
        return;
    }
    que[rear]=_v;
    rear=(rear+1)%Q_SZ;
}

int dequeue(void){
    if(isEmpty()){
        printf("queue is empty");
        return -999;//eror code
    }
    int result=que[front];
    front=(front+1)%Q_SZ;
    return result;
}

int main(){
    enqueue(4);
    enqueue(5);
    enqueue(7);

    while(!isEmpty()){
        printf("%d\n",dequeue());
    }
}

#endif

//덱
//deque : doule ended queue
//앞뒤 아무데서나 front, rear로 활용가능

#if 1

#include<stdio.h>

#define Q_SZ 10 //circular qeue : 9개

int que[Q_SZ];
int front=0;
int rear=0;

int isEmpty(void){
    return (front==rear);
}
int isFull(){
    return ((rear+1)%Q_SZ==front);
}

void enqueue(int _v){
    if(isFull()){
        printf("queue is full");
        return;
    }
    que[rear]=_v;
    rear=(rear+1)%Q_SZ;
}

int dequeue(void){
    if(isEmpty()){
        printf("queue is empty");
        return -999;//eror code
    }
    int result=que[front];
    front=(front+1)%Q_SZ;
    return result;
}

//add to front
void add_to_front(int _v){
    if(isFull()){
        printf("error queue is full");
        return;
    }
    front=(front+Q_SZ-1)%Q_SZ;
    que[front]=_v;
    return;
}

//del from rear
int del_from_rear(void){
    if(isEmpty()){
        printf("error queue is empty");
        return -999;
    }
    rear=(rear+Q_SZ-1)%Q_SZ;
    return que[rear];
        
}

int main(){
    add_to_front(1);
    enqueue(2);
    enqueue(3);
    add_to_front(4);

    while(!isEmpty()){
        printf("%d\n",del_from_rear());
    }
}

#endif

//chap6 : 연결리스트
//데구의 꽃 <--근데 왜 3주차에 나오는건데요
//Linked List

//array는 크기가 고정되어있다는 단점이 있음
//연속된 메모리 공간이 필요함
//중간에 끼워넣기도 힘듦
//중간에 빠져나가면 공간 채우기도 힘듦

//so... linked list라는 것이 나왔다
//array의 단점을 극복함
//대신 array의 장점을 다 잃음...성능도 ㅂㅅ...

//Linked List 장점
//필요한 만큼 메모리 사용
//연속되지 않은 메모리도 기워서 씀
//끼워넣기, 빼기 가능 - 매우 효율적으로 처리

//Linked List 단점
//느림
//구현이 복잡함

//linked list의 개별요소들을 node라고 부른다
//각 노드는 데이터를 저장하는 공간과 그 다음것을 가리키는 링크로 구성

#if 1

#include<stdio.h>

typedef struct Node{
    int data;
    struct node *next;
}NODE;
NODE* head=0;

//linked List에는 head가 있음

#endif