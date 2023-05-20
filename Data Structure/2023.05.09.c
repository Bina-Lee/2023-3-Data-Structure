#include<stdio.h>

#if 1
#define NV 5

void addEdge(int graph[][NV],int v1, int v2, int weight){
    graph[v1][v2]=weight;
    graph[v2][v1]=weight;
}

void perform_MST_Prim(int graph[][NV],int sVertex){
    int visited[NV]={0,};
    visited[sVertex]=1;

    for(int i=0;i<NV-1;i++){

        int minDist=99999;
        int visited_vertex=-1;
        int nonvisited_vertex=-1;

        for(int j=0;j<NV;j++){
            if(visited[j]==1){
                for(int k=0;k<NV;k++){
                    if(visited[k]==0){
                        if(graph[j][k]>0 && graph[j][k]<minDist){
                            minDist=graph[j][k];
                            visited_vertex=j;
                            nonvisited_vertex=k;
                        }
                    }
                }
            }
        }
        printf("%d -- %d\n",visited_vertex,nonvisited_vertex);
        visited[nonvisited_vertex]=1;
    }
}

void perform_MST_Kruskal(int graph[][NV]){
    int family[NV]={0,1,2,3,4};
    for(int cnt=0;cnt<NV-1;cnt++){

        int v1,v2;
        int minDist=99999;

        for(int i=0;i<NV;i++){
            for(int j=i+1;j<NV;j++){
                if(graph[i][j]>0 && family[i]!=family[j] && minDist>graph[i][j]){
                    minDist=graph[i][j];
                    v1=i;
                    v2=j;
                }
            }
        }
        printf("%d --- %d\n",v1,v2);
        int old_family=family[v2];
        int new_family=family[v1];
        for(int k=0;k<NV;k++)if(family[k]==old_family)family[k]=new_family;
    }
}

int main(){
    int graph[NV][NV]={0};

    addEdge(graph,0,1,100);
    addEdge(graph,0,2,10);
    addEdge(graph,1,2,40);
    addEdge(graph,1,3,50);
    addEdge(graph,2,3,1);
    addEdge(graph,3,4,10);
    
    perform_MST_Prim(graph,0);

    perform_MST_Kruskal(graph);
}
#endif

#if 01

#include<stdio.h>

#define G_SZ 7

typedef struct{
    int prev;
    int dist;
    int done;
}DijkstraElement;

DijkstraElement dtable[G_SZ];

int find_shortest_path_vertex(DijkstraElement dtable[]){
    int vertex_idx=-1;
    int vertex_dist=9999;

    for(int i=0;i<G_SZ;i++){
        if(dtable[i].done==0 && dtable[i].dist<vertex_dist){
            vertex_idx=i;
            vertex_dist=dtable[i].dist;
        }
    }
    return vertex_idx;
}

void showDTable(DijkstraElement dtable[]){
    for(int i=1;i<G_SZ;i++){
        printf("%5d ",i);
    }
    printf("\n");
    for(int i=1;i<G_SZ;i++){
        printf("%5d ",dtable[i].prev);
    }
    printf(" - prev\n");
    for(int i=1;i<G_SZ;i++){
        printf("%5d ",dtable[i].dist);
    }
    printf(" - dist\n");
    for(int i=1;i<G_SZ;i++){
        printf("%5d ",dtable[i].done);
    }

    printf("\n\n");
}

void showPath(int s,int e,DijkstraElement dtable[]){
    int current=e;
    while(current!=s){
        printf("%d\n",current);
        current=dtable[current].prev;
    }
    printf("%d",s);
}

int main(){
    int graph[G_SZ][G_SZ]={
        {-1,-1,-1,-1,-1,-1,-1},
        {-1,-1, 3,-1,15,-1,-1},
        {-1, 3,-1,30, 2,-1,-1},
        {-1,-1,30,-1,-1, 3, 4},
        {-1,15, 2,-1,-1, 1,-1},
        {-1,-1,-1, 3, 1,-1,20},
        {-1,-1,-1, 4,-1,20,-1}
    };

    DijkstraElement dtable[G_SZ];
    for(int i=0;i<G_SZ;i++){
        dtable[i].prev=-1;
        dtable[i].dist=9999;
        dtable[i].done=0;
    }

    int start_vertex=1;

    for(int i=0;i<G_SZ;i++){
        if(graph[start_vertex][i]!=-1){
            dtable[i].dist=graph[start_vertex][i];
            dtable[i].prev=start_vertex;
        }
    }

    while(1){
        int v=find_shortest_path_vertex(dtable);
        if(v==-1)break;

        dtable[v].done=1;

        for(int i=0;i<G_SZ;i++){
            if(graph[v][i]>-1 && dtable[i].done==0){
                if(dtable[i].dist>dtable[v].dist+graph[v][i]){
                    dtable[i].dist=dtable[v].dist+graph[v][i];
                    dtable[i].prev=v;
                }
            }
        }
    }

    showDTable(dtable);
    printf("-------\n");
    showPath(1,6,dtable);
}

#endif
