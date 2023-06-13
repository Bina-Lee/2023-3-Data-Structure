#if 0
#include<stdio.h>

int stack

int main(){
    
}
#endif

#if 0
#include <stdio.h>

#define NV 5    // number of vertices <-- 이것은 고정이니 수정 금지

/*
*  아래 2개 함수를 구현하시오. 전역변수 등은 필요에 따라 선언 가능
* 
   1) void addEdge (int graph[][NV], int v1, int v2, int w)
      - vertex v1과 v2 사이에 weight w인 edge를 추가한다.
	  - edge는 undirected이다.
*/
void addEdge(int graph[][NV], int v1, int v2, int w){
    graph[v1][v2]=w;
    graph[v2][v1]=w;
    return;
}
/*
   2) void MST_BY_PRIM(int graph[][NV], int start_vertex)
      
	  - parameter로 주어진 graph에 대한 minimum spanning tree를 start_vertex부터 시작하여 Prim알고리즘으로 구한다.
	  - MST를 구하는 과정에서, 가장 마지막으로 MST에 추가되는 edge (vertex A와 B 사이)에 대해 A B (A < B)를 출력하시오.
	  - 예를 들어, vertex 0과 2 사이의 edge가 MST에 마지막으로 추가되면 0 2(끝에 줄바꿈없음)을 출력한다.
*/
void MST_BY_PRIM(int graph[][NV], int start_vertex){
    int visited[NV]={0,};
    visited[start_vertex]=1;

    int f1;
    int f2;

    for(int i=0;i<NV-1;i++){

        int minDist=9999;
        int visited_vtx=-1;
        int nonv_vtx=-1;

        for(int j=0;j<NV;j++){
            if(visited[j]==1){
                for(int k=0;k<NV;k++){
                    if(visited[k]==0){
                        if(graph[j][k]>0 && graph[j][k]<minDist){
                            minDist=graph[j][k];
                            visited_vtx=j;
                            nonv_vtx=k;

                            f1=visited_vtx;
                            f2=nonv_vtx;
                        }
                    }
                }
            }
        }
        visited[nonv_vtx]=1;
    }
    if(f1>f2){
        int temp=f1;
        f1=f2;
        f2=temp;
    }
    printf("%d %d\n",f1,f2);
}

// ---------------------- 이하 절대 수정 금지 -----------------------------------

int main(void) {

	int v1 = 0;
	int v2 = 0;
	int w = 0;
	int graph[NV][NV] = { 0 };

	while (1) {

		scanf("%d %d %d", &v1, &v2, &w);
		
		if (v1 < 0) {
			break;
		}
		addEdge(graph, v1, v2, w);

	}

	MST_BY_PRIM(graph, -v1);

	return 0;

}
#endif

#if 0 //G

#include <stdio.h>

int cnt_target_movement = 0;

void merge(int nums[], int tarry[],int start, int mid, int end, int target_num){
    int ls=start;
    int le=mid;
    int rs=mid+1;
    int re=end;
    int i=ls;
    int j=rs;
    int t=ls;

    int tar_idx;
    for(int i=0;i<10;i++)if(nums[i]==target_num)tar_idx=i;

    while(1){
        if(i>le && j>re)break;

        if(j>re){
            tarry[t]=nums[i];
            t++;
            i++;
        }
        else if(i>le){
            tarry[t]=nums[j];
            t++;
            j++;
        }
        else{
            if(nums[i]<nums[j]){
                tarry[t]=nums[i];
                t++;
                i++;
            }
            else{
                tarry[t]=nums[j];
                t++;
                j++;
            }
        }
    }
    if(tarry[tar_idx]!=target_num)cnt_target_movement++;
    for(i=start;i<=end;i++)nums[i]=tarry[i];
}

void merge_sort(int nums[], int start, int end, int tarry[], int target_num) {
	/*
	   nums : merge sort 수행할 배열
	   start : 시작 인덱스
	   end : 종료 인덱스
	   tarry : 임시 배열
	   target_num : 자세한 설명은 아래 참조

	   merge sort를 수행하면, target_num이 배열 nums 내에서 자리를 이동하는 회수를
	   전역변수 cnt_target_movement에 저장하시오.

	   예를 들어, 
	   20, 10, 5, 30 = nums, target_num = 10이면
	   10은 2번 움직이므로, merge sort 후에 
	   cnt_target_movement = 2가 저장되어 있어야 한다.

	   10, 20, 30, 40 = nums, target_num = 30인 경우
	   30은 움직이지 않으므로,
	   cnt_target_movement = 0
	
	*/
//merge sort
    if(start==end)return;
    merge_sort(nums,start,(start+end)/2,tarry,target_num);
    merge_sort(nums,(start+end)/2+1,end,tarry,target_num);

    merge(nums,tarry,start,(start+end)/2,end,target_num);
}


//--------------- 이하로는 수정금지 -------------------------------

