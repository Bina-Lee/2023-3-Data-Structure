#if 0
//1625
#include<stdio.h>
int stack[20];
int top=-1;

void pop(void){
    if(top==-1)return;
    top--;
    return;
}
void push(int _v){
    if(top==19)return;
    top++;
    stack[top]=_v;
    return;
}

void print(void){
    if(top==-1){
        printf("-999");
        return;
    }
    printf("%d", stack[top]+stack[0]);
    return;
}

int main(){
    while(1){
        int v;
        scanf("%d", &v);
        if(v==0)break;
        if(v==-1)pop();
        else push(v);
    }
    print();
}
#endif

#if 0
#include<stdio.h>
int queue[20];
int front=0;
int rear=0;

void enqueue(int _v){
    if((rear+1)%20==front)return;
    queue[rear]=_v;
    rear=(rear+1)%20;
    return;
}

void dequeue(void){
    if(rear==front)return;
    int res=queue[front];
    front=(front+1)%20;
}

void print(void){
    if(rear==front){
        printf("-999");
        return;
    }
    printf("%d", queue[front]+queue[(rear+19)%20]);
}

int main(){
    while(1){
        int v;
        scanf("%d", &v);
        if(v==0)break;
        if(v==-1)dequeue();
        else enqueue(v);
    }
    print();
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
    if(_v%2==0){
        NODE* spear=head;
        while(spear->next!=0)spear=spear->next;
        spear->next=_new;
        return;
    }
    if(head->data%2==0){
        NODE* spear=head;
        _new->next=spear;
        head=_new;
        return;
    }
    NODE* spear=head;
    while(spear->next->data%2!=0)spear=spear->next;
    NODE* spear2=spear->next;
    spear->next=_new;
    _new->next=spear2;
    return;
}

