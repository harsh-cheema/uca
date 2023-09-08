#include <stdio.h>

int partition(int arr[],int l,int h){
    int pivot=arr[h];
    int low=l-1;
    int i;
    for(i=l;i<=h-1;i++){
        if(arr[i]<pivot){
            low++;
            int temp=arr[i];
            arr[i]=arr[low];
            arr[low]=temp;
        }
    }
    int temp=arr[low+1];
    arr[low+1]=arr[h];
    arr[h]=temp;
    return low+1;
    
}
int kth_smallest(int arr[],int l,int h,int k){
    if(l<h){
        int p=partition(arr,l,h);
        if(k-1==p) return arr[p];
        else if(k<p) return kth_smallest(arr,l,p-1,k);
        else return kth_smallest(arr,p+1,h,k);
    }
}


int main(){
        int arr[]={10,4,5,8,11,6,26};
        printf("%d\n",kth_smallest(arr,0,6,5));
}