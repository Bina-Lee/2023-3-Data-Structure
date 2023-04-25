#if 1

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}NODE;
NODE* root=0;

NODE* newNODE(int _v){
    NODE* _new=(NODE*)malloc(sizeof(NODE));
    _new->data=_v;
    _new->left=0;
    _new->right=0;
    return _new;
}

void addToBST(int _v){
    NODE* _new=newNODE(_v);
    if(root==0){
        root=_new;
        return;
    }
    NODE* spear=root;
    while(1){
        if(spear->data > _v){
            if(spear->left==0){
                spear->left=_new;
                return;
            }
            spear=spear->left;
        }
        else{
            if(spear->right==0){
                spear->right=_new;
                return;
            }
            spear=spear->right;
        }
    }
}

void traversal_inorder(NODE* _cur){
    if(_cur==0)return;
    traversal_inorder(_cur->left);
    printf("%d\n",_cur->data);
    traversal_inorder(_cur->right);
    return;
}

void traversal_preorder(NODE* _cur){
    if(_cur==0)return;
    printf("%d\n",_cur->data);
    traversal_inorder(_cur->left);
    traversal_inorder(_cur->right);
    return;
}

void traversal_postorder(NODE* _cur){
    if(_cur==0)return;
    traversal_inorder(_cur->left);
    traversal_inorder(_cur->right);
    printf("%d\n",_cur->data);
    return;
}

NODE* stack[20];
int top=-1;

int isFull(void){
    return top==19;
}

void push(NODE* _cur){
    if(isFull())return;
    top++;
    stack[top]=_cur;
    return;
}

int isEmpty(void){
    return top==-1;
}

NODE* pop(void){
    if(isEmpty())return 0;
    NODE* result=stack[top];
    top--;
    return result;
}

void nonrecursive_inorder(NODE* _cur){
    // if(_cur==0)return;
    // top++;
    // stack[top]=_cur;
    // while(top!=-1){
    //     if(_cur->left!=0){
    //         push(_cur);
    //         _cur=_cur->left;
    //     }
    //     else{
    //         printf("%d\n",_cur->data);
    //         if(_cur->right!=0){
    //             _cur=_cur->right;
    //         }
    //         else{
    //             _cur=pop();
    //         }
    //     }
    // }
    //-->> 이 방식은 왼쪽을 다시 내려가려고 해서
    //      가장 왼쪽에 있는 노드의 값만 계속 출력함

    while(1){
        while(1){
            if(_cur!=0){
                push(_cur);
                _cur=_cur->left;
            }
            else break;
        }
        _cur=pop();
        if(_cur==0)break;
        printf("%d\n",_cur->data);
        _cur=_cur->right;
    }
}

NODE* queue[20];
int front=0;
int rear=0;

int isFull(void){
    return rear==-19;
}

void enqueue(NODE* _cur){
    if(isFull())return;
    queue[rear]=_cur;
    rear++;
    return;
}

int isEmpty(void){
    return front==rear;
}

NODE* dequeue(void){
    if(isEmpty())return 0;
    NODE* res=queue[front];
    front++;
    return res;
}

void level_order(NODE* _cur){
    if(ifEmpty())return;
    enqueue(_cur);
    while(_cur!=0){
        _cur=dequeue();
        printf("%d\n",_cur->data);
        if(_cur->left!=0)enqueue(_cur->left);
        if(_cur->right!=0)enqueue(_cur->right);
    }
}


int which_is_bigger(int a, int b){
    return (a>b)?a:b;
}
int get_height(NODE* _cur){
    if(_cur==0)return 0;
    return 1+which_is_bigger(get_height(_cur->left),get_height(_cur->right));
}

int get_node_count(NODE* _cur){
    if(_cur==0)return 0;
    return 1+get_node_count(_cur->left)+get_node_count(_cur->right);
}

int get_terminalnode_count(NODE* _cur){
    if(_cur==0)return 0;
    else if(_cur->left==0&&_cur->right==0)return 1;
    return get_terminalnode_count(_cur->left)+get_terminalnode_count(_cur->right);
}   //p289 단말노드 개수 구하기 자식노드가 없는 노드

//p283
// 8.7 트리의 응용 : 수식 트리 처리


int main(){
    addToBST(20);
    addToBST(10);
    addToBST(30);
    addToBST(40);
    addToBST(5);

    NODE* spear=root;

    traversal_inorder(spear);

    printf("\n\n");

    nonrecursive_inorder(spear);

    printf("\n\n");

    level_order(spear);
    
    int height=get_height(spear);  //p289

    int count=get_node_count(spear);

}

//skewed BST : 일자형 BST

//traversal(방문) p267
//이진트리 순회(traversal
//아래 방식을 parent를 방문하는 순서를 나타냄
//1. pre-order traversal(전위 순회)
//2. in-order traversal(중위 순회)
//3. post-order traversal(후위 순회)

//  재귀함수없이 : p277

//레벨순회
//위->아래, 왼쪽->오른쪽
//1 - 2 3 - 4 5 6 - 7 8 9 10
//p 279

#endif