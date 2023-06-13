#if 0
#include<stdio.h>
int stack[5];
int top=-1;

void push(int _v){
    if(top==4)return;
    top++;
    stack[top]=_v;
    return;
}

int pop(void){
    if(top==-1)return -999;
    int res=stack[top];
    top--;
    return res;
}

void print(void){
    if(top==-1){
        printf("-999");
        return;
    }
    for(int i=0;i<=top;i++){
        printf("%d ", stack[i]);
    }
    return;
}

int main(){
    while(1){
        int v;
        scanf("%d", &v);
        if(v==-1)pop();
        else if(v==0)break;
        else push(v);
    }
    print();
}
#endif

#if 0
#include<stdio.h>
int queue[6];
int front =0;
int rear=0;

void enqueue(int _v){
    if((rear+1)%5==front)return;
    queue[rear]=_v;
    rear=(rear+1)%5;
    return;
}
int dequeue(void){
    if(front==rear)return -999;
    int res=queue[front];
    front=(front+1)%5;
    return res;
}

void print(void){
    if(front==rear){
        printf("-999");
        return;
    }
    while((rear)%5!=front){
        printf("%d ", queue[front]);
        front=(front+1)%5;
    }
    return;
}

int main(){
    while(1){
        int v;
        scanf("%d", &v);
        if(v==-1)dequeue();
        else if(v==0)break;
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
    NODE* spear=head;
    while(spear->next!=0)spear=spear->next;
    spear->next=_new;
    return;
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
    return;
}

void del(int _v){
    while(1){
        if(head->data==_v){
            if(head->next==0){
                free(head);
                head=0;
                return;
            }
            NODE* spear=head;
            head=head->next;
            free(spear);
            continue;
        }
        if(head->next->data==_v){
            if(head->next->next==0){
                free(head->next);
                head->next=0;
                return;
            }
            NODE* spear=head->next->next;
            free(head->next);
            head->next=spear;
            continue;
        }
        NODE* spear=head;
        int check=0;
        while(spear->next->next!=0){
            if(spear->next->data==_v){
                NODE* spear2=spear->next->next;
                free(spear->next);
                spear->next=spear2;
                check=1;
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

void add_b_next_a(int a, int b){
    if(head==0)return;
    NODE* spear=head;
    while(spear->next!=0){
        if(spear->data==a){
            NODE* _new=newNODE(b);
            NODE* spear2=spear->next;
            spear->next=_new;
            _new->next=spear2;
        }
        spear=spear->next;
    }
    if(spear->data==a){
        NODE* _new=newNODE(b);
        spear->next=_new;
    }
    return;
}

void add_b_before_a(int a,int b){
    if(head==0)return;
    if(head->data==a){
        NODE* _new=newNODE(b);
        _new->next=head;
        head=_new;
    }
    NODE* spear=head->next;
    while(spear->next!=0){
        if(spear->next->data==a){
            NODE* _new=newNODE(b);
            NODE* spear2=spear->next;
            spear->next=_new;
            _new->next=spear2;
            spear=spear->next;
        }
        spear=spear->next;
    }
    return;
}

int main(){
    int v;
    while(1){
        scanf("%d", &v);
        if(v>0)push(v);
        else if(v==-1){
            scanf("%d", &v);
            del(v);
        }
        else if(v==-2){
            int a,b;
            scanf("%d %d", &a, &b);
            add_b_next_a(a,b);
        }
        else if(v==-3){
            int a,b;
            scanf("%d %d",&a, &b);
            add_b_before_a(a,b);
        }
        else if(v==0)break;
    }
    print();
}
#endif

#if 01
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
        NODE* next=spear->right;
        while(next->left!=0)next=next->left;
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

void delroot(void){
    if(root==0)return;
    del(root->data);
    return;
}
void delmax(void){
    if(root==0)return;
    NODE* spear=root;
    while(spear->right!=0)spear=spear->right;
    del(spear->data);
    return;
}
void delmin(void){
    if(root==0)return;
    NODE* spear=root;
    while(spear->left!=0)spear=spear->left;
    del(spear->data);
    return;
}

NODE* queue[100];
int front=0;
int rear=0;

void enqueue(NODE* _cur){
    if((rear+1)%100==front)return;
    queue[rear]=_cur;
    rear=(rear+1)%100;
    return;
}

NODE* dequeue(void){
    if(front==rear)return 0;
    NODE* res=queue[front];
    front=(front+1)%100;
    return res;
}

void level_order(NODE* _cur){
    if(_cur==0){
        printf("-999");
        return;
    }
    if(front==(rear+1)%100)return;
    enqueue(_cur);
    while(_cur!=0){
        _cur=dequeue();
        if(_cur==0)break;
        printf("%d ",_cur->data);
        if(_cur->left!=0)enqueue(_cur->left);
        if(_cur->right!=0)enqueue(_cur->right);
    }
}

int main(){
    while(1){
        int v;
        scanf("%d", &v);
        if(v==0)break;
        else if(v==-1){
            scanf("%d", &v);
            del(v);
        }
        else if(v==-2)delroot();
        else if(v==-3)delmax();
        else if(v==-4)delmin();
        else push(v);
    }
    level_order(root);
}
#endif

#if 0
#include<stdio.h>

int heap[11];
int idx=0;

void add(int _v){
    if(idx==10){
        return;
    }
    idx++;
    heap[idx]=_v;

    int cur=idx;
    while(cur>1){
        int p=cur/2;
        if(heap[p]>=heap[cur])return;
        int temp=heap[p];
        heap[p]=heap[cur];
        heap[cur]=temp;
        cur=p;
    }
}

int del(void){
    if(idx==0)return -999;
    int res=heap[1];

    heap[1]=heap[idx];
    idx--;

    int cur=1;
    while(1){
        int child_idx=2*cur;
        if(child_idx>idx)break;
        if((child_idx<=idx-1)&&heap[child_idx]<heap[child_idx+1])child_idx++;
        if(heap[cur]>=heap[child_idx])break;            
        int temp=heap[cur];
        heap[cur]=heap[child_idx];
        heap[child_idx]=temp;
        cur=child_idx;
    }
    return res;
}

void print(void){
    if(idx==0){
        printf("-999");
        return;
    }
    while(idx!=0){
        int res=del();
        printf("%d ", res);
    }
    return;
}

int main(){
    while(1){
        int v;
        scanf("%d", &v);
        if(v==0)break;
        if(v>0)add(v);
        else del();
    }
    print();
}
#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

