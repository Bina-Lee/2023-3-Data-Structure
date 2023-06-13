#if 0
#include<stdio.h>

int stack[20];
int top=-1;

void push(int v){
    if(top==19)return;
    top++;
    stack[top]=v;
    return;
}

int pop(){
    if(top==-1)return -999;
    top--;
    return stack[top+1];
}

int main(){
    while(1){
        int v;
        scanf("%d", &v);
        if(v==0)break;
        else if(v==-1)pop();
        else push(v);
    }
    if(top==-1){
        printf("-999");
        return 0;
    }
    printf("%d",stack[0]+stack[top]);
    return 0;
}
#endif

#if 0
#include<stdio.h>

int queue[20];
int front=0;
int rear=0;

void enqueue(int v){
    if((rear+1)%20==front)return;
    queue[rear]=v;
    rear=(rear+1)%20;
    return;
}

int dequeue(){
    if(front==rear)return -999;
    int res=queue[front];
    queue[front]=0;
    front=(front+1)%20;
    return res;
}

int main(){
    while(1){
        int v;
        scanf("%d",&v);
        if(v==0)break;
        else if(v==-1)dequeue();
        else enqueue(v);
    }
    if(front==rear){
        printf("-999");
        return 0;
    }
    printf("%d",(queue[front]+queue[(rear+19)%20]));
    return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}NODE;
NODE* head=0;

NODE* newNODE(int v){
    NODE* _new=(NODE*)malloc(sizeof(NODE));
    _new->data=v;
    _new->next=0;
    return _new;
}

void enqueue(int v){
    NODE* _new=newNODE(v);
    if(head==0){
        head=_new;
        return;
    }
    if(v%2==0){
        NODE* spear=head;
        while(spear->next!=0)spear=spear->next;
        spear->next=_new;
        return;
    }
    if(head->data%2==0){
        _new->next=head;
        head=_new;
        return;
    }
    NODE* spear=head;
    while((spear->next->data)%2!=0)spear=spear->next;
    NODE* spear2=spear->next;
    spear->next=_new;
    _new->next=spear2;
    return;
}

int main(){
    while(1){
        int v;
        scanf("%d",&v);
        if(v==0)break;
        enqueue(v);
    }
    if(head==0)return 0;
    NODE* spear=head;
    while(spear!=0){
        printf("%d ",spear->data);
        spear=spear->next;
    }
    return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}NODE;
NODE* head=0;

NODE* newNODE(int v){
    NODE* _new=(NODE*)malloc(sizeof(NODE));
    _new->data=v;
    _new->next=0;
    _new->prev=0;
    return _new;
}

void enqueue(int v){
    NODE* _new=newNODE(v);
    if(head==0){
        head=_new;
        return;
    }
    if(v%2==0){
        NODE* spear=head;
        while(spear->next!=0)spear=spear->next;
        spear->next=_new;
        _new->prev=spear;
        return;
    }
    if(head->data%2==0){
        _new->next=head;
        head->prev=_new;
        head=_new;
        return;
    }
    NODE* spear=head;
    while(spear->next!=0 && spear->next->data%2!=0)spear=spear->next;
    _new->next=spear->next;
    _new->next->prev=_new;
    spear->next=_new;
    _new->prev=spear;
    return;
}

int main(){
    while(1){
        int v;
        scanf("%d",&v);
        if(v==0)break;
        enqueue(v);
    }
    NODE* spear=head;
    while(spear->next!=0)spear=spear->next;
    while(spear!=0){
        printf("%d ",spear->data);
        spear=spear->prev;
    }
    return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}NODE;
NODE* head=0;

NODE* newNODE(int v){
    NODE* _new=(NODE*)malloc(sizeof(NODE));
    _new->data=v;
    _new->next=0;
    return _new;
}

void enqueue(int v){
    NODE* _new=newNODE(v);
    if(head==0){
        head=_new;
        return;
    }
    NODE* spear=head;
    while(spear->next!=0)spear=spear->next;
    spear->next=_new;
    return;
}

void del(int v){
    if(head==0)return;
    if(head->data==v){
        if(head->next==0){
            free(head);
            head=0;
            return;
        }
        NODE* spear=head;
        while(spear->data==v){
            head=spear->next;
            free(spear);
            spear=head;
            if(head==0)return;
        }
    }
    NODE* spear=head;
    while(spear->next->next!=0){
        if(spear->next->data==v){
            NODE* spear2=spear->next->next;
            free(spear->next);
            spear->next=spear2;
        }
        else spear=spear->next;
    }
    if(spear->next->data==v){
        free(spear->next);
        spear->next=0;
    }
    return;
}

int main(){
    while(1){
        int v;
        scanf("%d",&v);
        if(v==0)break;
        enqueue(v);
    }
    while(1){
        int v;
        scanf("%d",&v);
        if(v==-1)break;
        del(v);
    }
    if(head==0){
        printf("-999");
        return 0;
    }
    NODE* spear=head;
    while(spear!=0){
        printf("%d ",spear->data);
        spear=spear->next;
    }
}
#endif

//1520
#if 0
#include<stdio.h>
int main(){
    int hashTable[10]={0,};
    while(1){
        int v;
        scanf("%d",&v);
        if(v==-999)break;
        if(hashTable[v%10]<v)hashTable[v%10]=v;
    }
    int v;
    scanf("%d",&v);        
    printf("%d",hashTable[v%10]);
    return 0;
}
#endif

#if 01
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char data[21];
    int key;
    struct node* next;
}NODE;
NODE* hashTable[10];

NODE* newNODE(int _key,char* _value){
    NODE* _new=(NODE*)malloc(sizeof(NODE));
    _new->key=_key;
    strcpy(_new->data,_value);
    _new->next=0;
    return _new;
}

void enqueue(int _key,char* _value){
    NODE* _new=newNODE(_key,_value);
    if(hashTable[_key%10]==0){
        hashTable[_key%10]=_new;
        return;
    }
    NODE* spear=hashTable[_key%10];
    while(spear->next!=0)spear=spear->next;
    spear->next=_new;
    return;
}

int main(){
    while(1){
        int key;
        scanf("%d",&key);
        char value[21];
        scanf("%s",value);
        if(key==-999 && strcmp(value,"aaa")==0)break;
        enqueue(key,value);
    }
    int find;
    scanf("%d",&find);
    if(hashTable[find%10]==0){
        printf("NULL");
        return 0;
    }
    if(hashTable[find%10]->key==find){
        if(hashTable[find%10]->next!=0)printf("c");
        printf("%s",hashTable[find%10]->data);
        return 0;
    }
    NODE* spear=hashTable[find%10]->next;
    while(spear!=0){
        if(spear->key==find){
            printf("c%s",spear->data);
            return 0;
        }
        spear=spear->next;
    }
    printf("NULL");
    return 0;
}

#endif