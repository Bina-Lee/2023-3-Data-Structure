#if 0
//A
#include<stdio.h>
int stack[5];
int top=-1;

void push(int _v){
    if(top==4){
        for(int i=1;i<5;i++){
            stack[i-1]=stack[i];
        }
        stack[4]=_v;
        return;
    }
    top++;
    stack[top]=_v;
    return;
}

void pop(void){
    if(top==-1)return;
    top--;
    return;
}

void realpop(void){
    if(top==-1){
        printf("%d",-999);
        return;
    }
    printf("%d", stack[top]);
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
    realpop();
}
#endif

#if 0
//B
#include<stdio.h>
int queue[5];
int front=0;
int rear=0;

void enqueue(int _v){
    if((rear+1)%5==front){
        front++;
        queue[rear]=_v;
        rear++;
        return;
    }
    queue[rear]=_v;
    rear++;
    return;
}

void dequeue(void){
    if(front==rear)return;
    front++;
    return;
}
void realdequeue(void){
    if(front==rear){
        printf("-999");
        return;
    }
    printf("%d",queue[front]);
    front++;
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
    realdequeue();
    return;
}
#endif

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

void del(int _v){
    NODE* spear=head;
    while(spear==head){
        if(spear->data==_v){
            if(spear->next==0){
                head==0;
                free(spear);
                return;
            }
            head=head->next;
            free(spear);
            spear=head;
            continue;
        }
    }
    while(spear==head->next){
        if(spear->data==_v){
            if(spear->next==0);
        }
    }
}

void show(void){
    NODE* spear=head;
    if(spear==0){
        printf("%d",-999);
        return;
    }
    while(spear!=0){
        printf("%d ", spear->data);
        spear=spear->next;
    }
    return;
}

int main(){
    while(1){
        int v;
        scanf("%d",&v);
        if(v==0)break;
        else push(v);
    }
    while(1){
        int v;
        scanf("%d",&v);
        if(v==-1)break;
        else del(v);
    }
    show();
}

#endif

#if 1

#endif

#if 1

#endif

#if 1

#endif

#if 1

#endif

#if 1

#endif

