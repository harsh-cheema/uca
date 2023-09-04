#include <stdio.h>


int count_flips(int a,int b){
    int c=a^b;
    int f=0;
    while(c>0){
        c=c&(c-1);
        f++;
    }
    return f;
}
int main(){
    int a=7;
    int b=10;
    printf("%d",count_flips(a,b));
}
