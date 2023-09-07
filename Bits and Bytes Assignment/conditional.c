#include <stdio.h>

int conditional(int x, int y, int z) {
    // Create a mask that is 0xFFFFFFFF (-1) if x is non-zero, and 0x00000000 (0) if x is zero.

    int mask = (!x + ~0);

    // Use the mask to select either y or z.
    return (y & mask) | (z & ~mask);
}

int main(){
    printf("%d\n",conditional(0,4,2));
}