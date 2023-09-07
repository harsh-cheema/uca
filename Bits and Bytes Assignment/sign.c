#include <stdio.h>

int sign(int num) {
    // Shift the number to the right by 31 bits (assuming int is 32 bits)
    // This will copy the sign bit to all other bits, effectively creating
    // a mask with all 1's for negative numbers and all 0's for non-negative numbers.
    int signMask = num >> 31;

    // Use bitwise AND to check if the number is 0
    int isZero = !(num | signMask);



    // Combine the conditions to return the appropriate sign
    printf("\n");
    return (~isZero & (signMask | 1));
}

int main() {
    int num1 = 5;   // Positive number
    int num2 = 0;   // Zero
    int num3 = -7;  // Negative number

    printf("Sign of %d: %d\n", num1, sign(num1)); // Should print "Sign of 5: 1"
    printf("Sign of %d: %d\n", num2, sign(num2)); // Should print "Sign of 0: 0"
    printf("Sign of %d: %d\n", num3, sign(num3)); // Should print "Sign of -7: -1"
   
   

    return 0;
}
