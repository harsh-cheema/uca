#include <stdio.h>


int replace(int n,int i,int j,int val){
   int clear=j-i+1;
   int mask=1<<clear;
   mask=(mask-1)<<i;
   mask=~mask;
   n=n&mask;
   return n | (val<<i);
}
int main(){
    int n=257;
    int i=1;
    int j=6;
    int val=127;
    printf("%d",replace(n,i,j,val));
}
