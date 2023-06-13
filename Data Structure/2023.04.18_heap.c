 #include<stdio.h>
#define HEAP_SZ 100

int heap[HEAP_SZ+1];
int idx=0;

void addToMaxHeap(int _v){
    if(idx==HEAP_SZ){
        printf("heap full\n");
        return;
    }
    idx++;
    heap[idx]=_v;


    int _cur=idx;
    while(_cur>1){
        int _p=_cur/2;
        if(heap[_p]>=heap[_cur])return;
        else{
            int temp=heap[_p];
            heap[_p]=heap[_cur];
            _cur=_p;
        }
    }
}

int delFromMaxHeap(void){
    if(idx==0)return -999;

    int res=heap[1];

    heap[1]=heap[idx];
    idx--;

    int _cur=1;
    while(1){
        int child_idx=2*_cur;
        if(child_idx>idx)break;
        if((child_idx<=idx-1)&&heap[child_idx]<heap[child_idx+1]){
            child_idx=child_idx+1;
        }
        if(heap[_cur]>=heap[child_idx])break;

        else{
            int temp=heap[_cur];
            heap[_cur]=heap[child_idx];
            heap[child_idx]=temp;
            _cur=child_idx;
        }
    }

    return res;
}

int main(){
    addToMaxHeap(20);
    addToMaxHeap(30);
    addToMaxHeap(5);
    addToMaxHeap(40);
    addToMaxHeap(15);

    printf("%d\n",delFromMaxHeap());
}