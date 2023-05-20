//graph
// chap10, 11

//무방향 그래프 undirected graph
//(A,B)

//방향 그래프 directed graph
//<A,B>

//가중치 그래프 weighted graph

#include<stdio.h>
#include<stdlib.h>

#define NUM_VTX 4

typedef struct node{
    int vtx;
    struct node* next;
}NODE;

NODE* graph[NUM_VTX];

// int graph[NUM_VTX][NUM_VTX];

// void addEdge(int v1, int v2){
//     graph[v1][v2]=1;
//     graph[v2][v1]=1;
//     return;
// }

// int isThereEdge(int v1, int v2){
//     return graph[v1][v2];
// }

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

int isThereEdge(int v1, int v2){
    NODE* spear=graph[v1];
    while(spear!=0){
        if(spear->vtx==v2)return 1;
        spear=spear->next;
    }
    return 0;
}

int main(){
    addEdge(0,3);
    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,2);

    printf("%d",isThereEdge(1,2));
}