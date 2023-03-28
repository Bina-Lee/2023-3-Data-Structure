#if 1

#include<stdio.h>
#include<stdlib.h>//malloc

typedef struct Node{
    int data;
    struct Node *next;
}NODE;
NODE* head=0;

//Singly Linked List : SLL

void addToSLL(int _v){
    //_v valude save in memory in node
    NODE* _new=(NODE*)malloc(sizeof(NODE));
    //malloc의 반환값은 void*이기 때문에 캐스팅 필요함
    //_new는 새로 할당받은 node구조체의 주소를 가리키고 있다
    //_new를 잃어버리면 할당받은 공간을 다시 찾아갈 방법이 없음
    _new->data=_v;
    _new->next=0;//신규 노드는 뒤에 오는 노드가 없으므로 0으로 초기화
    //_new를 기존 SLL에 추가
    //  1. 빈 SLL일 경우
    if(head==0){
        head=_new;
        return;
    }
    //  2. 아닌 경우
    //      2.1 기존 SLL에서 맨 끝의 노드의 주소를 알아냄
    NODE* temp=head;
    while(temp->next!=0)temp=temp->next;
    //      2.2 맨끝 노드의 next에 새로운 노드의 주소를 집어넣는다
    temp->next=_new;
    return;
}

void displaySLL(void){
    NODE* temp=head;

    while(1){
        if(temp==0)break;
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

int countSLL(void){
    NODE* temp=head;
    int cnt=0;
    while(temp!=0){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

NODE* findSLL(int _v){
    NODE* temp=head;
    while(temp!=0){
        if(temp->data==_v)return temp;
        temp=temp->next;
    }
    //없으면 0, 있으면 노드의 주소 반환
}

void destroySLL(void){
    NODE* spear=head;
    while(head!=0){
        head=head->next;
        free(spear);
        spear=head;
    }
    return;
}

void addToFront(int _v){
    NODE* _new=(NODE*)malloc(sizeof(NODE));
    _new->data=_v;
    _new->next=0;
    if(head==0){
        head=_new;
        return;
    }
    _new->next=head;    //순서 중요
    head=_new;          //뭘 먼저 할건지...
    return;
}

int delFromFront(void){
    if(head==0)return -999; //SLL is empty code
    NODE* spear=head;
    head=head->next;
    int res=spear->data;
    free(spear);
    return res;
}

int delFromLast(void){
    if(head==0)return -999;
    if(head->next==0){
        //single node
        int res=head->data;
        free(head);
        return res;
    }
    NODE* spear=head;
    while( (spear->next)->next!=0) spear=spear->next;
    int res= (spear->next)->data;
    free(spear->next);
    spear->next=0;
}

//_findv값을 가진 노드를 찾아서 그 뒤에 _addv를 가진 새로운 노드를 추가
void insertInto(int _findv, int _addv){
    NODE* target=findSLL(_findv);
    if(target==0)return;
    NODE* _new=(NODE*)malloc(sizeof(NODE));
    _new->data=_addv;
    _new->next=0;

    _new->next=target->next;
    target->next=_new;
    return;
}

int main(){
    
    addToSLL(10);
    addToSLL(20);
    addToSLL(20);

    displaySLL();

    //addToFront();
    addToFront(90);

    //delFromLast();
    delFromLast();

    //delFromFront();
    delFromFront();

    //insertInto();   //특정노드를 찾아서 그 뒤에 추가

    //  delFromSLL();   //특정 노드를 찾아서 제거

    //destroySLL();   //SLL노드를 모두 제거
    destroySLL();
    if(head!=0)printf("제대로 destroy하지 못함");

    // countSLL(); //노드 개수를 반환
    printf("%d\n",countSLL());

    //findSLL();  //특정 노드 위치를 검색
    printf("%x\n",findSLL(20));//해당 값을 가진 노드의 주소를 출력
    NODE* temp=findSLL(20);
    printf("%d\n",temp->data);//must be 20

}

#endif