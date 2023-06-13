//2by2 Dijkstra Algorithm
#if 1
#include<stdio.h>
#define mcsz 10
#define mrsz 11
#define gsz mcsz*mrsz

int map[mcsz][mrsz]={
    {0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0},
    {1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0}
};

int graph[gsz][gsz];

void edge(int c1,int r1,int c2,int r2){
    graph[c1*mrsz+r1][c2*mrsz+r2]=1;
    graph[c2*mrsz+r2][c1*mrsz+r1]=1;
    return;
}

void initGraph(){
    for(int i=0;i<mcsz;i++){
        for(int j=0;j<mrsz;j++){
            if(map[i][j])continue;
            if(j+1<mcsz && map[i][j+1]==0)edge(i,j,i,j+1);
            if(i+1<mrsz && map[i+1][j]==0)edge(i,j,i+1,j);
        }
    }
}

typedef struct dij{
    int prev;
    int dist;
    int done;
}DIJ;

DIJ dtable[gsz];

void initDIJ(int start_idx){
    for(int i=0;i<gsz;i++){
        if(i==start_idx){
            dtable[i].prev=start_idx;
            dtable[i].dist=0;
            dtable[i].done=0;
        }
        else if(graph[start_idx][i]>0){
            dtable[i].prev=start_idx;
            dtable[i].dist=graph[start_idx][i];
            dtable[i].done=0;
        }
        else{
            dtable[i].prev=-1;
            dtable[i].dist=9999;
            dtable[i].done=0;
        }
    }
    return;
}

int MinDistVtx(){
    int minDist=9999;
    int minVtx=-1;
    for(int i=0;i<gsz;i++){
        if(dtable[i].done==0 && dtable[i].dist<minDist){
            minDist=dtable[i].dist;
            minVtx=i;
        }
    }
    return minVtx;
}

void doDIJ(int start_idx,int end_idx){
    while(1){
        int res=MinDistVtx();
        dtable[res].done=1;
        if(res==end_idx)break;
        for(int i=0;i<gsz;i++){
            if(dtable[i].done==0 && graph[res][i]>0 
            && dtable[i].dist>dtable[res].dist+graph[res][i]){
                dtable[i].prev=res;
                dtable[i].dist=dtable[res].dist+graph[res][i];
            }
        }
    }
}

void print(){
    for(int i=0;i<mcsz;i++){
        for(int j=0;j<mrsz;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}

int main(){

    int scidx=1;
    int sridx=1;
    int ecidx=9;
    int eridx=9;

    initGraph();
    initDIJ(scidx*mrsz+sridx);
    doDIJ(scidx*mrsz+sridx,ecidx*mrsz+eridx);

    int temp=ecidx*mrsz+eridx;
    while(1){
        map[temp/mrsz][temp%mrsz]=8;
        temp=dtable[temp].prev;
        if(temp==scidx*mrsz+sridx)break;
    }
    map[temp/mrsz][temp%mrsz]=8;
    print();
}
#endif

//dijkstra algorithm
#if 01
#include<stdio.h>
#define gsz 7

typedef struct dij{
    int prev;
    int dist;
    int done;
}DIJ;

//DIJ dtable[gsz];

int minDistVTX(DIJ dtable[]){
    int vtx_idx=-1;
    int vtx_dist=9999;

    for(int i=0;i<gsz;i++){
        if(dtable[i].done==0 && dtable[i].dist<vtx_dist){
            vtx_idx=i;
            vtx_dist=dtable[i].dist;
        }
    }
    return vtx_idx;
}

void printDTable(DIJ dtable[]){
    for(int i=1;i<gsz;i++) printf("%2d ",i);
    printf("\n");
    for(int i=1;i<gsz;i++) printf("%2d ",dtable[i].prev);
    printf(" - prev\n");
    for(int i=1;i<gsz;i++) printf("%2d ",dtable[i].dist);
    printf(" - dist\n");
    for(int i=1;i<gsz;i++) printf("%2d ",dtable[i].done);
    printf("\n\n");
}

void print(int start,int end,DIJ dtable[]){
    int temp=end;
    while(temp!=start){
        printf("%d\n",temp);
        temp=dtable[temp].prev;
    }
    printf("%d",temp);
    return;
}

int main(){
    int graph[gsz][gsz]={
        {-1,-1,-1,-1,-1,-1,-1},
        {-1,-1, 3,-1,15,-1,-1},
        {-1, 3,-1,30, 2,-1,-1},
        {-1,-1,30,-1,-1, 3, 4},
        {-1,15, 2,-1,-1, 1,-1},
        {-1,-1,-1, 3, 1,-1,20},
        {-1,-1,-1, 4,-1,20,-1}
    };

    DIJ dtable[gsz];
    for(int i=0;i<gsz;i++){
        dtable[i].prev=-1;
        dtable[i].dist=9999;
        dtable[i].done=0;
    }

    int start_vertex=1;

    for(int i=0;i<gsz;i++){
        if(graph[start_vertex][i]!=-1){
            dtable[i].dist=graph[start_vertex][i];
            dtable[i].prev=start_vertex;
        }
    }

    while(1){
        int v=minDistVTX(dtable);
        if(v==-1)break;

        dtable[v].done=1;

        for(int i=0;i<gsz;i++){
            if(graph[v][i]>-1 && dtable[i].done==0){
                if(dtable[i].dist>dtable[v].dist+graph[v][i]){
                    dtable[i].dist=dtable[v].dist+graph[v][i];
                    dtable[i].prev=v;
                }
            }
        }
    }

    printDTable(dtable);
    printf("-------\n");
    print(1,6,dtable);
}
#endif