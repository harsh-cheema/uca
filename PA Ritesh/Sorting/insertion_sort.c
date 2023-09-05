#include <stdio.h>

void insertion_sort(int arr[],int n){
    int i;
    for(i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
    int arr[]={8,1,6,2,5,3};
    insertion_sort(arr,6);
    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
