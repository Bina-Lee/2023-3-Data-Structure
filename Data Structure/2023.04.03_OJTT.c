//OJT
//1625 오답
#if 01
#include<stdio.h>

int stack[20];
int top=-1;

int isEmpty(void){
	return (top==-1);
}
int isFull(void){
	return (top==19);
}

void push(int _v){
	if(isFull())return;
	top++;
	stack[top]=_v;
	return;
}

int pop(void){
	if(isEmpty())return -999;
	int result=stack[top];
	top--;
	return result;
}

int main(){
	while(1){
		int v;
		scanf("%d",&v);
		if(v==-1)pop();
		else if(v==0){
			if(top==-1){
				printf("%d",-999);
                return;
			}
			
			int result=pop();
			while(top!=0)pop();
			result=result+pop();
			printf("%d",result);
			return 0;
		}
		else {
			push(v);
		}
	}
}
#endif

//1625 정답
#if 01
#include<stdio.h>

int stack[20];
int top=-1;

int isEmpty(void){
	return (top==-1);
}
int isFull(void){
	return (top==19);
}

void push(int _v){
	if(isFull())return;
	top++;
	stack[top]=_v;
	return;
}

int pop(void){
	if(isEmpty())return -999;
	int result=stack[top];
	top--;
	return result;
}

int main(){
	while(1){
		int v;
		scanf("%d",&v);
		if(v==-1)pop();
		else if(v==0){
			break;
		}
		else {
			push(v);
		}
	}
    if(top==-1){
		printf("%d",-999);
        return;
	}
			
	printf("%d",stack[top]+stack[0]);
	return 0;
}
#endif

//1626 정답
#if 01
#include<stdio.h>
int queue[20];
int front=0;
int rear=0;

int isEmpty(void){
	return (rear-front==0);
}
int isFull(void){
	return (rear==20);
}

void enqueue(int _v){
	if(isFull())return;
	queue[rear]=_v;
	rear++;
	return;
}
int dequeue(void){
	if(isEmpty())return -999;
	int result=queue[front];
	front++;
	return result;
}

int main(){
	while(1){
		int v;
		scanf("%d",&v);
		if(v==-1)dequeue();
		else if(v==0)break;
		else {enqueue(v);}
	}
	if(isEmpty()){
		printf("%d",-999);
		return 0;
	}
	printf("%d",queue[front]+queue[rear-1]);
	return 0;
}
#endif

//1627 정답
#if 01
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}NODE;
NODE* head=0;

NODE* newSLL(int _v){
	NODE* _new=(NODE*)malloc(sizeof(NODE));
	_new->data=_v;
	_new->next=0;
	return _new;
}

void addToSLL(int _v){
	NODE* _new=newSLL(_v);
	if(head==0) {
		head=_new;
		return;
	}
	NODE* spear=head;
	if(_v%2==1){
		if(head->data%2==0){
			_new->next=head;
			head=_new;
			return;
		}
		while(spear->next->data%2==1)spear=spear->next;
		_new->next=spear->next;
		spear->next=_new;
		return;
	}
	while(spear->next!=0)spear=spear->next;
	spear->next=_new;
	return;
}

void allSLL(void){
	if(head==0)return;
	NODE* spear=head;
	while(spear!=0){
		printf("%d ",spear->data);
		spear=spear->next;
	}
	return;
}

int main(){
	while(1){
		int v;
		scanf("%d",&v);
		if(v==0)break;
        addToSLL(v);
	}
	allSLL();
}
#endif

//1628
#if 01
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* prev;
	struct node* next;
}NODE;
NODE* head=0;

NODE* newDLL(int _v){
	NODE* _new=(NODE*)malloc(sizeof(NODE));
	_new->next=0;
	_new->prev=0;
	_new->data=_v;
	return _new;
}

void addToDLL(int _v){
	NODE* _new=newDLL(_v);
	if(head==0){
		head=_new;
		return;
	}
	if(_v%2==1){
		if(head->data%2==0){
			_new->next=head;
			head->prev=_new;
			head=_new;
			return;
		}
		NODE* spear=head;
		while(spear->next->data%2==1)spear=spear->next;
		_new->next=spear->next;
		spear->next->prev=_new;
		spear->next=_new;
		_new->prev=spear;
		return;
	}
	NODE* spear=head;
	while(spear->next!=0)spear=spear->next;
	_new->prev=spear;
	spear->next=_new;
	return;
}

