#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int a=1;
    int b=5;
    int i;
    for(i=1;i<n;i+=3){
        printf("%d ",a);
        int temp=b;
        b=4*b+a;
        a=temp;
    }
    printf("\n");
}