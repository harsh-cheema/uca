#include <stdio.h>

int bang(int x) {
    
    int oppositeSign = ((~x+1));
    printf("%d %d \n",oppositeSign,(x | oppositeSign));


    // Return 1 only if x is not 0 (sign bit and oppositeSign bit are both set).
    return ((x | oppositeSign)>>31)+1;
}

int main(){
    printf("%d",bang(8));
}