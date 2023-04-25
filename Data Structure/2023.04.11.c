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

//p283
// 8.7 트리의 응용 : 수식 트리 처리

//binary search tree delete node
//  terminal node - easy
//      parent node link : null
//  one child node / nonterminal node
//      link parent node and child node
//  two child node / nonterminal node
//      left node's maximum data node be new parent node or
//      right node's minimum data node be new parent node

typedef struct combo{
    NODE* parent;
    NODE* me;
}COMBO;

COMBO find(int _v){
    struct node* spear=root;
    struct node* parent=0;
    while(1){
        if(spear==0){
            COMBO res={0,0};
            return res;
        }
        if(spear->data==_v){
            COMBO res={parent,spear};
            return res;
        }
        if(spear->data>_v){
            parent=spear;
            spear=spear->left;
        }
        else{
            parent=spear;
            spear=spear->right;
        }
    }
}

void delFromBST(int _v){
    COMBO res=find(_v);
    if(res.me==0)return;
    if(res.me->left==0 && res.me->right==0){
        if(res.parent==0){
            root=0;
            free(res.me);
            return;
        }
        if(res.parent->left==res.me)res.parent->left=0;
        else res.parent->right=0;
        free(res.me);
        return;
    }

    if(res.me->left!=0 && res.me->right!=0){
        NODE* spear=res.me->right;
        while(spear->left!=0)spear=spear->left;
        int temp=spear->data;
        delFromBST(temp);
        res.me->data=temp;
        return;
    }

    if(res.me->right==0){
        if(res.parent==0){
            root=res.me->left;
            free(res.me);
            return;
        }
        if(res.parent->left==res.me)res.parent->left=res.me->left;
        else res.parent->right=res.me->left;
        free(res.me);
        return;
    }
    else{
        if(res.parent==0){
            root=res.me->right;
            free(res.me);
            return;
        }
        if(res.parent->left==res.me)res.parent->left=res.me->right;
        else res.parent->right=res.me->right;
        free(res.me);
        return;
    }

}

int main(){
    addToBST(20);
    addToBST(10);
    addToBST(30);
    addToBST(40);
    addToBST(5);

    NODE* spear=root;


}
#endif