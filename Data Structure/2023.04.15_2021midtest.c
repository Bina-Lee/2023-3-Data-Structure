#if 0
//1505
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
    if(_v% 2==1){
        NODE* spear=head;
        head=_new;
        head->next=spear;
        return;
    }
    else{
        NODE* spear=head;
        while(spear->next!=0)spear=spear->next;
        spear->next=_new;
        return;
    }
}

void print(void){
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
        if(v==-999)break;
        else push(v);
    }
    print();
}
#endif

#if 0
//1506
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

int check=0;

void push(int _v){
    if(_v==0){
        check^=1;
        return;
    }
    NODE* _new=newNODE(_v);
    if(head==0){
        head=_new;
        return;
    }
    if(check==0){
        NODE* spear=head;
        while(spear->next!=0)spear=spear->next;
        spear->next=_new;
        _new->prev=spear;
        return;
    }
    else{
        NODE* spear=head;
        _new->next=head;
        head->prev=_new;
        head=_new;
        return;
    }
}

void print(void){
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
        if(v==-999)break;
        else push(v);
    }
    print();
}
#endif

#if 1
//1507
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    unsigned char str[30];
    int length;
    struct node* left;
    struct node* right;
}NODE;
NODE* root=0;

NODE* newNODE(unsigned char* _v){
    NODE* _new=(NODE*)malloc(sizeof(NODE));
    strcpy(_new->str,_v);
    _new->length=strlen(_new->str);
    _new->left=0;
    _new->right=0;
    return _new;
}

typedef struct comb{
    NODE* parent;
    NODE* me;
}COMB;

COMB find(NODE* find){
    COMB temp={0,root};
    while(1){
        if(temp.me==0)return temp;
        if(temp.me->length==find->length)return temp;
        if(strcmp(find->str,temp.me->str)<0){
            temp.parent=temp.me;
            temp.me=temp.me->left;
        }
        else{
            temp.parent=temp.me;
            temp.me=temp.me->right;
        }
    }
}

void del(NODE* spear){
    COMB temp=find(spear);
    if(temp.me==0)return;
    if(temp.me->left==0 && temp.me->right==0){
        if(temp.parent==0){
            root=0;
            free(temp.me);
            return;
        }
        free(temp.me);
        temp.me=0;
        return;
    }
    if(temp.me->left!=0 && temp.me->right!=0){
        NODE* spear2=temp.me->left;
        while(spear2->right==0)spear2=spear2->right;
        unsigned char tempdata[30];
        strcpy(tempdata,temp.me->str);
        if(spear2->left!=0)del(spear2);
        strcpy(temp.me->str,tempdata);
        temp.me->length=strlen(temp.me->str);
        return;
    }
    if(temp.me->left!=0){
        ;//NODE* 
    }

}

void push(unsigned char* _v){
    NODE* _new=newNODE(_v);
    del(_new);
}

int main(){
    while(1){
        unsigned char v[30];
        scanf("%s",v);
        if(strcmp(v,"ab")==0)break;
        else push(v);
    }
}
#endif

#if 0
//1508
#include<stdio.h>
int stack[5];
int top=-1;

void pop(void);

void push(int _v){
    if(_v==-1){
        pop();
        return;
    }
    if(top==4)return;
    top++;
    stack[top]=_v;
    return;
}

void pop(void){
    int sum=0;
    while(top!=-1){
        sum=sum+stack[top];
        top--;
    }
    push(sum);
    return;
}

void realpop(void){
    while(top!=-1){
        printf("%d ", stack[top]);
        top--;
    }
    return;
}

int main(){
    while(1){
        int v;
        scanf("%d",&v);
        if(v==-999)break;
        else push(v);
    }
    realpop();
}
#endif

#if 0
//1509
#include<stdio.h>
int queue[6];
int front=0;
int rear=0;

void enqueue(int _v){
    if(front==(rear+1)%6)return;
    queue[rear]=_v; // index : rear 에 입력
    rear=(rear+1)%6;    //rear 증가
    return;
}

void dequeue(void){
    if(front==rear)return;  //queue가 비어있으면 아무것도 안함
    int temp=queue[front];  //다시 enqueue해야되기 때문에 값 저장
    front=(front+1)%6;  //front 증가
    queue[rear]=temp;   //temp를 enqueue
    rear=(rear+1)%6;    //rear 증가
    return;
}

void realdequeue(void){
    while(front!=rear){
        printf("%d ", queue[front]); //head 출력
        front=(front+1)%6;    //head 증가
    }
    return;
}

int main(){
    while(1){
        int v;
        scanf("%d",&v); //v 입력
        if(v==-999)break;   //-999면 입력 종료, 출력하러 감
        if(v==-1)dequeue(); //-1이면 dequeue
        else enqueue(v);    //나머지 v값은 enqueue
    }
    realdequeue();  //출력하러감
}
#endif