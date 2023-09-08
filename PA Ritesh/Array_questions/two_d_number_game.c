#include <stdio.h>
#include <math.h>

int query(int n,int k,int i, char ch){
    int r=(int)ceil((float)n/(float)k);
   
    if((i>r && ch=='R') || (i>k && ch=='C')) return 0;

    if(ch=='R'){
        int a_first=(i-1)*k+1;
        int a_last=a_first+k-1;
        if(a_last>n) a_last=n;
        int no_of_terms=a_last-a_first+1;
        int sum=((no_of_terms)*(a_first+a_last))/2;
        return sum;
    }

    else{
        int a_first=i;
        int a_last=a_first+((r-1)*k);
        if(a_last>n)a_last=a_last-k;
        int no_of_terms=(a_last-a_first)/k +1;
        int sum=((no_of_terms)*(a_first+a_last))/2;
        return sum;
    }
}

int main(){
    printf("%d\n",query(10,3,4,'R'));
}