void showDLL(void){
	NODE* spear=head;
	while(spear->next!=0)spear=spear->next;
	while(spear!=0){
		printf("%d ",spear->data);
		spear=spear->prev;
	}
	return;
}

int main(){
	while(1){
		int v;
		scanf("%d",&v);
		if(v==0)break;
		addToDLL(v);
	}
	showDLL();
}
#endif

//1629
#if 1
#include<stdio.h>

int pivo(int n){
	if(n==0)return 0;
	else if(n==1)return 1;
	return pivo(n-1)+pivo(n-2);
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d",pivo(n));
}
#endif

//1630
#if 1
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int result=0;
	if(n==0);
	else if(n==1)result=1;
	else{
		int prev=1;
		int prevprev=0;
		for(int i=2;i<=n;i++){
			result=prev+prevprev;
			prevprev=prev;
			prev=result;
		}
	}
	printf("%d",result);
}
#endif

//1631
#if 1
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}NODE;
NODE* head=0;

NODE* newNODE(int _v){
	NODE* _new=(NODE*)malloc(sizeof(NODE));
	_new->data=_v;
	_new->next=0;
	return _new;
}

void push(int _v){
	NODE* _new=newNODE(_v);
	if(head==0){
		head=_new;
		return;
	}
	NODE* spear=head;
	while(spear->next!=0)spear=spear->next;
	spear->next=_new;
	return;
}

void pop(void){
	if(head==0)return;
	if(head->next==0){
		free(head);
		head=0;
		return;
	}
	NODE* spear=head;
	while(spear->next->next!=0)spear=spear->next;
	NODE* spear2=spear->next;
	spear->next=0;
	free(spear2);
	return;
}

int sum(void){
	if(head==0)return 0;
	if(head->next==0)return head->data;
	NODE* spear=head;
	int result=0;
	while(spear!=0){
		result=result+(spear->data);
		spear=spear->next;
	}
	return result;
}

int main(){
	while(1){
		int v;
		scanf("%d",&v);
		if(v==0)break;
		else if(v==-1)pop();
		else push(v);
	}
	printf("%d",sum());
}
#endif

//1632
#if 1
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* prev;
	struct node* next;
}NODE;
NODE* head=0;

NODE* newNODE(int _v){
	NODE* _new=(NODE*)malloc(sizeof(NODE));
	_new->data=_v;
	_new->next=0;
	_new->prev=0;
	return _new;
}

void push(_v){
	NODE* _new=newNODE(_v);
	if(head==0){
		head=_new;
		return;
	}
	head->next=_new;
	_new->prev=head;
	head=_new;
	return;
}

void pop(void){
	if(head==0)return;
	if(head->prev==0){
		free(head);
		head=0;
		return;
	}
	head=head->prev;
	free(head->next);
	head->next=0;
	return;
}

void all(void){
	if(head==0){
		printf("%d",-999);
		return;
	}
	if(head->prev==0){
		printf("%d %d ",head->data,head->data);
		return;
	}
	while(head->prev!=0){
		printf("%d ",head->data);
		head=head->prev;
	}
	printf("%d ",head->data);
	while(head->next!=0){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("%d ",head->data);
	return;
}

int main(){
	while(1){
		int v;
		scanf("%d",&v);
		if(v==0)break;
		if(v==-1)pop();
		else push(v);
	}
	all();
}
#endif

//1633
#if 1
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}NODE;
NODE* front=0;
NODE* rear=0;

NODE* newNODE(int _v){
	NODE* _new=(NODE*)malloc(sizeof(NODE));
	_new->data=_v;
	_new->next=0;
	return _new;
}

void inqueue(int _v){
	NODE* _new=newNODE(_v);
	if(front==0){
		front=_new;
		rear=_new;
		return;
	}
	rear->next=_new;
	rear=rear->next;
	return;
}

