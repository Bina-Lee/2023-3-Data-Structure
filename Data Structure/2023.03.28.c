#if 0

#include<stdio.h>
#include<stdlib.h>//malloc

typedef struct Node{
    int data;
    struct node *next;
}NODE;
NODE* head=0;

void delFromSLL(int _v){
    NODE* spear=findSLL(_v);
    if(spear==0)return;
    if(head==spear){
        head=head->next;
        free(spear);
        return;
    }
    NODE* prev=head;
    while(prev->next!=spear){
        prev=prev->next;
    }
    prev->next=spear->next;
    free(spear);
    return;
}

int main(){

}

#endif

#if 1

//DLL
//Doubly linked List

#include<stdio.h>
#include<stdlib.h>//malloc

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}NODE;

NODE* head=0;

NODE* createNODE(int _v){
    NODE* _new=(NODE*)malloc(sizeof(NODE));
    _new->next=0;
    _new->prev=0;
    _new->data=_v;
    return _new;
}

void addToDLL(int _v){
    NODE* _new=createNODE(_v);
    if(head==0){
        head=_new;
        return;
    }
    NODE* spear=head;
    while(spear->next!=0){
        spear=spear->next;
    }
    spear->next=_new;
    _new->prev=spear;
    return;
}

void displayReverseDLL(void){
    if(head==0)return;

    NODE* spear=head;
    while(spear->next!=0)spear=spear->next;
    while(spear!=0){
        printf("%d\n",spear->data);
        spear=spear->prev;
    }
}

NODE* findNODE(int _v){
    NODE* spear=head;
    while(spear!=0){
        if(spear->data==_v)return spear;
        spear=spear->next;
    }
    return spear;
}

void insertIntoDLL(int _t,int _v){
    NODE* target=findNODE(_t);
    if(target==0)return;
    NODE* _new=createNODE(_v);

    _new->prev=target;
    _new->next=target->next;
    target->next=_new;
    if(_new->next!=0)_new->next->prev=_new;
    return;
}

void delFromDLL(int _t){
    NODE* spear=findNODE(_t);
    if(spear==0)return;

    if(spear==head){
        head=head->next;
        free(spear);
        if(head!=0)head->prev=0;
        return;
    }

    spear->prev->next=spear->next;
    if(spear->next!=0) spear->next->prev=spear->prev;
    free(spear);
    return;
}

int main(){
    addToDLL(10);
    addToDLL(20);
    addToDLL(30);


    //displayDLL();
    
    displayReverseDLL();

    isertIntoDLL(20,90);

    delFromDLL(90);
}

#endif
