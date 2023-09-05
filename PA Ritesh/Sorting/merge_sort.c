#include <stdio.h>

void merge(int arr[],int l,int m,int h){
    int n1=m-l+1;
    int n2=h-m;
    int left[n1];
    int right[n2];

    int i,j;
    for(i=0;i<n1;i++)
        left[i]=arr[i+l];

    for(j=0;j<n2;j++)
        right[j]=arr[j+m+1];

    int k=l;
    i=0;
    j=0;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
            k++;
        }
        else{
            arr[k]=right[j];
            j++;
            k++;
        }
    }

    while(i<n1){
        arr[k]=left[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k]=right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[],int l,int h){
    if(l>=h) return;
    int m=(l+h)/2;
    merge_sort(arr,l,m);
    merge_sort(arr,m+1,h);
    merge(arr,l,m,h);
}

int main(){
    int arr[]={8,1,6,2,5,3};
    merge_sort(arr,0,5);
    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}