void dequeue(void){
	if(front==0)return;
	if(front==rear){
		free(front);
		front=0;
		rear=0;
		return;
	}
	NODE* spear=front;
	front=front->next;
	free(spear);
	return;
}

int max(void){
	if(front==0)return 0;
	if(front==rear)return front->data;
	int result=front->data;
	while(front!=rear){
		if(result<front->next->data){
			result=front->next->data;
		}
		front=front->next;
	}
	return result;
}

int main(){
	while(1){
		int v;
		scanf("%d",&v);
		if(v==0)break;
		if(v==-1)dequeue();
		else inqueue(v);
	}
	printf("%d",max());
}
#endif

//1634
#if 1
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
	struct node* prev;
}NODE;
NODE* front=0;
NODE* rear=0;

NODE* newNODE(int _v){
	NODE* _new=(NODE*)malloc(sizeof(NODE));
	_new->data=_v;
	_new->next=0;
	_new->prev=0;
	return _new;
}

void inqueue(int _v){
	NODE* _new=newNODE(_v);
	if(front==0){
		front=_new;
		rear=_new;
		return;
	}
	rear->next=_new;
	rear=_new;
	return;
}

void dequeue(void){
	if(front==0)return;
	if(front==rear){
		free(front);
		front=0;
		rear=0;
		return;
	}
	NODE* spear=front;
	front=front->next;
	free(spear);
	return;
}

int checkmax(void){
	NODE* spear=front;
	int result=spear->data;
	while(spear!=0){
		if(result<spear->data)result=spear->data;
		spear=spear->next;
	}
	return result;
}

int checkmin(void){
	NODE* spear=front;
	int result=spear->data;
	while(spear!=0){
		if(result>spear->data)result=spear->data;
		spear=spear->next;
	}
	return result;
}

int count(void){
	if(front==0)return 0;
	if(front==rear)return 1;
	int result=1;
	NODE* spear=front;
	while(spear->next!=0){
		result++;
		spear=spear->next;
	}
	return result;
}

int main(){
	while(1){
		int v;
		scanf("%d",&v);
		if(v==0)break;
		if(v==-1)dequeue();
		else inqueue(v);
	}
	if(front==0){
		printf("%d ",0);
		return 0;
	}
	int max=checkmax();
	int min=checkmin();
	if(max==min){
		printf("%d",-999);
		return 0;
	}
	int length=count();
	int* array=(int*)malloc(sizeof(int)*length);
	
	NODE* spear=front;
	int i=0;
	while(spear!=0){
		array[i]=spear->data;
		i++;
		spear=spear->next;
	}

	for(int i=1;i<length;i++){
		for(int j=1;j<length;j++){
			if(array[j-1]>array[j]){
				int temp=array[j-1];
				array[j-1]=array[j];
				array[j]=temp;
			}
		}
	}
	for(int i=1;i<length-1;i++){
		printf("%d ",array[i]);
	}
	free(array);
	return 0;
}
#endif

//1636
#if 1
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}NODE;
NODE* front=0;
NODE* rear=0;

NODE* newNODE(int _v){
	NODE* _new=(NODE*)malloc(sizeof(NODE));
	_new->data=_v;
	_new->next=0;
	return _new;
}

void enqueue(int _v){
	NODE* _new=newNODE(_v);
	if(front==0){
		front=_new;
		rear=_new;
		return;
	}
	NODE* spear=front;
	while(spear!=rear){
		if(spear->data==_new->data){
			NODE* newFront=newNODE(_v);
			newFront->next=front;
			front=newFront;
			break;
		}
		spear=spear->next;
	}
	rear->next=_new;
	rear=rear->next;
	return;
}

void dequeue(void){
	if(front==0)return;
	if(front==rear){
		free(front);
		front=0;
		rear=0;
		return;
	}
	NODE* spear=front;
	front=front->next;
	free(spear);
}

void printAll(void){
	if(front==0){
		printf("%d",0);
		return;
	}
	NODE* spear=front;
	while(spear!=0){
		printf("%d ",spear->data);
		spear=spear->next;
	}
	return;
}

