//chap8 tree p254

//계층적 구조
//Tree는 계층적 구조를 표현하는 대표적 데이터 구조

//여기서도 NODE를 사용함

//제일 위의 친구를 Root NODE 라고 함
//아래에 있는 것들을 sub tree 서브트리 라고 함

//parent node <-> child node
//sibling node(형제자매)

//terminal node(종말, 단말노드)
//non-terminal node(비단말 노드)
//child node의 유무

//degree of a node(차수) p.256
//노드의 자식노드 개수(직계하위만)

//degree of a tree
//max(degree of a node)

//height of a tree p256
//max(level)
//level은 root가 1 아래로 하나씩 증가

//forest
//set of trees

//p257 트리의 종류
//degree of a tree==2 : binary tree 이진 트리

//p258 이진트리 정의
//left subtree / right subtree

//node와 node를 잇는 선 : edge 간선

//p259 이진트리의 성질
//1. n개의 노드를 가진 이진트리에서 edge의 개수는 n-1
//  트리에서 모든 노드는 부모로 가는 edge를 가짐(root node 제외)
//2. p.260
//  높이가 h인 이진 트리에는
//  노드 최소 h개, 최대 2^h-1개 있다
//3. p260
//  n개의 노드를 가지는 이진트리의 높이는
//  최대 n, 최소 log_2(n+1)

//p261 이진트리의 분류
//1. full binary tree
//  모든 층에 들어갈수있는만큼 노드가 있음
//2. complete binary tree
//  자식노드가 0개아니면 2개로 모두 차있음
//  위->아래, 좌->우 로갈때 다 차있는 경우

//binary search tree
//BST
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

void showAll(void){
    NODE* spear=root;

}

int main(){
    addToBST(20);
    addToBST(10);
    addToBST(30);
    addToBST(40);
    addToBST(5);
}

#endif

//skewed BST : 일자형 BST

//traversal(방문) p267
//이진트리 순회(traversal
//아래 방식을 parent를 방문하는 순서를 나타냄
//1. pre-order traversal(전위 순회)
//2. in-order traversal(중위 순회)
//3. post-order traversal(후위 순회)