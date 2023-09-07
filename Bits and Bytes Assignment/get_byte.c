#include <stdio.h>

unsigned char getByte(unsigned int x, int n) {
    // Shift the desired byte to the least significant position (byte 0).
    unsigned int shifted = x >> (n << 3); // Equivalent to x >> (n * 8)

    // And with 0xFF gives LSB byte i.e LS 8 bits
    unsigned char result = shifted & 0xFF;

    return result;
}

int main() {
    unsigned int x = 0x12345678;
    int n=1;

    unsigned char byte = getByte(x, n);

    printf("Byte %d of 0x%08X: 0x%02X\n", n, x, byte); // Should print "Byte 1 of 0x12345678: 0x56"

    return 0;
}


