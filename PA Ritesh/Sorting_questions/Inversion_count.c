#include <stdio.h>

int merge(int arr[],int l,int m,int h){
    int n1=m-l+1;
    int n2=h-m;

    int left[n1];
    int right[n2];

    int i,j;
    for(i=0;i<n1;i++){
        left[i]=arr[i+l];
    }

    for(j=0;j<n2;j++){
        right[j]=arr[j+m+1];
    }

    i=0;
    j=0;
    int k=l;
    int res=0;

    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            k++;
            i++;
        }
        else{
            arr[k]=right[j];
            k++;
            j++;
            res=res+(n1-i);
        }
    }

    while(i<n1){
        arr[k]=left[i];
        k++;
        i++;
    }

    while(j<n2){
        arr[k]=right[j];
        k++;
        j++;
    }
    return res;

}

int mergeSort(int arr[],int l,int h){
    int c=0;
    if(l<h){
        int m=(l+h)/2;
        c+=mergeSort(arr,l,m);
        c+=mergeSort(arr,m+1,h);
        c+=merge(arr,l,m,h);
    }
    return c;
}

int main(){
    int arr[]={2,4,1,3,5};
	
	int n=sizeof(arr)/sizeof(arr[0]);
	
	printf("%d\n",mergeSort(arr,0,n-1));
}