int main(){
	while(1){
		int v;
		scanf("%d",&v);
		if(v==0)break;
		if(v==-1)dequeue();
		else enqueue(v);
	}
	printAll();
	return 0;
}
#endif

//1635
#if 1
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
	struct node* prev;
}NODE;
NODE* head=0;

NODE* newNODE(int _v){
	NODE* _new=(NODE*)malloc(sizeof(NODE));
	_new->data=_v;
	_new->next=0;
	_new->prev=0;
	return _new;
}

void pop(void){
	if(head==0)return;
	if(head->next==0){
		free(head);
		head=0;
		return;
	}
	NODE* spear=head;
	while(spear->next->next!=0)spear=spear->next;
	free(spear->next);
	spear->next=0;
	return;
}

void push(int _v){
	NODE* _new=newNODE(_v);
	if(head==0)head=_new;
	if(head->next==0){
		if(head->data==_new->data)return;
		head->next=_new;
		_new->prev=head;
		return;
	}
	NODE* spear=head;
	while(spear->next!=0){
		if(spear->data==_new->data){
			NODE* spear2=spear;
			spear=spear->next;
			spear2->next->prev=spear2->prev;
			if(spear2->prev==0){
				spear->prev=0;
				head=spear;
			}
			else spear2->prev->next=spear2->next;
			free(spear2);
		}
		else spear=spear->next;
	}
	if(spear->data==_new->data)return;
	spear->next=_new;
	_new->prev=spear;
	return;
}

void printAll(void){
	if(head==0){
		printf("%d",0);
		return;
	}
	if(head->next==0){
		printf("%d",head->data);
		return;
	}
	NODE* spear=head;
	while(spear->next!=0)spear=spear->next;
	while(spear!=0){
		printf("%d ",spear->data);
		spear=spear->prev;
	}
	return;
}

int main(){
	while(1){
		int v;
		scanf("%d",&v);
		if(v==0)break;
		if(v==-1)pop();
		else push(v);
	}
	printAll();
	return 0;
}
#endif

//1637
#if 1
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
	struct node* prev;
}NODE;
NODE* front=0;
NODE* rear=0;

NODE* newNODE(int _v){
	NODE* _new=(NODE*)malloc(sizeof(NODE));
	_new->data=_v;
	_new->next=0;
	_new->prev=0;
	return _new;
}

void dequeue(void){
	if(front==0)return;
	if(front==rear){
		NODE* spear=front;
		front=0;
		rear=0;
		free(spear);
		return;
	}
	NODE* spear=front;
	front=front->next;
	front->prev=0;
	free(spear);
	return;
}

void enqueue(int _v){
	NODE* _new=newNODE(_v);
	if(front==0){
		front=_new;
		rear=_new;
		return;
	}
	if(front==rear){
		if(front->data >= _v){
			front=_new;
			front->next=rear;
			rear->prev=front;
			return;
		}
		rear=_new;
		rear->prev=front;
		front->next=rear;
		return;
	}
	if(front->data >= _v){
		_new->next=front;
		front->prev=_new;
		front=_new;
		return;
	}
	NODE* spear=front;
	while(spear->next!=0){
		if(spear->data >= _v){
			_new->prev=spear->prev;
			spear->prev->next=_new;
			_new->next=spear;
			spear->prev=_new;
			return;
		}
		spear=spear->next;
	}
	if(spear->data >= _v){
		_new->prev=spear->prev;
		spear->prev->next=_new;
		_new->next=spear;
		spear->prev=_new;
		return;
	}
	_new->prev=spear;
	spear->next=_new;
	rear=_new;
	return;
}

void printAll(void){
	if(front==0){
		printf("%d",0);
		return;
	}
	if(front==rear){
		printf("%d",front->data);
		return;
	}
	NODE* spear=rear;
	while(spear!=0){
		printf("%d ",spear->data);
		spear=spear->prev;
	}
	return;
}

int main(){
	while(1){
		int v;
		scanf("%d",&v);
		if(v==0)break;
		if(v==-1)dequeue();
		else enqueue(v);
	}
	printAll();
}
#endif