#include <stdio.h>

unsigned int logicalShift(int x, int n) {
    // Calculate a mask to clear the leftmost n bits
    unsigned int mask = ~(1 << 31 >> n<<1);

    // Perform the logical shift
    return (x >> n) & mask;
}


int main(){
    printf("%d\n",logicalShift(-3,2));
    
}