//DFS 깊이우선탐색
//BFS 너비우선탐색
    //first search

#include<stdio.h>
#include<stdlib.h>

#define NUM_VTX 6

typedef struct node{
    int vtx;
    struct node* next;
}NODE;

NODE* graph[NUM_VTX];

NODE* newNODE(int v2){
    NODE* _new=(NODE*)malloc(sizeof(NODE));
    _new->vtx=v2;
    _new->next=0;
    return _new;
}

void _addEdge(int v1, int v2){
    NODE* _new=newNODE(v2);
    if(graph[v1]==0){
        graph[v1]=_new;
        return;
    }
    NODE* spear=graph[v1];
    while(spear->next!=0)spear=spear->next;
    spear->next=_new;
    return;
}

void addEdge(int v1, int v2){
    _addEdge(v1,v2);
    _addEdge(v2,v1);
    return;
}


int stack_DFS[NUM_VTX];
int top=-1;

void push(int _v){
    if(top==NUM_VTX-1)return;
    top++;
    stack_DFS[top]=_v;
    return;
}

int pop(void){
    if(top==-1)return -999;
    int res=stack_DFS[top];
    top--;
    return res;
}

int checkDuplication(int _v){
    if(top==-1)return 0;
    for(int i=0;i<=top;i++)if(stack_DFS[i]==_v)return 1;
    return 0;
}

void do_DFS(int _v){
    int visited[NUM_VTX]={0,};
    push(_v);
    while(top!=-1){
        int cur=pop();
        if(cur==-999)break;
        if(visited[cur]==0){
            visited[cur]=1;
            printf("%d vertex visited\n",cur);
        }
        NODE* _cur=graph[cur];
        while(_cur!=0){
            if(visited[_cur->vtx]==0)push(_cur->vtx);
            _cur=_cur->next;
        }
    }
}


int queue_BFS[NUM_VTX];
int front=0;
int rear=0;

void enqueue(int _v){
    if(front==(rear+1)%NUM_VTX)return;
    queue_BFS[rear]=_v;
    rear=(rear+1)%NUM_VTX;
    return;
}

int dequeue(void){
    if(front==rear)return -999;
    int res=queue_BFS[front];
    front=(front+1)%NUM_VTX;
    return res;
}

void do_BFS(int _v){
    int visited[NUM_VTX]={0,};
    enqueue(_v);
    while(1){
        int m=dequeue();
        if(m==-999)break;
        if(visited[m]!=1){
            visited[m]=1;
            printf("%d vertex visited\n",m);
        }
        NODE* _cur=graph[m];
        while(_cur!=0){
            if(visited[_cur->vtx]==0)enqueue(_cur->vtx);
            _cur=_cur->next;
        }
    }
}

int main(){
    addEdge(0,3);
    addEdge(0,1);
    addEdge(0,2);
    addEdge(2,3);
    addEdge(1,4);
    addEdge(2,4);
    addEdge(4,5);
    addEdge(3,5);

    do_DFS(0);
    printf("\n");
    do_BFS(0);

}