#include <stdio.h>
#include <stdbool.h>

int partition(int arr[],int l,int h){
    int pivot=arr[h];
    int j=l-1;
    int i;
    for(i=l;i<h;i++){
        if(arr[i]<=pivot){
            j++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[j+1];
    arr[j+1]=arr[h];
    arr[h]=temp;
    return j+1;
}


void quick_sort(int arr[],int l,int h){
    if(l>=h) return;
    int p=partition(arr,l,h);
    quick_sort(arr,l,p-1);
    quick_sort(arr,p+1,h);
}

int main(){
    int arr[]={8,1,6,2,5,3};
    int p=partition(arr,0,5);
    quick_sort(arr,0,5);
    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
