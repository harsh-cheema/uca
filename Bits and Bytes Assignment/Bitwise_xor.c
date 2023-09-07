#include <stdio.h>

int bitwise_xor(int a,int b){
    int c=(~a);
    int d=(~b);
    int x=(a & d);
    int y=(b & c);
    return ~((~x)&(~y));
}

int main(){
    printf("%d %d\n",bitwise_xor(5,8),(5^8));
}
