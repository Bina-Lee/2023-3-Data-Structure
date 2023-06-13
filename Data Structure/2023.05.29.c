//shell sort

//merge sort

//quick sort

//quick sort
#if 01

#include<stdio.h>

void print(int nums[],int sz){
    for(int i=0;i<sz;i++)printf("%d --> ",nums[i]);
    printf("\n");
    return;
}

void doSwap(int nums[],int idxa, int idxb){
    int temp  =nums[idxa];
    nums[idxa]=nums[idxb];
    nums[idxb]=temp;
}

void quick_sort(int nums[],int start, int end){
    if(start>=end)return;

    int pivot=start;
    int low=start+1;
    int high=end;

    while(low<=high){
        while( nums[low ]<=nums[pivot] && low  <=     end )  low++;
        while( nums[high]>=nums[pivot] && high >= start+1 ) high--;
        if(low<high)doSwap(nums,low,high);
    }
    doSwap(nums,pivot,high);

    print(nums,13);

    quick_sort(nums,start,high-1);
    quick_sort(nums,high+1,end);
}

int main(){
    int nums[]={23,32,34,100,87,76,23,65,2,90,21,1,3};
    int sz=sizeof(nums)/sizeof(nums[0]);

    print(nums,sz);

    quick_sort(nums,0,sz-1);
    
    print(nums,sz);
}

#endif

//shell sort
#if 01

#include<stdio.h>

void shell_sort(int num_array[],int sz){
    for(int gap=sz/2;gap>0;gap/=2){
        for(int i=0;i<gap;i++){
            for(int k=i+gap;k<sz;k+=gap){
                int me=num_array[k];
                int d;
                for(d=k-gap;d>=0 && num_array[d]>me;d-=gap){
                    num_array[d+gap]=num_array[d];
                }
                num_array[d+gap]=me;
            }
        }
    }
}

int main(){
    int nums[]={23,32,34,100,87,65,2,90,21,1,3};
    int sz=sizeof(nums)/sizeof(nums[0]);

    shell_sort(nums,sz);

    for(int i=0;i<sz;i++)printf("%d ",nums[i]);

}

#endif

//merge sort

#if 01

#include<stdio.h>
#include<stdlib.h>

void do_merge(int nums[], int tarry[],int start, int mid, int end){
    int lstart=start;
    int lend=mid;
    int rstart=mid+1;
    int rend=end;
    int i=lstart;
    int j=rstart;
    int t=lstart;

    while(1){
        if(i>lend && j>rend)break;

        if(j>rend){
            tarry[t]=nums[i];
            t++;
            i++;
        }
        else if(i>lend){
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
    for(i=start;i<=end;i++)nums[i]=tarry[i];
}

void merge_sort(int nums[],int start, int end, int tarry[]){
    if(start==end)return;
    
    merge_sort(nums,start,(start+end)/2,tarry);
    merge_sort(nums,(start+end)/2+1,end,tarry);

    do_merge(nums,tarry,start,(start+end)/2,end);
}

int main(){
    int nums[]={23,32,34,100,87,65,2,90,21,1,3};
    int sz=sizeof(nums)/sizeof(nums[0]);

    int *tarry=(int*)malloc(sizeof(int)*sz);

    merge_sort(nums,0,sz-1,tarry);

    for(int i=0;i<sz;i++)printf("%d ",nums[i]);

    free(tarry);
}

#endif