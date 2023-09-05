#include <stdio.h>

void bubble_sort(int arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int arr[]={8,1,6,2,5,3};
    bubble_sort(arr,6);
    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}