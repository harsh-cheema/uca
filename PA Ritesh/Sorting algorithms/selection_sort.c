#include <stdio.h>

void selection_sort(int arr[],int n){
    int i,j;
    for(i=0;i<n;i++){
        int min_ind=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min_ind])
                min_ind=j;
        }
        if(min_ind!=i){
            int temp=arr[i];
            arr[i]=arr[min_ind];
            arr[min_ind]=temp;
        }
    }
}

int main(){
    int arr[]={8,1,6,2,5,3};
    selection_sort(arr,6);
    int i;
    for(i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
