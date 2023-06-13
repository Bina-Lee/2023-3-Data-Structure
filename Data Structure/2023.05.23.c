//bubble sort
//O(n^2)
#if 01
#include<stdio.h>
int main(){
    int arr[5]={5,4,3,2,1};
    for(int i=0;i<4;i++){
        for(int j=1;j<5-i;j++){
            if(arr[j-1]>arr[j]){
                int temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}
#endif

//selection sort
#if 01
#include<stdio.h>
int main(){
    int arr[5]={5,4,3,2,1};
    for(int i=0;i<4;i++){
        int min_idx=i;
        for(int j=i;j<5;j++){
            if(arr[min_idx]>arr[j]){
                min_idx=j;
            }
        }
        int temp=arr[min_idx];
        arr[min_idx]=arr[i];
        arr[i]=temp;
    }
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}
#endif

//insertion sort
#if 01
#include<stdio.h>
int main(){
    int arr[5]={5,4,3,2,1};
    for(int i=1;i<5;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            else break;
        }
    }
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}
#endif

//shell sort

//merge sort

//quick sort
