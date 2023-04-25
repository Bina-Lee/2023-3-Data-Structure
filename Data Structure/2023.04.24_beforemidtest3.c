#if 1
#include<stdio.h>
int heap[101];
int idx=0;

void push(int _v){
    if(idx==100)return;
    idx++;
    heap[idx]=_v;
    int cur=idx;
    
    while(cur>1){
        if(heap[cur/2]>heap[cur])return;
        int temp=heap[cur/2];
        heap[cur/2]=heap[cur];
        heap[cur]=temp;
        cur=cur/2;
    }
}

int pop(int _v){
    if(idx==0)return -999;
    int res=heap[1];
    heap[1]=heap[idx];
    idx--;

    int cur=1;
    while(1){
        int child=cur*2;
        if(cur*2>idx)break;
        if(heap[child]<heap[child+1]&&(child+1<=idx))child++;
        if(heap[cur]>heap[cur*2])break;
        int temp=heap[cur];
        heap[cur]=heap[child];
        heap[child]=temp;
        cur=child;
    }

    return res;
}

int main(){

}
#endif

#if 1
#include<stdio.h>
int heap[11];
int idx=0;

void push(int _v){
    if(idx==10)return;
    idx++;
    heap[idx]=_v;
    int cur=idx;
    while(cur>1){
        if(heap[cur]>heap[cur/2])return;
        int temp=heap[cur];
        heap[cur]=heap[cur/2];
        heap[cur/2]=temp;
        cur=cur/2;
    }
}

int pop(void){
    if(idx==0)return -999;
    int res=heap[1];
    heap[1]=heap[idx];
    idx--;

    int cur=1;
    while(1){
        int child=cur*2;
        if(child>idx)break;
        if(heap[child]>heap[child+1]&&(heap[child]>heap[child+1]))child++;
        if(heap[child]>heap[cur])break;
        int temp=heap[child];
        heap[child]=heap[cur];
        heap[cur]=temp;
    }
}

void print(int _v){
    if(_v==-1){
        int res=pop();
        printf("%d", res);
        return;
    }
    int max=heap[1];
    for(int i=2;i<=idx;i++){
        if(max<heap[i])max=heap[i];
    }
    printf("%d", max);
}

int main(){
    int v;
    while(1){
        scanf("%d", &v);
        if(v<0)break;
        push(v);
    }
    print(v);
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
        scanf("%d", &v);
        if(v==0)break;
        push(v);
    }
    while(1){
        int v;
        scanf("%d", &v);
        if(v==-1)break;
        del(v);
    }
    print();
    return 0;
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
        if(_v<spear->data){
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
    NODE* spear=root;
    while(spear!=0){
        if(spear->data==_v)break;
        if(_v<spear->data)spear=spear->left;
        else spear=spear->right;
    }

    if(spear==0)return;
    
    if(spear->left==0 && spear->right==0){
        if(spear==root){
            free(spear);
            root=0;
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
        NODE* spear2=spear->left;
        while(spear2->right!=0)spear2=spear2->right;
        int temp=spear2->data;
        del(spear2->data);
        spear->data=temp;
        return;
    }

    if(spear==root){
        if(root->left!=0){
            spear=root->left;
            free(root);
            root=spear;
            root->parent=0;
            return;
        }
        else{
            spear=root->right;
            free(root);
            root=spear;
            root->parent=0;
            return;
        }
    }
    NODE* spear2=spear->parent;
    if(spear->left!=0){
        if(spear2->left==spear){
            spear2->left=spear->left;
            spear2->left->parent=spear2;
            free(spear);
            return;
        }
        else{
            spear2->right=spear->left;
            spear2->right->parent=spear2;
            free(spear);
            return;
        }
    }
    else{
        if(spear2->left==spear){
            spear2->left=spear->right;
            spear2->left->parent=spear2;
            free(spear);
            return;
        }
        else{
            spear2->right=spear->right;
            spear2->right->parent=spear2;
            free(spear);
            return;
        }
    }
}

void inorder(NODE* spear){
    if(spear==0)return;
    inorder(spear->left);
    printf("%d ", spear->data);
    inorder(spear->right);
}

int main(){
    int v;
    while(1){
        scanf("%d", &v);
        if(v==0)break;
        push(v);
    }
    while(1){
        scanf("%d", &v);
        if(v<0)break;
        del(v);
    }
    if(v==-1)inorder(root);
}
#endif