void print(void){
    if(head==0)return;
    NODE* spear=head;
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
    print();
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

NODE* newNODE(int _v){
    NODE* _new=(NODE*)malloc(sizeof(NODE));
    _new->data=_v;
    _new->next=0;
    _new->prev=0;
    return _new;
}

void push(int _v){
    NODE* _new=newNODE(_v);
    if(head==0){
        head=_new;
        return;
    }
    if(_new->data%2==0){
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
    while(spear->next->data%2!=0)spear=spear->next;
    _new->next=spear->next;
    _new->next->prev=_new;
    spear->next=_new;
    _new->prev=spear;
    return;
}

void print(void){
    NODE* spear=head;
    while(spear->next!=0)spear=spear->next;
    while(spear!=0){
        printf("%d ", spear->data);
        spear=spear->prev;
    }
    return;
}

int main(){
    while(1){
        int v;
        scanf("%d", &v);
        if(v==0)break;
        else push(v);
    }
    print();
}
#endif

#if 0
//문제C
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

void print(void);

void del(int _v){
    if(head==0)return;
    while(1){
        NODE* spear=head;
        if(head->data==_v){
            if(head->next==0){
                free(head);
                head=0;
                return;
            }
            spear=spear->next;
            free(head);
            head=spear;
            continue;
        }
        else if(head->next->data==_v){
            if(head->next->next==0){
                if(head->next->data==_v){
                    free(head->next);
                    head->next=0;
                    return;
                }
                return;
            }
        }

        int check=0;
        while(spear->next->next!=0){
            if(spear->next->data==_v){
                NODE* spear2=spear->next;
                spear->next=spear->next->next;
                free(spear2);
                check=1;
                break;
            }
            spear=spear->next;
        }
        if(check==1)continue;

        if(spear->next->data==_v){
            free(spear->next);
            spear->next=0;
        }
        return;
    }
}

void print(void){
    if(head==0){
        printf("-999");
        return;
    }
    NODE* spear=head;
    while(spear!=0){
        printf("%d ", spear->data);
        spear=spear->next;
    }
}

int main(){
    while(1){
        int v;
        scanf("%d", &v);
        if(v==0)break;
        else push(v);
    }
    while(1){
        int v;
        scanf("%d", &v);
        if(v==-1)break;
        else del(v);
    }
    print();
}
#endif

#if 0
//문제D
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

void push(int _v){
    NODE* _new=newNODE(_v);
    if(head==0){
        head=_new;
        return;
    }
    NODE* spear=head;
    while(spear->next!=0)spear=spear->next;
    spear->next=_new;
    _new->prev=spear;
    return;
}

void del(int _v){
    while(1){
        if(head==0)return;
        if(head->data==_v){
            if(head->next==0){
                free(head);
                head=0;
                return;
            }
            NODE* spear=head;
            head=head->next;
            head->prev=0;
            free(spear);
            continue;
        }
        if(head->next->data==_v){
            if(head->next->next==0){
                free(head->next);
                head->next=0;
                return;
            }
            NODE* spear=head->next;
            head->next=head->next->next;
            head->next->prev=head;
            free(spear);
            continue;
        }

        NODE* spear=head;
        int check=0;
        while(spear->next->next!=0){
            if(spear->next->data==_v){
                NODE* spear2=spear->next;
                spear->next=spear->next->next;
                spear->next->prev=spear;
                check=1;
                free(spear2);
                break;
            }
            spear=spear->next;
        }
        if(check)continue;

        if(spear->next->data==_v){
            free(spear->next);
            spear->next=0;
            return;
        }
        return;
    }
}

void print(void){
    if(head==0){
        printf("-999");
        return;
    }
    NODE* spear=head;
    while(spear->next!=0)spear=spear->next;
    while(spear!=0){
        printf("%d ", spear->data);
        spear=spear->prev;
    }
    return;
}

int main(){
    while(1){
        int v;
        scanf("%d", &v);
        if(v==0)break;
        else push(v);
    }
    while(1){
        int v;
        scanf("%d", &v);
        if(v==-1)break;
        else del(v);
    }
    print();
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
}NODE;
NODE* root=0;

NODE* newNODE(int _v){
    NODE* _new=(NODE*)malloc(sizeof(NODE));
    _new->data=_v;
    _new->left=0;
    _new->right=0;
    _new->parent=0;
    return _new;
}

void push(int _v){
    NODE* _new=newNODE(_v);
    if(root==0){
        root=_new;
        return;
    }
    NODE* spear=root;
    while(1){
        if(_v < spear->data){
            if(spear->left==0){
                spear->left=_new;
                _new->parent=spear;
                return;
            }
            spear=spear->left;
        }
        else{
            if(spear->right==0){
                spear->right=_new;
                _new->parent=spear;
                return;
            }
            spear=spear->right;
        }
    }
}

void del(int _v){
    if(root==0)return;
    NODE* spear=root;
    while(spear!=0){
        if(spear->data==_v)break;
        if(_v < spear->data)spear=spear->left;
        else                spear=spear->right;
    }
    if(spear==0)return;
    
    if(spear->left==0 && spear->right==0){
        if(root==spear){
            root=0;
            free(spear);
            return;
        }
        NODE* spear2=spear->parent;
        if(spear2->left==spear){
            free(spear);
            spear2->left=0;
            return;
        }
        else{
            free(spear);
            spear2->right=0;
            return;
        }
    }
    if(spear->left!=0 && spear->right!=0){
        NODE* next=spear->left;
        while(next->right!=0)next=next->right;
        int temp=next->data;
        del(next->data);
        spear->data=temp;
        return;
    }
    if(spear->parent==0){
        if(spear->left!=0){
            spear=spear->left;
            free(root);
            root=spear;
            root->parent=0;
            return;
        }
        else{
            spear=spear->right;
            free(root);
            root=spear;
            root->parent=0;
            return;
        }
    }
    NODE* spear2=spear->parent;
    if(spear2->left==spear){
        if(spear->left!=0)spear2->left=spear->left;
        else              spear2->left=spear->right;
        free(spear);
        return;
    }
    else{
        if(spear->left!=0)spear2->right=spear->left;
        else              spear2->right=spear->right;
        free(spear);
        return;
    }
}

void inorder(NODE* spear){
    if(spear==0)return;
    inorder(spear->left);
    printf("%d ",spear->data);
    inorder(spear->right);
    return;
}

int countterminal(NODE* spear){
    if(spear==0)return 0;
    if(spear->left==0 && spear->right==0)return 1;
    return countterminal(spear->left)+countterminal(spear->right);
}

int main(){
    while(1){
        int v;
        scanf("%d",&v);
        if(v==0)break;
        push(v);
    }
    int v;
    while(1){
        scanf("%d",&v);
        if(v==-1)break;
        if(v==-2)break;
        del(v);
    }
    if(v==-1){
        inorder(root);
        return 0;
    }
    int count=countterminal(root);
    printf("%d",count);
    return 0;
}
#endif

#if 01
//2-A
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char str[10];
    struct node* left;
    struct node* right;
    struct node* parent;
}NODE;
NODE* root=0;

NODE* newNODE(char* _str){
    NODE* _new=(NODE*)malloc(sizeof(NODE));
    strcpy(_new->str,_str);
    _new->left=0;
    _new->right=0;
    _new->parent=0;
    return _new;
}

void push(char* _str){
    NODE* _new=newNODE(_str);
    if(root==0){
        root=_new;
        return;
    }
    NODE* spear=root;
    while(1){
        if(strcmp(_new->str,spear->str)<0){
            if(spear->left==0){
                spear->left=_new;
                _new->parent=spear;
                return;
            }
            spear=spear->left;
        }
        else{
            if(spear->right==0){
                spear->right=_new;
                _new->parent=spear;
                return;
            }
            spear=spear->right;
        }
    }
}

int main(){
    while(1){
        char v[10];
        scanf("%s",v);
        if(strcmp("end",v)==0)break;
        else push(v);
    }
    NODE* spear=root;
    while(1){
        int v;
        scanf("%d", &v);
        if(v==-1)break;
        if(v==0)spear=spear->left;
        else if(v==1)spear=spear->right;
        if(spear==0)break;
    }
    if(spear==0){
        printf("INVALID");
        return 0;
    }
    printf("%s",spear->str);
    return 0;
}
#endif
