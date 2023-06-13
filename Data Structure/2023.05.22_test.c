#if 01
#include<stdio.h>
#define mrsz 5
#define gsz mrsz*mrsz

/*
char map[mrsz][mrsz]={
    {'.','.','.','.','.'},
    {'.','#','#','#','#'},
    {'.','.','.','.','.'},
    {'#','#','#','#','.'},
    {'.','.','.','.','.'}
};
*/

char map[mrsz][mrsz]={
    {'.','.','.','.','.'},
    {'.','.','.','.','.'},
    {'.','.','.','.','.'},
    {'.','.','.','.','.'},
    {'.','.','.','.','.'}
};

char graph[gsz][gsz];

void edge(int c1,int r1,int c2,int r2){
    graph[c1*mrsz+r1][c2*mrsz+r2]=1;
    graph[c2*mrsz+r2][c1*mrsz+r1]=1;
    return;
}

void initGraph(){
    for(int i=0;i<mrsz;i++){
        for(int j=0;j<mrsz;j++){
            if(map[i][j]=='#')continue;
            if(j+1<mrsz && map[i][j+1]=='.')edge(i,j,i,j+1);
            if(i+1<mrsz && map[i+1][j]=='.')edge(i,j,i+1,j);
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
        printf("%d\n",res);
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
    for(int i=0;i<mrsz;i++){
        for(int j=0;j<mrsz;j++){
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }
    return;
}

int main(){
    /*
    int scidx=0;
    int sridx=4;
    int ecidx=4;
    int eridx=0;
    */

    int scidx=2;
    int sridx=2;
    int ecidx=4;
    int eridx=4;

    initGraph();
    initDIJ(scidx*mrsz+sridx);
    doDIJ(scidx*mrsz+sridx,ecidx*mrsz+eridx);

    int temp=ecidx*mrsz+eridx;
    while(1){
        map[temp/mrsz][temp%mrsz]='*';
        temp=dtable[temp].prev;
        if(temp==scidx*mrsz+sridx)break;
    }
    map[temp/mrsz][temp%mrsz]='*';
    print();
}
#endif