int main(void) {

	int i;
	int nums[10] = { 0 };
	int tarry[10] = { 0 };
	int target_num = 0;

	for (i = 0; i < 4; i++) {
		scanf("%d", &nums[i]);
	}
	scanf("%d", &target_num);

	merge_sort(nums, 0, 3, tarry, target_num);
	printf("%d", cnt_target_movement);

	return 0;
}
#endif

#if 0 //I

#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
}NODE;

NODE* root = 0;

NODE* newNODE(int _data){
    NODE* _new=(NODE*)malloc(sizeof(NODE));
    _new->data=_data;
    _new->left=0;
    _new->right=0;
    _new->parent=0;
    return _new;
}
void addToBST(int _data){
    NODE* _new=newNODE(_data);
    if(root==0){
        root=_new;
        return;
    }
    NODE* spear=root;
    while(1){
        if(_data<spear->data){
            if(spear->left==0){
                spear->left=_new;
                _new->parent=spear;
                return;
            }
            spear=spear->left;
        }
        else{
            if(spear->right==0){
                spear->right=_new;
                _new->parent=spear;
                return;
            }
            spear=spear->right;
        }
    }
}
void delFromBST(int _data){
    if(root==0)return;
    NODE* spear=root;
    while(spear!=0){
        if(spear->data==_data)break;
        if(_data<spear->data)spear=spear->left;
        else spear=spear->right;
    }
    if(spear==0)return;
    
    if(spear->left==0 && spear->right==0){
        if(root==spear){
            root=0;
            free(spear);
            return;
        }
        NODE* spear2=spear->parent;
        if(spear2->left==spear){
            free(spear);
            spear2->left=0;
            return;
        }
        else{
            free(spear);
            spear2->right=0;
            return;
        }
    }
    if(spear->left!=0 && spear->right!=0){
        NODE* next=spear->right;
        while(next->left!=0)next=next->left;
        int temp=next->data;
        delFromBST(next->data);
        spear->data=temp;
        return;
    }
    if(spear->parent==0){
        if(spear->left!=0){
            spear=spear->left;
            free(root);
            root=spear;
            root->parent=0;
            return;
        }
        else{
            spear=spear->right;
            free(root);
            root=spear;
            root->parent=0;
            return;
        }
    }
    NODE* spear2=spear->parent;
    if(spear2->left==spear){
        if(spear->left!=0)spear2->left=spear->left;
        else              spear2->left=spear->right;
        free(spear);
        return;
    }
    else{
        if(spear->left!=0)spear2->right=spear->left;
        else spear2->right=spear->right;
        free(spear);
        return;
    }
}
//-----------------------------------------------

/*
	void addToBST(int _data)를 완성하시오.
	
	addToBST는 _data를 갖는 노드를 생성하여 
	binary search treee에 추가한다.
	
	root는 BST의 root node를 가리키는 포인터이다.
	
	void delFromBST(int _data)를 완성하시오.
	
	_data를 갖는 노드를 삭제한다.
	_data가 없으면 just return
	쌍자식을 가진 노드를 삭제할 경우, 대체자는 오른쪽에서 올라와야 한다.

*/
//-----------------------------------------------

// 아래로는 수정하지 마시오

int main(void) {

	int d = 0;
	int i;
	
	for (i = 0; i < 6; i++) {
		scanf("%d", &d);
		addToBST(d);
	}
	scanf("%d", &d);
	delFromBST(d);
	
	scanf("%d", &d);
	delFromBST(d);
	
	printf("%d", root->right->data);

	return 0;
}
#endif

#if 0 //D
#include <stdio.h>

#define NV 5    // number of vertices <-- 이것은 고정이니 수정 금지

/*
*  아래 2개 함수를 구현하시오. 전역변수 등은 필요에 따라 선언 가능
* 
   1) void addEdge (int graph[][NV], int v1, int v2, int w)
      - vertex v1과 v2 사이에 weight w인 edge를 추가한다.
	  - edge는 undirected이다.
      */
void addEdge(int graph[][NV],int v1,int v2,int w){
    graph[v1][v2]=w;
    graph[v2][v1]=w;
    return;
}
     /*

   2) void MST_BY_KRUSKAL(int graph[][NV])
      
	  - parameter로 주어진 graph에 대한 minimum spanning tree를 Kruskal알고리즘으로 구한다.
	  - MST를 구하는 과정에서, cycle 형성 때문에 MST에 포함되지 않는 edge (vertex A와 B사이)가 생기면
      - A + B 값을 출력한다. 이러한 edge들이 발생할 때 마다 A+B값을 출력하되, 각 출력들은 줄바꿈으로 구분한다.
	  - 예를 들어, vertex 0과 1사이의 edge, 3과 4사이의 edge가 여기에 해당되면 
      - 1\n7\n (1과 7이 각각 다른 줄에 출력)
       	  

*/
void MST_BY_KRUSKAL(int graph[][NV]){
    int family[NV];
    for(int i=0;i<NV;i++)family[i]=i;
    for(int cnt=0;cnt<NV-1;cnt++){
        int v1,v2;
        int minDist=9999;
        for(int i=0;i<NV;i++){
            for(int j=i+1;j<NV;j++){
                if(graph[i][j]>0 && family[i]!=family[j] 
                   && minDist>graph[i][j]){
                    minDist=graph[i][j];
                    v1=i;
                    v2=j;
                }
            }
        }
        int old=family[v2];
        int new=family[v1];
        for(int k=0;k<NV;k++)if(family[k]==old)family[k]=new;
    }
    for(int i=0;i<NV;i++){
        for(int j=0;j<NV;j++){
            if(i!=j){
                if(family[i]!=family[j])printf("%d\n",i+j);
            }
        }
    }
}

