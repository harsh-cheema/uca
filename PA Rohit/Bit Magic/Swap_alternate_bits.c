#include <stdio.h>


int swap_alternate_bits(int n){
    int even=0xAAAAAAAA;
    int even_mask=(even & n)>>1;
    int odd=0x55555555;
    int odd_mask=(odd & n)<<1;
    return even_mask | odd_mask;

}
int main() {
        printf("%d",swap_alternate_bits(10));
}

