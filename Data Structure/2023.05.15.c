// //Floyd algorithm

//Topological(topology) sort
//일의 선수관계

//in-degree가 없는 케이스에서 시작
//끝나고 out-degree를 없앰
//in-degree찾아서 없대기 반복
#if 1
#include<stdio.h>

#define SZ 6

void addDEdge(int _sv,int _ev,int g[][SZ]){
    g[_sv][_ev]=1;
    return;
}

void initIndegree(int g[][SZ],int ideg[]){
    for(int i=0;i<SZ;i++){
        for(int j=0;j<SZ;j++){
            if(g[i][j]==1)ideg[j]++;
        }
    }
    return;
}

int findZeroIndegreeVtx(int indeg[]){
    for(int i=0;i<SZ;i++){
        if(indeg[i]==0){
            return i;
        }
    }
    return -1;
}

void topo_sort(int g[][SZ],int indeg[]){
    while(1){
        int v=findZeroIndegreeVtx(indeg);
        if(v==-1)return;
        printf("%d \n",v);
        indeg[v]=-1;
        for(int i=0;i<SZ;i++)if(g[v][i]>0)indeg[i]--;
    }
}

int main(){

    int graph[SZ][SZ]={0,};

    int indegree[SZ]={0,};

    addDEdge(0,1,graph);
    addDEdge(0,2,graph);
    addDEdge(0,3,graph);
    addDEdge(1,4,graph);
    addDEdge(2,4,graph);
    addDEdge(2,5,graph);
    addDEdge(3,5,graph);
    //addDEdge(5,2,graph);

    initIndegree(graph,indegree);

    topo_sort(graph,indegree);
    
}
#endif

#if 01
//Floyd Alggorithm
//모든 점 사이의 최단 경로

#include<stdio.h>

#define SZ 4

int graph[SZ][SZ];
int floyd_graph[SZ][SZ];

void addEdge(int v1,int v2, int w){
    graph[v1][v2]=w;
    graph[v2][v1]=w;
    return;
}

void initFloydGraph(){
    for(int i=0;i<SZ;i++){
        for(int j=0;j<SZ;j++){
            if(i==j)floyd_graph[i][j]=0;
            else if(graph[i][j]>0)floyd_graph[i][j]=graph[i][j];
            else floyd_graph[i][j]=9999;
        }
    }
}

int main(){
    addEdge(0,1,1);
    addEdge(0,3,1);
    addEdge(0,2,1);

    initFloydGraph();

    for(int k=0;k<SZ;k++){
        for(int i=0;i<SZ;i++){
            for(int j=0;j<SZ;j++){
                if(floyd_graph[i][j]>(floyd_graph[i][k]+floyd_graph[k][j])){
                    floyd_graph[i][j]=floyd_graph[i][k]+floyd_graph[k][j];
                }
            }
        }
    }
    for(int i=0;i<SZ;i++){
        for(int j=0;j<SZ;j++){
            printf("%d ",floyd_graph[i][j]);
        }
        printf("\n");
    }
}
#endif