// ---------------------- 이하 절대 수정 금지 -----------------------------------

int main(void) {

	int v1 = 0;
	int v2 = 0;
	int w = 0;
	int graph[NV][NV] = { 0 };

	while (1) {

		scanf("%d %d %d", &v1, &v2, &w);
		
		if (v1 < 0) {
			break;
		}
		addEdge(graph, v1, v2, w);

	}

	MST_BY_KRUSKAL(graph);

	return 0;

}

#endif

#if 0 //L

#include <stdio.h>

/*

크기 _sz인 배열 _data[]를 insertion sort방식으로 정렬할 경우,
지정된 숫자 _num 이 자리 이동한 횟수를 반환하는 함수 do_insertion_sort를 구현하시오.

예를 들어, _num이 최초에 index 4번 위치에 있다가
index 2번, 1번으로 이동하였다면, 이동횟수는 2회이다.
*/
int do_insertion_sort(int _data[], int _sz, int _num){

    int n_idx;
    for(int i=0;i<_sz;i++)if(_data[i]==_num)n_idx=i;
    int cnt=0;

    for(int i=1;i<_sz;i++){
        for(int j=i-1;j>=0;j--){
            if(_data[j]>_data[j+1]){
                int temp=_data[j];
                _data[j]=_data[j+1];
                _data[j+1]=temp;


                if(_data[n_idx]!=_num){
                    cnt++;
                    for(int i=0;i<_sz;i++)if(_data[i]==_num)n_idx=i;
                }
            }
            else break;
        }
    }
    return cnt;
}
/*
_data[] : 정렬해야 할 배열, 양의 정수이며 서로 다른 숫자를 담고 있다.
_sz     : 배열 크기
_num    : 자리 이동 회수를 count할 숫자

*/

// ------------ 이하 수정 금지 -------------------

int main(void) {

	int data[10]= {0};
	int d, i;
	int res;
	for (i = 0; i < 10; i++) {
		scanf("%d", &d);
		data[i] = d;
	}
	scanf("%d", &d);
	
	res = do_insertion_sort(data, 10, d);
	
	printf("%d", res);
	return 0;
}
#endif

#if 0 //B

#include<stdio.h>
int main(){
    int graph[6][6]={0,};
    while(1){
        int s,t;
        scanf("%d %d",&s,&t);
        if(s==-1&&t==-1)break;
        graph[s][t]=1;
    }
    for(int k=0;k<6;k++){
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
                if(i!=0&&j!=0){
                    if(graph[i][k]+graph[k][j]<graph[i][j]){
                        graph[i][j]=graph[i][k]+graph[k][j];
                    }
                }
            }
        }
    }
    
}
#endif

#if 01
#include <stdio.h>
#include <stdlib.h>

#define SZ 10

int myheap[SZ];
int heap_size = 0;

// -----------------------------------------------

/*
	Priority queue를 max heap으로 구현하고자 한다.
	
	아래 Max heap과 관련한 2개 함수들을 구현하시오.

	void enqueue(int _d)
	queue full일 경우, just discard
	
	int dequeue(void)
	queue empty일 경우, -999를 반환
	
*/
void enqueue(int _d){
    if(heap_size==SZ-1)return;
    heap_size++;
    myheap[heap_size]=_d;

    int cur=heap_size;
    while(cur>1){
        int p=cur/2;
        if(myheap[p]>=myheap[cur])return;
        else{
            int temp=myheap[p];
            myheap[p]=myheap[cur];
            cur=p;
        }
    }
}

int dequeue(){
    if(heap_size==0)return -999;
    int res=myheap[1];

    myheap[1]=myheap[heap_size];
    heap_size--;

    int cur=1;
    while(1){
        int child_idx=2*cur;
        if(child_idx>heap_size)break;
        if((child_idx<=heap_size-1)&&myheap[child_idx]<myheap[child_idx+1]){
            child_idx=child_idx+1;
        }
        if(myheap[cur]>=myheap[child_idx])break;

        else{
            int temp=myheap[cur];
            myheap[cur]=myheap[child_idx];
            myheap[child_idx]=temp;
            cur=child_idx;
        }
    }
    return res;
}
// ------------ 이하 수정금지 ---------------------

int main(void) {

	int d;
	int i;

	while (1) {
		scanf("%d", &d);
		if (d < 0) {
			break;
		}
		enqueue(d);
	}
	dequeue();
	printf("%d", dequeue());


	return 0;
}
#endif

#if 01

#endif