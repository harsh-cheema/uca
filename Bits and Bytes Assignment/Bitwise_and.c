#include <stdio.h>

int bitwise_and(int a,int b){
    return ~((~a) | (~b));
}

int main(){
    printf("%d %d\n",bitwise_and(5,4),(5&4));
}